#include <bits/stdc++.h>
using namespace std;
long long a[10000005], n, m ;
int main ()
{
    cin>> n >> m;
    for(int i=1; i<= n+m; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n + m );
    long long res=1;
    for(int i=2; i<=n + m; i++)
    {

        if(a[i] != a[i-1]) res++;
    }

    cout<< res;
}
