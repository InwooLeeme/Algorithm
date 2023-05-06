# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define int int_fast64_t

vector<int> g[33];
vector<int> indegree(33);
vector<int> cost(33, -1);

vector<string> Split(const string& s){
    vector<string> ret;
    string temp;
    stringstream in(s);
    while(in >> temp) ret.push_back(temp);
    return ret;
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s; 
    while(getline(cin, s)){
        auto ss = Split(s);
        auto to = ss[0][0] - 'A';
        cost[to] = stoi(ss[1]);
        if(ss.size() >= 3){
            for(auto from : ss[2]){
                g[from - 'A'].push_back(to);
                indegree[to]++;
            }
        }
    }   
    queue<int> Q;
    vector<int> D(26, -1);
    for(int i = 0; i < 26; i++){
        if(!indegree[i] and cost[i] != -1){
            Q.push(i);
            D[i] = cost[i];
        }
    }
    while(Q.size()){
        auto cur = Q.front(); Q.pop();
        for(auto nxt : g[cur]){
            D[nxt] = max<int>(D[nxt], D[cur] + cost[nxt]);
            --indegree[nxt];
            if(!indegree[nxt]) Q.push(nxt);
        }
    }
    cout << *max_element(D.begin(), D.end()) << "\n";
    return 0;   
}
