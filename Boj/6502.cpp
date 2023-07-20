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

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,m,r,tc = 1;
    while(cin >> r >> n >> m and r){
        const int PI = acos(-1);
        cout << "Pizza " << tc << " ";
        cout << (2*r >= sqrt(n*n + m*m) ? "fits on the table." : "does not fit on the table.") << '\n';
        tc++;
    }
    return 0;
}