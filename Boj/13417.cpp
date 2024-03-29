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
        int n; cin >> n;
        deque<char> DQ;
        while(n--){
            char c; cin >> c;
            if(!DQ.empty() and DQ.front() >= c) DQ.push_front(c);
            else if(!DQ.empty() and DQ.back() < c) DQ.push_back(c);
            else DQ.push_back(c);
        }
        for(auto& i : DQ) cout << i; cout << "\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}