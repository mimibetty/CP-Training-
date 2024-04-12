#include<bits/stdc++.h>
using namespace std;

//int a[1000005];

int trace[1000005]; // trace[i] là ước NT lớn nhất của i
int a[100005];
int n,k;

void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (trace[i] == 0) {
            for (int j = i; j <= n; j += i) {
                trace[j] = i;
            }
        }
    }
}


bool solve(int x) {
    int cnt = 1;
    int gcd = a[1];

    for (int i = 1; i <= n; i++) {
        gcd = __gcd(a[i],gcd);

        if (trace[gcd] < x) {
            gcd = a[i];
            cnt++;
            if (trace[gcd] < x) return 0;
        }
    }
    if (cnt > k) return 0;
    return 1;
}
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    sieve(1e6);

    vector<int>primes;
    primes.push_back(0);
    for (int i = 2; i <= 1e6; i++) {
        if (trace[i] == i) primes.push_back(i);
    }


    int lower = 1, upper = primes.size()-1;
        while (lower < upper) {
            int mid = (lower + upper) / 2;          
            if (solve(primes[mid]) == 0) {
                upper = mid;
            }
            else {
                lower = mid + 1;
            }
           // if (solve(mid) == 1) cout << mid << endl; 
        }
    if (solve(primes[lower]) == 0) lower--; 
    cout << primes[lower];

    return 0;
}