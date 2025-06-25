#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
ll snt[1000005];
void check(ll n){
    for (int i=1;i<=n;i++) snt[i]=1;
    snt[0]=snt[1]=0;
    for (int i=2;i<=sqrt(n);i++){
        if (snt[i]==1){
            for (int j=i*i;j<=n;j+=i) {
                snt[j]=0;
            }
        }
    }
    return;
}
int main()
{
    if(fopen("input.txt", "r")) {
            freopen("input.txt","r",stdin);
            // freopen("output.txt","w",stdout);
        }
    
        ios::sync_with_stdio(0);
        cin.tie(NULL);
    
        ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n + 1, vector<ll>(m + 1, 0));
    vector<vector<ll>> ps(n + 1, vector<ll>(m + 1, 0));
    ll res = 0;
    check(1000000);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + (1 - snt[a[i][j]]);
            for (int x = 0; x <= min(n, m) - 1; x++) {
                ll y = i - x;
                ll z = j - x;
                if (y < 1 || z < 1) break;
                ll sum = ps[i][j] - ps[y - 1][j] - ps[i][z - 1] + ps[y - 1][z - 1];
                if (sum <= 1) {
                    res = max(res, (x + 1) * (x + 1) * 1LL);
                }
            }
        }
    }
    cout << res;
}