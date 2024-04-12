#include<stdio.h>
#include<vector>

using namespace std;
 

int trace[1000005];
long long ps[1000005];
vector<int>primes;

void sieve(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (trace[i] == 0) {
			for (int j = i *i; j <= n; j+=i) {
				if (trace[j] == 0) trace[j] = i;
			}
		}
	}

	for (int j = 2; j <= n; j++) if (trace[j] == 0) {
		trace[j] = j;
		primes.push_back(j);	
	} 

}


int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(NULL);
 	
 	sieve(1000000);


 	int t;
 	scanf("%d",&t);

 	while (t--) {
 		int n;
 		scanf("%d",&n);
 		int a = 0, b = 0;

 		for (int i = 1; i <= 100; i++) {
 			if (primes[i] > n) break;
 			if(trace[primes[i]] == primes[i] && trace[n - primes[i]] == (n - primes[i])) {
 				a = primes[i];
 				b = n - primes[i];
 				if (a > b) swap(a,b);
 				break;
 			}
 		}

 		if (a*b == 0) printf("No\n");
 		else {
 			printf("%d ",n);
 			printf("= ");
 			printf("%d ",a);
 			printf("+ ");
 			printf("%d\n",b);	
 		} 
 		
 	}
    return 0;
}