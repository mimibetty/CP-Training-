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
const int N = 1000000;
int minPrime[N + 2];

int n;
vector<int>mp[N+1];
vector<int> g[N+2];
vector<int> a(N+1);
int cnt =0;
vector<int> used(N+1,0);
void dfs(int u,int p) {
    // cout << u << ' ';
    for (int v: g[u]) {
        if (!used[v] && (a[v] % p == 0)) {

            cnt++;
            used[v]=1;
            dfs(v,p);
        }
    }
}
void solve() {
   cin >> n;
   
   for (int i=1; i<=n; i++) {
    cin >> a[i];
    int x = a[i];
    while (x != 1) {
        int k = minPrime[x];
        mp[k].push_back(i);
        while (minPrime[x] == k) x/=k;
    }
    }
   for (int i=1; i<n; i++) {
    int u,v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
   }
   int ans = 0;
   for (int i=2; i<=N; i++) {
    if (mp[i].size() >= 1) {
        // cout << i << ' ';
        int  len = mp[i].size();
        for (int j=0; j<len; j++) {
            if (!used[mp[i][j]]) {
                // cout << mp[i][j];
                cnt = 0;
                used[mp[i][j]] =1;
                // cout << "Trace "<< ' ';
                dfs(mp[i][j],i);
                cnt++;
                // cout << "end   " ;
                // cout << ' '<< cnt << '\n';
                ans = max(ans,cnt);
            }
        }
        for (int j=0; j<len; j++) used[mp[i][j]] =0;
    }
   }
   cout << ans;
}


int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    for (int i = 2; i * i <= N; ++i) {
        if (minPrime[i] == 0) { //if i is prime
            for (int j = i * i; j <= N; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= N; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }
    
    
    int t;
    t = 1;
    while (t--)    
    solve();
    
    return 0;
}