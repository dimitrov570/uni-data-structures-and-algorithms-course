// Complete the deleteNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) 
{
    SinglyLinkedListNode* current=head;
    if(position==0)
    {
        SinglyLinkedListNode* tmp=head;
        head=head->next;
        delete tmp;
        return head;
    }
    for(int i=0;i<position-1;++i)
    {
        if(current==nullptr)
        {
            return head;
        }
        current=current->next;
    }
    if(current->next!=nullptr)
    {
    SinglyLinkedListNode* tmp=current->next;
    current->next=current->next->next;
    delete tmp;
    return head;
    }
    
    return head;
}
