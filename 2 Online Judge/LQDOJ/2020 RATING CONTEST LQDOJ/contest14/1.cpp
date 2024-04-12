#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main()
{
    int n,res = 0,du1=0,du2=0;
    cin>>n;
    for (int i= 1; i<= n; i++) {
            cin>>a[i];
            a[i]= a[i]%3;
    }
    for (int i = 1; i<= n; i++) {
        if (a[i] % 3 == 0) res++;
        else if (a[i] % 2 == 0) du2++;
        else du1++;
    }
    int dem = min(du2,du1);
    res = res + dem + (du2 - dem)/3 + (du1-dem)/3;
    cout<<res;
    return 0;
}
