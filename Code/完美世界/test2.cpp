#include<iostream>
#include<vector>
using namespace std;
//Ë®ÏÉ»¨Êý
bool judge(int n){
	int sum = 0;
	int tmp = n, bit = 0;
	while (tmp){
		bit = tmp % 10;
		sum += bit * bit * bit;
		tmp /= 10;
	}

	if (sum == n)
		return true;

	return false;
}

int main(){
	int m, n;
	while (cin >> m >> n){
		vector<int> res;

		for (int i = m; i <= n; ++i){
			if (judge(i))
				res.push_back(i);
		}
		if (res.empty())
			cout << "no" << endl;
		else{
			for (int i = 0; i < res.size() - 1; ++i)
				cout << res[i] << " ";
			cout << res[res.size() - 1] << endl;
		}
	}
	return 0;
}