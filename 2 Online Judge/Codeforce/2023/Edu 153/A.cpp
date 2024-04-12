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
    string s;
    cin >> s;
    int n = s.size();
    string s1,s2;
    for (int i = 1; i <= n; i++) {
        s1 += '(';
    }
    for (int i = 1; i <= n; i++) {
        s1 += ')';
    }
    for (int i = 1; i <= n; i++) {
        s2 += "()";
    }

    bool ok1 = 1;
    for (int i = 0; i <= n; i++) {
        string z;
        for (int j = 0; j < n; j++) {
            z += s1[i+j];
        }
        // cout << z << endl;
        if (z == s) {
            ok1 = 0;
            break;
        }
    }
    bool ok2 = 1;
    for (int i = 0; i <= n; i++) {
        string z;
        for (int j = 0; j < n; j++) {
            z += s2[i+j];
        }
        // cout << z << endl;
        if (z == s) {
            ok2 = 0;
            break;
        }
    }
    // cout << s1 << ' ' << s2 << endl;
    if (ok1 == 0 && ok2 == 0) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        if (ok1 == 1) cout << s1 <<endl;
        else cout << s2 << endl;
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
    while (t--)
    solve();
    
    return 0;
}