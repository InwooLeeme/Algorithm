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

using pii = pair<int, int>;
using tii = tuple<int, int, int>;

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
		if (a == b) return 0;
		if (rank[a] < rank[b]) swap(a, b);
		par[b] = a;
		rank[a] += rank[a] == rank[b];
		cnt[a] += cnt[b];
		return 1;
	}
};

struct Game{
    private:
        int n,m;
        int board[11][11];
    public:
        const int dx[4] = {-1 ,0, 1, 0};
        const int dy[4] = {0, 1, 0, -1};

        bool OOB(int x,int y){return x < 0 || x >= n || y < 0 || y >= m; }

        void Init(){
            cin >> n >> m;
            for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> board[i][j];
        }

        int Indexing(){
            int cnt = 0;
            bool vist[11][11];
            memset(vist, 0, sizeof vist);
            for(int i = 0 ; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(board[i][j] and !vist[i][j]){
                        queue<pii> Q;
                        vist[i][j] = 1;
                        board[i][j] = ++cnt;
                        Q.push({i, j});
                        while(!Q.empty()){
                            auto [x, y] = Q.front(); Q.pop();
                            for(int d = 0; d < 4; d++){
                                auto nx = x + dx[d];
                                auto ny = y + dy[d];
                                if(OOB(nx, ny) || vist[nx][ny] || !board[nx][ny]) continue;
                                vist[nx][ny] = 1;
                                board[nx][ny] = cnt;
                                Q.push({nx, ny});
                            }
                        }
                    }
                }
            }
            return cnt;
        }


        vector<tii> AddEdge(){
            vector<tii> e;
            for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
                int cnt = 0;
                if(!board[i][j]) continue;
                for(int d = 0; d < 4; d++){
                    auto nx = i + dx[d],ny = j + dy[d];
                    if(OOB(nx, ny)) continue;
                    cnt += !board[nx][ny];
                }
                // Get Dist
                if(cnt >= 1){
                    for(int d = 0; d < 4; d++){
                        int x = i,y = j;
                        int ddx = dx[d],ddy = dy[d];
                        while(!OOB(x + ddx, y + ddy) and board[x + ddx][y + ddy] == 0) x += ddx,y += ddy;
                        x += ddx,y += ddy;
                        if(OOB(x, y)) continue;
                        auto dist = abs(x - i) + abs(y - j) - 1;
                        if(dist < 2) continue;
                        e.push_back({dist, board[i][j], board[x][y]});
                    }
                }
            }
            return e;
        }

        void Print(){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << board[i][j] << ' ';
                }
                cout << "\n";
            }
        }
        int Sol(){
            int ret = 0,cnt = 0;
            auto s = Indexing();
            vector<tii> e = AddEdge();
            UnionFind UF(s + 1);
            sort(e.begin(), e.end());
            for(auto& [c, a, b] : e){
                if(UF.Union(a, b)){
                    ret += c;
                    if(++cnt == s - 1) break;
                }
            }
            return (cnt != s - 1 ? -1 : ret);
        }
} G;

int32_t main(){
    fastio;
    G.Init();
    cout << G.Sol() << "\n";
    return 0;
}