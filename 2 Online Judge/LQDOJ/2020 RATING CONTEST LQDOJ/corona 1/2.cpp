#include <bits/stdc++.h>
 using namespace std;
int main()
{
    for (int i = 10; i<= 99;i++) {
        int n=i,a=0;

    int b=i,c=0;
    while (n>0) {
        a+=(n%10);
        n/=10;
    }
    while (b>0) {
        c=c*10 +(b%10);
        b/=10;
    }
    if (a+c == i) cout<<i<<endl;
    }

 return 0;
}
