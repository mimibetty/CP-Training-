#include<bits/stdc++.h>
using namespace std;

const long long lim = 1e7;
int check[10000005];
int cnt[10000005];

int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    // code sang

    int can = sqrt(lim);
    for (int i = 1; i <= lim; i++) {
         for (int j = 1; j <= lim; j+=i) {
           if ((long long)i*j > lim) break;
           else check[i*j]++;
         }
    }
    for (int i = 1; i <= lim; i++) {
        if (check[i] == 4) cnt[i] = cnt[i-1] + 1;
        else cnt[i] = cnt[i-1];
    }
    int t;
    cin>>t;
    for (int i = 1; i<= t; i++) {
        int k;
        int l,r ;
        cin >> l >> r;
       
        cout<<cnt[r] - cnt[l-1]<<endl;
    }


    return 0;
}