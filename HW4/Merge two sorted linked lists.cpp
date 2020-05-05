// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) 
{
    if(head1==nullptr)
    {
        return head2;
    }
    else if(head2==nullptr)
    {
        return head1;
    }
    
    SinglyLinkedListNode* current1=head1;
    SinglyLinkedListNode* current2=head2;
    SinglyLinkedListNode* tmp;
    SinglyLinkedListNode* head;
    if(head1->data > head2->data)
    {
        head = tmp = head2;
        current2=current2->next;
    }
    else
    {
        head = tmp = head1;
        current1=current1->next;
    }
    
    while(current1!=nullptr && current2!=nullptr)
    {
     if(current1->data<=current2->data)
     {
        tmp=tmp->next=current1;
         current1=current1->next;
     }
     else
     {
       tmp=tmp->next=current2;
         current2=current2->next;
     }
    }
    while(current1!=nullptr)
    {
        tmp=tmp->next=current1;
         current1=current1->next;
    }
    while(current2!=nullptr)
    {
        tmp=tmp->next=current2;
         current2=current2->next;
    }
    
    return head;
}
