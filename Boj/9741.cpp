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

template<typename T>
struct Triangle{
    using pt = pair<T, T>;
    pt A,B,C;
    Triangle(pt _A,pt _B, pt _C):A(_A),B(_B),C(_C){}
    void Input(){  }
    T Area(){ // gauss
        return abs((A.first * B.second + B.first*C.second + C.first * A.second) - (B.first*A.second + C.first*B.second + A.first*C.second)) / 2;
    }
    int BoundaryPoint(pt& a, pt& b){
        T dx = abs(a.first - b.first);
        T dy = abs(a.second - b.second);
        int g = __gcd(max<T>(dx, dy), min<T>(dx, dy));
        return g - 1;
    }
    int CountBoundaryPoint(){
        return BoundaryPoint(A, B) + BoundaryPoint(B, C) + BoundaryPoint(C, A);
    }
    int Pick(){
        auto area = Area();
        auto bp = CountBoundaryPoint() + 3;
        int ip = area - bp / 2 + 1;
        return ip;
    }
};

void test_case(){
    int a,b,c,d,e,f; cin >> a >> b >> c >> d >> e >> f;
    Triangle<int> TR({a, b}, {c, d}, {e, f});
    cout << (TR.Area() == 0 ? 0 : TR.Pick()) << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while(t--) test_case();
    return 0;
}