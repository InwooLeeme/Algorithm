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

int v[11][11],vist[11];
int mx = -int(1e9), n,k;
vector<int> S;

void f(int dep){
    if(dep == k){
        int sum = 0;
        for(int i = 0; i < S.size(); i++) for(int j = i + 1; j < S.size(); j++) sum += v[S[i]][S[j]];
        mx = max<int>(mx, sum);
        return;
    }
    for(int i = 0; i < n; i++){
        if(vist[i]) continue;
        vist[i] = 1;
        S.push_back(i);
        f(dep + 1);
        S.pop_back();
        vist[i] = 0;
    }
}

void Main(){
    cin >> n >> k;
    if(k == 1){
        cout << 0 << "\n";
        return;
    }
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> v[i][j];
    f(0);
    cout << mx << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}