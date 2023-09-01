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
    int n; cin >> n;
    deque<int> DQ; for(int i = 0,t; i < n; i++){
        cin >> t;
        DQ.push_back(t);
    }
    sort(DQ.begin(), DQ.end());
    int l = 0,r = 0,idx = 1;
    while(!DQ.empty()){
        if(idx & 1) r += DQ.back(), DQ.pop_back();
        else l += DQ.front(), DQ.pop_front();
        idx++;
    }
    cout << l << " " << r << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}