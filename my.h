#pragma once
#include<stdio.h>
#include <stdlib.h>
#define ONLINE -1
#define OFFLINE 0
struct trainFile//�г���Ϣ�ṹ�嶨�� 
{
	char trainid[20];		//�г���	 
	char firststand[20];	//ʼ��վ 
	char middlestand[20];	//��ͣվ			 
	char finalstand[20];	//�յ�վ 
	char time_day[20];		//�������� 
	char time_hour[20];		//����ʱ�� 
	int prize;				//�۸� 
	int totalzw;			//��λ�� 
	int freezw;				//ʣ��λ�� 
	int n;
};
struct PassengerINformation
{
	char name[20];			//����	 
	char gender[20];		//�Ա� 
	char id[20];			//���֤�� 
	char seat_number[20];	//��λ�� 
};
struct Account{
	char username[20];//�˺� 
	char password[20];//���� 
	int n;//������ 
};
void readtrainFile();//��ȡ�г���Ϣ�ļ� 
void readPassengerINformation();//��ȡ�˿���Ϣ�ļ�
void readAccount();//��ȡ�˺���Ϣ�ļ� 
void menu();//���˵� 
void choose(); //ѡ������˵� 
void userload();//��½���� 
void Exitlogin();//�˳���½ 
void Train_inquiry_admin();// 
void Train_inquiry_user();//�г���Ϣ��ѯ����
void TrainBooking();//��Ʊϵͳ 
void PersonalInformationInquiry();//�˿Ͷ�Ʊ��Ϣ��ѯ
int DeleteFile(int linenum,char *Filename);//ɾ���ļ��е�ĳһ�� 
void TrainUnBooking();//��Ʊϵͳ

