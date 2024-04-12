#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int q = 1; q <=t ; q++) {
    	cout << "Case #" << q << ':' << '\n';
    	int n, cs1 = 0, cs2= 0;
    	cin >> n;
    	char a;
    	for (int i = 1; i <= n;i++ ) {
    		cin >> a;
    		if (a == 'A') cs1++;
    		else cs2++;
    	}
    	if ( abs(cs1-cs2) <= 1) cout << 'Y';
    	else cout << 'N';
    	cout << '\n';
    }
    return 0;
}