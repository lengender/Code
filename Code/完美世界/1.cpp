#include <stdio.h>


void ball(int w, int h, int x, int n)
{
	//implement your code here
	int y = 0;
	int vx = 1, vy = 1;
	while (n > 0){
		x += vx;
		y += vy;

		if (x >= w || x <= 0)
			vx = -vx;

		if (y >= h || y <= 0)
			vy = -vy;

		if (y <= 0){
			printf("%d ", x);
			n--;
		}
	}
	printf("\n");
}

int main()
{
	int w, h, x, n;
	while (scanf("%d%d%d%d", &w, &h, &x, &n) != EOF) {
		ball(w, h, x, n);
	}
	return 0;
}
