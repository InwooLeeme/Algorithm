// 1916번 : 최소비용 구하기
// https://www.acmicpc.net/problem/1916

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <cmath>
#include <queue>
#include <functional>
#define INF 0x3f3f3f3f
#define max 1001
using namespace std;
vector<pair<int, int>> adj[max]; // 노드들의 정보들을 담는 벡터
vector<int> dist(max, INF);      //최단거리를 저장하는 배열, dist배열 초기화 해준다.
int start;
int n, m; // n : 정점의 수, m : 간선의 수
int dest;

void dijkstra(int vertax)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, vertax));
    dist[vertax] = 0;
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        if (dist[cur] < weight)
            continue; // pq에 넣어준 최단거리가 최근 갱신한 최단거리보다 클 경우에는 굳이 다익스트라를 할 필요 없이 넘어가주면 된다
        //if(cur == dest) return;
        for (int i = 0; i < adj[cur].size(); i++)
        {
            int next = adj[cur][i].second;
            int nWeight = adj[cur][i].first;
            if (dist[next] > nWeight + weight)
            {
                dist[next] = nWeight + weight;
                pq.push(make_pair(dist[next], next));
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(w, v));
    }
    scanf("%d%d", &start, &dest);
    dijkstra(start);
    cout << dist[dest];
    return 0;
}
