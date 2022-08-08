#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <windows.h>

//库存图书
typedef struct StockBook
{
	char bookNumber[20];//图书编号
	char title[30];//书名
	char author[20];//作者 
	char publisher[30];//出版社
	int yearOfPublication;//出版年
	int monthOfPublication;//出版月
	double money;//金额
	char category[10];//类别
	int numberOfBooks;//图书数量
	int currentNumberOfBooks;//当前图书
	int numberOfBooksBorrowed;//已借图书量
	struct StockBook* next;
}Book;

//借阅的图书
typedef struct BorrowBooks
{
	Book booksOnLoan[10];//最多可借10本书
	int numberOfLoans;//借阅图书的数量
	time_t borrowDate[10];//借书日期
	time_t dueDate[10];//到期日期
	double fine[10];//罚款金额
	struct BorrowBooks* next;
}Borrow;

//用户信息
typedef struct User
{

	char ID[10];//学工号
	char name[30];//姓名
	char password[20];//密码
	char gender[10];//性别
	int admin;//是否为管理员
	int login;//是否为可登录状态
	int theClass;//班级
	char position[10];//职务
	Borrow borrow;
	struct User* next;
}User;


Book* book_head;//图书头指针
User* user_head;//用户头指针,头为超级管理员
int book_amount;  //图书总数量
int user_amount;  //用户总数量
int g_maxday;//最大借阅天数
double g_fineRate; // 罚款率


//程序结束
void End();
//加载数据
void ToLoad();
//存储数据
void Storage();
//欢迎界面
void Welcome();
//主菜单
void MainMenu();
//使用手册
void ServiceManual();
//用户注册
void UserRegistration();
//创建用户新节点
void CreateAUser(char* name, char* ID, char* password, char* gender, char* position, int theClass);
//查找用户ID
User* FindTheUserId(char* ID);
//比对账户密码
User* ComparingAccountPasswords(char* ID, char* password);
//用户登录
void UsersLogin();
//用户菜单
void UserMenu(User* account);
//历史借阅
void HistoryOfBorrowing(User* account);
//逾期书籍
int OverdueBooks(User* account, int i);
//注销账号
void DeleteAUser(User* account);
//修改账号信息
void ChangeUserInformation(User* account);
//还书管理
void ReturnABook(User* account);
//借阅图书
void BorrowBooks(User* account);
//查询图书
void SearchBooks();
//按出版社查找
void SearchByPublisher();
//按作者查找
void SearchByAuthor();
//按书名查找
void SearchByTitle();
//按图书编号查找
void SearchByBookNumber();
//浏览图书
void BrowseBooks();
//超级管理员初始化
void SuperAdminInit();
//管理员登录
void AdminLogin();
//管理员菜单
void AdminMenu(User* account);
//统计
void Statistic(User* account);
//图书借阅量排行
void BookLoanVolumeRanking();
//读者借阅量排行
void ReaderBorrowingRanking(User* account);
//浏览逾期书籍
int BrowsingOverdueBooks();
//参数
void Parameter();
//账户管理
void AccountManagement(User* account);
//设置管理员
void SettingAnAdmin(User* account, User* t);
//浏览用户
void BrowseTheUser(User* account);
//图书管理
void BooksManagement();
//删除图书信息
void DeletingBookInformation();
//修改图书信息
void ChangingBookInformation();
//增加图书信息
void AddingBookInformation();
//创建图书新节点
void CreateABook(char* bookNumber, char* title, char* author, char* publisher, int year, int month,
	double money, char* category, int newnumber);