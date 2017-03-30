#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int search_first(int x, vector<int>& num){
	int high = num.size() - 1;
	int low = 0, mid = 0;
	while (low < high){
		if (mid > 0 && num[mid] >= x && num[mid - 1] < x)
			return mid;

		mid = low + (high - low) / 2;
		if (num[mid] > x)
			high = mid - 1;
		else if (num[mid] < x)
			low = mid + 1;
	}
	return low;
}
int main(){
	int n, q;
	cin >> n >> q;
	vector<int> A(n);
	vector<int> Q(q);
	vector<int> num(n);
	
	int i = 0;
	int tmp;
	for (i = 0; i < n; ++i){
		cin >> A[i];
	}
	for (i = 0; i < n; ++i){
		cin >> tmp;
		tmp = tmp > A[i] ? A[i] : tmp;
		num[i] = tmp;
	}
	int tmp2;
	for (i = 0; i < q; ++i){
		cin >> tmp >> tmp2;
		Q[i] = tmp > tmp2 ? tmp : tmp2;
	}
	int count = 0;
	sort(num.begin(), num.end());

	for (i = 0; i < q; ++i){
		count = 0;
		int pos = search_first(Q[i], num);
		count = num.size() - pos - 1;
		cout << count << endl;
	}

	return 0;
}