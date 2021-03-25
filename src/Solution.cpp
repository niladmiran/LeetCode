#include "../include/Solution.h"

#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <map>

#include "../include/ListNode.h"
#include "../include/TreeNode.h"

int Solution::coinChange(std::vector<int> &coins, int amount)
{
    int numCoins = coins.size();
    // result[i], the least number of coins we need to make up to money i.
    std::vector<int> results(amount+1, amount+1);

    results[0] = 0;
    for (int money = 1; money < amount + 1; ++money) {
        for (int j = 0; j < numCoins; ++j) {  // number of coins
            if (money - coins[j] >= 0 && results[money] > results[money - coins[j]] + 1)
                results[money] = results[money - coins[j]] + 1;
        }
    }
    return results[amount] < amount+1 ? results[amount] : -1;
}

ListNode* Solution::rotateRight(ListNode* head, int k) {
    if (k == 0 || head == nullptr)  return head;
    int size = 0; // length of the linked list

    // calculate the length of the linklist
    ListNode *p = head;
    while (p != nullptr)
    {
        size++;
        p = p->next;
    }

    // make sure k <= size - 1
    k %= size;

    // use two pointers to find the k-th last ptr
    ListNode *fast = head;
    for (int i = 0; i < k; ++i)
    {
        fast = fast->next;
    }
    ListNode *slow = head;
    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    // redirect the head ptr
    head = slow->next;
    slow->next = nullptr;

    return head;
}

void Solution::wiggleSort(std::vector<int>& nums) {
    std::vector<int> temp = nums;
    int sz = nums.size();
    int mid = (sz + 1) / 2;
    int reverse_it = sz;
    std::sort(temp.begin(), temp.end());
    // exchange the first part of the array and the second part array
    for (int i = 0; i < sz; ++i)
    {
        if (i % 2)
            nums[i] = temp[--reverse_it];
        else
            nums[i] = temp[--mid];
    }
}

void MidOrder(TreeNode* root, std::vector<int>& vals){
    if (root != nullptr){
        MidOrder(root->left, vals);
        vals.push_back(root->val);
        MidOrder(root->right, vals);
    }
}

bool Solution::isValidBST(TreeNode* root){
    std::vector<int> vals;
    MidOrder(root, vals);
    int nums_nodes = vals.size();
    for (int i = 0; i < nums_nodes - 1; ++i){
        if (vals[i] >= vals[i + 1])
            return false;
    }
    return true;
}

std::vector<int> Solution::rotateLeft(int d, std::vector<int> arr){
    // given a vector, shift each of the array's element 1 unit to the left
    for (int i = 0; i < d; ++i) {
        arr.push_back(arr[0]);
        arr.erase(arr.begin());
    }
    return arr;
}

int Solution::lengthOfLIS(std::vector<int>& nums)
{
    int sz = nums.size();
    int maxLength = 1;
    // result[i] is the max length of the increasing subsequence that ending with nums[i]
    std::vector<int> result(sz, 1);
    for (int i = 1; i < sz; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i])
                result[i] = (result[i] > result[j] + 1 ? result[i] : result[j] + 1);
        }
        if (result[i] > maxLength)  maxLength = result[i];
    }
    return maxLength;
}

std::string Solution::pangrams(std::string s) {
    std::vector<bool> result(26, false);
    int count = 0;
    int ind = 0;
    for(auto ch: s){
        if (ch == ' ') continue;
        ind = (ch - 'a' >= 0 ? ch - 'a' : ch - 'A');
        if (!result[ind]){
            result[ind] = true;
            count++;
        }
        if (count == 26) return std::string("pangram");
    }
    return std::string("not pangram");
}

void flip(char & c){
    // flip a char, that is, return '1' if c = '0', return '0' if c = '1'
    c ^= 1;
}

int Solution::passwordLock(std::string & initial, std::string & goal){
    int sz = initial.size();
    if (sz == 1) return initial[0] == goal[0] ? 0 : 1;
    int count;
    int best = 40;
    for (int i = 0; i < 2; ++i) {
        // press or not press the first button
        count = 0;
        char c = '0' + i;
        std::string temp(initial);
        if (temp[0] != c){
            flip(temp[0]);
            flip(temp[1]);
            count++;
        }
        int j;
        // flip the middle button
        for (j = 1; j < sz - 1; ++j){
            if (temp[j-1] != goal[j-1]){
                flip(temp[j-1]);
                flip(temp[j]);
                flip(temp[j+1]);
                count++;
            }
        }
        // flip the last button
        if (temp[j-1] != goal[j-1]){
            flip(temp[j-1]);
            flip(temp[j]);
            ++count;
        }
        // the expected state is approachable
        if (temp[j] == goal[j])
            best = best > count ? count : best;
    }
    return best <= sz ? best : -1;
}

ListNode* Solution::reverseList(ListNode* head){
    ListNode *current = head;
    ListNode *pre = nullptr, *nxt;
    while (current){
        // store the next node
        nxt = current->next;

        // reverse the current node
        current->next = pre;

        // update the new head
        pre = current;

        // update the current node
        current = nxt;
    }

    return pre;
}

bool Solution::isValid(std::string s){
    std::stack<char> result;
    int sz = s.size();
    for (int i = 0; i < sz; ++i) {
        if (result.empty())
            result.push(s[i]);
        else if (result.top() == '(' && s[i] == ')' ||
            result.top() == '[' && s[i] == ']' ||
            result.top() == '{' && s[i] == '}')
            result.pop();
        else
            result.push(s[i]);
    }
    if (result.empty())
        return true;
    return false;
}

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2){
    ListNode *head = new ListNode(0);
    ListNode *p3 = head;
    while (l1 && l2){
        if (l1->val < l2->val) {
            p3->next = l1;
            p3 = l1;
            l1 = l1->next;
        }else{
            p3->next = l2;
            p3 = l2;
            l2 = l2->next;
        }
    }
    p3->next = l1 ? l1 : l2;

    return head->next;
}

void Solution::merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n){
    int i = m, j = n;
    // insert the element in reverse order
    while (i && j){
        if (nums1[i - 1] < nums2[j - 1]){
            nums1[i + j - 2] = nums2[j - 1];
            j--;
        }else{
            nums1[i + j - 2] = nums1[j - 1];
            i--;
        }
    }
    // add the rest of nums2
    while (j){
        nums1[i + j - 2] = nums2[j - 1];
        j--;
    }
}

int Solution::findKthLargest(std::vector<int>& nums, int k){
    // always maintain the largest k numbers.
    int sz = nums.size();
    std::multiset<int> result;
    for (int i = 0; i < sz; ++i) {
        if (i < k)  result.insert(nums[i]);
        else{
            auto iterSmallest = result.begin();
            // if we find a larger number, update curent result
            if (nums[i] > *(result.begin())){
                result.erase(iterSmallest);
                result.insert(nums[i]);
            }
        }
    }
    return *(result.begin());
}



int Solution::maxProfit(std::vector<int>& prices){
    int sz = prices.size();
    int minPrice = prices[0];
    int maxProfit = 0;
    for (int i = 0; i < sz; ++i){
        if (prices[i] < minPrice)
            minPrice = prices[i];
        if (maxProfit < prices[i] - minPrice)
            maxProfit = prices[i] - minPrice;
    }
    return maxProfit;
}

TreeNode* Solution::invertTree(TreeNode* root){
    if (root == nullptr)
        return nullptr;
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);

    return root;
}

ListNode* Solution::reverseK(ListNode* head, int k){
    ListNode *tail = head;
    while (k){
        ListNode* cur = tail->next;
        tail->next = tail->next->next;
        cur->next = head;
        head = cur;
        k--;
    }
    return head;
}

ListNode* Solution::reverseBetween(ListNode* head, int left, int right){
    if (left == 1)  return reverseK(head, right - left);
    int k = 2;
    ListNode *cur = head;
    while (k < left){
        cur = cur->next;
        k++;
    }
    cur->next = reverseK(cur->next, right-left);
    return head;
}

int Solution::getNumberOfBackOrders(std::vector<std::vector<int> >& orders){
    std::map<int, int,std::greater<int> > buyOrders; // from large to small
    std::map<int, int> sellOrders; // from small to large
    int count = 0;
    int sz = orders.size();
    int price, amount;
    for (int i = 0; i < sz; ++i) {
        price = orders[i][0];
        amount = orders[i][1];
        if (orders[i][2] == 0) { // buy
            while (!sellOrders.empty() && price >= sellOrders.begin()->first) {
                if (amount >= sellOrders.begin()->second) {
                    amount -= sellOrders.begin()->second;
                    sellOrders.erase(sellOrders.begin());
                    continue;
                } else {
                    sellOrders.begin()->second -= amount;
                    amount = 0;
                    break;
                }
            }
            if (amount)
                buyOrders[price] += amount;
        } else { // sell
            while (!buyOrders.empty() && price <= buyOrders.begin()->first) {
                if (amount >= buyOrders.begin()->second) {
                    amount -= buyOrders.begin()->second;
                    buyOrders.erase(buyOrders.begin());
                    continue;
                } else {
                    buyOrders.begin()->second -= amount;
                    amount = 0;
                    break;
                }
            }
            if (amount)
                sellOrders[price] += amount;
        }
    }
    std::map<int,int>::iterator it;
    if (!buyOrders.empty()){
        for (it = buyOrders.begin(); it != buyOrders.end(); ++it) {
            count += it->second;
            count = count % ((int)(1e9 + 7));
        }
    }
    if (!sellOrders.empty()){
        for (it = sellOrders.begin(); it != sellOrders.end(); ++it) {
            count += it->second;
            count = count % ((int)(1e9 + 7));
        }
    }

    return count;
}

int Solution::maxValue(int n, int index, int maxSum) {
    maxSum -= n;
    int left = 0, right = maxSum, opt = 0;
    long long sum;
    while (left <= right){
        sum = 0LL;
        int mid = (right + left) / 2;
        int leftEnd = std::max(mid - index, 0);
        int rightEnd = std::max(mid - (n - 1 - index), 0);
        sum += 1LL * (mid + leftEnd) * (mid - leftEnd + 1) / 2;
        sum += 1LL * (mid + rightEnd) * (mid - rightEnd + 1) / 2;
        if (sum - mid <= maxSum){
            opt = std::max(opt, mid);
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return opt + 1;
}

