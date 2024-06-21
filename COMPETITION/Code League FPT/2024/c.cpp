#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<long long>> Matrix;
const long long MOD = 1000000007;

Matrix multiply(Matrix &A, Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j] % MOD) % MOD;
    return C;
}

Matrix matrixExponentiation(Matrix base, long long exp) {
    int size = base.size();
    Matrix result(size, vector<long long>(size, 0));
    for (int i = 0; i < size; ++i) result[i][i] = 1;  // Identity matrix
    while (exp) {
        if (exp % 2 == 1) result = multiply(result, base);
        base = multiply(base, base);
        exp /= 2;
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
    

    long long a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;
    
     Matrix P = {
        {3, 2, 1, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0}
    };
    
    if (n == 0) {
        cout << b << endl;
        return 0;
    } else if (n == 1) {
        cout << a << endl;
        return 0;
    }
    
    Matrix result = matrixExponentiation(P, n-1);
    
    // Calculate F[n]
    long long Fn = (result[0][0] * a % MOD + result[0][1] * b % MOD + result[0][2] * (c + 2*d)  % MOD +
                    result[0][3] * c % MOD + result[0][4] * d % MOD) % MOD;
    
    cout << Fn << endl;
    return 0;
}