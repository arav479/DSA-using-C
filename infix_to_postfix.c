#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

char peek()
{
    return stack[top];
}

int isoperator(char ch)
{
    return ch == '+' || ch == '-' ||
           ch == '*' || ch == '/';
}

int prec(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;

    if (ch == '*' || ch == '/')
        return 2;

    return 0;
}

int main()
{
    char infix[] = "A+B*C";
    char postfix[100];

    int i = 0, j = 0;

    char ch;

    while (infix[i] != '\0')
    {
        ch = infix[i];

        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }

        else if (isoperator(ch))
        {
            while (top != -1 &&
                   prec(peek()) >= prec(ch))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }

        i++;
    }

    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix: %s", postfix);

    return 0;
}