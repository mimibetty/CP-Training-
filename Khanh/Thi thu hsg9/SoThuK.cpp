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

int n,t;
long long k;
int a[100005];

int cnt1[305];

long long combi2(long long n) {
    long long res = n * (n-1) / 2;
    return res; 
}

void sub3() {
    vector<pair<int,int>>b; 
    for (int i = 1; i <= n; i++) {
        cnt1[a[i]]++;
    }
    for (int i = 1; i <= 300; i++) {
        if (cnt1[i] == 0) continue;
        b.push_back({2*i, combi2(cnt1[i])});
        for (int j = i + 1; j <= 300; j++) {
            if (cnt1[j] == 0) continue;     
            b.push_back({i + j, cnt1[i] * cnt1[j]});
        }
    }
    sort(b.begin(),b.end());
    for (auto i : b) {
        k -= i.se;
        if (k <= 0) {
            cout << i.fi << endl;
            return;
        }
    }

}
void sub4() {

}
void sub5() {

}

void solve() {
    cin >> n >> t >> k;
    int maxval = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxval = max(maxval, a[i]);
    }

    if (t == 2 && maxval <= 300) {
        sub3();
    } 
}

int main() {
    freopen("KSET.INP", "r", stdin);
    freopen("KSET.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    t = 1;
    while (t--)    
    solve();
    
    return 0;
}