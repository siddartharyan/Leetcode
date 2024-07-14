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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector<int>v;
        while(head != nullptr){
            v.push_back(head->val);
            head=head->next;
        }
        unordered_set<int>s(nums.begin(),nums.end());
        ListNode* t=nullptr;
        head=nullptr;
        for(auto &x:v){
            if(s.find(x) == s.end()){
                ListNode* n = new ListNode(x);
                if(head == nullptr){
                    head=n;
                    t=n;
                }else{
                    t->next = n;
                    t = n;
                }
            }
        }
        return head;
    }
};