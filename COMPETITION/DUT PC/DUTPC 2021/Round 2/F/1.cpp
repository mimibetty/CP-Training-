#include<bits/stdc++.h>
using namespace std;
map<string, long long> dem;
vector<string> res;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1;i<=n;i++){
        string a,b;
        long long c;
        cin >> a >> b >> c;
        if(dem[a]==0){
            res.push_back(a);
        }
        if(dem[b]==0){
            res.push_back(b);
        }
        dem[a] += c;
        dem[b] += c;
    }
    sort(res.begin(),res.end());
    for (int i = 0; i < res.size();i++){
        cout << res[i] << ' ' << dem[res[i]]<<'\n';
    }
        return 0;
}