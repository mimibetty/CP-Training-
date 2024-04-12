#include<bits/stdc++.h>
using namespace std;

int a[5005];
int b[5005];
int res[4];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
		b[i] = a[i];
    }
    sort(a+1,a+1+n);

    for (int i = 1; i <= n -2; i++) {
    	for (int j = i + 1; j <= n-1; j++) {
    		
    		long long sum = a[i] + a[j];
    		int lower = j+1, upper = n;
        	while (lower < upper) {
	            int mid = (lower + upper) / 2;
	             if (a[mid] + sum == k) {
	            	res[1] = a[i];
	            	res[2] = a[j];
	            	res[3] = a[mid];
	            	for (int l = 1; l <= n; l++) {
	            		for (int r = 1; r <= 3; r++) {
	            			if (res[1] == 0 && res[2] == 0 && res[3] == 0) return 0;
	            			if (res[r] == b[l]) {
	            				cout << l << ' ';
	            				res[r] = 0;
	            				break;
	            			}
	            		}
	            	} 
	            	return 0;
	            }
	            if (a[mid] + sum > k) {
	                upper = mid;
	            }
	            else {
	                lower = mid + 1;
	            }
        	}
        	if (a[lower] + sum == k) {
	            	res[1] = a[i];
	            	res[2] = a[j];
	            	res[3] = a[lower];
	            	for (int l = 1; l <= n; l++) {
	            		for (int r = 1; r <= 3; r++) {
	            			if (res[1] == 0 && res[2] == 0 && res[3] == 0) return 0;
	            			if (res[r] == b[l]) {
	            				cout << l << ' ';
	            				res[r] = 0;
	            				break;
	            			}
	            		}
	            	} 
	            	return 0;
	            }   
    	}
    }
    cout <<"IMPOSSIBLE";
    return 0;
}