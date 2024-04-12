#include<bits/stdc++.h>
using namespace std;

#define precision(x) cout << setprecision(x) << fixed;

const int base = 31;
const long long MOD = 1000000003;
const int N=4e4+5;
long long POW[N],hashS[N];
int m,lenS,d;
string s;
long long getHashS(int l,int r)
{
    return (hashS[r]-hashS[l-1]*POW[r-l+1]+MOD*MOD)%MOD;
}
bool check(int x)
{
  //  cout<<x<<endl;
    vector<pair<long long,int>>v;
   // map<long long,string>mp;
   // map<string,long long>mp2;
    for (int i=1;i<=lenS-x+1;i++)
    {
        long long val=getHashS(i,i+x-1);
        v.push_back(make_pair(val,i));
        // string str=s.substr(i,x);
       // mp[val]=str;
       // mp2[str]=val;
      //  cout<<val<<" "<<i<<" "<<i+x-1<<" "<<str<<endl;
    }
   // cout<<endl;
    sort(v.begin(),v.end());
   // for (auto y:v) cout<<y.first<<" "<<mp[y.first]<<" "<<y.second<<" "<<endl;
    int cnt=1,maxx=0,u=0;
    d=0;
    for (int i=1;i<v.size();i++)
    {
        if (v[i].first==v[i-1].first)
        {
            cnt++;
            if (cnt>maxx) {maxx=cnt;u=v[i].first;}
        }
        else
        {
            if (cnt>maxx) {maxx=cnt;u=v[i].first;}
            cnt=1;
        }
    }
    //cout<<maxx<<endl;
    for (int i=0;i<v.size();i++)
        if (u==v[i].first) d=max(d,v[i].second-1);
    if (maxx>=m) return true;
    else return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (1)
    {
        cin>>m;
        if (m==0) break;
        cin>>s;
        lenS=s.size();
        s=' '+s;
        memset(POW,0,sizeof(POW));
        memset(hashS,0,sizeof(hashS));
        POW[0]=1;
        for (int i=1;i<=lenS;i++)
            POW[i]=(POW[i-1]*base)%MOD;
        for (int i=1;i<=lenS;i++)
            hashS[i]=(hashS[i-1]*base+s[i]-'a'+1)%MOD;
        int l=1,r=lenS,res=-1,pos=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if (check(mid)) {res=mid;pos=d;l=mid+1;}
            else r=mid-1;
        }
       // check(5);
        if (res==-1) cout<<"none"<<'\n';
        else
        cout<<res<<" "<<pos<<'\n';
    }
}