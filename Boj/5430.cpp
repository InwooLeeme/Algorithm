#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using namespace __gnu_cxx;

#define X first
#define Y second
#define int int64_t
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define Compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)
#define IDX(v, x) (lower_bound(all(v), x) - (v).begin())
#define debug(x) cout << (#x) << ": " << (x) << '\n'

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tii = tuple<int, int, int>;
template <typename T>
using wector = vector<vector<T>>;

vector<int> Parsing(string& s){
	const int sz = s.size();
	for(int i = 0; i < sz; i++){
		if(s[i] == ',' || s[i] == '[') s[i] = ' ';
	}
	vector<int> ret;
	stringstream in(s);
	int temp;
	while(in >> temp) ret.push_back(temp);
	return ret;
}

void Print(const deque<int>& DQ){
	cout << '[';
	for(int i = 0; i < DQ.size(); i++){
		cout << DQ[i];
		if(i != DQ.size() - 1) cout << ',';
	}
	cout << "]\n";
}

void Sol(){
	string p,s;
	int n;
	cin >> p >> n >> s;
	auto arr = Parsing(s);
	deque<int> DQ;
	bool isReverse = false;
	for(int i = 0; i < arr.size(); i++) DQ.push_back(arr[i]);
	for(int i = 0; i < p.size(); i++){
		if(p[i] == 'R'){
			// reverse
			isReverse = !isReverse;
		}
		else{
			if(DQ.empty()){
				cout << "error" << "\n";
				return;
			}
			else{
				isReverse ? DQ.pop_back() : DQ.pop_front();
			}
		}
	}
	if(isReverse) reverse(all(DQ));
	Print(DQ);
}

int32_t main(){
	fastio;
	int t; cin >> t;
	while(t--){
		Sol();	
	}
}