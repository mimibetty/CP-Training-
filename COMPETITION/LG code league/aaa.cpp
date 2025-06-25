#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;

long long n, x, y;
long long a[1005];

bool canWin(long long z) {
    double my_time;
    if (z >= x) {
        my_time = (double)x / z;
    } else {
        my_time = 1.0 + (double)(x - z) / a[n];
    }
    
    for (int i = 1; i < n; i++) {
        double other_time = (double)x / a[i];
        if (my_time >= other_time) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (!canWin(y)) {
        cout << -1 << endl;
        return;
    }

    if (canWin(0)) {
        cout << 0 << endl;
        return;
    }

    long long left = 1, right = y;
    long long answer = y;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (canWin(mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << answer << endl;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}