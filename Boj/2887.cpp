// 2887번 : 행성 터널 

#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define MAX 1005
#define INF 1e9+7
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ldb = long double; 
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdbl = pair<double, double>;
using vi = vector<int>;
using tiii = tuple<int,int,int>;
#define sz(a) int((a).size())

struct UnionFind {
	vector<int> parent, rank, cnt;
	UnionFind(int n) : parent(n), rank(n, 1), cnt(n, 1) {
		iota(parent.begin(), parent.end(), 0);
	}
	int Find(int x) {
		return x == parent[x] ? x : parent[x] = Find(parent[x]);
	}
	bool Union(int a, int b) {
		a = Find(a), b = Find(b);
		if (a == b) return 0;
		if (rank[a] < rank[b]) swap(a, b);
		parent[b] = a;
		rank[a] += rank[a] == rank[b];
		cnt[a] += cnt[b];
		return 1;
	}
};

struct Edge{
  int u,v,w;
  Edge(int u1,int v1,int w1):u(u1),v(v1),w(w1){}
  bool operator < (const Edge& O) const{ return w < O.w;}
};

struct Point3d{
  int x; int y; int z; int idx;
};

int find_dist(Point3d a, Point3d b,int c){
  if(c == 1) return abs(a.x - b.x);
  else if(c == 2) return abs(a.y - b.y);
  return abs(a.z - b.z);
}

bool cmpX(Point3d a, Point3d b){
  return a.x < b.x;
}

bool cmpY(Point3d a, Point3d b){
  return a.y < b.y;
}

bool cmpZ(Point3d a, Point3d b){
  return a.z < b.z;
}

int32_t main(){
  fastio;
  int n,sum = 0,cnt = 0; cin >> n;
  vector<Edge> e;
  vector<Point3d> coord(n);
  for(int i = 0; i < n; i++){
    cin >> coord[i].x >> coord[i].y >> coord[i].z; 
    coord[i].idx = i;
  }
  // x기준 간선
  sort(coord.begin(), coord.end(), cmpX);
  for(int i = 0; i < n - 1; i++){
    int c = find_dist(coord[i], coord[i + 1],1);
    e.pb(Edge(coord[i].idx,coord[i + 1].idx, c));
  }
  // y기준 간선
  sort(coord.begin(), coord.end(), cmpY);
  for(int i = 0; i < n - 1; i++){
    int c = find_dist(coord[i], coord[i + 1],2);
    e.pb(Edge(coord[i].idx,coord[i + 1].idx, c));
  }
  // z기준 간선
  sort(coord.begin(), coord.end(), cmpZ);
  for(int i = 0; i < n - 1; i++){
    int c = find_dist(coord[i], coord[i + 1],3);
    e.pb(Edge(coord[i].idx,coord[i + 1].idx, c));
  }
  sort(e.begin(), e.end());
  UnionFind UF(n+1);
  for(int i = 0; ; i++){
    if(UF.Union(e[i].u, e[i].v)){
      sum += e[i].w;
      if(++cnt == n - 1) break;
    }
  }
  cout << sum << "\n";
  return 0;
}
