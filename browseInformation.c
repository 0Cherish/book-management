#include "statement.h"

//浏览用户
void BrowseTheUser(User* account)
{
	int count = 1;
	User* t = user_head;
	printf("%-4s  %-10s  %-30s  %-20s  %-10s  %-6s  %-6s  %-11s  %-12s\n",
		"序号", "学工号", "姓名", "密码", "性别", "管理员", "可登录", "职务/班级", "借阅书籍数量");
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

//浏览逾期书籍
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
		"序号", "图书编号", "书名", "作者", "类别", "借阅人姓名", "ID", "借阅日期", "到期日期");
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

//浏览图书
void BrowseBooks()
{
	if (!book_amount)
	{
		printf("馆内暂无图书资料，请联系管理员添加书籍！\n");
		return;
	}
	Book* t = book_head->next;
	int i = 1;
	printf("%-4s  %-20s  %-30s  %-20s  %-30s  %-8s  %-6s  %-10s  %-8s  %-8s  %-10s\n",
		"序号", "图书编号", "书名", "作者", "出版社", "出版日期", "金额", "类别", "图书数量",
		"当前库存", "已借图书量");
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

//历史借阅
void HistoryOfBorrowing(User* account)
{
	if (!account->borrow.numberOfLoans)
	{
		printf("暂无借阅记录！\n");
		return;
	}
	printf("%-4s  %-20s  %-30s  %-6s  %-24s  %-24s  %-8s  %-8s\n",
		"序号", "图书编号", "书名", "金额", "借书日期", "到期日期", "是否逾期", "罚款金额");
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