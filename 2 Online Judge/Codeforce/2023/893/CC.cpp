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

int a[100];
void solve() {
    int n;
    cin >> n;
    vector<int>f;
    int num = 0;
    for  (int i = 1; i <= n; i++) a[i] = i;
    sort(a + 1, a + 1 + n);
    do {
        set<int>s;
        for (int i = 1; i <= n; i++) {
            int z = __gcd(a[i], a[i%n + 1]);
            s.insert(z);
        }
        if (s.size() > num) {
            num = f.size();
        }
        for (int i = 1; i <= n; i++) cout << ' ' << a[i] << " ";
        EL;
        cout << num << endl;
    } while(next_permutation(a + 1, a + 1 + n) );

    do {
        set<int>s;
        for (int i = 1; i <= n; i++) {
            int z = __gcd(a[i],a[i%n + 1]);
            s.insert(z);
        }

        if (s.size() == num) {
            for (int i = 1; i <= n; i++) {
                cout << a[i] << ' ';
            }
            EL;

            for (int i = 1; i <= n; i++) {
                int z = __gcd(a[i],a[i%n + 1]);
                cout << z <<endl;
            }
            EL;
            EL;
        }
        cout <<"num   " << num << endl;
    } while(next_permutation(a + 1, a + 1 + n) );

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
    while (t--)     
    solve();
    
    return 0;
}