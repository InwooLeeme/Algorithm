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

#define int int_fast64_t

using Point = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int n,mm,k;
// 0-indexed
bool Bound(int x,int y) { return x < 0 || x >= n || y < 0 || y >= n; }
constexpr int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
constexpr int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

// for moving each fireball in board
int F(int x,int MOD){
	return ((x % MOD) + MOD) % MOD;
}

struct FireBall{
	int x,y,m,s,d;
	FireBall():x(0),y(0),m(0),s(0),d(0){}
	void Moving(){
		x = F(x + dx[d] * s, n);
		y = F(y + dy[d] * s, n);
	};
};

// 파이어볼 이동 함수
void MoveFireBall(vector<FireBall>& v){
	for(auto& fireball : v) fireball.Moving();
}

int CalDir(const vector<FireBall>& v, int idx){
	int DB1[4] = {0, 2, 4, 6};
	int DB2[4] = {1, 3, 5, 7};
	int t1 = 0,t2 = 0; // 홀수, 짝수
	const int sz = v.size();
	for(auto& [x, y, m, s, d] : v){
		if(d & 1) t1++;
		else t2++;
	}
	if(t1 == sz) return DB1[idx];
	if(t2 == sz) return DB1[idx];
	return DB2[idx];
}

// 속도 계산
int CalSpeed(const vector<FireBall>& v){
	int ret = 0; const int sz = v.size();
	for(auto& [x, y, m, s, d] : v) ret += s;
	return ret / sz;
}

// 나눠질 파이어볼의 질량 계산 함수
int CalWeight(const vector<FireBall>& v){
	int ret = 0;
	for(auto& [x, y, m, s, d] : v) ret += m;
	return ret / 5;
}

// 파이어볼을 합치는 함수
void MergeFireBall(vector<FireBall>& ret, const vector<FireBall>& v){
	const int sz = v.size();
	for(int i = 0; i < 4; i++){
		FireBall temp;
		temp.x = v[0].x,temp.y = v[0].y;
		int weight = CalWeight(v);
		if(!weight) return;
		temp.m = weight;
		temp.s = CalSpeed(v);
		temp.d = CalDir(v, i);
		ret.push_back(temp);
	}
}

// 같은 곳에 있는 파이어볼이 2개 이상인지 판단하고 배열을 업데이트 하는 함수.
vector<FireBall> CheckFireBallIntersection(const vector<FireBall>& v){
	vector<FireBall> ret;
	map<Point, vi> Check;
	const int sz = v.size();
	for(int i = 0; i < sz; i++){
		auto& [x, y, m, s, d] = v[i];
		Check[{x, y}].push_back(i);
	}
	for(auto& I : Check){
		if(I.second.size() >= 2){
			vector<FireBall> temp;
			for(auto& j : I.second) temp.push_back(v[j]);
			MergeFireBall(ret, temp);
		}
		else {
			for(auto& c : I.second) ret.push_back(v[c]);
		}
	}
	return ret;
}

int Sol(vector<FireBall>& v){
	int ret = 0;
	for(int i = 0; i < k; i++){
		MoveFireBall(v);
		auto temp = CheckFireBallIntersection(v);
		v = temp;
	}
	for(auto& [x, y, m, s, d] : v) ret += m;
	return ret;
}

int32_t main(){
	fastio;
	// Input
	cin >> n >> mm >> k;
	vector<FireBall> Fb(mm);
	for(auto& [x, y, m, s, d] : Fb){
		cin >> x >> y >> m >> s >> d; --x,--y;
	}
	cout << Sol(Fb) << "\n";
	return 0;
}