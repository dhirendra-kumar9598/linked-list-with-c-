#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
void print(node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " " << endl;
        ptr = ptr->next;
    }
}
node* add(node *ptr, int value)
{
    node *new_node = NULL;
    new_node = new node();
    new_node->next=ptr;
    new_node->data = value;
    return new_node;
}
node* deletefirst(node* head){
    node* ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
node* deletelAtIndex(node* head,int index){
    node* p=head;
    node* q=head->next;
    for (int i = 0; i < index-1; i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}
node* deletelast(node* head){
    node* p=head;
    node* q=head->next;
    while (q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
    
}
node* deletevalue(node* head,int value){
    node* p=head;
    node* q= head->next;
    while (q->data!=value && q->next!=NULL)
    {
        p=p->next;
        q=q->next;

    }
    if (q->data==value)
    {
        p->next=q->next;
        free(q);
    }
    return head;
    
    
}
int main()
{
    node *head = NULL;
    node *second = NULL;
    node *third = NULL;
    node *fifth = NULL;
    node *ten = NULL;

    head = new node();
    second = new node();
    third = new node();
    fifth = new node();
    ten = new node();

    head->data = 2;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 4;
    third->next = ten;

    ten->data = 10;
    ten->next = fifth;

    fifth->data = 5;
    fifth->next = NULL;

    
    
    //head=add(head,9);
    //head=deletefirst(head);
    //head=deletelAtIndex(head,3);
    //head=deletelast(head);
    head=deletevalue(head,5);

    print(head);
}