#include<bits/stdc++.h>
using namespace std;
#include<vector>
int a[15][15];
vector<int>tong;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,res = 0;
    cin>>n;
    for (int i = 1; i<= n; i++) {
            for (int j = 1; j<= n; j++) cin>>a[i][j];
    }
    for (int i = 1; i<= n; i++) {
            res = 0;
            for (int j = 1; j<= n; j++) {
            res+=a[i][j];
            }

         tong.push_back(res);
    }
    for (int j = 1; j<= n; j++) {
            res = 0;
            for (int i = 1; i<= n; i++) {
            res+=a[i][j];
            }

         tong.push_back(res);
    }
    res = 0;
    for (int i = 1; i<= n; i++) {
        res += a[i][i];
    }
    tong.push_back(res);
    res = 0;
    for (int i = n; i>= 1; i--) {
        res+=a[i][n-i+1];
    }
    tong.push_back(res);
         int k= tong.size(),done = 1;
     for (int i = 0; i <= k-2; i++) {
        if (tong.at(i) != tong.at(i+1) ) done = 0;
     }
     if (done == 1) cout<<"YES";
     else cout<<"NO";
    return 0;
}
