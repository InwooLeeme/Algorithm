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

int32_t main(){
    fastio;
    int cnt = 0,N; cin >> N;
    set<int> S;
    while(!S.count(N)){
        S.insert(N);
        N = ((N % 1000) - (N % 10)) / 10;
        N = N * N;
        //cout << N << "\n";
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}