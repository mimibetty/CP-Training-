#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int n,k;
 	cin >> n >> k;
 	vector<int> b;
 	multiset<int>s;

 	for (int i = 1; i <= n; i++) {
 		cin >> a[i];
 		b.push_back(a[i]);
 		s.insert(a[i]);
 	}
    auto r = equal_range(ar + 1, ar + 1 + n, x);  // số lượng ar[i] = x trong mảng;
    cout << r.second-r.first << "\n";
    
 	sort(a + 1, a + 1 + n);
 	// Ap Dung Voi Mang
 	for (int i = 1; i <= n; i++) {
 		// tim min >= k
 		auto j = lower_bound(a + 1, a + 1 + n,k) - a;
 		// tim min > k
 		auto m = upper_bound(a + 1, a + 1 + n,k) - a;
 		// IN RA GIA TRI
 		cout << a[j] << endl;
 		//IN RA VI TRI
 		cout << j << endl;
 	}

 	// Ap Dung Voi Vector 
 	// Mang Giong Vector
 	for (auto i : b) {
 		auto j = lower_bound(b.begin(), b.end(), k) - b.begin();
 		auto m = upper_bound(b.begin(), b.end(), k) - b.begin();
 		// IN RA GIA TRI
 		cout << b[j] << endl;
 		//IN RA VI TRI
 		cout << j << endl; 
 	}

 	for (auto i : s) {
 		auto j = s.lower_bound(k); 
 		auto m = s.upper_bound(k); 
 		// IN RA GIA TRI
 		cout << *j << endl;
 		//IN RA VI TRI
 		cout << s.find(*j) << endl;
 		// XOA TAT CA CAC PHAN TU CO GIA TRI J
 		s.erase(*j);
 		// XOA VI TRI 
 		s.erase(s.find(*j));	
 	}

 	// CHECK SO UPPER CO TON TAI KO
	auto x = s.upper_bound(m);
	if (x == s.begin()) {
		continue;
	}
	x--;
	if (x == s.end()) continue;
    return 0;
}