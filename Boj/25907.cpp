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
    int n,cnt = 0; cin >> n;
    int lo = 1,hi = n,s,t;
    while(lo + 1 < hi){
        ++cnt;
        s = lo + hi >> 1;
        cout << "? " << s << endl;
        cin >> t;
        if(s - t > t){
            hi = s;
        } else if(s - t == t){
            cout << "! " << s << endl;
            return 0;
        } else{
            lo = s;
        }

    }
    return 0;
}