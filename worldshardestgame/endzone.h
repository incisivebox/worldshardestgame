int py = 1019 / 8;
void lvl1endzonesetup()
{
	
	setcolor(2);
	bar(1919-(py*1.5), py*3, 1879, py*5);

}

void lvl1walls(){
	setcolor(8);
	bar(0, 65, 1919, 0);
	bar(0, 1019, 1919, 954);
	bar(0, 1019, 200, py * 5);
	bar(0, 0, 200, py * 3);
	bar(0, py * 3, 50, py * 5);
	bar(1919 - (py*1.5), py * 3, 1919, 0);
	bar(1919 - (py*1.5), 1019, 1919, py * 5);
	bar(1919, py * 3, 1879, py * 5);
}

void lvl2endzonesetup(){

}

void lvl2walls(){


}