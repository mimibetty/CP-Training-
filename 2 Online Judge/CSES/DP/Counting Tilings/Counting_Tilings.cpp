#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int dp[1001][1 << 10]; // dp[cột][trạng thái bitmask]

int main() {
        if(fopen("input.txt", "r")) {
            freopen("input.txt","r",stdin);
            // freopen("output.txt","w",stdout);
        }
    
        ios::sync_with_stdio(0);
        cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    dp[0][0] = 1; // Khởi tạo trạng thái ban đầu, lưới rỗng ban đầu có 1 cách (không làm gì)

    for (int col = 0; col < m; col++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[col][mask] == 0) continue; // Bỏ qua những trạng thái không khả thi
            // Sử dụng đệ quy để lấp đầy cột tiếp theo dựa trên trạng thái hiện tại
            function<void(int, int, int)> fill = [&](int row, int curMask, int nextMask) {
                if (row == n) {
                    // Đã lấp đầy hết các hàng trong cột hiện tại, cập nhật trạng thái cho cột tiếp theo
                    dp[col + 1][nextMask] = (dp[col + 1][nextMask] + dp[col][mask]) % MOD;
                    return;
                }
                if ((curMask & (1 << row)) != 0) { // Nếu ô này đã được lấp đầy
                    fill(row + 1, curMask, nextMask); // Tiếp tục với ô tiếp theo
                } else { // Ô này chưa được lấp đầy
                    // Lấp đầy ô này bằng cách đặt viên gạch dọc
                    fill(row + 1, curMask, nextMask | (1 << row));
                    // Lấp đầy ô này bằng cách đặt viên gạch ngang (nếu có thể)
                    if (row + 1 < n && (curMask & (1 << (row + 1))) == 0) {
                        fill(row + 2, curMask, nextMask);
                    }
                }
            };
            fill(0, mask, 0); // Bắt đầu đệ quy từ hàng đầu tiên của cột hiện tại
        }
    }

    cout << dp[m][0] << endl; // Kết quả là số cách lấp đầy lưới với cột cuối cùng có trạng thái 0
    return 0;
}