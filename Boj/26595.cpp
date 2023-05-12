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
    int n,a,b,c,d,mx = 0,t1 = 0,t2 = 0; cin >> n >> a >> b >> c >> d;
    for(int i = 0; i <= n; i++){
        int cnt1 = (n - i) / b;
        int cnt2 = i / d;
        int sum = a * cnt1 + c * cnt2;
        if(mx < sum){
            mx = sum;
            t1 = cnt1,t2 = cnt2;
        }
    }
    cout << t1 << ' ' << t2 << "\n";
    return 0;
}