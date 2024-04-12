#include<bits/stdc++.h>
using namespace std;

typedef long long Int;

/*
duyệt trâu 3^n
duyệt phân tập 3^(n/2) * T(3^(n/2))

mỗi phần chứa các thông tin : (a,b,c)
a : giá trị tập 1
b : giá trị tập 2
c : giá trị phần không chọn

match (a,b,c) với (A,B,C) ?
a+A = b+B
a-b = -(A-B)
--> tôi dùng map
*/
const int N = 100;
int weight[N];

Int delta = 0, unpicked = 0;
typedef pair<Int,Int> info;
void backtrack(int i, const int& r, vector<info>& s) {
	if (i > r) 
		s.push_back(make_pair(delta, unpicked));
	else {
		delta += (Int) weight[i];
		backtrack(i+1,r,s);
		delta -= (Int) 2*weight[i];
		backtrack(i+1,r,s);
		delta += (Int) weight[i];
		unpicked += (Int) weight[i];
		backtrack(i+1,r,s);
		unpicked -= (Int) weight[i];		
	}
}

const int MAX = 1e6 + 1e5;
const Int INF = 1e18;
Int Min[MAX];
int neg[MAX];

/*
subtask 3 : n <= 50, v <= 100
f(i,x,y) = true/false xét trong i số đầu tiên, liệu có tạo được tổng phần 1 là x, tổng phần 2 là y
KMTTQ, giả sử x >= y
f(i,x) = y : xét trong i số đầu tiên, phần 1 có tổng là x, thì phần 2 lớn nhất là?
trạng thái sai, code khá giống tham :)

f(i,d) = x : xét trong i số đầu tiên, chênh lệch giữa phần lớn và phần bé là d, thì tổng phần bé lớn nhất là?
*/
const int SUM = N * 1000;
int dp[N][SUM];

int main()
{
	// #define task "treasure"
	// if (fopen(task".inp", "r")) {
	// 	freopen(task".inp", "r", stdin);
	// 	freopen(task".out", "w", stdout);
	// }
//	freopen("debug.txt", "w", stderr);
	int num_elems;
	while (cin >> num_elems) {
		for (int i = 1; i <= num_elems; i++) cin >> weight[i];
		if (num_elems > 24) {
			int total = 0;
			int ans = 1e9;
			for (int i = 1; i <= num_elems; i++) total += weight[i];
//			for (int i = 1; i <= num_elems; i++) cerr << weight[i] << ' '; cerr << '\n';
//			cerr << "total = " << total << '\n';
			for (int s = 1; s <= total; s++) dp[0][s] = -ans;
			for (int i = 0; i < num_elems; i++) {
				for (int s = 0; s <= total; s++) dp[i+1][s] = dp[i][s];
				for (int s = 0; s <= total; s++) if (dp[i][s] >= 0) {
					int ss = s + weight[i+1];
					if (ss <= total and dp[i][s] >= 0) 
						dp[i+1][ss] = max(dp[i+1][ss], dp[i][s]);
					ss = abs(s - weight[i+1]);
					dp[i+1][ss] = max(dp[i+1][ss], dp[i][s] + min(s,weight[i+1]));
				}
			}
//			for (int i = 1; i <= num_elems; i++)
//				for (int s = 0; s <= total; s++) if (dp[i][s] >= 0)
//					cerr << "[" << i << ',' << dp[i][s] << ',' << dp[i][s]+s << "]\n";
			ans = total - 2*dp[num_elems][0];
			cout << ans << '\n';
//			cerr << "ans = " << ans << '\n';
			continue;
		}
		vector<info> lset, rset;
		int m = (num_elems / 2);
		lset.clear();
		rset.clear();
		backtrack(1,m,lset);
		backtrack(m+1,num_elems,rset);
	
		sort(lset.begin(), lset.end());
		for (auto& pair : rset) pair.first = -pair.first;
		sort(rset.begin(), rset.end());
		
		Int ans = INF;
		auto jt = lset.begin();
		for (auto it = rset.begin(); it != rset.end(); it++) {
			for (;jt < lset.end() and (jt->first) < (it->first); jt++);
			for (;jt < lset.end() and jt->first == it->first; jt++)
				ans = min(ans, (jt->second) + (it->second)); 
		}
//		for (auto& pair : lset) 
//			pair.first = lower_bound(all_vals.begin(), all_vals.end(), pair.first) - all_vals.begin();

//		int id = 0;
//		for (auto pair : rset) {
//			neg[++id] = lower_bound(all_vals.begin(), all_vals.end(), -pair.first) - all_vals.begin();
//			if (neg[id] < (int) all_vals.size() and all_vals[neg[id]] == -pair.first) 
//				Min[neg[id]] = INF;
//		}			
//		for (auto pair : lset)
//			Min[pair.first] = min(Min[pair.first], pair.second);
//		Int ans = INF;
//		id = 0;
//		for (auto pair : rset) {
//			if (neg[++id] < (int) all_vals.size() and all_vals[neg[id]] == -pair.first) 
//				ans = min(ans, Min[neg[id]] + pair.second);
//		}
////		cerr << "ans";
		cout << ans << '\n';
	}
	
}