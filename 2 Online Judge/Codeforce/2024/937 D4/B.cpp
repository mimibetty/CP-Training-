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
int a[400][400];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= 2*n; i++) {
        int x = (i - 1) / 2;
        if (x% 2 == 1) {
            a[1][i] = 1;
            a[2][i] = 1;
        }

    }

    for (int i = 3; i <= 2*n; i++) {
        for (int j = 1; j <= 2*n ; j++) {
            int x = (i - 1)/2;
            if (x % 2 == 0) {
                a[i][j] = a[1][j];
            }
            else {
                a[i][j] = 1 - a[1][j];
                
            }
        }
        // cout << endl;
    }
    for (int i = 1; i <= 2*n; i++) {
        for (int j = 1; j <= 2*n ; j++) {
            if (a[i][j] == 0) cout << '#';
            else cout << '.';
        }
        cout << endl;
    }

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
    cin >> t;
    while (t--)    
    solve();
    
    return 0;
}