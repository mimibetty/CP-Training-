#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	string s,a;
 	cin >> s;
 	a += s[0];
 	int l = s.size();
 	for (int i = 1 ; i< l/2;i++) {
 		int n = a.size();
 		for (int j = 0; j < n ; j++) {
 		 	if (a[i] != s[i+j]) {
 		 		a+= s[i+j];
 		 		break;
 		 	}		 	
 		}
 	}   
 	cout << a;
    return 0;
}