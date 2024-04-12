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

int minPrime[100005];
bool checkii(int x) {
    while (x > 0) {
        if (x % 10 > 1) {
            return 0;
        }
        x /= 10;
    }
    return 1;
}
void solve() {
    int n;
    cin >> n;
    int x = n;
    int f = 1;
    while (x > 1) {
        int z = minPrime[x];
        if (checkii(z) == 0) {
            f *= z;
        }
        x /= z;
    }   
    int res  = (checkii(f) | checkii(n));
    if (res) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO " << endl;
    }
    // cout << checkii(f) | checkii(n) << endl
    // cout <<n << ' ' << f << ' ' <<  checkii(f) << endl;
}   
    
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    const int n = 1e5;
    for (int i = 2; i * i <= n; ++i) {
        if (minPrime[i] == 0) { //if i is prime
            for (int j = i * i; j <= n; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
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