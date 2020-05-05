// Complete the insertNodeAtPosition function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) 
{
    SinglyLinkedListNode *node=new SinglyLinkedListNode(data);
    
    if(position==0)    
    {
        node->next=head;
        head=node;
        return head;
    }
    
    SinglyLinkedListNode *tmp=head;
    for(int i=0;i<position-1;++i)
    {
        if(tmp==nullptr)
        {
            return head;
        }
        tmp=tmp->next;
    }
        node->next=tmp->next;
        tmp->next=node;
    return head;
}
