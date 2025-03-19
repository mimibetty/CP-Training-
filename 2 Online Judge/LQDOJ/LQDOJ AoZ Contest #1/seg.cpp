#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> convertInversionToPermutation(const vector<int>& t) {
    int n = t.size();
    vector<int> x(n);
    set<int> available; // set lưu các số còn available để chọn
    
    // Khởi tạo tập các số từ 1 đến n
    for(int i = 1; i <= n; i++) {
        available.insert(i);
    }
    
    // Duyệt từ phải sang trái
    for(int i = n-1; i >= 0; i--) {
        // t[i] cho biết cần chọn số lớn thứ mấy trong tập còn lại
        auto it = available.begin();
        // Di chuyển iterator tới vị trí thứ t[i]
        advance(it, t[i]);
        x[i] = *it; // Gán giá trị vào hoán vị
        available.erase(it); // Xóa số đã sử dụng
    }
    
    return x;
}

// Hàm kiểm tra kết quả
vector<int> getInversionArray(const vector<int>& x) {
    int n = x.size();
    vector<int> t(n);
    
    for(int i = 0; i < n; i++) {
        int count = 0;
        for(int j = 0; j < i; j++) {
            if(x[j] > x[i]) count++;
        }
        t[i] = count;
    }
    return t;
}

int main() {
    // Test với ví dụ từ đề bài
    vector<int> t = {2, 1, 0, 1, 1, 0};
    
    cout << "Day nghich the t: ";
    for(int x : t) cout << x << " ";
    cout << endl;
    
    vector<int> x = convertInversionToPermutation(t);
    
    cout << "Hoan vi x: ";
    for(int val : x) cout << val << " ";
    cout << endl;
    
    // Kiểm tra lại kết quả
    vector<int> check = getInversionArray(x);
    cout << "Kiem tra lai day nghich the: ";
    for(int val : check) cout << val << " ";
    cout << endl;
    
    return 0;
}



int binarySearch(vt,current_pos) {
    
    while (l < r) {
        mid = l+r / 2;
        if (query(1, mid) >= t[current_pos]) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    return 
}

for (int i = 1; i <= n; i++) {
    int vt = binarysearch(vt) 
    x[vt] = i;
    update(vt, 0);

}


2 1 0 1 1 0
1 1 (0) 1 1 1
     2

    3,4