/*
link submit: 
Note: for i , j để cố định 2 vị trí
ai + aj + ak + al = x
xác định ak + al = x - ai - aj
và  j < k < l
tiền xử lí 2 vòng for để lưu vị trí tạo nên các cặp tổng k,l
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
void solve() {
    long long n,k;
    cin >> n >> k;  
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }  
    map<long long, pair<int,int>>d;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            d[a[i] + a[j]] = {i,j};
            // cout <<d[a[i] + a[j]].se << endl;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            long long x = k - a[i] - a[j];
            if (x <= 0) continue;
            if (d[x].fi <= j) continue;

            else {
                cout << i << ' ' << j << ' ' << d[x].fi << ' ' << d[x].se <<endl;
                return;
            }

        }
    }
    cout << "IMPOSSIBLE";
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