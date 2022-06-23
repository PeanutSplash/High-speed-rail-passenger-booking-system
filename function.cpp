#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include<Conio.h>
#include<windows.h>
#include "my.h"
extern struct trainFile train[15];
extern struct PassengerINformation Passenger[30];
extern struct Account user[40]; 
extern int Login_status;//��½״̬ 
extern char NowUser[20];//��ǰ��½���û��� 

 void readtrainFile(){//��ȡ�г���Ϣ�ļ� 
	FILE *fp = fopen("trainFile.txt","r");// ���ļ�������fpָ���ļ� 
    if (fp == NULL) {
        fprintf(stderr, "�ļ���ʧ��.\n");
        exit(EXIT_FAILURE);
    }
    char row[80];
    char *token;
    int i=0;
    if(fgets(row, 80, fp) != NULL){
   	 	while (fgets(row, 80, fp) != NULL) {
      		sscanf(row,"%s%s%s%s%s%s%d%d%d",train[i].trainid,train[i].firststand,train[i].middlestand,train[i].finalstand,train[i].time_day,train[i].time_hour,&train[i].prize,&train[i].totalzw,&train[i].freezw);//�����ݴ���ṹ������ 
      		//printf("%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n",train[i].trainid,train[i].firststand,train[i].middlestand,train[i].finalstand,train[i].time_day,train[i].time_hour,train[i].prize,train[i].totalzw,train[i].freezw);
			i++;
			train[0].n++;
		}
    }
    fclose(fp);
}
void readPassengerINformation(){//��ȡ�˿���Ϣ�ļ� 
	FILE *fp = fopen("PassengerINformation.txt", "r");// ���ļ�������fpָ���ļ� 
    if (fp == NULL) {
        fprintf(stderr, "�ļ���ʧ��.\n");
        exit(EXIT_FAILURE);
    }
    char row[80];
    char *token;
    int i=0;
    if(fgets(row, 80, fp) != NULL){
   	 	while (fgets(row, 80, fp) != NULL) {
      		sscanf(row,"%s%s%s%s",Passenger[i].name,Passenger[i].gender,Passenger[i].id,Passenger[i].seat_number);//�����ݴ���ṹ������ 
    		//printf("%s\t%s\t%s\t%s\n",Passenger[i].name,Passenger[i].gender,Passenger[i].id,Passenger[i].seat_number);
			// 	 	 	system("pause");
			i++;
		}
    }
    fclose(fp);
}
void readAccount(){//��ȡ�û���Ϣ�ļ� 
	FILE *fp = fopen("�˺�.txt", "r");// ���ļ�������fpָ���ļ� 
    if (fp == NULL) {
        fprintf(stderr, "�ļ���ʧ��.\n");
        exit(EXIT_FAILURE);
    }
    char row[80];
    char *token;
    int i=0;
    if(fgets(row, 80, fp) != NULL){
   	 	while (fgets(row, 80, fp) != NULL) {
      		sscanf(row,"%s%s",user[i].username,user[i].password);//�����ݴ���ṹ������ 
    	//	printf("%s\t%s\n",user[i].username,user[i].password);
    		 	 //	 	system("pause");
			i++;
			user[0].n=i;
		}
		Login_status=0;//��֪��Ϊɶ����while���½״̬��ֵ���޸��ˣ��ڴ�����ֵ 
    }
    
    fclose(fp);
}
void menu() {
	system("color 9F");
	time_t timep;    //ϵͳʱ�� 
	struct tm* p;
	time(&timep);
	p = gmtime(&timep);
	system("cls");
	printf("\t\t\t\t\t\t   %d��%02d��%02d��\n", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
	printf("\t\t\t\t\t\t  ��ǰʱ��%02dʱ%02d��%\n", 8 + p->tm_hour, p->tm_min);
	if(Login_status==0)printf("\t\t\t\t\t************************************\t\t\t��ǰ��½״̬������\n");
	else	printf("\t\t\t\t\t************************************\t\t\t��ǰ��½״̬������\n");	
	printf("\t\t\t\t\t************************************\n");
	printf("\t\t\t\t\t******                        ******\n");
	printf("\t\t\t\t\t******    �� �� �� �� ϵ ͳ   ******\n");
	printf("\t\t\t\t\t******                        ******\n");
	printf("\t\t\t\t\t******                        ******\n");
	printf("\t\t\t\t\t******     1. �� Ʊ ϵ ͳ     ******\n");
	printf("\t\t\t\t\t******     2. �� Ʊ ϵ ͳ     ******\n");
	printf("\t\t\t\t\t******     3. �г���Ϣ��ѯ    ******\n");
	printf("\t\t\t\t\t******     4. ������Ϣ��ѯ    ******\n");
	printf("\t\t\t\t\t******     5. �� ½ ϵ ͳ     ******\n");
	printf("\t\t\t\t\t******     6. �� �� �� ½     ******\n");
	printf("\t\t\t\t\t******     0. �� �� ϵ ͳ     ******\n");
	printf("\t\t\t\t\t******                        ******\n");
	printf("\t\t\t\t\t******                        ******\n");
	printf("\t\t\t\t\t************************************\n");
	printf("\t\t\t\t\t************************************\n");
}
void choose() {
	system("color 9F");
	//system("color 17");//���ñ�����ɫ
L1:	menu(); 
	int choose;
	printf("\t\t\t\t\t����������ѡ��ϵͳ����:");
	scanf("%d",&choose);
	while (choose > 6 || choose < 0) {
		printf("���������д�������ѡ��\n");
		scanf("%d", &choose);
	}
	system("cls");    //���� 
	if(Login_status==0&&choose!=5&&choose!=0){
		system("cls");
		system("color 9F");
						printf("\n\t\t\t\t\t************************************\n");
							printf("\t\t\t\t\t************************************\n");
							printf("\t\t\t\t\t******                        ******\n");
							printf("\t\t\t\t\t******      �� �� �� ½ ��    ******\n");
							printf("\t\t\t\t\t******                        ******\n");
							printf("\t\t\t\t\t************************************\n");
							printf("\t\t\t\t\t************************************\n");
		system("pause");
		goto L1;
	}
	switch (choose) {
	case 1: {
		TrainBooking();
		goto L1;
	}break;
	case 2: {
			TrainUnBooking();
			goto L1;
	} break;
	case 3: {
			//Train_inquiry_admin();
			Train_inquiry_user();
			goto L1;
	} break;
	case 4: { 
			PersonalInformationInquiry();
			goto L1;
	} break;
	case 5: { 
		userload();
		goto L1;
	} break;
	case 6: {
		Exitlogin();
		goto L1;	
	} break;
	case 0:{
		printf("��ѡ���˳�ϵͳ!\n");
		break;
	}
	system("cls"); 
	goto L1;
	printf("\nmain�������н���\n");
	}
}
void userload() {
	system("color 9F");
	char username[20];
	char password[20];
	time_t timep;    //ϵͳʱ�� 
	struct tm* p;
	time(&timep);
	p = gmtime(&timep);
	system("cls");
	if(Login_status==1){
			printf("\n\n\n\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t******    �� ǰ �� �� ½ ��   ******\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n\n\n");
		system("pause");
		return;
	}
			printf("\t\t\t\t\t\t   %d��%02d��%02d��\n", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
			printf("\t\t\t\t\t\t  ��ǰʱ��%02dʱ%02d��%\n", 8 + p->tm_hour, p->tm_min);
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t******       �� ½ ϵ ͳ      ******\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
			printf("  �����������˺�\n");
			printf("\t�˺�:\t") ;
			scanf("%s", username);
			printf("  ��������������\n");
			printf("\t����:\t") ;
/*
	������������Ϊ* 
*/
	 int x = 0;
	 char c;
	 while(x < 80 && c != 13)   
 	{
 	 	c = getch();
 	 	if(c != 13&&c!=8){
 	 		 putchar('*');
 		 }
 	  	else if(c==8&&x>0){
 	 	 	printf("\b \b");  //�˸񣬴�һ���ո����˸�ʵ�������ÿո񸲸ǵ��Ǻ�
	  		--x;
			continue;
 	  	}
 	   password[x++] = c;
 	}
 	password[x] = '\0';
 	//printf("\n%s\n",password);
 	int username_flag=-1;
 	int password_flag=-1;
 	system("cls");
 	for(int i=0;i<user[0].n;i++){//��ѯ���ݿ����Ƿ������� 
 		 	password[x-1]=0;//�������ַ������ȼ�һ�������ַ�������˸�δ֪���ַ��� 
 		username_flag=strcmp(username,user[i].username); 
 		password_flag=strcmp(password,user[i].password);
 		if(username_flag==0&&password_flag==0){
 			Login_status=1;
 			strcpy(NowUser,username);//�ѵ�ǰ��½���û������Ƶ�ȫ�ֱ��� 
			printf("\n\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t******       �� ½ �� ��      ******\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
 		}else{
 			if(i==user[0].n-1&&Login_status==0){
			printf("\n\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t******       �� ½ ʧ ��      ******\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
 			}
 		} 
 	} 
 	system("pause");
 	system("cls");
}
void Exitlogin(){
	 	system("cls");
	 	system("color 9F");
		 if(Login_status==1){
		 	printf("\n\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t******       �� �� �� ��      ******\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
				Login_status=0;//��½״̬����Ϊ���� 
				strcpy(NowUser, "");//��յ�ǰ�����û� 
		 } else{
		 		printf("\n\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t******       �� �� ʧ ��      ******\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
			printf("����ԭ��\n\n\t��ǰ��½״̬Ϊ������\n\n") ;
		 }
	 	system("pause");
	 	system("cls");
}
void  Train_inquiry_admin() {
	system("cls");
	system("color 9F");
		printf("\n\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t******       �� �� �� Ϣ      ******\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\t\t��ǰ����ʽ: �г��ŵ���\n");
	printf("\n\n\t  \t�г���\tʼ��վ\t��ͣվ\t�յ�վ\t��������\t����ʱ�� Ʊ��\t��λ��\tʣ��λ��\n");
	for(int i=0;i<train[0].n;i++){
			printf("\t  \t%s\t%s\t%s\t%s\t%s\t %s\t %d\t %d\t %d\t\n",train[i].trainid,train[i].firststand,train[i].middlestand,train[i].finalstand,train[i].time_day,train[i].time_hour,train[i].prize,train[i].totalzw,train[i].freezw);
	}
}
void Train_inquiry_user(){
	system("color 9F");
	char TrainNum[20];
	int TrainNumFlag=-1;
			printf("\n\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t******       �� �� �� ѯ      ******\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
			printf("������Ҫ��ѯ�г����г���:\n\t");
			scanf("%s",TrainNum);
			for(int i=0;i<train[0].n;i++){
				TrainNumFlag=strcmp(TrainNum,train[i].trainid);
				if(TrainNumFlag==0){
	 				system("cls");
					printf("\n\t\t\t\t\t************************************\n");
					printf("\t\t\t\t\t************************************\n");
					printf("\t\t\t\t\t******                        ******\n");
					printf("\t\t\t\t\t******       �� �� �� Ϣ      ******\n");
					printf("\t\t\t\t\t******                        ******\n");
					printf("\t\t\t\t\t************************************\n");
					printf("\t\t\t\t\t************************************\n");
						printf("\n\n\t  \t�г���\tʼ��վ\t��ͣվ\t�յ�վ\t��������\t����ʱ�� Ʊ��\t��λ��\tʣ��λ��\n");
					printf("\t  \t%s\t%s\t%s\t%s\t%s\t %s\t %d\t %d\t %d\t\n",train[i].trainid,train[i].firststand,train[i].middlestand,train[i].finalstand,train[i].time_day,train[i].time_hour,train[i].prize,train[i].totalzw,train[i].freezw);
						system("pause");
					break;
				}
				else if(i==train[0].n-1){
					system("cls");
					printf("\n\t\t\t\t\t************************************\n");
					printf("\t\t\t\t\t************************************\n");
					printf("\t\t\t\t\t******                        ******\n");
					printf("\t\t\t\t\t******      �� �� �� �� ��    ******\n");
					printf("\t\t\t\t\t******                        ******\n");
					printf("\t\t\t\t\t************************************\n");
					printf("\t\t\t\t\t************************************\n");
					system("pause");
				}
				
			}
}
void PersonalInformationInquiry(){
	char IdCardNum[20];
	int TrainNumFlag=-1;
			printf("\n\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t******    �� �� Ԥ �� �� ѯ   ******\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
			char NowUserPath[20];
						strcpy(NowUserPath,NowUser);
						strcat(NowUserPath,".txt");//����һ���û���+.txt���ļ� 
				FILE *fp = fopen(NowUserPath, "r");// ���ļ�������fpָ���ļ� 
  			  if (fp == NULL) {
        		fprintf(stderr, "�ļ���ʧ��.\n");
       			 exit(EXIT_FAILURE);
    			}
    			printf("\n\n\t  \t�г���\tʼ��վ\t��ͣվ\t�յ�վ\t��������\t����ʱ�� Ʊ��\t��λ��\tʣ��λ��\n");
    			char str[60];
    			
    			while (fgets(str, 60, fp) != NULL)
				{
					//printf("%s",RdStrng);
					printf("\t  \t");
   					   puts(str);
				}
  				 fclose(fp);
			system("pause");
} 
void TrainBooking(){
	system("cls");
	printf("\n\n\t\t\t\t\t************************************\n");
	printf("\t\t\t\t\t************************************\n");
	printf("\t\t\t\t\t******                        ******\n");
	printf("\t\t\t\t\t******       �� Ʊ ϵ ͳ      ******\n");
	printf("\t\t\t\t\t******                        ******\n");
	printf("\t\t\t\t\t******     1. �г��ִ����    ******\n");
	printf("\t\t\t\t\t******     2. �� �� ʱ ��     ******\n");
	printf("\t\t\t\t\t******     3. �� Ʊ �� ��     ******\n");
	printf("\t\t\t\t\t******                        ******\n");
	printf("\t\t\t\t\t******                        ******\n");
	printf("\t\t\t\t\t************************************\n");
	printf("\t\t\t\t\t************************************\n");
	printf("��ѡ��Ҫ��ѯ������:\n\t");
		int choose=-1;
		scanf("%d",&choose);
		switch (choose){
			case 1:{
				printf("�������г��ִ����:\n\t");
				break;
			}
			case 2:{
				printf("�������г�����ʱ��:\n\t");
				printf("��ʽ: 2022/xx/xx\t\n\t");
				break;
			}
			case 3:{
					printf("�����붩Ʊ����:\n\t");
				break;
			}
		}
		char TrainBooking[20];
		scanf("%s",TrainBooking);
		printf("\n\n\t\t\t\t\t************************************\n");
	printf("\t\t\t\t\t************************************\n");
	printf("\t\t\t\t\t******                        ******\n");
	printf("\t\t\t\t\t******     ��ѡ������ʽ:    ******\n");
	printf("\t\t\t\t\t******                        ******\n");
	printf("\t\t\t\t\t******     1. �� �� ʱ ��     ******\n");
	printf("\t\t\t\t\t******     2. ��    ��        ******\n");
	printf("\t\t\t\t\t******     3. ��  ��  ��      ******\n");
	printf("\t\t\t\t\t******                        ******\n");
	printf("\t\t\t\t\t******                        ******\n");
	printf("\t\t\t\t\t************************************\n");
	printf("\t\t\t\t\t************************************\n");
	int squrychoose;
	scanf("%d",&squrychoose);//��������ʽ 
		int TrainBooking_flag=-1;
		int count=0;//�г���Ϣ�ļ�������ֻ���һ�Σ� 
		int count2=0;//��¼����г���Ϣ�Ĵ��� 
				system("cls");
				for(int i=0;i<train[0].n;i++){
					switch(choose){
						case 1:{
							TrainBooking_flag = strcmp(TrainBooking,train[i].finalstand); //�Ƚ��յ�վ 
							break;
						}
						case 2:{
							TrainBooking_flag = strcmp(TrainBooking,train[i].time_day ); //�ȽϷ������� 
							break;
						}
						case 3:{
							char temp[30]; 
							 itoa(train[i].freezw,temp,10);
							TrainBooking_flag = strcmp(TrainBooking,temp); //�Ƚ��г���Ʊ 
							break;
						}
					}
					if(TrainBooking_flag==0){
						if(count==0){
							
							printf("\n\t\t\t\t\t************************************\n");
							printf("\t\t\t\t\t************************************\n");
							printf("\t\t\t\t\t******                        ******\n");
							printf("\t\t\t\t\t******       �� �� �� Ϣ      ******\n");
							printf("\t\t\t\t\t******                        ******\n");
							printf("\t\t\t\t\t************************************\n");
							printf("\t\t\t\t\t************************************\n");
							switch(squrychoose){
								case 1:{
									printf("����Ҫ����г���Ϣ����\t\t\t\t\t\t\t\t\t��ǰ����ʽ��ʱ�����\n");
									break;
								}
								case 2:{
									printf("����Ҫ����г���Ϣ����\t\t\t\t\t\t\t\t\t��ǰ����ʽ���۸����\n");
									break;
								}case 3:{
									printf("����Ҫ����г���Ϣ����\t\t\t\t\t\t\t\t\t��ǰ����ʽ���г��ŵ���\n");
								}
							}
							
							printf("\n\n\t  \t�г���\tʼ��վ\t��ͣվ\t�յ�վ\t��������\t����ʱ�� Ʊ��\t��λ��\tʣ��λ��\n");
						}
						count++;
						count2++;
								printf("\t  \t%s\t%s\t%s\t%s\t%s\t %s\t %d\t %d\t %d\t\n",train[i].trainid,train[i].firststand,train[i].middlestand,train[i].finalstand,train[i].time_day,train[i].time_hour,train[i].prize,train[i].totalzw,train[i].freezw);
					}
						if(count2==0&&i==train[0].n-1){
							printf("\n\t\t\t\t\t************************************\n");
							printf("\t\t\t\t\t************************************\n");
							printf("\t\t\t\t\t******                        ******\n");
							printf("\t\t\t\t\t******      �� �� �� �� ��    ******\n");
							printf("\t\t\t\t\t******                        ******\n");
							printf("\t\t\t\t\t************************************\n");
							printf("\t\t\t\t\t************************************\n");
						}
				}
					count=0;
					FILE *fp1;
					char BuyTrainId[20];
					if(count2!=0){
						printf("������Ҫ������г��ţ�\n\t");
						scanf("%s",BuyTrainId);
					} 
					if(Login_status==1){
						char NowUserPath[20];
						strcpy(NowUserPath,NowUser);
						strcat(NowUserPath,".txt");//����һ���û���+.txt���ļ� 
						fp1 = fopen(NowUserPath,"a+"); 
						if(fp1!=NULL){    //�ļ��Ѿ�����  �����һ�д���
          				     //fprintf(fp1,"%s",BuyTrainId);
          				     int BuyTrainId_flag=-1;
          				     for(int i=0;i<train[0].n;i++){
          				     	BuyTrainId_flag=strcmp(train[i].trainid,BuyTrainId);//��ѯ�Ƿ�������г� 
          				     	if(BuyTrainId_flag==0){
          				     		train[i].freezw--;
          				     		fprintf(fp1,"%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n",train[i].trainid,train[i].firststand,train[i].middlestand,train[i].finalstand,train[i].time_day,train[i].time_hour,train[i].prize,train[i].totalzw,train[i].freezw);
          				     	 	printf("����ɹ�!\n");
								   }
          				     } 
          				     fclose(fp1);
       				   	}
						else{         
      				     perror("Error: "); //  �ļ�û�д������һ�������Դ�����Ϣ�������׼���� stderr    void perror(const char *str)
      				    }
					}
					else{
						system("cls");
						printf("\n\t\t\t\t\t************************************\n");
							printf("\t\t\t\t\t************************************\n");
							printf("\t\t\t\t\t******                        ******\n");
							printf("\t\t\t\t\t******      �� �� �� ½ ��    ******\n");
							printf("\t\t\t\t\t******                        ******\n");
							printf("\t\t\t\t\t************************************\n");
							printf("\t\t\t\t\t************************************\n");
					} 
					system("pause");
} 
void TrainUnBooking(){
	system("cls");
	system("color 9F");
	char str[60];
	FILE *fp1,*fp;
	char NowUserPath[20];
	strcpy(NowUserPath,NowUser);
	strcat(NowUserPath,".txt");//����һ���û���+.txt���ļ� 
	fp1 = fopen(NowUserPath,"a+"); 
		if(fp1!=NULL){    //�ļ��Ѿ�����  ��ɾ��һ��
		printf("\n\n\t  \t�г���\tʼ��վ\t��ͣվ\t�յ�վ\t��������\t����ʱ�� Ʊ��\t��λ��\tʣ��λ��\n\t  \t");
			  while(fgets(str, 60, fp1) != NULL){
      			  printf("%s", str);
					printf("\t  \t");	     
           	  }
		}
		fclose(fp1);
		printf("������Ҫ��Ʊ������:\n\t\t\t");
		int unbooking;
		char unbookingid[20];
		int unbookingid1;
		scanf("%d",&unbooking);
		for(int i=0;i<unbooking;i++){
			printf("\t\t��ǰ���ڽ��е�%d����Ʊ����:\n\t\t\t",i+1) ;
			printf("�������г���ţ�\n\t\t\t");
			//scanf("%s",unbookingid);
			scanf("%d",&unbookingid1);
			if(0==DeleteFile(unbookingid1,NowUserPath)){
				printf("\t\t��Ʊ�ɹ���\n");
			}
			system("pause");
			system("cls");
			printf("��ǰ��Ʊ��\n");
			//ÿ��һ��Ʊ�����һ�ε�ǰ��Ʊ��Ϣ 
				fp1 = fopen(NowUserPath,"a+"); 
				if(fp1!=NULL){    //�ļ��Ѿ�����  ��ɾ��һ��
				printf("\n\n\t  \t�г���\tʼ��վ\t��ͣվ\t�յ�վ\t��������\t����ʱ�� Ʊ��\t��λ��\tʣ��λ��\n\t  \t");
			 	 while(fgets(str, 60, fp1) != NULL){
      				  printf("%s", str);
						printf("\t  \t");	     
           	  	}
				}
					fclose(fp1);
		} 
		//printf("��Ʊ�����!\n");
		system("pause");
}
int DeleteFile(int linenum,char *Filename){
	char buf[4096]; 
    FILE *fp = fopen(Filename, "r");    
    FILE *fpt = fopen("temp.txt", "w+"); 
    // ���ܴ��ļ����˳�����
    if (!fp) {
        printf("�ļ�������!\n");
        return -1;
    } 
    int total_line = 0;     // ��¼�ļ�������
    while (fgets(buf, sizeof(buf), fp)) {  
        total_line++;
    }
    //printf("�ļ�������:%d\n",total_line);
    if(total_line==0){
    	printf("��ǰû������!\n");
    	return -1;
    }
    	rewind(fp);     //���ļ�ָ���Ƶ��ļ�ͷ
    // ���Ҫɾ���ļ������������ļ����������˳�����
    if (linenum > total_line) {
        printf("Ҫɾ������������������!\n");
        return -1;
    }
    int i = 0;      // ��¼��ǰ��
    while (fgets(buf, sizeof(buf), fp)) {  
        i++;  
        if (i != linenum) {
            fputs(buf, fpt); 
        }
    } 
	 fclose(fp); //�ر��ļ� 
    fclose(fpt); 
    remove(Filename)   ;
	      //perror("remove");
   rename("temp.txt", Filename);    // ��������ʱ�ļ�ΪԴ�ļ�
   return 0;
}
