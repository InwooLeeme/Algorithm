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

using vi = vector<int>;
using vvi = vector<vi>;

const int PRECISION = 0;

int n,m;
bool Bound(int x, int y){ return x < 0 or x >= n or y < 0 or y >= m;}
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

vvi Melting(vvi& v){
	vvi ret(n, vi(m));
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
		if(!v[i][j]) continue;
		int cnt = 0;
		for(int d = 0; d < 4; d++){
			auto nx = i + dx[d], ny = j + dy[d];
			if(Bound(nx, ny)) continue;
			cnt += (!v[nx][ny]);
		}
		ret[i][j] = v[i][j] - cnt;
		if(ret[i][j] < 0) ret[i][j] = 0;
	}
	return ret;
}

void DFS(vvi& vist, vvi& v, int x, int y){
	vist[x][y] = 1;
	for(int d = 0; d < 4; d++){
		auto nx = x + dx[d], ny = y + dy[d];
		if(Bound(nx, ny) or vist[nx][ny] or !v[nx][ny]) continue;
		DFS(vist, v, nx, ny);
	}
}

void Print(vvi & board){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) cout << board[i][j] << " ";
		cout << "\n";
	}
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    cin >> n >> m;
    vvi board(n, vi(m)); 
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> board[i][j];
	for(int ret = 0; ; ret++){
		int components = 0;
		board = Melting(board);
		vvi vist(n + 1, vi(m + 1));
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
			if(board[i][j] and !vist[i][j]){
				components++;
				DFS(vist, board, i, j);
			}
		}
		if(!components){
			cout << 0 << "\n"; return 0;
		}
		if(components >= 2){
			cout << ret + 1 << "\n";
			return 0;
		}
	}
    return 0;
}
