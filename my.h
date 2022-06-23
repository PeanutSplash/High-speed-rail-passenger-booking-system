#pragma once
#include<stdio.h>
#include <stdlib.h>
#define ONLINE -1
#define OFFLINE 0
struct trainFile//列车信息结构体定义 
{
	char trainid[20];		//列车号	 
	char firststand[20];	//始发站 
	char middlestand[20];	//经停站			 
	char finalstand[20];	//终点站 
	char time_day[20];		//出发日期 
	char time_hour[20];		//出发时间 
	int prize;				//价格 
	int totalzw;			//总位置 
	int freezw;				//剩余位置 
	int n;
};
struct PassengerINformation
{
	char name[20];			//名字	 
	char gender[20];		//性别 
	char id[20];			//身份证号 
	char seat_number[20];	//座位号 
};
struct Account{
	char username[20];//账号 
	char password[20];//密码 
	int n;//总行数 
};
void readtrainFile();//读取列车信息文件 
void readPassengerINformation();//读取乘客信息文件
void readAccount();//读取账号信息文件 
void menu();//主菜单 
void choose(); //选择二级菜单 
void userload();//登陆界面 
void Exitlogin();//退出登陆 
void Train_inquiry_admin();// 
void Train_inquiry_user();//列车信息查询函数
void TrainBooking();//订票系统 
void PersonalInformationInquiry();//乘客订票信息查询
int DeleteFile(int linenum,char *Filename);//删除文件中的某一行 
void TrainUnBooking();//退票系统

