#include <bits/stdc++.h>
using namespace std;

const int lim = 2e8 + 5;
bitset<lim>prime,isPrime;
vector<int>sieve;

void normalSieve(int n)
{
    //bool prime[n/2];
    //memset(prime, false, sizeof(prime));
 
    for (int i=3 ; i*i < n; i+=2)
    {
        if (prime[i/2] == false)
            for (int j=i*i; j<n; j+=i*2)
                prime[j/2] = true;
    }
 
    //printf("2 ");
    sieve.push_back(2);
    for (int i=3; i<n ; i+=2) {
        if (prime[i/2] == false) {
           //printf( "%d " , i );
            sieve.push_back(i);
        }

    }
    for (auto i :sieve) isPrime[i] = 1;
}
 
int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);


    normalSieve(lim);

    int t;
    cin >> t;
    for (int q = 1; q <= t; q++) {
        int l,r;
        cin >> l >> r;
        if (l > r) cout << 0 <<endl;
        else {
            auto countL = upper_bound(sieve.begin(), sieve.end(), l) - sieve.begin();
            auto countR = upper_bound(sieve.begin(), sieve.end(), r) - sieve.begin();
            cout << countR - countL + 1<<endl;    
        }
    }
    return 0;
}