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
vector<int> G[10101];
int D[10101];

int F(int cur){
    if(cur == n) return 1;
    int& ret = D[cur];
    if(ret != -1) return ret;
    ret = 0;
    for(auto nxt : G[cur]){
        ret += F(nxt);
    }
    return ret;
}

void Sol(){
    cin >> n;
    memset(D, -1, sizeof D);
    int a,b;
    while(cin >> a >> b and a) {G[a].push_back(b);}
    cout << F(1) << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Sol();
    return 0;
}