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
//��ʾ���˵�
void mainMenu(void)
{
	do {
		printf("\n-----------------�ѽ�����֧����ϵͳ-----------------\n");
		printf("\t\t     1.��֧��ϸ\n");
		printf("\t\t     2.�Ǽ�����\n");
		printf("\t\t     3.�Ǽ�֧��\n");
		printf("\t\t     4.�˳�ϵͳ\n");
		printf("\t\t     ��ѡ��");
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
			printf("\t      *���������������������*\n");
			printf("\t      **************************\n");
			Sleep(1000);
		}
		system("cls");
	} while (strcmp(again, "y"));
	printf("\n\n\n\n\t\t\t�����˳�������ϵͳ����л����ʹ�ã��ټ�������");
	printf("\n\n\n\t\t\t\t�밴��������رմ˴��ڣ�����");
	_getch();
}
//��֧��ϸ
void showDetails(void)
{
	char showDetailsKey[3] = { '\0' };
	char again[3] = { '\0' };
	do {
		system("cls");
		printf("\n---------------------------------��ǰ��֧��ϸ��¼---------------------------------\n");
		if (flag == 0)
		{
			printf("\n\n\t\t\t����տ���ҲŶ��ȥ��һ�ʰɣ�����\n\n\n");
		}
		else
		{
			printf("\n\t��֧���\t    ��֧���\t\t      �˻����\t˵��\n");
			for (int i = 0; i < flag; i++)
			{
				if (strcmp(detail[i].revenueOrExpenditure, "����") == 0)
				{
					printf("\t%s\t%+18.2fԪ\t%20.2fԪ\t%s\n", detail[i].revenueOrExpenditure, detail[i].money, detail[i].balance, detail[i].note);
				}
				else
				{
					printf("\t%s\t%18.2fԪ\t%20.2fԪ\t%s\n", detail[i].revenueOrExpenditure, -detail[i].money, detail[i].balance, detail[i].note);
				}
			}
		}
		printf("\n\t\t\t1.�˳���֧��ϸ��¼\n");
		printf("\t\t\t��ѡ��");
		scanf("%2s", showDetailsKey);
		scanf("%*[^\n]"); scanf("%*c");
		if (strcmp(showDetailsKey, "1") == 0)
		{
			do {
				system("cls");
				printf("\n\t\t��ȷ��Ҫ�˳���(y[��]/n[����])\n");
				printf("\t\t������y��n��");
				scanf("%2s", again);
				scanf("%*[^\n]"); scanf("%*c");
				if (strcmp(again, "y") && strcmp(again, "n"))
				{
					printf("\n\t\t**************************\n");
					printf("\t\t*���������������������*\n");
					printf("\t\t**************************\n");
					Sleep(1000);
				}
			} while (strcmp(again, "y") && strcmp(again, "n"));
		}
		else
		{
			printf("\n\t\t\t**************************\n");
			printf("\t\t\t*���������������������*\n");
			printf("\t\t\t**************************\n");
			Sleep(1000);
		}
	} while (strcmp(again, "y"));
}
//�Ǽ�����
void inCome(void)
{
	char inComeKey[3] = { '\0' };
	char again[3] = { '\0' };
	do {
		if (flag < Total)
		{
			system("cls");
			printf("\n--------------------�ѽ���Ǽ�����ϵͳ--------------------\n");
			printf("\t\t\t1.��ʼ�Ǽ�\n");
			printf("\t\t\t2.�˳��Ǽ�\n");
			printf("���ĵ�ǰ���Ϊ%.2fԪ\n", temp);
			printf("\t\t\t��ѡ��");
			scanf("%2s", inComeKey);
			scanf("%*[^\n]"); scanf("%*c");
			if (strcmp(inComeKey, "1") == 0)
			{
				printf("���������");
				scanf("%lf", &detail[flag].money);
				scanf("%*[^\n]"); scanf("%*c");
				if (detail[flag].money <= 0)
				{
					printf("\n\t\t\t**************************");
					printf("\n\t\t\t*����Ľ�����Ϊ����    *");
					printf("\n\t\t\t*�����������뱾��������*");
					printf("\n\t\t\t**************************");
					Sleep(2000);
					continue;
				}
				printf("��������˵����");
				scanf("%s", detail[flag].note);
				scanf("%*[^\n]"); scanf("%*c");
				detail[flag].revenueOrExpenditure = "����";
				detail[flag].balance = temp + detail[flag].money;
				temp = detail[flag].balance;
				flag++;
			}
			else if (strcmp(inComeKey, "2") == 0)
			{
				do {
					system("cls");
					printf("\n\t\t��ȷ��Ҫ�˳���(y[��]/n[����])\n");
					printf("\t\t������y��n��");
					scanf("%2s", again);
					scanf("%*[^\n]"); scanf("%*c");
					if (strcmp(again, "y") && strcmp(again, "n"))
					{
						printf("\n\t\t**************************\n");
						printf("\t\t*���������������������*\n");
						printf("\t\t**************************\n");
						Sleep(1000);
					}
				} while (strcmp(again, "y") && strcmp(again, "n"));
			}
			else
			{
				printf("\n\t\t**************************\n");
				printf("\t\t*���������������������*\n");
				printf("\t\t**************************\n");
				Sleep(1000);
			}
		}
		else
		{
			system("cls");
			printf("\n\n\n��Ǹ��������ϵͳֻ�ܴ��%d����֧��ϸ��������ֻ�ܲ鿴��֧��ϸ�����˳�ϵͳ�ˣ�����\n\t\t\t���������Ĳ���֮�������½⣡����", Total);
			printf("\n\t\t\t      �밴������������˵�");
			_getch();
			break;
		}
	} while (strcmp(again, "y"));
}
//�Ǽ�֧��
void pay(void)
{
	char payKey[3] = { '\0' };
	char again[3] = { '\0' };
	do {
		if (flag < Total)
		{
			system("cls");
			printf("\n--------------------�ѽ���Ǽ�֧��ϵͳ--------------------\n");
			printf("\t\t\t1.��ʼ�Ǽ�\n");
			printf("\t\t\t2.�˳��Ǽ�\n");
			printf("���ĵ�ǰ���Ϊ%.2fԪ\n", temp);
			printf("\t\t\t��ѡ��");
			scanf("%2s", payKey);
			scanf("%*[^\n]"); scanf("%*c");
			if (strcmp(payKey, "1") == 0)
			{
				printf("����֧����");
				scanf("%lf", &detail[flag].money);
				scanf("%*[^\n]"); scanf("%*c");
				if (detail[flag].money <= 0)
				{
					printf("\n\t\t\t**************************");
					printf("\n\t\t\t*����Ľ�����Ϊ����    *");
					printf("\n\t\t\t*�����������뱾��֧�����*");
					printf("\n\t\t\t**************************");
					Sleep(2000);
					continue;
				}
				else if (detail[flag].money > temp)
				{
					printf("\n\t\t\t**************************");
					printf("\n\t\t\t*��������            *");
					printf("\n\t\t\t*�����������뱾��֧�����*");
					printf("\n\t\t\t**************************");
					Sleep(2000);
					continue;
				}
				printf("����֧��˵����");
				scanf("%s", detail[flag].note);
				scanf("%*[^\n]"); scanf("%*c");
				detail[flag].revenueOrExpenditure = "֧��";
				detail[flag].balance = temp - detail[flag].money;
				temp = detail[flag].balance;
				flag++;
			}
			else if (strcmp(payKey, "2") == 0)
			{
				do {
					system("cls");
					printf("\n\t\t��ȷ��Ҫ�˳���(y[��]/n[����])\n");
					printf("\t\t������y��n��");
					scanf("%2s", again);
					scanf("%*[^\n]"); scanf("%*c");
					if (strcmp(again, "y") && strcmp(again, "n"))
					{
						printf("\n\t\t**************************\n");
						printf("\t\t*���������������������*\n");
						printf("\t\t**************************\n");
						Sleep(1000);
					}
				} while (strcmp(again, "y") && strcmp(again, "n"));
			}
			else
			{
				printf("\n\t\t**************************\n");
				printf("\t\t*���������������������*\n");
				printf("\t\t**************************\n");
				Sleep(1000);
			}
		}
		else
		{
			system("cls");
			printf("\n\n\n��Ǹ��������ϵͳֻ�ܴ��%d����֧��ϸ��������ֻ�ܲ鿴��֧��ϸ�����˳�ϵͳ�ˣ�����\n\t\t\t���������Ĳ���֮�������½⣡����", Total);
			printf("\n\t\t\t      �밴������������˵�");
			_getch();
			break;
		}
	} while (strcmp(again, "y"));
}
//�˳�ϵͳ
void myExit(void)
{
	do {
		system("cls");
		printf("\n\t\t��ȷ��Ҫ�˳���\n\t\t���������֧���ݽ����㣬���Ƿ�Ҫ������\n\t\t(y[��]/n[��])\n");
		printf("\t\t������y��n��");
		scanf("%2s", again);
		scanf("%*[^\n]"); scanf("%*c");
		if (strcmp(again, "y") && strcmp(again, "n"))
		{
			printf("\n\t\t**************************\n");
			printf("\t\t*���������������������*\n");
			printf("\t\t**************************\n");
			Sleep(1000);
		}
	} while (strcmp(again, "y") && strcmp(again, "n"));
}