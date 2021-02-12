#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *leftLink,*rightLink;
};
void insertBST(struct node **root,int data){
    struct node *newNode,*ptr; 
    newNode=(struct node *)malloc(sizeof(struct node));
    newNode->leftLink=NULL;
    newNode->rightLink=NULL;
    newNode->data=data; 
    if(*root==NULL){
        *root=newNode;
    }
    else{
        ptr=*root;
        while(1){
            if(newNode->data<ptr->data){
                if(ptr->leftLink==NULL){
                    ptr->leftLink=newNode;
                    break;
                }
                ptr=ptr->leftLink;
            }
            else if(newNode->data>ptr->data){
                if(ptr->rightLink==NULL){       
                    ptr->rightLink=newNode;
                    break;
                }
                ptr=ptr->rightLink;
            }
        }
    }
}
void preorder(struct node *root){
    if(root==NULL)
        return ;
    printf("%d ",root->data);
    preorder(root->leftLink);
    preorder(root->rightLink);
}
void postorder(struct node *root){
    if(root==NULL)
        return ;
    preorder(root->leftLink);
    preorder(root->rightLink);
    printf("%d ",root->data);
}
void inorder(struct node *root){
    if(root==NULL)
        return ;
    inorder(root->leftLink);
    printf("%d ",root->data);
    inorder(root->rightLink);
}
void main(){
    struct node *root=NULL;
    int dis,data;
    printf("1-INSERTION \n2-DELETION\n3-PREORDER\n4-POSTORDER\n5-INORDER\n6-EXIT\n");
    do{
        printf("\nENTER YOUR CHOICE : ");
        scanf("%d",&dis); 
        switch(dis){
            case 1:printf("Enter Value : ");
                    scanf("%d",&data);
                    insertBST(&root,data);
                    break;
            case 2:break;
            case 3:printf("PREORDER    : ");
                    preorder(root);
                    break;
            case 4:printf("\nPOSTOEDER : ");
                    postorder(root);
                    break;
            case 5:printf("\nINORDER   : ");
                    inorder(root);
                    break;
            case 6:break;
            
        }
    }while(dis!=6);
}