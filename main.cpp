#include<stdio.h>
#include<windows.h>
#include"my.h"

/*
ȫ�ֱ���
*/ 
struct trainFile train[15];
struct PassengerINformation Passenger[30];
struct Account user[40];
int Login_status = OFFLINE;
char NowUser[20];


int main(int argc, char** argv) {
/*
��������
*/ 
SetConsoleTitle("������Ʊ����ϵͳ");

	readtrainFile();//��ȡ�г���Ϣ 
	readPassengerINformation(); //��ȡ�˿���Ϣ 
	readAccount();//��ȡ�û���Ϣ
 	choose();//��ӡ��ҳ��


}
