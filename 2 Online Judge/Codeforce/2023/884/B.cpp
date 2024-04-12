/*
link submit: 
Note:
*/
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

int a[100];
int mexx(int l, int r) {
    map<int,int>d;
    for (int i = l; i <= r; i++) d[a[i]]++;
    for (int i = 1; i <= 1000000; i++) {
        if (d[i] == 0) return i;
    } 
    return 0;
}
bool snt(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}
void solve() {
    int n;
    cin >> n;

    vector<int>f;
    int res = 0;
    int tmp = 0;

    for  (int i = 1; i <= n; i++) a[i] = i;
    do {
        tmp = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (snt(mexx(i,j)) == 1) tmp++;
            }
        }
        if (res < tmp) {
            res = tmp;
            f.clear();
            for (int i = 1; i <= n; i++) f.pb(a[i]);
        }
        if (tmp == 12) {
            for (int  i = 1; i <= n; i++) cout << a[i] << ' '; 
            cout << tmp << endl;
            // cout << endl;
        }

    } while(next_permutation(a + 1, a + 1 + n) );
    // for (auto i : f) cout << i << ' ';
    // cout <<tmp <<endl;
    EL;
    cout << "REES  " << res << endl;
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
    while(t--)    
    solve();
    
    return 0;
}