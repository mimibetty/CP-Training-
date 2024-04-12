#include<bits/stdc++.h>
using namespace std;
long long a[10000005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long n,k=170901,maxvl =0,tich=1;
    cin>>n;
    for (int i = 1; i<= n; i++) {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    a[n] = a[n]- 1;
    for (int i = 1; i<= n-1;i++) {
        tich = ((tich%k)* (a[i]%k))%k ;
    }
    cout<<(tich *a[n] )%k;

    return 0;
}


