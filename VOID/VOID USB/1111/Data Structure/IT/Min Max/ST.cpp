#include <bits/stdc++.h>

using namespace std;

int st[400005];
int a[400005];
int posInf = 1e18;
int negInf = -1e18;

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
    st[id] = min(st[2 * id], st[2 * id + 1]);
}

int query(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        // Đoạn [u, v] không giao với đoạn [l, r]
        return posInf;
    }

    if (u <= l && r <= v) {
        // Đoạn [u, v] bao trùm đoạn [l, r]
        return st[id];
    }

    int mid = (l + r) / 2;
    return min(query(2 * id, l, mid, u, v), query(2 * id + 1, mid + 1, r, u, v));
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    for (int i = 1; i <= q; i++) {
        int k, h;
        cin >> k >> h;
        cout << query(1, 1, n, k, h) << endl;
    }

//    for (int i = 1; i <= 15; i++) {
//        cout << st[i] << " ";
//    }
    return 0;
}

