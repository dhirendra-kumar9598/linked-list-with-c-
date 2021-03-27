#include <iostream>
using namespace std;
class node
{
public:
    int data;
    class node *pre;
    class node *next;
};
class node *head = NULL;
void print()
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

void inserbeg(int value)
{
    node *ptr = NULL;
    ptr = new node();
    ptr->data = value;
    ptr->pre = NULL;
    if (head == NULL)
    {
        ptr->next = NULL;
        head = ptr;
    }
    else
    {
        ptr->next = head;
        head->pre = ptr;
        head = ptr;
    }
}
void insertlast(int value)
{
    node *ptr = new node();
    ptr->data = value;
    node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->pre = p;
    ptr->next = NULL;
}
void addindex(int index,int value){
    node* ptr=new node();
    ptr->data=value;
    node* p=head;
    int i=0;
   for (i = 0; i < index-1; i++)
   {
       p=p->next;
   }
   ptr->next=p->next;
   p->next=ptr;
   ptr->pre=p;
   
    

}
void insertvalue(int val,int value){
    node* ptr=new node();
    ptr->data=value;
    node* p=head;
    while (p->data!=val && p->next!=NULL)
    {
        p=p->next;
    }
    if (p->data==val)
    {
        ptr->next=p->next;
        ptr->pre=p;
        p->next=ptr;
    }
    else{
        cout<<"the value doesn't exist"<<endl;
    }
    
    
}
void delbeg(){
    node*p=head;
    head=head->next;
    free(p);
}
void dellast(){
    node*p=head;
    node* q=head->next;
    while (q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    
}
void delindex(int index){
    node* p=head;
    node* q=head->next;
    int i=0;
    for ( i = 0; i < index-1; i++)
    {
        p=p->next;
        q=q->next;
    }
    p=q->next;
    free(q);
    
}
void delvalue(int value){
    node* p=head;
    node* q=head->next;
    while (q->data!=value && q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    if (q->data==value)
    {
        p=q->next;
        free(q);
    }
    if (head->data==value)
    {
        head=head->next;
        free(p);
    }
    else{
        cout<<"not found"<<endl;
    }
    
    
    
}
int main()
{
   
    inserbeg(1);
    inserbeg(4);
    insertlast(2);
    addindex(2,9);
    insertvalue(4,10);
    //delbeg();
    //dellast();
    //delindex(2);
    delvalue(1);
    print();


    return 0;
}