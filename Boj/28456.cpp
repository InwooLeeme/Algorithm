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
    using vi = vector<int>; using vvi = vector<vi>;
    int n,q; cin >> n;
    vvi v(n, vi(n)); for(auto& i : v) for(auto& j : i) cin >> j;
    auto Rotate = [&](vvi& board) -> vvi{
        vvi ret(n, vi(n));
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) ret[i][j] = board[n - 1 - j][i];
        return ret;
    };
    cin >> q;
    while(q--){
        int t,i; cin >> t;
        if(t == 1) {
            cin >> i; --i;
            rotate(v[i].begin(), v[i].end() - 1, v[i].end());
        }
        else v = Rotate(v);
    }
    for(auto& i : v){
        for(auto& j : i) cout << j << " ";
        cout << "\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}