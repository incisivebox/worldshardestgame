
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



void main()
{
	int key = 0;
	gr_start(GrDriver, GrMode, ErrorCode);
	Square square(500, 600, 600, 500);
	square.spawn();
	circsetup();
	while(true)
	{
		if(kbhit())
		{
			key = getch();
			cout << key << '\n';
			square.translate(key);
		}
		else
		{
			square.spawn();
		}
		circupdate();
		Sleep(45);
	}
}






