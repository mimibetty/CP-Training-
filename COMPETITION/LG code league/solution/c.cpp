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

vector<vector<int>> children;
vector<ll> values;
vector<vector<ll>> dp;

void dfs(int node) {
    if (children[node].empty()) {
        dp[node][1] = values[node];
        dp[node][0] = 0;
        return;
    }

    for (int child : children[node]) {
        dfs(child);
    }

    dp[node][1] = values[node];
    for (int child : children[node]) {
        dp[node][1] += dp[child][0];
    }

    ll sum_max_child = 0;
    bool child_natural = false; // is any children naturall 

    for (int child : children[node]) {
        sum_max_child += max(dp[child][0], dp[child][1]);
        if (dp[child][1] >= dp[child][0]) {
            child_natural = true;
        }
    }

    if (child_natural) {
        dp[node][0] = sum_max_child;
    } else {
        ll min_penalty = 1e18;
        for (int child : children[node]) {
            min_penalty = min(min_penalty, dp[child][0] - dp[child][1]);
        }
        dp[node][0] = sum_max_child - min_penalty;
    }
}

void solve() {
    int n;
    cin >> n;
    
    values.resize(n + 1);
    children.assign(n + 1, vector<int>());
    dp.assign(n + 1, vector<ll>(2, 0));
    
    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }
    
    int root = -1;
    for (int i = 1; i <= n; i++) {
        int parent;
        cin >> parent;
        if (parent == 0) {
            root = i;
        } else {
            children[parent].push_back(i);
        }
    }
    
    dfs(root);
    
    cout << max(dp[root][0], dp[root][1]) << endl;
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
    while(t--) {
        solve();
    }
    return 0;
}

