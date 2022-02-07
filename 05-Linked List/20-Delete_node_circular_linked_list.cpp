// Deletion of node in circular Linked List.

//Psedo code from GFG. https://www.geeksforgeeks.org/deletion-circular-linked-list/
void deleteNode(Node** head, int key)
{
     
    // If linked list is empty
    if (*head == NULL)
        return;
         
    // If the list contains only a single node
    if((*head)->data==key && (*head)->next==*head)
    {
        free(*head);
        *head=NULL;
        return;
    }
     
    Node *last=*head,*d;
     
    // If head is to be deleted
    if((*head)->data==key)
    {
         
        // Find the last node of the list
        while(last->next!=*head)
            last=last->next;
             
        // Point last node to the next of head i.e.
        // the second node of the list
        last->next=(*head)->next;
        free(*head);
        *head=last->next;
      return;
    }
     
    // Either the node to be deleted is not found
    // or the end of list is not reached
    while(last->next!=*head&&last->next->data!=key)
    {
        last=last->next;
    }
     
    // If node to be deleted was found
    if(last->next->data==key)
    {
        d=last->next;
        last->next=d->next;
        free(d);
    }
    else
        cout<<"no such keyfound";
    }
