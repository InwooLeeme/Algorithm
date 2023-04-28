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

using tii = tuple<int, int, int>;

vector<string> Split(string& s){
    vector<string> ret;
    for(auto& i : s) if(i == '+' || i == '=') i = ' ';
    string temp;
    stringstream in(s);
    while(in >> temp) ret.push_back(temp);
    return ret;
}

map<char, int> M[3];

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s; cin >> s;
    auto ss = Split(s);
    for(int i = 0; i < 3; i++){
        auto& c = ss[i];
        int sz = c.size();
        for(int j = 0; j < sz; j++){
            if(isdigit(c[j])){
                M[i][c[j - 1]] += (c[j] - '0' - 1);
            } 
            else M[i][c[j]]++;
        }
    }
    vector<tii> ret;
    for(int a = 1; a <= 10; a++) for(int b = 1; b <= 10; b++) for(int c = 1; c <= 10; c++){
        map<char, int> news;
        for(auto& [x, y] : M[0]) news[x] += a * y;
        for(auto& [x, y] : M[1]) news[x] += b * y;
        bool ok = 1;
        for(auto& [a, b] : news){
            if(b != c * M[2][a]){
                ok = 0;
                break;
            }
        }
        if(ok) ret.push_back({a, b, c});
    }
    sort(ret.begin(), ret.end());
    auto& [x,y,z] = ret[0];
    cout << x << " " << y << " " << z << "\n";
    return 0;
}