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

const int PRECISION = 0;

#define double long double
const double EPS = 1e-12;
const double PI = acos(-1);

struct point {
	int x, y;
	/* constructors */
	point() : x(0), y(0) {}
	point(int x, int y) : x(x), y(y) {}
	/* methods */
	friend int dist(point a, point b) { // (Euclidean distance)^2, use ll if x, y > 1e4
		return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	}
	friend int ccw(point a, point b, point c) {
		int t = (b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y);
		return t ? t > 0 ? 1 : -1 : 0;
	}
	friend int is_cross(point a, point b, point c, point d) { // cross : -1, intersect : 1
		int ab = ccw(a, b, c) * ccw(a, b, d);
		int cd = ccw(c, d, a) * ccw(c, d, b);
		if (ab < 0 && cd < 0) return -1;
		if (ab == 0 && cd == 0) {
			if (a > b) swap(a, b);
			if (c > d) swap(c, d);
			return c <= b && a <= d;
		}
		return ab <= 0 && cd <= 0;
	}
	/* operators */
	bool operator == (const point& i) const { return x == i.x && y == i.y; }
	bool operator <  (const point& i) const { return x < i.x || x == i.x && y < i.y; }
	bool operator >  (const point& i) const { return i < *this; }
	bool operator != (const point& i) const { return !(*this == i); }
	bool operator <= (const point& i) const { return *this < i || *this == i; }
	bool operator >= (const point& i) const { return *this > i || *this == i; }
	friend int operator * (point a, point b) { return a.x * b.y - a.y * b.x; } // cross product
	friend point operator + (point a, point b) { return { a.x + b.x, a.y + b.y }; }
	friend point operator - (point a, point b) { return { a.x - b.x, a.y - b.y }; }
	friend istream& operator >> (istream& in, point& i) { in >> i.x >> i.y; return in; }
};

struct line {
	point a, b;
	/* constructors */
	line() {}
	line(point a, point b) : a(a), b(b) { if (a > b) swap(a, b); }
	/* methods */
	double length() { return sqrt(dist(a, b)); }
	bool is_on_line(point c) { return !ccw(a, b, c) && min(a, b) <= c && c <= max(a, b); }
	friend int is_cross(line a, line b) { return is_cross(a.a, a.b, b.a, b.b); }
	/* operators */
	friend istream& operator >> (istream& in, line& i) { in >> i.a >> i.b; return in; }
};


void Sol(){
    int n; cin >> n;
    vector<point> v(n),u(n); for(auto& i : v) cin >> i; for(int i = 0; i < n; i++) cin >> u[i].x >> u[i].y;
    map<int, point> M;
    for(int i = 1; i <= n; i++) M[i] = u[i - 1];
    vector<int> chk(n); iota(chk.begin(), chk.end(), 1);
    do{
        bool check = 1;
        vector<line> l;
        for(int i = 0; i < n; i++) l.push_back(line(v[i], M[chk[i]]));
        for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++){
            if(is_cross(l[i], l[j])) {check = 0; break;}
        }
        if(check){
            for(auto& i : chk) cout << i << "\n";
            break;
        }
    }while(next_permutation(chk.begin(), chk.end()));
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Sol();
    return 0;
}