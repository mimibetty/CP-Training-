#include<bits/stdc++.h>
using namespace std;

long long a[15];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    long long x,y,z;
    cin >> x >> y >> z;
    a[1] = x ;
    a[2] = y; 
    a[3] = z;
    for (int i = 1; i <= 3; i++) a[i]%= 3;
    sort(a+1, a+4);
	if (x == 0 || y == 0 || z == 0) cout << x/3+y/3+z/3;
	else if (a[1] == 0 && a[2] == 1 && a[3] == 2) cout << (x+y+z-3)/3;
	else cout << (x+y+z)/3;
    return 0;
}