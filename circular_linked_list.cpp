#include <iostream>
using namespace std;
class node
{
public:
    int data;
    class node *next;
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
node *insertfirst(node *head, int value)
{
    node *ptr = NULL;
    ptr = new node();
    ptr->data = value;
    node *temp = head->next;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}
node *insertlast(node *head, int value)
{
    node *ptr = NULL;
    ptr = new node();
    ptr->data = value;
    node *temp = head->next;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->next = head;
    return head;
}
node *insertindex(node *head, int value, int index)
{
    node *ptr = NULL;
    ptr = new node();
    ptr->data = value;
    node *temp = head->next;
    int i = 0;
    for (i = 0; i < index - 1; i++)
    {
        temp = temp->next;
        i++;
    }
    ptr->next = temp->next;
    temp->next = ptr;
    return head;
}
/*node *insertvalue(node *head, int value, int node)
{
    node* ptr=NULL;
    ptr=new node();
    ptr->data=value;
    node* temp=head->next;
    while (temp->data!=value && temp->next!=NULL)
    {
        temp=temp-next;
    }
    if (temp->data==value)
    {
        ptr->next=temp;
    }
    
    
}*/
int main()
{

    node *head = NULL;
    node *second = NULL;
    head = new node();
    second = new node();

    head->next = second;
    head->data = 1;

    second->data = 2;
    second->next = head;
    head = insertfirst(head, 5);
    head = insertlast(head, 6);
    head = insertindex(head, 8, 3);
    print(head);
    return 0;
}