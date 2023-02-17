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
    string s;
    while(getline(cin, s) and s != "#"){
        string temp;
        stringstream in(s);
        vector<string> v;
        while(in >> temp) v.push_back(temp);
        for(auto& i : v){
            reverse(i.begin(), i.end());
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}