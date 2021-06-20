// 10026번 : 적록색약

#include <stdio.h>
#define MAX 101

int graph[MAX][MAX];
int visited[MAX][MAX];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void clearVisitedArray()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            visited[i][j] = 0;
        }
    }
}

int countForNotRGB; // 적록색약이 아닌 사람
int countForRGB;    // 적록색약인 사람

void floodfillForNotRGB(int x, int y, int value)
{
    visited[x][y] = 1;
    int newX, newY;
    for (int i = 0; i < 4; i++)
    {
        newX = x + dx[i];
        newY = y + dy[i];
        if (0 <= newX && newX <= MAX && 0 <= newY && newY <= MAX)
        {
            if (visited[newX][newY] == 0 && graph[newX][newY] == value)
            {
                floodfillForNotRGB(newX, newY, value);
            }
        }
    }
}

void floodfillForRGB(int x, int y)
{
    visited[x][y] = 1;
    int newX, newY;
    for (int i = 0; i < 4; i++)
    {
        newX = x + dx[i];
        newY = y + dy[i];
        if (0 <= newX && newX <= MAX && 0 <= newY && newY <= MAX)
        {
            if (visited[newX][newY] == 0 && (graph[newX][newY] == 1 || graph[newX][newY] == 2))
            {
                floodfillForRGB(newX, newY);
            }
        }
    }
}

int main()
{
    int n;
    int red = 0, blue = 0, green = 0;
    char arr[MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr);
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == 'R')
            {
                graph[i][j] = 1;
            }
            else if (arr[j] == 'G')
            {
                graph[i][j] = 2;
            }
            else
            {
                graph[i][j] = 3;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 0 && graph[i][j] == 1)
            {
                floodfillForNotRGB(i, j, 1);
                red++;
            }
            if (visited[i][j] == 0 && graph[i][j] == 2)
            {
                floodfillForNotRGB(i, j, 2);
                green++;
            }
            if (visited[i][j] == 0 && graph[i][j] == 3)
            {
                floodfillForNotRGB(i, j, 3);
                blue++;
            }
        }
    }
    clearVisitedArray();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 0 && (graph[i][j] == 1 || graph[i][j] == 2))
            {
                floodfillForRGB(i, j);
                countForRGB++;
            }
        }
    }
    printf("%d ", red + green + blue);
    printf("%d\n", countForRGB + blue);
    return 0;
}