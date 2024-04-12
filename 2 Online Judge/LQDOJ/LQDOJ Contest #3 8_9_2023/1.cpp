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
    int n;
    cin >> n;
    vector<long long>a;
    vector<long long>b;
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        if (x % 2 ==0 ) {
            a.pb(x);
        }
        else b.pb(x);
    }
    sort(a.begin(), a.end());
    auto itr = unique(a.begin(), a.end());
    a.erase(itr, a.end());

    sort(b.begin(), b.end());
    auto itr2 = unique(b.begin(), b.end());
    b.erase(itr2, b.end());

    long long res = -1;
    if (a.size() >= 2) {
        res = max(res, a[a.size()-1] + a[a.size()-2]);
    }

    if (b.size() >= 2) {
        res = max(res, b[b.size()-1] + b[b.size()-2]);
    }
    cout <<res<<endl;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}