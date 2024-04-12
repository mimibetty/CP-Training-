#include<bits/stdc++.h>
using namespace std;

//int a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    string s;
    getline (cin , s);
    s += ' ';
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
    	//cout << cnt;
    	if (s[i] == ' ') {
    		cout << cnt << ' ';
    		cnt = 0;
    		
    	}
    	else cnt++;
    }
    cout << s;

    return 0;
}