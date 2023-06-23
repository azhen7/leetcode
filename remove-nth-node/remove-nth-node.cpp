struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp = head;
        while (temp)
        {
            temp = temp->next;
            size++;
        }

        ListNode* prev = nullptr;
        temp = head;
        for (int i = 0; i < size - n; i++)
        {
            if (i == size - n - 1)
            {
                prev = temp;
            }
            temp = temp->next;
        }
        if (!prev)
        {
            ListNode* next = head->next;
            delete head;
            return next;
        }
        prev->next = temp->next;
        delete temp;

        return head;
    }
};

int main()
{
}