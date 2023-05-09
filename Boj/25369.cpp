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

int n,a = 1;
set<vector<int>> S;
vector<int> v;

void f(int dep){
    if(dep == n){
        int b = 1;
        for(auto& c : v) b *= c;
        if(b > a){
            for(auto& c : v) cout << c << ' ';
            exit(0);
        }
        return;
    }
    for(int i = 1; i <= 9; i++){
        v.push_back(i);
        f(dep + 1);
        v.pop_back();
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 0,t; i < n; i++) cin >> t, a *= t;
    f(0);
    if(S.empty()){
        cout << -1 << "\n";
        return 0;
    }
    for(auto& c : *S.begin()) cout << c << " ";
    return 0;
}