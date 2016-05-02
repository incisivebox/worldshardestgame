
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
	/*		int speed = 10;
			if(key == 119 && top >= 100)
			{
				
			}
			else if(key == 115 && bottom <= getmaxy() - 100)
			{

			}
			else if(key == 97 && left >= 10)
			{
				
			}
			else if(key == 100 && right <= getmaxx() - 10)
			{
			
			}
			//cleardevice();*/
			spawn();
		}

		void reset(int startleft, int starttop, int startright, int startbottom)
		{
			left = startleft;
			top = starttop;
			right = startright;
			bottom = startbottom;
		}


		
}square(100, 560, 200, 460);


bool circlecollision(Circle circles[], int numcircles)
{
	int centerx, centery, radius, distance, radiussum;
	centerx = (square.left + square.right) / 2;
	centery = (square.top + square.bottom) / 2;
	radius = 50;
	for (int i = 0; i < numcircles; i++)
	{
		distance = sqrt(((centerx - circles[i].x) *(centerx - circles[i].x)) + ((centery - circles[i].y) * (centery - circles[i].y)));
		radiussum = radius + circles[i].radius;
		if (distance < radiussum)
		{
			return true;
		}
	}
	return false;
}



bool powerupcollision(Powerup powerup)
{
	int centerx, centery, radius, distance, radiussum, poweruprad;
	poweruprad = 10;
	centerx = (square.left + square.right) / 2;
	centery = (square.top + square.bottom) / 2;
	radius = 50;
	distance = sqrt(((centerx - powerup.x) * (centerx - powerup.x)) + ((centery - powerup.y) * (centery - powerup.y)));
	radiussum = radius + poweruprad;
	if (distance < radiussum)
	{
		return true;
	}
	return false;
}

bool endzonecollision(Square square)
{
	for (int i = square.left; i < square.right; i++)
	{
		if (getpixel(i, square.top + 1) == 2)
		{
			if (getpixel(i, square.bottom - 1) == 2)
			{
				for (int i = square.top; i > square.bottom; i--)
				{

					if (getpixel(square.left - 1, i) == 2)
					{
						if (getpixel(square.right + 1, i) == 2)
						{
							return true;
						}
					}


				}
			}
		}

		
	}
	
	
			


	return false;
}
