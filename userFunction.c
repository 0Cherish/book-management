#include "statement.h"

//�û�ע��
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
		printf("*                       �û�ע��                         *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*            �������Ӧ���ֽ��в���                      *\n");
		printf("*                                                        *\n");
		printf("*            1.�û���                                    *\n");
		printf("*            2.ѧ���ţ�ID��                              *\n");
		printf("*            3.�û�����(8-16���ַ������ٺ���3���ַ�)     *\n");
		printf("*            4.�Ա�male/female��                       *\n");
		printf("*            5.ְ��ְ��/ѧ��ѡ��һ��                   *\n");
		printf("*            6.ѧ������༶��                            *\n");
		printf("*            7.ȷ��ע��                                  *\n");
		printf("*            0.������һ����                              *\n");
		printf("*                                                        *\n");
		printf("**********************************************************\n");
		printf("������%s��ѧ���ţ�%s�����룺%s���Ա�%s��ְ��%s���༶��%d\n",
			name, ID, password, gender, position, theClass);

		op = getch();
		switch (op)
		{
		case '1':
			printf("����������û�����\n");
			scanf("%s", name);
			break;
		case '2':
			while (1)
			{
				printf("���������ѧ���ţ�\n");
				scanf("%s", ID);
				if (FindTheUserId(ID)) {
					printf("��ID�Ѵ��ڣ��볢��������ID��\n");
				}
				else break;
			}
			break;
		case '3':
			while (1)
			{
				printf("����������û����룺\n");
				scanf("%s", password);
				printf("���ٴ���������û����룺\n");
				scanf("%s", password1);
				if (strcmp(password, password1))
				{
					printf("������������벻��ͬ����˶Ժ����������룡\n");
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
						printf("��������벻����Ҫ�����������룡\n");
					}
					else break;
				}

			}
			break;
		case '4':
			while (1)
			{
				printf("����������Ա�\n");
				scanf("%s", gender);
				if (strcmp(gender, "female") && strcmp(gender, "male"))
				{
					printf("������ַ�������Ҫ�����������룡\n");
				}
				else break;
			}break;
		case '5':
			printf("���������ְ��\n");
			scanf("%s", position);
			theClass = 0;
			break;
		case '6':
			printf("��������İ༶��\n");
			scanf("%d", &theClass);
			strcpy(position, "");
			break;
		case '7':
			if (name[0] && ID[0] && password[0] && gender[0] && (position[0] || theClass))
			{
				CreateAUser(name, ID, password, gender, position, theClass);
				printf("ע��ɹ�,�����ص���һ����......");
				Sleep(2000);
				system("cls");
				return;
			}
			else
			{
				printf("������������Ϣ�����ԣ�\n");
			}
			break;
		case '0':system("cls"); return;
		default:printf("%c\tָ���������������!\n", op);
		}
		system("cls");
	}
}

//����ͼ��
void BorrowBooks(User* account)
{
	while (1)
	{
		int n = account->borrow.numberOfLoans, max = 10;
		if (n == max)
		{
			printf("����ͼ������ %d �����Ѵ����� %d �������ȹ黹����ͼ�飡\n", n, max);
			return;
		}
		BrowseBooks();
		printf("����������Ҫ���ĵ��鼮���(���� 0 �˳�����)��\n");
		int count;
		scanf("%d", &count);
		if (count == 0)
		{
			printf("�ѳɹ��˳�����ͼ�飡\n");
			system("pause");
			return;
		}
		else if (count > book_amount || count < 0)
		{
			printf("����ȷ������ͼ�����е�ͼ����ţ�\n");
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
			printf("����ͼ�顶%s���ɹ�,����������һ���棡\n", t->title);
			Sleep(2000);
			system("cls");
			return;
		}
	}
}

//�������
void ReturnABook(User* account)
{
	HistoryOfBorrowing(account);
	if (!account->borrow.numberOfLoans)
	{
		printf("û���ѽ��ͼ��!");
		system("pause");
		return;
	}
	printf("����������Ҫ�黹���鼮��ţ�����0���˳�����ϵͳ��\n");
	int count = 0;
	scanf("%d", &count);
	if (count == 0)
	{
		printf("�ѳɹ��˳��������\n");
		system("pause");
		return;
	}
	if (count > account->borrow.numberOfLoans || count < 0)
	{
		printf("����ȷ���������鼮��ţ�\n");
		system("pause");
		return;
	}
	else
	{
		if (OverdueBooks(account, count - 1))
		{
			printf("������δ��ָ�������ڹ黹��%s��,����ϵ����Ա֧������%.2fԪ��\n",
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
			printf("�鼮��%s���黹�ɹ�,����������һ���棡\n", title);
			Sleep(2000);
			system("cls");
			return;
		}
	}
}

//�޸��˺���Ϣ
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
		printf("*                    �޸��˻���Ϣ                        *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*             �������Ӧ���ֽ��в���                     *\n");
		printf("*                                                        *\n");
		printf("*               1.�û���                                 *\n");
		printf("*               2.ѧ���ţ�ID��                           *\n");
		printf("*               3.�û�����(8-16���ַ������ٺ���3���ַ�)  *\n");
		printf("*               4.�Ա�male/female��                    *\n");
		printf("*               5.��ʦ                                   *\n");
		printf("*               6.ѧ������༶��                         *\n");
		printf("*               7.ȷ���޸�                               *\n");
		printf("*               0.������һ����                           *\n");
		printf("*                                                        *\n");
		printf("**********************************************************\n");
		printf("������%s��ѧ���ţ�%s�����룺%s���Ա�%s����ʦ��%s���༶��%d\n",
			name, ID, password, gender, position, theClass);

		op = getch();
		switch (op)
		{
		case '1':
			printf("����������û�����\n");
			scanf("%s", name);
			break;
		case '2':
			while (1)
			{
				printf("���������ѧ���ţ�\n");
				scanf("%s", ID);
				if (FindTheUserId(ID) != NULL) {
					printf("��ID�Ѵ��ڣ��볢��������ID��\n");
				}
				else break;
			}
			break;
		case '3':
			while (1)
			{
				printf("������ԭ���룺\n");
				scanf("%s", password);
				printf("�������޸ĺ�����룺\n");
				scanf("%s", password1);
				if (strcmp(account->password, password))
				{
					printf("ԭ�������������˶Ժ����������룡\n");
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
						printf("����������벻����Ҫ�����������룡\n");
					}
					else break;
				}

			}
			break;
		case '4':
			while (1)
			{
				printf("����������Ա�\n");
				scanf("%s", gender);
				if (strcmp(gender, "female") && strcmp(gender, "male"))
				{
					printf("������ַ�������Ҫ�����������룡\n");
				}
				else break;
			}break;
		case '5':
			printf("��������İ༶��\n");
			scanf("%s", position);
			theClass = 0;
			break;
		case '6':
			printf("��������İ༶��\n");
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
			printf("������Ϣ�޸ĳɹ������ڷ�����һ����...\n");
			Sleep(2000);
			system("cls");
			return;
		case '0':system("cls"); return;
		default:printf("%c\tָ���������������!\n", op);
		}
		system("cls");
	}
}

//ע���˺�
void DeleteAUser(User* account)
{
	printf("**********************************************************\n");
	printf("*                       ע���˺�                         *\n");
	printf("*--------------------------------------------------------*\n");
	if (account == user_head)
	{
		printf("�û�ӵ�����Ȩ�ޣ����ɱ�ɾ��������\n");
		system("pause");
		return;
	}
	printf("�Ƿ���Ҫɾ���˺ţ�\n");
	printf("��������Ӧ�����Լ���������\n");
	printf("1����\t0����\n");

	int op;
	scanf("%d", &op);
	if (op == 1)
	{
		if (account->borrow.numberOfLoans)
		{
			printf("ɾ��ʧ�ܣ����û���%d��ͼ��δ�黹�����ȹ黹������ͼ�飡\n",
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
					printf("�˺���ɾ���ɹ���\n");
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
		printf("��ȡ�����β�����\n");
	}
	else
	{
		printf("����ѡ��������������룡\n");
	}
	system("pause");
}