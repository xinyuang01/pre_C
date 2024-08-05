// #define IN 1
// #define HASHSIZE 101

// typedef static struct nlist{
//     struct nlist* next;
//     char* name;
//     char* data;
// }Nlist;

// Nlist *hashtab[HASHSIZE];
#include <stdio.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

//通过根出现的位置决定了先 中 后序
//先序 根->左->右
void preorder(Node *node){
    if(node!=NULL){
        printf("%d\n",node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

//中序 左->根->右
void inorder(Node *node){
    if(node!=NULL) {
        inorder(node->left);
        printf("%d\n",node->data);
        inorder(node->right);
    }
}

//后序 左->右->根
void postorder(Node *node){
    if(node!=NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%d\n",node->data);
    }
}

int main(){
    Node n1;
    Node n2;
    Node n3;
    Node n4;
    Node n5;

    n1.data=5;
    n2.data=6;
    n3.data=7;
    n4.data=8;
    n5.data=9;

    n1.left=&n2;
    n1.right=&n3;
    n2.left=&n4;
    n2.right=NULL;
    n3.left=NULL;
    n3.right=&n5;
    n4.left=n4.right=NULL;
    n5.left=n5.right=NULL;
    
    printf("This is preorder:\n");
    preorder(&n1);
    printf("This is inorder:\n");
    inorder(&n1);
    printf("This is postorder:\n");
    postorder(&n1);
}

