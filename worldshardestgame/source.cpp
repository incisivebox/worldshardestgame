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
}

