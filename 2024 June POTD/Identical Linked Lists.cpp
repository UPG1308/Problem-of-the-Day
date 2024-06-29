bool areIdentical(struct Node *head1, struct Node *head2) {
    // if both are empty then identical
    if(head1 == nullptr && head2 == nullptr) return true;
    // if only one LL is empty then not identical
    if(head1 == nullptr || head2 == nullptr) return false;
    
    // check if each element in LL is same
    // else say not identical
    // it goes till any of the LL is empty
    while(head1 != nullptr && head2 != nullptr) {
        if(head1->data != head2->data) return false;
        
        head1 = head1->next;
        head2 = head2->next;
    }
    
    // at last check if both LL is empty
    // if both empty then, identical else not identical
    return head1 == nullptr && head2 == nullptr;
}
