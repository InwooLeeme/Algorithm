#pragma GCC target("avx,avx2,fma")
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

int n,m,q;
vector<string> v;
map<string, int> M;
string s;

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};

void DFS(int dep, int x, int y){
	if(s[dep] != v[x][y]) return;
	if(dep + 1 == s.size()){
		M[s]++;
		return;
	}
	for(int d = 0; d < 8; d++){
		auto nx = x + dx[d], ny = y + dy[d];
		nx += n, nx %= n, ny += m, ny %= m;
		DFS(dep + 1, nx, ny);
	}
}

void Main(){
	cin >> n >> m >> q;
	v.resize(n); for(auto& i : v) cin >> i;
	while(q--){
		cin >> s;
		if(M.count(s)){ cout << M[s] << "\n"; continue;	}
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) DFS(0, i, j);
		cout << M[s] << "\n";
	}
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
