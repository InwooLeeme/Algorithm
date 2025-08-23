#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    map<int, int> M;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(!M.count(x)) M[x] = i;
        else{
            cout << M[x] << " " << i << endl;
        }
    }
    
    return 0;
}
