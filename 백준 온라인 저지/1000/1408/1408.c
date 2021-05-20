// 1408번 : 24

#include <stdio.h>

typedef struct
{
    int hour;
    int minute;
    int second;
} Time;

void printTime(int hour, int minute, int second)
{
    printf("%02d:%02d:%02d", hour, minute, second);
}

int main()
{
    Time h1, h2;
    Time result;
    scanf("%d:%d:%d", &h1.hour, &h1.minute, &h1.second);
    scanf("%d:%d:%d", &h2.hour, &h2.minute, &h2.second);
    result.hour = h2.hour - h1.hour;
    result.minute = h2.minute - h1.minute;
    result.second = h2.second - h1.second;
    if (result.second < 0)
    {
        result.second += 60;
        result.minute--;
    }
    if (result.minute < 0)
    {
        result.minute += 60;
        result.hour--;
    }
    if (result.hour < 0)
    {
        result.hour += 24;
    }
    printTime(result.hour, result.minute, result.second);
    return 0;
}