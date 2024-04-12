#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long gcd(long long a,long long b)
{

    while (b>0) {
    long long r = a % b;
    a = b;
    b = r;
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long n,g=1;
    cin>>n;
    for (int i =1 ; i<= n; i++) cin>>a[i];
    g = gcd(a[1],a[2]);
    for (int i = 2; i<= n; i++) {
        g = gcd(g,a[i]);
    }
    if (g == 1) {
        cout<<"LN";
        return 0;
    }
    else {
        for (int i = 2; i<= g; i++) {
            if (g % i == 0) {
                cout<<i;
                return 0;
            }
        }
    }

    return 0;
}



