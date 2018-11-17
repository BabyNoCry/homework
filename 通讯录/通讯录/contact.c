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
		printf("ͨѶ¼�������޷����\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", pcon->data[pcon->sz].name);
		printf("����������:>");
		scanf("%hd", &(pcon->data[pcon->sz].age));
		printf("�������Ա�:>");
		scanf("%s", pcon->data[pcon->sz].sex);
		printf("������绰:>");
		scanf("%s", pcon->data[pcon->sz].tele);
		printf("�������ַ:>");
		scanf("%s", pcon->data[pcon->sz].addr);

		pcon->sz++;
		printf("��ӳɹ�\n");
	}
}

void ShowContact(const Contact* pcon)
{
	int i = 0;
	assert(pcon != NULL);
	printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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

static int FindEntry(Contact* pcon, char name[])//����
{
	int i = 0;
	assert(pcon != NULL);
	for (i = 0; i < pcon->sz; i++)
	{
		if (strcmp(pcon->data[i].name, name) == 0)
		{
			return i;//�ҵ���
		}
	}
	return -1;//û�ҵ�
}

void DelContact(Contact* pcon)
{
	int pos = 0;
	char name[MAX_NAME] = { 0 };
	assert(pcon != NULL);
	if (pcon->sz == 0)
	{
		printf("ͨѶ¼�ѿգ��޷�ɾ��\n");
	}
	else
	{
		printf("������Ҫɾ���˵�����:>");
		scanf("%s", name);
		pos = FindEntry(pcon, name);
		if (pos == -1)
		{
			printf("Ҫɾ�����˲�����\n");
		}
		else
		{
			//ɾ��
			int i = 0;
			for (i = pos; i < pcon->sz - 1; i++)
			{
				pcon->data[i] = pcon->data[i + 1];
			}
			pcon->sz--;
			printf("ɾ���ɹ�\n");
		}
	}
}
void Sreachcontact(Contact* pcon)//������ϵ��
{
	char name[MAX_NAME] = { 0 };
	int i = 0;
	printf("��������Ҫ���ҵ��˵�������>");
	scanf("%s", name);
	i=FindEntry(pcon, name);//����
	if (i !=-1)
	{
		printf("\n�ҵ��ˣ�����˵���Ϣ����:\n");
		printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ\n");
		printf("%-15s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			pcon->data[i].name,
			pcon->data[i].age,
			pcon->data[i].sex,
			pcon->data[i].tele,
			pcon->data[i].addr);
	}
	else
	{
		printf("����ϵ�˲����ڣ���\n");
	}
}
void Modifycontact(Contact* pcon)//�޸���Ϣ
{
	char name[MAX_NAME] = { 0 };
	int i = 0;

	printf("��������Ҫ�޸���Ϣ���˵����֣�>");
	scanf("%s",name);
	i=FindEntry(pcon,name);//����
	if (i == -1)
	{
		printf("����ϵ�˲����ڣ���\n");
	}
	else
	{
		int j = 0;

		printf("1.����  2. ����  3.�Ա�  4.�绰 5.��ַ  0.ȡ��\n");
		do
		{
			printf("��������Ҫ�޸ĵ�ѡ�\n");
			scanf("%d", &j);
			switch (j)
			{
			case 1:
				char name1[MAX_NAME] = { 0 };
				printf("�������µ����֣�");
				scanf("%s", name1);
				strcpy(pcon->data[i].name, name1);
				break;
			case 2:
				int age1 = 0;
				printf("�������µ����䣺");
				scanf("%d", &age1);
				pcon->data[i].age = age1;
				break;
			case 3:
				char sex1[MAX_NAME] = { 0 };
				printf("�������µ��Ա�");
				scanf("%s", sex1);
				strcpy(pcon->data[i].sex, sex1);
				break;
			case 4:
				char tele1[MAX_NAME] = { 0 };
				printf("�������µĵ绰��");
				scanf("%s", tele1);
				strcpy(pcon->data[i].tele, tele1);
				break;
			case 5:
				char addr1[MAX_NAME] = { 0 };
				printf("�������µĵ�ַ��");
				scanf("%s", addr1);
				strcpy(pcon->data[i].addr, addr1);
				break;
			case 0:
				printf("�˳��޸�\n");
				break;
			default:
				printf("������󣡣�\n");
				break;

			}
		} while (j);
	}
	printf("~~�޸ĳɹ�~~\n");
}
void EmptyContact(Contact* pcon)//���ͨѶ¼
{
	assert(pcon != NULL);
	pcon->sz = 0;
	printf("��ͨѶ¼����գ���\n");
}
void SortContact(Contact* pcon)//����//ð��
{
	int i=0;
	int j = 0;
	printf("�������������£�\n");
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
	
	
	
	fprintf(fp,"%-15s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
