/*
link submit: 
có n viên kẹo chia cho m người , có bao nhiêu cách 
x1 + x2 + … + xn =  m 
TH1 : 0≤ x ≤ m
chia ra làm dãy 11101111110101111
có n-1 số 0, tượng trưng cho việc phân chia số lượng số 1 vào dãy
tổng có m + n  - 1 số, cần đặt n-1 số 0 vào bất kì vị trí nào 
⇒ C(m + n - 1 , n - 1)


TH2: 1 ≤ x ≤ m 
1 1  1 1 1 1 1 1  1 1   1
có tổng m số 1, cần đặt các que tăm vào khoảng trống giữa 2 số 1 bất kì 
⇒ m - 1 khoảng trống và cần đặt n - 1 que tăm 
⇒ C(m - 1, n - 1)

C(n,k) = n! / (n-k)! * k! 
       = n! % mod     *   pw((n-k)!, mod-2)  * pw(k!, mod-2)

*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define bit(n,i)  ((n>>i) & 1) 
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

const long long MOD = 1e9 + 7;
const int NN = int(1e6 + 5);
long long fact[(2*NN)];
long long pw(long long a, long long b) {
    if (b == 0) return 1;
    long long q = pw(a,b/2);

    if (b % 2 == 0) {
        return q * q % MOD;
    }
    else {
        return q * q % MOD * a % MOD;
    }
}

long long inv(long long a) {
    return pw(a, MOD - 2);
}

long long combi(long long n, long long k) {
    return fact[n] * pw(fact[k], MOD-2) % MOD * pw(fact[n-k], MOD - 2) % MOD;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    long long people,apple;
    cin >> people >> apple;

    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i <= 2000000; i++) fact[i] = fact[i-1] * i % MOD;

    long long res = combi(apple + people - 1, people - 1);
    cout << res << endl;
    return 0;
}