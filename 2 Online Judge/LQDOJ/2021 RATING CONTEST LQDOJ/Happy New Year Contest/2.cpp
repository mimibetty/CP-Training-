#include<bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	long long res =0;
 	int n;
 	cin >>n;
 	for (int i = 1; i <= n; i++) {
 		if (i % 2 == 0) res -= i;
 		else res += i;
 	}   
 	cout <<res;
    return 0;
}