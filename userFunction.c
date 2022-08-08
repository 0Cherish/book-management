#include "statement.h"

//用户注册
void UserRegistration()
{
	char name[30] = { '\0' };
	char ID[10] = { '\0' };
	char password[20] = { '\0' };
	char password1[20] = { '\0' };
	char gender[10] = { '\0' };
	char position[10] = { '\0' };
	int theClass = 0;
	int uppercase = 0, lowercase = 0, num = 0, other = 0;
	char op;

	while (1)
	{
		printf("**********************************************************\n");
		printf("*                       用户注册                         *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*            请输入对应数字进行操作                      *\n");
		printf("*                                                        *\n");
		printf("*            1.用户名                                    *\n");
		printf("*            2.学工号（ID）                              *\n");
		printf("*            3.用户密码(8-16个字符，至少含有3种字符)     *\n");
		printf("*            4.性别（male/female）                       *\n");
		printf("*            5.职务（职务/学生选其一）                   *\n");
		printf("*            6.学生（填班级）                            *\n");
		printf("*            7.确认注册                                  *\n");
		printf("*            0.返回上一界面                              *\n");
		printf("*                                                        *\n");
		printf("**********************************************************\n");
		printf("姓名：%s；学工号：%s；密码：%s；性别：%s；职务：%s；班级：%d\n",
			name, ID, password, gender, position, theClass);

		op = getch();
		switch (op)
		{
		case '1':
			printf("请输入你的用户名：\n");
			scanf("%s", name);
			break;
		case '2':
			while (1)
			{
				printf("请输入你的学工号：\n");
				scanf("%s", ID);
				if (FindTheUserId(ID)) {
					printf("该ID已存在，请尝试其他的ID！\n");
				}
				else break;
			}
			break;
		case '3':
			while (1)
			{
				printf("请输入你的用户密码：\n");
				scanf("%s", password);
				printf("请再次输入你的用户密码：\n");
				scanf("%s", password1);
				if (strcmp(password, password1))
				{
					printf("两次输入的密码不相同，请核对后再输入密码！\n");
				}
				else
				{
					for (int i = 0; password[i]; i++)
					{
						if (password[i] >= '0' && password[i] <= '9')
						{
							num = 1;
						}
						else if (password[i] >= 'a' && password[i] <= 'z')
						{
							lowercase = 1;
						}
						else if (password[i] >= 'A' && password[i] <= 'Z')
						{
							uppercase = 1;
						}
						else
						{
							other = 1;
						}
					}
					if ((num + uppercase + lowercase + other) < 3 || strlen(password) < 8 ||
						strlen(password) > 16)
					{
						printf("输入的密码不符合要求，请重新输入！\n");
					}
					else break;
				}

			}
			break;
		case '4':
			while (1)
			{
				printf("请输入你的性别：\n");
				scanf("%s", gender);
				if (strcmp(gender, "female") && strcmp(gender, "male"))
				{
					printf("输入的字符不符合要求，请重新输入！\n");
				}
				else break;
			}break;
		case '5':
			printf("请输入你的职务：\n");
			scanf("%s", position);
			theClass = 0;
			break;
		case '6':
			printf("请输入你的班级：\n");
			scanf("%d", &theClass);
			strcpy(position, "");
			break;
		case '7':
			if (name[0] && ID[0] && password[0] && gender[0] && (position[0] || theClass))
			{
				CreateAUser(name, ID, password, gender, position, theClass);
				printf("注册成功,即将回到上一界面......");
				Sleep(2000);
				system("cls");
				return;
			}
			else
			{
				printf("请输入完整信息后重试！\n");
			}
			break;
		case '0':system("cls"); return;
		default:printf("%c\t指令错误，请重新输入!\n", op);
		}
		system("cls");
	}
}

//借阅图书
void BorrowBooks(User* account)
{
	while (1)
	{
		int n = account->borrow.numberOfLoans, max = 10;
		if (n == max)
		{
			printf("借阅图书数量 %d 本，已达上限 %d 本，请先归还部分图书！\n", n, max);
			return;
		}
		BrowseBooks();
		printf("请输入您需要借阅的书籍序号(输入 0 退出操作)：\n");
		int count;
		scanf("%d", &count);
		if (count == 0)
		{
			printf("已成功退出借阅图书！\n");
			system("pause");
			return;
		}
		else if (count > book_amount || count < 0)
		{
			printf("请正确输入上图中已有的图书序号！\n");
		}
		else
		{
			Book* t = book_head->next;
			for (int i = 1; i < count; i++)
			{
				t = t->next;
			}
			t->currentNumberOfBooks--;
			t->numberOfBooksBorrowed++;
			account->borrow.numberOfLoans++;
			account->borrow.booksOnLoan[n] = *t;
			account->borrow.fine[n] = 0;
			account->borrow.borrowDate[n] = time(NULL);
			account->borrow.dueDate[n] = time(NULL) + g_maxday * 3600 * 24;
			Storage();
			printf("借阅图书《%s》成功,即将返回上一界面！\n", t->title);
			Sleep(2000);
			system("cls");
			return;
		}
	}
}

//还书管理
void ReturnABook(User* account)
{
	HistoryOfBorrowing(account);
	if (!account->borrow.numberOfLoans)
	{
		printf("没有已借的图书!");
		system("pause");
		return;
	}
	printf("请输入您需要归还的书籍序号（输入0以退出还书系统）\n");
	int count = 0;
	scanf("%d", &count);
	if (count == 0)
	{
		printf("已成功退出还书管理！\n");
		system("pause");
		return;
	}
	if (count > account->borrow.numberOfLoans || count < 0)
	{
		printf("请正确输入上述书籍序号！\n");
		system("pause");
		return;
	}
	else
	{
		if (OverdueBooks(account, count - 1))
		{
			printf("由于您未在指定日期内归还《%s》,请联系管理员支付罚金%.2f元！\n",
				account->borrow.booksOnLoan[count - 1].title, account->borrow.fine[count - 1]);
			system("pause");
			return;
		}
		else
		{
			char title[30];
			strcpy(title, account->borrow.booksOnLoan[count - 1].title);
			for (int i = count - 1; i < account->borrow.numberOfLoans; i++)
			{
				account->borrow.booksOnLoan[i] = account->borrow.booksOnLoan[i + 1];
				account->borrow.borrowDate[i] = account->borrow.borrowDate[i + 1];
				account->borrow.dueDate[i] = account->borrow.dueDate[i + 1];
				account->borrow.fine[i] = account->borrow.fine[i];
			}
			account->borrow.numberOfLoans--;
			Book* t = book_head->next;
			while (t)
			{
				if (!strcmp(account->borrow.booksOnLoan[count - 1].bookNumber, t->bookNumber))
				{
					t->numberOfBooksBorrowed--;
					t->currentNumberOfBooks++;
					break;
				}
				t = t->next;
			}
			Storage();
			printf("书籍《%s》归还成功,即将返回上一界面！\n", title);
			Sleep(2000);
			system("cls");
			return;
		}
	}
}

//修改账号信息
void ChangeUserInformation(User* account)
{
	char name[30] = { '\0' };
	char ID[10] = { '\0' };
	char password[20] = { '\0' };
	char password1[20] = { '\0' };
	char gender[10] = { '\0' };
	char position[10] = { '\0' };
	int theClass = 0;
	char op;
	int num = 0, uppercase = 0, lowercase = 0, other = 0;

	while (1)
	{
		printf("**********************************************************\n");
		printf("*                    修改账户信息                        *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*             请输入对应数字进行操作                     *\n");
		printf("*                                                        *\n");
		printf("*               1.用户名                                 *\n");
		printf("*               2.学工号（ID）                           *\n");
		printf("*               3.用户密码(8-16个字符，至少含有3种字符)  *\n");
		printf("*               4.性别（male/female）                    *\n");
		printf("*               5.教师                                   *\n");
		printf("*               6.学生（填班级）                         *\n");
		printf("*               7.确认修改                               *\n");
		printf("*               0.返回上一界面                           *\n");
		printf("*                                                        *\n");
		printf("**********************************************************\n");
		printf("姓名：%s；学工号：%s；密码：%s；性别：%s；教师：%s；班级：%d\n",
			name, ID, password, gender, position, theClass);

		op = getch();
		switch (op)
		{
		case '1':
			printf("请输入你的用户名：\n");
			scanf("%s", name);
			break;
		case '2':
			while (1)
			{
				printf("请输入你的学工号：\n");
				scanf("%s", ID);
				if (FindTheUserId(ID) != NULL) {
					printf("该ID已存在，请尝试其他的ID！\n");
				}
				else break;
			}
			break;
		case '3':
			while (1)
			{
				printf("请输入原密码：\n");
				scanf("%s", password);
				printf("请输入修改后的密码：\n");
				scanf("%s", password1);
				if (strcmp(account->password, password))
				{
					printf("原密码输入错误，请核对后再输入密码！\n");
				}
				else
				{
					for (int i = 0; password1[i]; i++)
					{
						if (password1[i] >= '0' && password1[i] <= '9')
						{
							num = 1;
						}
						else if (password1[i] >= 'a' && password1[i] <= 'z')
						{
							lowercase = 1;
						}
						else if (password1[i] >= 'A' && password1[i] <= 'Z')
						{
							uppercase = 1;
						}
						else
						{
							other = 1;
						}
					}
					if ((num + uppercase + lowercase + other) < 3 || strlen(password1) < 8 || strlen(password1) > 16)
					{
						printf("输入的新密码不符合要求，请重新输入！\n");
					}
					else break;
				}

			}
			break;
		case '4':
			while (1)
			{
				printf("请输入你的性别：\n");
				scanf("%s", gender);
				if (strcmp(gender, "female") && strcmp(gender, "male"))
				{
					printf("输入的字符不符合要求，请重新输入！\n");
				}
				else break;
			}break;
		case '5':
			printf("请输入你的班级：\n");
			scanf("%s", position);
			theClass = 0;
			break;
		case '6':
			printf("请输入你的班级：\n");
			scanf("%d", &theClass);
			strcpy(position, "");
			break;
		case '7':
			if (name[0])
			{
				strcpy(account->name, name);
			}
			if (ID[0])
			{
				strcpy(account->ID, ID);
			}
			if (password1[0])
			{
				strcpy(account->password, password1);
			}
			if (gender[0])
			{
				strcpy(account->gender, gender);
			}
			if (position[0])
			{
				strcpy(account->position, position);
			}
			if (theClass)
			{
				account->theClass = theClass;
			}
			Storage();
			printf("个人信息修改成功，正在返回上一界面...\n");
			Sleep(2000);
			system("cls");
			return;
		case '0':system("cls"); return;
		default:printf("%c\t指令错误，请重新输入!\n", op);
		}
		system("cls");
	}
}

//注销账号
void DeleteAUser(User* account)
{
	printf("**********************************************************\n");
	printf("*                       注销账号                         *\n");
	printf("*--------------------------------------------------------*\n");
	if (account == user_head)
	{
		printf("用户拥有最高权限，不可被删除！！！\n");
		system("pause");
		return;
	}
	printf("是否需要删除账号？\n");
	printf("请输入相应数字以继续操作！\n");
	printf("1、是\t0、否\n");

	int op;
	scanf("%d", &op);
	if (op == 1)
	{
		if (account->borrow.numberOfLoans)
		{
			printf("删除失败！该用户有%d本图书未归还！请先归还所借阅图书！\n",
				account->borrow.numberOfLoans);
		}
		else
		{
			User* t = user_head, * last = user_head;
			while (t)
			{
				if (account == t)
				{
					last->next = t->next;
					free(t);
					user_amount--;
					Storage();
					printf("账号已删除成功！\n");
					Sleep(2000);
					system("cls");
					return;
				}
				last = t;
				t = t->next;
			}
		}
	}
	else if (!op)
	{
		printf("已取消本次操作！\n");
	}
	else
	{
		printf("输入选项错误，请重新输入！\n");
	}
	system("pause");
}