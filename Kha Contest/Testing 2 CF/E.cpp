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

int dung[100005];
int sai[100005];

int a[100005];
int ok[100005];
int x[100005]; //len

int okm[100005];
// priority_queue<pii, vector<pii>, greater<pii>> pq; // sai, vt
// từ nhỏ tới lớn
void show(set<pii>s) {
    while (s.empty() == 0) {
         auto f = *s.begin();
         s.erase(f);
         cout << f.fi << ' ' << f.se <<endl;
    }
}
void solve() {
    
    int n,m;
    cin >> n >> m;

    vector<vector<int>>b(m + 2);
    vector<vector<int>>vt(n + 2);
    set<pii>s;

    for (int i = 1; i <= n ;i++) {
        cin >> a[i];
    }   
    int cnt_left = n;
    
    
    int res = 1;
    for (int i = 1; i <= m; i++) {
        cin >> x[i];
        char o;
        cin >> o;

        int dd = 0, ss = 0;
        for (int j = 1; j <= x[i]; j++) {
            int z;
            cin >> z;
            if (a[z] == i) { // dung
                dd++;
            }
            else {
                ss++;
            }
            b[i].pb(z);
            vt[z].pb(i);
        }
        dung[i] = dd;
        sai[i] = ss;
        s.insert({ss,i});
    }


    for (int i  = 1; i <= n; i++) {
        cout <<"SSS   "<< i << endl;
        for (auto j : vt[i]) cout << j << ' ';
        EL;
    }

    cout <<"HHH  " <<endl;
        show(s);
    cout <<"HHH  " <<endl;
   EL;
    while (cnt_left != 0 || s.empty() == 0) {
        auto f = *s.begin();
        int pos = f.se;
        okm[pos] = 1;
        // cout << "vtt  " << pos << endl;
        cout <<f.fi << ' ' << f.se <<endl;
        if (f.fi != 0) { // sai != 0
            cout << "NO" <<endl;
            return;
        }
        for (auto j : b[pos]) {
            if (ok[j] == 0 && a[j] == pos) {
                ok[j] = 1; // chua toi thi danh dau da toi 
                cnt_left--;
            }
        }

        // cap nhat sai cua tung thang
        for (auto i : b[pos]) {
            if (ok[])
            for (auto j : vt[i]) {

            }
        }
        for (auto i : vt[pos]) {
            cout << "VTT   " << i <<endl;
            // if (okm[i] == 1) continue;
            // s.erase(s.find({sai[i], i}));
            // sai[i]--; 
            // s.insert({sai[i],i});
            // xoa ra khoi pq va them vao pq
        }
        cout << 100 << endl;
        s.erase(f);
    }

    if (res) {
        cout << "YES";
    }
    else cout <<"NO";
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
    while (t--)    
    solve();
    
    return 0;
}