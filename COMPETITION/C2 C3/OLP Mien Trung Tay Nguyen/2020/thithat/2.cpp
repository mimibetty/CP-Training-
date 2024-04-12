#include<bits/stdc++.h>
using namespace std;

bool snt[1000005];
bool check[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int m = 1000000, k = sqrt(m); 
    for (int i = 2; i <= m; i++) check[i] = 1;
    for (int i = 2; i <= k; i++)
        if (check[i] == 1) for (int j = i * i; j <= m; j += i) check[j] = 0;
    int n,res = 0;
    cin >> n;
    for (int i = 2; i <= n/2; i++) {
        if (check[i] == 1 && check[n-i] == 1) res++;
    }
    cout << res;
    return 0;
}