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
long long a[10005];
const int N = 1000000; // = 1e6
int minPrime[N + 1];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    map<int,int>d;
    for (int i = 1; i <= n; i++) {
        int tmp = a[i];
        while (tmp > 1) {
            int x = minPrime[tmp];
            while (tmp % x == 0) {
                d[x]++;
                tmp /= x;
            }
        }
    }
    bool ok = 1;
    for (auto i : d) if (i.se % n != 0) {
        ok = 0;
        break;
    }
    if (ok == 1) {
        cout << "YES" <<endl;
    }
    else cout << "NO" <<endl;
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
    cin >> t;
    while (t--)    
    solve();
    
    return 0;
}