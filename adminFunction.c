#include "statement.h"

//ͼ�����
void BooksManagement()
{
	char op;

	while (1)
	{
		printf("**********************************************************\n");
		printf("*                       ͼ�����                         *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*                 �������Ӧ���ֽ��в���                 *\n");
		printf("*                                                        *\n");
		printf("*                    1.����ͼ����Ϣ                      *\n");
		printf("*                    2.�޸�ͼ����Ϣ                      *\n");
		printf("*                    3.ɾ��ͼ����Ϣ                      *\n");
		printf("*                    4.ͼ�����                          *\n");
		printf("*                    5.ͼ�����                          *\n");
		printf("*                    0.������һ����                      *\n");
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
		default:printf("%c\tָ���������������!\n", op);
		}
		system("cls");
	}
}

//����ͼ����Ϣ
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
		printf("*                    ����ͼ����Ϣ                        *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*               �������Ӧ���ֽ��в���                   *\n");
		printf("*                                                        *\n");
		printf("*                    1.ͼ����                          *\n");
		printf("*                    2.����                              *\n");
		printf("*                    3.����                              *\n");
		printf("*                    4.������                            *\n");
		printf("*                    5.�������ڣ��� �£�                 *\n");
		printf("*                    6.���                              *\n");
		printf("*                    7.���                              *\n");
		printf("*                    8.��������                          *\n");
		printf("*                    9.ȷ�ϲ���                          *\n");
		printf("*                    0.������һ����                      *\n");
		printf("*                                                        *\n");
		printf("**********************************************************\n");
		printf("ͼ���ţ�%s��������%s�����ߣ�%s�������磺%s��\n",
			bookNumber, title, author, publisher);
		printf("�������ڣ�%d-%d����%.2f�����%s������������%d\n",
			year, month, money, category, newnumber);

		op = getch();

		switch (op)
		{
		case '1':
			printf("������ͼ��ı�ţ�\n");
			scanf("%s", bookNumber);
			break;
		case '2':
			printf("������������\n");
			scanf("%s", title);
			break;
		case '3':
			printf("������ͼ������ߣ�\n");
			scanf("%s", author);
			break;
		case '4':
			printf("������ͼ��ĳ����磺\n");
			scanf("%s", publisher);
			break;
		case '5':
			printf("������ͼ��ĳ������ڣ��� �£���\n");
			scanf("%d %d", &year, &month);
			break;
		case '6':
			printf("������ͼ��Ľ�\n");
			scanf("%lf", &money);
			break;
		case '7':
			printf("������ͼ������\n");
			scanf("%s", category);
			break;
		case '8':
			printf("����������ͼ���������\n");
			scanf("%d", &newnumber);
			break;
		case '9':
			if (bookNumber[0] && title[0] && author[0] && publisher[0] && year && month && money &&
				category[0] && newnumber)
			{
				CreateABook(bookNumber, title, author, publisher, year, month, money, category,
					newnumber);
				printf("�����ɹ�,������ת����һ����......");
				Sleep(2000);
				system("cls");
				return;
			}
			else
			{
				printf("������������Ϣ�����ԣ�\n");
				Sleep(1000);
				break;
			}
		case '0':system("cls"); return;
		default:printf("%c\tָ���������������\n", op);
		}
		system("cls");
	}
}

//�޸�ͼ����Ϣ
void ChangingBookInformation()
{
	BrowseBooks();
	printf("��������޸ĵ��鼮���(���� 0 �˳��޸Ĳ���)��\n");
	int count;
	scanf("%d", &count);
	if (count == 0)
	{
		system("cls");
		return;
	}
	else if (count > book_amount || count < 0)
	{
		printf("����ȷ������ͼ�д��޸ĵ�ͼ����ţ�\n");
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
					printf("*                     �޸�ͼ����Ϣ                       *\n");
					printf("*--------------------------------------------------------*\n");
					printf("*                                                        *\n");
					printf("*                �������Ӧ���ֽ��в���                  *\n");
					printf("*                                                        *\n");
					printf("*                  1.�޸�ͼ����                        *\n");
					printf("*                  2.�޸�����                            *\n");
					printf("*                  3.�޸�����                            *\n");
					printf("*                  4.�޸ĳ�����                          *\n");
					printf("*                  5.�޸ĳ������ڣ��� �£�               *\n");
					printf("*                  6.�޸Ľ��                            *\n");
					printf("*                  7.�޸����                            *\n");
					printf("*                  8.�޸�ͼ������                        *\n");
					printf("*                  9.ȷ�ϲ���                            *\n");
					printf("*                  0.������һ����                        *\n");
					printf("*                                                        *\n");
					printf("**********************************************************\n");
					printf("ͼ���ţ�%s��������%s�����ߣ�%s�������磺%s��\n",
						bookNumber, title, author, publisher);
					printf("�������ڣ�%d-%d����%.2f�����%s��ͼ��������%d\n",
						year, month, money, category, numberOfBooks);

					op = getch();
					switch (op)
					{
					case '1':
						printf("�������޸ĺ��ͼ���ţ�\n");
						scanf("%s", bookNumber);
						break;
					case '2':
						printf("�������޸ĺ��������\n");
						scanf("%s", title);
						break;
					case '3':
						printf("�������޸ĺ��ͼ�����ߣ�\n");
						scanf("%s", author);
						break;
					case '4':
						printf("�������޸ĺ��ͼ������磺\n");
						scanf("%s", publisher);
						break;
					case '5':
						printf("�������޸ĺ��ͼ��������ڣ��� �£���\n");
						scanf("%d %d", &year, &month);
						break;
					case '6':
						printf("�������޸ĺ��ͼ���\n");
						scanf("%lf", &money);
						break;
					case '7':
						printf("�������޸ĺ��ͼ�����\n");
						scanf("%s", category);
						break;
					case '8':
						printf("�������޸ĺ��ͼ��������\n");
						scanf("%d", &numberOfBooks);
						if (numberOfBooks < t->numberOfBooksBorrowed)
						{
							printf("ͼ������С���ѽ��ͼ������");
							numberOfBooks = 0;
						}
						break;
					case '9':
						if (!bookNumber[0] && !title[0] && !author[0] && !publisher[0] &&
							!year && !month && !money && !category[0] && !numberOfBooks)
						{
							printf("�������޸ĺ����Ϣ���ԣ�\n");

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
							printf("�����ɹ�,������ת����һ����......");
							Sleep(2000);
							system("cls");
							return;
						}
					case '0':system("cls"); return;
					default:printf("%c\tָ���������������\n", op);
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

//ɾ��ͼ����Ϣ
void DeletingBookInformation()
{
	int count, delete_num;
	char title[30];

	BrowseBooks();
	printf("�������ɾ�����鼮���(���� 0 �˳�ɾ������)��\n");
	scanf("%d", &count);
	if (count == 0)
	{
		printf("�ѳɹ�ȡ���ò�����\n");
		system("pause");
		system("cls");
		return;
	}
	else if (count > book_amount || count < 0)
	{
		printf("����ȷ������ͼ�д�ɾ����ͼ����ţ�\n");
	}
	else
	{
		printf("��������Ҫɾ����ͼ�鱾����");
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
			printf("��������ͼ�飡");
		}
		else if (delete_num == t->currentNumberOfBooks && !t->numberOfBooksBorrowed)
		{
			last->next = t->next;
			free(t);
			book_amount--;
			Storage();
			printf("��ɾ��ȫ����%s����\n", title);
		}
		else
		{
			t->numberOfBooks -= delete_num;
			t->currentNumberOfBooks -= delete_num;
			printf("��ɾ��%d����%s��!\n", delete_num, title);
		}
	}
	system("pause");
	system("cls");
}

//�˻�����
void AccountManagement(User* account)
{
	char op;
	int num;

	while (1)
	{
		printf("**********************************************************\n");
		printf("*                       �˻�����                         *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*                �������Ӧ���ֽ��в���                  *\n");
		printf("*                                                        *\n");
		printf("*                  1.�鿴�û���Ϣ                        *\n");
		printf("*                  2.�޸��û���Ϣ                        *\n");
		printf("*                  3.֧������                            *\n");
		printf("*                  4.�˻���ʧ                            *\n");
		printf("*                  5.ע���˻�                            *\n");
		printf("*                  6.�û��������                        *\n");
		printf("*                  7.���ù���Ա                          *\n");
		printf("*                  0.�˳���һ����                        *\n");
		printf("*                                                        *\n");
		printf("**********************************************************\n");

		op = getch();
		switch (op)
		{
		case '1':system("cls"); BrowseTheUser(account); system("pause"); break;
		case '2':
			system("cls");
			BrowseTheUser(account);
			printf("��������������û���ţ�\n");
			scanf("%d", &num);
			if (num > user_amount || num <= 0)
			{
				printf("����ȷ������ͼ�д��������û���ţ�\n");
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
					printf("��û�и�Ȩ�ޣ�\n");
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
				printf("���������鼮��\n");
				system("pause");
				break;
			}
			printf("���������������ţ�\n");
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
				printf("����ȷ������ͼ�д��������û���ţ�\n");
			}
			else
			{
				printf("���������㣡\n");
				Storage();
			}
			system("pause");
			break;
		case '4':system("cls"); BrowseTheUser(account);
			printf("��������������û���ţ�\n");
			scanf("%d", &num);
			if (num == 1)
			{
				printf("���˻�ӵ�����Ȩ�ޣ����ɸ��ģ�");
			}
			else if (num > user_amount || num <= 0)
			{
				printf("����ȷ������ͼ�д��������û���ţ�\n");
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
					printf("����ǰû�д�Ȩ�ޣ�\n");
				}
				else
				{
					t->login = 0;
					printf("�˻��ѹ�ʧ��\n");
				}
			}
			system("pause");
			break;
		case '5':
			system("cls");
			BrowseTheUser(account);
			printf("��������������û���ţ�\n");
			scanf("%d", &num);
			if (num > user_amount || num <= 0)
			{
				printf("����ȷ������ͼ�д��������û���ţ�\n");
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
					printf("��û�и�Ȩ�ޣ�\n");
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
			printf("��������������û���ţ�\n");
			scanf("%d", &num);
			if (num > user_amount || num <= 0)
			{
				printf("����ȷ������ͼ�д��������û���ţ�\n");
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
			printf("����ȷ������ͼ�д��������û���ţ�\n");
			scanf("%d", &num);
			if (num > user_amount || num <= 0)
			{
				printf("��������ȷ����ţ�\n");
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
		default:printf("%c\tָ���������������\n", op);
		}
		system("cls");
	}
}

//���ù���Ա
void SettingAnAdmin(User* account, User* t)
{
	if (t == user_head)
	{
		printf("ӵ����߹���Ȩ�ޣ����ɱ��޸ģ�����\n");
		return;
	}
	if (t->admin && account != user_head)
	{
		printf("��û�и�Ȩ�ޣ�");
		return;
	}
	printf("��������Ӧ�����Լ���������\n");
	printf("1������Ϊ����Ա\t0��ȡ������ԱȨ��\n");
	int op;

	scanf("%d", &op);
	if (op == 1)
	{
		t->admin = 1;
		printf("����ԱȨ�����óɹ���\n");
	}
	else if (op == 0)
	{
		t->admin = 0;
		printf("����ԱȨ���ѱ�ȡ����\n");
	}
	else
	{
		printf("���ù���ԱȨ��ʧ�ܣ��밴Ҫ�����룡\n");
	}
	Storage();
}

//ͳ��
void Statistic(User* account)
{
	char op;

	while (1)
	{
		printf("**********************************************************\n");
		printf("*                         ͳ��                           *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*               �������Ӧ���ֽ��в���                   *\n");
		printf("*                                                        *\n");
		printf("*                  1.�鼮����������                      *\n");
		printf("*                  2.���߽���������                      *\n");
		printf("*                  3.��������鼮                        *\n");
		printf("*                  0.������һ����                        *\n");
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
				printf("���������鼮��\n");
			}
			system("pause"); break;
		case '0':system("cls"); return;
		default:printf("%c\tָ���������������\n", op);
		}
		system("cls");
	}
}

//����
void Parameter()
{
	char op;

	while (1)
	{
		printf("**********************************************************\n");
		printf("*                         ����                           *\n");
		printf("*--------------------------------------------------------*\n");
		printf("*                                                        *\n");
		printf("*               �������Ӧ���ֽ��в���                   *\n");
		printf("*                                                        *\n");
		printf("*                 1.���������鼮������                   *\n");
		printf("*                 2.��������������                     *\n");
		printf("*                 0.������һ����                         *\n");
		printf("*                                                        *\n");
		printf("**********************************************************\n");
		printf("�����ʣ�%.2f��������������%d\n", g_fineRate, g_maxday);

		op = getch();
		switch (op)
		{
		case '1':
			printf("�����뷣���ʣ�\n");
			scanf("%lf", &g_fineRate); break;
		case '2':
			printf("������������������\n");
			scanf("%d", &g_maxday); break;
		case '0':system("cls"); return;
		default:printf("%c\tָ���������������\n", op);
		}
		Storage();
		system("cls");
	}
}