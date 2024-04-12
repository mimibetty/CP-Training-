#include<bits/stdc++.h>
using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
  	long long n, res = 0;
  	cin >> n;
  	for (int i = 1; i <= n/3-1; i++) {
  		long long a,b;
  		a = i+ 1;
  		b = n - a - i;
  		res += (b-a)/2;
  		if ( (b-a) != ((b-a)/2)*2 ) res++;
  		//cout << res  << endl;
  	}
  	cout << res;
    return 0;
}