
struct Square
{
		int left, top, right, bottom;
		int height, width;
		

		Square(int rectleft, int recttop, int rectright, int rectbottom)
		{
			left = rectleft;
			top = recttop;
			right = rectright;
			bottom = rectbottom;
			height = bottom - top;
			width = right - left;
		}


		void spawn()
		{
			setcolor(4);
			bar(left, top, right, bottom);
		}

		void erase()
		{
			setcolor(0);
			bar(left, top, right, bottom);
		}

		void translate(int key)
		{
			int speed = 10;
			if(key == 119 && top >= 100)
			{
				top-=speed;
				bottom-=speed;
			}
			else if(key == 115 && bottom <= getmaxy() - 100)
			{
				top+=speed;
				bottom+=speed;
			}
			else if(key == 97 && left >= 10)
			{
				left-=speed;
				right-=speed;
			}
			else if(key == 100 && right <= getmaxx() - 10)
			{
				left+=speed;
				right+=speed;
			}
			//cleardevice();
			spawn();
		}


		
		
}square(500, 600, 600, 500);

double clamp(double x, double upper, double lower)
{
	return min(upper, max(x, lower));
}

bool collision(Square square, Circle circle)
{
	float closestx = clamp(circle.x, square.left, square.right);
	float closesty = clamp(circle.y, square.top, square.bottom);

	float distancex = circle.x - closestx;
	float distancey = circle.y - closesty;

	float distancesquared = (distancex * distancex) + (distancey * distancey);
	return distancesquared < (circle.radius * circle.radius);
}