SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
if(head==nullptr || head->next==nullptr)
{
    return head;
}
    
SinglyLinkedListNode* current=head->next;
SinglyLinkedListNode* before=head;
SinglyLinkedListNode* after=head->next->next;
head->next=nullptr;
while(after!=nullptr)
{
    current->next=before;
    before=current;
    current=after;
    after=after->next;
}
    current->next=before;
    head=current;
    return head;
}
