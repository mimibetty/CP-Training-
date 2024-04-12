#include <bits/stdc++.h>
using namespace std;

int st[4 * 1000005];
int a[4000005];
// Given a[1], a[2], ..., a[n]
// q queries:
// 1 u val: a[u] = val
// 2 l r: print max(a[l] -> a[r])

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


int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,q;
    cin >> n >> q;
    for ( int i = 1 ; i <= n; i++ ) cin >> a[i];
   	build(1 , 1 , n);
   	for ( int s = 1; s <= q; s++ ) {
   		int t;
   		int l,r;
   		cin >> t >> l >> r;
   		if ( t ==  1) {
   			update(1 , 1 , n , l , r);
   		}
   		else {
   			cout << getMax(1, 1, n , l , r);
   			cout << '\n';
   		} 
   		
   	}
    return 0;
}