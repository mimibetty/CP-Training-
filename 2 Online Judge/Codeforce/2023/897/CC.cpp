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

int n;
void out(ll x) {
     cout << x << '\n'; cout.flush();
}
void solve() {
    cin >> n;
    map<int,int>d;
    for (int i = 1; i<= n; i++) {
        int a;
        cin >> a;
        d[a]++;
    }
    int mex = 0;
    for (int i = 0; i <= 2*n; i++) {
        if (d[i] == 0) {
            mex = i;
            break;
        }
    }
    out(mex);
    // int y;
    // cin >> y;
    // while (y != -1) {
    //     cout << y << endl;
    //     cin >> y;
    // }

    // for (int i = 1; i <= n; i++) {
    //     int y;
    //     cin >> y;
    //     if (y == -1 || y == -2) break;
    //     else {
    //         out(y);
    //     }
    //     cout << endl;
    // }
}

int main() {
    // if(fopen("input.txt", "r")) {
    //     freopen("input.txt","r",stdin);
    //     // freopen("output.txt","w",stdout);
    // }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    t = 1;
    cin >> t;

    while (t--)
    solve();

    return 0;
}
