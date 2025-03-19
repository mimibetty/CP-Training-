#include <iostream>
using namespace std;

const long long MOD = 1e9 + 7;

// Count numbers in range [0, X] with bit i set
long long countBit(long long X, int i) {
    if (X < 0) return 0;
    long long period = 1LL << (i+1);
    long long fullCycles = (X+1) / period;
    long long remainder = (X+1) % period;
    return fullCycles * (1LL << i) + max(0LL, remainder - (1LL << i));
}

// Fast modular exponentiation
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
        if(fopen("input.txt", "r")) {
            freopen("input.txt","r",stdin);
            // freopen("output.txt","w",stdout);
        }
    
        ios::sync_with_stdio(0);
        cin.tie(NULL);
    
    long long L, R;
    cin >> L >> R;
    
    long long n = R - L + 1;
    long long result = 0;
    
    // Calculate max bit position needed
    int maxBit = 0;
    long long temp = max(L, R);
    while (temp > 0) {
        maxBit++;
        temp >>= 1;
    }
    
    // Calculate contribution from each bit
    for (int i = 0; i < maxBit; i++) {
        // Count numbers with bit i set in range [L, R]
        long long r = countBit(R, i) - countBit(L-1, i);
        long long s = n - r;
        
        // Calculate s^3 and r^3 with modular arithmetic
        long long sCubed = power(s, 3, MOD);
        long long rCubed = power(r, 3, MOD);
        
        // Calculate 4*r*s^3 + 4*r^3*s (simplified combinatorial formula)
        long long term = (4 * ((r * sCubed) % MOD + (rCubed * s) % MOD)) % MOD;
        
        // Multiply by 2^i and add to result
        long long bitContribution = (power(2, i, MOD) * term) % MOD;
        result = (result + bitContribution) % MOD;
    }
    
    cout << result << endl;
    return 0;
}