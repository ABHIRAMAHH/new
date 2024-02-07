#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define Size 50
int top=-1;
int stck[Size];
char post[Size];
void pushStack(int );
void caliculate(char );
void main(){
    int i=0;
    printf("enter the postfix expression");
    scanf("%s",post);
    for(i=0;i<strlen(post);i++){
        if((post[i]<='9')&&(post[i]>='0')){
            pushStack(i);
        }
        if((post[i]=='+')||(post[i]=='-')||(post[i]=='*')||(post[i]=='/')){
            caliculate(post[i]);
        }
    }
    printf("the result of the postfix expression is %d",stck[top]);
}
void pushStack(int tmp){
    top=top+1;
    stck[top]=(int)(post[tmp]-48);
}
void caliculate(char c){
    int a,b,res;
    a=stck[top];
    stck[top]='\0';
    top=top-1;
    b=stck[top];
    stck[top]='\0';
    top--;
    switch(c){
        case '+':res=a+b;break;
        case '-':res=b-a;break;
        case '*':res=a*b;break;
        case '/':res=b/a;break;
        default :printf("invalid operator");
    }
    top=top+1;
    stck[top]=res;
}