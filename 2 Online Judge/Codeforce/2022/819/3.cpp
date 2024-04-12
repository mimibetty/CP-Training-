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
    int n;
    string s;
    cin >> n;
    cin >> s;

    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    int res = 0, cnt = 0;    
    for (int i = 0; i < 2*n-1; i++) {
        int l = i,r = i+1;
        if (l >= 0 && r < 2*n && s[l] == '(' && s[r] == ')') cnt++;

        while (l >= 0 && r < 2*n && s[l] == '(' && s[r] == ')') {
            // cout << l << ' ' << r << endl;
            res++;
            l--;
            r++;
            if (l < 0 || r >= 2*n) {
                break;
            }
            if (s[l] != '(' || s[r] != ')') break;
        }
    }
    cout <<res - cnt + 1<<endl;
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


3 
1 4     5
2 5 7 
5 9 
14