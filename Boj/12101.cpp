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

using vi = vector<int>;

int n,k;
set<string> S;
int v[3] = {1, 2, 3};

void f(string s = "", int sum = 0){
    for(int i = 0; i < 3; i++){
        sum += v[i];
        if(sum > n) continue;
        else if(sum == n) S.insert(s + "+" + to_string(v[i]));
        else f(s + "+" + to_string(v[i]), sum);
        sum -= v[i];
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k; --k;
    f();
    int idx = 0;
    for(auto& c : S){
        if(idx == k){
            cout << c.substr(1) << "\n";
            return 0;
        }
        idx++;
    }
    cout << -1 << "\n";
    return 0;
}