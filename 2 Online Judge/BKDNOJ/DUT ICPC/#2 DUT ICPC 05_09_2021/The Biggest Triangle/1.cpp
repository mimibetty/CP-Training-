#include<bits/stdc++.h>
using namespace std;

const double INF = -1e9;

struct line
{
    double a,b,c;
};

line x[105];

pair<double,double> commonPoint(line &p, line&q) {
    //(a1b2 – a2b1) x = c1b2 – c2b1
    //double determinant = a1*b2 - a2*b1;
    double determinant = p.a*q.b - q.a*p.b;

    if (determinant == 0) {
        // parallel 
        return {INF,INF};
    }

    double x = p.c * q.b - q.c * p.b; //(c1b2 - c2b1)/determinant
    x /= determinant; 
    double y = p.a * q.c - q.a * p.c; // (a1c2 - a2c1)/determinant 
    y /= determinant; 
    return {x,y};
}

double sq (double a) {
    return a*a;
}
double dist(pair<double,double>a, pair<double,double>b) {
    double x = sq(a.first - b.first) + sq(a.second - b.second);
    double res = sqrt(x);
    return res;
}

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n; 
    double x1,x2,y1,y2;
    for (int i = 1; i <= n; i++) {   
        cin >> x1 >> y1 >> x2 >> y2;
        x[i].a = y2 - y1;
        x[i].b = x1 - x2;
        x[i].c = (y1*x[i].b)  + (x1*x[i].a);
    }

    double res = INF;
    
    for (int i = 1; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            for (int k = j + 1; k <= n; k++) {
                pair<double, double> p1 = commonPoint(x[i], x[j]);
                pair<double, double> p2 = commonPoint(x[i], x[k]);
                pair<double, double> p3 = commonPoint(x[k], x[j]);
             
                pair<double, double> pINF = {INF, INF};
                if (p1 == pINF || p2 == pINF || p3 == pINF) continue;
                if (p1 == p2 || p2 == p3 || p1 == p3) continue;
 
                double peri = dist(p1, p2) + dist(p2, p3) + dist(p3, p1);
                res = max(res, peri);
            }
        }
    }
 
    if (res == INF) cout << "no triangle";
    else {
        cout << fixed << setprecision(10) << res;
    }

    return 0;
}