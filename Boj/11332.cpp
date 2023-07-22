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

const int sz = 100000000;

void Sol(){
    string s; int n,t,l; cin >> s >> n >> t >> l;
    auto pass = [&]()-> void{ cout << "May Pass.\n";};
    auto fail = [&]() -> void { cout << "TLE!\n"; };
    if(s == "O(N)"){
        int sum = n*t;
        if(sum <= (l* sz)){
            pass();
            return;
        } else{ fail(); return; }
    }
    else if(s == "O(N^2)"){
        if(n >= 31623){
            fail();
            return;
        }
        else{
            int sum = (n*n*t);
            if(sum <= (l * sz)){
                pass();
            } else{ fail(); return; }
        }
    }
    else if(s == "O(N^3)"){
        if(n >= 31623){ fail(); return;}
        else{
            int sum = n*n*n*t;
            if(sum <= (l*sz)){ pass(); return; }
            else{ fail(); return; }
        }
    }
    else if(s == "O(2^N)"){
        if(n >= 30){ fail(); return; }
        else{
            int sum = (int)pow(2, n)*t;
            if(sum <= (l * sz)){ pass(); return; }
            else{fail(); return; }
        }
    }
    else if(s == "O(N!)"){
        if(n >= 13){fail(); return; }
        else{
            int sum = t;
            for(int i = 1; i <= n; i++) sum *= i;
            if(sum <= (l * sz)){pass(); return;}
            else{fail(); return;}
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while(t--) Sol();
    return 0;
}