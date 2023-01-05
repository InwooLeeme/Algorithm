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
    int n,k; cin >> n >> k; cin.ignore(); n *= 3;
    map<string, int> M,idx;
    vector<string> v;
    for(int i = 0; i < n; i++){
        string str; getline(cin, str);
        if(!M.count(str)) v.push_back(str);
        M[str]++;
        idx[str] = i;
    }
    sort(v.begin(), v.end(), [&](const string& a, const string& b){
        if(M[a] == M[b]) return idx[a] > idx[b];
        return M[a] > M[b];
    });
    for(int i = 0; i < min<int>(v.size(), k); i++) cout << v[i] << "\n";
    return 0;
}