struct Circle{

	int x;
	int y;
	bool dir;
	int radius = 30;

}circ[20];

void lvl1circsetup(){
	//Setup circles on opposing ends of screen (for level one only)
	circ[0].x = 300;
	circ[0].y = 100;
	circ[0].dir = true;
	setcolor(1);
	fillellipse(circ[0].x, circ[0].y, 30,30);

	for (int i = 1; i < 13; i++){
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
bool change;
int prevy1 = 100, prevy2 = 900;

void lvl1circupdate(){
	for (int i = 0; i < 13; i++){
		
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

	}
	change = true;
}

void lvl1circprint(){
	if (change){
		for (int i = 0; i < 13; i++){
			if (circ[i].dir){
				if (circ[i].y == 100){
					setcolor(0);
					fillellipse(circ[i].x, prevy2, 30, 30);
				}
				else{
					setcolor(0);
					fillellipse(circ[i].x, prevy1, 30, 30);
				}
				
				
				//prevy1 = circ[i].y;
			}
			else {
				if (circ[i].y == 900){
					setcolor(0);
					fillellipse(circ[i].x, prevy1, 30, 30);
				}
				else{
					setcolor(0);
					fillellipse(circ[i].x, prevy2, 30, 30);
				}
				//prevy2 = circ[i].y;
			}
			setcolor(1);
			fillellipse(circ[i].x, circ[i].y, 30, 30);
		}

		if (circ[0].dir){
			prevy1 = circ[0].y;
			prevy2 = circ[1].y;
		}
		else{
			prevy1 = circ[1].y;
			prevy2 = circ[0].y;
		}
		
		change = false;
	}


}

void lvl2circsetup(){
	circ[0].x = 220;
	circ[0].y = 200;
	circ[0].dir = true;
	setcolor(1);
	fillellipse(circ[0].x, circ[0].y, 30, 30);

	for (int i = 1; i < 14; i++){
		circ[i].x = circ[i - 1].x + 110;
		if (i % 2 == 0){
			circ[i].y = 200;
			circ[i].dir = true;
			setcolor(0);
			fillellipse(circ[0].x, circ[0].y, 30, 30);
		}
		else if (i % 2 == 1){
			circ[i].y = 800;
			circ[i].dir = false;
			setcolor(0);
			fillellipse(circ[0].x, circ[0].y, 30, 30);
		}
		circle(circ[i].x, circ[i].y, 30);
		setcolor(0);
		fillellipse(circ[0].x, circ[0].y, 30, 30);
	}
	circ[15].x = 220;
	circ[15].y = 400;
	circ[15].dir = true;
	circ[16].x = 840;
	circ[16].y = 300;
	circ[16].dir = false;

}

void lvl2circupdate(){
	for (int i = 0; i < 14; i++){

		//Move circle
		if (circ[i].dir == true){
			circ[i].y += 12;

		}
		else{
			circ[i].y -= 12;
		}

		//Test for level boundary (currently level one only)
		if (circ[i].y == 800 && circ[i].dir == true){
			circ[i].dir = false;
		}
		else if (circ[i].y == 200 && circ[i].dir == false){
			circ[i].dir = true;
		}
		//Print update circle

	}
	if (circ[15].dir == true){
		circ[15].x += 20;
		if (circ[15].x == 840){
			circ[15].dir = false;
		}
		circ[16].x -= 20;
	}
	else{
		circ[15].x -= 20;
		if (circ[15].x == 220){
			circ[15].dir = true;
		}
		circ[16].x += 20;
	}
	change = true;
}
int prevx1 = 220, int prevx2 = 840;

void lvl2circprint(){
	if (change){
		for (int i = 0; i < 14; i++){
			if (circ[i].dir){
				if (circ[i].y == 200){
					setcolor(0);
					fillellipse(circ[i].x, prevy2, 30, 30);
				}
				else{
					setcolor(0);
					fillellipse(circ[i].x, prevy1, 30, 30);
				}


				//prevy1 = circ[i].y;
			}
			else {
				if (circ[i].y == 800){
					setcolor(0);
					fillellipse(circ[i].x, prevy1, 30, 30);
				}
				else{
					setcolor(0);
					fillellipse(circ[i].x, prevy2, 30, 30);
				}
				//prevy2 = circ[i].y;
			}
			setcolor(1);
			fillellipse(circ[i].x, circ[i].y, 30, 30);
		}

		if (circ[0].dir){
			prevy1 = circ[0].y;
			prevy2 = circ[1].y;
		}
		else{
			prevy1 = circ[1].y;
			prevy2 = circ[0].y;
		}

		change = false;
	}


}