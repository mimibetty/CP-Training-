#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
bool check[2000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
   // vector<int>snt;
   int i,m=2000005,n = sqrt(m);
    for (i = 2; i <= m; i++) check[i] = 1;
    for (i = 2; i <= n; i++)
        if (check[i] == 1) for (int j = i * i; j <= m; j += i) check[j] = 0;


   	int a;
   	bool done = 1;
	while(cin >> a) {
    	if (a == 0) break;
    	else {
    		if (a <= 3) cout << 0;
    		else {
    			done = 1;
	    		if (check[a] == 1) done = 0;
	  
	    		if (done == 1) {
	    			int vtt = a-1;
	    			int vtp = a+1;
	    			while (check[vtt] == 0) vtt--;
	    			while (check[vtp] == 0) vtt++;
	    			cout << vtp-vtt;
	    		}	
	    		else cout << 0;
    		}	
    		 	cout <<endl;
    	}
    }	
   
    return 0;
}