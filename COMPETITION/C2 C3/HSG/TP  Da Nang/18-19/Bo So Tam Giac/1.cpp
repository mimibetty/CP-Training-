#include<bits/stdc++.h>
using namespace std;

int a[5005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int n;
 	cin >> n;

 	long long res = 0;
 	for (int i = 1; i <= n; i++) {
 		cin >> a[i];
 	}   
 	sort(a + 1, a + 1 + n);
   
 		if (n <= 1000) {
        for (int i = 1; i <= n-2; i++) {
            for (int j = i + 1; j <= n-1; j++) {
                for (int z = j + 1; z <= n; z++) {
                    if (a[i] + a[j] > a[z]) res++;
                }
            }
        }
        cout << res;
    }
    else {
        for (int i = 1; i <= n-1; i++) {
            for (int j = i+1; j <= n; j++) {
                long long sum = a[i] + a[j];
                int lower = j+1, upper = n;
                
                while (lower < upper) {
                    int mid = (lower + upper) / 2;
                    if (a[mid] < sum) {
                        lower = mid + 1;
                    }
                    else {
                       upper = mid;
                    }
                }
                
                if (lower + 1 > j && lower + 1 <= n && sum > a[lower+1]) res += (lower + 1 - j);
                else if (lower > j && lower <= n && sum > a[lower]) res += (lower  - j);
                else if (lower - 1 > j && lower - 1 <= n && sum > a[lower-1]) res += (lower - 1 - j);  
                //cout <<a[i] << ' '<< a[j] << ' ' << a[lower] << ' ' << res << endl;
                //cout <<i << ' '<< j << ' ' << lower << ' ' << res << endl;
            }
        }
        cout << res;
    }
 	
    return 0;
}