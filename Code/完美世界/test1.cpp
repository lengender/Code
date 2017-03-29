#include<stdio.h>
#include<math.h>
int main(){
	int m, n;
	int i = 0;
	while (scanf("%d%d", &n, &m) == 2){
		double tmp = n * 1.0;
		double sum = 0.0;
		for (i = 1; i < m; ++i){
			sum += tmp;
			tmp = sqrt(tmp);
		}
		sum += tmp;
		printf("%.2lf\n", sum);
	}

	return 0;
}