# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define int int_fast64_t

const double PI = acos(-1);

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    auto Sol = []() -> void{
        int n; cin >> n;
        double a,b; cin >> a >> b;
        if(n == 1){     
            double r = sqrt(a * a + b * b);
            double seta = 0.0;
            seta = acos(a / r);
            if(b < 0.0) seta = 2. * PI - seta;
            cout << fixed << setprecision(8) << r << " " << (r == 0.0 ? 0.0 : seta) << "\n";
        }
        else{
            double x = a*cos(b), y = a * sin(b);
            cout << fixed << setprecision(8) << x << ' ' << y << "\n";
        }
    };
    while(t--) Sol();
    return 0;   
}
