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

using vi = vector<int>;

struct Shark{
    int x = -1,y = -1, d = -1, p[4][4]{};
    int GetDir(const vector<int>& v) const {
        return *min_element(v.begin(), v.end(), [&](int a, int b){
            return p[d][a] < p[d][b];
        });
    }
};

struct Smell{ int idx = -1, t = -1; };

struct Board{
    int n,m,k;
    int board[20][20];
    Shark shark[444];
    Smell s[20][20];

    void Input(){
        cin >> n >> m >> k;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j]) {
				shark[board[i][j]].x = i;
				shark[board[i][j]].y = j;
			}
		}
		for (int cur = 1; cur <= m; cur++) {
			int d; cin >> d; --d;
			shark[cur].d = "1320"[d] - '0';
		}
		for (int cur = 1; cur <= m; cur++) {
			for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
				int d; cin >> d; --d;
				shark[cur].p["1320"[i] - '0']["1320"[d] - '0'] = j;
			}
		}
    }

    bool Bound(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

    void Move(int t){
        int nv[20][20]{};
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
            if(!board[i][j]) continue;
            const auto idx = board[i][j]; vector<int> v;
            for(int d = 0; d < 4; d++){
                auto nx = i + "1012"[d] - '1';
                auto ny = j + "2101"[d] - '1';
                if(Bound(nx, ny)) continue;
                if(s[nx][ny].idx == -1 || s[nx][ny].t < t - k) v.push_back(d);
            }
            if(v.empty()) for(int d = 0; d < 4; d++){
                auto nx = i + "1012"[d] - '1';
                auto ny = j + "2101"[d] - '1';
                if(!Bound(nx, ny) and s[nx][ny].idx == idx) v.push_back(d);
            }
            const int nd = shark[idx].GetDir(v);
            const int nx = i + "1012"[nd] - '1';
            const int ny = j + "2101"[nd] - '1';
            shark[idx].x = nx, shark[idx].y = ny, shark[idx].d = nd;
            if(nv[nx][ny] == 0 || nv[nx][ny] > idx) nv[nx][ny] = idx;
        }
        memcpy(board, nv ,sizeof board);
    }

    void SetSmell(int t){
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
            if(board[i][j]) s[i][j] = {board[i][j], t};
        }
    }

    int Cnt(){
        int ret = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(board[i][j]) ret++;
        return ret;
    }

    int Sol(){
        for(int ret = 1; ret <= 1000; ret++){
            SetSmell(ret - 1), Move(ret);
            if(Cnt() == 1) return ret;
        }
        return -1;
    }
};

int32_t main(){
    fastio;
    Board B;
    B.Input();
    cout << B.Sol() << "\n";
    return 0;
}