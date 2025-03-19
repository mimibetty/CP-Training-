#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll dp[10005][5][2][2];
const ll mod = 1e9 + 7;
int cnt = 0;
bool checkprime(int x) {
    if (x == 0 || x == 1) return 0;
    for (int i = 2; i <=sqrt(x); i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

ll dpdigit(ll vitri, string num, bool tight, ll sum, bool zero){
    if (vitri==num.size()) {
        return ((sum%3) == 0);
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
        ll newsum=sum + i*i;
        newsum %= 3;
        bool newtight= tight & (i==limit);
        bool newzero = zero & (i==0);
        res+= dpdigit(vitri+1,num,newtight,newsum,newzero)%mod;
        res %= mod;
    }
    return dp[vitri][sum][zero][tight]=res;
}
ll tinh(string a){
    string newa= a;
    memset(dp,-1,sizeof(dp));
    return dpdigit(0,newa,1,0,1);
}
int main()
{
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    string s;
    cin>>s;
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
        sum += (s[i] - '0');
    }
    int x = ((sum % 3) == 0);
    cout<<tinh(s) - x;
}
