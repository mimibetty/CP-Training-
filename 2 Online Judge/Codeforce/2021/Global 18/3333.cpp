#include <bits/stdc++.h>

#define ll long long
#define endl "\n"
#define afor(i,n) for(int i =0; i<n;i++)
#define push_back emplace_back
//priority_queue <int> ; less
//priority_queue <int,vector<int>,greater<int> > ; greater

using namespace std;

void solve(){
    string s,t;
    int n;
    cin>>n;
    cin>>s;
    cin>>t;
    //le lan
    int dcount1=0,dcount0=0;
    int scount1=0,scount0=0;
    for (int i=0; i<n; i++){
        if(s[i]!=t[i]){
            if (s[i]=='1') dcount1++;
            else dcount0++;
        }
        else {
            if (s[i]=='0') scount0++;
            else scount1++;
        }
    }
    int res=0;
    // cout<<dcount0<<" "<<dcount1<<endl;
    // cout<<scount0<<" "<<scount1<<endl;
    if (dcount1==0 && dcount0==0) {
        res=0;
        cout<<res<<endl; 
        return;
    }
    
    int res1=0;//le lan
    int res2=0;//chan lan
    
    // xet le lan
    if ((scount1-scount0==0 || scount1-scount0==1) && (scount1+scount0)%2==1){
        res1=scount1+scount0;
    }
    else res1=100001;
    
    if ((dcount1-dcount0==0 || dcount1-dcount0==1) && (dcount1+dcount0)%2==0){
        res2=dcount1+dcount0;
    }
    else res2=100001;
    
    if (res1==100001 && res2==100001) {
        cout<<"-1"<<endl;
    }
    else cout<<min(res1,res2)<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}