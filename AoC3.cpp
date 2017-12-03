#include<iostream>
using namespace std;

void SpiralCheck(int val, int size) {
	int x, y, dx, dy, t;
	x = y = dx = 0;
	dy = -1;
	int maxI = size*size;

	for (int i = 0; i < maxI; i++) {
		if ((-size/2 <= x) && (x <= size/2) && (-size/2 <= y) && (y <= size/2)){
			if ((i+1) == val) {
				cout << x << " " << y << endl;
				return;
			}
		}

		if ((x == y) || ((x < 0) && (x == -y)) || ((x > 0) && (x == 1-y))){
			t = dx;
			dx = -dy;
			dy = t;
		}

		x += dx;
		y += dy;
	}
}

void SpiralCompute(int val, int size) {
	int arr[size][size];

	int x, y, dx, dy, t;
	x = y = dx = 0;
	dy = -1;
	int maxI = size*size;
	int stepSize = size/2;
	int indX, indY;

	for (int i = 0; i < maxI; i++) {
		if (i == 0) {
			arr[size/2][size/2] = 1;
		}
		else if ((-size/2 <= x) && (x <= size/2) && (-size/2 <= y) && (y <= size/2)){
			indX = x + stepSize;
			indY = y + stepSize;

			arr[indX][indY] = arr[indX+1][indY] + arr[indX+1][indY-1] + arr[indX][indY-1] + arr[indX-1][indY-1] + arr[indX-1][indY] + arr[indX-1][indY+1] + arr[indX][indY+1] + arr[indX+1][indY+1];
			
			if (arr[indX][indY] > val) {
				cout << arr[indX][indY] << endl;
				return;
			}
		}

		if ((x == y) || ((x < 0) && (x == -y)) || ((x > 0) && (x == 1-y))){
			t = dx;
			dx = -dy;
			dy = t;
		}

		x += dx;
		y += dy;
	}

}

int main() {

//	SpiralCheck(361527, 602);
	SpiralCompute(361527, 602);

	return 0;
}