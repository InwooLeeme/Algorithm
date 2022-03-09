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

// x^n O(logN)
int _pow(int x,int n){
  int ret = 1;
  while(n){
    if(n & 1) ret *= x;
    n >>= 1;
    x *= x;
  }
  return ret;
}

int32_t main(){
	fastio;
	const int sz = 100;
	int a = _pow(sz * (sz + 1) / 2, 2);
	int b = 100 * 101 * 201 / 6;
	cout << a - b << "\n";
}