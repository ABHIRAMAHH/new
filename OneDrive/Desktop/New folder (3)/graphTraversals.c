#include<stdio.h>
#include<stdlib.h>
int a[50][50],q[20],visited[50],s[20],frount=-1,rear=-1,top=-1,count=0,n;
void bfs(int v){
    int cur,i;
    q[++rear]=v;
    visited[v]=1;
    while(frount!=rear){
        cur=q[++frount];
    for(i=1;i<=n;i++){
       if((a[cur][i]==1)&&(visited[i]==0)){
        printf("\t%d",i);
        q[++rear]=i;
        visited[i]=1;
       }
    }
    }
}
void create(){
    printf("Enter the value of n");
    scanf("%d",&n);
    printf("enter the nxn matrix");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
}
void dfs(int v){
    visited[v]=1;
    s[++top]=v;
    for(int i=1;i<=n;i++){
        if((a[v][i]==1)&&visited[i]==0){
            dfs(i);
            count++;
        }
    }
}
int main(){
    int ch,start;
    create();
    while(1){
        printf("\n1.bfs");
        printf("\n2.dfs");
        printf("3.exit");
        printf("\n enter your option");
        scanf("%d",&ch);
        switch(ch){
            case 1:for(int i=1;i<=n;i++){
                visited[i]=0;
            }
             printf("\nenter the starting vertex");
             scanf("%d",&start);
             bfs(start);
             printf("\n bodes which are not reachable");
             for(int i=1;i<=n;i++){
                if(visited[i]==0){
                    printf("\t%d",i);
                }
             }
             break;
             case 2:for(int i=1;i<=n;i++){
                visited[i]=0;
            }
             printf("\nenter the starting vertex");
             scanf("%d",&start);
             dfs(start);
             printf("\n nodes not reachable");
             for(int i=1;i<=n;i++){
                if(visited[i]==0){
                    printf("\t%d",i);
                }
             }
             break;
            case 3:exit(0);
            default :printf("\ninvalid option");
        }
    }
}