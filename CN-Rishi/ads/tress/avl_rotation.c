#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node 
{
    int data;
    struct node *left , *right;
    int height;
};

struct node *root = NULL;
struct node *FindMax (struct node *root)
{
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *FindMin (struct node *root)
{
    while (root -> left !=NULL){
        {
            root = root->left;
        }
        return root;
    }
}

struct node *getnewnode(int data)
{
    struct node *NewNode;
    NewNode = (struct node*)malloc(sizeof(struct node));
    NewNode->data = data;
    NewNode->right = NULL;
    NewNode->left = NULL;
    return NewNode ;
}

int Max (int n1,int n2)
{
    return n1>n2 ? n1 :n2;
}

int getHeight (struct node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return root->height;
}

int getBalancefactor(struct node *root)
{
    if(root==NULL)
    return 0;
    return getHeight(root->left)- getHeight(root->right);
}

struct node *rightrotate(struct node *root)
{
    // Store pointers to the root's left child and the left child's right child
    struct node *leftChild = root->left;
    struct node *leftrightChild = leftChild->right;

    // Perform the right rotation
    leftChild->right = root;
    root->left = leftrightChild;
    
    root->height = Max(getHeight(root->left),getHeight(root->right))+1;
    leftChild->height = Max(getHeight(leftChild->left),getHeight(leftChild->right))+1;
    return leftChild;
}

struct node *leftrotate(struct node *root)
{
    struct node *rightChild = root->right;
    struct node *rightleftChild = rightChild->left;

    rightChild->left = root;
    root->right = rightleftChild;
    root->height=Max(getHeight(root->left),getHeight(root->right))+1;
    rightChild->height = Max(getHeight(rightChild->left),getHeight(rightChild->right)) + 1;
    return rightChild;
}

struct node *insert(struct node *root, int data)
{
    if(root==NULL)
    {
        root= getnewnode(data);
        return root;
    }
    if(data<root->data)
    {
        root->left = insert(root->left,data);
    }
    if(data>root->data)
    {
        root->right = insert(root->right,data);
    }
    else{
        return root;
    }
    root->height = Max(getHeight(root->left),getHeight(root->right))+1;
    int bf = getBalancefactor(root);
    if(bf>1 && data < root->left->data) //left-left
    {
        return rightrotate(root);
    }
    if(bf<-1 && data >root->right->data) //right-right
    {
        return leftrotate(root);
    }
    if(bf>1 && data >root->left->data) //left-right
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if(bf<-1 && data<root->right->data) //right-left
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}

struct node *delete(struct node *root , int data)
{
    if(root==NULL)
    {
        return root;
    }
    if(data < root->data)
    {
        root->left = delete(root->left , data);
    }
    if(data > root->data)
    {
        root->right = delete(root->right , data);
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
    {
        free(root);
        root=NULL;
        return root;
    }
    if(root->left==NULL)
    {
        struct node *temp = root;
        root = root->right;
        free(temp);
        return root;
    }
    if(root->right==NULL)
    {
        struct node *temp = root;
        root = root->left;
        free(temp);
        return root;
    }
    struct node *temp = FindMin(root->right);
    root->data = temp->data;
    root->right = delete(root->right,temp->data);
    }
    root->height = Max(getHeight(root->left),getHeight(root->right))+1;
    int bf = getBalancefactor(root);
    if(bf>1 && getBalancefactor(root->left)>=0)  //left-left
    {
        return rightrotate(root);
    }
    if(bf>1 && getBalancefactor(root->left)<0) // left-right
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if(bf<-1 && getBalancefactor(root->right)<=0)  //right-left
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
    if(bf<-1 && getBalancefactor(root->right) >0)  //right-right
    {
        return leftrotate(root);
    }
    return root;
    printf("Node deleted");  
}

int countNodes(struct node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return countNodes(root->left)+countNodes(root->right)+1;
}

void search(struct node *root , int data)
{
    if(root==NULL)
    {
        printf("Element not found");
        return;
    }
    if(data == root->data)
    {
        return;
    }
    if(data<root->data)
    {
        search(root->left,data);
        
    }
    else{
        search(root->right,data);
       
    }
}

void Inorder(struct node *root)
{
    if(root!=NULL)
    {
        Inorder(root->left);
        printf("%d",root->data);
        Inorder(root->right);
    }

}

void display(struct node *root, int space)
{
if (root == NULL)
{
return;
}
space += 10;
display(root->right, space);
printf("\n");
for (int i = 10; i < space; i++)
{
printf(" ");
}
printf("%d\n", root->data);
display(root->left, space);
}

int main(){
struct node *temp;
int data, choice, val, i;
printf("AVL tree Implementation :\n");
printf("1.Insert\n");
printf("2.Delete\n");
printf("3.Search\n");
printf("4.Height\n");
printf("5.Inorder\n");
printf("6.Total number of nodes\n");
printf("7.Display\n");
printf("8.EXIT\n");
while (1)
{
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice)
{
case 1:
printf("Enter the data to be inserted: ");
scanf("%d", &data);
root = insert(root, data);
break;
case 2:
printf("Enter the data to be deleted: ");
scanf("%d", &data);
root = delete (root, data);
break;
case 3:
printf("Enter the data to be searched: ");
scanf("%d", &val);
search(root, val);
break;
case 4:
printf("Height of the tree is %d\n", getHeight(root));
break;
case 5:
printf("INORDER: ");
Inorder(root);
printf("\n");
break;
case 6:
printf("Total number of nodes in the tree is %d\n", countNodes(root));
break;
case 7:
display(root, 0);
break;
case 8:
exit(0);
default:
printf("Wrong choice\n");
};
}
return 0;
}


