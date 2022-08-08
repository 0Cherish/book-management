#include "statement.h"

//����û�
void BrowseTheUser(User* account)
{
	int count = 1;
	User* t = user_head;
	printf("%-4s  %-10s  %-30s  %-20s  %-10s  %-6s  %-6s  %-11s  %-12s\n",
		"���", "ѧ����", "����", "����", "�Ա�", "����Ա", "�ɵ�¼", "ְ��/�༶", "�����鼮����");
	while (t)
	{
		printf("%-4d  %-10s  %-30s  ", count, t->ID, t->name);
		if (t->admin && account != user_head)
		{
			printf("%-20s  ", "*********");
		}
		else
		{
			printf("%-20s  ", t->password);
		}
		printf("%-10s  ", t->gender);
		if (t->admin)
		{
			printf("%-6s  ", "Yes");
		}
		else
		{
			printf("%-6s  ", "No");
		}
		if (t->login)
		{
			printf("%-6s  ", "Yes");
		}
		else
		{
			printf("%-6s  ", "No");
		}
		if (t->position[0])
		{
			printf("%-11s  ", t->position);
		}
		else
		{
			printf("%-11d  ", t->theClass);
		}
		printf("%-12d\n", t->borrow.numberOfLoans);
		t = t->next;
		count++;
	}
}

//��������鼮
int BrowsingOverdueBooks()
{
	User* t = user_head;
	int numberOfOverdueBooks = 0;
	int i = 0, count = 0;
	while (t)
	{
		for (i = 0; i < t->borrow.numberOfLoans; i++)
		{
			if (OverdueBooks(t, i))
			{
				numberOfOverdueBooks++;
			}
		}
		t = t->next;
	}
	if (!numberOfOverdueBooks)
	{
		return 0;
	}
	char borrowDate[30], dueDate[30];
	printf("%-4s  %-20s  %-30s  %-20s  %-10s  %-30s  %-10s  %-24s  %-24s\n",
		"���", "ͼ����", "����", "����", "���", "����������", "ID", "��������", "��������");
	t = user_head;
	while (t)
	{
		for (i = 0; i < t->borrow.numberOfLoans; i++)
		{
			if (OverdueBooks(t, i))
			{
				strcpy(borrowDate, ctime(&t->borrow.borrowDate[i]));
				strcpy(dueDate, ctime(&t->borrow.dueDate[i]));
				borrowDate[strlen(borrowDate) - 1] = '\0';
				dueDate[strlen(dueDate) - 1] = '\0';
				count++;
				printf("%-4d  %-20s  %-30s  %-20s  %-10s  %-30s  %-10s  %-24s  %-24s\n",
					count, t->borrow.booksOnLoan[i].bookNumber, t->borrow.booksOnLoan[i].title,
					t->borrow.booksOnLoan[i].author, t->borrow.booksOnLoan[i].category, t->name,
					t->ID, borrowDate, dueDate);
			}
		}
		t = t->next;
	}
	return 1;
}

//���ͼ��
void BrowseBooks()
{
	if (!book_amount)
	{
		printf("��������ͼ�����ϣ�����ϵ����Ա����鼮��\n");
		return;
	}
	Book* t = book_head->next;
	int i = 1;
	printf("%-4s  %-20s  %-30s  %-20s  %-30s  %-8s  %-6s  %-10s  %-8s  %-8s  %-10s\n",
		"���", "ͼ����", "����", "����", "������", "��������", "���", "���", "ͼ������",
		"��ǰ���", "�ѽ�ͼ����");
	while (t)
	{
		printf("%-4d  %-20s  %-30s  %-20s  %-30s  %-4d-%-2d   %-6.2f  %-10s  %-8d  %-8d  %-10d\n",
			i, t->bookNumber, t->title, t->author, t->publisher, t->yearOfPublication,
			t->monthOfPublication, t->money, t->category, t->numberOfBooks, t->currentNumberOfBooks,
			t->numberOfBooksBorrowed);
		t = t->next;
		i++;
	}
}

//��ʷ����
void HistoryOfBorrowing(User* account)
{
	if (!account->borrow.numberOfLoans)
	{
		printf("���޽��ļ�¼��\n");
		return;
	}
	printf("%-4s  %-20s  %-30s  %-6s  %-24s  %-24s  %-8s  %-8s\n",
		"���", "ͼ����", "����", "���", "��������", "��������", "�Ƿ�����", "������");
	char borrowDate[30], dueDate[30];
	for (int i = 0; i < account->borrow.numberOfLoans; i++)
	{
		strcpy(borrowDate, ctime(&account->borrow.borrowDate[i]));
		strcpy(dueDate, ctime(&account->borrow.dueDate[i]));
		borrowDate[strlen(borrowDate) - 1] = '\0';
		dueDate[strlen(dueDate) - 1] = '\0';
		if (OverdueBooks(account, i))
		{
			account->borrow.fine[i] = (time(NULL) - account->borrow.dueDate[i]) / 24.0 / 3600 * g_fineRate;
		}
		printf("%-4d  %-20s  %-30s  %-6.2f  %-24s  %-24s  %-8d  %-6.2f\n", i + 1,
			account->borrow.booksOnLoan[i].bookNumber, account->borrow.booksOnLoan[i].title,
			account->borrow.booksOnLoan[i].money, borrowDate, dueDate, OverdueBooks(account, i),
			account->borrow.fine[i]);
	}
}