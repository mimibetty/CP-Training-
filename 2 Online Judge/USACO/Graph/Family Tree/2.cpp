#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
 
#define For(i, l, r) for (int i = l; i < r; i++)
#define REP(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl
#define SQ(a) a*a
 
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long long oo = 1e18 + 7;
const int MOD = int(1e9)+7;
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

int trace[100005];
vector<int>adj[100005];
int dist[100005];


int dist2[100005];

void dfs(int u, int p) {
    dist[u] = dist[p] + 1;

    for (auto i : adj[u]) {
        if(i == p) continue;

        dfs(i,u);
    }
}

void dfs2(int u, int p) {
    dist2[u] = dist[p] + 1;

    for (auto i : adj[u]) {
        if(i == p) continue;

        dfs(i,u);
    }
}
int main() {
    // if(fopen("family.in", "r")) {
    //     freopen("family.in","r",stdin);
    //     freopen("family.out","w",stdout);
    // }

    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    map<string,int>d;
    map<int,string>name;
    string a,b;
    int n;
    cin >> n >> a >> b;
    int cnt = 0;
    if (!d[a]) {
        cnt++;
        d[a] = cnt;
        name[cnt] = a;
    }
    if (!d[b]) {
        cnt++;
        d[b] = cnt;
        name[cnt] = b;
    }

    for (int i = 1; i <= n; i++) {
        string x,y;
        cin >> x >> y;
        if (!d[x]) {
            cnt++;
            d[x] = cnt;
            name[cnt] = x;
        }
        if (!d[y]) {
            cnt++;
            d[y] = cnt;
            name[cnt] = y;
        }
        
        adj[d[x]].push_back(d[y]);
        adj[d[y]].push_back(d[x]);
        trace[d[y]] = d[x];    
    }

    vector<int>roots;
    for (int i = 1; i <= cnt; i++) {
        if (trace[i] == 0) {
            roots.pb(i);
        } 
    }

    for (auto i : roots) {
        dfs(i,0);
    }

    // for (auto i : d) {
    //     cout << i.fi << ' ' << i.se << ' ' << dist[i.se] << endl;
    // }


    int numa = d[a], numb = d[b];
    dfs2(numa,0);
    if (dist2[numb] == 0) {
        cout << "NOT RELATED" <<endl;
        return 0;
    }

    if (trace[numa] == trace[numb]) {
        cout << "SIBLINGS" <<endl;
        return 0;
    }
    if (dist[numa] == dist[numb]) {
        cout << "COUSINS" <<endl;
        return 0;   
    }

    int child, aunt;
    if (dist[numa] > dist[numb]) {
        aunt = numb;
        child = numa;
    } 
    else {
        aunt = numa;
        child = numb;
    } 

    int xx = child;
    int ok = 0;
    while (trace[xx] != 0) {
        xx = trace[xx];
        if (xx == aunt) {
            ok = 1;
            break;
        }
    }

    if (ok == 1) {
        cout << name[aunt] << " is the "; 
         if (1 == dist[child] - dist[aunt]) {
                cout << "mother ";
                cout << "of " << name[child] << endl; 
                return 0;
         }        

        for (int i = 2; i <= dist[child] - dist[aunt]; i++) {
           
            if (i == dist[child] - dist[aunt]) {
                cout << "grand-";
                break;
            }
            cout << "great-";
        }
        cout << "mother ";
        cout << "of " << name[child] << endl;
        return 0;   
    }
    else {
        cout <<name [aunt] << " is the "; 
        for (int i = 1; i < dist[child] - dist[aunt]; i++) {
            cout << "great-";
        }
        cout << "aunt ";
        cout << "of " << name[child] << endl;
        return 0;   
    }
    return 0;
}