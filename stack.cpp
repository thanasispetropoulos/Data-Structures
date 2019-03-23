#include <iostream>
#include <string.h>

using namespace std;

struct node{
    string str;
    struct node* next;
};

class Stack{
private:
    struct node *top,*temp;
public:
    Stack(){
        top=new struct node;
        top->next=0;
    }
    void push(string s){
        temp=new struct node;
        temp->str=s;
        temp->next=top;
        top=temp;
    }
    void pop(void){
        temp=new struct node;
        temp=top;
        top=top->next;
        delete temp;
    }
    void print(void){
        struct node *temp2;
        temp2=new struct node;
        temp2=top;
        do{
            cout<<temp2->str<<endl;
            temp2=temp2->next;
        }while(temp2->next!=0);
    }
};

int main(void){
    class Stack stack;
    string s;
    cin>>s;
    while(s!="0"){
        stack.push(s);
        cin>>s;
    }
    stack.pop();
    stack.print();
    return 0;
}
    