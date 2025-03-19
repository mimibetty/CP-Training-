#include <iostream>
#include <vector>

using namespace std;

bool isValidMatrix(const vector<vector<int>>& matrix, int n, int m) {
    // Kiểm tra các hàng ngang
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m - 3; ++j) {
            if (matrix[i][j] == matrix[i][j + 1] && matrix[i][j] == matrix[i][j + 2]) {
                return false;
            }
        }
    }
    
    // Kiểm tra các cột dọc
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i <= n - 3; ++i) {
            if (matrix[i][j] == matrix[i + 1][j] && matrix[i][j] == matrix[i + 2][j]) {
                return false;
            }
        }
    }
    
    // Kiểm tra L-shape và reverse L-shape
    for (int i = 0; i <= n - 2; ++i) {
        for (int j = 0; j <= m - 2; ++j) {
            if (matrix[i][j] == matrix[i][j + 1] && matrix[i][j] == matrix[i + 1][j]) {
                return false; // L-shape
            }
            if (matrix[i][j] == matrix[i + 1][j] && matrix[i][j] == matrix[i + 1][j + 1]) {
                return false; // reverse L-shape
            }
        }
    }
    
    return true;
}

void generateMatrices(vector<vector<int>>& matrix, int n, int m, int row, int col, int& count) {
    if (row == n) {
        if (isValidMatrix(matrix, n, m)) {
            ++count;
        }
        return;
    }
    
    int nextRow = (col == m - 1) ? row + 1 : row;
    int nextCol = (col == m - 1) ? 0 : col + 1;
    
    matrix[row][col] = 0;
    generateMatrices(matrix, n, m, nextRow, nextCol, count);
    
    matrix[row][col] = 1;
    generateMatrices(matrix, n, m, nextRow, nextCol, count);
}

int main() {
        if(fopen("input.txt", "r")) {
            freopen("input.txt","r",stdin);
            // freopen("output.txt","w",stdout);
        }
    
        ios::sync_with_stdio(0);
        cin.tie(NULL);
    
    int n, m;
    cout << "Nhập n và m: ";
    cin >> n >> m;
    
    vector<vector<int>> matrix(n, vector<int>(m));
    int count = 0;
    
    generateMatrices(matrix, n, m, 0, 0, count);
    
    cout << "Số ma trận thỏa mãn: " << count << endl;
    
    return 0;
}