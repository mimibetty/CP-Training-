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
 
const long long oo = 1e18 + 7;
const int MOD = int(1e9)+7;
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

pair<int,int>dx[10000005];
map<pair<int,int>, int>dy;

void build(int stt, int height, int p, int q) {
    if (height == 17) return;

    dx[stt] = {p,q};
    dy[{p,q}] = stt;

    build(stt * 2, height + 1, p, q + p);
    build(stt * 2 + 1, height + 1, q + p, q);
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    build(1,1,1,1);

    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;

            cout << dx[x].fi << ' ' << dx[x].se <<endl;
        }
        else {
            int ax,ay;
            cin >> ax >> ay;
            cout << dy[{ax,ay}] << endl;
        }
    }
    return 0;
}