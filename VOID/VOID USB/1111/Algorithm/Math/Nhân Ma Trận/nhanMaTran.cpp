#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

struct Matrix {
	long long coef[105][105];

	Matrix() {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				coef[i][j] = 0;
			}
		}
	}

	Matrix operator * (Matrix& a) {
		Matrix res;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					res.coef[i][j] += coef[i][k] * a.coef[k][j] % MOD;
					res.coef[i][j] %= MOD;
				}
			}
		}
		return res;
	}
};

Matrix pw(Matrix A, long long n) {
	if (n == 1) return A;
	Matrix Q = pw(A, n / 2);
	if (n % 2 == 0) return Q * Q;
	return Q * Q * A;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	long long n, m;
	cin >> n >> m;

	int a, b;
	cin >> a >> b;

	Matrix v1, A;

	v1.coef[a][1] = 1;

	Matrix res;
	if (m == 1) {
		res = v1;
	}
	else {
		for (int i = 1; i <= n; i++) {
			for (int j = i - 1; j <= i + 1; j++) {
				if (1 <= j && j <= n) {
					A.coef[i][j] = 1;
				}
			}
		}
		res = pw(A, m - 1);
		res = res * v1;
	}

	cout << res.coef[b][1] << endl;

	return 0;
}
