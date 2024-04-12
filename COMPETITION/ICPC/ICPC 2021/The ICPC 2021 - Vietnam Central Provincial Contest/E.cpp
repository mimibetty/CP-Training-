#include <bits/stdc++.h>
using namespace std;
 
struct Point {
    long long x, y;
    Point (long long x = 0, long long y = 0): x(x), y(y) {}
 
    Point operator + (const Point &a) const{
        return {x + a.x, y + a.y};
    }
 
    Point operator - (const Point &a) const{
        return {x - a.x, y - a.y};
    }
 
    long long operator * (const Point &a) const{
        return x * a.x + y * a.y;
    }
 
    bool operator < (const Point &a) {
        if (x == a.x) return y < a.y;
        return x < a.x;
    }
 
    bool operator == (const Point &a) {
        return (x == a.x && y == a.y);
    }
};
 
// tích chéo
long long cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}
 
long long cross2(const Point a, const Point b) {
    return (a.x - b.x) * (a.y + b.y);
}
 
// area of triangle
long long area(Point a, Point b, Point c) {
    return cross(a, b) + cross(b, c) + cross(c, a);
}
 
vector<Point> convexHull(vector<Point> pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<Point> up, dn;
    for (int i = 0; i < pts.size(); i++) {
        // Note: If need maximum points on convex hull, need to change >= and <= to > and <.
        while (up.size() > 1 && area(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
        while (dn.size() > 1 && area(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
    return pts;
}

long long areaPolygon(vector<Point> a) {
    long long res = 0;
    int n = a.size();

    for (int i = 1; i < n; i++) {
        res += cross2(a[i], a[i - 1]);
    }
    res += cross2(a[0], a[n - 1]);

    return abs(res);
}
 

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {    
        
        vector<Point> a(4);
        for (int i = 0; i < 4; i++) {
            cin >> a[i].x >> a[i].y;
        }
     
        auto p = convexHull(a);
        // for (auto i: p) {
        //     cout << i.x << ' ' << i.y << endl;
        // }
        
        // long long res = areaPolygon(p);
     
        // cout << res / 2;
        // if (res % 2 == 0) cout << ".0";
        // else cout << ".5";
        if (p.size() == 4) cout << "YES";
        else cout << "NO";
        cout << endl;
    }

    return 0;
}