#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
ll a[5005];
int main()
{
        if(fopen("input.txt", "r")) {
            freopen("input.txt","r",stdin);
            // freopen("output.txt","w",stdout);
        }
    
        ios::sync_with_stdio(0);
        cin.tie(NULL);
    
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,x;
    cin>>n>>x;
    map<ll,ll>vt;
    map<ll,ll>b;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]++;
        vt[a[i]]=i;
    }
    ll res1,res2,res3,res4;
    res1=res2=res3=res4=0;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            ll tmp=x-a[i]-a[j];
            if (i==vt[tmp] or j==vt[tmp]) continue;
            if (b[tmp]>0){
                res1=1;
                res2=vt[tmp];
                res3=i;
                res4=j;
                break;
            }
        }
    }
    if (res1==0) cout<<"IMPOSSIBLE";
    else{
        cout<<res3<<' '<<res2<<' '<<res4;
    }
}