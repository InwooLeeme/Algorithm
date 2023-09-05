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

void Main(){
    int t; cin >> t; while(t--){
        int n; cin >> n; int h = n >> 1;
        unordered_map<int, int> M;
        for(int i = 0,x; i < n; i++){
            cin >> x; M[x]++;
        }
        vector<int> ret;
        for(auto& [a, b] : M) if(b > h) ret.push_back(a);
        if((int)ret.size() != 1) cout << "SYJKGW" << "\n";
        else cout << ret[0] << "\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}