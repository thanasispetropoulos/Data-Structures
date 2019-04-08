#include <iostream>

using namespace std;

struct node{
    int key;
    struct node *l; //left subtree
    struct node *r;  //right subtree
};

class BinarySearchTree{
private:
    struct node *root;
    struct node* Insert(int k,struct node*  n){
        if(n==0){
            n=new struct node;
            n->key=k;
            n->l=0;
            n->r=0;
        }else if(k>n->key){
            n->r=Insert(k,n->r);
        }else if(k<n->key){
            n->l=Insert(k,n->l);
        }
    }
    void InOrder(struct node* n){
        if(n==0){
            return;
        }
        InOrder(n->l);
        cout<<n->key<<"\t";
        InOrder(n->r);
    }
    void PreOrder(struct node* n){
        if(n==0){
            return;
        }
        cout<<n->key<<"\t";
        InOrder(n->l);
        InOrder(n->r);
    }
    void PostOrder(struct node* n){
         if(n==0){
            return;
        }
        InOrder(n->l);
        InOrder(n->r);
        cout<<n->key<<"\t";
    }
    struct node* FindMin(struct node* n){
        if(n==0){
            return NULL;
        }else if(n->l==0){
            return n;
        }else{
            return FindMin(n->l);
        }
    }struct node* FindMax(struct node* n){
        if(n==0){
            return NULL;
        }else if(n->r==0){
            return n;
        }else{
            return FindMax(n->r);
        }
    }
    struct node* Remove(int k,struct node* n){
        struct node *temp;
        if(n==0){
            return 0;
        }else if(k<n->key){
            n->l=Remove(k,n->l);
        }else if(k>n->key){
            n->r=Remove(k,n->r);
        }else if(n->l==0&&n->r==0){
            temp = FindMin(n->l);
            n->key = temp->key;
            n->l = Remove(n->key,n->l);
        }else{
            temp=n;
            if(n->l==0)
                n=n->r;
            else if(n->r==0)
                n=n->l;
            delete temp;
        }
        return n;
    }
            
public:
    BinarySearchTree(){
        root=0;
    }
    void insert(int key){
        root=Insert(key,root);
    }
    void inorder(void){
        InOrder(root);
    }
    void preorder(void){
        PreOrder(root);
    }
    void postorder(void){
        PostOrder(root);
    }
    void remove(int key){
        root=Remove(key,root);
    }
};


int main(void){
    class BinarySearchTree bst;
    int a[9]={31,13,17,20,101,98,2,40,16};
    for(int i=0;i<9;i++){
        bst.insert(a[i]);
    }
    cout<<"Inorder"<<endl;
    bst.inorder();
    cout<<endl;
    cout<<"Preorder"<<endl;
    bst.preorder();
    cout<<endl;
    cout<<"Postorder"<<endl;
    bst.postorder();
    cout<<endl;
    bst.remove(101);
    bst.remove(13);
    cout<<"Inorder"<<endl;
    bst.inorder();
    cout<<endl;
    cout<<"Preorder"<<endl;
    bst.preorder();
    cout<<endl;
    cout<<"Postorder"<<endl;
    bst.postorder();
    cout<<endl;
    return 0;
}








            