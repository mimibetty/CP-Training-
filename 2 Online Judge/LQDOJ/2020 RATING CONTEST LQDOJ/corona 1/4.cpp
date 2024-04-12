#include <bits/stdc++.h>
using namespace std;
long long a[100000005];
long long b[100000005];
int main()
    {
        long long n;
        bool res = 0;
        cin>>n;
        for (int i = 1; i<= n; i++) cin>>a[i];
        for (int i = 1; i<= n-1; i++) {
            if (abs(a[i+1] - a[i]) >= 2) {
                res = 1;
                break;
            }
        }
        if (res == 0) cout<<"No";
        else cout<<"Yes";
        return 0;
    }
