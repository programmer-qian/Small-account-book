#pragma once
#define Total 10000
struct Detail {
	char* revenueOrExpenditure;   //"收入"或"支出"字符串
	double money;   //收入或支出的钱
	double balance;   //余额
	char note[50];   //说明
};
extern struct Detail detail[Total];
extern char key[3];
extern int flag;
extern double temp;
extern char again[3];
void mainMenu(void);
void showDetails(void);
void inCome(void);
void pay(void);
void myExit(void);