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
#define fi first
#define se second
#define pb push_back

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
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R>
using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R>
using ordered_multimap = tree<T, R, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int HW_RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ HW_RANDOM; }
};

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

template <int mod>
struct ModInt {
	int x;	
	ModInt() : x(0) {}	
	ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}	
	ModInt &operator+=(const ModInt &p) {
	  if ((x += p.x) >= mod) x -= mod;
	  return *this;
	}	
	ModInt &operator-=(const ModInt &p) {
	  if ((x += mod - p.x) >= mod) x -= mod;
	  return *this;
	}	
	ModInt &operator*=(const ModInt &p) {
	  x = (int)(1LL * x * p.x % mod);
	  return *this;
	}	
	ModInt &operator/=(const ModInt &p) {
	  *this *= p.inverse();
	  return *this;
	}	
	ModInt operator-() const { return ModInt(-x); }
	ModInt operator+() const { return ModInt(*this); }	
	ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }	
	ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }	
	ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }	
	ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }	
	bool operator==(const ModInt &p) const { return x == p.x; }	
	bool operator!=(const ModInt &p) const { return x != p.x; }	
	ModInt inverse() const {
	  int a = x, b = mod, u = 1, v = 0, t;
	  while (b > 0) {
	    t = a / b;
	    swap(a -= t * b, b);
	    swap(u -= t * v, v);
	  }
	  return ModInt(u);
	}	
	ModInt pow(int64_t n) const {
	  ModInt ret(1), mul(x);
	  while (n > 0) {
	    if (n & 1) ret *= mul;
	    mul *= mul;
	    n >>= 1;
	  }
	  return ret;
	}	
	friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }	
	friend istream &operator>>(istream &is, ModInt &a) {
	  int64_t t;
	  is >> t;
	  a = ModInt<mod>(t);
	  return (is);
	}	
	int get() const { return x; }	
	static constexpr int get_mod() { return mod; }
};

constexpr int INF = int(2e18);
constexpr int MOD = int(1e9) + 7;
constexpr double PI = acos(-1);
const int PRECISION = 0;

const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

using mint = ModInt<1'000'000'007>;

/* mt19937 mt((unsigned int)time(NULL));
uniform_int_distribution<int> uid(0, INF);
auto rnd = bind(uid, mt); */

struct Line {
	mutable ll a, b, p;
	bool operator<(const Line& i) const { return a < i.a; }
	bool operator<(ll x) const { return p < x; }
};
// default upper hull if get lower hull ? x축 대칭으로 넣어주기 y = ax + b -> y = -ax - b
struct LineContainer : multiset<Line, less<>> { 
	static constexpr ll INF = LLONG_MAX;
	ll Div(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b != 0); }
	bool Cross(iterator x, iterator y) {
		if (y == end()) return x->p = INF, 0;
		if (x->a == y->a) x->p = x->b > y->b ? INF : -INF;
		else x->p = Div(y->b - x->b, x->a - y->a);
		return x->p >= y->p;
	}
	void Insert(ll a, ll b) { // y = ax + b
		auto z = insert({ a, b, 0 }), y = z++, x = y;
		while (Cross(y, z)) z = erase(z);
		if (x != begin() && Cross(--x, y)) Cross(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p) Cross(x, erase(y));
	}
	ll Query(ll x) {
		auto l = *lower_bound(x);
		return l.a * x + l.b;
	}
} CHT;

int N;
int dist[101010], v[101010], w[101010], s[101010], D[101010];

void Main(){
	ri(N);
	for(int i = 2; i <= N; i++) ri(v[i]);
	for(int i = 1; i <= N; i++) ri(w[i], s[i]);
	for(int i = 2; i <= N; i++) dist[i] = dist[i - 1] + v[i];
	for(int i = 1; i <= N; i++){
		D[i] = (i > 1 ? -CHT.Query(dist[i]) : 0);
		CHT.Insert(-s[i], -D[i] -w[i] + s[i] * dist[i]);
	}
	po(D[N]);
}	

int32_t main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
	return 0;
}
