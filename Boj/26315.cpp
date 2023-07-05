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

int a,b;

void testcase(){
    cout << "Possible records:\n";
    for(int i = a; i >= 0; i--){
        for(int j = a; j >= 0; j--){
            for(int k = a; k >= 0; k--){
                if(3*i + j == b and i+j+k == a){
                    cout << i << '-' << j << '-' << k << "\n";
                }
            }
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Team #" << i << "\n";
        cin >> a >> b;
        cout << "Games: " << a << "\n";
        cout << "Points: " << b << "\n";
        testcase();
        cout << "\n";
    }
    return 0;
}