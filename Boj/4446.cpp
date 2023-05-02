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

vector<string> Split(string& s){
    vector<string> ret;
    stringstream in(s);
    string temp;
    while(in >> temp) ret.push_back(temp);
    return ret;
}

string DB1 = "aiyeou";
string DB2 = "bkxznhdcwgpvjqtsrlmf";

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;  //getline(cin, s);
    while(getline(cin, s)){
        auto ss = Split(s);
        const int sz1 = DB1.size();
        const int sz2 = DB2.size();
        for(int i = 0; i < ss.size(); i++){
            auto c = ss[i];
            for(auto& j : c){
                if(!isalpha(j)) continue;
                bool flag = 0;
                if(isupper(j)) flag = 1, j = tolower(j);
                if(DB1.find(j) != -1){
                    int idx = DB1.find(j);
                    j = (!flag ? DB1[abs(idx + 3) % sz1] : toupper(DB1[abs(idx + 3) % sz1]));
                }
                else{
                    int idx = DB2.find(j);
                    j = (!flag ? DB2[abs(idx + 10) % sz2] : toupper(DB2[abs(idx + 10) % sz2]));
                }
            }
            cout << c << (i != ss.size() - 1 ? " " : "");
        }
        cout << "\n";
    }
    return 0;
}