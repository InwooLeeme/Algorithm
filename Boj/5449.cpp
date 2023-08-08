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
#define double long double
const double EPS = 1e-12;
const double PI = acos(-1);

using pii = pair<double, int>;

struct point {
	int x, y;
	/* constructors */
	point() : x(0), y(0) {}
	point(int x, int y) : x(x), y(y) {}
	/* methods */
	friend int dist(point a, point b) { //(Euclidean distance)^2, use ll if x, y > 1e4
		return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	}
	friend int ccw(point a, point b, point c) {
		int t = (b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y);
		return t ? t > 0 ? 1 : -1 : 0;
	}
	friend bool is_cross(point a, point b, point c, point d) {
		int ab = ccw(a, b, c) * ccw(a, b, d);
		int cd = ccw(c, d, a) * ccw(c, d, b);
		return ab < 0 && cd < 0;
	}
	/* operators */
	bool operator == (const point& i) const { return x == i.x && y == i.y; }
	bool operator <  (const point& i) const { return x < i.x || x == i.x && y < i.y; }
	bool operator >  (const point& i) const { return i < *this; }
	bool operator <= (const point& i) const { return *this < i || *this == i; }
	bool operator >= (const point& i) const { return *this > i || *this == i; }
	friend istream& operator >> (istream& in, point& i) { in >> i.x >> i.y; return in; }
};

struct line {
	point a, b;
	/* constructors */
	line() {}
	line(point a, point b) : a(a), b(b) { if (a > b) swap(a, b); }
	/* methods */
	double length() { return sqrt(dist(a, b)); }
	friend bool is_cross(line a, line b) { return is_cross(a.a, a.b, b.a, b.b); }
	/* operators */
	friend istream& operator >> (istream& in, line& i) { in >> i.a >> i.b; return in; }
};

const int PRECISION = 6;

void Main(){
    point s, e; cin >> s >> e;
	int n; cin >> n;
	vector<point> w{ s, e };
	vector<line> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		w.push_back(v[i].a);
		w.push_back(v[i].b);
	}
    // Graph Construct
    vector<vector<pii>> G(w.size() + 1);
    for(int i = 0; i < w.size(); i++) for(int j = i + 1; j < w.size(); j++){
        bool check = 1;
        line cur(w[i], w[j]);
        for(const auto& L : v) if(is_cross(L, cur)){ check = 0; break;}
        if(!check) continue;
        double d = sqrt(dist(w[i], w[j]));
        G[i].push_back({d, j});
        G[j].push_back({d, i});
    }
    // dijkstra
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    vector<double> dist(w.size() + 1, 2e18); 
    dist[0] = 0;
	PQ.push({ dist[0], 0 });
	while (!PQ.empty()) {
		auto [cdist, cur] = PQ.top(); PQ.pop();
		if (abs(dist[cur] - cdist) > EPS) continue;
		for (auto [ndist, nxt] : G[cur]) {
			if (dist[nxt] > cdist + ndist) {
				dist[nxt] = cdist + ndist;
				PQ.push({ dist[nxt], nxt });
			}
		}
	}
    cout << dist[1] << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    int t; cin >> t; while(t--) Main();
    return 0;
}