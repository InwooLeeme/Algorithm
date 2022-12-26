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

string s;

void Sol(){
    bool flag = 1;
    vector<char> st;
    for(auto& i : s){
        if(i == '(' || i == '{' || i == '[') st.push_back(i);
        if(i == ')'){
            auto t = st.back();
            if(t != '(') flag = 0;
            else st.pop_back();
        }
        if(i == ']'){
            auto t = st.back();
            if(t != '[') flag = 0;
            else st.pop_back();
        }
        if(i == '}'){
            auto t = st.back();
            if(t != '{') flag = 0;
            else st.pop_back();
        }
    }
    cout << ((flag and st.empty()) ? "Legal" : "Illegal") << "\n";
}

int32_t main(){
    fastio; 
    while(getline(cin, s) and s != "#") Sol();
    return 0;
}