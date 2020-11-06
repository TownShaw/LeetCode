/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 *
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
	int val;
	struct ListNode *next;
};*/

void Insert(struct ListNode **pLast, int value)
{
	struct ListNode *pKey = (struct ListNode *)malloc(sizeof(struct ListNode));
	pKey->val = value;
	pKey->next = NULL;
	(*pLast)->next = pKey;
	*pLast = pKey;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	struct ListNode *pTemp_1 = l1;
	struct ListNode *pTemp_2 = l2;
	struct ListNode *pHead = (struct ListNode *)malloc(sizeof(struct ListNode));	//头节点
	pHead->val = -1;
	pHead->next = NULL;
	struct ListNode *pLast = pHead;
	int prod = 0;	//进位
	for ( ; pTemp_1 != NULL && pTemp_2 != NULL; pTemp_1 = pTemp_1->next, pTemp_2 = pTemp_2->next)
	{
		int sum = pTemp_1->val + pTemp_2->val + prod;
		Insert(&pLast, sum % 10);
		prod = sum / 10;
	}
	if (pTemp_1 == NULL && pTemp_2 == NULL)
	{
		if (prod == 1)
		{
			Insert(&pLast, prod);
		}
	}
	else if (pTemp_1 == NULL)
	{
		for ( ; pTemp_2 != NULL; pTemp_2 = pTemp_2->next)
		{
			int sum = pTemp_2->val + prod;
			Insert(&pLast, sum % 10);
			prod = sum / 10;
		}
		if (prod == 1)
		{
			Insert(&pLast, prod);
		}
	}
	else	//pTemp_2 == NULL
	{
		for ( ; pTemp_1 != NULL; pTemp_1 = pTemp_1->next)
		{
			int sum = pTemp_1->val + prod;
			Insert(&pLast, sum % 10);
			prod = sum / 10;
		}
		if (prod == 1)
		{
			Insert(&pLast, prod);
		}
	}
	struct ListNode *pTemp = pHead;
	pHead = pHead->next;
	free(pTemp);	//释放头节点
	return pHead;
}
// @lc code=end

