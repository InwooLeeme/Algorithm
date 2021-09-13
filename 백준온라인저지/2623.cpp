// 2623.cpp : 음악 프로그램.
// https://www.acmicpc.net/problem/2623

#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define MAX 100001
#define INF 1e9+7
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ldb = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
#define sz(a) int((a).size())

int32_t main(){
	fastio;
	int N, M, indegree[1000] = {0};
    vector<int> adj[1000];
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++){
        int K, prev, curr;
        scanf("%d", &K);
        if(K == 0) continue;
 
        scanf("%d", &prev);
        for(int i=1; i<K; i++){
            scanf("%d", &curr);
            indegree[curr-1]++;
            adj[prev-1].push_back(curr-1);
            prev = curr;
        }
    }
 
    int result[1000];
    queue<int> Q;
    // ���� ���� ����: ť�� indegree�� 0�� ������ �� ����
    for(int i=0; i<N; i++)
        if(indegree[i] == 0) Q.push(i);
 
    // ���� ����
    for(int i=0; i<N; i++){
        // ���߿� ť�� ��� �Ұ���
        if(Q.empty()){
            puts("0");
            return 0;
        }
 
        int curr = Q.front();
        Q.pop();
        result[i] = curr+1; // ť���� ���� ���� ������ ���������� ����. 
        // ������ ������ ��ȸ�ϸ鼭 indegree 1�� ����. 0�� �Ǹ� ť�� ����
        for(int next: adj[curr])
            if(--indegree[next] == 0) Q.push(next);
    }
 
    // ��� ���
    for(int i=0; i<N; i++)
        printf("%d\n", result[i]);
	return 0;
}
