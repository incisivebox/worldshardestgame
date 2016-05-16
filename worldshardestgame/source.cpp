

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


string deathct = "Deaths = 0     ";
bool win = false;
bool drawNewLevel = false;
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
	bool erase = false;
	int deaths = 0;
}global;

/*void updatecirc(){
	while (true){
		lvl1circupdate();
		Sleep(45);
	}
}*/

int key = 0;


void game(){
	srand((unsigned int)time(NULL));
	gr_start(GrDriver, GrMode, ErrorCode);
	//setcolor(1);
//	bar(0, 0, getmaxx(), getmaxy());
	setbkcolor(0);
	global.go = true;
	//global.lvl = 4;
	//goto lvl4;
	square.spawn();
	powerup.setup(800, 500, true);
	powerup.spawn();
	lvl1circsetup();
	lvl1endzonesetup();
	lvl1walls();
	setbkcolor(8);
	settextstyle(0, 0, 6);
	setcolor(15);
	outtextxy(0, 0, deathct.c_str());
	setbkcolor(0);
//	getch();
	
	while (true){
		lvl1circupdate();

	
		
		
			bool collide = circlecollision(circ, 13);
			if (collide)
			{
				global.deaths++;
			//	cout << "Collide!" << '\n';
				global.erase = true;

				square.reset(100, 560, 200, 460);
				powerup.respawn();
				win = false;

			}

			if (powerupcollision(powerup) && win == false)
			{
				powerup.collect();
				global.go = false;
				global.erase = true;
				//lvl1walls();
				Sleep(5);
				global.erase = true;
				//lvl1walls();
				global.go = true;

				win = true;
			}

			if (win)
			{
				if (endzonecollision(square))
				{
				//	cout << "YOU WIN" << '\n';
					

					global.lvl = 2;
					goto lvl2;
					
					closegraph();
				}
			}

		

		Sleep(45);
	}

lvl2:
	global.erase = true;
	global.go = false;
	drawNewLevel = true;
	while (drawNewLevel){};
	
	global.go = true;
	while (true){
		lvl2circupdate();
	//	square.reset(100, 560, 200, 460);


		bool collide = circlecollision(circ, 16);

		if (collide)
		{
			global.deaths++;
	//		cout << "Collide!" << '\n';
			global.erase = true;

			square.reset(1919 / 2 - 50, 1017, 1919 / 2 + 50, 917);

			win = false;

		}

		
		/*

		if (powerupcollision(powerup) && win == false)
		{
			powerup.collect();
			global.erase = true;
			Sleep(5);
			global.erase = true;

			win = true;
		}
		*/
		
			if (endzonecollision(square))
			{
				//cout << "YOU WIN" << '\n';
				goto lvl3;

				closegraph();
			}

			Sleep(45);
	}

lvl3:
	global.erase = true;
	global.go = false;
	

	lvl3circsetup();
	//outtextxy(100, 100, "This is a possible level.");
	//lvl3endzonesetup();
	//lvl3walls();
	square.reset(1919 / 2 - 50, 1017, 1919 / 2 + 50, 917);
	square.spawn();

	global.go = true;
	while (true){
		lvl2circupdate();
		//	square.reset(100, 560, 200, 460);


		bool collide = circlecollision(circ, 12);
		if (collide)
		{
			global.deaths++;
			//cout << "Collide!" << '\n';
			global.erase = true;

			square.reset(1919 / 2 - 50, 1017, 1919 / 2 + 50, 917);
			//powerup.respawn();
			win = false;

		}


		/*

		if (powerupcollision(powerup) && win == false)
		{
		powerup.collect();
		global.erase = true;
		Sleep(5);
		global.erase = true;

		win = true;
		}
		*/

		if (endzonecollision(square))
		{
			//cout << "YOU WIN" << '\n';

			goto lvl4;
		}

	}

lvl4:
	global.erase = true;
	global.go = false;
	square.reset(100, 560, 200, 460);
	square.spawn();
	powerup.setup(800, 500, true);
	powerup.spawn();
	global.erase = true;
	square.reset(100, 560, 200, 460);
	powerup.respawn();
	win = false;
	lvl1circsetup();
	randcircsetup();
	lvl1endzonesetup();
	lvl1walls();
	global.go = true;
	global.lvl = 4;
	//goto lvl2;

	while (true){
		lvl1circupdate();
		randcircupdate();



		bool collide = circlecollision(circ, 15);
		if (collide)
		{
			global.deaths++;
		//	cout << "Collide!" << '\n';
			global.erase = true;

			square.reset(100, 560, 200, 460);
			powerup.respawn();
			win = false;

		}

		if (powerupcollision(powerup) && win == false)
		{
			powerup.collect();
			global.go = false;
			global.erase = true;
			//lvl1walls();
			Sleep(5);
			global.erase = true;
			//lvl1walls();
			global.go = true;

			win = true;
		}

		if (win)
		{
			if (endzonecollision(square))
			{
				cout << "YOU WIN" << '\n';
				cout << "You died " << global.deaths << " times." << '\n';
				//global.lvl = 2;

				closegraph();
			}
		}



		Sleep(45);
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


int tempdeaths = 0;
string deathint;

void PrintFuncts(){
	if (global.erase){
		setcolor(0);
		bar(0, 0, 1919, 1019);
		global.erase = false;
	}
	if (global.lvl == 1){
		powerup.spawn();
		lvl1circprint();
		lvl1endzonesetup();
		lvl1walls();
		square.spawn();

	}
	else if (global.lvl == 2){
		//powerup.spawn();
		lvl2circprint();
		lvl2endzonesetup();
		lvl2walls();
		square.spawn();
		

	}

	else if (global.lvl == 4){
		powerup.spawn();
		lvl1circprint();
		randcircprint();
		lvl1endzonesetup();
		lvl1walls();
		square.spawn();
		

	}
//	if (global.deaths != tempdeaths){
		setbkcolor(8);
		//settextstyle(0, 0, 6);
		setcolor(15);
		outtextxy(0, 0, deathct.c_str());
		setbkcolor(0);
		if (global.deaths != tempdeaths){

			tempdeaths = global.deaths;
			deathint = to_string(global.deaths);
			deathct = "Deaths = " + deathint + "       ";
}

}

void KEY_LISTENER(){
	PrintFuncts();
	while (true){
		if (drawNewLevel){

			setcolor(0);
			bar(0, 0, 1919, 1019);

			lvl2walls();
			lvl2circsetup();
			lvl2endzonesetup();
			square.reset(910, 1017, 1010, 917);
			square.spawn();

			drawNewLevel = false;
		}
		while (global.go){
			while (global.go){
				global.hold = global.press = false;
				
				if ((KEYBOARD(VK_S) || KEYBOARD(VK_DOWN)) && square.top <= getmaxy() && getpixel(square.left + 50, square.top + 10) != 8 && getpixel(square.left, square.top + 10) != 8 && getpixel(square.right, square.top + 10) != 8 && getpixel(square.left + 50, square.top + 1) != 8 && getpixel(square.left, square.top + 1) != 8 && getpixel(square.right, square.top + 1) != 8){
					square.erase();
					square.top += speed - 5;
					square.bottom += speed - 5;
					square.spawn();
					PrintFuncts();
					while (global.hold && ((GetAsyncKeyState(VK_S) & 0x8000) || (GetAsyncKeyState(VK_DOWN) & 0x8000)) && square.top <= getmaxy() && getpixel(square.left + 50, square.top + 10) != 8 && getpixel(square.left, square.top + 10) != 8 && getpixel(square.right, square.top + 10) != 8 && getpixel(square.left + 50, square.top + 1) != 8 && getpixel(square.left, square.top + 1) != 8 && getpixel(square.right, square.top + 1) != 8){
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
						if (((GetAsyncKeyState(VK_D) & 0x8000) || (GetAsyncKeyState(VK_RIGHT) & 0x8000)) && square.top <= getmaxy() && square.right <= getmaxx() && getpixel(square.right + 10, square.bottom + 50) != 8 && getpixel(square.right + 10, square.bottom) != 8 && getpixel(square.right + 10, square.top) != 8 && getpixel(square.right + 1, square.bottom + 50) != 8 && getpixel(square.right + 1, square.bottom) != 8 && getpixel(square.right + 1, square.top) != 8){
							square.erase();
							square.left += speed;
							square.right += speed;
							square.spawn();
							PrintFuncts();
							Sleep(.5);
						}
						if (((GetAsyncKeyState(VK_A) & 0x8000) || (GetAsyncKeyState(VK_LEFT) & 0x8000)) && square.top <= getmaxy() && square.left >= 0 && getpixel(square.left - 10, square.bottom + 50) != 8 && getpixel(square.left - 10, square.bottom) != 8 && getpixel(square.left - 10, square.top) != 8 && square.left >= 0 && getpixel(square.left - 1, square.bottom + 50) != 8 && getpixel(square.left - 1, square.bottom) != 8 && getpixel(square.left - 1, square.top) != 8){
							square.erase();
							square.left -= speed;
							square.right -= speed;
							square.spawn();
							PrintFuncts();
							Sleep(.5);
						}
					}
				}
				if ((KEYBOARD(VK_W) || KEYBOARD(VK_UP)) && square.bottom >= 0 && getpixel(square.left, square.bottom - 10) != 8 && getpixel(square.left + 50, square.bottom - 10) != 8 && getpixel(square.right, square.bottom - 10) != 8){
					square.erase();
					square.top -= speed - 5;
					square.bottom -= speed - 5;
					square.spawn();
					PrintFuncts();
					while (global.hold && ((GetAsyncKeyState(VK_W) & 0x8000) || (GetAsyncKeyState(VK_UP) & 0x8000)) && square.bottom >= 0 && getpixel(square.left, square.bottom - 10) != 8 && getpixel(square.left + 50, square.bottom - 10) != 8 && getpixel(square.right, square.bottom - 10) != 8){
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
						if (((GetAsyncKeyState(VK_D) & 0x8000) || (GetAsyncKeyState(VK_RIGHT) & 0x8000)) && square.bottom >= 0 && square.right <= getmaxx() && getpixel(square.right + 10, square.bottom + 50) != 8 && getpixel(square.right + 10, square.bottom) != 8 && getpixel(square.right + 10, square.top) != 8 && getpixel(square.right + 1, square.bottom + 50) != 8 && getpixel(square.right + 1, square.bottom) != 8 && getpixel(square.right + 1, square.top) != 8){
							square.erase();
							square.left += speed;
							square.right += speed;
							square.spawn();
							PrintFuncts();
							Sleep(.5);
						}
						if (((GetAsyncKeyState(VK_A) & 0x8000) || (GetAsyncKeyState(VK_LEFT) & 0x8000)) && square.bottom >= 0 && square.left >= 0 && getpixel(square.left - 10, square.bottom + 50) != 8 && getpixel(square.left - 10, square.bottom) != 8 && getpixel(square.left - 10, square.top) != 8){
							square.erase();
							square.left -= speed;
							square.right -= speed;
							square.spawn();
							PrintFuncts();
							Sleep(.5);
						}
					}
				}
				if ((KEYBOARD(VK_A) || KEYBOARD(VK_LEFT)) && square.left >= 0 && getpixel(square.left - 10, square.bottom + 50) != 8 && getpixel(square.left - 10, square.bottom) != 8 && getpixel(square.left - 10, square.top) != 8){
					square.erase();
					square.left -= speed - 5;
					square.right -= speed - 5;
					square.spawn();
					PrintFuncts();
					while (global.hold && ((GetAsyncKeyState(VK_A) & 0x8000) || (GetAsyncKeyState(VK_LEFT) & 0x8000)) && square.left >= 0 && getpixel(square.left - 10, square.bottom + 50) != 8 && getpixel(square.left - 10, square.bottom) != 8 && getpixel(square.left - 10, square.top) != 8){
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
						if (((GetAsyncKeyState(VK_W) & 0x8000) || (GetAsyncKeyState(VK_UP) & 0x8000)) && square.left >= 0 && square.bottom >= 0 && getpixel(square.left, square.bottom - 10) != 8 && getpixel(square.left + 50, square.bottom - 10) != 8 && getpixel(square.right, square.bottom - 10) != 8){
							square.erase();
							square.top -= speed;
							square.bottom -= speed;
							square.spawn();
							PrintFuncts();
							Sleep(.5);
						}
						if (((GetAsyncKeyState(VK_S) & 0x8000) || (GetAsyncKeyState(VK_DOWN) & 0x8000)) && square.left >= 0 && square.top <= getmaxy() && getpixel(square.left + 50, square.top + 10) != 8 && getpixel(square.left, square.top + 10) != 8 && getpixel(square.right, square.top + 10) != 8 && getpixel(square.left + 50, square.top + 1) != 8 && getpixel(square.left, square.top + 1) != 8 && getpixel(square.right, square.top + 1) != 8){
							square.erase();
							square.top += speed;
							square.bottom += speed;
							square.spawn();
							PrintFuncts();
							Sleep(.5);
						}
					}
				}
				if ((KEYBOARD(VK_D) || KEYBOARD(VK_RIGHT)) && square.right <= getmaxx() && getpixel(square.right + 10, square.bottom + 50) != 8 && getpixel(square.right + 10, square.bottom) != 8 && getpixel(square.right + 10, square.top) != 8 && getpixel(square.right + 1, square.bottom + 50) != 8 && getpixel(square.right + 1, square.bottom) != 8 && getpixel(square.right + 1, square.top) != 8){
					square.erase();
					square.left += speed - 5;
					square.right += speed - 5;
					square.spawn();
					PrintFuncts();
					while (global.hold && ((GetAsyncKeyState(VK_D) & 0x8000) || (GetAsyncKeyState(VK_RIGHT) & 0x8000)) && square.right <= getmaxx() && getpixel(square.right + 10, square.bottom + 50) != 8 && getpixel(square.right + 10, square.bottom) != 8 && getpixel(square.right + 10, square.top) != 8 && getpixel(square.right + 1, square.bottom + 50) != 8 && getpixel(square.right + 1, square.bottom) != 8 && getpixel(square.right + 1, square.top) != 8){
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
						if (((GetAsyncKeyState(VK_W) & 0x8000) || (GetAsyncKeyState(VK_UP) & 0x8000)) && square.right <= getmaxx() && square.bottom >= 0 && getpixel(square.left, square.bottom - 10) != 8 && getpixel(square.left + 50, square.bottom - 10) != 8 && getpixel(square.right, square.bottom - 10) != 8){
							square.erase();
							square.top -= speed;
							square.bottom -= speed;
							square.spawn();
							PrintFuncts();
							Sleep(.5);
						}
						if (((GetAsyncKeyState(VK_S) & 0x8000) || (GetAsyncKeyState(VK_DOWN) & 0x8000)) && square.top <= getmaxy() && square.right <= getmaxx() && getpixel(square.left + 50, square.top + 10) != 8 && getpixel(square.left, square.top + 10) != 8 && getpixel(square.right, square.top + 10) != 8 && getpixel(square.left + 50, square.top + 1) != 8 && getpixel(square.left, square.top + 1) != 8 && getpixel(square.right, square.top + 1) != 8){
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




