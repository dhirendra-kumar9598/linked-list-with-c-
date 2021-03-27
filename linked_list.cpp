#include <iostream>
using namespace std;
class node {
    public:
   int data;
   node* next;
};
class node* insertbeg(node* head,int value){
    node* ptr=NULL;
    ptr=new node();
    ptr->data=value;
    ptr->next=head;
    return ptr;
}
class node* insertindex(node* head,int value,int index){
    node* ptr=NULL;
    ptr=new node();
    ptr->data=value;
    node* p=head;
    int i=0;
    while (i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
class node* insertend(node* head,int value){
    node* ptr=NULL;
    ptr=new node();
    ptr->data=value;
    node* p=head;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
class node* insert_at_node(node* head,node* prev_node,int value){
    node* ptr=NULL;
    ptr=new node();
    ptr->data=value;
    node* p=head;
    ptr->next=prev_node->next;
    prev_node->next=ptr;
    return head;
}
void printlist(node* ptr){
    while (ptr!=NULL)
    {
        cout<<ptr->data<<" "<<endl;
        ptr=ptr->next;
    }

}
int main(){
    node* head=NULL;
    head=new node();
     node* second=NULL;
    second=new node();
    head->data=1;
    head->next=second;
   
    second->data=2;
    second->next=NULL;
    //head=insertbeg(head,3);
    //head=insertindex(head,8,2);
    //head=insertend(head,10);
    //head=insert_at_node(head,second,90);
    printlist(head);

}