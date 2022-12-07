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

#define int int64_t

int n,m;
int arr[11];
vector<int> v;
set<int> S;
bool chk[11];

int IsPrime(int x){
    if(x <= 1) return 0;
    for(int i = 2; i * i <= x; i++) if(x % i == 0) return 0;
    return 1;
}

void F(int depth){
    if(depth == m){
        int sum = accumulate(v.begin(), v.end(), 0);
        if(IsPrime(sum)) S.insert(sum);
        return;
    }
    for(int i = 0; i < n; i++){
        if(chk[i]) continue;
        chk[i] = 1;
        v.push_back(arr[i]);
        F(depth + 1);
        v.pop_back();
        chk[i] = 0;
    }
}

int32_t main(){
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    F(0);
    if(!S.size()) cout << -1 << "\n";
    else for(auto& i : S) cout << i << ' ';    
    return 0;
}