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
    string s; cin >> s;
    stack<char> v;
    for(char& i : s){
        if(i == '(') v.push(i);
        else{
            if(!v.empty() and v.top() == '(') v.pop();
            else v.push(i);
        }
    }
    cout << v.size() << "\n";
    return 0;
}