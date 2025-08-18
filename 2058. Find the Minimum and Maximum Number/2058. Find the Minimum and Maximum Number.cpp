/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalpoint;
        ListNode* p = head;//previous node
        ListNode* c = p->next;//current node
        if(c->next == NULL) return {-1,-1};
        ListNode* n = c->next;//next node to current node
        int pos = 1;

        while(n != NULL){
            if((c->val > p->val && c->val > n->val) || (c->val < p->val && c->val < n->val)){
                criticalpoint.push_back(pos);
            }
            p = p->next;
            c = c->next;
            n = n->next;
            pos++;
        }
        if(criticalpoint.size() < 2)return {-1,-1};

        int min_d = INT_MAX;
        for (int i = 1; i < criticalpoint.size(); ++i) {
            min_d = min(min_d, criticalpoint[i] - criticalpoint[i - 1]);
        }
        int max_d = criticalpoint.back() - criticalpoint.front();
        return{min_d,max_d};
    }
};