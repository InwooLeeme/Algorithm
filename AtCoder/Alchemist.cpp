#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define int int_fast64_t

int32_t main(){
    fastio;
    int n; cin >> n;
    double ret = 0.0;
    priority_queue<double, vector<double>, greater<double>> PQ;
    for(int i = 0; i < n; i++){
        double s; cin >> s;
        PQ.push(s);
    }
    while(PQ.size() != 1){
        auto s = PQ.top(); PQ.pop();
        auto e = PQ.top(); PQ.pop();
        ret = (s + e) / 2;
        PQ.push(ret);
    }
    cout << fixed << setprecision(5) << PQ.top() << "\n";
    return 0;
}