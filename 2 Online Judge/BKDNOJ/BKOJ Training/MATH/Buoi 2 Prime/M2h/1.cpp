#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long, long long> pll;
typedef double ld;
 
#define For(i, l, r) for (int i = l; i < r; i++)
#define REP(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl
#define SQ(a) a*a
 
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long long oo = 1e18 + 7;
const int lim3 = 1e3, lim5 = 1e5;
const ll MOD = int(1e6)+3;
const double PI = acos(-1);

ll d[1000009]; 
int trace[1000009];
bool cnt[1000009];
int st[4005];
int a[4005];


void build(int id, int l, int r) {
    // Đoạn chỉ có 1 phần tử, không có nút con
    if (l == r) {
        st[id] = a[l];
        return ;
    }

    // Gọi đệ quy để xử lí các nút con của nút id
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);

    // Cập nhật lại giá trị min của đoạn [l, r] theo 2 nút con
    st[id] = max(st[2 * id], st[2 * id + 1]);
}

// change a[pos] using val, O(logn)
void update(int id, int l, int r, int pos, int val) {
  if (l == r) {
    st[id] = val; // or st[id] = val or st[id] += val
    return;
  }
  int mid = (l + r) / 2;
  // [l, r] = [l, mid] + [mid + 1, r]
  if (pos <= mid) { // left
    update(id * 2, l, mid, pos, val);
  }
  else { // right
    update(id * 2 + 1, mid + 1, r, pos, val);
  }

  st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int getMax(int id, int l, int r, int u, int v) {
  if (v < l || r < u) {
    return -1e9;
  }

  if (u <= l && r <= v) {
    return st[id];
  }

  int mid = (l + r) / 2;

  return max(getMax(id * 2, l, mid, u, v), getMax(id * 2 + 1, mid + 1, r, u, v));
}


ll solve(ll x, vector<int>&factor) {
	int n = factor.size();
	bitset<7>bs;
	ll sum = 0;
	for (int i = 1; i < (1 << n); i++) { // bao hàm loại trừ, cnt chẵn trừ, lẻ + 
		bs = i;
		ll bcnn = 1;
		for (int j = 0; j < n; j++) {
			if (bs[j] == 1) bcnn *= factor[j];
		}

		ll  n1 = bcnn, num = x/bcnn;
		ll  n2 = num*bcnn;
		ll val = (n1+n2) *num/2;

		if (cntBit(i) % 2 == 0 ) sum = (sum%MOD - val + MOD)%MOD;
		else sum = (val%MOD + sum%MOD) %MOD;
		sum += MOD;
		sum %=MOD;
		// cout << bs << ' ' << sum << endl;
		// cout << "PT" << ' ' << n1 << ' ' << n2 << ' ' << num << ' ' << bcnn << endl;
	}
	return sum%MOD;

} 

void sieve(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (trace[i] == 0) {
			for (int j = i * i; j <= n; j+=i) {
				if (trace[j] == 0) trace[j] = i;
			}
		}
	}
	for (int i = 2; i <= n; i++) if (trace[i] == 0) trace[i] = i;
}

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int maxN = 1000003;
 	sieve(maxN);
/*
	12 = 2^2 * 3
	D[12] =
	+sieve 2: 2 4 6 8 10 12
	+sieve 3: 3 6 9 12 
	-sieve 2,3: 6,12 
*/

 	// tiền xử lí tìm d[x]: tổng các số <= x ko nto cung nhau với x;
 	d[0] = 0;
 	d[1] = 0;
    for (int i = 2; i <= maxN; i++) {
    	int val = i;
    	vector<int>s;
    	// cout << i << endl;
    	while (val > 1) {
    		if (cnt[trace[val]] == 0) s.pb(trace[val]);
    		cnt[trace[val]] = 1;
    		val /= trace[val]; 
    	}
    	
    	d[i] = solve(i,s);	
    	for (auto i : s) cnt[i] = 0;
    	s.clear();
    }

    // int x = 5184;
    // vector<int>e{2,3};
    // cout << solve(x,e) << endl;
    
    // for (int i = 1; i <= 10000; i++) {
    // 	ll sum = 0;
    // 	for ( int j = 2; j <= i; j++) {
    // 		if (__gcd(i,j) != 1) sum += j;
    // 		sum%= MOD;
    // 	}
    // 	if (sum != d[i]) cout << i << ' ' << sum << ' ' << d[i] << endl;
    // }



    int t;
    cin >> t;
    while (t--) {

	    int n,q;
	    cin >> n >> q;

	    for (int i = 1; i <= n; i++) {
	    	cin >> a[i];
	    	a[i] = d[a[i]];
	    }
	    build(1 , 1 , n);

	    while (q--) {
	    	int type;
	    	int idx,r,l;

	    	cin >> type;

	    	// cout << "TTTT  " << q << endl; 
	    	// for (int i = 1; i <= n; i++) cout << getMax(1 , 1 ,n , i, i) << ' ';
	    	// cout << endl;

	    	if (type == 1) {
	    		cin >> l >> r;
	    		cout << getMax(1, 1, n , l , r);
	   			cout << '\n';
	    	}
	    	else {	
	    		cin >> idx;
	    		auto value = getMax(1, 1, n , idx , idx);
	    		update(1 , 1 , n , idx ,d[value]);
	    	}

	    	// for (int i = 1; i <= n; i++) cout << getMax(1 , 1 ,n , i, i) << ' ';
	   		// cout << endl;
	    }
	}
    return 0;
}