/*
link submit: 
Note:
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

int a[100005];

int min_prime[1000005];
int cnt[1000005];
void sieve(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (min_prime[i] == 0) { //if i is prime
            for (int j = i * i; j <= n; j += i) {
                if (min_prime[j] == 0) {
                    min_prime[j] = i;
                }
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (min_prime[i] == 0) {
            min_prime[i] = i;
        }
    }
}


int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    sieve(1000000);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // ll res = 0;
    // for (int i = 1; i <= n; i++) {
    //     int tmp = a[i];
    //     int x;
    //     while (tmp > 1) {
    //         x = min_prime[tmp];
    //         cnt[x]++;
            
    //         while (tmp % x == 0) tmp /= x;
    //     }
    // }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = i +1; j <= n; j++) {
    //         if (__gcd(a[i], a[j]) == 1) {
    //             res++;
    //         }
    //     }
    // }
    cout << res << endl;
    return 0;

}


n/1  + n/2 + ... + n/k-1   + n/k

n/i   -> i = 1 -> k
res = 0


res = x1 + x2
TH1  n/ i    i -> 1 -> sqrt(n)  => so luong khac nhau max = sqrt(n)
    n/i = x  >    sqrt(n) , số lượng x tạo ra sqrt(k)
    x1 = sum(n/i) i <= sqrt(k)

    for (int i = 1; i <= sqrt(n); i++) {
        x1 += n/i;
    }


TH2 i -> sqrt(n) + 1  -> k    n/i  <= sqrt(n)  => sl khac nhau max = sqrt(n)
    n/i < sqrt(n)
    x2 = sum(n/i)  i > sqrt(n)  -> k 
1e12 
1e6 -> 1e12? 

20  sqrt(20) = 4

n/i > sqrt(n)
20/1 = 20 
20/2 = 10 
20/3 = 6
20/(4) = 5   > 4
x1 đã có 


n/i < sqrt(n)   1 <= n/i <= sqrt(n)
n/i = z    for (int z = 1; z <= sqrt(n); z++) {
    x2 += soluong(zi) * zi 
}

3 < n/i <= 4
x2 = n/i
x2 = sum (n/i)  
x2 =zi * cnt[zi] =  4*2   + 3*3 + 2*5 + 1*10 =   
20/5 = 4
 20/6 = 4 
20/7 = 3
20/8 = 3
20/9 = 3  
20/10 = 2
20/11 = 2
 / 12 =     2
2
2
2
1
1
1
1
0