#include<bits/stdc++.h>
using namespace std;
 

void solve() {
    int n;
    cin >> n;
    cout << "n = ";
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            cout << i << '^' << cnt;
            if (n > 1) cout << " * ";
        }
    }   
    if (n > 1) cout << n << endl;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    solve();
    return 0;
}