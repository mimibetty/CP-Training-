#include<bits/stdc++.h>
using namespace std;

int a[100005];
int cnt[100005];
int sum[100005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int n;
 	cin >> n;

 	long long res = 0;
 	for (int i = 1; i <= n ;i++) {
 		cin >> a[i];
 		res += (long long)i * cnt[a[i]] - sum[a[i]];
 		cnt[a[i]]++;
 		sum[a[i]] += i;
 	}
 	cout << res;
 	
    return 0;
}