#include "statement.h"

//ͼ���ѯ
void SearchBooks()
{
	char op;

	while (1)
	{
		printf("**********************************************************\n");
		printf("*                       ͼ���ѯ                         *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*                  �������Ӧ���ֽ��в���                *\n");
		printf("*                                                        *\n");
		printf("*                    1����ͼ���Ų���                   *\n");
		printf("*                    2������������                       *\n");
		printf("*                    3�������߲���                       *\n");
		printf("*                    4�������������                     *\n");
		printf("*                    0��������һ����                     *\n");
		printf("*                                                        *\n");
		printf("**********************************************************\n");

		op = getch();
		switch (op)
		{
		case '1': system("cls"); SearchByBookNumber();  break;
		case '2': system("cls"); SearchByTitle(); break;
		case '3': system("cls"); SearchByAuthor();  break;
		case '4': system("cls"); SearchByPublisher();  break;
		case '0': system("cls"); return;
		default: printf("%c\tָ���������������\n", op);
		}
		system("cls");
	}
}

//�����������
void SearchByPublisher()
{
	Book* t = book_head->next;
	char publisher[30];
	int flag = 0;
	printf("��������ҵĳ��������ƣ�\n");
	scanf("%s", publisher);
	while (t)
	{
		if (!strcmp(t->publisher, publisher))
		{
			if (flag == 0)
			{
				printf("%-20s  %-30s  %-20s  %-30s  %-8s  %-6s  %-10s  %-8s  %-8s  %-10s\n",
					"ͼ����", "����", "����", "������", "��������", "���", "���", "ͼ������",
					"��ǰ���", "�ѽ�ͼ����");
			}
			printf("%-20s  %-30s  %-20s  %-30s  %-4d-%-2d   %-6.2f  %-10s  %-8d  %-8d  %-10d\n",
				t->bookNumber, t->title, t->author, t->publisher, t->yearOfPublication,
				t->monthOfPublication, t->money, t->category, t->numberOfBooks,
				t->currentNumberOfBooks, t->numberOfBooksBorrowed);
			flag = 1;
		}
		t = t->next;
	}
	if (flag == 0)
	{
		printf("�������޸ó�������鼮������ϵ����Ա����鼮��\n");
	}
	system("pause");
}

//�����߲���
void SearchByAuthor()
{
	Book* t = book_head->next;
	char author[20];
	int flag = 0;
	printf("��������ҵ����ߣ�\n");
	scanf("%s", author);
	while (t)
	{
		if (!strcmp(t->author, author))
		{
			if (flag == 0)
			{
				printf("%-20s  %-30s  %-20s  %-30s  %-8s  %-6s  %-10s  %-8s  %-8s  %-10s\n",
					"ͼ����", "����", "����", "������", "��������", "���", "���", "ͼ������",
					"��ǰ���", "�ѽ�ͼ����");
			}
			printf("%-20s  %-30s  %-20s  %-30s  %-4d-%-2d   %-6.2f  %-10s  %-8d  %-8d  %-10d\n",
				t->bookNumber, t->title, t->author, t->publisher, t->yearOfPublication,
				t->monthOfPublication, t->money, t->category, t->numberOfBooks,
				t->currentNumberOfBooks, t->numberOfBooksBorrowed);
			flag = 1;
		}
		t = t->next;
	}
	if (flag == 0)
	{
		printf("�������޸����ߵ��鼮������ϵ����Ա����鼮��\n");
	}
	system("pause");
}

//����������
void SearchByTitle()
{
	Book* t = book_head->next;
	char title[30];
	int flag = 0;
	printf("��������ҵ�������\n");
	scanf("%s", title);
	while (t)
	{
		if (!strcmp(t->title, title))
		{
			if (flag == 0)
			{
				printf("%-20s  %-30s  %-20s  %-30s  %-8s  %-6s  %-10s  %-8s  %-8s  %-10s\n",
					"ͼ����", "����", "����", "������", "��������", "���", "���", "ͼ������",
					"��ǰ���", "�ѽ�ͼ����");
			}
			printf("%-20s  %-30s  %-20s  %-30s  %-4d-%-2d   %-6.2f  %-10s  %-8d  %-8d  %-10d\n",
				t->bookNumber, t->title, t->author, t->publisher, t->yearOfPublication,
				t->monthOfPublication, t->money, t->category, t->numberOfBooks,
				t->currentNumberOfBooks, t->numberOfBooksBorrowed);
			flag = 1;
		}
		t = t->next;
	}
	if (flag == 0)
	{
		printf("�������޸��鼮������ϵ����Ա����鼮��\n");
	}
	system("pause");
}

//��ͼ���Ų���
void SearchByBookNumber()
{
	Book* t = book_head->next;
	char bookNumber[20], flag = 0;
	printf("��������ҵ�ͼ���ţ�\n");
	scanf("%s", bookNumber);
	while (t)
	{
		if (!strcmp(t->bookNumber, bookNumber))
		{
			printf("%-20s  %-30s  %-20s  %-30s  %-8s  %-6s  %-10s  %-8s  %-8s  %-10s\n",
				"ͼ����", "����", "����", "������", "��������", "���", "���", "ͼ������",
				"��ǰ���", "�ѽ�ͼ����");
			printf("%-20s  %-30s  %-20s  %-30s  %-4d-%-2d   %-6.2f  %-10s  %-8d  %-8d  %-10d\n",
				t->bookNumber, t->title, t->author, t->publisher, t->yearOfPublication,
				t->monthOfPublication, t->money, t->category, t->numberOfBooks,
				t->currentNumberOfBooks, t->numberOfBooksBorrowed);
			flag = 1;
			break;
		}
		t = t->next;
	}
	if (flag == 0)
	{
		printf("�������޸��鼮������ϵ����Ա����鼮��\n");
	}
	system("pause");
}