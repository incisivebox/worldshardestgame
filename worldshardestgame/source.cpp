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

void main()
{
	gr_start(GrDriver, GrMode, ErrorCode);
	system("pause");
	Square square(500, 600, 600, 500);
	square.spawn();
	while(true)
	{
		square.translate();
	}
}

struct Square
{

		Square(int rectleft, int recttop, int rectright, int rectbottom)
		{
			left = rectleft;
			top = recttop;
			right = rectright;
			bottom = rectbottom;
		}


		void spawn()
		{
			bar(left, top, right, bottom);
		}

		void translate()
		{
			int keypress = kbhit();
			if(keypress == 119)
			{
				top--;
				bottom--;
			}
		}

		int left, top, right, bottom;
		
};



