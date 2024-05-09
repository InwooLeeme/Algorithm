#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(){
    fastio;
    auto Split = [&](string& s) -> vector<string>{
        vector<string> ret;
        string temp;
        for(auto& i : s) if(isalpha(i)) i = tolower(i);
        for(auto& i : s) if(string("()[]{}.,;:").find(i) != -1) i = ' ';
        stringstream in(s);
        while(in >> temp) ret.push_back(temp);
        return ret;
    };
    auto Sol = [&]() -> void{
        string a,b; getline(cin, a); getline(cin, b);
        auto aa = Split(a), bb = Split(b);
        cout << (aa == bb ? "equal" : "not equal") << "\n\n";
    };
    int t; cin >> t; cin.ignore(); for(int tc = 1; tc <= t; tc++){
        cout << "Data Set "  << tc << ": ";
        Sol();
    }
    return 0;
}
