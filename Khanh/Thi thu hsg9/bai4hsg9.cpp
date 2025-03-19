#include <iostream>
using namespace std;
 
const long long MOD = 1000000007;
 
// ---------------------------------------------------------
// 1. Brute force: iterative computation of Fibonacci numbers.
//    We compute F(m) for m = 2*k+1 using a loop.
 
long long fibBrute(long long m) {
    // using 1-indexed Fibonacci: F(1)=1, F(2)=1
    if(m <= 2) return 1;
    long long a = 1, b = 1, c;
    for (long long i = 3; i <= m; i++){
        c = (a + b) % MOD;
        a = b;
        b = c;
    }
    return b;
}
 
// ---------------------------------------------------------
// 2. Optimized: fast doubling method.
//    The fast–doubling method computes (F(n),F(n+1)) recursively.
 
// Returns a pair: {F(n), F(n+1)}
pair<long long,long long> fibFast(long long n) {
    if(n == 0)
        return {0, 1};
    auto p = fibFast(n >> 1);
    long long a = p.first;  // F(n)
    long long b = p.second; // F(n+1)
    long long c = ( (2 * b % MOD) - a + MOD ) % MOD;
    c = (a * c) % MOD;      // c = F(2*n)
    long long d = (a*a % MOD + b*b % MOD) % MOD; // d = F(2*n+1)
    if(n & 1)
        return {d, (c + d) % MOD};
    else
        return {c, d};
}
 
// ---------------------------------------------------------
// Main: read n, k; compute answer = n * F(2*k+1) mod MOD.
 
int main(){
        if(fopen("input.txt", "r")) {
            freopen("input.txt","r",stdin);
            // freopen("output.txt","w",stdout);
        }
    
        ios::sync_with_stdio(0);
        cin.tie(NULL);
    
    
    long long n, k;
    cin >> n >> k;
 
    // We want F(2*k+1) in our 1-indexed Fibonacci sequence.
    long long index = 2 * k + 1;
 
    // Method 1: Brute-force
    long long F_brute = fibBrute(index);
    long long ans_brute = (n % MOD) * F_brute % MOD;
    
    cout << "Brute force answer: " << ans_brute << "\n";
    
    // // Method 2: Optimized fast doubling
    // // Note: Our fast doubling is written for 0-indexed Fibonacci where F(0)=0, F(1)=1.
    // // In our 1-indexed version we need F(1)=1, F(2)=1.
    // // But it is easy to see that the 1-indexed F(m) equals the 0-indexed F(m+1).
    // auto p = fibFast(index + 1);
    // long long F_fast = p.first; // F(index+1) in 0-index = F(index) in 1-index.
    // long long ans_fast = (n % MOD) * F_fast % MOD;
 
    // // Display both answers:
    // cout << "Optimized answer: " << ans_fast << "\n";
 
    return 0;
}

s = "abcdef"

s = string -> int 
s = s[0] * base^0 + s[1] * base^i%mod + s[2] *base^2 +... s[i] *base^i %mod
742003
10042003
5-7
ab != ba 
a*base^0 + b*base^1 != a*base^1 + b*base^0

tk mk: raw(khanh12345) => mk = hash() => xyczwaqe12312312 
abc =bca
1*1^0 + 2*1^1 + 3*1^2 == 2*1^0 + 3*1^1 + 1*1^2 = 6
hash xong họ ko bi

a = b => s(a) = s(b) 
