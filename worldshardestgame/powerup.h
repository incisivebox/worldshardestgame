struct Powerup
{
	int x, y;
	bool draw;

	void setup(int powx, int powy, bool show)
	{
		x = powx;
		y = powy;
		draw = show;
	}

	void spawn()
	{
		if (draw)
		{
			setcolor(4);
			fillellipse(x, y, 10, 10);
		}
	}

	void collect()
	{
		draw = false;
	}
}powerup;