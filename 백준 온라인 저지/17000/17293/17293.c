
#include <stdio.h>

int main()
{
    int K;
    scanf("%d", &K);
    for (int i = K; i >= 0; i--)
    {
        if (i > 2)
        {
            printf("%d bottles of beer on the wall, %d bottles of beer.\n", i, i);
            printf("Take one down and pass it around, %d bottles of beer on the wall.\n\n", i - 1);
        }
        else if (i == 2)
        {
            printf("2 bottles of beer on the wall, 2 bottles of beer.\n");
            printf("Take one down and pass it around, 1 bottle of beer on the wall.\n\n");
        }
        else if (i == 1)
        {
            printf("1 bottle of beer on the wall, 1 bottle of beer.\n");
            printf("Take one down and pass it around, no more bottles of beer on the wall.\n\n");
        }
    }
    printf("No more bottles of beer on the wall, no more bottles of beer.\n");
    if (K == 1)
        printf("Go to the store and buy some more, 1 bottle of beer on the wall.\n");
    else
        printf("Go to the store and buy some more, %d bottles of beer on the wall.\n", K);
    return 0;
}