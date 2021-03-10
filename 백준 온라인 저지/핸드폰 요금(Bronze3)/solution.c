#include <stdio.h>

int main()
{
    int number, s[20], total, mquot, yqout, young, m = 0, y = 0;
    scanf("%d", &number);
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &s[i]);
    }
    for (int i = 0; i < number; i++)
    {
        yqout = s[i] / 30;
        if ((s[i] % 30) >= 0)
        {
            y += 10;
        }
        y += yqout * 10;
        mquot = s[i] / 60;
        if ((s[i] % 60) >= 0)
        {
            m += 15;
        }
        m += mquot * 15;
    }
    if (m == y)
    {
        printf("Y M %d", y);
        return 0;
    }
    printf("%s %d", (m < y) ? "M" : "Y", (m < y) ? m : y);
    return 0;
}