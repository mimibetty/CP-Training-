#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int n;
 	cin >> n;

 	long long res = 0;
 	for (int i = 1; i <= n; i++) {
 		cin >> a[i];
 		res += a[i];
 	}
 	sort(a + 1, a + 1 + n, greater<int>() );
 	//for (int i = 1; i <= n; i++) cout << a[i] << ' ';
 	
 	for (int  i = 1; i <= n/3; i++) {
 		res -= (a[3 + 3*(i-1)]) ;
 	} 
 	cout << res;
    return 0;
}