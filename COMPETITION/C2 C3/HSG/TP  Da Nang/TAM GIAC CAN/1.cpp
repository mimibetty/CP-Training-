#include <bits/stdc++.h>
using namespace std;

long long a[500005];
long long cnt[100005];
long long S_cnt[100005];

int main() {
	freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
   
/*    fact[0] = 1;
    inv[0] = 1;
    for (long long i = 1; i <= 500000; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = pw(fact[i], MOD - 2);
    }*/

    long long n;
    cin >> n;
    set<long long>s;
    long long res = 0;

    for (long long i = 1; i <= n; i++) {
    	cin >> a[i];
    	cnt[a[i]]++;
    	s.insert(a[i]);
    }

    long long sum = 0;
    for (auto i : s) {
    //	cout << i <<' ';
    	S_cnt[i] = cnt[i] + sum;
    	sum += cnt[i];
    }
  //  cout << endl;
    //for (auto i : s) cout << S_cnt[i] <<' ';
    
    for (auto i : s) {
    	if (cnt[i] >= 2) {
    		auto j = s.lower_bound(2*i);
    		if(j == s.begin() ) continue;
    		j--;
    		if(j == s.end() ) continue;

    		if (*j >= i) {
    			//res += combi(cnt[i],2)  * (S_cnt[*j] - cnt[i]);
    			res += ( (cnt[i] * (cnt[i] - 1) / 2 ) * (S_cnt[*j] - cnt[i]) );
    		}
    		else res += ( (cnt[i] * (cnt[i] - 1) / 2 ) * S_cnt[*j] ); 
    		 
    	}
    	if (cnt[i] >= 3) {
    		//res+= combi(cnt[i],3);
    		res += ( cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6 );
    	}
    }	
    cout << res ;
    return 0;
}