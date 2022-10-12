   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode *newNode=new ListNode(),*head=newNode;
        
        while(l1 && l2){
            int sum=l1->val+l2->val+carry;
            carry=sum/10;
            newNode->next= new ListNode(sum%10);
            newNode=newNode->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            int sum=l1->val+carry;
            carry=sum/10;
            newNode->next= new ListNode(sum%10);
            newNode=newNode->next;
            l1=l1->next;
        }
        while(l2){
            int sum=l2->val+carry;
            carry=sum/10;
            newNode->next= new ListNode(sum%10);
            newNode=newNode->next;
            l2=l2->next;
        }
        if(carry){
            newNode->next= new ListNode(carry);
        }
        
        
        return head->next;
    }
