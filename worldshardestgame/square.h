#include <iostream>
#include <string>
#include <graphics.h>
#include <winbgi.cpp>
#include <ctime>
#include <math.h>


using namespace std;

struct Square
{
		int left, top, right, bottom;
		

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

		void translate(int key)
		{
			int speed = 10;
			if(key == 119)
			{
				top-=speed;
				bottom-=speed;
			}
			else if(key == 115)
			{
				top+=speed;
				bottom+=speed;
			}
			else if(key == 97)
			{
				left-=speed;
				right-=speed;
			}
			else if(key == 100)
			{
				left+=speed;
				right+=speed;
			}
			cleardevice();
			spawn();
		}

		
		
};