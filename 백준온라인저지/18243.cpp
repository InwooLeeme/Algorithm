#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define sz(v) (int)(v).size()
#define all(v) v.begin(), v.end()
#define rall(v) (v).rbegin(), (v).rend()
#define compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)
#define debug(x) cout << (#x) << ": " << (x) << '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ldb = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vs = vector<string>;
using tii = tuple<int,int,int>;
template<typename T> using wector = vector<vector<T>>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const ll LNF = 1e18 + 7;

int n,k,dist[101][101];

int main() {
	fastio;
  cin >> n >> k;
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= n; j++){
      dist[i][j] = INF;
    }
  }
  for(int i = 0; i < k; i++){
    int a,b; cin >> a >> b;
    dist[a][b] = 1;
    dist[b][a] = 1;
  }
  for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++){
    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
  }
  bool flag = true;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(dist[i][j] > 6){
        flag = false;
        break;
      }
    }
  }
  cout << (flag ? "Small World!" : "Big World!") << "\n";
	return 0;
}