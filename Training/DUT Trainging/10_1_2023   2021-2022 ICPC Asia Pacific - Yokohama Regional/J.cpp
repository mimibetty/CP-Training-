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

pii a[200005];
int suff_max[200005];
int suff_min[200005];

int check(int mid,int j) {
    int x = a[j].se;
    int y = a[mid].se;
    if (x > y) swap(x,y);
    // cout <<x << " " << y << endl;

    int zmax = suff_max[mid];
    int zmin = suff_min[mid];
    // cout << zmax << ' ' << zmin << endl;
    if (zmax >= x && zmax <= y && zmin >= x && zmin <= y) return 1;
    return 0;
}
void solve() {
     int n;
     cin >> n;
     for (int i = 1; i <= n; i++) {
        cin >> a[i].fi>> a[i].se;
     }  
     sort(a + 1, a + 1 +n);

     suff_max[n+1] = -1e9;
     suff_min[n+1] = 1e9;
     for (int i = n; i>=1; i--) {
        suff_min[i] = min(suff_min[i+1], a[i].se);
        suff_max[i] = max(suff_max[i+1], a[i].se);
     
     }

     long long res = 0;
     for (int i = 1; i <= n; i++) {
        // cout << "I   " << i << endl << endl;
        int l = i + 1, r = n;
        while (l < r) {
            int mid = (l + r + 1 )/2;
            if (check(mid,i)) {
                l = mid;
            }
            else {
                r = mid-1;
            }
            // cout << l << ' ' << r << endl;
        }
         // cout <<"ANS   " << l << endl;
         if (check(l,i) == 0) {
            continue;
         }

        cout <<a[i].fi << ' ' << a[i].se <<endl;
         cout <<"ANS   " << l << endl;
         res += max(0,n - l+1);
         cout << endl <<endl;
     }
     cout <<res <<endl;
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