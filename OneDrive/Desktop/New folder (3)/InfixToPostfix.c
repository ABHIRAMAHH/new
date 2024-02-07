#include<stdio.h>
#include<ctype.h>
#define max 50
char s[max];
int top=-1;
void push(char item){
    s[++top]=item;
}
char pop(){
    return (s[top--]);
}
int pr(char item){
    switch(item){
     case '#':return 0;
     case '(':return 1;
     case '+':
     case '-':return 2;
     case '*':
     case '/':
     case '%':return 3;
     case '^':return 4;
     default :printf("\n invalid operators");
    }
}
void main(){
    char infix[50],postfix[50],ch,ele;
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
            while(s[top]!='('){
                postfix[k++]=pop();
            }
            ele=pop();
         }
         else{
            while(pr(s[top])>=pr(ch)){
                postfix[k++]=pop();
            } 
                push(ch);
            
         }
    }
    while(s[top]!='#')
        postfix[k++]=pop();
        postfix[k]='\0';
    
    printf("%s",postfix);
}