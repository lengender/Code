#include <stdio.h>
#include <stdlib.h>

void get_time(int *hour, int *min, int *second, int const time_diff_second)
{
	// implement your code here
	int h = *hour, m = *min, s = *second; 
	int flag = 0;
	int time = time_diff_second;
	if (time_diff_second < 0){
		flag = 1;
		time = -time_diff_second;
	}

	int min_time = time / 60;
	int sec_time = time % 60;
	int hour_count = min_time / 60;
	min_time = min_time % 60;
	int sec_1 = 0;
	int sec_2 = 0;
	int min_1 = 0;
	int min_2 = 0;

	if (flag == 0){
		sec_1 = (s + sec_time) / 60;
		sec_2 = (s + sec_time) % 60;

		min_1 = (m + sec_1 + min_time) / 60;
		min_2 = (m + sec_1 + min_time) % 60;

		h = (h + min_1 + hour_count) % 24;

		//printf("%2d %2d %2d\n", h, min_2, sec_2);
		*hour = h;
		*min = min_2;
		*second = sec_2;
	}
	else{
		
		if (s - sec_time < 0){
			m--;
			s = s + 60 - sec_time;
		}
		else{
			s = s - sec_time;
		}

		if (m <= 0){
			if (h > 0) h--;
			else h = 23;
			m = 60 + m;
		}

		if (m - min_time < 0){
			if(h > 0) h--;
			else h = 23;
			m = m + 60 - min_time;
		}
		else{
			m = m - min_time;
		}

		hour_count = hour_count % 24;

		if (h - hour_count < 0)
			h = h + 24 - hour_count;
		else h = h - hour_count;

		h = h % 24;
		//printf("%2d %2d %2d\n", h, m, s);
		*hour = h;
		*min = m;
		*second = s;
	}
}

int main()
{
	int hour, min, second, time_diff_second;

	while (scanf("%d:%d:%d,%d", &hour, &min, &second, &time_diff_second) != EOF) {

		get_time(&hour, &min, &second, time_diff_second);
		printf("%02d %02d %02d\n", hour, min, second);
	}
}