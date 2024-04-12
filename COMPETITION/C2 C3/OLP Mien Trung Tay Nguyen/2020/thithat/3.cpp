#include<bits/stdc++.h>
using namespace std;

long long a[10000005],s[10000005];
int main()
{
     freopen("input.txt", "r", stdin);
    long long n, res=0, maxvl= -1e9;
    cin>>n;
    for (int i = 1; i<= n; i++) {
        int k;
        cin >> k;
        cin>>a[i];
        s[i] = 1;
    }
    for (int i = 1; i<= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j]) {
                s[i] = max(s[i], s[j] + 1);
                res += a[j];
            }
        }
        res = max(res,s[i]);
    }
    cout<<res;


}
    