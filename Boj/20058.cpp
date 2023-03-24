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
using vvi = vector<vi>;

struct WizardShark{
    int n,q,sz;
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};
    vvi board, vist;
    vi L;
    WizardShark(int n, int q):n(n),q(q),sz(1 << n),board(sz, vi(sz)),vist(sz, vi(sz, 0)), L(q){
        Init();
    }

    void Init(){
        for(int i = 0; i < sz; i++) for(int j = 0; j < sz; j++) cin >> board[i][j];
        for(auto& i : L) cin >> i;
    }

    bool Bound(int x, int y) { return x < 0 || x >= sz || y < 0 || y >= sz; }

    int DFS(int x, int y){
        int ret = 1;
        vist[x][y] = 1;
        for(int d = 0; d < 4; d++){
            auto nx = x + dx[d], ny = y + dy[d];
            if(Bound(nx, ny) || !board[nx][ny] || vist[nx][ny]) continue;
            ret += DFS(nx, ny);
        }
        return ret;
    }

    void MeltICE(){
        vvi temp(sz, vi(sz, 0));
        for(int i = 0; i < sz; i++) for(int j = 0; j < sz; j++) temp[i][j] = board[i][j];
        for(int i = 0; i < sz; i++) for(int j = 0; j < sz; j++){
            if(!board[i][j]) continue;
            int cnt = 0;
            for(int d = 0; d < 4; d++){
                auto nx = i + dx[d];
                auto ny = j + dy[d];
                if(Bound(nx, ny) || !board[nx][ny]) continue;
                cnt++;
            }
            if(cnt >= 3) continue;
            temp[i][j]--;
        }
        for(int i = 0; i < sz; i++) for(int j = 0; j < sz; j++) board[i][j] = temp[i][j];
    }

    void Rotate(int x, int y, int k){
        vvi temp(k, vi(k)), v(k, vi(k));
        for(int i = 0; i < k; i++) for(int j = 0; j < k; j++) v[i][j] = board[i + x][j + y];
        for(int i = 0; i < k; i++) for(int j = 0; j < k; j++) temp[j][i] = v[k - i - 1][j];
        for(int i = 0; i < k; i++) for(int j = 0; j < k; j++) board[i + x][j + y] = temp[i][j];
    }

    void FireStorm(int x){
        const int n = (1 << x);
        for(int x = 0; x < sz; x += n) for(int y = 0; y < sz; y += n){
            Rotate(x, y, n);
        }
    }

    int GetCnt(){
        int ret = 0;
        for(int i = 0; i < sz; i++) for(int j = 0; j < sz; j++) ret += board[i][j];
        return ret;
    }

    int GetMaxIsland(){
        int ret = 0;
        for(int i = 0; i < sz; i++) for(int j = 0; j < sz; j++){
            if(!vist[i][j] and board[i][j]) ret = max<int>(ret, DFS(i, j));
        }
        return ret;
    }

    void Sol(){
        for(auto& l : L){
            FireStorm(l);
            MeltICE();
        }
        cout << GetCnt() << "\n" << GetMaxIsland() << "\n";
    }

    void PrintBoard(){
        for(int i = 0; i < sz; i++){
            for(int j = 0; j < sz; j++) cout << board[i][j] << " ";
            cout << "\n";
        }
    }
};

int32_t main(){
    fastio;
    int n,q; cin >> n >> q;
    WizardShark WS(n, q);
    WS.Sol();
    return 0;
}