#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
    int cf,px,py;
    struct node *next;
}*temp=NULL,*first=NULL,*temp2=NULL;
void insert_poly(int cf,int px,int py){
    
    temp2=(struct node*)malloc(sizeof(struct node));
   
       temp2->px=px;
        temp2->py=py;
        temp2->cf=cf;
        temp2->next=NULL; 
        if(first==NULL){
            first=temp2;
        }
        else{
            temp=first;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=temp2;
        }
        
   
}
void display(){
    temp=first;
    printf("\n");
    if(first==NULL){
        printf("empty");
    }
    while(temp!=NULL){
        if(temp->cf>0){
            printf("+%d",temp->cf);
        }
        else{
            printf("%d",temp->cf);
        }
        if(temp->px==1){
            printf("X");
        }
        else{
            printf("X^%d",temp->px);
        }
        if(temp->py==1){
            printf("Y");
        }
        else{
            printf("Y^%d\t",temp->py);
        }
        temp=temp->next;
    }
}
int evaluate(){
    int x,y,sum=0;
    printf("\nEnter the values of x and y");
    scanf("%d %d",&x,&y);
    temp=first;
    while(temp!=NULL){
        sum=sum+(temp->cf*pow(x,temp->px)*pow(y,temp->py));
        temp=temp->next;
    }
    return sum;
}

int main(){
    int cf,px,py;
    while(1){
     printf("\nenter the value of cf");
     scanf("%d",&cf);
     if(cf==0){
        break;
     }
     printf("\nEnter the power of x");
     scanf("%d",&px);
     printf("\nenter the power of y");
     scanf("%d",&py);
     insert_poly(cf,px,py);
    }
    display();
    int sum=evaluate();
    printf("\n the result of the polynomial is %d",sum);
}