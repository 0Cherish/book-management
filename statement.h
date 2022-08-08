#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <windows.h>

//���ͼ��
typedef struct StockBook
{
	char bookNumber[20];//ͼ����
	char title[30];//����
	char author[20];//���� 
	char publisher[30];//������
	int yearOfPublication;//������
	int monthOfPublication;//������
	double money;//���
	char category[10];//���
	int numberOfBooks;//ͼ������
	int currentNumberOfBooks;//��ǰͼ��
	int numberOfBooksBorrowed;//�ѽ�ͼ����
	struct StockBook* next;
}Book;

//���ĵ�ͼ��
typedef struct BorrowBooks
{
	Book booksOnLoan[10];//���ɽ�10����
	int numberOfLoans;//����ͼ�������
	time_t borrowDate[10];//��������
	time_t dueDate[10];//��������
	double fine[10];//������
	struct BorrowBooks* next;
}Borrow;

//�û���Ϣ
typedef struct User
{

	char ID[10];//ѧ����
	char name[30];//����
	char password[20];//����
	char gender[10];//�Ա�
	int admin;//�Ƿ�Ϊ����Ա
	int login;//�Ƿ�Ϊ�ɵ�¼״̬
	int theClass;//�༶
	char position[10];//ְ��
	Borrow borrow;
	struct User* next;
}User;


Book* book_head;//ͼ��ͷָ��
User* user_head;//�û�ͷָ��,ͷΪ��������Ա
int book_amount;  //ͼ��������
int user_amount;  //�û�������
int g_maxday;//����������
double g_fineRate; // ������


//�������
void End();
//��������
void ToLoad();
//�洢����
void Storage();
//��ӭ����
void Welcome();
//���˵�
void MainMenu();
//ʹ���ֲ�
void ServiceManual();
//�û�ע��
void UserRegistration();
//�����û��½ڵ�
void CreateAUser(char* name, char* ID, char* password, char* gender, char* position, int theClass);
//�����û�ID
User* FindTheUserId(char* ID);
//�ȶ��˻�����
User* ComparingAccountPasswords(char* ID, char* password);
//�û���¼
void UsersLogin();
//�û��˵�
void UserMenu(User* account);
//��ʷ����
void HistoryOfBorrowing(User* account);
//�����鼮
int OverdueBooks(User* account, int i);
//ע���˺�
void DeleteAUser(User* account);
//�޸��˺���Ϣ
void ChangeUserInformation(User* account);
//�������
void ReturnABook(User* account);
//����ͼ��
void BorrowBooks(User* account);
//��ѯͼ��
void SearchBooks();
//�����������
void SearchByPublisher();
//�����߲���
void SearchByAuthor();
//����������
void SearchByTitle();
//��ͼ���Ų���
void SearchByBookNumber();
//���ͼ��
void BrowseBooks();
//��������Ա��ʼ��
void SuperAdminInit();
//����Ա��¼
void AdminLogin();
//����Ա�˵�
void AdminMenu(User* account);
//ͳ��
void Statistic(User* account);
//ͼ�����������
void BookLoanVolumeRanking();
//���߽���������
void ReaderBorrowingRanking(User* account);
//��������鼮
int BrowsingOverdueBooks();
//����
void Parameter();
//�˻�����
void AccountManagement(User* account);
//���ù���Ա
void SettingAnAdmin(User* account, User* t);
//����û�
void BrowseTheUser(User* account);
//ͼ�����
void BooksManagement();
//ɾ��ͼ����Ϣ
void DeletingBookInformation();
//�޸�ͼ����Ϣ
void ChangingBookInformation();
//����ͼ����Ϣ
void AddingBookInformation();
//����ͼ���½ڵ�
void CreateABook(char* bookNumber, char* title, char* author, char* publisher, int year, int month,
	double money, char* category, int newnumber);