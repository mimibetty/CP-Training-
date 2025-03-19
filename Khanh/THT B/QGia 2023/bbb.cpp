#include <bits/stdc++.h>

using namespace std;
#define ll long long
int n,m;
long long res = 0;
const ll mod=1e9+7;

ll b[105][105],dp[205][5];

bool check(ll i, ll j, ll a[105][105]){
    if (i>=3){
        if (a[i][j]==a[i-1][j]and a[i-1][j]==a[i-2][j]) return false;
    }
    if (j>=3){
        if (a[i][j]==a[i][j-1] and a[i][j]==a[i][j-2]) return false;
    }
    if (i>=2 and j>=2){
        if (a[i][j]==a[i-1][j] and a[i-1][j]==a[i][j-1]) return false;
    }
    if (i>=2 and j>=2){
        if (a[i][j]== a[i-1][j] and a[i-1][j]==a[i-1][j-1]) return false;
    }
    if (i>=2 and j<=m-1 ){
        if (a[i][j]==a[i-1][j] and a[i-1][j]==a[i-1][j+1]) return false;
    }
    if (i>=2 and j>=2){
        if (a[i][j]==a[i-1][j-1] and a[i-1][j-1]==a[i][j-1]) return false;
    }
    return true;
}
void dequy(ll i, ll j, ll a[105][105]){
    if (i>n){
        res++;
        if (res >= mod) res -= mod;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) cout << a[i][j] << ' ';
            cout << endl;
        }
        cout << endl;
        return;
    }
    if (j==m){
        a[i][j]=1;
        if (check(i,j,a)){
            dequy(i+1,1,a);
        }
        a[i][j]=0;
        if (check(i,j,a)){
            dequy(i+1,1,a);
        }
        return;
    }
    a[i][j]=1;
    if (check(i,j,a)){
        dequy(i,j+1,a);
    }
    a[i][j]=0;
    if (check(i,j,a)){
        dequy(i,j+1,a);
    }
    return;
}
int main()
{
        if(fopen("input.txt", "r")) {
            freopen("input.txt","r",stdin);
            // freopen("output.txt","w",stdout);
        }
    
        ios::sync_with_stdio(0);
        cin.tie(NULL);
    
    cin>>n>>m;
       dequy(1,1,b);
        cout<<res;
}