#include<iostream>
#include<vector>
#include<string>
using namespace std;

int cnt_substr(string& s1, string& s2) {
	int i = 0, cnt = 0;
	if (s1.find(s2) == -1)
		return 0;
	int len = s2.size();
	while (i < s1.size()) {
		string ss(s1, i, len);
		if (ss == s2)
			cnt++;
		++i;
	}
	return cnt;
}
int main() {
	string s1, s2;
	cout << "type a string:" << endl;
	getline(cin, s1);
	cout << "type substring you want to find:" << endl;
	getline(cin, s2);
	cout << "number of repeating substring in string is: " << cnt_substr(s1, s2);
	return 0;

}
