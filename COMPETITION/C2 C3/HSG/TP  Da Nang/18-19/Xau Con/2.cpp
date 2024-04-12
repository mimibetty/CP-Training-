#include<bits/stdc++.h>
using namespace std;

long long a[1000005]; // a so luong so 0
int vt1[1000005]; // vi tri chu a

int main() {
  	freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

 	int k;
 	cin >> k;

 	string s;
 	cin >> s;

 	int  l = s.size();
 	int vt = 1;
 	for (int i = 0; i < l; i++ ) {
 		if (s[i] == '0') {
 			a[i] = a[i-1] + 1;	
 		}
 		else if (s[i] == '1') {
 			vt1[vt] = i;
 			vt++;
 			a[i] = a[i-1] ;	
 		}
 	}   
 	
 	vt--;
 	a[0] = 0;
 	a[l] = a[l-1];
 	vt1[0]= 0;
 	vt1[vt+1] = l;
 	long long res = 0;

 	if (vt < k) {
 		cout << 0;
 		return 0;
 	}

 	if (k == 0) {
 		for (int i = 1; i <= vt + 1; i++) {
 			res += ( (a[vt1[i]] - a[vt1[i-1]]) + 1) * (a[vt1[i]] - a[vt1[i-1]]) / 2;
 		}
 		cout << res ;
 		return 0;
 	}
 	
 	for (int i = 1; i <= vt - k + 1; i++) { 
 		int low = a[vt1[i]] - a[vt1[i-1]];
 		int up = a[vt1[i+k]]- a[vt1[i+k-1]];
 		res += low;
 		res += up;
 		res += (low*up);
 		res++; 
 	}
 	cout << res;

    return 0;
}