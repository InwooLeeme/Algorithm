#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define int int_fast64_t

namespace SmallestEnclosingCircle{
    struct pt{
        long double x,y;
        pt operator + (pt const& a){ return {x + a.x, y + a.y}; }
        pt operator - (pt const& a){ return {x - a.x, y - a.y}; }
        pt operator - (){ return {-x, -y}; }
        pt operator * (long double a) { return {x * a, y * a}; }
        pt operator / (long double a) { return {x / a, y / a}; }
    };
    long double inner_product(pt a, pt b){ return a.x * b.x + a.y * b.y; }
    long double outer_product(pt a, pt b){ return a.x * b.y - a.y * b.x; }
    long double dist(pt a,pt b) { return hypot<long double>(a.x - b.x, a.y - b.y); }
    
    // 외심
    pt CenterMeter(pt a, pt b, pt c){
        pt ab = b - a, ac = c - a;
        auto c1 = inner_product(ab, ab) / 2, c2 = inner_product(ac, ac) / 2;
        auto d = outer_product(ab, ac);
        auto x = a.x + (c1 * ac.y - c2 * ab.y) / d;
        auto y = a.y + (c2 * ab.x - c1 * ac.x) / d;
        return {x, y};
    }

    struct circle{
        pt p; double r;
    };

    circle Sol(vector<pt> v){
        pt p = { 0, 0 }; double r = 0;
		int n = v.size();
		for (int i = 0; i < n; i++) if (dist(p, v[i]) > r) {
			p = v[i], r = 0;
			for (int j = 0; j < i; j++) if (dist(p, v[j]) > r) {
				p = (v[i] + v[j]) / 2, r = dist(p, v[i]);
				for (int k = 0; k < j; k++) if (dist(p, v[k]) > r) {
					p = CenterMeter(v[i], v[j], v[k]), r = dist(p, v[k]);
				}
			}
		}
		return { p, r };
    }
};

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    vector<double> x(n), y(n), z(n);
	vector<SmallestEnclosingCircle::pt> xy(n),yz(n),zx(n);
    for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i] >> z[i];
		xy[i] = {x[i], y[i]};
		yz[i] = {y[i], z[i]};
		zx[i] = {x[i], z[i]};
	}
    auto t1 = SmallestEnclosingCircle::Sol(xy);
	auto t2 = SmallestEnclosingCircle::Sol(yz);
	auto t3 = SmallestEnclosingCircle::Sol(zx);
	cout << fixed << setprecision(10) << min<double>({t1.r * 2, t2.r * 2, t3.r* 2}) << "\n";
    return 0;
}