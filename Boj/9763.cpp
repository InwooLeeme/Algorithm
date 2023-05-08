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

struct Point3D{
    int x,y,z;
};

int GetD(Point3D& a, Point3D& b){
    int ret = 0;
    return abs(a.x - b.x) + abs(a.y - b.y) + abs(a.z - b.z);
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    vector<Point3D> v(n);
    vector<int> chk(n);
    for(auto& [x, y, z] : v) cin >> x >> y >> z;
    fill(chk.begin(), chk.begin() + 3, 1);
    int mn = int(2e9);
    for(int i = 0; i < n; i++){
        int x = 10000, y = 10000;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            int d = GetD(v[i], v[j]);
            if(x > d) y = x, x = d;
            else y = min<int>(y, d);
        }
        mn = min<int>(mn, x + y);
    }
    cout << mn << '\n';
    return 0;
}