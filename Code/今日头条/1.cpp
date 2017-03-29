#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int N;
	cin >> N;

	vector<int> num(N, 0);
	for (int i = 0; i < N; ++i){
		cin >> num[i];
	}

	sort(num.begin(), num.end());
	int res = 0;
	int count = 1;
	for (int i = 1; i  < N; i++){
		if (num[i] - num[i - 1] <= 10)
			count++;
		else{
			if (count % 3 != 0)
				res += (3 - (count % 3));
			count = 1;
		}
	}

	if (count % 3 != 0)
		res += (3 - (count % 3));

	cout << res << endl;

	return 0;
}

