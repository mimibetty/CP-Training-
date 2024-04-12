#include<bits/stdc++.h>
using namespace std;

long long a[30];
long long d[305];
long long b[100005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    string s;
    cin >> s;

    long long res = 1e9;
    long long n = s.size();
    long long vt1 = 0, vt2 = 0;

    for (long long i = 1; i <= 26; i++) {
        cin >> a[i];
        d[(long long)('a' + i - 1)] = a[i];
    } 
    
    long long t;
    cin >> t;

    for (long long i = 1; i <= n; i++) {
        //char o = s[i-1];
        if (d[(long long)s[i-1]] > t) {
            cout << s[i-1];
            return 0;
        }
        b[i] = b[i-1] + d[(long long)s[i-1]];
       // cout << b[i] << ' ';
        //cout << d[o] << ' ';
    }
    //cout << endl;


    for (long long i = 0; i < n; i++) {
        if (t + b[i] > b[n]) continue;
        auto j = upper_bound(b + 1, b + 1 +n, t + b[i]) - b;
      
        //cout << i << ' '<< b[j] - b[i] <<' '; 
        //cout << j - i<< endl;
        res = min(res , j - i);
    }

    for (long long i = 0; i < n; i++) {
        if (t + b[i] > b[n]) continue;
        auto j = upper_bound(b + 1, b + 1 +n, t + b[i]) - b;
        
        if (j - i == res) {
            for (long long l = i; l < j; l++) {
                cout << s[l];
            }
            return 0;
        }
    }
    cout << -1;
    //cout << res;
    return 0;
}