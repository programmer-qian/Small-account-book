#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include "header.h"
struct Detail detail[Total];
char key[3];
int flag = 0;
double temp = 0.0;
char again[3];
//显示主菜单
void mainMenu(void)
{
	do {
		printf("\n-----------------已进入收支记账系统-----------------\n");
		printf("\t\t     1.收支明细\n");
		printf("\t\t     2.登记收入\n");
		printf("\t\t     3.登记支出\n");
		printf("\t\t     4.退出系统\n");
		printf("\t\t     请选择：");
		scanf("%2s", &key);
		scanf("%*[^\n]"); scanf("%*c");
		if (strcmp(key, "1") == 0)
		{
			showDetails();
		}
		else if (strcmp(key, "2") == 0)
		{
			inCome();
		}
		else if (strcmp(key, "3") == 0)
		{
			pay();
		}
		else if (strcmp(key, "4") == 0)
		{
			myExit();
		}
		else
		{
			printf("\n\t      **************************\n");
			printf("\t      *你的输入有误，请重新输入*\n");
			printf("\t      **************************\n");
			Sleep(1000);
		}
		system("cls");
	} while (strcmp(again, "y"));
	printf("\n\n\n\n\t\t\t你已退出本记账系统，感谢您的使用，再见！！！");
	printf("\n\n\n\t\t\t\t请按下任意键关闭此窗口！！！");
	_getch();
}
//收支明细
void showDetails(void)
{
	char showDetailsKey[3] = { '\0' };
	char again[3] = { '\0' };
	do {
		system("cls");
		printf("\n---------------------------------当前收支明细记录---------------------------------\n");
		if (flag == 0)
		{
			printf("\n\n\t\t\t这里空空如也哦，去来一笔吧！！！\n\n\n");
		}
		else
		{
			printf("\n\t收支情况\t    收支金额\t\t      账户余额\t说明\n");
			for (int i = 0; i < flag; i++)
			{
				if (strcmp(detail[i].revenueOrExpenditure, "收入") == 0)
				{
					printf("\t%s\t%+18.2f元\t%20.2f元\t%s\n", detail[i].revenueOrExpenditure, detail[i].money, detail[i].balance, detail[i].note);
				}
				else
				{
					printf("\t%s\t%18.2f元\t%20.2f元\t%s\n", detail[i].revenueOrExpenditure, -detail[i].money, detail[i].balance, detail[i].note);
				}
			}
		}
		printf("\n\t\t\t1.退出收支明细记录\n");
		printf("\t\t\t请选择：");
		scanf("%2s", showDetailsKey);
		scanf("%*[^\n]"); scanf("%*c");
		if (strcmp(showDetailsKey, "1") == 0)
		{
			do {
				system("cls");
				printf("\n\t\t你确定要退出吗？(y[是]/n[不是])\n");
				printf("\t\t请输入y或n：");
				scanf("%2s", again);
				scanf("%*[^\n]"); scanf("%*c");
				if (strcmp(again, "y") && strcmp(again, "n"))
				{
					printf("\n\t\t**************************\n");
					printf("\t\t*你的输入有误，请重新输入*\n");
					printf("\t\t**************************\n");
					Sleep(1000);
				}
			} while (strcmp(again, "y") && strcmp(again, "n"));
		}
		else
		{
			printf("\n\t\t\t**************************\n");
			printf("\t\t\t*你的输入有误，请重新输入*\n");
			printf("\t\t\t**************************\n");
			Sleep(1000);
		}
	} while (strcmp(again, "y"));
}
//登记收入
void inCome(void)
{
	char inComeKey[3] = { '\0' };
	char again[3] = { '\0' };
	do {
		if (flag < Total)
		{
			system("cls");
			printf("\n--------------------已进入登记收入系统--------------------\n");
			printf("\t\t\t1.开始登记\n");
			printf("\t\t\t2.退出登记\n");
			printf("您的当前余额为%.2f元\n", temp);
			printf("\t\t\t请选择：");
			scanf("%2s", inComeKey);
			scanf("%*[^\n]"); scanf("%*c");
			if (strcmp(inComeKey, "1") == 0)
			{
				printf("本次收入金额：");
				scanf("%lf", &detail[flag].money);
				scanf("%*[^\n]"); scanf("%*c");
				if (detail[flag].money <= 0)
				{
					printf("\n\t\t\t**************************");
					printf("\n\t\t\t*输入的金额必须为正数    *");
					printf("\n\t\t\t*请您重新输入本次收入金额*");
					printf("\n\t\t\t**************************");
					Sleep(2000);
					continue;
				}
				printf("本次收入说明：");
				scanf("%s", detail[flag].note);
				scanf("%*[^\n]"); scanf("%*c");
				detail[flag].revenueOrExpenditure = "收入";
				detail[flag].balance = temp + detail[flag].money;
				temp = detail[flag].balance;
				flag++;
			}
			else if (strcmp(inComeKey, "2") == 0)
			{
				do {
					system("cls");
					printf("\n\t\t你确定要退出吗？(y[是]/n[不是])\n");
					printf("\t\t请输入y或n：");
					scanf("%2s", again);
					scanf("%*[^\n]"); scanf("%*c");
					if (strcmp(again, "y") && strcmp(again, "n"))
					{
						printf("\n\t\t**************************\n");
						printf("\t\t*你的输入有误，请重新输入*\n");
						printf("\t\t**************************\n");
						Sleep(1000);
					}
				} while (strcmp(again, "y") && strcmp(again, "n"));
			}
			else
			{
				printf("\n\t\t**************************\n");
				printf("\t\t*你的输入有误，请重新输入*\n");
				printf("\t\t**************************\n");
				Sleep(1000);
			}
		}
		else
		{
			system("cls");
			printf("\n\n\n抱歉，本记账系统只能存放%d条收支明细，您现在只能查看收支明细或者退出系统了！！！\n\t\t\t给您带来的不便之处，请谅解！！！", Total);
			printf("\n\t\t\t      请按任意键返回主菜单");
			_getch();
			break;
		}
	} while (strcmp(again, "y"));
}
//登记支出
void pay(void)
{
	char payKey[3] = { '\0' };
	char again[3] = { '\0' };
	do {
		if (flag < Total)
		{
			system("cls");
			printf("\n--------------------已进入登记支出系统--------------------\n");
			printf("\t\t\t1.开始登记\n");
			printf("\t\t\t2.退出登记\n");
			printf("您的当前余额为%.2f元\n", temp);
			printf("\t\t\t请选择：");
			scanf("%2s", payKey);
			scanf("%*[^\n]"); scanf("%*c");
			if (strcmp(payKey, "1") == 0)
			{
				printf("本次支出金额：");
				scanf("%lf", &detail[flag].money);
				scanf("%*[^\n]"); scanf("%*c");
				if (detail[flag].money <= 0)
				{
					printf("\n\t\t\t**************************");
					printf("\n\t\t\t*输入的金额必须为正数    *");
					printf("\n\t\t\t*请您重新输入本次支出金额*");
					printf("\n\t\t\t**************************");
					Sleep(2000);
					continue;
				}
				else if (detail[flag].money > temp)
				{
					printf("\n\t\t\t**************************");
					printf("\n\t\t\t*您的余额不足            *");
					printf("\n\t\t\t*请您重新输入本次支出金额*");
					printf("\n\t\t\t**************************");
					Sleep(2000);
					continue;
				}
				printf("本次支出说明：");
				scanf("%s", detail[flag].note);
				scanf("%*[^\n]"); scanf("%*c");
				detail[flag].revenueOrExpenditure = "支出";
				detail[flag].balance = temp - detail[flag].money;
				temp = detail[flag].balance;
				flag++;
			}
			else if (strcmp(payKey, "2") == 0)
			{
				do {
					system("cls");
					printf("\n\t\t你确定要退出吗？(y[是]/n[不是])\n");
					printf("\t\t请输入y或n：");
					scanf("%2s", again);
					scanf("%*[^\n]"); scanf("%*c");
					if (strcmp(again, "y") && strcmp(again, "n"))
					{
						printf("\n\t\t**************************\n");
						printf("\t\t*你的输入有误，请重新输入*\n");
						printf("\t\t**************************\n");
						Sleep(1000);
					}
				} while (strcmp(again, "y") && strcmp(again, "n"));
			}
			else
			{
				printf("\n\t\t**************************\n");
				printf("\t\t*你的输入有误，请重新输入*\n");
				printf("\t\t**************************\n");
				Sleep(1000);
			}
		}
		else
		{
			system("cls");
			printf("\n\n\n抱歉，本记账系统只能存放%d条收支明细，您现在只能查看收支明细或者退出系统了！！！\n\t\t\t给您带来的不便之处，请谅解！！！", Total);
			printf("\n\t\t\t      请按任意键返回主菜单");
			_getch();
			break;
		}
	} while (strcmp(again, "y"));
}
//退出系统
void myExit(void)
{
	do {
		system("cls");
		printf("\n\t\t你确定要退出吗？\n\t\t你输入的收支数据将清零，你是否还要继续？\n\t\t(y[是]/n[否])\n");
		printf("\t\t请输入y或n：");
		scanf("%2s", again);
		scanf("%*[^\n]"); scanf("%*c");
		if (strcmp(again, "y") && strcmp(again, "n"))
		{
			printf("\n\t\t**************************\n");
			printf("\t\t*你的输入有误，请重新输入*\n");
			printf("\t\t**************************\n");
			Sleep(1000);
		}
	} while (strcmp(again, "y") && strcmp(again, "n"));
}