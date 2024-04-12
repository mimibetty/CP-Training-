#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long, long long> pll;
typedef double ld;
 
#define For(i, l, r) for (int i = l; i < r; i++)
#define REP(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl
#define SQ(a) a*a
 
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long long oo = 1e18 + 7;
const int lim3 = 1e3, lim5 = 1e5;
const int MOD = int(1e9)+7;
const double PI = acos(-1);


#define pdd pair<double, double>
 
void lineFromPoints(pdd P, pdd Q, double &a, double &b,double &c)
{
    a = Q.second - P.second;
    b = P.first - Q.first;
    c = a * (P.first) + b * (P.second);
	
	c = -c; 
    // if (b < 0) {
    //     cout << "The line passing through points P and Q "
    //             "is: "
    //          << a << "x - " << b << "y = " << c << endl;

    // }
    // else {
    //     cout << "The line passing through points P and Q "
    //             "is: "
    //          << a << "x + " << b << "y = " << c << endl;
    // }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	
	bool check = 1;
	double x1,y1,x2,y2,x3,y3,r,p;
	double a,b,c;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> r >> p;

	pdd P = make_pair(x1, y1);
    pdd Q = make_pair(x2, y2);
    lineFromPoints(P,Q,a,b,c);
	//pt dth 

    // cout << a << ' ' << b << ' ' << c;
    double d = c + y3*b;
    double a1 = 1 + 1.00*a*a/(b*b);
    double b1 = -2.00 * x3 + 2*d*a/(b*b);
    double c1 = x3*x3 + 1.00*d*d/ (b*b);


    precision(5);
 	if (a == 0) {
        if (b == 0 && c == 0) {
        	cout << "NO" << endl;
        	return 0;
        	 // cout << "Phuong trinh co vo so nghiem" << endl;
        }
        else if (b == 0 && c != 0) {
        	cout << "NO" << endl;
        	return 0;
        	// cout << "Phuong trinh vo nghiem" << endl;	
        }  
 		else { 
 			cout << "NO" << endl;
        	return 0;
       //      cout << "Phuong trinh co 1 nghiem:  " << endl;
     		// cout << (-c/b);
     		// cout << endl;
        }
 	}
 	else {
 		long double delta = b*b - 4*a*c;
 		if (delta > 0) {
 			delta = sqrt(delta);
 			cout << "Phuong trinh co 2 nghiem:  " << endl;
 			cout << (-b + delta)/(2*a) << endl;
 			cout << (-b - delta)/(2*a) << endl;
 		}
 		else if (delta == 0) {
 			cout << "Phuong trinh co 1 nghiem:  " << endl;
 			cout << -b/(2*a);	
 		}
 		else {
 			cout << "Phuong trinh vo nghiem" << endl;
 		}
 	}


// double r, a, b, c; // given as input

double x0 = -a*c/(a*a+b*b), y0 = -b*c/(a*a+b*b);
if (c*c > r*r*(a*a+b*b)+EPS)
    puts ("no points");
else if (abs (c*c - r*r*(a*a+b*b)) < EPS) {
    puts ("1 point");
    cout << x0 << ' ' << y0 << '\n';
}
else {
    double d = r*r - c*c/(a*a+b*b);
    double mult = sqrt (d / (a*a+b*b));
    double ax, ay, bx, by;
    ax = x0 + b * mult;
    bx = x0 - b * mult;
    ay = y0 - a * mult;
    by = y0 + a * mult;
    puts ("2 points");
    cout << ax << ' ' << ay << '\n' << bx << ' ' << by << '\n';
} 
    return 0;
}