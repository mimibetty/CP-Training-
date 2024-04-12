/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
 
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}
// struct Point {
//     int x, y;
//     bool operator<(const Point& other) const {
//         if (x == other.x) {
//             return y < other.y;
//         }
//         return x < other.x;
//     }
// };

// #include <vector>
// #include <algorithm>
// #include <limits>

typedef long long T;

struct Point {
    T x, y;

    Point operator-(const Point& other) const {
        return {x - other.x, y - other.y};
    }

    bool operator<(const Point& other) const {
        if (x == other.x) {
            return y < other.y;
        }
        return x < other.x;
    }

    T dist2() const {
        return x * x + y * y;
    }

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

bool on_x(const Point& a, const Point& b) { return a.x < b.x; }
bool on_y(const Point& a, const Point& b) { return a.y < b.y; }

struct Node {
    Point pt;
    T x0 = numeric_limits<T>::max(), x1 = -numeric_limits<T>::max();
    T y0 = numeric_limits<T>::max(), y1 = -numeric_limits<T>::max();
    Node *first = nullptr, *second = nullptr;

    T distance(const Point& p) {
        T x = (p.x < x0 ? x0 : p.x > x1 ? x1 : p.x);
        T y = (p.y < y0 ? y0 : p.y > y1 ? y1 : p.y);
        return (Point{x, y} - p).dist2();
    }

    Node(vector<Point>&& vp) : pt(vp[0]) {
        for (Point p : vp) {
            x0 = min(x0, p.x); x1 = max(x1, p.x);
            y0 = min(y0, p.y); y1 = max(y1, p.y);
        }
        if (vp.size() > 1) {
            sort(vp.begin(), vp.end(), x1 - x0 >= y1 - y0 ? on_x : on_y);
            int half = vp.size()/2;
            first = new Node({vp.begin(), vp.begin() + half});
            second = new Node({vp.begin() + half, vp.end()});
        }
    }
};

struct KDTree {
    Node* root;
    KDTree(const vector<Point>& vp) : root(new Node({vp.begin(), vp.end()})) {}

    pair<T, Point> search(Node *node, const Point& p) {
        if (!node->first) {
            if (p == node->pt) return {numeric_limits<T>::max(), Point()};
            return make_pair((p - node->pt).dist2(), node->pt);
        }

        Node *f = node->first, *s = node->second;
        T bfirst = f->distance(p), bsec = s->distance(p);
        if (bfirst > bsec) swap(bsec, bfirst), swap(f, s);

        auto best = search(f, p);
        if (bsec < best.first)
            best = min(best, search(s, p));
        return best;
    }

    pair<T, Point> nearest(const Point& p) {
        return search(root, p);
    }
};

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    vector<Point> points = {{2, 3}, {2, 3}, {9, 6}, {4, 7}, {8, 1}, {7, 2}};
    
    KDTree kd(points);
    Point a;
    a.x = 2, a.y =3 ;
    auto x = kd.nearest(a);
    cout << x.second.x << ' ' << x.second.y << endl;
    return 0;
}