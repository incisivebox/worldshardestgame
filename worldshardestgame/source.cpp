#include <iostream>
#include <string>
#include <graphics.h>
#include <winbgi.cpp>
#include <ctime>
#include <math.h>

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

struct Circle{
	
	int x;
	int y;
	bool dir;

}circ[16];

void circsetup(){
	//Setup circles on opposing ends of screen (for level one only)
		circ[0].x = 300;
		circ[0].y = 40;
		circ[0].dir = true;
		circle (circ[0].x, circ[0].y, 20);

			for(int i = 1; i < 16; i++){
				circ[i].x = circ[i-1].x + 80;
				if(i % 2 == 0){
					circ[i].y = 40;
					circ[i].dir = true;
				}
				else if (i % 2 == 1){
					circ[i].y = 900;
					circ[i].dir = false;
				}
					circle (circ[i].x, circ[i].y, 20);
			}

}

void circupdate(){
	for (int i = 0; i < 16; i++){
			setcolor(0);
			circle (circ[i].x, circ[i].y, 20);
		//Move circle
			if(circ[i].dir == true){
				circ[i].y +=10;
			}
			else{
				circ[i].y -=10;
			}

		//Test for level boundary (currently level one only)
			if (circ[i].y == 900 && circ[i].dir == true){
				circ[i].dir = false;
			}
			else if (circ[i].y == 40 && circ[i].dir == false){
				circ[i].dir = true;
			}
			//Print update circle
			setcolor(15);
			circle (circ[i].x, circ[i].y, 20);
	}
}


void main()
{
	gr_start(GrDriver, GrMode, ErrorCode);
		circsetup();
			while (true){
				circupdate();
				Sleep(45);
			}
	system("pause");
}

