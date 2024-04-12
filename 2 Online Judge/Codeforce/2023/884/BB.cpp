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

bool isPrime[200005];
void sieve(int N) {
    for(int i = 0; i <= N;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= N; ++i) {
         if(isPrime[i] == true) {
             for(int j = i * i; j <= N; j += i)
                 isPrime[j] = false;
        }
    }
}
void solve() {
    int n;
    cin >> n;
    vector<int>f(n + 2);
    vector<int>c(n + 2);
   
    f[n] = 2;
    c[n] = 1;
    
    f[(n+1)/2] = 1;
    c[(n+1)/2] = 1;
    
    vector<int>tmp;
    for (int i = 3; i <= n; i++) {
        if (isPrime[i] == 1) tmp.pb(i);
    }
    // for (auto i : tmp ) cout << i << ' ';
    for (int i = 1; i <= n; i++) {
        if (c[i] == 1) continue;
        if (tmp.size() == 0) break;
        f[i] = tmp.back();
        c[i] = 1;
        tmp.pop_back(); 
    }


    vector<int>tmp2;
    for (int i = 3; i <= n; i++) {
        if (isPrime[i] == 0) tmp2.pb(i);
    }
    for (int i = 1; i <= n; i++) {
        if (c[i] == 1) continue;
        if (tmp2.size() == 0) break;
        f[i] = tmp2.back();
        tmp2.pop_back(); 
    }
    for (int i = 1; i <= n; i++) cout << f[i] << ' ';
    EL;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    sieve(200000);

    int t;
    cin >> t;   
    while(t--)
    solve();
    
    return 0;
}