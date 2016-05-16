int py = 1019 / 8;

void lvl1endzonesetup()
{
	
	setcolor(2);
	bar(1919-(py*1.5), py*3, 1879, py*5);

}

void lvl2endzonesetup()
{
	setcolor(2);
	bar(1919 / 2 - 125, 150, 1919/2 +125, 0);
}

void lvl1walls(){
	setcolor(8);
	bar (672, 50, 1919, 0);
	bar(0, 50, 1919, 65);
	bar(0, 1019, 1919, 954);
	bar(0, 1019, 200, py * 5);
	bar(0, 50, 200, py * 3);
	bar(0, py * 3, 50, py * 5);
	bar(1919 - (py*1.5), py * 3, 1919, 0);
	bar(1919 - (py*1.5), 1019, 1919, py * 5);
	bar(1919, py * 3, 1879, py * 5);
}


void lvl2walls(){
	setcolor(8);
	bar(50, 1019, 1919/2 - 125, 890 );
	bar(1919 / 2 + 125, 890, 1919, 1019);
	bar(0, 50, 1919 / 2 - 125, 150); //
	bar(1919 / 2 + 125, 150, 1919, 0); //
	bar(0, 890, 150, 150);
	bar(1919, 890, 1919 - 150, 150);
	bar(1919 / 2 - 125, 0, 672, 50);
}

void lvl3endzonesetup();

void lvl3walls();