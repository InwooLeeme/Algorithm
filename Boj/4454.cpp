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

const int PRECISION = 2;

void Main(){
    double a,b,c,d,m,t; 
    const double EPS = 1e-12;
    while(cin >> a >> b >> c >> d >> m >> t){
        double lo = 0.0, hi = 1e9;
        auto f = [&](double v) -> double{ return a*v*v*v*v + b*v*v*v + c*v*v + d*v; };
        auto Check = [&](const double mid) -> bool{
            return m < (mid * (t / f(mid)));
        };
        while(lo + EPS < hi){
            double mid = (lo + hi) / 2.0;
            if(Check(mid)) lo = mid;
            else hi = mid;
        }
        lo *= 100; lo = int(lo);
        cout << (lo / 100.0) << "\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}