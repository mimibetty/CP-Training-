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

const long long modd = 998244353;
void solve() {
    int n , k;
    cin >> n >> k;
    vector<unsigned long long>a(n);
    vector<unsigned long long>b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unsigned long long p = 1;
    b=a;
    vector<unsigned long long>f = {2,3,5,7};
    for (int i = 0 ; i < k; i++) {
        a = b;
        for (int j = 0; j < n; j++) {
            b[j] = a[j] * a[(j + p) % n];
            // b[j] %= modd;
        }
        for (int j = 0; j < n; j++) {
            cout << "SSTT   " << j << ' ' << b[j] << endl;
            map<unsigned long long,int>d;
            unsigned long long tmp = b[j];
            for (auto z : f) {
                while (tmp % z == 0) {
                    tmp /= z;
                    d[z]++;
                }
            }
            for (auto i : d) cout << i.fi << '^' << i.se << endl;
        }
        EL;
        EL;
        // for (auto j : b) cout << j << ' ';
        // EL;
        // for (int j = 0; j < n; j++) {
        //     cout << (j + p) % n << ' ';
        // }
        // EL;
        // for (int j = 0; j < n; j++) {
        //     cout << a[(j + p) % n] << ' ';
        // }
        // EL;
        // for (int j = 0; j < n; j++) {
        //     cout << a[j] << ' ';
        // }
        // EL;
        // EL;
        // p = p * 2 % modd;
        
    }

    // for (auto i : b) cout << i << ' ';
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
    while (t--)    
    solve();
    
    return 0;
}