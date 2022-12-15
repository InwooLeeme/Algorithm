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

#define int int64_t

int32_t main(){
    fastio;
    int n,q; cin >> n;
    map<string, string> M;
    while(n--){
        string s;  cin >> s;
        if(s.size() < 4) continue;
        string ori = s.substr(1, s.size() - 2);
        sort(ori.begin(), ori.end());
        string temp = "";
        temp += s.front();
        temp += ori;
        temp += s.back();
        M[temp] = s;
    }
    cin >> q; cin.ignore();
    vector<string> ret;
    while(q--){
        string S; cin >> S;
        auto F = S.substr(1, S.size() - 2);
        sort(F.begin(), F.end());
        auto cv = S.front() + F + S.back();
        if(M.count(cv)) ret.push_back(M[cv]);
        else ret.push_back(S);
    }
    for(auto& i : ret) cout << i << " ";
    return 0;
}