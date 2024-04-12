#include<stdio.h>
using namespace std;
 

int trace[10000005];
int phi[10000005];
long long ps[10000005];

void sieve(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (trace[i] == 0) {
			for (int j = i *i; j <= n; j+=i) {
				if (trace[j] == 0) trace[j] = i;
			}
		}
	}

	for (int j = 2; j <= n; j++) if (trace[j] == 0) trace[j] = j;

	// for (int i = 2; i <= n; i++) {
	// 	if (trace[i] == 0) {
	// 		for (int j = i; j <= n; j+= i) trace[j] = i;
	// 	}
	// }
}

// int fi(int n) {
//     int res = n;
//     for (int i = 2; i * i <= n; ++i) {
//         if (n % i == 0) {
//             while (n % i == 0) {
//                 n /= i;
//             }
//             res -= res / i;
//         }
//     }
//     if (n != 1) {
//         res -= res / n;
//     }
//     return res;
// }


int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(NULL);
 	
 	sieve(10000000);

 	phi[1] = 1;
 	ps[1] = 1;
 	for (int i = 2; i <= 10000000; i++) {
 		phi[i] = i;
 		int val = i;
 		while (val > 1) {
 			int p = trace[val];
 			// if (val % p == 0) {
 				phi[i] -= phi[i]/p;
				while (val % p == 0) val /= p; 				
 			// }
 		}
 		ps[i] = ps[i-1] + phi[i];
 	}

 	int t;
 	scanf("%d",&t);

 	while (t--) {
 		int n;
 		scanf("%d",&n);
 		printf("%lld\n",ps[n]);
 		
 		// cin >> n	;
 		// cout << ps[n] << '\n';
 	}
    return 0;
}