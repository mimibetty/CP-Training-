#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
 
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
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

ll n,c,d;

void show(queue<int>q) {
    while(q.empty() == 0) {
        cout << q.front() << ' ';
        q.pop();
    }
}
long long a[200005];
bool doit(int mid) {
    queue<int>q;
    for (int i = 1; i <= mid; i++) {
        if(i > n) {
            q.push(0);
            continue;
        }
        q.push(a[i]);
    }
    ll sum = 0;

    // cout << "STT   " << mid << endl;
    // show(q);
    // cout << endl;

    for (int i = 1; i <= d; i++) {
        ll z = q.front();
        q.pop();
        q.push(z);
        sum+=z;
        // cout << i << ' ' << sum <<endl;
        if(sum >= c) {
            // cout << endl;
            // cout <<"SUM   " << sum <<endl;
            // cout <<endl;
            return 1;
        }
    }

    return 0;
}

void solve() {
    cin >> n >> c >> d;
    ll maxxx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxxx = max(maxxx, a[i]);
    }
    if (maxxx * d < c) {
        cout << "Impossible" << endl;
        return;
    }
    sort(a+1,a+1+n);    
    reverse(a+1,a+1+n);
    ll ss = 0;
    for (int i = 1; i <= min(d,n); i++) {
        ss += a[i];
    }

    if (ss >= c) {
        cout << "Infinity" << endl;
        return;
    }
    

    int l = 0;
    int r = d + 1; 
    int mid;

    while (l < r) {
        mid = (l + r + 1) / 2;
        if (doit(mid)) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
        // cout << l <<' ' << r <<endl;
    }
    cout << l - 1 <<endl;

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
    while (t--) solve();
    return 0;
}