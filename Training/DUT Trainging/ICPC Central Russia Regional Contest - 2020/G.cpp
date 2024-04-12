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

void solve() {
    ll x,y;
    cin >> x >> y;

    vector<int>res;
    for (int i = 0 ; i <= 3*y; i++) {
        double aa = 1.0000*i/3;
        int a = i/3;
        double hieu1 = (aa - a);
        if (hieu1 >= 0.5) {
            a++;
        }

        double aa2 = 1.0000*i/2;
        int a2 = i/2;
        double hieu2 = (aa2 - a2);
        if (hieu2 >= 0.5) {
            a2++;;
        }
        if (a == x && a2 == y)    res.pb(i);
        // cout << i << ' ' << a << ' ' << a2 
        // <<' ' <<hieu1 << ' ' << hieu2 << endl;
    }
    if (res.size() == 0) {
        cout << 0 << endl;
    }
    else {
        for (auto i : res) cout << i << ' ';
    }   
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