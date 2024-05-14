#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(){
	fastio;
    int n,q; cin >> n >> q;
    string s; cin >> s;
    while(q--){
        int t,a,b; cin >> t >> a >> b; --a,--b;
        if(t == 1){
            int ret = 0,cnt = 0;
            for(int l = a; l <= b;){
                char cur = s[l]; int x = l;
                while(1){
                    if(x > b or s[x] != cur) break;
                    cnt++;
                    x++;
                }
                l += cnt;
                ret++;
                cnt = 0;
            }
            cout << ret << "\n";
        } else{
            for(int i = a; i <= b; i++){
                s[i] = char((((s[i] - 'A') + 1) % 26) + 'A');
            }
        }
    }
    return 0;
}
