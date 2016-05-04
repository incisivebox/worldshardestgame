

#include <iostream>
#include <string>
#include <graphics.h>
#include <winbgi.cpp>
#include <ctime>
#include <thread>
#include <math.h>
#include "circle.h"
#include "endzone.h"
#include "powerup.h"
#include "VirtualKeys.h"
#include "square.h"


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

bool win = false;
int speed = 8;
void PrintFuncts();
void KEY_LISTENER();
bool KEYBOARD(int);
INPUT_RECORD irInBuf;

struct Pass {
	bool press = false;
	bool hold = false;
	int VirtualKey;
	POINT p;
	bool go = false;
	int lvl = 1;
}global;

/*void updatecirc(){
	while (true){
		lvl1circupdate();
		Sleep(45);
	}
}*/

int key = 0;

/*
void tick(){		
				square.erase();
				lvl1endzonesetup();
				key = getch();
				square.translate(key);
		for (int i = 0; i < 12; i++) //value is currently hardcoded

	while (kbhit())
	{
		square.erase();
		lvl1endzonesetup();
		key = getch();
		square.translate(key);
	}
		bool collide = circlecollision(square);
		if (collide)
		{
			cout << "Collide!" << '\n';
		}

		collide = powerupcollision(square);
		if (collide)
		{
			cout << "Collide! - powerup" << '\n';
		}

		collide = endzonecollision(square);
		if (collide)
		{
			cout << "Collide!" << '\n';
		}

			

		
}
*/

void game(){
	
	gr_start(GrDriver, GrMode, ErrorCode);
	//setcolor(1);
//	bar(0, 0, getmaxx(), getmaxy());
	setbkcolor(0);
	square.spawn();
	powerup.setup(800, 500, true);
	powerup.spawn();
	lvl1circsetup();
	lvl1endzonesetup();
	lvl1walls();
	global.go = true;
	global.lvl = 2;
	goto lvl2;

	while (true){
		lvl1circupdate();

	
		
		
			bool collide = circlecollision(circ, 12);
			if (collide)
			{
				cout << "Collide!" << '\n';
				cleardevice();
				Sleep(5);
				cleardevice();

				square.reset(100, 560, 200, 460);
				powerup.respawn();
				win = false;

			}

			if (powerupcollision(powerup) && win == false)
			{
				powerup.collect();
				cleardevice();
				Sleep(5);
				cleardevice();
				
				win = true;
			}

			if (win)
			{
				if (endzonecollision(square))
				{
					cout << "YOU WIN" << '\n';
					global.lvl = 2;
					goto lvl2;
					
					closegraph();
				}
			}

		

		Sleep(45);
	}

lvl2:
	global.go = false;
	cleardevice();

	lvl2circsetup();
	lvl2endzonesetup();
	lvl2walls();
	square.reset(1919 / 2 - 50, 1017, 1919 / 2 + 50, 917);
	square.spawn();

	global.go = true;
	while (true){
		lvl2circupdate();
	//	square.reset(100, 560, 200, 460);

		bool collide = circlecollision(circ, 12);
		if (collide)
		{
			cout << "Collide!" << '\n';
			cleardevice();
			Sleep(5);
			cleardevice();

			square.reset(100, 560, 200, 460);
			powerup.respawn();
			win = false;

		}

		/*

		if (powerupcollision(powerup) && win == false)
		{
			powerup.collect();
			cleardevice();
			Sleep(5);
			cleardevice();

			win = true;
		}
		*/
		
			if (endzonecollision(square))
			{
				cout << "YOU WIN" << '\n';

				closegraph();
			}

	}







	closegraph();
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
				return true;
			}
		} while ((GetAsyncKeyState(VirtualKey) & 0x8000) != 0);
		return true;
	}
	return false;
}

bool squarecheck(){
	//if
	


	return true;
}

void PrintFuncts(){
	if (global.lvl == 1){
		powerup.spawn();
		lvl1circprint();
		lvl1endzonesetup();
		square.spawn();
		lvl1walls();
	}
	else if (global.lvl == 2){
		powerup.spawn();
		lvl2circprint();
		lvl2endzonesetup();
		square.spawn();
		lvl2walls();

	}


}

void KEY_LISTENER(){
	PrintFuncts();
	while (true){
		while (global.go){
			while (true){
				global.hold = global.press = false;
				if (KEYBOARD(VK_S) && square.top <= getmaxy() && getpixel(square.left + 50, square.top + 8) != 8 && getpixel(square.left, square.top + 8) != 8 && getpixel(square.right, square.top + 8) != 8){
					square.erase();
					square.top += speed - 5;
					square.bottom += speed - 5;
					square.spawn();
					PrintFuncts();
					while (global.hold && (GetAsyncKeyState(VK_S) & 0x8000) && square.top <= getmaxy() && getpixel(square.left + 50, square.top + 8) != 8 && getpixel(square.left, square.top + 8) != 8 && getpixel(square.right, square.top + 8) != 8){
						square.erase();
						square.top += speed;
						square.bottom += speed;
						square.spawn();
						//PrintFuncts();
						//Sleep(10);
						PrintFuncts();
						Sleep(10);
						PrintFuncts();
						Sleep(10);
						PrintFuncts();
						Sleep(10);
						PrintFuncts();
						if ((GetAsyncKeyState(VK_D) & 0x8000) && square.top <= getmaxy() && square.right <= getmaxx() && getpixel(square.right + 8, square.bottom + 50) != 8 && getpixel(square.right + 8, square.bottom) != 8 && getpixel(square.right + 8, square.top) != 8){
							square.erase();
							square.left += speed;
							square.right += speed;
							square.spawn();
							PrintFuncts();
							Sleep(.5);
						}
						if ((GetAsyncKeyState(VK_A) & 0x8000) && square.top <= getmaxy() && square.left >= 0 && getpixel(square.left - 8, square.bottom + 50) != 8 && getpixel(square.left - 8, square.bottom ) != 8 && getpixel(square.left - 8, square.top) != 8){
							square.erase();
							square.left -= speed;
							square.right -= speed;
							square.spawn();
							PrintFuncts();
							Sleep(.5);
						}
					}
				}
				if (KEYBOARD(VK_W) && square.bottom >= 0 && getpixel(square.left, square.bottom - 8) != 8 && getpixel(square.left + 50, square.bottom - 8) != 8 && getpixel(square.right, square.bottom - 8) != 8){
					square.erase();
					square.top -= speed - 5;
					square.bottom -= speed - 5;
					square.spawn();
					PrintFuncts();
					while (global.hold && (GetAsyncKeyState(VK_W) & 0x8000) && square.bottom >= 0 && getpixel(square.left, square.bottom - 8) != 8 && getpixel(square.left + 50, square.bottom - 8) != 8 && getpixel(square.right, square.bottom - 8) != 8){
						square.erase();
						square.top -= speed;
						square.bottom -= speed;
						square.spawn();
						//PrintFuncts();
						//Sleep(10);
						PrintFuncts();
						Sleep(10);
						PrintFuncts();
						Sleep(10);
						PrintFuncts();
						Sleep(10);
						PrintFuncts();
						if ((GetAsyncKeyState(VK_D) & 0x8000) && square.bottom >= 0 && square.right <= getmaxx() && getpixel(square.right + 8, square.bottom + 50) != 8 && getpixel(square.right + 8, square.bottom) != 8 && getpixel(square.right + 8, square.top) != 8){
							square.erase();
							square.left += speed;
							square.right += speed;
							square.spawn();
							PrintFuncts();
							Sleep(.5);
						}
						if ((GetAsyncKeyState(VK_A) & 0x8000) && square.bottom >= 0 && square.left >= 0 && getpixel(square.left - 8, square.bottom + 50) != 8 && getpixel(square.left - 8, square.bottom) != 8 && getpixel(square.left - 8, square.top) != 8){
							square.erase();
							square.left -= speed;
							square.right -= speed;
							square.spawn();
							PrintFuncts();
							Sleep(.5);
						}
					}
				}
				if (KEYBOARD(VK_A) && square.left >= 0 && getpixel(square.left - 8, square.bottom + 50) != 8 && getpixel(square.left - 8, square.bottom) != 8 && getpixel(square.left - 8, square.top) != 8){
					square.erase();
					square.left -= speed - 5;
					square.right -= speed - 5;
					square.spawn();
					PrintFuncts();
					while (global.hold && (GetAsyncKeyState(VK_A) & 0x8000) && square.left >= 0 && getpixel(square.left - 8, square.bottom + 50) != 8 && getpixel(square.left - 8, square.bottom) != 8 && getpixel(square.left - 8, square.top) != 8){
						square.erase();
						square.left -= speed;
						square.right -= speed;
						square.spawn();
						//PrintFuncts();
					//	Sleep(10);
						PrintFuncts();
						Sleep(10);
						PrintFuncts();
						Sleep(10);
						PrintFuncts();
						Sleep(10);
						PrintFuncts();
						if ((GetAsyncKeyState(VK_W) & 0x8000) && square.left >= 0 && square.bottom >= 0 && getpixel(square.left, square.bottom - 8) != 8 && getpixel(square.left + 50, square.bottom - 8) != 8 && getpixel(square.right, square.bottom - 8) != 8){
							square.erase();
							square.top -= speed;
							square.bottom -= speed;
							square.spawn();
							PrintFuncts();
							Sleep(.5);
						}
						if ((GetAsyncKeyState(VK_S) & 0x8000) && square.left >= 0 && square.top <= getmaxy() && getpixel(square.left + 50, square.top + 8) != 8 && getpixel(square.left, square.top + 8) != 8 && getpixel(square.right, square.top + 8) != 8){
							square.erase();
							square.top += speed;
							square.bottom += speed;
							square.spawn();
							PrintFuncts();
							Sleep(.5);
						}
					}
				}
				if (KEYBOARD(VK_D) && square.right <= getmaxx() && getpixel(square.right + 8, square.bottom + 50) != 8 && getpixel(square.right + 8, square.bottom) != 8 && getpixel(square.right + 8, square.top) != 8){
					square.erase();
					square.left += speed - 5;
					square.right += speed - 5;
					square.spawn();
					PrintFuncts();
					while (global.hold && (GetAsyncKeyState(VK_D) & 0x8000) && square.right <= getmaxx() && getpixel(square.right + 8, square.bottom + 50) != 8 && getpixel(square.right + 8, square.bottom) != 8 && getpixel(square.right + 8, square.top) != 8){
						square.erase();
						square.left += speed;
						square.right += speed;
						square.spawn();
									//	PrintFuncts();
									//	Sleep(10);
									//	PrintFuncts();
									//	Sleep(10);
						PrintFuncts();
						Sleep(10);
						PrintFuncts();
						Sleep(10);
						PrintFuncts();
						Sleep(10);
						PrintFuncts();
						if ((GetAsyncKeyState(VK_W) & 0x8000) && square.right <= getmaxx() && square.bottom >= 0 && getpixel(square.left, square.bottom - 8) != 8 && getpixel(square.left + 50, square.bottom - 8) != 8 && getpixel(square.right, square.bottom - 8) != 8){
							square.erase();
							square.top -= speed;
							square.bottom -= speed;
							square.spawn();
							PrintFuncts();
							Sleep(.5);
						}
						if ((GetAsyncKeyState(VK_S) & 0x8000) && square.top <= getmaxy() && square.right <= getmaxx() && getpixel(square.left + 50, square.top + 8) != 8 && getpixel(square.left, square.top + 8) != 8 && getpixel(square.right, square.top + 8) != 8){
							square.erase();
							square.top += speed;
							square.bottom += speed;
							square.spawn();
							PrintFuncts();
							Sleep(.5);
						}
					}
				}
				if (change){
					PrintFuncts();
					
				}
			}
		}
	}
}




