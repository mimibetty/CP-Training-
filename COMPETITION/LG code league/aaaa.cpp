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
    int n, x, y;
    cin >> n >> x >> y;
    
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<double> end_time(n-1);
    for(int i = 0; i < n-1; i++) {
        end_time[i] = (double)x / v[i];
    }
    
    sort(end_time.begin(), end_time.end());
    double fastest_time = end_time[0];
    
    if(v[n-1] > v[0]) {
        cout << 0 << endl;
        return;
    }
    
    int left = 0, right = y;
    int ans = -1;
    
    while(left <= right) {
        int mid = (left + right) / 2;
        
        double our_time;
        if(mid >= x) {
            our_time = 1.0; 
        } else {
            our_time = 1.0 + (double)(x - mid) / v[n-1];
        }
        
        bool ok = true;
        for(int i = 0; i < n-1; i++) {
            if(abs(end_time[i] - our_time) < 1e-9) {
                ok = false;
                break;
            }
        }
        
        if(ok && our_time < fastest_time) {
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
    while(t--) {
        solve();
    }
    return 0;
}

