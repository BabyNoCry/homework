#pragma once
#include"������.h"
void SListInit(SList* plist)
{
	assert(plist);
	
	plist->_head = NULL;
}
void SListDestory(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur != NULL)
	{
		SListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	plist->_head = NULL;
}
SListNode* BuySListNode(SLTDataType x)
{
	SListNode* p = (SListNode*)malloc(sizeof(SListNode));
	p->_data = x;
	p->_next = NULL;
	return p;
}
void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* M= BuySListNode(x);
	if (plist->_head== NULL)
	{
		plist->_head= M;
	}
	else
	{
		SListNode* p = plist->_head;
		plist->_head = M;
		M->_next = p;
	}

}
void SListPopFront(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	SListNode* next = cur->_next;
	free(cur);
	cur = NULL;
	plist->_head = next;
}
SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur != NULL)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->_next;
		}
	}
	return NULL;
}
// ��pos�ĺ�����в��� 
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode* p=BuySListNode(x);
	SListNode* p2=pos->_next;
	pos->_next = p;
	p->_next = p2;
}
// ��pos��ǰ����в��� 
void SListInsertFront(SList* plist,SListNode* pos, SLTDataType x)
{
	assert(pos);
	assert(plist);
	SListNode* cur = plist->_head;
	SListNode* p = BuySListNode(x);
	SListNode* p2 = NULL;
	while (cur !=NULL)
	{
		if (cur == pos)
		{
			break;
		}
		cur = cur->_next;
	}
	p2 = cur;
	cur = p;
	p->_next = p2;
}


void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	SListNode* p= pos->_next->_next;
	free(pos->_next);
	pos->_next = p;
}
void SListRemove(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* node = SListFind(plist, x);
	if (node == NULL)
	{
		return;
	}
	SListNode* cur = plist->_head;
	while (cur != NULL)
	{
		if (cur == node)
		{
			SListNode* next = cur->_next;
			free(cur);
			cur = next;
		}
		else
		{
			cur = cur->_next;
		}
	}
}

void SListPrint(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur!= NULL)
	{
		printf("%d->", cur->_data);
		cur=cur->_next;
	}
	printf("NULL");
	printf("\n");
}
void TestSList()
{
	SList S;
	SListInit(&S);
	SListPushFront(&S, 1);
	SListPushFront(&S, 2);
	SListPushFront(&S, 3);
	SListPrint(&S);
	
	SListPushFront(&S, 4);
	SListPrint(&S);

	SListPopFront(&S);
	SListPrint(&S);
	//SListRemove(&S, 2);
	SListPrint(&S);

	SListDestory(&S);
}
//
//����һ������ͷ��� head �ķǿյ���������������м��㡣
//����������м��㣬�򷵻صڶ����м��㡣

//	struct ListNode* middleNode(struct ListNode* head) {
//	struct ListNode* cur = head;
//	int count = 0;
//	int mid = 0;
//	while (cur)
//	{
//		count++;
//		cur = cur->next;
//	}
//	mid = count / 2;
//	cur = head;
//	while (mid--)
//	{
//		cur = cur->next;
//	}
//	return cur;
//}
//ɾ�������е��ڸ���ֵ val �����нڵ㡣
//struct ListNode* removeElements(struct ListNode* head, int val) {
//struct ListNode* p = NULL;
//struct ListNode* c = head;
//struct ListNode* next;
//while (c)
//{
//	if (c->val == val)
//	{
//		next = c->next;
//		free(c);
//		c = next;
//		if (p == NULL)
//		{
//			head = next;
//		}
//		else
//		{
//			p->next = next;
//		}
//	}
//	else
//	{
//		p = c;
//		c = c->next;
//	}
//}
//return head;

//��תһ��������
//struct ListNode* reverseList(struct ListNode* head) {
//	struct ListNode* prev = NULL;
//	struct ListNode* cur = head;
//	struct ListNode* next;
//	while (cur)
//	{
//		//�Ȼ�ȡ��һ���ڵ�
//		next = cur->next;
//		//���ĵ�ǰ�ڵ��ָ��
//		cur->next = prev;
//		prev = cur;
//		cur = next;
//	}
//	return prev;
//}

//����һ����������������е�����k����㡣
//�������ÿ�ָ������k����Ȼ�����ָ��һ���ߣ�����ָ���ߵ�β������ָ���ߵ�������kԪ��λ�á�
//ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
//	struct ListNode* fast = pListHead;
//	struct ListNode* slow = fast;
//	while (k--)
//	{
//		if (fast)
//		{
//			fast = fast->next;
//		}
//		else {
//			return NULL;
//		}
//	}
//	//����ָ��һ����
//	while (fast)
//	{
//		fast = fast->next;
//		slow = slow->next;
//	}
//	return slow;
//}

//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵ�
//������
//1.�ҵ��������ͷ�ڵ㣺��������ֵС��ͷ�ڵ���Ϊ�������ͷ�ڵ�
//2.����Ƚ����������ʣ��Ԫ�أ����Ӵ�Сβ�嵽�µ������С�
//*/
//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
//	struct ListNode* tail;
//	struct ListNode* head;
//	if (l1 == NULL)
//	{
//		return l2;
//	}
//	if (l2 == NULL)
//	{
//		return l1;
//	}
//	if (l1->val < l2->val)
//	{
//		head = l1;
//
//		l1 = l1->next;
//	}
//	else
//	{
//		head = l2;
//
//		l2 = l2->next;
//	}
//	tail = head;
//	while (l1&&l2)
//	{
//		if (l1->val < l2->val)
//		{
//			tail->next = l1;
//			tail = tail->next;
//			l1 = l1->next;
//		}
//		else
//		{
//			tail->next = l2;
//			tail = tail->next;
//			l2 = l2->next;
//		}
//	}
//	//�������һ������û�б����꣬�ŵ��������β��
//	if (l1)
//	{
//		tail->next = l1;
//	}
//	if (l2)
//	{
//		tail->next = l2;
//	}
//	return head;
//}