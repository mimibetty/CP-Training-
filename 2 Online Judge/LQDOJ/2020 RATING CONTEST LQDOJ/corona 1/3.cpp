#include <bits/stdc++.h>
using namespace std;
long long a[100000005];
long long b[100000005];
int main()
    {
        long long n,k,kq= 0;
        cin>>n>>k;
        for (int i = 1; i<= n; i++) cin>>a[i];
        b[1] = a[1];
        for (int i = 2; i<= n;i++) b[i] = b[i-1] +a[i];
        for (int i = 3; i<= n;i++) {
            if (b[i] - b[i-3] >=k) kq++;
        }
        cout<<kq;
        return 0;
    }
