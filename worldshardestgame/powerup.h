struct Powerup
{
	int x, y;

	void setup(int powx, int powy)
	{
		x = powx;
		y = powy;
	}

	void spawn()
	{
		setcolor(14);
		fillellipse(x, y, 10, 10);
	}

	void collect();
};