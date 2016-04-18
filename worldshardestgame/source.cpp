#include <iostream>
#include <string>
#include <graphics.h>
#include <winbgi.cpp>
#include <ctime>
#include <thread>
#include <math.h>
#include <amp.h>
#include "circle.h"
#include "square.h"
#include "endzone.h"
#include "powerup.h"

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


void updatecirc(){
	while (true){
		lvl1circupdate();
		Sleep(45);
	}
}

int key = 0;

void tick(){		
		while (kbhit())
			{
				square.erase();
				lvl1endzonesetup();
				key = getch();
				square.translate(key);
			}
		for (int i = 0; i < 12; i++) //value is currently hardcoded
		{
			bool collide = collision(square, circ[i]);
			if (collide)
			{
				cout << "Collide!" << '\n';
				break;
			}
			

		}
}



void main()
{

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





