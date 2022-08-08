#include "statement.h"

//��ӭ����
void Welcome()
{
	ToLoad();

	char op;

	while (1)
	{
		printf("**********************************************************\n");
		printf("*                 ��ӭʹ��ͼ��������ϵͳ               *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*                 �������Ӧ���ֽ��в���                 *\n");
		printf("*                                                        *\n");
		printf("*                    1.����ϵͳ                          *\n");
		printf("*                    2.�鿴˵��                          *\n");
		printf("*                    0.�˳�ϵͳ                          *\n");
		printf("*                                                        *\n");
		printf("**********************************************************\n");

		op = getch();
		switch (op)
		{
		case '1': system("cls"); MainMenu(); break;
		case '2': system("cls"); ServiceManual(); system("pause"); break;
		case '0': system("cls"); return;
		default:printf("%c\tָ���������������!\n", op);
		}
		system("cls");
	}
}

//ʹ���ֲ�
void ServiceManual()
{
	printf("*******************************************************************************\n");
	printf("*                         ͼ����Ĺ���ϵͳʹ��˵��                            *\n");
	printf("*-----------------------------------------------------------------------------*\n");
	printf("*                                                                             *\n");
	printf("*1.��ϵͳ���в�������ͨ����������ʵ��                                         *\n");
	printf("*  �û�����Ҫ���빦�ܽ����ϵ����־��ܹ�ʵ�ֶ�Ӧ�Ĳ���                         *\n");
	printf("*2.�û���Ҫ�ϸ��������ڵ����ֽ������루����û��˵���������⣩               *\n");
	printf("*  ���磺���û�ע��ʱ��Ҫ�����Ա��û���Ҫ����female����male                 *\n");
	printf("*3.��1����ϵͳ��ʼ��ʱ��ӵ��һ����������Ա�˺ţ����˺�ӵ�и�ϵͳ��һ��Ȩ�ޡ�  *\n");
	printf("*       ����֮�⣬��ϵͳ��ʹ�ö�����Ҫ��Ϊ���ࣺ��ͨ�û��͹���Ա��            *\n");
	printf("*  ��2����ͨ�û�ӵ��Ȩ�ޣ�                                                    *\n");
	printf("*       �˺�ע��                                                              *\n");
	printf("*       �˺���Ϣ�޸�                                                          *\n");
	printf("*       �鿴��ʷ����                                                          *\n");
	printf("*       �������ͼ��                                                          *\n");
	printf("*       ��ѯͼ��                                                              *\n");
	printf("*       ʵ�ֽ��ĺ͹黹                                                        *\n");
	printf("*  ��3������Աӵ����ͨ�û���ӵ�е�Ȩ�ޣ����⻹�ܣ�                            *\n");
	printf("*       ����ͼ�飨���ӣ��޸Ļ���ɾ��ͼ����Ϣ��                                *\n");
	printf("*       ����ϵͳ�˺ţ��鿴�����û�ȫ����Ϣ���˺Ź�ʧ���˺�ע����              *\n");
	printf("*       ͳ�Ʒ������鼮�����������߽������������鼮��                          *\n");
	printf("*       ����ϵͳ�����������������������鼮�����ʣ�                          *\n");
	printf("*******************************************************************************\n");
}

//���˵�
void MainMenu()
{
	char op;

	while (1)
	{
		printf("**********************************************************\n");
		printf("*                 ͼ����Ĺ������ϵͳ                   *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*                 �������Ӧ���ֽ��в���                 *\n");
		printf("*                                                        *\n");
		printf("*                    1.�û�ע��                          *\n");
		printf("*                    2.�û���¼                          *\n");
		printf("*                    3.����Ա��¼                        *\n");
		printf("*                    0.������һ����                      *\n");
		printf("*                                                        *\n");
		printf("**********************************************************\n");

		op = getch();
		switch (op)
		{
		case '1':system("cls"); UserRegistration(); break;
		case '2':system("cls"); UsersLogin(); break;
		case '3':system("cls"); AdminLogin(); break;
		case '0':system("cls"); return;
		default:printf("%c\tָ���������������!\n", op);
		}
		system("cls");
	}
}

//�û���¼
void UsersLogin()
{
	char ID[10] = { '\0' };
	char password[20] = { '\0' };
	User* account;
	char op;

	while (1)
	{
		printf("**********************************************************\n");
		printf("*                       �û���¼                         *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*                �������Ӧ���ֽ��в���                  *\n");
		printf("*                                                        *\n");
		printf("*                  1.�û�ID��ѧ���ţ�                    *\n");
		printf("*                  2.�û�����                            *\n");
		printf("*                  3.ȷ�ϵ�¼                            *\n");
		printf("*                  0.������һ����                        *\n");
		printf("*                                                        *\n");
		printf("**********************************************************\n");
		printf("ѧ���ţ�%s�����룺%s\n", ID, password);

		op = getch();
		switch (op)
		{
		case '1':
			printf("���������ID��\n");
			scanf("%s", ID);
			break;
		case '2':
			printf("������������룺\n");
			scanf("%s", password);
			break;
		case '3':
			if (account = ComparingAccountPasswords(ID, password))
			{
				if (!account->login)
				{
					printf("��ǰ״̬���ɵ�¼������ϵ����Ա��");
				}
				else
				{
					printf("��¼�ɹ�,������ת���û�����......");
					Sleep(2000);
					system("cls");
					UserMenu(account);
					return;
				}
			}
			else
			{
				printf("������û����������������˶Ժ����ԣ�\n");
			}
			break;
		case '0':system("cls"); return;
		default:printf("%c\tָ���������������!\n", op);
		}
		system("cls");
	}
}

//�û��˵�
void UserMenu(User* account)
{
	char op;

	while (1)
	{
		printf("**********************************************************\n");
		printf("*                     �û��˵�                           *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*                 �������Ӧ���ֽ��в���                 *\n");
		printf("*                                                        *\n");
		printf("*                    1.��ʷ����                          *\n");
		printf("*                    2.ͼ�����                          *\n");
		printf("*                    3.ͼ���ѯ                          *\n");
		printf("*                    4.����ͼ��                          *\n");
		printf("*                    5.�������                          *\n");
		printf("*                    6.�޸��˺���Ϣ                      *\n");
		printf("*                    7.ע���˺�                          *\n");
		printf("*                    0.�˳���¼                          *\n");
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
		default:printf("%c\tָ���������������\n", op);
		}
		system("cls");
	}
}

//����Ա��¼
void AdminLogin()
{
	char ID[20] = { '\0' };
	char password[20] = { '\0' };
	User* account;
	char op;

	while (1) {
		printf("**********************************************************\n");
		printf("*                       ����Ա��¼                       *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*                �������Ӧ���ֽ��в���                  *\n");
		printf("*                                                        *\n");
		printf("*                   1.����ԱID                           *\n");
		printf("*                   2.����Ա����                         *\n");
		printf("*                   3.ȷ�ϵ�¼                           *\n");
		printf("*                   0.����������                         *\n");
		printf("*                                                        *\n");
		printf("**********************************************************\n");
		printf("ѧ���ţ�%s�����룺%s\n", ID, password);

		op = getch();
		switch (op) {
		case '1':
			printf("���������ID��\n");
			scanf("%s", ID);
			break;
		case '2':
			printf("������������룺\n");
			scanf("%s", password);
			break;
		case '3':
			if (account = ComparingAccountPasswords(ID, password))
			{
				if (!account->login)
				{
					printf("��ǰ״̬���ɵ�¼������ϵ��������Ա��");
				}
				else {
					printf("��¼�ɹ�,������ת������Ա����......");
					Sleep(2000);
					system("cls");
					AdminMenu(account);
					return;
				}
			}
			else
			{
				printf("������û����������������˶Ժ����ԣ�");
			}
			break;
		case '0':
			system("cls");
			return;
		default:
			printf("%c\tָ���������������!\n", op);
		}
		system("cls");
	}
}

//����Ա�˵�
void AdminMenu(User* account)
{
	char op;

	while (1) {
		printf("**********************************************************\n");
		printf("*                       ����Ա                           *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*               �������Ӧ���ֽ��в���                   *\n");
		printf("*                                                        *\n");
		printf("*                   1.ͼ�����                           *\n");
		printf("*                   2.�˻�����                           *\n");
		printf("*                   3.ͳ��                               *\n");
		printf("*                   4.���ò���                           *\n");
		printf("*                   0.�˳���¼                           *\n");
		printf("*                                                        *\n");
		printf("**********************************************************\n");

		op = getch();
		switch (op) {
		case '1': system("cls"); BooksManagement(); break;
		case '2': system("cls"); AccountManagement(account); break;
		case '3': system("cls"); Statistic(account); break;
		case '4': system("cls"); Parameter(); break;
		case '0': system("cls"); return;
		default:printf("%c\tָ���������������\n", op);
		}
		system("cls");
	}
}

//�������
void End()
{
	printf("*****************��лʹ��ͼ��������ϵͳ*****************\n");
	printf("*                                                        *\n");
	printf("*                                                        *\n");
	printf("*                                                        *\n");
	printf("*                     �˳�ϵͳ�ɹ���                     *\n");
	printf("*                                                        *\n");
	printf("*                                                        *\n");
	printf("**********************************************************\n");
}