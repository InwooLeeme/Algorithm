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
using vi = vector<int>;
using vvi = vector<vector<int>>;
struct Info{ int x,y,d; };
int n;
int board[22][22];
int x,y; // 아기 상어의 위치

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

bool OOB(int x,int y){ return x < 0 || x >= n || y < 0 || y >= n; }

// 각 칸마다 거리를 구해주는 함수
vvi BFS(int stx, int sty, int sz){
    queue<pii> Q;
    vvi dist(n, vi(n, -1));
    Q.push({stx, sty});
    dist[stx][sty] = 0;
    while(!Q.empty()){
        auto [x, y] = Q.front(); Q.pop();
        for(int d = 0; d < 4; d++){
            auto nx = x + dx[d],ny = y + dy[d];
            if(OOB(nx, ny) || dist[nx][ny] != -1) continue;
            if(board[nx][ny] > sz) continue;
            dist[nx][ny] = dist[x][y] + 1;
            Q.push({nx, ny});
        }
    }
    return dist;
}

// 먹을 수 있는 물고기를 구하는 함수
pii GetPos(vvi dist, int sz){
    vector<Info> v;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
        if((board[i][j] > 0 and board[i][j] < sz) and dist[i][j] != -1){
            v.push_back({i, j, dist[i][j]});
        }
    }
    if(v.empty()) return {-1, -1};
    auto ret = *min_element(v.begin(), v.end(), [&](Info& a, Info& b){
        if (a.d != b.d) return a.d < b.d;
		if (a.x != b.x) return a.x < b.x;
		return a.y < b.y;
    });
    return {ret.x, ret.y};
}

void Input(){
    cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
        cin >> board[i][j];
        if(board[i][j] == 9){
            x = i,y = j;
            board[i][j] = 0;
        }
    }
}

int Sol(){
    int ret = 0, babySharksize = 2,cnt = 0; // 아기 상어 크기
    while(1){
        auto dist = BFS(x, y, babySharksize);
        auto [nx, ny] = GetPos(dist, babySharksize);
        if(nx == -1) break;
        board[nx][ny] = 0, ret += dist[nx][ny],cnt++,x = nx,y = ny;
        if(cnt == babySharksize) babySharksize++,cnt = 0;
    }
    return ret;
}

int32_t main(){
    fastio;
    Input();
    cout << Sol() << "\n";
    return 0;
}