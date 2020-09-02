


// recursive approach

LinkedList * merge(LinkedList* list1, LinkedList* list2){
      LinkedList* final = NULL;

      if(list1 == NULL)
            return(list2);
      if(list2 == NULL)
            return(list1);

      if (list1->data >= list2->data){
            final = list2;
            final->next = merge(list1, list2->next);
      }
      else {
            final = list1;
            final->next = merge(list1->next, list2);
      }
      return(final);
}
