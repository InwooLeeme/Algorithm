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

//#define int int_fast64_t

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,k; cin >> n >> k;
    if(n == 1){
        cout << 1 << '\n';
        return 0;
    }
    else if(n == 2){
        cout << 1 << ' ' << 2 << "\n";
        return 0;
    }
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    do{
        vector<int> s;
        for(int i = 1; i < n; i++) s.push_back(v[i - 1] + v[i]);
        while(s.size() != 2){
            vector<int> A;
            for(int i = 1; i < s.size(); i++) A.push_back(s[i - 1] + s[i]);
            s = A;
        }
        if(s[0] + s[1] == k){
            for(auto& c : v) cout << c << " ";
            return 0;
        }
    }while(next_permutation(v.begin(), v.end()));
    return 0;
}