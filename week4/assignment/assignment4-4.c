//Pakkawat Kaolim 66070503446 
//Assignment 4.4 : Infix to Postfix

// 1. Scan the infix expression from left to right. 
// 2. If the scanned character is an operand, put it in the postfix expression. 
// 3. Otherwise, do the following 
// 	- If the precedence and associativity of the scanned operator are greater than the precedence and associativity of the operator in the stack [or the stack is empty or the stack contains a ‘(‘ ], then push it in the stack. [‘^‘ operator is right associative and other operators like ‘+‘,’–‘,’*‘ and ‘/‘ are left-associative].
// 		- Check especially for a condition when the operator at the top of the stack and the scanned operator both are ‘^‘. In this condition, the precedence of the scanned operator is higher due to its right associativity. So it will be pushed into the operator stack. 
// 		- In all the other cases when the top of the operator stack is the same as the scanned operator, then pop the operator from the stack because of left associativity due to which the scanned operator has less precedence. 
// 	- Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator.
// 		- After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.) 
// 4. If the scanned character is a "(" , push it to the stack. 
// 5. If the scanned character is a ")", pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis. 
// 6. Repeat steps 2-5 until the infix expression is scanned. 
// 7. Once the scanning is over, Pop the stack and add the operators in the postfix expression until it is not empty.
// 8. Finally, print the postfix expression.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STRING_MAX 1000

bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int GetOperatorPrior(char cur){
    if(cur == '^')
        return 4;
    else if(cur == '*' || cur == '/')
        return 3;
    else if(cur == '+' || cur == '-')
        return 2;
    else if(cur == '(' || cur == ')')
        return 1;
    else
        return 0;
}

void push(char *st, int *top, char value){
    (*top)++;
    st[*top] = value;
}

char pop(char *st,int *top){
    (*top)--;
    return st[*top + 1];
}

char *InfixToPostfix(char *string){
    char stack[STRING_MAX];
    int top = -1;

    char *PostFix = (char *)malloc(sizeof(char) * STRING_MAX);
    int index = 0;

    int isInParen = 0;
    while(*string){

        if(isOperator(*string)){
            while(top >= 0 && GetOperatorPrior(*string) <= GetOperatorPrior(stack[top])) //until it stay at same lvl
                PostFix[index++] = pop(stack, &top);
            push(stack, &top, *string);
        }else if(GetOperatorPrior(*string) == 1){ //paren case
            if(isInParen){
                while(GetOperatorPrior(stack[top]) != 1){
                    PostFix[index++] = pop(stack, &top);
                    isInParen = 0;
                }
                pop(stack, &top);
            }else{
                push(stack, &top, *string);
                isInParen = 1;
            }
        }else{
            PostFix[index++] = *string;
        }
        string++;
    }

    while (top >= 0){
        PostFix[index++] = pop(stack, &top);
    }
    PostFix[index] = '\0';

    return PostFix;
}

int main(void){
    char equation[STRING_MAX];
    scanf("%s", equation);
    printf("%s", InfixToPostfix(equation));
    return 0;
}