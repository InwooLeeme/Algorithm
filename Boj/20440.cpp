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

using p = pair<int, int>;

void Sol(){
    int n; cin >> n;
    vector<int> w;
    vector<p> v(n); for(auto& [a, b] : v) cin >> a >> b, w.push_back(a), w.push_back(b);
    // Compress
    sort(w.begin(), w.end());
    w.erase(unique(w.begin(), w.end()), w.end());
    auto IDX = [&](int x) -> int{ return lower_bound(w.begin(), w.end(), x) - w.begin(); };
    for(auto& [a, b] : v) a = IDX(a),b = IDX(b);
    // build prefix sum using imos
    vector<int> ps(w.size() + 1);
    for(auto& [a, b] : v) ps[a]++,ps[b]--;
    for(int i = 1; i < ps.size(); i++) ps[i] += ps[i - 1];
    int mx = *max_element(ps.begin(), ps.end());
    int st = find(ps.begin(), ps.end(), mx) - ps.begin();
    cout << mx << '\n';
    for(int i = st; i <= ps.size(); i++){
        if(i == ps.size() or ps[i] ^ mx){
            cout << w[st] << ' ' << w[i] << "\n";
            break;
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Sol();
    return 0;
}