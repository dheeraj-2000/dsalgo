/****************************************************************
    Following is the Linked List node structure

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
codestudio problem : Reverse List In K Groups

*****************************************************************/


Node* kReverse(Node* head, int k) {
    // base condition when we have to stop reversing 
    if(head == NULL){
        return NULL;
    }
    
    Node* forward = NULL;    
    Node* curr = head;      
    Node* prev = NULL;
    int cnt = 0;
    
    // curr = NULL break loop and cnt times reverse kardo 
    while(curr != NULL && cnt<k ){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }
    if(forward!=NULL){
        // forward is haed here
        head->next = kReverse(forward,k);
    }
    return prev;
}
