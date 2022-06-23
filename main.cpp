#include<stdio.h>
#include<windows.h>
#include"my.h"

/*
全局变量
*/ 
struct trainFile train[15];
struct PassengerINformation Passenger[30];
struct Account user[40];
int Login_status = OFFLINE;
char NowUser[20];


int main(int argc, char** argv) {
/*
加载运行
*/ 
SetConsoleTitle("高铁订票客运系统");

	readtrainFile();//读取列车信息 
	readPassengerINformation(); //读取乘客信息 
	readAccount();//读取用户信息
 	choose();//打印主页面


}
