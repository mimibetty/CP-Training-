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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k % 2 == 0) {
        sort(All(s));
        cout << s;
    }
    else {
        vector<char>chan;
        vector<char>le;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) chan.pb(s[i]);
            else le.pb(s[i]);
        } 
        sort(All(chan));
        sort(All(le));
        int x = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 ==0 ) cout << chan[x];
            else {
                cout << le[x];
                x++;
            }
        } 
    }
    EL;
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