#include "statement.h"

//加载数据
void ToLoad()
{
	//图书
	book_head = (Book*)malloc(sizeof(Book));
	book_head->next = NULL;
	book_amount = 0;

	FILE* fp1 = fopen("库存图书.bin", "rb");
	if (fp1 == NULL) {
		fp1 = fopen("库存图书.bin", "wb");
		fclose(fp1);
	}
	else {
		Book* book_pnew, * book_ptail;
		book_ptail = book_head;
		fread(book_head, sizeof(Book), 1, fp1);
		book_pnew = (Book*)malloc(sizeof(Book));
		while (fread(book_pnew, sizeof(Book), 1, fp1)) {
			book_ptail->next = book_pnew;
			book_amount++;
			book_ptail = book_pnew;
			book_pnew = (Book*)malloc(sizeof(Book));
		}
		fclose(fp1);
	}

	//用户
	user_head = (User*)malloc(sizeof(User));
	user_head->next = NULL;
	user_amount = 1;

	FILE* fp2 = fopen("用户信息.bin", "rb");
	if (fp2 == NULL) {
		SuperAdminInit();
	}
	else {
		User* user_pnew, * user_ptail;
		user_ptail = user_head;
		fread(user_head, sizeof(User), 1, fp2);
		user_pnew = (User*)malloc(sizeof(User));
		while (fread(user_pnew, sizeof(User), 1, fp2)) {
			user_ptail->next = user_pnew;
			user_amount++;
			user_ptail = user_pnew;
			user_pnew = (User*)malloc(sizeof(User));
		}
		fclose(fp2);
	}

	//参数
	FILE* fp3 = fopen("参数.txt", "r");
	if (fp3 == NULL) {
		FILE* fp3 = fopen("参数.txt", "w");
		g_maxday = 15;
		g_fineRate = 1;
		Storage();
		fclose(fp3);
	}
	else
	{
		fscanf(fp3, "%d %lf", &g_maxday, &g_fineRate);
		fclose(fp3);
	}
}

//存储数据
void Storage()
{
	//图书
	FILE* fp1 = fopen("库存图书.bin", "wb");
	Book* t1 = book_head;
	while (t1) {
		fwrite(t1, sizeof(Book), 1, fp1);
		t1 = t1->next;
	}
	fclose(fp1);

	//用户
	FILE* fp2 = fopen("用户信息.bin", "wb");
	User* t2 = user_head;
	while (t2) {
		fwrite(t2, sizeof(User), 1, fp2);
		t2 = t2->next;
	}
	fclose(fp2);

	//参数
	FILE* fp3 = fopen("参数.txt", "w");
	fprintf(fp3, "%d %f", g_maxday, g_fineRate);
	fclose(fp3);
}

//超级管理员初始化
void SuperAdminInit()
{
	FILE* fp = fopen("用户信息.bin", "wb");
	user_head = (User*)malloc(sizeof(User));
	strcpy(user_head->name, "super");
	strcpy(user_head->password, "Sa666666");
	strcpy(user_head->position, "super admin");
	strcpy(user_head->ID, "666666");
	strcpy(user_head->gender, "male");
	user_head->admin = 1;
	user_head->login = 1;
	user_head->borrow.numberOfLoans = 0;
	user_head->next = NULL;
	user_amount = 1;
	Storage();
	fclose(fp);
}

//创建用户新节点
void CreateAUser(char* name, char* ID, char* password, char* gender, char* position, int theClass)
{
	User* t = user_head;
	while (t->next)
	{
		t = t->next;
	}
	User* pnew = (User*)malloc(sizeof(User));
	strcpy(pnew->name, name);
	strcpy(pnew->ID, ID);
	strcpy(pnew->password, password);
	strcpy(pnew->gender, gender);
	strcpy(pnew->position, position);
	pnew->theClass = theClass;
	pnew->borrow.numberOfLoans = 0;
	pnew->admin = 0;
	pnew->login = 1;
	t->next = pnew;
	pnew->next = NULL;
	user_amount++;
	Storage();
}

//创建图书新节点
void CreateABook(char* bookNumber, char* title, char* author, char* publisher, int year, int month,
	double money, char* category, int newnumber)
{
	Book* t = book_head;
	while (t->next) {
		if (strcmp(t->bookNumber, bookNumber) && !strcmp(t->title, title) && !strcmp(t->author, author) && !strcmp(t->publisher, publisher) && t->yearOfPublication == year && t->monthOfPublication == month && !strcmp(t->category, category))
		{
			t->numberOfBooks += newnumber;
			t->currentNumberOfBooks += newnumber;
			return;
		}
		t = t->next;
	}
	Book* pnew = (Book*)malloc(sizeof(Book));
	strcpy(pnew->bookNumber, bookNumber);
	strcpy(pnew->title, title);
	strcpy(pnew->author, author);
	strcpy(pnew->publisher, publisher);
	pnew->yearOfPublication = year;
	pnew->monthOfPublication = month;
	pnew->money = money;
	strcpy(pnew->category, category);
	pnew->numberOfBooks = newnumber;
	pnew->currentNumberOfBooks = newnumber;
	pnew->numberOfBooksBorrowed = 0;
	t->next = pnew;
	pnew->next = NULL;
	book_amount++;
	Storage();
}