#include <bits/stdc++.h>
using namespace std;

const int lim7 = 1e7 + 5;
int trace[10000005]; // trace[i] là ước NT lớn nhất của i
int a[10000005];
int s[10000005];

// faster
void sieve(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (trace[i] == 0) { //if i is prime
            for (int j = i * i; j <= n; j += i) {
                if (trace[j] == 0) {
                    trace[j] = i;
                }
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (trace[i] == 0) {
            trace[i] = i;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    vector<int>primes;
    sieve(1e7);

    a[1] = 0
    for (int i = 2; i <= 1e7; i++) {
        int k = i;
        int cnt = 1;
        while (k != 1) {
            k /= trace[k];
            cnt++;
        }   
        if (cnt == 4) a[i] = 1;
        else a[i] = 0;
    }

    
    for (int i = 1; i <= 1e7; i++) {
        s[i] = s[i-1] + a[i]; 
    }

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int l,r;
        cin >> l >> r;
        cout << s[r] - s[l-1];
        cout << endl;
    }

    return 0;
}