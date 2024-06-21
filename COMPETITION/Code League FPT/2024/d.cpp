#include<bits/stdc++.h>
#define ll int
#define int int
#define nn "\n"
#define pb push_back
using namespace std;
#define X first
#define Y second
#define all(x) x.begin(),x.end()
const ll N = (int)1e6 + 9 ;


ll n , m ;
long long q ;
ll a[N] ;

struct SMT {
    vector<int> ST ;
    SMT() {
        ST.resize(4*(n+1)+2,(int)1e8) ; 
    }
    void update(int id, int l, int r, int i, int v) {
        if (i < l || r < i)   return ;
        if (l == r) {
            ST[id] = v;
            return ;
        }

        int mid = (l + r) / 2;
        update(id*2, l, mid, i, v);  update(id*2 + 1, mid+1, r, i, v);

        ST[id] = min(ST[id*2], ST[id*2 + 1]);
    }
    int get(int id, int l, int r, int u, int v) {
        if (v < l || r < u)  return (int)1e8+1;
        if (u <= l && r <= v) return ST[id];
        
        int mid = (l + r) / 2;
        return min(get(id*2, l, mid, u, v), get(id*2 + 1, mid+1, r, u, v));
    }
} ;
ll dp[N] ;
void Input(){
    cin >> n ;
    for (int i=1;i<=n;i++) cin >> a[i] ;
}
void solve(){
    SMT smt ;
    for(int i=1;i<=n;i++) {
        dp[i] = (int)1e8 ;
        smt.update(1,1,n,i,dp[i]) ;
    }
    dp[n+1] = 0 ;
    smt.update(1,1,n+1,n+1,0) ;

    //cout<<smt.get(1,1,n,n,n)<<nn;
    for(int i=n;i>=1;i--) {
        if(a[i]==0) continue;
        ll g = smt.get(1,1,n+1,i+1,min(i+a[i],n+1)) ;
        //cout<<g<<nn;
        dp[i] = g+1 ;
        smt.update(1,1,n+1,i,dp[i]) ;
    }

    //for(int i=1;i<=n;i++) cout<<dp[i]<<" ";cout<<nn;
    if (dp[1] <= n) cout<<dp[1] ;
    else cout<<"CANNOT GET DESTINATION";
    
}
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    if(fopen( "icecream.txt", "r"))
    { freopen("icecream.txt", "r", stdin);  freopen( "chocolate.txt", "w", stdout); }
    int T=1;
    //cin>>T;
    while(T--) {  Input() ;  solve() ;  }
}