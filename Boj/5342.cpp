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

int32_t main(){
    fastio;
    string s; 
    double ret = 0.0;
    while(cin >> s and s != "EOI"){
        if(s == "Paper") ret += 57.99;
        else if(s == "Printer") ret += 120.50;
        else if(s == "Planners") ret += 31.25;
        else if(s == "Binders") ret += 22.50;
        else if(s == "Calendar") ret += 10.95;
        else if(s == "Notebooks") ret += 11.20;
        else if(s == "Ink") ret += 66.95;
    }
    cout << fixed << setprecision(2) << "$" << ret<< "\n";
    return 0;
}