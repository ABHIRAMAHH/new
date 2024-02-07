#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head=NULL,*temp=NULL,*temp1=NULL,*temp2=NULL;
void create(){
    int data;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nenter the dats to be inserted");
    scanf("%d",&data);
    temp->data=data;
    temp->next=NULL;
}
void insertFrount(){
    create();
    if(head==NULL){
        head=temp;
    }
    else{
        temp->next=head;
        head=temp;
    }
}
void insertEnd(){
    create();
    struct node *temp1;
    temp1=head;
    if(head==NULL){
        head=temp;
    }
    else{
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=temp;

    }
}
void deletebeg(){
    if(head==NULL){
        printf("\nempty list");
    }
    else{
        struct node *temp1;
        printf("the element deleted is %d",head->data);
        temp1=head;
        head=head->next;
        free(temp1);
    }
}
void deleteEnd(){
    if(head==NULL){
        printf("\nempty list");
    }
    else{
        temp1=head;
        while(temp1->next!=NULL){
            temp2=temp1;
            temp1=temp1->next; // Issue is here
        }
        printf("\n the deleted item is %d",temp1->data);
        temp2->next=NULL;
        free(temp1);
    }
}
void display(){
    if(head==NULL){
        printf("\nempty list");
    }
    else{
      struct node *temp1;
      temp1=head;
      while(temp1!=NULL){
        printf("\t%d",temp1->data);
        temp1=temp1->next;
      }
    }
}
int main(){
    int ch,n;
    while(1){
        printf("\n1.create a sll");
        printf("\n2.insert at beg");
        printf("\n3.insert at end");
        printf("\n4.delete at beg");
        printf("\n5.delete at end");
        printf("\n6.exit");
        printf("\n7.display");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("\nenter the no of elements");
            scanf("%d",&n);
            for(int i=0;i<n;i++){
                insertFrount();
            }
            break;
            case 2:insertFrount();
            break;
            case 3:insertEnd();
            break;
            case 4:deletebeg();
            break;
            case 5:deleteEnd();
            break;
            case 6:exit(0);
            case 7:display();
            break;
            default :printf("invalid choice");
        }
    }
}