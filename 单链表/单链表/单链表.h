#pragma once
//1.������ʵ��
//// 1����ͷ�����ѭ��������ɾ���ʵ�� 
#include"common.h"
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;

typedef struct SList
{
	SListNode* _head;
}SList;

void SListInit(SList* plist);
void SListDestory(SList* plist);

SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SList* plist, SLTDataType x);
void SListPopFront(SList* plist);
SListNode* SListFind(SList* plist, SLTDataType x);
// ��pos�ĺ�����в��� 
void SListInsertAfter(SListNode* pos, SLTDataType x);
// ��pos��ǰ����в��� 
void SListInsertFront(SList* plist,SListNode* pos, SLTDataType x);

void SListEraseAfter(SListNode* pos);
void SListRemove(SList* plist, SLTDataType x);

void SListPrint(SList* plist);
void TestSList();