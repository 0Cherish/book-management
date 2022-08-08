#include "statement.h"

//���߽���������
void ReaderBorrowingRanking(User* account)
{
	User* big, * i, * j, * k;
	for (i = user_head; i->next; i = i->next)
	{
		k = i;
		for (j = i; j->next; j = j->next)
		{
			if (j->next->borrow.numberOfLoans > k->next->borrow.numberOfLoans)
			{
				k = j;
			}
		}
		if (i != k)
		{
			big = k->next;
			k->next = big->next;
			big->next = i->next;
			i->next = big;
		}
	}
	BrowseTheUser(account);
}

//ͼ�����������
void BookLoanVolumeRanking()
{
	Book* big, * i, * j, * k;
	for (i = book_head; i->next; i = i->next)
	{
		k = i;
		for (j = i; j->next; j = j->next)
		{
			if (j->next->numberOfBooksBorrowed > k->next->numberOfBooksBorrowed)
			{
				k = j;
			}
		}
		if (i != k)
		{
			big = k->next;
			k->next = big->next;
			big->next = i->next;
			i->next = big;
		}
	}
	BrowseBooks();
}