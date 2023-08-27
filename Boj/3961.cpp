#pragma GCC target("avx,avx2,fma")
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
    using p = pair<int, string>;
    auto Search = [&](char& a) -> pair<int, int>{
        int x = 0,y = 0;
        if(string("qwertyuiop").find(a) != -1) x = 0,y = string("qwertyuiop").find(a);
        else if(string("asdfghjkl").find(a) != -1) x = 1,y = string("asdfghjkl").find(a);
        else if(string("zxcvbnm").find(a) != -1) x =  2,y = string("zxcvbnm").find(a);
        return {x, y};
    };
    auto Score = [&](char& a, char& b) -> int{
        auto t1 = Search(a), t2 = Search(b);
        return abs(t1.first - t2.first) + abs(t1.second - t2.second);
    };
	int t; cin >> t; while(t--){
        string s; int n; cin >> s >> n;
        const int sz = s.size();
        vector<string> v(n); for(auto& i : v) cin >> i;
        vector<p> ret;
        for(auto& I : v){
            int sum = 0;
            for(int i = 0; i < sz; i++){
                sum += Score(s[i], I[i]);
            }
            ret.push_back({sum, I});
        }
        sort(ret.begin(), ret.end(), [&](p& a, p& b){
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });
        for(auto& I : ret) cout << I.second << " " << I.first << "\n";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
	return 0;
}
