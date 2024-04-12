#include<bits/stdc++.h>
using namespace std;
int check[2000005],vs[2000005];
int d[2000005];
int main()
{
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    // code sang
    int i,j,m=2000005,n = sqrt(m);
    for (i = 2; i <= m; i++) check[i] = 1;
    for (i = 2; i <= n; i++)
        if (check[i] == 1) for (int j = i * i; j <= m; j += i) check[j] = 0;
    //so uoc 
    for (i = 1; i <= m; i++) {
         for (j = 1; j <= m; j++) {
           if (i*j > 1e6) break;
           else vs[i*j]++;
         }
    }
    for (i = 2; i <=m; i++) {
    	if (check[vs[i]] == 1 && vs[i] > 2) d[i]=d[i-1]+1;
    	else d[i]=d[i-1];
    } 
    	

    int t;
    cin>>t;
    for (int i = 1; i<= t; i++) {
        int a, b;
        cin >> a >> b;
        int res = 0;
        res = d[b] - d[a-1];
        cout<<res<<"\n";
    }
    	/*for (int i = 1; i <= 25; i++) cout << vs[i] <<' ';
    		cout << endl;
    	for (int i = 1; i <= 25; i++) cout << d[i] << ' ';
 */
    return 0;
}