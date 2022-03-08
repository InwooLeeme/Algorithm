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

int32_t main(){
	fastio;
	crope R[50001];
	int ver = 0; // version
	int cnt = 0; // count of char 'c'
	int t; // testcase
	cin >> t; t--;
	int cmd,p;
	char S[104]; cin >> cmd >> p >> S;
	R[++ver].insert(0, S);
	while(t--){
		int cmd; cin >> cmd;
		if(cmd == 1){
			char s[101]; 
			int p; cin >> p >> s;
			R[ver + 1] = R[ver];
			ver++;
			R[ver].insert(p - cnt, s);
		}
		else if(cmd == 2){
			int p,C; cin >> p >> C;
			R[ver + 1] = R[ver];
			ver++;
			R[ver].erase(p - cnt - 1, C - cnt);
		}
		else{ // 3
			int v,p,C; cin >> v >> p >> C;
			auto temp = R[v - cnt].substr(p - cnt - 1, C - cnt);
			cnt += count(all(temp),'c');
			cout << temp << "\n";
		}
	}
}