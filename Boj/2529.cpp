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

const int INF = int(2e18);
int k,mx = -INF, mn = INF;
string retmx,retmn;
vector<int> v;
vector<char> S;
int chk[22];

void f(int dep){
    if(dep == k + 1){
        string cur = "";
        for(auto& c : v) cur.push_back(c + '0');
        if(mn > stoll(cur)) retmn = cur,mn = stoll(cur);
        if(mx < stoll(cur)) retmx = cur,mx = stoll(cur);
        return;
    }
    for(int i = 0; i < 10; i++){
        if(chk[i]) continue;
        if(S[dep - 1] == '<' and v[dep - 1] >= i) continue;
        if(S[dep - 1] == '>' and v[dep - 1] <= i) continue;
        chk[i] = 1;
        v.push_back(i);
        f(dep + 1);
        v.pop_back();
        chk[i] = 0;
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> k;
    for(int i = 0; i < k; i++){
        char c; cin >> c;
        S.push_back(c);
    }
    for(int i = 0; i < 10; i++){
        chk[i] = 1;
        v.push_back(i);
        f(1);
        v.pop_back();
        chk[i] = 0;
    }
    cout << retmx << '\n' << retmn << "\n";
    return 0;
}