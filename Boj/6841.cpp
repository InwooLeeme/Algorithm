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
    string str;
    while(cin >> str){
        if(str == "CU") cout << "see you";
        else if(str == ":-)") cout << "I’m happy";
        else if(str == ":-(") cout << "I’m unhappy";
        else if(str == ";-)") cout << "wink";
        else if(str == ":-P") cout << "stick out my tongue";
        else if(str == "(~.~)") cout << "sleepy";
        else if(str == "TA") cout << "totally awesome";
        else if(str == "CCC") cout << "Canadian Computing Competition";
        else if(str == "CUZ") cout << "because";
        else if(str == "TY") cout << "thank-you";
        else if(str == "YW") cout << "you’re welcome";
        else if(str == "TTYL") cout << "talk to you later";
        else cout << str;
        cout << "\n";
    }
    return 0;
}