#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e6 + 3;
const int MAXN = 1e6;
const int oo = 1e9;
vector<string> ans;
vector<pair<string,string> > ldk;
map<string, int> dem;
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("hellodking.txt","r",stdin);
    #else
    // online submission
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s,st,stt;
    int n;
    cin >> n;
    for (int i = 1; i<= n; i++)
    {
        cin >> s >> st >> stt;
        s+=" "; s+=st;
        ldk.pb({s,stt});
    }
    sort(ldk.begin(),ldk.end());
    for (int i =1 ;i < ldk.size(); i++)
        if (ldk[i].f!=ldk[i-1].f||ldk[i].s!=ldk[i-1].s)
        {
           string tt = ldk[i-1].s;
            if (dem[tt] == 0) ans.pb(tt);
            dem[tt]++;
        }
            string tt = ldk.back().s;
            if (dem[tt] == 0) ans.pb(tt);
            dem[tt]++;
    //cout << ans.size()<<endl;
    sort(ans.begin(), ans.end());
    for (auto v : ans) 
    {
        cout << v <<" "<<dem[v]<<" "; if (dem[v]>=10) cout << "YES" <<endl; else cout << "NO"<<endl;
    }
}