#include <stdio.h>
#include <stdbool.h>

bool find(int a,int b, int input, char op){
    int result = 0;
    switch(op){
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '/':
            result = a / b;
            break;
        case '*':
            result = a * b;
            break;
    }
    if(result == input) return true;
    else return false;
}

int main()
{
    int test = 0;
    scanf("%d", &test);
    for(int i = 0; i < test; i++){
        int a = 0,b = 0,input = 0;
        char operator;
        scanf("%d %c %d = %d", &a,&operator,&b,&input);
        if(find(a,b,input,operator) == true){
            printf("correct\n");
        }
        else{
            printf("wrong answer\n");
        }
    }
    return 0;
}