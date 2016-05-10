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
	circ[15].y = 600;
	circ[15].dir = true;
	circ[16].x = 1700;
	circ[16].y = 400;
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
		if (circ[15].x == 1700){
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
int prevx1 = 220, prevx2 = 1700;

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
	if (circ[15].dir){
		if (circ[15].x == 220){
			setcolor(0);
			fillellipse(prevx1, circ[15].y, 30, 30);
			fillellipse(prevx2, circ[16].y, 30, 30);
			setcolor(1);
			fillellipse(circ[15].x, circ[15].y, 30, 30);
			fillellipse(circ[16].x, circ[16].y, 30, 30);

		}
		else{
			setcolor(0);
			fillellipse(prevx2, circ[16].y, 30, 30);
			fillellipse(prevx1, circ[15].y, 30, 30);
			setcolor(1);
			fillellipse(circ[15].x, circ[15].y, 30, 30);
			fillellipse(circ[16].x, circ[16].y, 30, 30);
		}
		prevx1 = circ[15].x;
		prevx2 = circ[16].x;
	}
	else{
		if (circ[15].x == 1700){
			setcolor(0);
			fillellipse(prevx2, circ[15].y, 30, 30);
			fillellipse(prevx1, circ[16].y, 30, 30);
			setcolor(1);
			fillellipse(circ[15].x, circ[15].y, 30, 30);
			fillellipse(circ[16].x, circ[16].y, 30, 30);
		}
		else{
			setcolor(0);
			fillellipse(prevx1, circ[16].y, 30, 30);
			fillellipse(prevx2, circ[15].y, 30, 30);
			setcolor(1);
			fillellipse(circ[15].x, circ[15].y, 30, 30);
			fillellipse(circ[16].x, circ[16].y, 30, 30);
		}
		prevx1 = circ[16].x;
		prevx2 = circ[15].x;
	}

}

void lvl3circsetup(){

}

void lvl3circupdate(){

}

void lvl3circprint(){

}

int randptx, randpty, prevrandx = 1919 / 2, prevrandy = 1019 / 2;
double m, b;
bool goingrt, change2;
int randptx2, randpty2, prevrandx2 = (1919 / 2) + 60, prevrandy2 = 1019 / 2;
double m2, b2;
bool goingrt2, change3;

void randcircsetup(){
	circ[13].x = (1919 / 2) + 60;
	circ[13].y = (1019 / 2);
	circ[14].x = 1919 / 2;
	circ[14].y = 1019 / 2;
	setcolor(1);
	fillellipse(circ[13].x, circ[13].y, 30, 30);
	fillellipse(circ[14].x, circ[14].y, 30, 30);

	randptx2 = rand() % 1919;
	randpty2 = rand() % 1019;
	m2 = ((double)circ[13].y - (double)randpty2) / ((double)circ[13].x - (double)randptx2);
	b2 = -(m * circ[13].x) + circ[13].y;
	goingrt2 = rand() % 2;

	randptx = rand() % 1919;
	randpty = rand() % 1019;
	m = ((double)circ[14].y - (double)randpty) / ((double)circ[14].x - (double)randptx);
	b = -(m * circ[14].x) + circ[14].y;
	goingrt = rand() % 2;
}



void randcircupdate(){


	if (goingrt){
		prevrandx = circ[14].x;
		prevrandy = circ[14].y;

		circ[14].x += 15;
		circ[14].y = (int)(m*(circ[14].x) + b);
		change2 = true;
		
		checkline:
		if (circ[14].x + 15 > 1700){
			goto getnewline;
		}
		if (m >= 0 && (m* (circ[14].x + 15)) + b > 925){
			goto getnewline;
		}
		if (m < 0 && (m* (circ[14].x + 15)) + b < 90){
			goto getnewline;
		}


	}
	else{
		prevrandx = circ[14].x;
		prevrandy = circ[14].y;
		
		circ[14].x -= 15;
		circ[14].y = (int)(m * circ[14].x + b);
		change2 = true;
		
		checkline2:
		if (circ[14].x - 15 < 235){
			goto getnewline;
		}
		if (m < 0 && ((m* (circ[14].x - 15)) + b > 925)){
			goto getnewline;
		}
		if (m >= 0 && ((m* (circ[14].x - 15)) + b < 90)){
			goto getnewline;
		}
	
	}

	if (false){
	getnewline:

		randptx = rand() % 1919;
		randpty = rand() % 1019;
		m = ((double)circ[14].y - (double)randpty) / ((double)circ[14].x - (double)randptx);
		b = -(m * circ[14].x) + circ[14].y;


		goingrt = rand() % 2;
		if (goingrt){
			goto checkline;
		}
		else {
			goto checkline2;
		}
	}


	if (goingrt2){
		prevrandx2 = circ[13].x;
		prevrandy2 = circ[13].y;
		
		circ[13].x += 15;
		circ[13].y = (int)(m2*(circ[13].x) + b2);
		change3 = true;

	checkline3:
		if (circ[13].x +15 > 1700){
			goto getnewline2;
		}
		if (m2 >= 0 && (m2* (circ[13].x + 15)) + b2 > 925){
			goto getnewline2;
		}
		if (m2 < 0 && (m2* (circ[13].x + 15)) + b2 < 90){
			goto getnewline2;
		}


	}
	else{
		prevrandx2 = circ[13].x;
		prevrandy2 = circ[13].y;

		circ[13].x -= 15;
		circ[13].y = (int)(m2 * circ[13].x + b2);
		change3 = true;

	checkline4:
		if (circ[13].x - 15 < 235){
			goto getnewline2;
		}
		if (m2 < 0 && ((m2* (circ[13].x - 15)) + b2 > 925)){
			goto getnewline2;
		}
		if (m2 >= 0 && ((m2* (circ[13].x - 15)) + b2 < 90)){
			goto getnewline2;
		}

	}

	if (false){
	getnewline2:

		randptx2 = rand() % 1919;
		randpty2 = rand() % 1019;
		m2 = ((double)circ[13].y - (double)randpty2) / ((double)circ[13].x - (double)randptx2);
		b2 = -(m2 * circ[13].x) + circ[13].y;


		goingrt2 = rand() % 2;
		if (goingrt2){
			goto checkline3;
		}
		else {
			goto checkline4;
		}
	}


}

void randcircprint(){
	if (change2){
		setcolor(0);
		fillellipse(prevrandx, prevrandy, 30, 30);

		setcolor(1);
		fillellipse(circ[14].x, circ[14].y, 30, 30);
		
		change2 = false;
	}
	
	if (change3){
		setcolor(0);
		fillellipse(prevrandx2, prevrandy2, 30, 30);

		setcolor(1);
		fillellipse(circ[13].x, circ[13].y, 30, 30);

		change3 = false;
	}

}