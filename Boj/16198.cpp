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

const int PRECISION = 0;

int Sol(vector<int>& v){
    if(v.size() < 3) return 0;
    int ret = 0;
    for(int i = 1; i < v.size() - 1; i++){
        vector<int> nxt;
        for(int j = 0; j < v.size(); j++){
            if(i != j) nxt.push_back(v[j]);
        }
        ret = max<int>(ret, v[i - 1] * v[i + 1] + Sol(nxt));
    }
    return ret;
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    int n; cin >> n;
    vector<int> v(n); for(auto& i : v) cin >> i;
    cout << Sol(v) << "\n";
    return 0;
}