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

int st[200005];
vector<int>adj[200005];
int d = 0;
int n;
int disA[200005];
int disB[200005];

void resets() {
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        st[i] = 0;
        disB[i] = disA[i] = -1;
    }
    d = 0;
}
void bfsB(int u) {
    deque<int>q;
    q.push_back(u);
    disB[u] = 0;
    while (!q.empty()) {
        auto a = q.front();
        // cout << a << endl;
        q.pop_front();

        for (auto i : adj[a]) {
            if (disB[i] == -1) {
                disB[i] = disB[a] + 1;
                q.push_back(i);
                // cout << i << ' ';
            }
        }
    }
    return;
}
void bfsA(int u) {
    deque<int>q;
    q.push_back(u);
    disA[u] = 0;
    while (!q.empty()) {
        auto a = q.front();
        // cout << a << endl;
        q.pop_front();

        for (auto i : adj[a]) {
            if (disA[i] == -1) {
                disA[i] = disA[a] + 1;
                q.push_back(i);
                // cout << i << ' ';
            }
        }
    }
    return;
}

void dfs_cycle(int u, int p) {
    if (st[u]) return;
    st[u] = 1;
    // cout << u << ' ';
    for (auto i : adj[u]) {
        if (i == p) continue;
        if (st[i] == 1) {
            d = i;
            st[i] = 2;
            st[u] = 2;
            continue;
        }

        dfs_cycle(i, u);
        if (st[i] == 2 && i != d) {
            st[u] = 2;
            // if (u == d) break;;
        }
    }
    // cout << u << ' ' << st[u] << ' ' << d << endl;
}
void solve() {
    int n,a,b;
    cin >> n >> a >> b;
    resets();
    for (int i = 1; i <= n; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    bfsA(a);
    bfsB(b);
    // cout << "begin  ";
    dfs_cycle(b,0);
    // cout << "end  ";
    cout << d << endl;
    if (b == a) {
        cout << "NO" << endl;
    }
    else {
        if (disA[d] > disB[d]) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    for (int i = 1; i <= n; i++) cout << st[i] << ' ';
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