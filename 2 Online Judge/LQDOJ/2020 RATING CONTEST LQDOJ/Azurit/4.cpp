#include<bits/stdc++.h>
using namespace std;
int res(int t, int d, int l, int r, int x, int y, int dc ) {
	if (dc >= d && dc <= t) {
		if (x >= l && x <= r  || y >= l && y <= r) return 1;
	} 
	else return 0;
}
struct hcn{
	int x1,y1,x2,y2;
	bool operator < (hcn other) {
		if (y1  == other.y1) return x1 < other.x1;
		return y1  < other.y1;
	} 
};
int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int n;
 	cin >> n;
 	for (int q = 1; q <= n; q++) {
 		int x1,y1,x2,y2;
 		cin >> x1 >> y1 >> x2 >> y2;
 		int up,d,l,r;
 		hcn.y1[q] = y1;
 		hcn.x1[q] = x1;
 		hcn.y2[q] = y2
 		hcn.x2[q] = x2;
 		// d[q] = y1;
 		// l[q] = x1;
 		// up[q] = y2
 		// r[q] = x2;
 	}   
 	int solve =0;
 	for (int i = 1 ; i <= n; i++) {
 		solve += res(hcn.y2[i+1] , hcn.y1[i+1], hcn.x1[i+1] , hcn.x2[i+1] ,hcn.x1[i] , hcn.x2[i] , hcn.y2[i]);
 		solve += res(hcn.y2[i+1] , hcn.y1[i+1], hcn.x1[i+1] , hcn.x2[i+1] ,hcn.x1[i] , hcn.x2[i] , hcn.y1[i]);
 		if (solve > 0) {
 			cout << 1;
 			break;
 		}
 	}
 	cout << 0;
    return 0;
}