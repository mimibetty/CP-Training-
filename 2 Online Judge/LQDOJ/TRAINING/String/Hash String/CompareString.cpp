#include<bits/stdc++.h>
using namespace std;


long long pw(long long a, long long n, long long MOD) {
    if (n == 0) return 1;
    long long q = pw(a, n / 2, MOD);
    if (n % 2 == 0) return q * q % MOD;
    return q * q % MOD * a % MOD;
}

struct HashString {
    string str;
    vector<long long> prefixSum, inv;
    long long MOD, BASE;
    
    // constructor
    HashString(string str = "", long long BASE = 10042003, long long MOD = 1e9 + 7): 
                                        str(str), MOD(MOD), BASE(BASE) {
        int n = str.size();
        prefixSum.resize(n + 1);
        inv.resize(n + 1);

        // calc inv
        long long invBase = pw(BASE, MOD - 2, MOD);
        inv[0] = 1;
        for (int i = 1; i <= n; i++) {
           inv[i] = inv[i - 1] * invBase % MOD;
        }
        
        // calc prefixSum
        long long curPow = 1; // BASE ^ i
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = (prefixSum[i - 1] + curPow * str[i - 1] % MOD) % MOD;
            curPow = curPow * BASE % MOD;
        }
    }
   
    // return hash of str[l..r]
    long long query(int l, int r) {
        long long res = (prefixSum[r] - prefixSum[l - 1] + MOD) % MOD;
        res = res * inv[l] % MOD; // res /= pw(BASE, l)
        return res;
    }
};

struct PalinCheck {
    string str;
    HashString hash, hashRev;
    
    PalinCheck(string str): str(str) {
        hash = HashString(str);
        string rev = str;
        reverse(rev.begin(), rev.end());
        hashRev = HashString(rev);
    }
    
    // return true if str[l..r] is palindrome
    // O(1)
    bool check(int l, int r) {
        int n = str.size();
        return (hash.query(l, r) == hashRev.query(n - r + 1, n - l + 1));
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int n,m ; 
 	cin >> n >> m;
 	string a, b;   
 	cin >> a >> b;
 	HashString hashA(&a, 10042003, 1e9 + 7);
    HashString hashB(&b, 10042003, 1e9 + 7);
 	/*int t ;
 	cin >> t ;
 	for (int q= 1; q <= t; q++) {*/
 		int l,r,u,v;
 		int res = 0;
 		cin >> l >> r >> u >> v;
 		if ( r - l > v - u) cout << '>';
 		else if ( r - l < v - u) cout << '<';
 		else {
 				int vt1 = -1, vt2 = min(m,n);
 				int mid = (vt1 + vt2)/2;
 				long long vala = hashA.query(l , l + mid) , valb = hashB.query(u , u + mid);
 				while ( vt1 < vt2) {
 					mid = (vt1 + vt2)/2;
 					vala = hashA.query(l , l + mid);
 					valb = hashB.query(u , u + mid);
 					if(vala != valb) {
 						vt2 = mid;
 					}
 					else {
 						vt1 = mid + 1;
 					}
 				}
 				res = mid;
 		}
 		// ktra res  
 		
		if (hashA.query(l ,l + res + 1) == hashB.query(u - 1 , u + res) ) res = res + 1;
		else if (hashA.query(l ,l + res - 1) == hashB.query(u , u + res - 1) ) res = res - 1;
 		else if (hashA.query(l ,l + res ) == hashB.query(u - 1 , u + res - 1 ) ) res = res;
 		cout << res ;
		/*if (res == -1) {
			if (a[l-1] > b[u-1]) cout <<'>';
			else cout << '<';

		}
		else if (a[l + res] > b[u + res] ) {
			cout << '>'; 
		}
		else cout << '<';*/

	//}
    return 0;
}