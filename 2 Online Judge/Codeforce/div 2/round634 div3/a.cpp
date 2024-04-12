#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long t;
    cin >> t;
    for (int q = 1; q <= t; q++) {
        long long n;
        cin >> n;
        cout << (n-1)/2;
        cout << "\n";
    }
    return 0;
}

