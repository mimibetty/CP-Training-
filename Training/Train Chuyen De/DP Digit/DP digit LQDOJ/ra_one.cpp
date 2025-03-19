#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll dp[20][200][2][2];
int cnt = 0;
ll dpdigit(ll vitri, string num, bool tight, ll sum, bool zero){
    if (vitri==num.size()) {
        if (cnt % 2 == 0) return (sum == 101);
        else return (sum == 99); 
        // if (sum == 101 ) return 1;
        // return 0;
    }
    if (dp[vitri][sum][zero][tight]!=-1){
        return dp[vitri][sum][zero][tight];
    }
    ll limit=9;
    if (tight == 1){
        limit=num[vitri]-'0';
    }
    ll res=0;
    for (int i=0;i<=limit;i++){
      ll newsum=sum;
        if (vitri%2==1) newsum-=i;
        else newsum+=i;
        bool newtight= tight & (i==limit);
        bool newzero = zero & (i==0);
        res+=dpdigit(vitri+1,num,newtight,newsum,newzero);
    }
    return dp[vitri][sum][zero][tight]=res;
}
ll tinh(ll a){
    string newa= to_string(a);
    cnt = newa.size();
    memset(dp,-1,sizeof(dp));
    return dpdigit(0,newa,1,100,1);
}
int main()
{
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    ll a,b;
    cin>>a>>b;
    cout<<tinh(b)-tinh(a-1);
}
