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
int d[1000005];
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    int b = 0, bb = 0;
    for (int i = n; i >= 1; i--) {
        if (s[i] == 'B' || s[i] == 'b') {
            if (s[i] == 'B') bb++;
            else b++;
        }
        else {
            d[i] = 1;
            if (s[i] >= 'A' && s[i] <= 'Z') {
                if (bb > 0) {
                    d[i] = 0;
                    bb--;
                }
            }
            else {
                if (b > 0) {
                    d[i] = 0;
                    b--;
                }
            }

        }
    }
    for (int i = 1; i <= n; i++) {
        if (d[i]) {
            d[i] = 0;
            cout << s[i] ;
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
    t = 1;
    cin >> t;
    while (t--)    
    solve();
    
    return 0;
}