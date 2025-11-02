#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node_t;

node_t* create_node(int value)
{
    node_t* new_node=(node_t*)malloc(sizeof(node_t));
    
    if(new_node == NULL)
    {
        perror("memory allocation failed");
        exit(EXIT_FAILURE);
    }
    
    new_node->data =value;
    new_node->left =NULL;
    new_node->right = NULL;
    return new_node;
}

node_t* insert(node_t* root,int value)
{
    if(root ==NULL)
    {
        return create_node(value);
    }
    
    if(value <root->data)
    {
        root->left =insert(root->left,value);
        
    }
    else
    {
        root->right = insert(root->right,value);
    }
    
    return root;
}


void inorder(node_t* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        
        printf("%d  ",root->data);
        
        inorder(root->right);
    }
}

int main()
{
    node_t* root=NULL;
    printf("inserting elements 10 20 30 40 50 60 80\n");
    root=insert(root,50);
    insert(root,30);
    insert(root,70);
    insert(root,20);
    insert(root,40);
    insert(root,60);
    insert(root,80);
    printf("inoder travel\n");
    
    inorder(root);
    printf("\n");
    return 0;
}
