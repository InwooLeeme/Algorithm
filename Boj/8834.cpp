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

int _pow(int x, int n){
    int ret = 1;
    while(n){
        if(n & 1) ret = ret * x;
        x = x * x;
        n >>= 1;
    }
    return ret;
}

constexpr int INF = int(2e18);

const int PRECISION = 0;

template<typename T>
struct SplayTree {
    struct Node {
        //member variables
        Node* l, * r, * p;
        int sz;
		T v, sum, mx, mn;
        bool flip;

        //constructor, destructor
        Node() : Node(0) {}
        Node(T v) : Node(v, nullptr) {}
        Node(T v, Node* p) : v(v), sum(v), mx(v), mn(v), p(p) {
            l = r = nullptr, sz = 1, flip = 0;
        }
        ~Node() {
            if (l) delete l;
            if (r) delete r;
        }

        //basic method
        bool IsLeft() const { return this == p->l; }
        void Rotate() {
            if (IsLeft()) {
                if (r) r->p = p;
                p->l = r; r = p;
            }
            else {
                if (l) l->p = p;
                p->r = l; l = p;
            }
            if (p->p) (p->IsLeft() ? p->p->l : p->p->r) = this;
            auto t = p; p = t->p; t->p = this;
            t->Update(); Update();
        }
        void Update() {
            sz = 1; sum = mn = mx = v;
            if (l) {
                sz += l->sz, sum += l->sum;
                mn = min(mn, l->mn), mx = max(mx, l->mx);
            }
            if (r) {
                sz += r->sz, sum += r->sum;
                mn = min(mn, r->mn), mx = max(mx, r->mx);
            }
        }
        void Update(int val) {
            v = val; Update();
        }
        void Push() {
            if (flip) {
                swap(l, r);
                if (l) l->flip ^= 1;
                if (r) r->flip ^= 1;
                flip = 0;
            }
        }
    };

    //member variable
    Node* root;
    Node* ptr[303030]; //node pointer

    //constructor, destructor
    SplayTree() : root() { memset(ptr, 0, sizeof ptr); }
    ~SplayTree() { if (root) delete root; }
    
    //basic method
    void Splay(Node* x, Node *p = nullptr) {
        for (; x->p != p; x->Rotate()) {
            if (x->p->p != p) x->p->p->Push();
            x->p->Push(); x->Push();
            if (x->p->p == p) continue;
            if (x->IsLeft() == x->p->IsLeft()) x->p->Rotate();
            else x->Rotate();
        }
        x->Push();
        if (!p) root = x;
    }
    void Kth(int k) {
        auto cur = root; cur->Push();
        while (1) {
            while (cur->l && cur->l->sz > k) {
                cur = cur->l; cur->Push();
            }
            if (cur->l) k -= cur->l->sz;
            if (!k--) break;
            cur = cur->r; cur->Push();
        }
        Splay(cur);
    }
    Node* Gather(int l, int r) {
        Kth(r + 1); auto t = root;
        Kth(l - 1); Splay(t, root);
        return root->r->l;
    }

    //additional method
    void Init(int n) {
        if (root) delete root;
        root = new Node(-INF);       //left dummy node
        auto cur = root;
        for (int i = 1; i <= n; i++) {
            ptr[i] = cur->r = new Node(i, cur);
            cur = cur->r;
        }
        cur->r = new Node(INF, cur); //right dummy node
        for (int i = n; i >= 1; i--) ptr[i]->Update();
        Splay(ptr[n / 2]);
    }
    void Print(Node* x) {
        x->Push();
        if (x->l) Print(x->l);
        if (abs(x->v) != INF) cout << x->v << ' ';
        if (x->r) Print(x->r);
    }
    void Flip(int l, int r) {
        auto t = Gather(l, r);
        t->flip ^= 1;
    }
    void Shift(int l, int r, int k) {
        Gather(l, r);
		k %= r - l + 1;
        if (k < 0) k += r - l + 1;
        if (k) Flip(l, r), Flip(l, l + k - 1), Flip(l + k, r);
    }
    void GetIdx(int k) { Splay(ptr[k]); }
	int GetSum(int l,int r){
		auto t = Gather(l, r);
		return t->sum;
	}
	int GetMin(int l,int r){
		auto t = Gather(l, r);
		return t->mn;
	}
	int GetMax(int l,int r){
		auto t = Gather(l, r);
		return t->mx;
	}
};

SplayTree<int> ST;

void Main(){
	int t; ri(t); while(t--){
		int n; ri(n); ordered_set<int> S;
		for(int i = 1; i <= n; i++) S.insert(i);
		vi v(n),ret; ri(v); for(int i = n - 1; i >= 0; i--){
			auto s = v[i];
			auto it = S.find_by_order(s);
			ret.push_back(*it);
			S.erase(it);
		}
		while(!ret.empty()){
			cout << ret.back() << " ";
			ret.pop_back();
		}
		cout << "\n";
	}
}

int32_t main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
	return 0;
}
