#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

void InitContact(Contact* pcon)
{
	assert(pcon != NULL);

	pcon->sz = 0;
	memset(pcon->data, 0, sizeof(pcon->data));//ok?
}

void AddContact(Contact* pcon)
{
	assert(pcon != NULL);

	if (pcon->sz == MAX)
	{
		printf("通讯录已满，无法添加\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", pcon->data[pcon->sz].name);
		printf("请输入年龄:>");
		scanf("%hd", &(pcon->data[pcon->sz].age));
		printf("请输入性别:>");
		scanf("%s", pcon->data[pcon->sz].sex);
		printf("请输入电话:>");
		scanf("%s", pcon->data[pcon->sz].tele);
		printf("请输入地址:>");
		scanf("%s", pcon->data[pcon->sz].addr);

		pcon->sz++;
		printf("添加成功\n");
	}
}

void ShowContact(const Contact* pcon)
{
	int i = 0;
	assert(pcon != NULL);
	printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pcon->sz; i++)
	{
		printf("%-15s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			pcon->data[i].name,
			pcon->data[i].age,
			pcon->data[i].sex,
			pcon->data[i].tele,
			pcon->data[i].addr);
	}
}

static int FindEntry(Contact* pcon, char name[])//查找
{
	int i = 0;
	assert(pcon != NULL);
	for (i = 0; i < pcon->sz; i++)
	{
		if (strcmp(pcon->data[i].name, name) == 0)
		{
			return i;//找到了
		}
	}
	return -1;//没找到
}

void DelContact(Contact* pcon)
{
	int pos = 0;
	char name[MAX_NAME] = { 0 };
	assert(pcon != NULL);
	if (pcon->sz == 0)
	{
		printf("通讯录已空，无法删除\n");
	}
	else
	{
		printf("请输入要删除人的姓名:>");
		scanf("%s", name);
		pos = FindEntry(pcon, name);
		if (pos == -1)
		{
			printf("要删除的人不存在\n");
		}
		else
		{
			//删除
			int i = 0;
			for (i = pos; i < pcon->sz - 1; i++)
			{
				pcon->data[i] = pcon->data[i + 1];
			}
			pcon->sz--;
			printf("删除成功\n");
		}
	}
}
void Sreachcontact(Contact* pcon)//查找联系人
{
	char name[MAX_NAME] = { 0 };
	int i = 0;
	printf("请输入你要查找的人的姓名：>");
	scanf("%s", name);
	i=FindEntry(pcon, name);//查找
	if (i !=-1)
	{
		printf("\n找到了，这个人的信息如下:\n");
		printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址\n");
		printf("%-15s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			pcon->data[i].name,
			pcon->data[i].age,
			pcon->data[i].sex,
			pcon->data[i].tele,
			pcon->data[i].addr);
	}
	else
	{
		printf("该联系人不存在！！\n");
	}
}
void Modifycontact(Contact* pcon)//修改信息
{
	char name[MAX_NAME] = { 0 };
	int i = 0;

	printf("请输入你要修改信息的人的名字：>");
	scanf("%s",name);
	i=FindEntry(pcon,name);//查找
	if (i == -1)
	{
		printf("该联系人不存在！！\n");
	}
	else
	{
		int j = 0;

		printf("1.名字  2. 年龄  3.性别  4.电话 5.地址  0.取消\n");
		do
		{
			printf("请输入你要修改的选项：\n");
			scanf("%d", &j);
			switch (j)
			{
			case 1:
				char name1[MAX_NAME] = { 0 };
				printf("请输入新的名字：");
				scanf("%s", name1);
				strcpy(pcon->data[i].name, name1);
				break;
			case 2:
				int age1 = 0;
				printf("请输入新的年龄：");
				scanf("%d", &age1);
				pcon->data[i].age = age1;
				break;
			case 3:
				char sex1[MAX_NAME] = { 0 };
				printf("请输入新的性别：");
				scanf("%s", sex1);
				strcpy(pcon->data[i].sex, sex1);
				break;
			case 4:
				char tele1[MAX_NAME] = { 0 };
				printf("请输入新的电话：");
				scanf("%s", tele1);
				strcpy(pcon->data[i].tele, tele1);
				break;
			case 5:
				char addr1[MAX_NAME] = { 0 };
				printf("请输入新的地址：");
				scanf("%s", addr1);
				strcpy(pcon->data[i].addr, addr1);
				break;
			case 0:
				printf("退出修改\n");
				break;
			default:
				printf("输入错误！！\n");
				break;

			}
		} while (j);
	}
	printf("~~修改成功~~\n");
}
void EmptyContact(Contact* pcon)//清空通讯录
{
	assert(pcon != NULL);
	pcon->sz = 0;
	printf("该通讯录已清空！！\n");
}
void SortContact(Contact* pcon)//排序//冒泡
{
	int i=0;
	int j = 0;
	printf("按年龄排序如下：\n");
	for (i = 0; i < pcon->sz; i++)
	{
		for (j = 0; j < (pcon->sz-i-1); j++)
		{
			if (pcon->data[j].age > pcon ->data[j+ 1].age)
			{
				char name1[MAX_NAME] = { 0 };
				strcpy(name1, pcon->data[j+1].name);
				strcpy(pcon->data[j+ 1].name, pcon->data[j].name);
				strcpy(pcon->data[j].name, name1);

				char sex1[SEX_MAX] = { 0 };
				strcpy(sex1,pcon ->data[j + 1].sex); 
				strcpy(pcon->data[j + 1].sex, pcon->data[j].sex);
				strcpy(pcon->data[j].sex,sex1);

				short int age1= pcon ->data[j + 1].age;
				pcon->data[j + 1].age=pcon->data[j].age;
				pcon->data[j].age=age1;

				char tele1[TELE_MAX] = { 0 };
				strcpy(	tele1,pcon ->data[j + 1].tele);
				strcpy(pcon->data[j + 1].tele, pcon->data[j].tele);
				strcpy(pcon->data[j].tele, tele1);

				char addr1[ADDR_MAX] = { 0 };

				strcpy(addr1,pcon ->data[j + 1].addr);
				strcpy(pcon->data[j + 1].addr, pcon->data[j].addr);
				strcpy(pcon->data[j].addr, addr1);
			}
		}

	}
	ShowContact(pcon);

}
void Savecontact(const Contact* pcon)
{
	int i = 0;
	assert(pcon != NULL);
	FILE *fp = fopen("E:\\text.txt", "w");
	
	
	
	fprintf(fp,"%-15s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pcon->sz; i++)
	{
		fprintf(fp,"%-15s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			pcon->data[i].name,
			pcon->data[i].age,
			pcon->data[i].sex,
			pcon->data[i].tele,
			pcon->data[i].addr);
	}
	fclose(fp);
}
