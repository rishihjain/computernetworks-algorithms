#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
int data;
struct node *left;
struct node *right;
};

struct node *root;
void create_root(struct node *);
struct node *insertElement(struct node *, int);
void preorderTraversal(struct node *);
void inorderTraversal(struct node *);
void postorderTraversal(struct node *);
struct node *mirrorImage(struct node *);
int totalNodes(struct node *);
int Height(struct node *);
void displayLeafNodes(struct node *root);
struct node *deleteroot(struct node *);

int main()
{
int choice, val;
struct node *ptr;
create_root(root);
do
{
printf("\n ******MAIN MENU******* \n");
printf("\n 1. Insert Element");
printf("\n 2. Preorder Traversal");
printf("\n 3. Inorder Traversal");
printf("\n 4. Postorder Traversal");
printf("\n 5. Count the total number of nodes");
printf("\n 6. Determine the height of the root");
printf("\n 7. Find the mirror image of the root");
printf("\n 8. Display leaf nodes");
printf("\n 9. Delete the root");
printf("\n 10. Exit");
printf("\n\n Enter your choice : ");
scanf("%d", &choice);
switch(choice)  
 {
case 1:
printf("\n Enter the value of the new node : ");
scanf("%d", &val);
root = insertElement(root, val);
break;
case 2:
printf("\n The elements of the root are(preorder) : \n");
preorderTraversal(root);
break;
case 3:
printf("\n The elements of the root are(inorder): \n");
inorderTraversal(root);
break;
case 4:
printf("\n The elements of the root are(postorder) : \n");
postorderTraversal(root);
break;
case 5:
printf("\n Total no. of nodes = %d", totalNodes(root));
break;
case 6:
printf("\n The height of the root = %d",Height(root));
break;
case 7:
root = mirrorImage(root);
break;
case 8:
printf("\n Leaf nodes of the root are: \n");
displayLeafNodes(root);
break;
case 9:
root = deleteroot(root);
break;
 }
}while(choice!=10);
getch();
return 0;
}
void create_root(struct node *root)
{
root = NULL;
}
struct node *insertElement(struct node *root, int val)
{
struct node *ptr, *nodeptr, *parentptr;
ptr = (struct node*)malloc(sizeof(struct node));
ptr->data = val;
ptr->left = NULL;
ptr->right = NULL;
if(root==NULL)
{
root=ptr;
root->left=NULL;
root->right=NULL;
}
else
{
parentptr=NULL;
nodeptr=root;
while(nodeptr!=NULL)
 {
parentptr=nodeptr;
if(val<nodeptr->data)
nodeptr=nodeptr->left;
else
nodeptr = nodeptr->right;
 }
if(val<parentptr->data)
parentptr->left = ptr;
else
parentptr->right = ptr;
}
return root;
}
void preorderTraversal(struct node *root)
{
if(root != NULL)
{
printf("%d\t", root->data);
preorderTraversal(root->left);
preorderTraversal(root->right);
}
}
void inorderTraversal(struct node *root)
{
if(root != NULL)
{
inorderTraversal(root->left);
printf("%d\t", root->data);
inorderTraversal(root->right);
}
}
void postorderTraversal(struct node *root)
{
if(root != NULL)
{
postorderTraversal(root->left);
postorderTraversal(root->right);
printf("%d\t", root->data);
}
}
int totalNodes(struct node *root)
{
if(root==NULL)
return 0;
else
return(totalNodes(root->left) + totalNodes(root->right) + 1);
}

int Height(struct node *root)
{
int leftheight, rightheight;
if(root==NULL)
return 0;
else
{
leftheight = Height(root->left);
rightheight = Height(root->right);
if(leftheight > rightheight)
return (leftheight + 1);
else
return (rightheight + 1);
}
}
struct node *mirrorImage(struct node *root)
{
struct node *ptr;
if(root!=NULL)
{
mirrorImage(root->left);
mirrorImage(root->right);
ptr=root->left;
ptr->left = ptr->right;
root->right = ptr;
}
}
struct node *deleteroot(struct node *root)
{
if(root!=NULL)
{
deleteroot(root->left);
deleteroot(root->right);
free(root);
}
}

void displayLeafNodes(struct node *root) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%d\t", root->data);
    }
    displayLeafNodes(root->left);
    displayLeafNodes(root->right);
}

