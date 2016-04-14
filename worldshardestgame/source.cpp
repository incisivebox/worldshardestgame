#include <iostream>
#include <string>
#include <graphics.h>
#include <winbgi.cpp>
#include <ctime>
#include <thread>
#include <math.h>
#include "square.h"
#include "circle.h"
#include "endzone.h"
#include "powerup.h"
#include "VirtualKeys.h"

using namespace std;

int GrDriver, GrMode, ErrorCode;

void gr_start(int &GrDriver, int &GrMode, int &ErrorCode)
{
	//set graphics driver
	GrDriver = VGA;
	//set graphics mode
	GrMode = VGAMAX;
	//start graphics
	initgraph(&GrDriver, &GrMode, "");
	//check for errors
	ErrorCode = graphresult();
	if(ErrorCode != grOk)
	{
		cout << "Error : " << ErrorCode << endl;
		getch();
		exit(1);
	}
}

void KEY_LISTENER();
bool KEYBOARD(int);
INPUT_RECORD irInBuf;

struct Pass {
	bool press = false;
	bool hold = false;
	int VirtualKey;
	POINT p;
}global;

/*void updatecirc(){
	while (true){
		lvl1circupdate();
		Sleep(45);
	}
}*/

int key = 0;

void tick(){		
		while (kbhit())
			{
				square.erase();
				lvl1endzonesetup();
				key = getch();
				square.translate(key);
			}
}

void game(){
	
	gr_start(GrDriver, GrMode, ErrorCode);

	square.spawn();
	powerup.setup(500, 500, true);
	powerup.spawn();
	lvl1circsetup();
	lvl1endzonesetup();


	while (true){
		tick();
		lvl1circupdate();
		powerup.spawn();
		Sleep(45);
	}

}

void main()
{
	thread g(game);
	thread kb(KEY_LISTENER);

	kb.join();
	g.join();

	return;
}

bool KEYBOARD(int VirtualKey){
	if ((GetAsyncKeyState(VirtualKey) & 0x8000) != 0)
	{
		irInBuf.EventType = KEY_EVENT;
		global.press = true;
		global.VirtualKey = VirtualKey;
		int count = 0;
		do{
			if (count++ > 1000){
				global.hold = true;
			}
		} while ((GetAsyncKeyState(VirtualKey) & 0x8000) != 0);
		return true;
	}
	return false;
}

void KEY_LISTENER(){
int 	speed = 10;
	while (true){
		if (KEYBOARD(VK_S)){
			square.top += speed;
			square.bottom += speed;
			square.erase();
			square.spawn();
		}
		if (KEYBOARD(VK_W)){
			square.top -= speed;
			square.bottom -= speed;
			square.erase();
			square.spawn();
		}
		if (KEYBOARD(VK_A)){
			square.left -= speed;
			square.right -= speed;
			square.erase();
			square.spawn();
		}
		if (KEYBOARD(VK_D)){
			square.left += speed;
			square.right += speed;
			square.erase();
			square.spawn();
		}
	
	}
}




