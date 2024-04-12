#include<bits/stdc++.h>
using namespace std;

int c[1000005];
int u[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	

	for (int i = 0; i < n; i++) {
		if (s[i] == 'c') c[i+1] = c[i] + 1;
		else c[i+1] = c[i];

		if (s[i] == 'u') u[i+1] = u[i] + 1;
		else u[i+1] = u[i];
	}

	long long res1 = 0, res2 = 0;
	for (int i = 0 ; i <  n; i++) {
		if (s[i] == 'c') {
			res1 += (u[n] + 1 - u[i+1]);
		}
		if (s[i] == 'u') {
			res2 += (c[n+1] + 1 );
		}
	}
	cout << max(res1, res2);

    return 0;
}