#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define int int_fast64_t

using pii = pair<int, int>;
using vvi = vector<vector<int>>;

struct UnionFind { // union-by-rank ver.
	vector<int> par, rank, cnt;
	UnionFind(int n) : par(n), rank(n, 1), cnt(n, 1) {
		iota(par.begin(), par.end(), 0);
	}
	int Find(int x) {
		return x == par[x] ? x : par[x] = Find(par[x]);
	}
	bool Union(int a, int b) {
		a = Find(a), b = Find(b);
		if (a == b) return 1;
		if (rank[a] < rank[b]) swap(a, b);
		par[b] = a;
		rank[a] += rank[a] == rank[b];
		cnt[a] += cnt[b];
		return 0;
	}
};

int n,m;
int board[2222][2222];
queue<pii> Q1,Q2;

bool OOB(int x,int y) { return x < 0 || x >= n || y < 0 || y >= n; }
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};

// BFS를 이용해서 문명을 합쳐주는 함수
void BFS_Union(UnionFind& UF){
    while(!Q1.empty()){
        auto [x,y] = Q1.front(); 
        Q2.push({x, y});
        Q1.pop();
        for(int d = 0; d < 4; d++){
            auto nx = x + dx[d],ny = y + dy[d];
            if(OOB(nx, ny) || !board[nx][ny]) continue;
            if(board[nx][ny] and board[nx][ny] != board[x][y]){
                if(UF.Union(board[x][y], board[nx][ny])) continue;
                m--;
            }
        }
    }
}

// BFS를 이용해서 문명을 전파하는 함수
void BFS_Pro(UnionFind& UF){
    while(!Q2.empty()){
        auto [x, y] = Q2.front(); Q2.pop();
        for(int d = 0; d < 4; d++){
            auto nx = x + dx[d],ny = y + dy[d];
            if(OOB(nx, ny)) continue;
            if(!board[nx][ny]){
                board[nx][ny] = board[x][y]; Q1.push({nx, ny});
            }
            else if(board[nx][ny] and board[nx][ny] != board[x][y]){
                if(UF.Union(board[x][y], board[nx][ny])) continue;
                m--;
            }
        }
    }
}

int32_t main(){
    fastio;
    cin >> n >> m;
    UnionFind UF(m + 1);
    for(int i = 1; i <= m; i++){
        int a,b; cin >> a >> b; --a,--b;
        board[a][b] = i;
        Q1.push({a, b});
    }
    int ret = 0;
    while(1){
        BFS_Union(UF);
        if(m == 1){
            cout << ret << "\n";
            return 0;
        }
        BFS_Pro(UF);
        ret++;
    }
    return 0;
}