#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    stack[++top] = value;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char postfix[100];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    int i = 0;

    while (postfix[i] != '\0')
    {
        char ch = postfix[i];

        // If operand
        if (isdigit(ch))
        {
            push(ch - '0');
        }

        // If operator
        else
        {
            int b = pop();
            int a = pop();

            int result;

            switch (ch)
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':

                    if (b == 0)
                    {
                        printf("Error: Division by zero\n");
                        return 1;
                    }

                    result = a / b;
                    break;

                case '^':
                    result = pow(a, b);
                    break;

                default:
                    printf("Invalid operator\n");
                    return 1;
            }

            push(result);
        }

        i++;
    }

    printf("Result = %d\n", pop());

    return 0;
}