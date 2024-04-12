	#include <bits/stdc++.h>
	using namespace std;
	#define EPS 1e-8
	#define precision(x) cout << setprecision(x) << fixed;

	long double a[50000],b[50000];
	int n;
	long double dist(long double t, long double x, long double y)
	{
		return sqrt((t-x)*(t-x)+y*y);
	}
	long double compute(long double X)
	{
		long double res = 0;
		for (int i = 1; i <=n; i++)
			res =max(res,dist(X,a[i],b[i]));
		return res;
	}
	void ass()
	{
		long double low = -1e6;
		long double high = 1e6;
		while ((high - low) > EPS) {
			long double mid1 = low + (long double)(high - low) / 3;
			long double mid2 = high - (long double)(high - low) / 3;
			long double dist1 = compute(mid1);
			long double dist2 = compute(mid2);
			if (dist1 < dist2)
				high = mid2;
			else
				low = mid1;
		}
		precision(8);
		cout << (long double)(low+high)/2 << ' ' << (long double)compute((long double)(low+high)/2) << '\n';
		// printf("%.6f %.6f\n",(double)(low+high)/2,compute((double)(low+high)/2));
	}
	int main()
	{	
		// freopen("input.txt", "r", stdin);
	    //freopen("output.txt", "w", stdout);
	    ios::sync_with_stdio(0);
	    cin.tie(NULL);

		while (true){
		    cin>>n;
		    if (n==0) break;
		    for (int i=1; i<=n; i++) {
		    	string x,y;
		    	cin >> x >> y;

		    	a[i] = stold(x);
		    	b[i] = stold(y);
		    	// cin>>a[i]>>b[i];
		    		
		    } 
		    ass();
		}
		return 0;
	}