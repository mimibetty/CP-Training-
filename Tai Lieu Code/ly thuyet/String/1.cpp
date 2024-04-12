#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    string s = "1234567";
    int a = stoi(s); // cv string > int  ,stoll ll, stod double, stof  float
    string b = to_string(a); // int to str

    string y = s.substr(x); // sub str = vị trí x > end
    cout << s.substr(x,k); // sub tr = vtr x > x+k

    str.erase(x, y); // Xóa đi y ký tự bắt đầu tại vị trí x.
str.erase(str.begin() + x); // Xóa đi ký tự tại vị trí x.
str.erase(str.begin() + x, str.begin() + y); // Xóa đi các ký tự từ chỉ số x đến chỉ số y - 1

str.insert(x, "y"); // Thêm chuỗi y vào vị trí x.
str.insert(x, "y", z); // Thêm z ký tự từ chuỗi y vào vị trí x. Nếu z có độ dài lớn hơn độ dài chuỗi y thì tiếp tục thêm vào 1 khoảng trắng và sau đó lại bắt đầu thêm vào các ký tự của chuỗi từ vị trí 0 --> sao cho đủ z thì thôi.

str.insert(x, y, 'z'); // Thêm y lần ký tự z vào vị trí x.
str.insert(str.begin() + x, 'y'); // Thêm ký tự y vào vị trí x.
str.insert(str.begin() + x, y, 'z'); // Thêm y lần ký tự z vào vị trí x.
str.insert(str.begin() + x, str2.begin() + y, str2.begin() + z); // Thêm chuỗi ký tự con của chuỗi str2 bắt đầu từ vị trí y cho đến vị trí z - 1 vào vị trí x trong chuỗi str.

int found = str.find('x');
//if (found == -1 ) > ko xuất hiện x
if(found != string::npos) => trả về found chính là vị trí xuất hiện đầu tiên của ký tự x trong chuỗi str.
else => Không tồn tại ký tự x trong chuỗi str. 

int found = str.find("x");
if(found != string::npos) => trả về found chính là vị trí xuất hiện đầu tiên của chuỗi x trong chuỗi str.
else => Không tồn tại chuỗi x trong chuỗi str. 

int found = str.find("x", y, z);
if(found != string::npos) => trả về found chính là vị trí xuất hiện đầu tiên của chuỗi x lấy ra z ký tự và sẽ bắt đầu tìm kiếm từ vị trí y trong chuỗi str.
else => Không tồn tại chuỗi x trong chuỗi str.
    return 0;
}