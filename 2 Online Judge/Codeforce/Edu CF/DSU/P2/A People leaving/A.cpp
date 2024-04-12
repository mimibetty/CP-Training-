#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
 
#define For(i, l, r) for (int i = l; i < r; i++)
#define REP(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl
#define SQ(a) a*a
 
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long long oo = 1e18 + 7;
const int MOD = int(1e9)+7;
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

int root_right[1000005];
int n,t;

void erase(int u) {
    root_right[u] = root_right[u+1];
    for (int i = u - 1; i >= 1; i--) {
        if (root_right[i] != u) break;
        if (root_right[i] == 0) break;
        root_right[i] = root_right[u];     
    }
}

void find(int u) {
    cout << root_right[u] << endl;
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> t;

    for (int i = 0; i <= n; i++) root_right[i] = i;

    for (int z = 1; z <= t; z++) {
        cout << "STT  " << z << endl; 
        string s;
        cin >> s;
        int u;
        cin >> u;

        if (s == "-") {
             erase(u);
             cout << s << ' ';
             cout << u << endl;
             for (int i = 1; i <= n; i++) cout << root_right[i] << ' ';
             cout << endl;   
        }
        else {
            cout << s << ' ' << u << endl;
            if (root_right[u] == 0 || root_right[u] > n) cout << -1 << endl;
            else cout << root_right[u] << endl;
            
            for (int i = 1; i <= n; i++) cout << root_right[i] << ' ';
            cout << endl;
        }
    }
    return 0;
}