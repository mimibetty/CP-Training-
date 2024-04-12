#include <bits/stdc++.h>
using namespace std;

#define cntBit __builtin_popcount 
#define II pair<int, int>

int a[1005];
bitset<20> bs;

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    

    int n;
    cin >> n;

    int res = n - 2;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // n - 1 phép tính
    if (n >= 30) cout << n - 2;
    else {
        for (int i = 0; i < (1 << n); i++) {
            bs = i;        
            bool done = 1;
            int vt1 = -1, vt2 = -1; 
            for (int j = 0; j < n; j++) {
                if(bs[j] == 1) {
                    if (vt1 != -1 && vt2 != -1) {
                        if (a[j+1] != (a[vt1] + a[vt2]) ) {
                            done = 0;
                            break;
                        }
                        vt1 = vt2;
                        vt2 = j+1;

                    }
                    if (vt1 == -1) {
                        vt1 = j+1;
                    }
                    else if (vt2 == -1) {
                        vt2 = j+1;
                    }
                }
            }
            if (done == 1) {
                res = min(res, n - cntBit(i));
            }
            //cout << bs<<endl; //<< ' ' << div5 << ' '  << div2 << endl;
        }
        
        cout << res;
        
    }
    
    return 0;
}