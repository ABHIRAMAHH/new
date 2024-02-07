#include<stdio.h>
#include<stdlib.h>
# define Size 5
int frount=-1,rear=-1;
int q[Size];
void insertion(int ele){
    if(frount==-1&&rear==-1){
        frount=0;
        rear=0;
        q[frount]=ele;
    }
    else if((rear+1)%Size==frount){
        printf("\nQueue is full");
    }
    else{
        rear=(rear+1)%Size;
        q[rear]=ele;
    }
}
void deletion(){
    if(frount==-1&&rear==-1){
        printf("\nQueue is empty");
    }
    else if(frount==rear){
        printf("\nthe last element %d is deleted",q[frount]);
        frount=-1;
        rear=-1;
    }
    else{
        printf("\n the element deleted is %d",q[frount]);
        frount=(frount+1)%Size;
    }
}
void display(){
         if(frount==-1&&rear==-1){
        printf("\nQueue is empty");
    }
    else{
        int i=frount,j=rear;
        while(i!=j){
            printf("\t%d",q[i]);
            i=(i+1)%Size;
        }
        printf("\t%d",q[i]);
    }
}
int main(){
    int ch,ele;
    while(1){
        printf("\nenter your choice");
        printf("\n1.insert");
        printf("\n2.delete");
        printf("\n3.display");
        printf("\n4.exit");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("\nenter the element to push");
            scanf("%d",&ele);
            insertion(ele);
            break;
            case 2:deletion();
            break;
            case 3:display();
            break;
            case 4:exit(0);
            default :printf("invalid choice");
        }
    }
}