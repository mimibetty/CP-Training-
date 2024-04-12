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

int a[100005];
void solve() {
    int n;
    cin >> n;
    for (int i = 1;i <= n; i++) {
        cin >> a[i];
    }
    
    if (a[1] == a[2]) a[1] = 0;
    if (a[n] == a[n-1]) a[n] = 0;
    

    if (a[1] == -1) a[1] = 0;
    if (a[n] == -1) a[n] = 0;
    
    if (a[2] == -1) a[2] = 0;
    if (a[n-1] == -1) a[n-1] = 0;
    

        

    int vt = -10;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i-1] && a[i] > a[i+1] && a[i-1] != -1 && a[i+1] != -1) {
            if (i - vt <= 2) {
                cout << "N" << endl;
                // cout << "ngu";
                // cout << vt << endl;
                // cout << i << endl;
                return;
            }
            vt = i;
            // cout << i << ' ';
        }
    }
    if (a[1] > a[2]) {
        // cout << "NO1" << endl;
        cout << "N" << endl;
        return;
    }
    if (a[n] > a[n-1]) {
        // cout << "NO2" << endl;
        cout << "N" << endl;
        return;
    }
    cout << "Y" << endl;
       
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