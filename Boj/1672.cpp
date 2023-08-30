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

string DB[4] = {
    "ACAG","CGTA","ATCG","GAGT"
};

void Main(){
    int n; string s; cin >> n >> s;
    auto F = [&](char& c) -> int{
        return string("AGCT").find(c);
    };
    while(s.size() != 1){
        int r = F(s.back()); s.pop_back();
        int c = F(s.back()); s.pop_back();
        s += DB[r][c];
    }
    cout << s << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}