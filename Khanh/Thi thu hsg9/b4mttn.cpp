#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353
typedef long long ll;

struct Hero {
    ll power;
    ll skill;
};

ll s(ll x) {
    return (x > 0) - (x < 0);
}

// Hàm tính (base^exponent) % MOD nhanh bằng binary exponentiation
ll mod_pow(ll base, ll exponent, ll mod) {
    ll result = 1;
    base %= mod;
    while(exponent > 0) {
        if(exponent & 1)
            result = result * base % mod;
        base = base * base % mod;
        exponent >>= 1;
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

    int n;
    cin >> n;

    vector<Hero> heroes(n);
    for(int i = 0; i < n; i++) {
        cin >> heroes[i].power >> heroes[i].skill;
    }

    // Sắp xếp theo power tăng dần
    sort(heroes.begin(), heroes.end(), [](const Hero &a, const Hero &b){
        return a.power < b.power;
    });

    ll total_energy = 0;

    // Duyệt từng cặp (i, j)
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            ll sum_power = heroes[i].power + heroes[j].power;

            // Tìm hero thứ ba sao cho power < sum_power
            int right = upper_bound(heroes.begin() + j + 1, heroes.end(), sum_power - 1, 
                [](ll val, const Hero &h){
                    return val < h.power;
                }) - heroes.begin();

            for (int k = j + 1; k < right; k++) {
                ll a = heroes[i].power, x = heroes[i].skill;
                ll b = heroes[j].power, y = heroes[j].skill;
                ll c = heroes[k].power, z = heroes[k].skill;

                ll D = 1 + abs(s(x - y)) + abs(s(x*y - x*z + z*z - y*z));
                ll team_power = mod_pow((a + b + c) % MOD, D, MOD);

                total_energy = (total_energy + team_power) % MOD;
            }
        }
    }

    cout << total_energy << '\n';
    return 0;
}