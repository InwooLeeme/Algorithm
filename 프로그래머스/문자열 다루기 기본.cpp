#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    if (s.size() == 4 || s.size() == 6)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (isalpha(s[i]))
            {
                answer = false;
                break;
            }
        }
    }
    else
        answer = false;
    return answer;
}