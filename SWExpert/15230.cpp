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

void Main(){
    string DB = "abcdefghijklmnopqrstuvwxyz";
    int t; cin >> t; for(int tc = 1; tc <= t; tc++){
        cout << "#" << tc << " ";
        string s; cin >> s; int ret = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == DB[i]) ret++;
            else break;
        }
        cout << ret << "\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}