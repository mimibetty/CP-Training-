#include<bits/stdc++.h>
using namespace std;
char a[105][105];


int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int m, n,res = 0 ;
 	cin >> m >> n;
 	for (int i = 1; i <= m; i++) {
 	    for (int j = 1; j <= n; j++) {
 	        cin >> a[i][j];
 	    }
 	}
 	for (int i = 1; i <= m - 1; i++) {
 	    for (int j = 1; j <= n-1; j++) {
 	        int f = 0, aa = 0 , c = 0, e= 0;
 	        for (int l = i; l <= i+1; l++) {
 	            for (int r = j; r <= j+1; r++) {
 	                if (a[l][r] == 'f') f= 1;
 	                if (a[l][r] == 'a') aa= 1;
 	                if (a[l][r] == 'c') c= 1;
 	                if (a[l][r] == 'e') e= 1;
 	            }
 	        }
 	         	    if (aa + f + c + e == 4) res ++ ;

 	    }
 	}
 	cout << res;
    return 0;
    
}