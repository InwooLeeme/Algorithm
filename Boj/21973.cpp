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

vector<int> p(30303);

int Find(int x){ return x == p[x] ? x : p[x] = Find(p[x]); }
bool Union(int a, int b){
    a = Find(a), b = Find(b);
    if(a == b) return 0;
    p[b] = a;
    return 1;
}

struct LinkCutTree{
    struct Node{
        Node *l, *r, *p;
        int v,sum,sz;
        bool flip;

        Node(int v = 0, Node* p = nullptr):v(v),sum(v),p(p){
            l = r = nullptr; sz = 0; flip = false;
        }

        bool IsRoot() const { return !p || this != p->l && this != p->r; }
        bool IsLeft() const { return this == p->l; }
        void Rotate(){
            if(IsLeft()) r && (r->p = p), p->l = r, r = p;
            else l && (l->p = p), p->r = l, l = p;
            if(!p->IsRoot()) (p->IsLeft() ? p->p->l : p->p->r) = this;
            auto t = p; p = t->p; t->p = this;
            t->Update(); Update();
        }

        void Update(){
            sz = 1; sum = v;
            if(l) sz += l->sz, sum += l->sum;
            if(r) sz += r->sz, sum += r->sum;
        }

        void Push(){
            if(flip){
                swap(l, r);
                if(l) l->flip ^= 1;
                if(r) r->flip ^= 1;
                flip = 0;
            }
        }
    };

    Node ptr[101010];

    void Splay(Node* x){
        for(; !x->IsRoot(); x->Rotate()){
            if(!x->p->IsRoot()) x->p->p->Push(); x->p->Push(); x->Push();
            if(!x->p->IsRoot()) (x->IsLeft() ^ x->p->IsLeft() ? x : x->p)->Rotate();
        }
        x->Push();
    }

    void Access(Node* x){
        Splay(x); x->r = nullptr;
        for(; x->p; Splay(x)) Splay(x->p), x->p->r = x;
    }

    void Link(Node* x, Node* p){ // p의 부모정점을 x로 만들어줌 이때 p는 무조건 트리의 루트여야함
        Access(x); Access(p);
        x->l = p; p->p = x;
        x->Update();
    }

    void Cut(Node* x){
        Access(x); if(!x->l) return;
        x->l = x->l->p = nullptr;
        x->Update();
    }

    Node* GetRoot(Node* x){
        Access(x); for(; x->l; x = x->l, x->Push());
        Access(x); return x;
    }

    Node* GetPar(Node* x){
        Access(x); if(!x->l) return nullptr;
        for(x = x->l, x->Push(); x->r; x = x->r, x->Push());
        Access(x); return x;
    }

    Node* GetLCA(Node* x, Node* y){
        Access(x); Access(y); Splay(x);
        return x->p ? x->p : x;
    }

    int GetDep(Node* x){
        Access(x);
        return x->l ? x->l->sz : 0;
    }

    void MakeRoot(Node* x){
        Access(x); Splay(x);
        x->flip ^= 1;
    }

    void Access(int x) { Access(ptr + x); }
    void Link(int x, int p) { Link(ptr + x, ptr + p); }
    void Cut(int x){ Cut(ptr + x); }
    Node* GetRoot(int x){ return GetRoot(ptr + x); }
    Node* GetPar(int x) { return GetPar(ptr + x); }
    Node* GetLCA(int x, int y){
        //if(GetRoot(x) != GetRoot(y)) return nullptr; // or -1
        return GetLCA(ptr + x, ptr + y);
    }
    int GetDep(int x){ return GetDep(ptr + x); }
    void MakeRoot(int x){ MakeRoot(ptr + x); }

    // for problem
    void VertexUpdate(Node* x, int val){
        Access(x); x->v = val;
        x->Update();
    }

    void VertexUpdate(int x, int val){
        VertexUpdate(ptr + x, val);
    }

    int PathQuery(Node* x, Node* y){
        Node* l = GetLCA(x, y);
        int ret = l->v;
        Access(x); Splay(l);
        if(l->r) ret = ret + l->r->sum;

        Access(y); Splay(l);
        if(l->r) ret = ret + l->r->sum;
        return ret;
    }

    int PathQuery(int a, int b){
        return PathQuery(ptr + a, ptr + b);
    }
} lct;

void Main(){
	iota(p.begin(), p.end(), 0);
    int n,q; ri(n);
    for(int i = 1; i <= n; i++){
        int t; ri(t); lct.VertexUpdate(i, t);
    }
    ri(q);
    while(q--){
        string s; int a,b; ri(s, a, b);
        if(s == "bridge"){
            if(Union(a, b)){
                cout << "yes" << endl;
                lct.MakeRoot(a); lct.MakeRoot(b);
                lct.Link(a, b);
            }
            else cout << "no" << endl;
        }
        else if(s == "penguins"){
            lct.VertexUpdate(a, b);
        }
        else if(s == "excursion"){
            if(Find(a) != Find(b)) cout << "impossible" << endl;
            else cout << lct.PathQuery(a, b) << endl;
        }
    }
}

int32_t main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
	return 0;
}
