#include<stdio.h>
#include<ctype.h>
#define size 50
char stck[size];
int top=-1;
void push(char c){
    stck[++top]=c;
}
char pop(){
    return (stck[top--]);
}
int precedence(char c){
    switch(c){
        case '#':return 0;
        case '(':return 1;
        case '+':
        case '-':return 2;
        case '*':
        case '/':
        case '%':return 3;
        case '^':return 4;
        default :printf("invalid operator");
    }
}
int main(){
    char infix[size],postfix[size],ch,ele;
    int i=0,k=0;
    printf("\nenter the infix expression");
    scanf("%s",infix);
    push('#');
    while((ch=infix[i++])!='\0'){
        if(ch=='('){
            push(ch);
        }
       else if(isalnum(ch)){
            postfix[k++]=ch;
        }
        else if(ch==')'){
            while(stck[top]!='('){
                postfix[k++]=pop();
            }
            ele=pop();
        }
        else{
            while(precedence(stck[top])>=precedence(ch)){
                postfix[k++]=pop();
                
            }
            push(ch);
        }
    }
        while(stck[top]!='#'){
            postfix[k++]=pop();
        }
        postfix[k]='\0';
    printf("the postfix experssion is %s",postfix);

}