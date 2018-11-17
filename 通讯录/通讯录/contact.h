
#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <assert.h>
#include <string.h>
#include <stdio.h>

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	EMPTY,
	SORT,
	SAVE
};

#define MAX 1000

#define MAX_NAME 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30

typedef struct PeoInfo
{
	char name[MAX_NAME];
	char sex[SEX_MAX];
	short int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}PeoInfo;

typedef struct Contact
{
	PeoInfo data[MAX];//存放数据
	int sz;//通讯录的有效信息个数
}Contact;

void InitContact(Contact* pcon);
void AddContact(Contact* pcon);
void ShowContact(const Contact* pcon);
void DelContact(Contact* pcon);
void Sreachcontact(Contact* pcon);
void Modifycontact(Contact* pcon);
void EmptyContact(Contact* pcon);
void SortContact(Contact* pcon);
void Savecontact(const Contact* pcon);

#endif //__TACT_H__