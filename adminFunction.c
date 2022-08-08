#include "statement.h"

//图书管理
void BooksManagement()
{
	char op;

	while (1)
	{
		printf("**********************************************************\n");
		printf("*                       图书管理                         *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*                 请输入对应数字进行操作                 *\n");
		printf("*                                                        *\n");
		printf("*                    1.增加图书信息                      *\n");
		printf("*                    2.修改图书信息                      *\n");
		printf("*                    3.删除图书信息                      *\n");
		printf("*                    4.图书浏览                          *\n");
		printf("*                    5.图书查找                          *\n");
		printf("*                    0.返回上一界面                      *\n");
		printf("*                                                        *\n");
		printf("**********************************************************\n");

		op = getch();
		switch (op)
		{
		case '1':system("cls"); AddingBookInformation(); break;
		case '2':system("cls"); ChangingBookInformation(); break;
		case '3':system("cls"); DeletingBookInformation(); break;
		case '4':system("cls"); BrowseBooks(); system("pause"); break;
		case '5':system("cls"); SearchBooks(); break;
		case '0':system("cls"); return;
		default:printf("%c\t指令错误，请重新输入!\n", op);
		}
		system("cls");
	}
}

//增加图书信息
void AddingBookInformation()
{
	char bookNumber[20] = { '\0' };
	char title[30] = { '\0' };
	char author[20] = { '\0' };
	char publisher[30] = { '\0' };
	int year = 0, month = 0;
	double money = 0;
	char category[10] = { '\0' };
	int newnumber = 0;
	char op;

	while (1)
	{
		printf("**********************************************************\n");
		printf("*                    增加图书信息                        *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*               请输入对应数字进行操作                   *\n");
		printf("*                                                        *\n");
		printf("*                    1.图书编号                          *\n");
		printf("*                    2.书名                              *\n");
		printf("*                    3.作者                              *\n");
		printf("*                    4.出版社                            *\n");
		printf("*                    5.出版日期（年 月）                 *\n");
		printf("*                    6.金额                              *\n");
		printf("*                    7.类别                              *\n");
		printf("*                    8.增加数量                          *\n");
		printf("*                    9.确认操作                          *\n");
		printf("*                    0.返回上一界面                      *\n");
		printf("*                                                        *\n");
		printf("**********************************************************\n");
		printf("图书编号：%s；书名：%s；作者：%s；出版社：%s；\n",
			bookNumber, title, author, publisher);
		printf("出版日期：%d-%d；金额：%.2f；类别：%s；增加数量：%d\n",
			year, month, money, category, newnumber);

		op = getch();

		switch (op)
		{
		case '1':
			printf("请输入图书的编号：\n");
			scanf("%s", bookNumber);
			break;
		case '2':
			printf("请输入书名：\n");
			scanf("%s", title);
			break;
		case '3':
			printf("请输入图书的作者：\n");
			scanf("%s", author);
			break;
		case '4':
			printf("请输入图书的出版社：\n");
			scanf("%s", publisher);
			break;
		case '5':
			printf("请输入图书的出版日期（年 月）：\n");
			scanf("%d %d", &year, &month);
			break;
		case '6':
			printf("请输入图书的金额：\n");
			scanf("%lf", &money);
			break;
		case '7':
			printf("请输入图书的类别：\n");
			scanf("%s", category);
			break;
		case '8':
			printf("请输入增加图书的数量：\n");
			scanf("%d", &newnumber);
			break;
		case '9':
			if (bookNumber[0] && title[0] && author[0] && publisher[0] && year && month && money &&
				category[0] && newnumber)
			{
				CreateABook(bookNumber, title, author, publisher, year, month, money, category,
					newnumber);
				printf("操作成功,即将跳转到上一界面......");
				Sleep(2000);
				system("cls");
				return;
			}
			else
			{
				printf("请输入完整信息后重试！\n");
				Sleep(1000);
				break;
			}
		case '0':system("cls"); return;
		default:printf("%c\t指令错误，请重新输入\n", op);
		}
		system("cls");
	}
}

//修改图书信息
void ChangingBookInformation()
{
	BrowseBooks();
	printf("请输入待修改的书籍序号(输入 0 退出修改操作)：\n");
	int count;
	scanf("%d", &count);
	if (count == 0)
	{
		system("cls");
		return;
	}
	else if (count > book_amount || count < 0)
	{
		printf("请正确输入上图中待修改的图书序号！\n");
	}
	else
	{
		Book* t = book_head->next;
		int i = 1;

		while (t)
		{
			system("cls");
			if (i == count)
			{
				char bookNumber[20] = { '\0' };
				char title[30] = { '\0' };
				char author[20] = { '\0' };
				char publisher[30] = { '\0' };
				int year = 0, month = 0;
				double money = 0;
				char category[10] = { '\0' };
				int numberOfBooks = 0;
				char op;

				while (1)
				{
					printf("**********************************************************\n");
					printf("*                     修改图书信息                       *\n");
					printf("*--------------------------------------------------------*\n");
					printf("*                                                        *\n");
					printf("*                请输入对应数字进行操作                  *\n");
					printf("*                                                        *\n");
					printf("*                  1.修改图书编号                        *\n");
					printf("*                  2.修改书名                            *\n");
					printf("*                  3.修改作者                            *\n");
					printf("*                  4.修改出版社                          *\n");
					printf("*                  5.修改出版日期（年 月）               *\n");
					printf("*                  6.修改金额                            *\n");
					printf("*                  7.修改类别                            *\n");
					printf("*                  8.修改图书数量                        *\n");
					printf("*                  9.确认操作                            *\n");
					printf("*                  0.返回上一界面                        *\n");
					printf("*                                                        *\n");
					printf("**********************************************************\n");
					printf("图书编号：%s；书名：%s；作者：%s；出版社：%s；\n",
						bookNumber, title, author, publisher);
					printf("出版日期：%d-%d；金额：%.2f；类别：%s；图书数量：%d\n",
						year, month, money, category, numberOfBooks);

					op = getch();
					switch (op)
					{
					case '1':
						printf("请输入修改后的图书编号：\n");
						scanf("%s", bookNumber);
						break;
					case '2':
						printf("请输入修改后的书名：\n");
						scanf("%s", title);
						break;
					case '3':
						printf("请输入修改后的图书作者：\n");
						scanf("%s", author);
						break;
					case '4':
						printf("请输入修改后的图书出版社：\n");
						scanf("%s", publisher);
						break;
					case '5':
						printf("请输入修改后的图书出版日期（年 月）：\n");
						scanf("%d %d", &year, &month);
						break;
					case '6':
						printf("请输入修改后的图书金额：\n");
						scanf("%lf", &money);
						break;
					case '7':
						printf("请输入修改后的图书类别：\n");
						scanf("%s", category);
						break;
					case '8':
						printf("请输入修改后的图书数量：\n");
						scanf("%d", &numberOfBooks);
						if (numberOfBooks < t->numberOfBooksBorrowed)
						{
							printf("图书总数小于已借的图书数！");
							numberOfBooks = 0;
						}
						break;
					case '9':
						if (!bookNumber[0] && !title[0] && !author[0] && !publisher[0] &&
							!year && !month && !money && !category[0] && !numberOfBooks)
						{
							printf("请输入修改后的信息重试！\n");

						}
						else {
							if (bookNumber[0])
							{
								strcpy(t->bookNumber, bookNumber);
							}
							if (title[0])
							{
								strcpy(t->title, title);
							}
							if (author[0])
							{
								strcpy(t->author, author);
							}
							if (publisher[0])
							{
								strcpy(t->publisher, publisher);
							}
							if (year)
							{
								t->yearOfPublication = year;
							}
							if (month)
							{
								t->monthOfPublication = month;
							}
							if (money)
							{
								t->money = money;
							}
							if (category[0])
							{
								strcpy(t->category, category);
							}
							if (numberOfBooks)
							{
								t->numberOfBooks = numberOfBooks;
								t->currentNumberOfBooks = t->numberOfBooks - t->numberOfBooksBorrowed;
							}
							Storage();
							printf("操作成功,即将跳转到上一界面......");
							Sleep(2000);
							system("cls");
							return;
						}
					case '0':system("cls"); return;
					default:printf("%c\t指令错误，请重新输入\n", op);
					}
					system("cls");
				}
				break;
			}
			t = t->next;
			i++;
		}
	}
	system("cls");
	return;
}

//删除图书信息
void DeletingBookInformation()
{
	int count, delete_num;
	char title[30];

	BrowseBooks();
	printf("请输入待删除的书籍序号(输入 0 退出删除操作)：\n");
	scanf("%d", &count);
	if (count == 0)
	{
		printf("已成功取消该操作！\n");
		system("pause");
		system("cls");
		return;
	}
	else if (count > book_amount || count < 0)
	{
		printf("请正确输入上图中待删除的图书序号！\n");
	}
	else
	{
		printf("请输入需要删除的图书本数：");
		scanf("%d", &delete_num);
		Book* t = book_head, * last;
		for (int i = 1; i <= count; i++)
		{
			last = t;
			t = t->next;
		}
		strcpy(title, t->title);
		if (delete_num > t->currentNumberOfBooks)
		{
			printf("超过现有图书！");
		}
		else if (delete_num == t->currentNumberOfBooks && !t->numberOfBooksBorrowed)
		{
			last->next = t->next;
			free(t);
			book_amount--;
			Storage();
			printf("已删除全部《%s》！\n", title);
		}
		else
		{
			t->numberOfBooks -= delete_num;
			t->currentNumberOfBooks -= delete_num;
			printf("已删除%d本《%s》!\n", delete_num, title);
		}
	}
	system("pause");
	system("cls");
}

//账户管理
void AccountManagement(User* account)
{
	char op;
	int num;

	while (1)
	{
		printf("**********************************************************\n");
		printf("*                       账户管理                         *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*                请输入对应数字进行操作                  *\n");
		printf("*                                                        *\n");
		printf("*                  1.查看用户信息                        *\n");
		printf("*                  2.修改用户信息                        *\n");
		printf("*                  3.支付罚金                            *\n");
		printf("*                  4.账户挂失                            *\n");
		printf("*                  5.注销账户                            *\n");
		printf("*                  6.用户借阅情况                        *\n");
		printf("*                  7.设置管理员                          *\n");
		printf("*                  0.退出上一界面                        *\n");
		printf("*                                                        *\n");
		printf("**********************************************************\n");

		op = getch();
		switch (op)
		{
		case '1':system("cls"); BrowseTheUser(account); system("pause"); break;
		case '2':
			system("cls");
			BrowseTheUser(account);
			printf("请输入待操作的用户序号：\n");
			scanf("%d", &num);
			if (num > user_amount || num <= 0)
			{
				printf("请正确输入上图中待操作的用户序号！\n");
			}
			else
			{
				User* t = user_head;
				for (int i = 1; i < num; i++)
				{
					t = t->next;
				}
				if (t->admin && account != user_head)
				{
					printf("您没有该权限！\n");
				}
				system("cls");
				ChangeUserInformation(t);
				break;
			}
			system("pause");
			break;
		case '3':system("cls");
			if (!BrowsingOverdueBooks())
			{
				printf("暂无逾期书籍！\n");
				system("pause");
				break;
			}
			printf("请输入待操作的序号：\n");
			scanf("%d", &num);

			User* t = user_head;
			int i, count = 0, flag = 0;
			while (t)
			{
				for (i = 0; i < t->borrow.numberOfLoans; i++) {
					if (OverdueBooks(t, i))
					{
						count++;
						if (num == count)
						{
							t->borrow.fine[i] = 0;
							t->borrow.borrowDate[i] = time(NULL);
							t->borrow.dueDate[i] = time(NULL) + g_maxday * 24 * 3600;
							flag = 1;
							break;
						}
					}
				}
				if (flag == 1)
				{
					break;
				}
				t = t->next;
			}
			if (flag == 0)
			{
				printf("请正确输入上图中待操作的用户序号！\n");
			}
			else
			{
				printf("罚金已清零！\n");
				Storage();
			}
			system("pause");
			break;
		case '4':system("cls"); BrowseTheUser(account);
			printf("请输入待操作的用户序号：\n");
			scanf("%d", &num);
			if (num == 1)
			{
				printf("此账户拥有最高权限，不可更改！");
			}
			else if (num > user_amount || num <= 0)
			{
				printf("请正确输入上图中待操作的用户序号！\n");
			}
			else
			{
				User* t = user_head;
				for (int i = 1; i < num; ++i)
				{
					t = t->next;
				}
				if (t->admin && account != user_head)
				{
					printf("您当前没有此权限！\n");
				}
				else
				{
					t->login = 0;
					printf("账户已挂失！\n");
				}
			}
			system("pause");
			break;
		case '5':
			system("cls");
			BrowseTheUser(account);
			printf("请输入待操作的用户序号：\n");
			scanf("%d", &num);
			if (num > user_amount || num <= 0)
			{
				printf("请正确输入上图中待操作的用户序号！\n");
			}
			else
			{
				User* t = user_head;
				for (int i = 1; i < num; ++i)
				{
					t = t->next;
				}
				if (t->admin && account != user_head)
				{
					printf("您没有该权限！\n");
				}
				else
				{
					system("cls");
					DeleteAUser(t);
				}
			}
			break;
		case '6':
			system("cls");
			BrowseTheUser(account);
			printf("请输入待操作的用户序号：\n");
			scanf("%d", &num);
			if (num > user_amount || num <= 0)
			{
				printf("请正确输入上图中待操作的用户序号！\n");
			}
			else
			{
				User* t = user_head;
				for (int i = 1; i < num; ++i)
				{
					t = t->next;
				}
				system("cls");
				HistoryOfBorrowing(t);
			}
			system("pause");
			break;
		case '7':
			system("cls");
			BrowseTheUser(account);
			printf("请正确输入上图中待操作的用户序号！\n");
			scanf("%d", &num);
			if (num > user_amount || num <= 0)
			{
				printf("请输入正确的序号！\n");
			}
			else
			{
				User* t = user_head;
				for (int i = 1; i < num; ++i)
				{
					t = t->next;
				}
				SettingAnAdmin(account, t);
			}
			system("pause");
			break;
		case '0':system("cls"); return;
		default:printf("%c\t指令错误，请重新输入\n", op);
		}
		system("cls");
	}
}

//设置管理员
void SettingAnAdmin(User* account, User* t)
{
	if (t == user_head)
	{
		printf("拥有最高管理权限，不可被修改！！！\n");
		return;
	}
	if (t->admin && account != user_head)
	{
		printf("您没有该权限！");
		return;
	}
	printf("请输入相应数字以继续操作！\n");
	printf("1、设置为管理员\t0、取消管理员权限\n");
	int op;

	scanf("%d", &op);
	if (op == 1)
	{
		t->admin = 1;
		printf("管理员权限设置成功！\n");
	}
	else if (op == 0)
	{
		t->admin = 0;
		printf("管理员权限已被取消！\n");
	}
	else
	{
		printf("设置管理员权限失败，请按要求输入！\n");
	}
	Storage();
}

//统计
void Statistic(User* account)
{
	char op;

	while (1)
	{
		printf("**********************************************************\n");
		printf("*                         统计                           *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*               请输入对应数字进行操作                   *\n");
		printf("*                                                        *\n");
		printf("*                  1.书籍借阅量排行                      *\n");
		printf("*                  2.读者借阅量排行                      *\n");
		printf("*                  3.浏览逾期书籍                        *\n");
		printf("*                  0.返回上一界面                        *\n");
		printf("*                                                        *\n");
		printf("**********************************************************\n");

		op = getch();
		switch (op)
		{
		case '1':system("cls"); BookLoanVolumeRanking(); system("pause"); break;
		case '2':system("cls"); ReaderBorrowingRanking(account); system("pause"); break;
		case '3':system("cls");
			if (!BrowsingOverdueBooks())
			{
				printf("暂无逾期书籍！\n");
			}
			system("pause"); break;
		case '0':system("cls"); return;
		default:printf("%c\t指令错误，请重新输入\n", op);
		}
		system("cls");
	}
}

//参数
void Parameter()
{
	char op;

	while (1)
	{
		printf("**********************************************************\n");
		printf("*                         参数                           *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*               请输入对应数字进行操作                   *\n");
		printf("*                                                        *\n");
		printf("*                 1.设置逾期书籍罚款率                   *\n");
		printf("*                 2.设置最多借阅天数                     *\n");
		printf("*                 0.返回上一界面                         *\n");
		printf("*                                                        *\n");
		printf("**********************************************************\n");
		printf("罚款率：%.2f；最大借阅天数：%d\n", g_fineRate, g_maxday);

		op = getch();
		switch (op)
		{
		case '1':
			printf("请输入罚款率：\n");
			scanf("%lf", &g_fineRate); break;
		case '2':
			printf("请输入最大借阅天数：\n");
			scanf("%d", &g_maxday); break;
		case '0':system("cls"); return;
		default:printf("%c\t指令错误，请重新输入\n", op);
		}
		Storage();
		system("cls");
	}
}