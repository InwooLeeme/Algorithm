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

int D[111'111];
int w[111];

void Main(){
    int n,m; cin >> n >> m;
    constexpr int INF = int(1e18);
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 0; i < 111'111; i++) D[i] = INF; // i만큼의 카페인을 마실 수 있을 때 필요한 커피의 최소개수
    D[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= w[i]; j--) D[j] = min<int>(D[j], D[j - w[i]] + 1);
    }
    cout << (D[m] == INF ? -1 : D[m]) << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}