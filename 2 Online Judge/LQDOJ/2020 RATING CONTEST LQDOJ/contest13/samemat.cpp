#include<bits/stdc++.h>
using namespace std;
long long a[1005][1005];
long long b[1005][1005];
long long cntA[1000005];
long long cntB[1000005];
int main()
{
    long long n,m;
    bool isdone = 1;
    cin>>n;
    cin>>m;

    for (int i = 1; i<= n; i++) {
         for (int j =1 ; j<= m; j++) {
                cin>> a[i][j];
                cntA[a[i][j]]++;
         }
    }
    for (int i = 1; i<= n; i++) {
         for (int j =1 ; j<= m; j++) {
                cin>> b[i][j];
                cntB[b[i][j]]++;
         }
    }
    for (int i = 1; i<= 1000005; i++) {
                if (cntA[i] != cntB[i]) {
                    isdone = 0;
                }
    }
    if (isdone == 0) {
        cout<<"NO";
    }
    else {
        cout<<"YES";
    }
    return 0;

}

