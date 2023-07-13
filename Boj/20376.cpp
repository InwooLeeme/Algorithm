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

vector<string> Split(string& s){
    vector<string> ret;
    string temp;
    stringstream in(s);
    while(in >> temp) ret.push_back(temp);
    return ret;
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string a,b;
    map<string, int> M;
    while(cin >> a){
        cin.ignore();
        getline(cin, b);
        M[b]++;
    }
    cout << M.size() << '\n';
    return 0;
}