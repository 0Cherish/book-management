#include "statement.h"

//图书查询
void SearchBooks()
{
	char op;

	while (1)
	{
		printf("**********************************************************\n");
		printf("*                       图书查询                         *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*                  请输入对应数字进行操作                *\n");
		printf("*                                                        *\n");
		printf("*                    1、按图书编号查找                   *\n");
		printf("*                    2、按书名查找                       *\n");
		printf("*                    3、按作者查找                       *\n");
		printf("*                    4、按出版社查找                     *\n");
		printf("*                    0、返回上一界面                     *\n");
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
		default: printf("%c\t指令错误，请重新输入\n", op);
		}
		system("cls");
	}
}

//按出版社查找
void SearchByPublisher()
{
	Book* t = book_head->next;
	char publisher[30];
	int flag = 0;
	printf("请输入查找的出版社名称：\n");
	scanf("%s", publisher);
	while (t)
	{
		if (!strcmp(t->publisher, publisher))
		{
			if (flag == 0)
			{
				printf("%-20s  %-30s  %-20s  %-30s  %-8s  %-6s  %-10s  %-8s  %-8s  %-10s\n",
					"图书编号", "书名", "作者", "出版社", "出版日期", "金额", "类别", "图书数量",
					"当前库存", "已借图书量");
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
		printf("馆内暂无该出版社的书籍，请联系管理员添加书籍！\n");
	}
	system("pause");
}

//按作者查找
void SearchByAuthor()
{
	Book* t = book_head->next;
	char author[20];
	int flag = 0;
	printf("请输入查找的作者：\n");
	scanf("%s", author);
	while (t)
	{
		if (!strcmp(t->author, author))
		{
			if (flag == 0)
			{
				printf("%-20s  %-30s  %-20s  %-30s  %-8s  %-6s  %-10s  %-8s  %-8s  %-10s\n",
					"图书编号", "书名", "作者", "出版社", "出版日期", "金额", "类别", "图书数量",
					"当前库存", "已借图书量");
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
		printf("馆内暂无该作者的书籍，请联系管理员添加书籍！\n");
	}
	system("pause");
}

//按书名查找
void SearchByTitle()
{
	Book* t = book_head->next;
	char title[30];
	int flag = 0;
	printf("请输入查找的书名：\n");
	scanf("%s", title);
	while (t)
	{
		if (!strcmp(t->title, title))
		{
			if (flag == 0)
			{
				printf("%-20s  %-30s  %-20s  %-30s  %-8s  %-6s  %-10s  %-8s  %-8s  %-10s\n",
					"图书编号", "书名", "作者", "出版社", "出版日期", "金额", "类别", "图书数量",
					"当前库存", "已借图书量");
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
		printf("馆内暂无该书籍，请联系管理员添加书籍！\n");
	}
	system("pause");
}

//按图书编号查找
void SearchByBookNumber()
{
	Book* t = book_head->next;
	char bookNumber[20], flag = 0;
	printf("请输入查找的图书编号：\n");
	scanf("%s", bookNumber);
	while (t)
	{
		if (!strcmp(t->bookNumber, bookNumber))
		{
			printf("%-20s  %-30s  %-20s  %-30s  %-8s  %-6s  %-10s  %-8s  %-8s  %-10s\n",
				"图书编号", "书名", "作者", "出版社", "出版日期", "金额", "类别", "图书数量",
				"当前库存", "已借图书量");
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
		printf("馆内暂无该书籍，请联系管理员添加书籍！\n");
	}
	system("pause");
}