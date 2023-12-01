#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int value)
{
    struct node *NewNode = (struct node*)malloc(sizeof(struct node));
    NewNode->data = value;
    NewNode->left = NULL;
    NewNode->right = NULL;
    return NewNode;
}

struct node *insert(struct node *root,int value)
{
    if(root==NULL)
    return createNode(value);

    if(value < root->data){
        root->left = insert(root->left,value);
    }
    else if(value>root->data){
        root->right = insert(root->right,value);
    }
    //return root;
}

void InOrder(struct node *root){
    if(root==NULL)
    return;

    InOrder(root->left);
    printf("%d ",root->data);
    InOrder(root->right);
}

void PreOrder(struct node *root)
{
    if(root==NULL)
    return;

    printf("%d ",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(struct node *root)
{
    if(root==NULL)
    return;

    PreOrder(root->left);
    PreOrder(root->right);
    printf("%d ",root->data);
}

int main()
{
    struct node* root = NULL;
    int choice,value;

    while(1)
    {
        printf("BST Menu\n");
        printf("1. Insert Node\n");
        printf("2. Display Tree (In-order Traversal)\n");
        printf("3. Display Tree (Pre-order Traversal)\n");
        printf("4. Display Tree (Post-order Traversal)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    
    switch(choice)
    {
        case 1: 
                printf("Enter the value to insert : ");
                scanf("%d",&value);
                root = insert(root,value);
                break;

        case 2:
                printf("In-Order Traversal : ");
                InOrder(root);
                printf("\n");
                break;
            
        case 3:
                printf("Pre-Order Traversal : ");
                PreOrder(root);
                printf("\n");
                break;

        case 4: 
                printf("Post-Order Traversal : ");
                PostOrder(root);
                printf("\n");
                break;
            
        case 5:
                exit(1);

        default:
                printf("Invalid choice. Please try again.\n");

    }
    }
    return 0;
}