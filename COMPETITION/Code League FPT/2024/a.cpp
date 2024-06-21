#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
const ll inf = 1e18;
const long double esp=1e-12;
const ll MOD=1e9+7;
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
ll powMod(ll a, ll b, ll MOD) {
    if (b == 0) return 1;
    else {
      if (b % 2 == 0) return powMod((a*a)%MOD, b/2, MOD);
      else return (a * powMod((a*a)%MOD, b/2, MOD)) % MOD;
    }      
}
void solve() {
  //cout << powMod(3,3,MOD) << endl;
  int n ; cin >> n;
  char a[n+1][n+1];
  for (int i =1; i<=n; i++) {
    for (int j=1; j<=n; j++) cin >> a[i][j];
  }
  ll ansh = 0, ansc = 0;
  for (int i=1; i<=n; i++) {
      ll cnt = 0;
    ll s = 0;
    
    for (int j=1; j<=n; j++) {
      if (a[i][j] == '#') ++cnt;
      else {
        if (cnt>0) s = (s + powMod(cnt,cnt,MOD))%MOD;
        cnt = 0;
      }
    }
    if(cnt>0) s = (s + powMod(cnt,cnt,MOD)) % MOD;
    //cout << s << endl;
    ansh = max(ansh, s);
  }


  for (int i=1; i<=n; i++) {
    ll cnt = 0;
    ll s = 0;
    
    for (int j=1; j<=n; j++) {
      if (a[j][i] == '#') ++cnt;
      else {
        if (cnt>0) s = (s + powMod(cnt,cnt,MOD)) %MOD;
        cnt = 0;  
      }
    }
    if (cnt>0) s = (s + powMod(cnt,cnt,MOD)) % MOD;
    ansc = max(ansc, s);
  }
  cout << ansh << ' ' << ansc << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); 
  int test=1;
  //cin>>test;
  while (test--) {
    solve();
  }
  return 0;
}