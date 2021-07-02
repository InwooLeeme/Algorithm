// 1935번 : 후위 표기식2

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <iomanip>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    int test;
    string task; // 식을 입력받기 위한 문자열
    cin >> test >> task;
    vector<int> v(test);
    stack<double> stack;
    for (int i = 0; i < test; i++)
        cin >> v[i]; // 숫자를 test갯수만큼 입력 받음
    for (int i = 0; i < task.size(); i++)
    {
        // 연산자를 만났으면 스택에서 2개를 빼서 계산하고 다시 스택에 push
        if (task[i] == '+')
        {
            double b = stack.top();
            stack.pop();
            double a = stack.top();
            stack.pop();
            stack.push(a + b);
        }
        else if (task[i] == '-')
        {
            double b = stack.top();
            stack.pop();
            double a = stack.top();
            stack.pop();
            stack.push(a - b);
        }
        else if (task[i] == '*')
        {
            double b = stack.top();
            stack.pop();
            double a = stack.top();
            stack.pop();
            stack.push(a * b);
        }
        else if (task[i] == '/')
        {
            double b = stack.top();
            stack.pop();
            double a = stack.top();
            stack.pop();
            stack.push(a / b);
        }
        else
        {
            // 피 연산자이면
            stack.push(v[task[i] - 'A']);
        }
    }
    cout << fixed << setprecision(2) << stack.top() << '\n';
    return 0;
}