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
    int n,q; cin >> n;
    map<int, int> M;
    for(int i = 0,x; i < n; i++){
        cin >> x;
        M[x]++;
    }
    cin >> q;
    while(q--){
        int a,b; cin >> a;
        vector<int> l(a); for(auto& i : l) cin >> i;
        cin >> b; vector<int> r(b); for(auto& i : r) cin >> i;
        map<int, int> C;
        for(const auto& i : l) C[i]++;
        bool chk = 1;
        for(const auto& [a, b] : C){
            if(M[a] < b) { chk = 0; break; }
        }
        if(chk){
            for(const auto& [a, b] : C) M[a] -= b;
            for(const auto& i : r) M[i]++;
        }
    }
    vector<int> ret;
    for(const auto& [a, b] : M){
        for(int j = 0; j < b; j++) ret.push_back(a);
    }
    cout << ret.size() << "\n";
    for(const auto& i : ret) cout << i << " ";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
