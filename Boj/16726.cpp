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

int n,m;
string board[55];
bool Bound(int x, int y) { return x < 0 or x >= n or y < 0 or y >= m; }
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
vector<int> g[2551];
vector<bool> match(2551);
vector<int> par(2551, -1);

int DFS(int cur){
	for(auto nxt : g[cur]){
		if(match[nxt]) continue;
		match[nxt] = 1;
		if(par[nxt] == -1 or DFS(par[nxt])){
			par[nxt] = cur;
			return 1;
		}
	}
	return 0;
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int block = 0;
    for(int i = 0; i < n; i++){
        cin >> board[i];
        for(auto& j : board[i]) if(j == '.') block++;
    }
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        if(board[i][j] == 'X') continue;
        if(i + j & 1){
            for(int d = 0; d < 4; d++){
                auto nx = i + dx[d], ny = j + dy[d];
                if(Bound(nx, ny) or board[nx][ny] == 'X') continue;
                g[i * m + j].push_back(nx * m + ny);
            }
        }
    }
    int ret = 0;
    for(int i = 0; i < 2551; i++){
        fill(match.begin(), match.end(), 0);
        ret += DFS(i);
    }
    cout << block - ret << "\n";
    return 0;
}