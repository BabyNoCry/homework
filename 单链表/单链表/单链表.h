#pragma once
//1.单链表实现
//// 1、无头单向非循环链表增删查改实现 
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
// 在pos的后面进行插入 
void SListInsertAfter(SListNode* pos, SLTDataType x);
// 在pos的前面进行插入 
void SListInsertFront(SList* plist,SListNode* pos, SLTDataType x);

void SListEraseAfter(SListNode* pos);
void SListRemove(SList* plist, SLTDataType x);

void SListPrint(SList* plist);
void TestSList();