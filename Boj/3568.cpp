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

vector<string> Split(const string& s){
    vector<string> ret;
    string temp;
    stringstream in(s);
    while(in >> temp) ret.push_back(temp);
    return ret;
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s; getline(cin, s);
    auto ss = Split(s);
    auto tt = ss[0];
    for(int i = 1; i < ss.size(); i++){
        auto name = regex_replace(ss[i], regex("[^a-zA-Z]"),"");
        auto k = regex_replace(ss[i], regex("[a-zA-Z]"), "");
        string revk = "";
        reverse(k.begin(), k.end());
        for(int i = 0; i < k.size(); i++){
            if(k[i] == ',' || k[i] == ';') continue;
            if(k[i] == '[') revk.push_back(']');
            else if(k[i] == ']') revk.push_back('[');
            else revk.push_back(k[i]);
        }
        cout << tt << revk << " " << name << ";\n";
    }
    return 0;
}