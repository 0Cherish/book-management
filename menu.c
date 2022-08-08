#include "statement.h"

//欢迎界面
void Welcome()
{
	ToLoad();

	char op;

	while (1)
	{
		printf("**********************************************************\n");
		printf("*                 欢迎使用图书管理借阅系统               *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*                 请输入对应数字进行操作                 *\n");
		printf("*                                                        *\n");
		printf("*                    1.进入系统                          *\n");
		printf("*                    2.查看说明                          *\n");
		printf("*                    0.退出系统                          *\n");
		printf("*                                                        *\n");
		printf("**********************************************************\n");

		op = getch();
		switch (op)
		{
		case '1': system("cls"); MainMenu(); break;
		case '2': system("cls"); ServiceManual(); system("pause"); break;
		case '0': system("cls"); return;
		default:printf("%c\t指令错误，请重新输入!\n", op);
		}
		system("cls");
	}
}

//使用手册
void ServiceManual()
{
	printf("*******************************************************************************\n");
	printf("*                         图书借阅管理系统使用说明                            *\n");
	printf("*-----------------------------------------------------------------------------*\n");
	printf("*                                                                             *\n");
	printf("*1.该系统所有操作均可通过键盘输入实现                                         *\n");
	printf("*  用户仅需要输入功能界面上的数字就能够实现对应的操作                         *\n");
	printf("*2.用户需要严格按照括号内的文字进行输入（如若没有说明，则例外）               *\n");
	printf("*  例如：在用户注册时需要输入性别，用户需要输入female或者male                 *\n");
	printf("*3.（1）该系统初始化时即拥有一个超级管理员账号，该账号拥有该系统的一切权限。  *\n");
	printf("*       除此之外，该系统的使用对象主要分为两类：普通用户和管理员。            *\n");
	printf("*  （2）普通用户拥有权限：                                                    *\n");
	printf("*       账号注册                                                              *\n");
	printf("*       账号信息修改                                                          *\n");
	printf("*       查看历史借阅                                                          *\n");
	printf("*       浏览馆内图书                                                          *\n");
	printf("*       查询图书                                                              *\n");
	printf("*       实现借阅和归还                                                        *\n");
	printf("*  （3）管理员拥有普通用户所拥有的权限，此外还能：                            *\n");
	printf("*       管理图书（增加，修改或者删除图书信息）                                *\n");
	printf("*       管理系统账号（查看所有用户全部信息，账号挂失，账号注销）              *\n");
	printf("*       统计分析（书籍借阅量，读者借阅量，逾期书籍）                          *\n");
	printf("*       设置系统参数（最大借阅天数，逾期书籍罚款率）                          *\n");
	printf("*******************************************************************************\n");
}

//主菜单
void MainMenu()
{
	char op;

	while (1)
	{
		printf("**********************************************************\n");
		printf("*                 图书借阅管理借阅系统                   *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*                 请输入对应数字进行操作                 *\n");
		printf("*                                                        *\n");
		printf("*                    1.用户注册                          *\n");
		printf("*                    2.用户登录                          *\n");
		printf("*                    3.管理员登录                        *\n");
		printf("*                    0.返回上一界面                      *\n");
		printf("*                                                        *\n");
		printf("**********************************************************\n");

		op = getch();
		switch (op)
		{
		case '1':system("cls"); UserRegistration(); break;
		case '2':system("cls"); UsersLogin(); break;
		case '3':system("cls"); AdminLogin(); break;
		case '0':system("cls"); return;
		default:printf("%c\t指令错误，请重新输入!\n", op);
		}
		system("cls");
	}
}

//用户登录
void UsersLogin()
{
	char ID[10] = { '\0' };
	char password[20] = { '\0' };
	User* account;
	char op;

	while (1)
	{
		printf("**********************************************************\n");
		printf("*                       用户登录                         *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*                请输入对应数字进行操作                  *\n");
		printf("*                                                        *\n");
		printf("*                  1.用户ID（学工号）                    *\n");
		printf("*                  2.用户密码                            *\n");
		printf("*                  3.确认登录                            *\n");
		printf("*                  0.返回上一界面                        *\n");
		printf("*                                                        *\n");
		printf("**********************************************************\n");
		printf("学工号：%s；密码：%s\n", ID, password);

		op = getch();
		switch (op)
		{
		case '1':
			printf("请输入你的ID：\n");
			scanf("%s", ID);
			break;
		case '2':
			printf("请输入你的密码：\n");
			scanf("%s", password);
			break;
		case '3':
			if (account = ComparingAccountPasswords(ID, password))
			{
				if (!account->login)
				{
					printf("当前状态不可登录，请联系管理员！");
				}
				else
				{
					printf("登录成功,即将跳转到用户界面......");
					Sleep(2000);
					system("cls");
					UserMenu(account);
					return;
				}
			}
			else
			{
				printf("输入的用户名或者密码错误，请核对后重试！\n");
			}
			break;
		case '0':system("cls"); return;
		default:printf("%c\t指令错误，请重新输入!\n", op);
		}
		system("cls");
	}
}

//用户菜单
void UserMenu(User* account)
{
	char op;

	while (1)
	{
		printf("**********************************************************\n");
		printf("*                     用户菜单                           *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*                 请输入对应数字进行操作                 *\n");
		printf("*                                                        *\n");
		printf("*                    1.历史借阅                          *\n");
		printf("*                    2.图书浏览                          *\n");
		printf("*                    3.图书查询                          *\n");
		printf("*                    4.借阅图书                          *\n");
		printf("*                    5.还书管理                          *\n");
		printf("*                    6.修改账号信息                      *\n");
		printf("*                    7.注销账号                          *\n");
		printf("*                    0.退出登录                          *\n");
		printf("*                                                        *\n");
		printf("**********************************************************\n");

		op = getch();
		switch (op)
		{
		case '1':system("cls"); HistoryOfBorrowing(account); system("pause"); break;
		case '2':system("cls"); BrowseBooks(); system("pause");  break;
		case '3':system("cls"); SearchBooks();  break;
		case '4':system("cls"); BorrowBooks(account); break;
		case '5':system("cls"); ReturnABook(account); break;
		case '6':system("cls"); ChangeUserInformation(account); break;
		case '7':system("cls"); DeleteAUser(account); break;
		case '0':system("cls"); return;
		default:printf("%c\t指令错误，请重新输入\n", op);
		}
		system("cls");
	}
}

//管理员登录
void AdminLogin()
{
	char ID[20] = { '\0' };
	char password[20] = { '\0' };
	User* account;
	char op;

	while (1) {
		printf("**********************************************************\n");
		printf("*                       管理员登录                       *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*                请输入对应数字进行操作                  *\n");
		printf("*                                                        *\n");
		printf("*                   1.管理员ID                           *\n");
		printf("*                   2.管理员密码                         *\n");
		printf("*                   3.确认登录                           *\n");
		printf("*                   0.返回主界面                         *\n");
		printf("*                                                        *\n");
		printf("**********************************************************\n");
		printf("学工号：%s；密码：%s\n", ID, password);

		op = getch();
		switch (op) {
		case '1':
			printf("请输入你的ID：\n");
			scanf("%s", ID);
			break;
		case '2':
			printf("请输入你的密码：\n");
			scanf("%s", password);
			break;
		case '3':
			if (account = ComparingAccountPasswords(ID, password))
			{
				if (!account->login)
				{
					printf("当前状态不可登录，请联系超级管理员！");
				}
				else {
					printf("登录成功,即将跳转到管理员界面......");
					Sleep(2000);
					system("cls");
					AdminMenu(account);
					return;
				}
			}
			else
			{
				printf("输入的用户名或者密码错误，请核对后重试！");
			}
			break;
		case '0':
			system("cls");
			return;
		default:
			printf("%c\t指令错误，请重新输入!\n", op);
		}
		system("cls");
	}
}

//管理员菜单
void AdminMenu(User* account)
{
	char op;

	while (1) {
		printf("**********************************************************\n");
		printf("*                       管理员                           *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*               请输入对应数字进行操作                   *\n");
		printf("*                                                        *\n");
		printf("*                   1.图书管理                           *\n");
		printf("*                   2.账户管理                           *\n");
		printf("*                   3.统计                               *\n");
		printf("*                   4.设置参数                           *\n");
		printf("*                   0.退出登录                           *\n");
		printf("*                                                        *\n");
		printf("**********************************************************\n");

		op = getch();
		switch (op) {
		case '1': system("cls"); BooksManagement(); break;
		case '2': system("cls"); AccountManagement(account); break;
		case '3': system("cls"); Statistic(account); break;
		case '4': system("cls"); Parameter(); break;
		case '0': system("cls"); return;
		default:printf("%c\t指令错误，请重新输入\n", op);
		}
		system("cls");
	}
}

//程序结束
void End()
{
	printf("*****************感谢使用图书管理借阅系统*****************\n");
	printf("*                                                        *\n");
	printf("*                                                        *\n");
	printf("*                                                        *\n");
	printf("*                     退出系统成功！                     *\n");
	printf("*                                                        *\n");
	printf("*                                                        *\n");
	printf("**********************************************************\n");
}