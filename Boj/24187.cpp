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
    string s; cin >> s;
    const int n = s.size();
    int t1 = 1,t2 = 0,t3 = 0,t4 = 0;
    for(int i = 0; i < n; i++){
        if(string("aeiouy").find(s[i]) != -1){
            t4 += t4;
            t4 += t2;
            t2 += (t1 + t3);
        }
        else{
            t1 += t1;
            t3 += (t2 + t4);
        }
    }
    cout << t1 + t2 + t3 + t4 - 1 << "\n";
    return 0;
}