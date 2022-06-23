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
extern int Login_status;//登陆状态 
extern char NowUser[20];//当前登陆的用户名 

 void readtrainFile(){//读取列车信息文件 
	FILE *fp = fopen("trainFile.txt","r");// 打开文件并且让fp指向文件 
    if (fp == NULL) {
        fprintf(stderr, "文件打开失败.\n");
        exit(EXIT_FAILURE);
    }
    char row[80];
    char *token;
    int i=0;
    if(fgets(row, 80, fp) != NULL){
   	 	while (fgets(row, 80, fp) != NULL) {
      		sscanf(row,"%s%s%s%s%s%s%d%d%d",train[i].trainid,train[i].firststand,train[i].middlestand,train[i].finalstand,train[i].time_day,train[i].time_hour,&train[i].prize,&train[i].totalzw,&train[i].freezw);//把数据存入结构体数组 
      		//printf("%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n",train[i].trainid,train[i].firststand,train[i].middlestand,train[i].finalstand,train[i].time_day,train[i].time_hour,train[i].prize,train[i].totalzw,train[i].freezw);
			i++;
			train[0].n++;
		}
    }
    fclose(fp);
}
void readPassengerINformation(){//读取乘客信息文件 
	FILE *fp = fopen("PassengerINformation.txt", "r");// 打开文件并且让fp指向文件 
    if (fp == NULL) {
        fprintf(stderr, "文件打开失败.\n");
        exit(EXIT_FAILURE);
    }
    char row[80];
    char *token;
    int i=0;
    if(fgets(row, 80, fp) != NULL){
   	 	while (fgets(row, 80, fp) != NULL) {
      		sscanf(row,"%s%s%s%s",Passenger[i].name,Passenger[i].gender,Passenger[i].id,Passenger[i].seat_number);//把数据存入结构体数组 
    		//printf("%s\t%s\t%s\t%s\n",Passenger[i].name,Passenger[i].gender,Passenger[i].id,Passenger[i].seat_number);
			// 	 	 	system("pause");
			i++;
		}
    }
    fclose(fp);
}
void readAccount(){//读取用户信息文件 
	FILE *fp = fopen("账号.txt", "r");// 打开文件并且让fp指向文件 
    if (fp == NULL) {
        fprintf(stderr, "文件打开失败.\n");
        exit(EXIT_FAILURE);
    }
    char row[80];
    char *token;
    int i=0;
    if(fgets(row, 80, fp) != NULL){
   	 	while (fgets(row, 80, fp) != NULL) {
      		sscanf(row,"%s%s",user[i].username,user[i].password);//把数据存入结构体数组 
    	//	printf("%s\t%s\n",user[i].username,user[i].password);
    		 	 //	 	system("pause");
			i++;
			user[0].n=i;
		}
		Login_status=0;//不知道为啥经过while后登陆状态的值被修改了，在此重置值 
    }
    
    fclose(fp);
}
void menu() {
	system("color 9F");
	time_t timep;    //系统时间 
	struct tm* p;
	time(&timep);
	p = gmtime(&timep);
	system("cls");
	printf("\t\t\t\t\t\t   %d年%02d月%02d日\n", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
	printf("\t\t\t\t\t\t  当前时间%02d时%02d分%\n", 8 + p->tm_hour, p->tm_min);
	if(Login_status==0)printf("\t\t\t\t\t************************************\t\t\t当前登陆状态：离线\n");
	else	printf("\t\t\t\t\t************************************\t\t\t当前登陆状态：在线\n");	
	printf("\t\t\t\t\t************************************\n");
	printf("\t\t\t\t\t******                        ******\n");
	printf("\t\t\t\t\t******    高 铁 客 运 系 统   ******\n");
	printf("\t\t\t\t\t******                        ******\n");
	printf("\t\t\t\t\t******                        ******\n");
	printf("\t\t\t\t\t******     1. 订 票 系 统     ******\n");
	printf("\t\t\t\t\t******     2. 退 票 系 统     ******\n");
	printf("\t\t\t\t\t******     3. 列车信息查询    ******\n");
	printf("\t\t\t\t\t******     4. 个人信息查询    ******\n");
	printf("\t\t\t\t\t******     5. 登 陆 系 统     ******\n");
	printf("\t\t\t\t\t******     6. 退 出 登 陆     ******\n");
	printf("\t\t\t\t\t******     0. 退 出 系 统     ******\n");
	printf("\t\t\t\t\t******                        ******\n");
	printf("\t\t\t\t\t******                        ******\n");
	printf("\t\t\t\t\t************************************\n");
	printf("\t\t\t\t\t************************************\n");
}
void choose() {
	system("color 9F");
	//system("color 17");//设置背景颜色
L1:	menu(); 
	int choose;
	printf("\t\t\t\t\t请输入数字选择系统功能:");
	scanf("%d",&choose);
	while (choose > 6 || choose < 0) {
		printf("您的输入有错，请重新选择\n");
		scanf("%d", &choose);
	}
	system("cls");    //清屏 
	if(Login_status==0&&choose!=5&&choose!=0){
		system("cls");
		system("color 9F");
						printf("\n\t\t\t\t\t************************************\n");
							printf("\t\t\t\t\t************************************\n");
							printf("\t\t\t\t\t******                        ******\n");
							printf("\t\t\t\t\t******      请 先 登 陆 ！    ******\n");
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
		printf("您选择退出系统!\n");
		break;
	}
	system("cls"); 
	goto L1;
	printf("\nmain函数运行结束\n");
	}
}
void userload() {
	system("color 9F");
	char username[20];
	char password[20];
	time_t timep;    //系统时间 
	struct tm* p;
	time(&timep);
	p = gmtime(&timep);
	system("cls");
	if(Login_status==1){
			printf("\n\n\n\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t******    当 前 已 登 陆 ！   ******\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n\n\n");
		system("pause");
		return;
	}
			printf("\t\t\t\t\t\t   %d年%02d月%02d日\n", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
			printf("\t\t\t\t\t\t  当前时间%02d时%02d分%\n", 8 + p->tm_hour, p->tm_min);
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t******       登 陆 系 统      ******\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
			printf("  请输入您的账号\n");
			printf("\t账号:\t") ;
			scanf("%s", username);
			printf("  请输入您的密码\n");
			printf("\t密码:\t") ;
/*
	把输入的密码变为* 
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
 	 	 	printf("\b \b");  //退格，打一个空格，再退格，实质上是用空格覆盖掉星号
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
 	for(int i=0;i<user[0].n;i++){//查询数据库中是否有数据 
 		 	password[x-1]=0;//把密码字符串长度减一（密码字符串后多了个未知的字符） 
 		username_flag=strcmp(username,user[i].username); 
 		password_flag=strcmp(password,user[i].password);
 		if(username_flag==0&&password_flag==0){
 			Login_status=1;
 			strcpy(NowUser,username);//把当前登陆的用户名复制到全局变量 
			printf("\n\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t******       登 陆 成 功      ******\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
 		}else{
 			if(i==user[0].n-1&&Login_status==0){
			printf("\n\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t******       登 陆 失 败      ******\n");
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
			printf("\t\t\t\t\t******       登 出 成 功      ******\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
				Login_status=0;//登陆状态设置为下线 
				strcpy(NowUser, "");//清空当前在线用户 
		 } else{
		 		printf("\n\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t******       登 出 失 败      ******\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
			printf("错误原因：\n\n\t当前登陆状态为：离线\n\n") ;
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
			printf("\t\t\t\t\t******       列 车 信 息      ******\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\t\t当前排序方式: 列车号递增\n");
	printf("\n\n\t  \t列车号\t始发站\t经停站\t终点站\t出发日期\t出发时间 票价\t总位置\t剩余位置\n");
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
			printf("\t\t\t\t\t******       列 车 查 询      ******\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
			printf("请输入要查询列车的列车号:\n\t");
			scanf("%s",TrainNum);
			for(int i=0;i<train[0].n;i++){
				TrainNumFlag=strcmp(TrainNum,train[i].trainid);
				if(TrainNumFlag==0){
	 				system("cls");
					printf("\n\t\t\t\t\t************************************\n");
					printf("\t\t\t\t\t************************************\n");
					printf("\t\t\t\t\t******                        ******\n");
					printf("\t\t\t\t\t******       列 车 信 息      ******\n");
					printf("\t\t\t\t\t******                        ******\n");
					printf("\t\t\t\t\t************************************\n");
					printf("\t\t\t\t\t************************************\n");
						printf("\n\n\t  \t列车号\t始发站\t经停站\t终点站\t出发日期\t出发时间 票价\t总位置\t剩余位置\n");
					printf("\t  \t%s\t%s\t%s\t%s\t%s\t %s\t %d\t %d\t %d\t\n",train[i].trainid,train[i].firststand,train[i].middlestand,train[i].finalstand,train[i].time_day,train[i].time_hour,train[i].prize,train[i].totalzw,train[i].freezw);
						system("pause");
					break;
				}
				else if(i==train[0].n-1){
					system("cls");
					printf("\n\t\t\t\t\t************************************\n");
					printf("\t\t\t\t\t************************************\n");
					printf("\t\t\t\t\t******                        ******\n");
					printf("\t\t\t\t\t******      无 此 列 车 ！    ******\n");
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
			printf("\t\t\t\t\t******    个 人 预 定 查 询   ******\n");
			printf("\t\t\t\t\t******                        ******\n");
			printf("\t\t\t\t\t************************************\n");
			printf("\t\t\t\t\t************************************\n");
			char NowUserPath[20];
						strcpy(NowUserPath,NowUser);
						strcat(NowUserPath,".txt");//创建一个用户名+.txt的文件 
				FILE *fp = fopen(NowUserPath, "r");// 打开文件并且让fp指向文件 
  			  if (fp == NULL) {
        		fprintf(stderr, "文件打开失败.\n");
       			 exit(EXIT_FAILURE);
    			}
    			printf("\n\n\t  \t列车号\t始发站\t经停站\t终点站\t出发日期\t出发时间 票价\t总位置\t剩余位置\n");
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
	printf("\t\t\t\t\t******       订 票 系 统      ******\n");
	printf("\t\t\t\t\t******                        ******\n");
	printf("\t\t\t\t\t******     1. 列车抵达城市    ******\n");
	printf("\t\t\t\t\t******     2. 发 出 时 间     ******\n");
	printf("\t\t\t\t\t******     3. 订 票 数 量     ******\n");
	printf("\t\t\t\t\t******                        ******\n");
	printf("\t\t\t\t\t******                        ******\n");
	printf("\t\t\t\t\t************************************\n");
	printf("\t\t\t\t\t************************************\n");
	printf("请选择要查询的条件:\n\t");
		int choose=-1;
		scanf("%d",&choose);
		switch (choose){
			case 1:{
				printf("请输入列车抵达城市:\n\t");
				break;
			}
			case 2:{
				printf("请输入列车发出时间:\n\t");
				printf("格式: 2022/xx/xx\t\n\t");
				break;
			}
			case 3:{
					printf("请输入订票数量:\n\t");
				break;
			}
		}
		char TrainBooking[20];
		scanf("%s",TrainBooking);
		printf("\n\n\t\t\t\t\t************************************\n");
	printf("\t\t\t\t\t************************************\n");
	printf("\t\t\t\t\t******                        ******\n");
	printf("\t\t\t\t\t******     请选择排序方式:    ******\n");
	printf("\t\t\t\t\t******                        ******\n");
	printf("\t\t\t\t\t******     1. 发 车 时 间     ******\n");
	printf("\t\t\t\t\t******     2. 价    格        ******\n");
	printf("\t\t\t\t\t******     3. 列  车  号      ******\n");
	printf("\t\t\t\t\t******                        ******\n");
	printf("\t\t\t\t\t******                        ******\n");
	printf("\t\t\t\t\t************************************\n");
	printf("\t\t\t\t\t************************************\n");
	int squrychoose;
	scanf("%d",&squrychoose);//输入排序方式 
		int TrainBooking_flag=-1;
		int count=0;//列车信息的计数器（只输出一次） 
		int count2=0;//记录输出列车信息的次数 
				system("cls");
				for(int i=0;i<train[0].n;i++){
					switch(choose){
						case 1:{
							TrainBooking_flag = strcmp(TrainBooking,train[i].finalstand); //比较终点站 
							break;
						}
						case 2:{
							TrainBooking_flag = strcmp(TrainBooking,train[i].time_day ); //比较发车日期 
							break;
						}
						case 3:{
							char temp[30]; 
							 itoa(train[i].freezw,temp,10);
							TrainBooking_flag = strcmp(TrainBooking,temp); //比较列车余票 
							break;
						}
					}
					if(TrainBooking_flag==0){
						if(count==0){
							
							printf("\n\t\t\t\t\t************************************\n");
							printf("\t\t\t\t\t************************************\n");
							printf("\t\t\t\t\t******                        ******\n");
							printf("\t\t\t\t\t******       列 车 信 息      ******\n");
							printf("\t\t\t\t\t******                        ******\n");
							printf("\t\t\t\t\t************************************\n");
							printf("\t\t\t\t\t************************************\n");
							switch(squrychoose){
								case 1:{
									printf("符合要求的列车信息如下\t\t\t\t\t\t\t\t\t当前排序方式：时间递增\n");
									break;
								}
								case 2:{
									printf("符合要求的列车信息如下\t\t\t\t\t\t\t\t\t当前排序方式：价格递增\n");
									break;
								}case 3:{
									printf("符合要求的列车信息如下\t\t\t\t\t\t\t\t\t当前排序方式：列车号递增\n");
								}
							}
							
							printf("\n\n\t  \t列车号\t始发站\t经停站\t终点站\t出发日期\t出发时间 票价\t总位置\t剩余位置\n");
						}
						count++;
						count2++;
								printf("\t  \t%s\t%s\t%s\t%s\t%s\t %s\t %d\t %d\t %d\t\n",train[i].trainid,train[i].firststand,train[i].middlestand,train[i].finalstand,train[i].time_day,train[i].time_hour,train[i].prize,train[i].totalzw,train[i].freezw);
					}
						if(count2==0&&i==train[0].n-1){
							printf("\n\t\t\t\t\t************************************\n");
							printf("\t\t\t\t\t************************************\n");
							printf("\t\t\t\t\t******                        ******\n");
							printf("\t\t\t\t\t******      无 此 列 车 ！    ******\n");
							printf("\t\t\t\t\t******                        ******\n");
							printf("\t\t\t\t\t************************************\n");
							printf("\t\t\t\t\t************************************\n");
						}
				}
					count=0;
					FILE *fp1;
					char BuyTrainId[20];
					if(count2!=0){
						printf("请输入要购买的列车号：\n\t");
						scanf("%s",BuyTrainId);
					} 
					if(Login_status==1){
						char NowUserPath[20];
						strcpy(NowUserPath,NowUser);
						strcat(NowUserPath,".txt");//创建一个用户名+.txt的文件 
						fp1 = fopen(NowUserPath,"a+"); 
						if(fp1!=NULL){    //文件已经创建  则加入一行代码
          				     //fprintf(fp1,"%s",BuyTrainId);
          				     int BuyTrainId_flag=-1;
          				     for(int i=0;i<train[0].n;i++){
          				     	BuyTrainId_flag=strcmp(train[i].trainid,BuyTrainId);//查询是否有这个列车 
          				     	if(BuyTrainId_flag==0){
          				     		train[i].freezw--;
          				     		fprintf(fp1,"%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n",train[i].trainid,train[i].firststand,train[i].middlestand,train[i].finalstand,train[i].time_day,train[i].time_hour,train[i].prize,train[i].totalzw,train[i].freezw);
          				     	 	printf("购买成功!\n");
								   }
          				     } 
          				     fclose(fp1);
       				   	}
						else{         
      				     perror("Error: "); //  文件没有创建则把一个描述性错误消息输出到标准错误 stderr    void perror(const char *str)
      				    }
					}
					else{
						system("cls");
						printf("\n\t\t\t\t\t************************************\n");
							printf("\t\t\t\t\t************************************\n");
							printf("\t\t\t\t\t******                        ******\n");
							printf("\t\t\t\t\t******      请 先 登 陆 ！    ******\n");
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
	strcat(NowUserPath,".txt");//创建一个用户名+.txt的文件 
	fp1 = fopen(NowUserPath,"a+"); 
		if(fp1!=NULL){    //文件已经创建  则删除一行
		printf("\n\n\t  \t列车号\t始发站\t经停站\t终点站\t出发日期\t出发时间 票价\t总位置\t剩余位置\n\t  \t");
			  while(fgets(str, 60, fp1) != NULL){
      			  printf("%s", str);
					printf("\t  \t");	     
           	  }
		}
		fclose(fp1);
		printf("请输入要退票的数量:\n\t\t\t");
		int unbooking;
		char unbookingid[20];
		int unbookingid1;
		scanf("%d",&unbooking);
		for(int i=0;i<unbooking;i++){
			printf("\t\t当前正在进行第%d个退票操作:\n\t\t\t",i+1) ;
			printf("请输入列车序号：\n\t\t\t");
			//scanf("%s",unbookingid);
			scanf("%d",&unbookingid1);
			if(0==DeleteFile(unbookingid1,NowUserPath)){
				printf("\t\t退票成功！\n");
			}
			system("pause");
			system("cls");
			printf("当前订票：\n");
			//每退一次票就输出一次当前订票消息 
				fp1 = fopen(NowUserPath,"a+"); 
				if(fp1!=NULL){    //文件已经创建  则删除一行
				printf("\n\n\t  \t列车号\t始发站\t经停站\t终点站\t出发日期\t出发时间 票价\t总位置\t剩余位置\n\t  \t");
			 	 while(fgets(str, 60, fp1) != NULL){
      				  printf("%s", str);
						printf("\t  \t");	     
           	  	}
				}
					fclose(fp1);
		} 
		//printf("退票已完成!\n");
		system("pause");
}
int DeleteFile(int linenum,char *Filename){
	char buf[4096]; 
    FILE *fp = fopen(Filename, "r");    
    FILE *fpt = fopen("temp.txt", "w+"); 
    // 不能打开文件，退出程序
    if (!fp) {
        printf("文件不存在!\n");
        return -1;
    } 
    int total_line = 0;     // 记录文件总行数
    while (fgets(buf, sizeof(buf), fp)) {  
        total_line++;
    }
    //printf("文件总行数:%d\n",total_line);
    if(total_line==0){
    	printf("当前没有数据!\n");
    	return -1;
    }
    	rewind(fp);     //将文件指针移到文件头
    // 如果要删除文件的行数大于文件总行数，退出程序
    if (linenum > total_line) {
        printf("要删除的行数比总行数大!\n");
        return -1;
    }
    int i = 0;      // 记录当前行
    while (fgets(buf, sizeof(buf), fp)) {  
        i++;  
        if (i != linenum) {
            fputs(buf, fpt); 
        }
    } 
	 fclose(fp); //关闭文件 
    fclose(fpt); 
    remove(Filename)   ;
	      //perror("remove");
   rename("temp.txt", Filename);    // 重命名临时文件为源文件
   return 0;
}
