#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define bit(n,i)  ((n>>i) & 1) 
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;


const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long double PI = acos(-1);

void solve() {
    int n;
    long long x, y;
    cin >> n >> x >> y;
    vector<long long> v(n);
    long long maxV = 0;
    for (int i = 0; i < n - 1; ++i) {
        cin >> v[i];
        if (v[i] > maxV) {
            maxV = v[i];
        }
    }
    cin >> v[n - 1];
    long long my_v = v[n - 1];

    if (my_v > maxV) {
        cout << 0 << endl;
        return;
    }

    double min_time = (double)x / maxV;

    long long ans = -1;
    long long left = 1, right = y;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        double my_time;

        if (mid >= x) {
            my_time = (double)x / mid;
        } else {
            my_time = 1.0 + (double)(x - mid) / my_v;
        }
        
        if (my_time < min_time) {
            ans = mid;
            right = mid - 1; 
        } else {
            left = mid + 1; 
        }
    }

    cout << ans << endl;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
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

