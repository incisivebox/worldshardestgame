
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

		
		
}square(100, 600, 200, 500);