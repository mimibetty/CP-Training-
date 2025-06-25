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
int n;
vector<string> s;
vector<string> reversed;
string result;
map<pair<int, string>, bool> memo;

string reverse_string(string s) {
    reverse(s.begin(), s.end());
    return s;
}

bool dp(int pos, string last_string) {
    if (pos == n) {
        return true;
    }
    
    pair<int, string> state = {pos, last_string};
    if (memo.find(state) != memo.end()) {
        return memo[state];
    }
    
    bool ok = false;
    
    if (last_string.empty() || last_string < s[pos]) {
        if (dp(pos + 1, s[pos])) {
            result[pos] = '0';
            ok = true;
        }
    }
    
    if (!ok && (last_string.empty() || last_string < reversed[pos])) {
        if (dp(pos + 1, reversed[pos])) {
            result[pos] = '1';
            ok = true;
        }
    }
    
    memo[state] = ok;
    return ok;
}

void solve() {
    cin >> n;
    s.resize(n);
    reversed.resize(n);
    result = string(n, '0');
    memo.clear();
    
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        reversed[i] = reverse_string(s[i]);
    }
    
    dp(0, "");
    cout << result << endl;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
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