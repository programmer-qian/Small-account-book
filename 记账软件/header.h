#pragma once
#define Total 10000
struct Detail {
	char* revenueOrExpenditure;   //"����"��"֧��"�ַ���
	double money;   //�����֧����Ǯ
	double balance;   //���
	char note[50];   //˵��
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