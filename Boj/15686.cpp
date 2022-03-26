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

int board[51][51];
const int INF = 1e9 + 7;

int getDist(pii a, pii b){
	return abs(a.X - b.X) + abs(a.Y - b.Y);
}

int32_t main(){
	fastio;
	int n,m; cin >> n >> m;
	vector<pii> house,chicken;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> board[i][j];
			if(board[i][j] == 1) house.push_back({i, j});
			if(board[i][j] == 2) chicken.push_back({i, j});
		}
	}
	vector<int> brute(chicken.size(), 1);
	fill(brute.begin(), brute.begin() + chicken.size() - m, 0);
	int mn = INF;
	// get Combi
	do{
		int dist = 0;
		for(const auto& h : house){
			int temp = INF;
			for(int i = 0; i < chicken.size(); i++){
				if(brute[i]) temp = min(temp, getDist(h, chicken[i]));
			}
			dist += temp;
		}
		mn = min(mn, dist);
	} while(next_permutation(all(brute)));
	cout << mn << "\n";
}