#include "statement.h"

//�����û�ID
User* FindTheUserId(char* ID)
{
	User* t = user_head;
	while (t)
	{
		if (!strcmp(t->ID, ID))
		{
			return t;
		}
		t = t->next;
	}
	return NULL;
}

//�ȶ��û�����
User* ComparingAccountPasswords(char* ID, char* password)
{
	User* t = user_head;
	while (t)
	{
		if (!strcmp(t->ID, ID) && !strcmp(t->password, password))
		{
			return t;
		}
		t = t->next;
	}
	return NULL;
}

//�����鼮
int OverdueBooks(User* account, int i)
{
	if (time(NULL) > account->borrow.dueDate[i])
	{
		return 1;
	}
	return 0;
}