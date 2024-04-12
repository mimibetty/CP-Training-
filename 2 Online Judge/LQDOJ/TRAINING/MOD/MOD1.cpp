#include<bits/stdc++.h>
using namespace std;

//int a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	long long a, b , c , res1, res2, res3;
 	cin >> a >> b >> c;
 	res1 = (a%c + b%c)% c; 
    res2 = (a%c - b%c + c)%c;
    res3 = (a%c * b%c)% c;
    cout << res1 <<' '<< res2 << ' ' << res3 ;
    return 0;
}