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
		setcolor(4);
		fillellipse(x, y, 10, 10);
	}

	void collect();
}powerup;