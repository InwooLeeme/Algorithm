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
    string s; getline(cin, s);
    vector<int> v(26, 0);
    for(auto& i : s){
        if(isalpha(i)){
            if(isupper(i)) i = tolower(i);
            v[i - 'a']++;
        }
    }
    for(int i = 0; i < 26; i++){
        cout << char(i + 'A') << " | ";
        for(int j = 0; j < v[i]; j++) cout << "*";
        cout << "\n";
    }
    return 0;
}