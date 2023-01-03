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
    int T; cin >> T; cin.ignore();
    while(T--){
        string s; getline(cin ,s); 
        vector<bool> v(26, 0);
        for(auto& i : s){
            if(isalpha(i)){
                if(isupper(i)) i = tolower(i);
                v[i - 'a'] = 1;
            }
        }
        string ret = "";
        for(int i = 0; i < 26; i++) if(!v[i]) ret += char(i + 'a');
        if(ret == "") cout << "pangram" << "\n";
        else cout << "missing " << ret << "\n";
    }
    return 0;
}