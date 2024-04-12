#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{

    while (b>0) {
    long long r = a % b;
    a = b;
    b = r;
    }
    return a;
}
long long lcm( long long a, long long b) {
    long long res = a* b / gcd(a,b);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long n;
    cin>>n;
    long long m = sqrt(n),a,b;
    for (int i = 1; i<= m; i++) {
        if (n%i == 0) {
            if (gcd(i,n/i) == 1 && lcm(i,n/i) == n) {
                a = i;
                b = n/i;
            }
        }
    }
    cout<<a<<' '<<b;
    return 0;
}


