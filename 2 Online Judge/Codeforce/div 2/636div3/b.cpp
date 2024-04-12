#include<bits/stdc++.h>
using namespace std;
long long a[35];
long long b[35];

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);


    int t;
    cin >> t;
    for (int q = 1; q <= t; q++) {
    	long long n;
    	cin >> n;
    	if (n % 4 == 0) {
            long long sum1 = 0, sum2 = 0;
            cout << "YES" << endl;
            for (int i = 2; i<= n; i+=2) {
                cout<<i<<' ';
                sum2+=i;
            }
            for (int i = 1; i<= n-2; i+=2) {
                    cout<<i<<' ';
                    sum1 +=i;
            }

            cout << sum2 - sum1;

    	}
    	else cout << "NO";
        cout << endl;
    }
    return 0;
}
