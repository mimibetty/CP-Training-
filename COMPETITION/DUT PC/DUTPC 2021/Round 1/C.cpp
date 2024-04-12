#include<bits/stdc++.h>
using namespace std;

map<string,bool> check;
map<string, int> cnt;
vector<string> check2;

int main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        string s1, s2, check1,type;
        cin >> s1 >> s2;
        check1 = s1 + s2;
        cin >> type;
        if(check[check1]==false){
            check[check1] = true;
            if(cnt[type]==0){
                check2.push_back(type);
            }
            cnt[type]++;
        }
    }
    sort(check2.begin(),check2.end());
    for (int i = 0; i < check2.size();i++){
        bool flag = false;
        if(cnt[check2[i]]>=10){
            flag = true;
        }
        if(flag){
            cout << check2[i] << ' ' << cnt[check2[i]] <<' '<<"YES"<< '\n';
        }
        else
        cout << check2[i] << ' ' << cnt[check2[i]] << ' ' << "NO" << '\n';
    }
        return 0;
}