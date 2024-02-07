#include<stdio.h>
#include<stdlib.h>
int count=0;
struct node{
    int data;
    struct node *next,*pre;
}*temp=NULL,*temp1=NULL,*temp2=NULL,*head=NULL;
void create(){
    int data;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nenter the data to insert");
    scanf("%d",&data);
    temp->data=data;
    temp->next=NULL;
    temp->pre=NULL;
    count++;
}
void insertbeg(){
    create();
    if(head==NULL){
        head=temp;
        temp1=head;
    }
    else{
        temp->next=head;
        head->pre=temp;
        head=temp;
    }
}
void insertEnd(){
    create();
    if(head==NULL){
        head=temp;
        temp1=head;
    }
    else{
        temp1->next=temp;
        temp->pre=temp1;
        temp1=temp;
    }
}
void deletebeg(){
     if(head==NULL){
       printf("the list is empty");
    }
    else{
        temp2=head;
        head=head->next;
        head->pre=NULL;
        temp2->next=NULL;
        free(temp2);
        count=count-1;
    }
}
void deleteEnd(){
    if(head==NULL){
       printf("the list is empty");
    }
    else{
        temp2=temp1;
        temp1=temp1->pre;
        temp1->next=NULL;
        temp2->pre=NULL;
        free(temp2);
    }
}
void displayForward(){
    if(head==NULL){
       printf("the list is empty");
    }
    else{
        temp2=head;
        while(temp2!=NULL){
            printf("\t%d",temp2->data);
            temp2=temp2->next;
        }
        printf("\n");
    }
}
void displayBackward(){
    if(head==NULL){
       printf("the list is empty");
    }
    else{
        temp2=temp1;
        while(temp2!=NULL){
            printf("\t%d",temp2->data);
            temp2=temp2->pre;
        }
        printf("\n");
    }
}
int main(){
    int ch,n;
    while(1){
        printf("\n1.create a dll");
        printf("\n2.insert at beg");
        printf("\n3.insert at end");
        printf("\n4.delete at beg");
        printf("\n5.delete at end");
        printf("\n6.exit");
        printf("\n7.display Forward");
        printf("\ndisplay Backwards");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("\nenter the no of elements");
            scanf("%d",&n);
            for(int i=0;i<n;i++){
                insertbeg();
            }
            break;
            case 2:insertbeg();
            break;
            case 3:insertEnd();
            break;
            case 4:deletebeg();
            break;
            case 5:deleteEnd();
            break;
            case 6:exit(0);
            case 7:displayForward();
            break;
            case 8:displayBackward();
            break;
            default :printf("invalid choice");
        }
    }
}