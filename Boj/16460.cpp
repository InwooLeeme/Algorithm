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

struct Info{
    string x,ty;
    int di;
};

int32_t main(){
    fastio;
    Info S; cin >> S.x >> S.ty >> S.di; 
    sort(S.ty.begin(), S.ty.end());
    int n; cin >> n; cin.ignore();
    vector<string> ret;
    for(int i = 0; i < n; i++){
        string a,b;
        int dist; cin >> a >> b >> dist;
        sort(b.begin(), b.end());
        if(S.ty.find(b) != -1 and dist <= S.di) ret.push_back(a);
    }
    sort(ret.begin(), ret.end());
    if(!ret.size()) cout << "No one yet" << "\n";
    else for(auto& i : ret) cout << i << "\n";
    return 0;
}