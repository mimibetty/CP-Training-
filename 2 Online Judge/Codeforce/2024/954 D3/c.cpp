/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define bit(n,i)  ((n>>i) & 1) 
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

int a[200005];
char b[200005];

void solve() {
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = ' ' + s;
    set<int>f;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        f.insert(a[i]);
    }
    for (int i = 1; i <= m; i ++) {
        cin >> b[i];
    }

    sort(b + 1, b + 1 + m);
    int cnt = 1;
    for (auto i : f) {
        s[i] = b[cnt];
        cnt++;


    }
    // cout << endl;
    // for (int i = 1; i <= m; i ++) {
    //     cout <<  b[i] << ' ';
    // }

    // cout << endl;


    cout << s << endl; 

    // cout << endl;
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