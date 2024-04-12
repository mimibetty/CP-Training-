#include <bits/stdc++.h>
using namespace std;

#define cntBit __builtin_popcount 
#define II pair<int, int>

long long a[25];
int pt2[25];
int pt5[25];
bitset<20> bs;

int main() {
   // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    

    int n;
    long long k,res = 0;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        long long m = a[i];
        if (m > 1) {
            while (m % 5 == 0) {
                m/= 5;
                pt5[i]++;
            }
            while (m % 2 == 0) {
                m/= 2;
                pt2[i]++;
            }
        }
        //cout << i << ' ' << pt5[i] << ' ' << pt2[i] << endl;
    }

    // n - 1 phép tính
    for (int i = 0; i < (1 << n); i++) {
        bs = i;        
        if (cntBit(i) == k) {
            long long div5 = 0, div2 = 0;
            for (int j = 0; j < n ; j++) {
                if (bs[j] == 1) {
                    div2 += pt2[j+1];
                    div5 += pt5[j+1];
                    //cout << a[j+1]  <<endl;
                }
            }
            //cout << bs<<endl; //<< ' ' << div5 << ' '  << div2 << endl;
            res = max(res, min(div5,div2));
        }
       
    }
    cout << res;
    
  

    return 0;
}