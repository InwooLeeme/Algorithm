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
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;


int n,m,r,v[300][300];

void rotate2D(int x1,int y1,int x2, int y2){
  int temp = v[x1][y1];
  // <-
  for(int j = y1; j < y2; j++) v[x1][j] = v[x1][j + 1];
    // up
  for(int i = x1; i < x2; i++) v[i][y2] = v[i + 1][y2];
  // ->
  for(int j = y2; j > y1; j--) v[x2][j] = v[x2][j - 1];
  // down
  for(int i = x2; i > x1; i--) v[i][y1] = v[i - 1][y1];
  v[x1 + 1][y1] = temp;
}

void Rotate(int r){
  int x1 = 0,x2 = n - 1,y1 = 0,y2 = m - 1;
  for(;x1 < x2 && y1 < y2; x1++,y1++,x2--,y2--){
  	for(int i = r % ((x2 - x1 + y2 - y1) * 2); i--;)
  		rotate2D(x1, y1, x2, y2);
  } 
}

int32_t main(){
  fastio; 
  cin >> n >> m >> r;
  for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> v[i][j];
  Rotate(r);
  for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << v[i][j] << ' ';
		cout << '\n';
	}
}