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
    string s; while(cin >> s and s != "#"){
        vector<string> v;
        for(int i = 0; i < s.size(); i++){
            auto l = s.substr(0, i) + s.substr(i + 1);
            v.push_back(l);
        }
        auto Check = [&](string& x) -> bool{ return equal(x.begin(), x.end(), x.rbegin()); };
        bool flag = 0;
        for(auto& i : v) if(Check(i)){
            flag = 1;
            cout << i << "\n";
            break;
        }
        if(!flag) cout << "not possible" << "\n";
    }
    return 0;
}