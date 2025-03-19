#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll n,m,res;
ll a[10][10];


bool check(ll i, ll j){
    if (i>=3){
        if (a[i][j]==a[i-1][j] and a[i-1][j]==a[i-2][j]) return false;
    }
    if (i>=2 && j<=n-2){
        if (a[i][j]==a[i-1][j] and a[i-1][j]=a[i-1][j+1]) return false;
    }
    if (i>=2 and j>=2){
        if (a[i][j]== a[i-1][j] and a[i-1][j]==a[i-1][j-1]) return false;
    }
    if (i>=2 and j>=1){
        if (a[i][j]==a[i-1][j] and a[i-1][j]==a[i][j-1]) return false;
    }
    if (i>=2 and j<=n-1){
        if (a[i][j]==a[i-1][j-1] and a[i-1][j-1]=a[i][j-1]) return false;
    }
    if (j>=3){
        if (a[i][j]==a[i][j-1] and a[i][j]==a[i][j-2]) return false;
    }
    
}
void dequy(ll i, ll j){
    if (i >n ){ res++; return;}
    if (j==m){
        a[i][j]=1;
        if (check(i,j,a)){
            dequy(i+1,1);
        }
        a[i][j]=0;
        if (check(i,j)){
            dequy(i+1,1);
        }
        return 0;
    }

    a[i][j]=1;
    if (check(i,j)){
        dequy(i,j+1);
    }
    a[i][j]=0;
    if (check(i,j)){
        dequy(i,j+1);
    }
    return;
}
int main()
{
    cin>>n>>m;
}