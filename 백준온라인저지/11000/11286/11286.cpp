// 11286번 : 절댓값 힙

#include <iostream>
#include <queue>
#include <algorithm>
#include <math.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

struct cmp
{
    bool operator()(int a, int b)
    {
        if (abs(a) == abs(b)) // 절댓값이 같은 경우
        {
            return a > b; // 오름차순으로 정렬(음수가 먼저 출력)
        }
        else
            return abs(a) > abs(b); // 절댓값이 다른 경우 내림차순으로 정렬
    }
};

int main()
{
    fastio;
    int n;
    cin >> n;
    priority_queue<int, vector<int>, cmp> pq;
    while (n--)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            if (pq.empty())
            {
                cout << "0\n";
            }
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
        {
            pq.push(x);
        }
    }

    return 0;
}