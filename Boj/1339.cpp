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
    vector<int> v(26);
    while(n--){
        string s; cin >> s;
        reverse(s.begin(), s.end());
        for(int i = 0,t = 1; i < s.size(); i++) v[s[i] - 'A'] += t, t *= 10;
    }
    sort(v.begin(), v.end());
    int ret = 0;
    for(int i = 0; i < 10; i++) ret += v[16 + i] * i;
    cout << ret << "\n";
    return 0;
}