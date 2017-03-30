#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

void splict(string str, set<string> &strSet){
	int i = 0, pos;
	while (i < str.size()){
		pos = str.find_first_of(" ");
		string tmp;
		if (pos != string::npos){
			tmp = str.substr(i, pos - i);
			str = str.substr(pos + 1);
		}
		else{
			tmp = str.substr(i);
			i = str.size();
		}

		for (int i = 0; i < tmp.size(); ++i){
			tmp[i] = tolower(tmp[i]);
		}
		strSet.insert(tmp);
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<string> str;
	vector<set<string>> wordSet;
	getchar();
	for (int i = 0; i < n + m; ++i){
		//fflush(stdin);
		
		char tmp[520];
		cin.getline(tmp, 512);
		string s(tmp);
		str.push_back(s);
		set<string> strSet;
		splict(s, strSet);
		wordSet.push_back(strSet);
	}

	for (int i = n; i < m + n; ++i){
		set<string>::iterator iter = wordSet[i].begin();
		vector<int> res(n);
		int max_count = -1;
		int flag = -1;
		for (; iter != wordSet[i].end(); ++iter){
			for (int j = 0; j < n; ++j){
				if (wordSet[j].count(*iter) > 0){
					res[j]++;
					if (res[j] > max_count){
						max_count = res[j];
						flag = j;
					}
				}
			}
		}
		cout << str[flag] << endl;
	}

	
		return 0;
}

