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

int n;
constexpr int INF = int(2e18);
using vvi = vector<vector<int>>;

void Main(){
    cin >> n;
    vvi c(n, vector<int>(n));
    for(auto& i : c) for(auto& j : i) cin >> j;
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
            if(j == k or i == j) continue;
            if(c[i][j] > c[i][k] + c[k][j]){
                cout << -1 << "\n";
                return;
            }
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++){
        bool flag = 0;
        for(int k = 0; k < n; k++){
            if(i == k or k == j) continue;
            if(c[i][j] == c[i][k] + c[k][j]){
                flag = 1;
                break;
            }
        }
        res += flag;
    }
    cout << res << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
