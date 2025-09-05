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

const int PRECISION = 0;


void Main(){
    int n; cin >> n;
	vector<vector<int>> G(n + 1);
	vector<pair<int, int>> v(n); for(auto& [a, b] : v) cin >> a >> b;
	int cnt = 0;
	map<int, int> M, Rev;
	for(int i = 0; i < n; i++){
		auto [a, b] = v[i];
		int x = a + b;
		int y = a - b;
		int z = a * b;
		if(!M.count(x)) M[x] = cnt++;
		Rev[M[x]] = x;
		G[i].push_back(M[x]);
		if(!M.count(y)) M[y] = cnt++;
		Rev[M[y]] = y;
		G[i].push_back(M[y]);
		if(!M.count(z)) M[z] = cnt++;
		Rev[M[z]] = z;
		G[i].push_back(M[z]);
	}
	vector<int> l(n + 1, -1), r(cnt + 1, -1);
	vector<int> match(cnt + 1);
	auto DFS = [&](int cur, auto&& DFS) -> int{
		for(const auto& nxt : G[cur]){
			if(match[nxt]) continue;
			match[nxt] = 1;
			if(r[nxt] == -1 or DFS(r[nxt], DFS)){
				r[nxt] = cur; l[cur] = nxt;
				return 1;
			}
		}
		return 0;
	};
	int ret = 0;
	for(int i = 0; i < n; i++){
		fill(match.begin(), match.end(), 0);
		ret += DFS(i, DFS);
	}
	if(ret != n){
		cout << "impossible" << "\n";
		return;
	}
	for(int i = 0; i < n; i++){
		auto [a, b] = v[i];
		int x = Rev[l[i]];
		cout << a << " ";
		if(a + b == x) cout << "+ ";
		else if(a - b == x) cout << "- ";
		else if(a * b == x) cout << "* ";
		cout << b << " = " << x << "\n";
	}
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
