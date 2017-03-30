#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> num(n, 0);
	for (int i = 0; i < n; ++i)
		cin >> num[i];

	int len = 0;
	int max_len = -1;
	int start = -1, end = -1;
	int i = 0;
	int flag_up = 0, flag_down = 0;
	while (i < n){
		if (i == 0){
			//len = 1;
			//max_len = 1;
			//start = 0;
			//end = 0;
			i++;
			continue;
		}

		if (num[i] > num[i - 1]){
			flag_up = 1;
			if (flag_down){
				if (len > max_len){
					end = i - 1;
					start = end - len;
					max_len = len;
				}
				flag_down = 0;
				flag_up = 0;
				len = 1;
			}
			else{
				len++;
			}
		}
		else{
			flag_down = 1;
			len++;
		}
		i++;
	}

	if (flag_up && flag_down && len > max_len){
		end = n - 1;
		start = end - len;
	}
	cout << start << " " << end << endl;

	return 0;
}

