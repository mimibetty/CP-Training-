#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

long long ps[20];

long long pw(long long x, long long n) {
    if (n == 0) {
        return 1;
    }
    long long m = pw(x, n / 2);
    if (n % 2 == 0) {
        return m * m ;
    }
    return m * m  * x ;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    long long sum = 0;
    for (int i = 0; i <= 16; i++) {
            sum += (pw(10,i) * 9 * (i+1)) ;
            ps[i] = sum;
        //    cout << i << ' '<< ps[i] << endl;
    }
    int t;
    cin >> t;
    for (int q = 1; q <= t; q++) {
        long long cs = 0;
        long long k;
        cin >> k;

        if (k <= 9) cout << k;
        else {
            for (int i = 0; i <= 16; i++) {
                if (ps[i] == k) {
                    cs = i;
                    break;
                }
                else if (ps[i] > k) {
                    cs = i;
                    break;
                }
            }
            long long d = k - ps[cs-1] ;
            long long num = pw(10,cs) - 1 + (d/(cs+1));
            int surplus = d % (cs+1);

            if (surplus == 0) {
                cout << num % 10;
            }
            else {
                num++;
                string s = to_string(num);
                cout << s[surplus-1];
            }
            //cout << q << ' ' << num << ' ' << cs  ;
        } 
 /*1 - 9
 10 - 99 
 100 - 999*/

        cout << endl;
    }
    return 0;
}