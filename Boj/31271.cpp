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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fi first
#define se second
#define pb push_back

const int PRECISION = 0;


void Main(){
    int n; cin >> n;
    using p = pair<int, int>;
    vector<p> w;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) w.pb({a[i], b[i]});
    vector<int> LIS;
    sort(all(w));
    for(int i = 0; i < n; i++){
        auto t = w[i].se;
        if(LIS.empty() or LIS.back() < t) LIS.pb(t);
        else *lower_bound(all(LIS), t) = t;
    }
    cout << LIS.size() << "\n";
}   

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
