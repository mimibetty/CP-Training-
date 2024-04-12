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

long long a[200005];
long long ps[200005];
long long tinh(int l, int r) {
    long long x = ps[r] - ps[l-1];
    return x;
}
void solve() {
    int n;
    cin >> n;
    long long res = 0;
    long long sum = 0;
    long long x = 0;
    for (int i = 1; i <= n ;i++) {
        cin >> a[i];
        sum += a[i];
        ps[i] = a[i] + ps[i-1];
    }

    sort(a + 1 , a + 1 + n);
    
    for (int i = 1; i <= n; i++) {
        ps[i] = ps[i-1] + a[i];
    }
    // EL;


    for (int i = 1; i<= n; i++) {
        if (a[i] == 1) {
            res++;
            x++;
        }
        else {
            long long tmp = x + a[i];
            long long sumleft = ps[n] - ps[i];
            if (sumleft <= tmp) {
                // cout << res << ' ' << x << endl;
                res += (n - (i+1) + 1);
                long long l = 0, r = a[i];
                // cout << "HERREEE   " << i << endl; 
                long long mid,z,sumx;
                while (l < r) {
                    mid = (l + r) / 2;
                    z = (a[i] - mid) + sumleft;
                    sumx = x + mid;
                    if (sumx < z) {
                        l = mid + 1;
                    } 
                    else {
                        r = mid;
                    }
                    // cout << mid << ' ' << sumx << ' ' << z <<endl;
                    // cout << l << ' ' << r << endl;
                }        
                res += l;
                if (l != a[i]) res++;
                // cout << i << ' ' << l << ' ' << sumx << ' ' << z << ' ' <<sumleft<<  endl;
                break;
            }
            else {
                res += a[i];
                x += a[i];
            }
        }
    }
    // cout <<ps[n] << ' ' << ps[4] << endl;
    // cout << ps[n] - ps[4] << endl;
    // cout <<"RES   ";
    cout << res;
    EL;
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