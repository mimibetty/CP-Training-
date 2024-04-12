#include<bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int h,m,s;
 	cin >> h >> m >> s;
  	s++;
  	if (s >= 60 ) {
  		m++;
  		s%=60;
  	}   
  	if (m >= 60 ) {
  		h++;
  		m%=60;
  	} 
   	if (h >= 24) {
  		h%=24;
  	}     
  	cout << h << ':' << m << ':' << s;
    return 0;
}