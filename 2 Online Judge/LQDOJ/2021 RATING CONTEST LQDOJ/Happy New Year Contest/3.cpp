#include<bits/stdc++.h>
using namespace std;

long long a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    long long x;
    int n;
    cin >> n >> x;

 	for (int i = 1; i <= n; i++) {
 		cin >> a[i];
 	}

 	bool check = 0;
 	long long res = x;

 	while (check == 0) {
 		for (int i = 1; i <= n; i++) {
 			if (res % a[i] == 0) {
 				check = 1; 
 				break;
 			}
 		}
 		if (check == 0) res++;
 	}   
 	cout <<res;
    return 0;
}