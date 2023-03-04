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

int in[1111],pre[1111];

void DFS(int rootIdx, int st, int en){
    for(int i = st; i < en; i++){
        if(in[i] == pre[rootIdx]){ // 현재 루트 잡고
            DFS(rootIdx + 1, st, i); // 왼쪽
            DFS(rootIdx + 1 + i - st, i + 1, en); // 오른쪽
            cout << pre[rootIdx] << ' ';
        }
    }
}

void test_case(){   
    int n; cin >> n;
    memset(pre, 0, sizeof pre);
    memset(in, 0, sizeof in);
    for(int i = 0; i < n; i++) cin >> pre[i];
    for(int i = 0; i < n; i++) cin >> in[i];
    DFS(0, 0, n);
    cout << "\n";
}

int32_t main(){
    fastio;
    int T; cin >> T;
    while(T--) test_case();
    return 0;
}