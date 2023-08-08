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
    vector<int> chk(12),v(12); for(int i = 0; i < 12; i++){
        cin >> v[i];
        if(0 <= i and i <= 2) chk[i] = 0;
        else if(3 <= i and i <= 5) chk[i] = 1;
        else if(6 <= i and i <= 8) chk[i] = 2;
        else chk[i] = 3;
    }
    int mn = int(2e18);
    do{
        vector<int> w(4);
        for(int i = 0; i < 12; i++) w[chk[i]] += v[i];
        mn = min<int>(mn, abs(*max_element(w.begin(), w.end()) - *min_element(w.begin(), w.end())));
        if(!mn and mn == 1) break;
    }while(next_permutation(chk.begin(), chk.end()));
    cout << mn << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}