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

void Sol(){
    int n; cin >> n;
    vector<int> v(n); for(auto& i : v) cin >> i;
    int idx = max_element(v.begin(), v.end()) - v.begin();
    for(int i = 1; i < idx; i++){
        if(v[i - 1] >= v[i]){
            cout << "NO" << "\n";
            return;
        }
    }
    for(int i = idx + 1; i < n; i++){
        if(v[i - 1] <= v[i]){
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Sol();
    return 0;
}