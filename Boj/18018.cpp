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
    string s,sele;
    int n; cin >> s >> n;
    map<char, int> M;
    vector<string> v;
    for(int i = 0; i < n; i++){
        string t; cin >> t;
        v.push_back(t);
        M[t.front()]++;
    }
    for(int i = 0; i < n; i++){
        if(v[i].front() == s.back()){
            --M[v[i].front()];
            if(!M[v[i].back()]){
                cout << v[i] << "!" << "\n";
                return 0;
            }
            ++M[v[i].front()];
        }
    }
    for(int i = 0; i < n; i++){
        if(v[i].front() == s.back()){
            cout << v[i] << "\n";
            return 0;
        }
    }
    cout << "?" << "\n";
    return 0;
}