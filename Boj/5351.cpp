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

vector<int> Split(string& s){
    vector<int> ret;
    string temp;
    stringstream in(s);
    while(in >> temp) ret.push_back(stoi(temp));
    return ret;
}

void Sol(){
    string s; getline(cin, s);
    auto ss = Split(s);
    const int n = ss.size();
    vector<int> d(n + 1, 0);
    if(ss.size() == 1){
        cout << ss[0] << "\n";
        return;
    }
    d[0] = ss[0], d[1] = max<int>(ss[0], ss[1]);
    for(int i = 0; i < n; i++){
        for(int j = i + 2; j < n; j++) d[j] = max<int>(d[j], d[i] + ss[j]);
    }
    cout << d[n - 1] << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; cin.ignore();
    while(t--) Sol();
    return 0;
}