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
    constexpr int INF = int(2e9);
    // Input
    int n; cin >> n;
    vector<int> score(n + 1); for(int i = 1; i <= n; i++) cin >> score[i];
    vector<int> G[n + 1];
    for(int i = 1; i <= n; i++){
        int t; cin >> t;
        while(t--){
            int x; cin >> x;
            G[i].push_back(x);
        }
    }
    // Get Score
    auto GetScore = [&](set<int>& S) -> int{
        int ret = 0; for(auto& i : S) ret += score[i];
        return ret;
    };
    auto MakeBip = [&](set<int>& S) -> bool{
        vector<vector<int>> D(n + 1, vector<int>(n + 1, INF));
        // make Graph
        for(auto& i : S){
            for(auto nxt : G[i]){
                if(!S.count(nxt)) continue;
                D[i][nxt] = 1;
            }
        }
        // floyd
        for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++){
            D[i][j] = min<int>(D[i][j], D[i][k] + D[k][j]);
        }
        for(auto& I : S){
            for(auto& J : S){
                if(I == J) continue;
                if(D[I][J] == INF) return 0;
            }
        }
        return 1;
    };
    int mn = INF;
    for(int i = 1; i < n; i++){
        vector<int> chk,v(n);
        for(int j = 0; j < n; j++) chk.push_back(j < i ? 0 : 1);
        sort(chk.begin(), chk.end());
        iota(v.begin(), v.end(), 1);
        do{
            set<int> l,r;
            for(int i = 0; i < n; i++){
                if(chk[i]) l.insert(v[i]);
                else r.insert(v[i]);
            }
            if(!MakeBip(l) or !MakeBip(r)) continue;
            auto lscore = GetScore(l),rscore = GetScore(r);
            mn = min<int>(mn, abs(lscore - rscore));
        }while(next_permutation(chk.begin(), chk.end()));
    }
    cout << (mn == INF ? -1 : mn) << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}