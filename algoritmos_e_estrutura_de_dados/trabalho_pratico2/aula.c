struct ListNode *addTwoNumbers( struct ListNode *l1, struct ListNode *l2 ) {
	struct ListNode *n1 = l1;
	struct ListNode *n2 = l2;
	int biggerthanl1 = 0;

	if ( l1->val == 0 ) {
		return l2;
	}
	if ( l2->val == 0 ) {
		return l1;
	}
	while ( n1 != NULL ) {
		n1->val = n1->val + n2->val;
		if ( n1->val >= 10 ) {
			n1->val = n1->val%10;
			n1->next->val += 1;
		}
		if ( n1->next == NULL ) {
			if ( n2->next != NULL ) {
				biggerthanl1 = 1;
				break;
			}
		}
		n1 = n1->next;
		n2 = n2->next;
	}
	if ( biggerthanl1 == 1 ) {
		n1->next = n2->next;
	}
	free(n1);
	free(n2);
	return l1;
}
