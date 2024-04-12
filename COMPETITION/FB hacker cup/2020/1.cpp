#include<bits/stdc++.h>
using namespace std;
bool ck[200];
char in[200];
char out[200];
int main() {
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int t;
 	cin >> t;
 	for (int q = 1; q <=t ; q++) {
 		cout << "Case #" << q <<':' << '\n'; 
 		int n;
 		cin >> n;
 		for (int i = 1 ; i <= n; i++) cin >> in[i];
 		for (int i = 1 ; i <= n; i++) cin >> out[i];
 		for (int i = 1; i <= n; i++) {
 			int vtt = i-1 , vtt1 = i;
 			int vtp = i+1 , vtp1 = i;
 			ck[i] = 1;
 			while (vtt >= 0 && in[vtt] == 'Y' && out[vtt1] == 'Y' ) {
 				ck[vtt] = 1;
 				vtt1--;
 				vtt--;
 			}
 			while (vtp <= n && in[vtp] == 'Y' && out[vtp1] == 'Y' ) {
 				ck[vtp] = 1;
 				vtp1++;
 				vtp++;
 			}
 			for (int i = 1; i <= n; i++) {
 				if (ck[i] == 1) cout << 'Y';
 				else cout << 'N';
 			}
 			cout << '\n';
 			for (int i = vtt1; i <= vtp1; i++ ) ck[i] = 0;
 		}
 	}   
    return 0;
}