
#include<bits/stdc++.h>
using namespace std;

int aa[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	long long n,m;
 	cin >> n >> m;
 	long long k = 0;

 	string a,b;
 	for (int i = 0; i < n; i++) {
 		cin >> a;
 		k = a.size();
 		aa[i+1] = k;

 	}
 	for (int i = 0; i < m; i++) {
 		cin >> b ;
 		k = b.size();
 		aa[i+1+n] = k;
 	}

 	for (int i = 1; i <= m+n ; i++) {
 		for (int j = 1; j <= m + n +1; j++) {
 			aa[j] = (aa[j] + aa[j+1]) % 10;
 		//	cout << aa[i] <<' ';
 		}
 		//cout <<endl;
 	}
 	cout << aa[1] << aa[2];
    return 0;
}