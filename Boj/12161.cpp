#include<bits/stdc++.h>

using namespace std;

#define int int64_t

const int PRECISION = 0;

void Main(){
    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cout << "Case #" << tc << ": ";
        int n; cin >> n;
        vector<int> v(n); for(auto& i : v) cin >> i;
        int l = 0,r = 0,mx = 0;
        for(int i = 1; i < n; i++) l += max<int>(v[i - 1] - v[i], (int)0);
        for(int i = 1; i < n; i++) mx = max<int>(mx, v[i - 1] - v[i]);
        for(int i = 0; i < n - 1; i++) r += min<int>(v[i], mx);
        cout << l << " " << r << "\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
