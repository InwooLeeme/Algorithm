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
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using vp = vector<pii>;
using vvp = vector<vp>;
using vs = vector<string>;
using vvs = vector<vs>;
using ti3 = tuple<int,int,int>;
using vti3 = vector<ti3>;
using ll = long long;
using ull = unsigned long long;

template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename V, class cmp = less<T>>
using ordered_map = tree<T, V, cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>
using multi_ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
void printv(vector<T> v) {
	for (auto e : v) {
		cout << e << " ";
	}   cout << "\n";
}
 
template<typename T>
void printvv(vector<T> vv) {
	for (int i=0; i<vv.size(); i++) {
		cout << i << ": ";
		for (auto e : vv[i]) {
			cout << e << " ";
		}   cout << "\n";
	}
}

template<typename T>
void ri(T &x) {
	cin >> x;
}
template<typename T, typename... Args>
void ri(T &x, Args&... args) {
	ri(x);
	ri(args...) ;
}
template<typename T>
void ri(vector<T> &v) {
	for (auto &x : v) {
		cin >> x;
	}
}
template<typename T, typename... Args>
void ri(vector<T> &v, Args&... args) {
	ri(v);
	ri(args...);
}

template<typename T>
void po(T x) {
	cout << x << "\n";
}
template<typename T, typename... Args>
void po(T x, Args... args) {
	cout << x << " ";
	po(args...) ;
}
template<typename T>
void po(vector<T> &a) {
	for (int i=0; i<(int)a.size(); i++) {
		if (i <(int)a.size()-1) {
			cout << a[i] << " ";
		}
		else cout << a[i] << "\n";
	}
}

void __print(int x) {cerr << x;}
void __print(signed x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T1, typename T2, typename T3>
void __print(const tuple<T1, T2, T3> &x) {cerr << '{'; __print(get<0>(x)); cerr << ','; __print(get<1>(x)); cerr << ','; __print(get<2>(x)); cerr << '}';}
template<typename T1, typename T2, typename T3, typename T4>
void __print(const tuple<T1, T2, T3, T4> &x) {cerr << '{'; __print(get<0>(x)); cerr << ','; __print(get<1>(x)); cerr << ','; __print(get<2>(x)); cerr << ','; __print(get<3>(x)); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
template<typename T1, typename T2>
void __print(map<T1,T2> &mp) {for (auto [k,v] : mp) {cerr << '{'; __print(k); cerr << ':'; __print(v); cerr << '}';}}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int cnt_leq_x(vi &a, int x) {
	return upper_bound(a.begin(), a.end(), x) - a.begin();
}

int cnt_leq_x(vi &a, int x, int lo, int hi) {
	return upper_bound(a.begin()+lo, a.begin()+hi, x) - a.begin()+lo;
}

int cnt_lt_x(vi &a, int x) {
	return lower_bound(a.begin(), a.end(), x) - a.begin();
}

int cnt_lt_x(vi &a, int x, int lo, int hi) {
	return lower_bound(a.begin()+lo, a.begin()+hi, x) - a.begin()+lo;
}

int cnt_geq_x(vi &a, int x) {
	return a.end() - lower_bound(a.begin(), a.end(), x);
}

int cnt_geq_x(vi &a, int x, int lo, int hi) {
	return a.begin()+hi - lower_bound(a.begin()+lo, a.begin()+hi, x);
}

int cnt_gt_x(vi &a, int x) {
	return a.end() - upper_bound(a.begin(), a.end(), x);
}

int cnt_gt_x(vi &a, int x, int lo, int hi) {
	return a.begin()+hi - upper_bound(a.begin()+lo, a.begin()+hi, x);
}

bool mul_overflow(int a, int b) {
	int c;
	return __builtin_mul_overflow(a, b, &c);
}

template<typename T>
int popcount(T x) {return __builtin_popcount(x);}

template<typename T>
T sum(vector<T> &a) {
	T ret = 0;
	for (auto v : a) ret += v;
	return ret;
}

template<typename T>
T max(vector<T> &a) {
	return *max_element(a.begin(), a.end());
}

template<typename T>
T min(vector<T> &a) {
	return *min_element(a.begin(), a.end());
}

int ceil_div(int a, int b) {
	return (a + b - 1) / b;
}

int int_pow(int base, int exp) {
	int res = 1;
	while (exp) {
		if (exp & 1) res *= base;
		exp >>= 1;
		base *= base;
	}
	return res;
}

int highest_power_of_2(int n) {
	while((n & (n-1)) != 0){
		n = n & (n-1);
	}
	return n;
}

int msb_pos(int x) {
	if (x==0) return -1;
	int y = __builtin_clzll(x);
	int ret = 63 - y;
	return ret;
}

template<typename T>
void chmax(T &x, T y) {x = max(x,y);}

template<typename T>
void chmin(T &x, T y) {x = min(x,y);}

template<typename T>
void asort(vector<T> &a) {sort(a.begin(), a.end());}

template<typename T>
void dsort(vector<T> &a) {sort(a.rbegin(), a.rend());}

template<typename T>
void reverse(vector<T> &a) {reverse(a.begin(), a.end());}

template<typename T>
set<T> get_set(vector<T> &a) {
	set<T> ret(a.begin(), a.end());
	return ret;
}

template<typename T>
vector<T> get_unique(vector<T> a) {
	asort(a);
	a.erase(unique(a.begin(), a.end()), a.end());
	return a;
}

vs Split(string& s, char c){
	string temp; 
	vs ret;
	for(auto& i : s) if(i == c) i = ' ';
	stringstream in(s);
	while(in >> temp) ret.push_back(temp);
	return ret;
}

int LIS(vi& v){
	vi LIS;
	for(auto& i : v){
		if(LIS.empty() or LIS.back() < i) LIS.push_back(i);
		else *lower_bound(LIS.begin(), LIS.end(), i) = i;
	}
	return LIS.size();
}

int LDS(vi& v){
	vi LDS;
	for(auto& i : v){
		auto t = -i;
		if(LDS.empty() or LDS.back() < t) LDS.push_back(t);
		else *lower_bound(LDS.begin(), LDS.end(), t) = t;
	}
	return LDS.size();
}

int _pow(int x, int n){
    int ret = 1;
    while(n){
        if(n & 1) ret = ret * x;
        x = x * x;
        n >>= 1;
    }
    return ret;
}

int _pow(int x, int n, int MOD) {
    int ret = 1;
	while(n){
		if(n & 1) ret = ret * x % MOD;
		x = x * x % MOD;
		n >>= 1;
	}
	return ret % MOD;
}

template<typename T>
struct _Eval{
	string ops = "+-*/%()";
	bool is_op(char c) { return ops.find(c) != string::npos; }
	bool is_op(string c) { return c.size() == 1 && is_op(c[0]); }
	T run_op(T a, T b, char op) {
		if (op == '+') return a + b;
		else if (op == '-') return a - b;
		else if (op == '*') return a * b;
		else if (op == '/') return a / b;
		else return a % b;
	}
	T run_op(T a, T b, string op) { return run_op(a, b, op[0]); }
	int op_priority(string op) {
		if (op == "*" || op == "/" || op == "%") return 3;
		else if (op == "+" || op == "-") return 2;
		else return 1;
	}
	T calc_infix(const string &s) { return calc_postfix(to_postfix(s)); }
	T calc_postfix(const vector<string> &s) {
	   vector<T> ret;
	   for (auto &c: s) {
	      if (is_op(c)) {
	         T val = run_op(ret[ret.size() - 2], ret[ret.size() - 1], c[0]);
	         ret.pop_back(), ret.pop_back(), ret.push_back(val);
	      } else {
	         // Warning: long long conversion will cause crash on bigint usage
	         ret.push_back(stoll(c));
	      }
	   }
	   return ret[0];
	}
	vector<string> to_postfix(const vector<string> &s) {
	   vector<string> ret, op;
	   for (auto &c: s) {
	      if (is_op(c)) {
	         if (c == "(") op.push_back("(");
	         else if (c == ")") {
	            while (op.size() && op.back() != "(") ret.push_back(op.back()), op.pop_back();
	            op.pop_back();
	         } else {
	            while (op.size() && op_priority(op.back()) >= op_priority(c)) ret.push_back(op.back()), op.pop_back();
	            op.push_back(c);
	         }
	      } else {
	         ret.push_back(c);
	      }
	   }
	   while (op.size()) ret.push_back(op.back()), op.pop_back();
	   return ret;
	}
	vector<string> to_postfix(const string &s) { return to_postfix(parse(s)); }
	vector<string> parse(const string &s) {
		vector<string> ret;
		string tmp;
		const int sz = s.size();
		for (int i = 0; i < sz; i++) {
			if (is_op(s[i])) ret.push_back(string(1, s[i]));
			else if (i == s.size() - 1 || is_op(s[i + 1])) ret.push_back(tmp + s[i]), tmp = "";
			else tmp += s[i];
		}
	   if (ret.size() && ret[0] == "-") { // leading negative operator
			ret[1] = "-" + ret[1];
			ret.erase(ret.begin());
		}
		return ret;
	}
	string to_raw(const vector<string> &s) {
		string ret;
		for (auto & c: s) ret += c;
		return ret;
	}
};

constexpr int INF = int(2e18);

const int PRECISION = 0;

const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

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
	friend int is_cross(point a, point b, point c, point d) { // cross : -1(X), intersect : 1(X or L)
		int ab = ccw(a, b, c) * ccw(a, b, d);
		int cd = ccw(c, d, a) * ccw(c, d, b);
		if (ab < 0 && cd < 0) return -1;
		if (ab == 0 && cd == 0) {
			if (a > b) swap(a, b);
			if (c > d) swap(c, d);
			if (!ccw(a, b, c) and !ccw(a, b, d) and !ccw(c, d, a) and !ccw(c, d, b) and c < b and a < d) return 2; // intersect INF
			return c <= b && a <= d;
		}
		return ab <= 0 && cd <= 0;
	}
	friend point findInterCod(point a, point b, point c, point d){
		double x = (a.x*b.y - a.y*b.x)*(c.x - d.x) - (a.x - b.x) * (c.x*d.y - c.y*d.x);
		double y = (a.x*b.y - a.y*b.x)*(c.y - d.y) - (a.y - b.y) * (c.x*d.y - c.y*d.x);
		double div = (a.x - b.x)*(c.y - d.y) - (a.y - b.y) * (c.x - d.x);
		if(div == 0.0){
			if(b == c and a <= c) return b;
			else if(a == d and a >= c) return a;
		}
		return point(x/div, y/div);
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
	// point to line distance
	friend double dist(line a, point b) {
		auto CCW = [&](point& a, point& b, point& c) -> int {
		    return (b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y);
		};
		return CCW(a.a, a.b, b) / a.length();
	}
	/* operators */
	friend istream& operator >> (istream& in, line& i) { in >> i.a >> i.b; return in; }
};

int n,m;
vi G[1111];
int color[1111];

void Main(){
	ri(n, m);
	vector<point> p(n);
	for(auto& i : p) ri(i);
	vector<line> v(m);
	for(int i = 0; i < m; i++){
		int s; ri(s); --s;
		point x; ri(x);
		v[i] = {p[s], x};
	}
	auto Check = [&](int a, int b) -> bool{
		return is_cross(v[a], v[b]) || v[a].is_on_line(v[b].b) || v[b].is_on_line(v[a].b);
	};
	for(int i = 0; i < m; i++) for(int j = i + 1; j < m; j++){
		if(v[i].a == v[j].a) continue;
		if(!Check(i, j)) continue;
		G[i].push_back(j); G[j].push_back(i);
	}
	int flag = 0;
	auto DFS = [&](int cur, int cc, auto&& DFS) -> void{
		for(const auto& nxt : G[cur]){
			if(!color[nxt]){
				color[nxt] = 3 - cc;
				DFS(nxt, 3 - cc, DFS);
			}
			else if(color[cur] == color[nxt]){ flag = 1; }
		}
	};
	for(int i = 0; i < m; i++){
		if(!color[i]){ color[i] = 1; DFS(i, 1, DFS); }
	}
	po(flag ? "impossible" : "possible");
} 		

int32_t main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
	return 0;
} 
