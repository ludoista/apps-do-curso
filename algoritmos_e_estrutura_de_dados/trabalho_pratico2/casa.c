struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode sentinel;
    sentinel.val = 0;
    sentinel.next = NULL;
    struct ListNode *cursor = &sentinel;
    int carry = 0;

    while ( l1 != NULL || l2 != NULL || carry > 0) {
        int sum = carry;
        if ( l1 != NULL ) {
            sum += l1->val;
            l1 = l1->next;
        }
        if ( l2 != NULL ) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;

        struct ListNode *novo = (struct ListNode*) malloc(sizeof(struct ListNode));
        novo->val = sum % 10;
        novo->next = NULL;

        cursor->next = novo;
        cursor = cursor->next;
    }
    return sentinel.next;
}
