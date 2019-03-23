#include <iostream>
#include <string>

using namespace std;

struct node{
    string str;
    struct node* next;
};


class Queue{
private:
    struct node *tail,*head,*temp;
public:
    Queue(){
        head=new struct node;
        tail=new struct node;
        head->str="";
        head->next=tail;
        tail->next=0;
    }
    void enqueue(string s){
        temp=new struct node;
        temp->str=s;
        temp->next=0;
        tail->next=temp;
        tail=temp;
    }
    void dequeue(void){
        temp=new struct node;
        temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=0;
        tail=temp;
    }
    void print(void){
        temp=new struct node;
        temp=head->next;
        while(temp!=0){
            cout<<temp->str<<endl;
            temp=temp->next;
        }
    }
};


int main(void){
    string s;
    class Queue queue;
    cin>>s;
    while(s!="0"){
        queue.enqueue(s);
        cin>>s;
    }
    queue.dequeue();
    queue.print();
}