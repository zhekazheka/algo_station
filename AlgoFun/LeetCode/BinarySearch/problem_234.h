#pragma once
#include <vector>

// 234. Palindrome Linked List

namespace PalindromeLinkedList
{
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

	class Solution
	{
	public:

		// Use two pointers. One will move with the speed of 1 and one with the speed of 2, so when the fast pointer reaches the end, slow pointer would be at mid.

		static ListNode* reverse(ListNode* head) 
		{
			ListNode* prev = nullptr;
			ListNode* curr = head;
			while (curr != nullptr) 
			{
				ListNode* next = curr->next;
				curr->next = prev;
				prev = curr;
				curr = next;
			}
			return prev;
		}

		static bool isPalindrome(ListNode* head)
		{
			ListNode* slow = head;
			ListNode* fast = head->next;
			while (fast != nullptr && fast->next != nullptr) 
			{
				slow = slow->next;
				fast = fast->next->next;
			}
			ListNode* rev = reverse(slow->next); // reverse second list
			slow->next = nullptr;
			while (rev != nullptr) 
			{
				if (head->val != rev->val) 
				{
					return false;
				}

				head = head->next;
				rev = rev->next;
			}
			return true;
		}

		// -----------------------------------------------------------------------------------------------------------------------------

		static bool isPalindromeBasic(ListNode* head)
		{
			std::vector<int> values;
			while (head != nullptr)
			{
				values.push_back(head->val);
				head = head->next;
			}

			if (values.size() == 1)
			{
				return false;
			}

			for (size_t i = 0; i < values.size() / 2; ++i)
			{
				int index = values.size() - 1 - i;
				if (values[i] != values[index])
				{
					return false;
				}
			}

			return true;
		}

		static bool test()
		{
			std::vector<int> inputData = { 1, 1, 2, 2, 1 };
			ListNode* input = new ListNode(inputData[0]);

			ListNode* head = input;

			for (size_t i = 1; i < inputData.size(); ++i)
			{
				ListNode* node = new ListNode(inputData[i]);
				input->next = node;

				input = node;
			}

			return isPalindrome(head);
		}
	};
}