
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

bool circlecollision(Square square)
{
	for (int i = square.left; i < square.right; i++)
	{
		if (getpixel(i, square.top + 1) == 1)
		{
			return true;
		}

		else if (getpixel(i, square.bottom - 1) == 1)
		{
			return true;
		}
	}

	for (int i = square.top; i < square.bottom; i++)
	{
		if (getpixel(square.left - 1, i) == 1)
		{
			return true;
		}
		
		else if (getpixel(square.right + 1, i) == 1)
		{
			return true;
		}
	}
	return false;
}

bool powerupcollision(Square square)
{
	for (int i = square.left; i < square.right; i++)
	{
		if (getpixel(i, square.top + 1) == 14)
		{
			return true;
		}

		else if (getpixel(i, square.bottom - 1) == 14)
		{
			return true;
		}
	}

	for (int i = square.top; i < square.bottom; i++)
	{
		if (getpixel(square.left - 1, i) == 14)
		{
			return true;
		}

		else if (getpixel(square.right + 1, i) == 14)
		{
			return true;
		}
	}
	return false;
}