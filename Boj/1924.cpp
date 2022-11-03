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

#define int int64_t

int week(int y,int m,int d){
    if(m < 3) y--;
    m = (m + 9) % 12 + 1;
    int _c = y / 100, _y = y % 100;
    return ((d + int(2.6*m - 0.2) - 2*_c + _y + _c / 4 + _y / 4) % 7 + 7) % 7;
}

const string DB[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int32_t main(){
    fastio;
    int x,y; cin >> x >> y;
    cout <<(DB[week(2007, x, y)]);
    return 0;
}