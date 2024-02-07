#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define Size 5
int arr[Size];
int top=-1;
void push(int ele){
    if(top>=Size-1){
        printf("\nStack overflow");
    }
    else{
        top=top+1;
        arr[top]=ele;
    }
}
void pop(){
    if(top<0){
        printf("\nStack under flow");
    }
    else{
        printf("\nthe deleted item is %d",arr[top]);
        top=top-1;
    }
}
void display(){
    if(top==-1){
        printf("empty stack");
    }
    else{
        for(int i=top;i>=0;i--){
            printf("\t%d",arr[i]);
        }
    }
}
void checkpalindrome(){
     int rev[Size],j=0,Len=top+1;
     for(int k=top;k>=0;k--,j++){
        rev[k]=arr[j];
     }
     for(j=0;j<Len;j++){
        if(arr[j]!=rev[j]){
            break;
        }
     }
     if(j==Len){
        printf("\npalindrome");
     }
     else{
        printf("\nnot a palindrome");
     }
}
int main(){
    int ch,ele;
    while(1){
        printf("\nenter your choice");
        printf("\n1.push");
        printf("\n2.pop");
        printf("\n3.display");
        printf("\n4.exit");
        printf("\n5.check palindrome");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("\nenter the element to push");
            scanf("%d",&ele);
            push(ele);
            break;
            case 2:pop();
            break;
            case 3:display();
            break;
            case 4:exit(0);
            case 5:checkpalindrome();
            break;
            default :printf("invalid choice");
        }
    }
}