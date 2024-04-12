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

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    string aa1,bb1,aa2,bb2;
    string a,b;
    cin >> a >> b;
    for (int i = 0; i < a.size();i++ ) {
        if (int(a[i]) % 2 == 0) {
            aa1.pb(a[i]);
        }
        else bb1.pb(a[i]);
    }

    for (int i = 0; i < b.size();i++ ) {
        if (int(b[i]) % 2 == 0) {
            aa2.pb(b[i]);
        }
        else bb2.pb(b[i]);
    }


    if (aa1 == aa2 && bb1 == bb2) {
        cout << "Yes" <<endl;
    }
    else cout << "No" <<endl;
    return 0;
}