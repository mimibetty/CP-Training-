/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    int h,m,n;
    cin >> h >> m >> n;
    cout << h << ':' << m << ':' << n << endl;
    return 0;
}