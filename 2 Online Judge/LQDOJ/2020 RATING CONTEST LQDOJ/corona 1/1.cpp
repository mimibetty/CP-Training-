#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long n;
    cin>>n;
    while (n>5) {
        long long a=0;
        while (n>0) {
            a+= (n%10);
            n/=10;
        }
        a=a/2;
        n=a;
    }
    cout<<n;
    return 0;
}


