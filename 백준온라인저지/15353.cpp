// 15353번 : 큰 수 A + B(2)
//www.acmicpc.net/problem/15353
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(string &A, string &B)
{
    string C(max(A.size(), B.size()), '0');
    bool carry = false;
    for (int i = 0; i < C.size(); i++)
    {
        int temp = carry;
        carry = false;
        if (i < A.size())
            temp += A[A.size() - i - 1] - '0';
        if (i < B.size())
            temp += B[B.size() - i - 1] - '0';
        if (temp >= 10)
        {
            carry = true;
            temp -= 10;
        }
        C[C.size() - i - 1] = temp + '0';
    }
    if (carry)
        C.insert(C.begin(), '1');
    return C;
}

string multiply(string &A, string &B)
{
    string C = "0";
    for (int i = 0; i < B.size(); i++)
    {
        string line(A);
        int carry = 0;
        for (int j = A.size() - 1; j >= 0; j--)
        {
            int temp = carry;
            carry = 0;
            temp += (A[j] - '0') * (B[B.size() - i - 1] - '0');
            if (temp >= 10)
            {
                carry = temp / 10;
                temp %= 10;
            }
            line[j] = temp + '0';
        }
        if (carry > 0)
            line.insert(line.begin(), carry + '0');
        line += string(i, '0');
        C = add(C, line);
    }
    return C;
}

string power(string &A, int B)
{
    if (B == 1)
        return A;
    string C = power(A, B - 1);
    C = multiply(C, A);
    return C;
}

int main()
{
    string A, C, B;
    cin >> A >> B;
    C = add(A, B);
    cout << C << endl;
}