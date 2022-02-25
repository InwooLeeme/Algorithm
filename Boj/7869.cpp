#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using namespace __gnu_cxx;

#define X first
#define Y second
#define int int64_t
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define Compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)
#define IDX(v, x) (lower_bound(all(v), x) - (v).begin())
#define debug(x) cout << (#x) << ": " << (x) << '\n'

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tii = tuple<int, int, int>;
template <typename T>
using wector = vector<vector<T>>;

const double PI = acos(-1);

double _pow(double x) {
	return x * x;
}

int32_t main(){
	fastio;
	double x1,x2,y1,y2,r1,r2; cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	double d = hypot(x2 - x1, y2 - y1); // d = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) ^ 0.5
	double ret = 0;
	if(r1 + r2 <= d) ret = 0; // Not intersect
	else if(abs(r1 - r2) < d && d < r1 + r2){ // 
		double a = 2*acos((_pow(d) + _pow(r1)- _pow(r2))/(2 * d * r1));
        double b = 2*acos((_pow(d) + _pow(r2)- _pow(r1))/(2 * d * r2));
        ret = _pow(r1)*(a-sin(a)) + _pow(r2)*(b-sin(b));
        ret /=2;
	}
	else{ // 
		double mn = min(r1, r2);
		ret = mn * mn * PI;
	}
	cout << fixed << setprecision(3) << ret << "\n";
}