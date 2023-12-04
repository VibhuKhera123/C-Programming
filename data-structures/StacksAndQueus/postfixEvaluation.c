#include<stdio.h>
int stack[100];
int top = -1;
void push(int x)
{
    stack[++top] = x;
}
int pop()
{
    return stack[top--];
}
int main()
{
    char exp[100];
    char *element;
    int n1,n2,n3,num;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    element = exp;
    while(*element != '\0')
    {
        if(isdigit(*element))
        {
            num = *element - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(*element)
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push(n3);
        }
        element++;
    }
    printf("\nThe result of expression %s  =  %d\n\n",exp,pop());
    return 0;
}

