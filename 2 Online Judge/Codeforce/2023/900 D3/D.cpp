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

int a[200005];
int b[200005];
string s;
int m,n;

int ps[200005];
int f[200005];
bool d[200005];
void swapp(int l, int r) {
    for (int i = 1; i <= r-l; i++) {
        int x1 = i + l - 1;
        int x2 = r - i + 1;
        if (x1 > x2) return;
        swap(s[x1], s[x2]);
    }
}

void resett() {
    for (int i = 1; i <= m; i++) {
        ps[i] = 0;
        f[i] = 0;
        d[i] = 0;
    }
}
void solve() {
    cin >> m >> n;
    cin >> s;
    s = ' ' + s;
    resett();
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    a[n + 1] = 1e9;
    b[n + 1] = 1e9;
    // swapp(2,2);
    // cout << s <<endl;
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (a[mid] > x) {
                r = mid - 1;
            }
            else {
                l = mid;
            }
        }
        int minn = min(x,a[l] + b[l] - x);
        int maxx = max(x,a[l] + b[l] - x);
        
        // cout << a[l] << ' ' << b[l] << 
        // ' ' <<minn << ' ' << maxx  <<  endl;
        

        // swapp(minn, maxx);
        
        // cout << "ss   " << s <<endl;
        // EL;
        f[minn]++;
        f[maxx + 1]--;
    }
    for (int i = 1; i <= m; i++) {
        ps[i] = ps[i-1] + f[i];
        // cout << ps[i] << ' ';
    }

    for (int i = 1; i <= m; i++) {
        ps[i] %= 2;
        // cout << ps[i] << ' ';
    }
    // EL;

    int vt = 1;
    for (int i = 1; i <= m; i++) {
        while (i > b[vt]) {
            vt++;
        }
        if (d[i] == 1) continue;
        if (ps[i] == 1) {
            int xx = i ;
            int yy = b[vt] - (i - a[vt]);
            // cout <<"vt  " << vt << ' ' <<xx << ' ' << yy 
            // << ' ' <<s[xx] << ' ' <<s[yy] << endl;
            swap(s[xx],s[yy]);
            d[xx] = d[yy] = 1; 
        }
    }
    for (int i = 1; i <= m; i++) cout << s[i];
    // cout << s <<endl;
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