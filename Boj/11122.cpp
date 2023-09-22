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

template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

vs Split(string& s){
	string temp; 
	vs ret;
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

constexpr int INF = int(2e18);

struct MCMF {
    struct Edge {
        int nxt;
        int inv; //inverse edge index
        int res; //residual
        int cost; //cost
    };

    vector<vector<Edge>> adj;
    vector<int> h, inq; //johnson's algorithm, spfa
    vector<int> dist; //dijkstra
    vector<int> check, work; //max flow
    int sz, s, e; //source, sink

    MCMF(int sz) :
        adj(sz), h(sz), inq(sz),
        dist(sz), check(sz), work(sz),
        sz(sz), s(-1), e(-1) {
    }

    void set_source(int t) { s = t; }
    void set_sink(int t) { e = t; }
    void add_edge(int a, int b, int fl, int cost) {
        Edge forward{ b, (int)adj[b].size(), fl, cost };
        Edge reverse{ a, (int)adj[a].size(), 0, -cost };
        adj[a].push_back(forward);
        adj[b].push_back(reverse);
    }
    void init() {
        fill(h.begin(), h.end(), INF);
        fill(dist.begin(), dist.end(), INF);

        //johnson's algorithm with spfa
        queue<int> Q;
        inq[s] = 1;
        Q.push(s);
        while (!Q.empty()) {
            int cur = Q.front(); Q.pop();
            inq[cur] = 0;
            for (auto i : adj[cur]) {
                if (i.res && h[i.nxt] > h[cur] + i.cost) {
                    h[i.nxt] = h[cur] + i.cost;
                    if (!inq[i.nxt]) {
                        inq[i.nxt] = 1;
                        Q.push(i.nxt);
                    }
                }
            }
        }
        for (int i = 0; i < sz; i++) {
            for (auto& j : adj[i]) {
                if (j.res) j.cost += h[i] - h[j.nxt];
            }
        }

        //get shortest path DAG with dijkstra
        priority_queue<pii, vector<pii>, greater<pii>> PQ;
        dist[s] = 0;
        PQ.push({ dist[s], s });
        while (PQ.size()) {
            auto [cdist, cur] = PQ.top(); PQ.pop();
            if (dist[cur] ^ cdist) continue;
            for (auto i : adj[cur]) {
                if (i.res && dist[i.nxt] > cdist + i.cost) {
                    dist[i.nxt] = cdist + i.cost;
                    PQ.push({ dist[i.nxt], i.nxt });
                }
            }
        }
        for (int i = 0; i < sz; i++) dist[i] += h[e] - h[s];
    }
    bool update() { //update shortest path DAG in O(V+E)
        int mn = INF;
        for (int i = 0; i < sz; i++) {
            if (!check[i]) continue;
            for (const auto& j : adj[i]) {
                if (j.res && !check[j.nxt]) {
                    mn = min(mn, dist[i] + j.cost - dist[j.nxt]);
                }
            }
        }
        if (mn >= INF) return 0;
        for (int i = 0; i < sz; i++) {
            if (!check[i]) dist[i] += mn;
        }
        return 1;
    }
    int dfs(int cur, int fl) {
        check[cur] = 1;
        if (cur == e) return fl;
        for (; work[cur] < adj[cur].size(); work[cur]++) {
            auto& i = adj[cur][work[cur]];
            if (!check[i.nxt] && dist[i.nxt] == dist[cur] + i.cost && i.res) {
                int ret = dfs(i.nxt, min(fl, i.res));
                if (ret) {
                    i.res -= ret;
                    adj[i.nxt][i.inv].res += ret;
                    return ret;
                }
            }
        }
        return 0;
    }
    pii mcmf() { //cost, flow
        if (s == -1 || e == -1) return { -1, -1 };
        init();
        int cost = 0, fl = 0;
        do {
            fill(check.begin(), check.end(), 0);
            fill(work.begin(), work.end(), 0);
            int cur = 0;
            while (cur = dfs(s, INF)) {
                cost += dist[e] * cur;
                fl += cur;
                fill(check.begin(), check.end(), 0);
            }
        } while (update());
        return { cost, fl };
    }
};

const int PRECISION = 0;

void Main(){
    int t; ri(t); while(t--){
        int n,p; ri(n, p);
        vvi v(n + 1, vi(n + 1)), cost(n + 1, vi(n + 1)),O(n + 1, vi(n + 1));
        for(int i = 1; i <= n; i++) for(int j = i + 1; j <= n; j++){
            ri(cost[i][j]);
        }
        for(int i = 1; i <= n; i++) for(int j = i + 1; j <= n; j++){
            ri(v[i][j]);
        }
        int I = 0;
        for(int i = 1; i <= n; i++) for(int j = i + 1; j <= n; j++){
            ri(O[i][j]);
            I += O[i][j];
        } 
        int s = 0,e = n + 2,D = 20000;
        MCMF flow(e + 5); flow.set_source(s); flow.set_sink(e);
        flow.add_edge(s, 1, p, 0); flow.add_edge(n, e, p, 0);
        for(int i = 1; i < n; i++) flow.add_edge(i, i + 1, INF, 0);
        for(int i = 1; i <= n; i++) for(int j = i + 1; j <= n; j++){
            flow.add_edge(i, j, v[i][j], -cost[i][j]);
            flow.add_edge(i, j, O[i][j], -D);
        }
        auto [c, fl] = flow.mcmf();
        po(-c - D*I);
    }
}

int32_t main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
	return 0;
}
