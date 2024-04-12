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

int a[100005];
void solve() {
    long long n,m;
    cin >> n >> m;
    
    if (n == 1) {
        cout << "yes" << endl;
        cout << m << endl;
        return;
    }
    if (n > m) {
        cout << "no" << endl;
        return;
    }

    if (m % n == 0) {
        cout << "yes" <<endl;
        for (int i = 1; i <= n; i++) cout << m/n << ' ';
        cout << endl;
        return;
    }

    if (n % 2 == 1) {
        if (m % 2 == 1) {
            if (n-1 + 3 > m) {
                cout << "no" << endl;
                return;
            }
        }
        else {
            if (n-1 + 2 > m) {
                cout << "no" << endl;
                return;   
            }
        }
        cout << "yes" << endl;
        for (int i = 1; i < n; i++) {
            cout << 1 << ' ';
        }
        cout << m - n + 1 << endl;
    }
    else {
        if (m%2 == 0) {
            cout << "yes" << endl;
            for (int i = 1; i < n-1; i++) cout << 1 << ' ';
            cout << (m - n + 2)/2 << ' ' << (m - n + 2)/2 << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
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