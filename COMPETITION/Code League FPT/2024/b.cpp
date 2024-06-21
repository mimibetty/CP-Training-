#include<bits/stdc++.h>
#define ll int
#define int int
#define nn "\n"
#define pb push_back
using namespace std;
#define X first
#define Y second
#define all(x) x.begin(),x.end()
const ll N = 5 ;


ll n , m ;
long long q ;
ll a[N] ;

struct SegmentTree {
    struct Node {
        int lazy=0 ; // giá trị T trong phân tích trên
        int val=0 ;  // giá trị lớn nhất
    } nodes[400001] ;

    void down(int id){
        int T = nodes[id].lazy ;
        nodes[id*2].lazy += T;      nodes[id*2].val += T;

        nodes[id*2+1].lazy += T;    nodes[id*2+1].val += T;

        nodes[id].lazy = 0;
    }
    void update(int id,int l,int r, int u,int v,int k){
        if (l>v || r<u)   return ;
        if (u<=l && r<=v) {
            nodes[id].val+=k ;  nodes[id].lazy+=k ; return ;
        }
        down(id) ;
        int mid=(l+r)/2 ;
        update(id*2,l,mid,u,v,k); update(id*2+1,mid+1,r,u,v,k) ;
        nodes[id].val = max( nodes[id*2].val , nodes[id*2+1].val ) ;
    }
    int get(int id,int l,int r,int u,int v) {
        if (l>v || r<u)  return 0 ;
        
        if (u<=l && r<=v)  return nodes[id].val ;
        down(id);
        int mid=(l+r)/2 ;
        return max( get(id*2,l,mid,u,v) , get(id*2+1,mid+1,r,u,v) ) ;
    }
} SMT ;

ll r ;
double p ; 
void Input(){
    cin >> n >> r >> q >> p;
}
void solve(){
    //<<SMT.get(1,1,n,1,n)<<nn;
    ll sum = 0 ;
    for(int i=1;i<=r;i++){
        ll l , r ;
        cin >> l >> r ;
        ll g = SMT.get(1,1,n,l+1,r);
        //cout<<"g : "<<g<<nn;
        if(g>=q) {   }
        else {
            SMT.update(1,1,n,l+1,r,1) ;
            sum++;
        }
    }
    cout<<sum<<"/"<<r<<": ";
    double tmp = sum;
    tmp/=r;
    tmp*=100;
    tmp = 100-tmp;
    //cout<<tmp<<" "<<p<<nn;
    if(tmp<=p) cout<<"No";
    else cout<<"Yes";

}
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    if(fopen( "icecream.txt", "r"))
    { freopen("icecream.txt", "r", stdin);  freopen( "chocolate.txt", "w", stdout); }
    int T=1;
    //cin>>T;
    while(T--) {  Input() ;  solve() ;  }
}