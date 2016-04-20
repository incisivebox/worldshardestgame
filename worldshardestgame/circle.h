struct Circle{

	int x;
	int y;
	bool dir;
	int radius = 30;

}circ[12];

void lvl1circsetup(){
	//Setup circles on opposing ends of screen (for level one only)
	circ[0].x = 300;
	circ[0].y = 100;
	circ[0].dir = true;
	circle(circ[0].x, circ[0].y, 30);

	for (int i = 1; i < 12; i++){
		circ[i].x = circ[i - 1].x + 110;
		if (i % 2 == 0){
			circ[i].y = 100;
			circ[i].dir = true;
		}
		else if (i % 2 == 1){
			circ[i].y = 900;
			circ[i].dir = false;
		}
		circle(circ[i].x, circ[i].y, 30);
	}

}

void lvl1circupdate(){
	for (int i = 0; i < 12; i++){
		setcolor(0);
		fillellipse(circ[i].x, circ[i].y, 30,30);
		//Move circle
		if (circ[i].dir == true){
			circ[i].y += 16;
		}
		else{
			circ[i].y -= 16;
		}

		//Test for level boundary (currently level one only)
		if (circ[i].y == 900 && circ[i].dir == true){
			circ[i].dir = false;
		}
		else if (circ[i].y == 100 && circ[i].dir == false){
			circ[i].dir = true;
		}
		//Print update circle
		setcolor(1);
		fillellipse(circ[i].x, circ[i].y, 30,30);
	}
}