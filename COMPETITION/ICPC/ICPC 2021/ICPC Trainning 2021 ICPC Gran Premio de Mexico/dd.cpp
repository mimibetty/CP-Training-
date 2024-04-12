#include<bits/stdc++.h>
using namespace std;

int n;

    struct xemay{
        float giaxe;
        string nhaSanxuat;
    };
struct hanghoa {
    string maH, tenH;
    int sl;

    xemay aa;
    void xenhohon25() {
    for (int i = 1; i <= n; i++) {
        if (a[i].aa.giaxe < 25) {
            cout << "Ten xe: " << a[i].tenH << endl;
            cout << "so luong:  " << a[i].sl << endl;
            cout << "Gia xe:  " << ' ' << a[i].aa.giaxe << endl;
            cout << "nhaSanxuat: " << ' ' << a[i].aa.nhaSanxuat << endl;    
            cout << endl;
        }
    }

    void honda() {
        cout << endl;
        for (int i = 1; i <= n; i++) {
            if (a[i].tenH == "Honda") {
                cout << "Xe Honda :" << endl;
                cout << "so luong xe" << ' ' << a[i].sl << endl;
                cout << "Doanh thu " << ' ' << a[i].aa.giaxe*a[i].sl <<endl;   
            }
        }   
        cout << endl;
    }

    void xethapnhat() {
        float minval = 9999999999;
        string name;
        for (int i = 1;i <= n; i++) {
            if (minval >= a[i].aa.giaxe) {
                minval =a[i].aa.giaxe;
                name = a[i].tenH;
            }
        }
        cout << endl;
        cout << "Xe Re Nhat: ";  
        for (int i = 1; i <= n; i++) if(a[i].aa.giaxe == minval) cout << a[i].tenH << endl;
    }
};

hanghoa a[1000];



int main() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].maH >> a[i].tenH >> a[i].sl;
        cin >> a[i].aa.giaxe >> a[i].aa.nhaSanxuat;
    }

    
    return 0;
}