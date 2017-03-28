/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* head) {
    if(!head)
        return NULL;
    unordered_map<RandomListNode*, RandomListNode*> ht;
    RandomListNode *p1 = head;
    RandomListNode *p2 = new RandomListNode(head->label);
    ht[head] = p2;
    while(p1) 
    {
        if(p1->next) 
        {
            if(ht.count(p1->next))
                p2->next = ht[p1->next];
            else
            {
                p2->next = new RandomListNode(p1->next->label);
                ht[p1->next] = p2->next;
            }
        }
        if(p1->random) 
        {
            if(ht.count(p1->random))
                p2->random = ht[p1->random];
            else
            {
                p2->random = new RandomListNode(p1->random->label);
                ht[p1->random] = p2->random;
            }
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return ht[head];
}
