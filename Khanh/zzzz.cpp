#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const ll MOD=1000000007;
void file()
{
}
ll a[1000001][3][2];
void pre_process(){
    a[1][0][0]=a[1][1][0]=a[1][0][1]=1;
}
void dp(int n){
    pre_process();
    if (n==1) return;
    for (int i=2;i<=n;i++){
        for (int t = 0;t<=2;t++){
            for (int x = 0;x<=1;x++){
                a[i][t][x]=(a[i-1][(t+1)%3][x]+a[i-1][t][(x+1)%2]+a[i-1][t][x])%MOD;
            }
        }
    }
}
void solve(){
    int n;
    cin>>n;
    dp(n);
    cout<<a[n][0][0];
}
int main()
{
      if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    file();
    int test=1;
    //cin >> test;
    while (test--){
        solve();
    }
    return 0;
}

int dp(int i) {}
dp = for 
dp = đệ quy 
for ()

int


for (int i = 1; i <= n; ) dp[i] = dp[i-1] + dp[i-2]


int fibo(int n) {
    if (n == 0) return 1;
    if (n == 1) return 2;

    return fibo(n-1)   + fibo(n-2)
} 