#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
};
void print(node *head)
{
    node *ptr = head;
    do
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}
node* delbeg(node* head){
    node* ptr=head;
    head=head->next;
    free(ptr);
    return head;

}
node* dellast(node* head){
    node* p=head;
    node* q=head->next;
    while (q->next!=head)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
    
}
node* delindex(node* head,int index){
    node* p=head;
    node* q=head->next;
    int i=0;
    for ( i = 0; i < index-1; i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
    
}
node* delvalue(node* head,int value){
    node* p=head;
    node* ptr=head;
    node* q=head->next;
    while (q->data!=value && q->next!=NULL)
    {
        p=p->next;
        q=q->next;

    }
    if(q->data==value){
        p->next=q->next;
        free(q);
    }
    /*if(p->data==value){
        head=head->next;
        free(ptr);

    }*/

    return head;
}
int main(){

    node *head = NULL;
    node *second = NULL;
    node* third=NULL;
    third=new node();
    head = new node();
    second = new node();

    head->next = second;
    head->data = 1;

    second->data = 2;
    second->next = third;

    third->data=3;
    third->next=head;
    //head=delbeg(head);
    //head=dellast(head);
    //head=delindex(head,1);
    head=delvalue(head,2);
    print(head);
}