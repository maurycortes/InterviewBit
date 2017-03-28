/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * typedef struct ListNode listnode;
 * 
 * listnode* listnode_new(int val) {
 *     listnode* node = (listnode *) malloc(sizeof(listnode));
 *     node->val = val;
 *     node->next = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Head pointer of linked list 
 * 
 * @Output head pointer of list.
 */
void merge(listnode **head1,listnode *head2){
	if(!head2)
		return;
	listnode *p=*head1,*q=head2;
	listnode *prev=p;
	if(p->val>q->val)
	{
		*head1=head2;
		q=q->next;
		head2->next=p;
		prev=head2;
	}
	else
	    p=p->next;
	while(p && q)
	{
		if(p->val>q->val)
		{
			prev->next=q;
			prev=q;
			q=q->next;
			prev->next=p;
		}
		else
		{
			prev=p;
			p = p->next;
		}
	}
	while(p)
	{	//condition necessary for data 46 625 409
		prev=p;
		p=p->next;
	}
	prev->next=q;	//merging the remaining list
}
void split(listnode **head){
	if(!(*head)->next)
		return;
	listnode *hare,*turtle;
	turtle=*head;
	hare=(*head)->next;
	int var=1;
	while(hare)
	{
		if(var)
		{
			hare=hare->next;
			var=0;
		}
		else
		{
			hare=hare->next;
			turtle=turtle->next;
			var=1;
		}
	}
	hare=turtle->next;
	turtle->next=NULL;
	split(head);
	split(&hare);
	merge(head,hare);
}
listnode* sortList(listnode* A) {
    split(&A);
    return A;
}
