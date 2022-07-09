#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define N 3

//structure for menu item
struct menu
{
	int id;
char itemName[25];
int rate;
};

//structure for user
struct user{
	char userId[20];
	//char userRole[20];
	char password[20];
};

//structure for customer
struct customer{
	char customerName[20];
	int customerTableNumber;
int  orderListId[10];
};

//Function used in this project
/*void p_bill();
void order();
void ext();
void menu1();
void e_menu();
void login();
void welcomeadmin();
bool isValidUser();
*/

int getNewId();
bool isDuplicateItem(char[]);
void FirstScreen();
void welcome();
void printStar(int);
void indexOutlook();
void admin(int );
void customer();
void customerPage();
void staffPage();
void adminPage();
void staff(int);
void addAdmin();
void addFood();
void viewFood();
void exit();
bool isValidateUser();
bool isNotvalidTable(int);
int getCount();
void editCost();
void showMenu();
void readMenu();

//main Function entry point of project
int main(){
	FirstScreen();
	welcome();
	getch();
	return 0;
}

//welcome page loading...
void welcome(){
	system("cls");
	int choice=1;
	printStar(50);
	indexOutlook();
	printStar(50);
	scanf("%d",&choice);
	if(choice==1){
		customer();
	}
	else if(choice==2){
		admin(1); 
	}
	else if(choice==3){
	staff(1);	
	}
	else if(choice==4){
		FirstScreen();
	exit();	
	}
	else{
		printf("\t\t\t\t\t\t\t\tEnter valid choice eg. 1 or 2 or 3 or 4... Thanks\n");
		printf("\t\t\t\t\t\t\t\tPress any key to continue!! \n");
		getch();
		system("cls");
		welcome();
	}

}

//printing star function
void printStar(int n){
	for(int i=0;i<n;i++){
		printf("\t\t\t\t\t\t\t\t*");
	}
	printf("\t\t\t\t\t\t\t\t\n");
}

//index page or first page on output
void indexOutlook(){
	printf("\t\t\t\t\t\t\t\tSelect User \n");
	printf("\t\t\t\t\t\t\t\t1--> Customer \n");
	printf("\t\t\t\t\t\t\t\t2--> Admin \n");
	printf("\t\t\t\t\t\t\t\t3--> Staff \n");
	printf("\t\t\t\t\t\t\t\t4--> Exit \n");
}

//exit function
void exit(){
	exit(0);
}

//admin Function
void admin(int i){
	system("cls");
	if(isValidateUser()){
		adminPage();
	}
		else{
		printf("\t\t\t\t\t\t\t\t\nPlease Enter valid Id or password %d Option remaining \n",3-i);
		printf("\t\t\t\t\t\t\t\tEnter any key to continue...\n");
		getch();
		if(i<3){
		admin((i+1));	
		}
		else{
		system("cls");
		printf("\t\t\t\t\t\t\t\t\nYou entered more  than 3 wrong password...\n");
		printf("\t\t\t\t\t\t\t\tPlease try againlater thank you ...\n");
		printf("\t\t\t\t\t\t\t\tEnter any key to continue...\n");
		getch();
		exit();	
		}
		
	}
}

//customer Function
void customer(){
	system("cls");
	customerPage();
}

//staff Function
void staff(int i){
	int choice;
system("cls");
	if(isValidateUser()){
		staffPage();
		
	}
	else{
		printf("\t\t\t\t\t\t\t\tPlease Enter valid Id or password %d Option remaining \n",3-i);
		printf("\t\t\t\t\t\t\t\tEnter any key to continue...\n");
		getch();
		if(i<3){
		staff((i+1));	
		}
		else{
		printf("\t\t\t\t\t\t\t\tYou entered more  than 3 wrong password...\n");
		printf("\t\t\t\t\t\t\t\tPlease try againlater thank you ...\n");
		printf("\t\t\t\t\t\t\t\tEnter any key to continue...\n");
		getch();
		exit();	
		}
		
	}
}

//admin Page
void adminPage(){
	int choice;
	system("cls");
	printStar(40);
	printf("\t\t\t\t\t\t\t\tEnter the option...\n");
	printf("\t\t\t\t\t\t\t\t1--> Add admin to the database \n");
	printf("\t\t\t\t\t\t\t\t2--> Add food item to the menu \n");
	printf("\t\t\t\t\t\t\t\t3--> Show the food item in menu \n");
	printf("\t\t\t\t\t\t\t\t4--> Edit cost of food item \n");
	printf("\t\t\t\t\t\t\t\t5--> Goto previous menu \n");
	printStar(40);
	scanf("%d",&choice);
	if(choice==1){
		system("cls");
		addAdmin();
	}
	else if(choice==2){
		system("cls");
		addFood();
	}
	else if(choice==3){
		system("cls");
		viewFood();
	}
	else if(choice==4){
		system("cls");
		editCost();
		printf("\t\t\t\t\t\t\t\tEnter any key to continue\n\n");
		getch();
		system("cls");
		adminPage();
		
	}
	else if(choice==5){
		system("cls");
		welcome();
	}
	else{
		printf("\t\t\t\t\t\t\t\t\n Enter valid option! \n");
		printf("\t\t\t\t\t\t\t\tEnter any key to continue!! \n");
		getch();
		adminPage();
	}
	
}

//customer page
void customerPage(){
	system("cls");
	struct customer c;
	int choice;
	printStar(40);
	printf("\t\t\t\t\t\t\t\tEnter the option...\n");
	printf("\t\t\t\t\t\t\t\t1--> View Menu \n");
	printf("\t\t\t\t\t\t\t\t2--> Order Food \n");
	printf("\t\t\t\t\t\t\t\t3--> Order Bill \n");
	printf("\t\t\t\t\t\t\t\t4--> Goto previous menu \n");
	printStar(40);
	scanf("%d",&choice);
	if(choice==1){
	system("cls");
	showMenu();
	printf("\t\t\t\t\t\t\t\t\n\nPress any key to continue@@\n\n");
	getch();
	system("cls");
	customerPage();
	}
	else if(choice==2){
	system("cls");
	int itemId;
	int ch;
	printf("\t\t\t\t\t\t\t\t Enter your name\n");
	scanf("%s",c.customerName);
		printf("\t\t\t\t\t\t\t\tEnter your table \n");
		scanf("%d",&c.customerTableNumber);
		while(isNotvalidTable(c.customerTableNumber)){	
			printf("\t\t\t\t\t\t\t\tEnter your Another table Number\n");
			scanf("%d",&c.customerTableNumber);
		}
		printf("\t\t\t\t\t\t\t\t\n\n Today's Menu \n\n");
		showMenu();
		int i=0;
	do{
			printf("\t\t\t\t\t\t\t\t\n\nEnter the food id to order\n");
			scanf("%d",&c.orderListId[i]);
			i++;
			printf("\t\t\t\t\t\t\t\tEnter 1 to add another item to your order\n");
			printf("\t\t\t\t\t\t\t\tOR Press 0 other key to end order and go back \n");
			scanf("%d",&ch);
			}while(ch==1);
			
			FILE *fp;
			fp=fopen("orderList.txt","a");
			if(fp==NULL){
				system("cls");
				printf("\t\t\t\t\t\t\t\tFile can not be opened!!!\n");

			}
			else{
			fwrite(&c,sizeof(struct customer),1,fp);
	fclose(fp);	
			}
			printf("\t\t\t\t\t\t\t\tPress any key to continue... \n");
		getch();
		system("cls");
		customerPage();
			
	}
	else if(choice==3){
		int tn;
		system("cls");
		printf("\t\t\t\t\t\t\t\tEnter your table Number:\n");
		scanf("%d",&tn);
		FILE *fp,*fp1;
		struct menu m;
	//fp1=fopen("FoodMenu.txt","r");
			fp=fopen("orderList.txt","r");
			//fp1=fopen("FoodMenu.txt","r");
			if(fp==NULL){
				system("cls");
				printf("\t\t\t\t\t\t\t\tFile can not be opened!!!\n");
			//	system("cls");
				
			}
			else{
			while(fread(&c,sizeof(struct customer),1,fp)){
				if(c.customerTableNumber==tn){
					
					system("cls");
					printStar(50);
					printf("\t\t\t\t\t\t\t\tYour name : %s\n\n",c.customerName);
					printf("\t\t\t\t\t\t\t\tTable Number:%d\n\n",tn);
					int k=0;
					int totalcost=0;
					printf("\t\t\t\t\t\t\t\tYOur order List IS: \n");
					while(c.orderListId[k]){
						fp1=fopen("FoodMenu.txt","r");
						while(fread(&m,sizeof(struct menu),1,fp1))
						if(c.orderListId[k]==m.id){
							printf("\t\t\t\t\t\t\t\t\t\t%20s\t\t%d\n",m.itemName,m.rate);
							totalcost+=m.rate;
							
						}
						fclose(fp1);
						
						k++;
					//	printf("\t\t\t\t\t\t\t\tfood items are:%d\n",c.orderListId[k]);
					}
					
					printf("\t\t\t\t\t\t\t\tYOur Total cost:%d \n",totalcost);
						printStar(50);
				}
			
			}
	fclose(fp);	
	fclose(fp1);
			}
				printf("\t\t\t\t\t\t\t\tPress any key to continue... \n");
		getch();
		system("cls");
		customerPage();
			
	}
	else if(choice==4){
	system("cls");
		welcome();
	}
	else{
		printf("\t\t\t\t\t\t\t\tEnter valid options!!\n");
			printf("\t\t\t\t\t\t\t\tPress any key to continue... \n");
		getch();
		system("cls");
		customerPage();
	}
	
}

//isNotvalidTable function
bool isNotvalidTable(int a){
	FILE *fp;
	bool result=false;
		struct customer c;
	//fp1=fopen("FoodMenu.txt","r");
			fp=fopen("orderList.txt","r");
			//fp1=fopen("FoodMenu.txt","r");
			if(fp==NULL){
				printf("\t\t\t\t\t\t\t\tFile can not be opened!!!\n");

			}
			else{
			while(fread(&c,sizeof(struct customer),1,fp)){
			if(c.customerTableNumber==a){
				result=true;
			}
			}
			fclose(fp);
			return result;
}
}

//staff page
void staffPage(){
	system("cls");
	int choice;
		printStar(40);
	printf("\t\t\t\t\t\t\t\tEnter the option...\n");
	printf("\t\t\t\t\t\t\t\t1--> Edit cost of food item \n");
	printf("\t\t\t\t\t\t\t\t2--> Add food item to the menu \n");
	printf("\t\t\t\t\t\t\t\t3--> Show the food item in menu \n");
	printf("\t\t\t\t\t\t\t\t4--> Goto previous menu \n");
	printStar(40);
	scanf("%d",&choice);
	if(choice==1){
		system("cls");
		editCost();
		printf("\t\t\t\t\t\t\t\tPress any key to continue@ \n");
		getch();
		system("cls");
		staffPage();
	}
	else if (choice==2){
		system("cls");
	addFood();	
	}
	else if(choice==3){
		system("cls");
		viewFood();
	}
	else if(choice==4){
		system("cls");
		welcome();
	}
	else{
		printf("\t\t\t\t\t\t\t\tEnter valid options!!\n");
		
	}
}

//validation user
bool isValidateUser(){
	FILE *fp;
	fp=fopen("admin.txt","r");
	char userId[20];
	char userPass[20];
	printf("\t\t\t\t\t\t\t\tEnter User Id \n");
	scanf("%s",userId);
		printf("\t\t\t\t\t\t\t\tEnter User Password \n");
	//scanf("%s",userPass);
	int p=0;
    do{
        userPass[p]=getch();
        if(userPass[p]!='\r'){
            printf("\t\t\t\t\t\t\t\t*");
        }
        p++;
    }while(userPass[p-1]!='\r');
    userPass[p-1]='\0';
	if(fp==NULL){
		//printf("\t\t\t\t\t\t\t\tPlease create add admin first")
		if((strcmp(userId,"admin")==0&&strcmp(userPass,"admin")==0)){
		return 1;
	}
	}
	struct user u;
	while(fread(&u,sizeof(struct user),1,fp)){
	
	if((strcmp(userId,u.userId)==0&&strcmp(userPass,u.password)==0)||(strcmp(userId,"admin")==0&&strcmp(userPass,"admin")==0)){
		return 1;
	}
	}	
		return 0;
}

int getCount(){
	int a=1;
	return a;
}

//adding food to file
void addFood(){
		readMenu();
		adminPage();
}

//viewing the foods in file
void viewFood(){
		showMenu();
		printf("\t\t\t\t\t\t\t\tEnter any key to continue\n\n");
		getch();
		system("cls");
		adminPage();
}

//adding admin to file
void addAdmin(){
	struct user u;
FILE *fp;
fp=fopen("admin.txt","a");
if(fp==NULL){
	printf("\t\t\t\t\t\t\t\tFile can not be opened!!");
	printf("\t\t\t\t\t\t\t\tPress any key to continue@ \n");
		getch();
		system("cls");
		adminPage();
}
else{
	printf("\t\t\t\t\t\t\t\tEnter user Id to add \n");
	scanf("%s",u.userId);
	printf("\t\t\t\t\t\t\t\tEnter user Pass to add \n");
	scanf("%s",u.password);
	fwrite(&u,sizeof(struct user),1,fp);
	fclose(fp);
	if(fwrite!=NULL){
		printf("\t\t\t\t\t\t\t\tFile successfully written \n");
		printf("\t\t\t\t\t\t\t\tPress any key to continue... \n");
		getch();
		system("cls");
		adminPage();
	}
	else{
			printf("\t\t\t\t\t\t\t\tFailed to write to file!!! \n");
		printf("\t\t\t\t\t\t\t\tPress any key to continue... \n");
		getch();
		system("cls");
		adminPage();
	}
	
}
	
}
void editCost(){
	FILE *fp;
	FILE *fp1;
	char foodName[20];
	struct menu m;
	fp1=fopen("temp.txt","w");
	fp=fopen("FoodMenu.txt","r");
	if(fp==NULL){
		printf("\t\t\t\t\t\t\t\tFile can not be opened \n");
		printf("\t\t\t\t\t\t\t\tPress any key to continue@ \n");
		getch();
		system("cls");
		staffPage();
	}
	else{
		printf("\t\t\t\t\t\t\t\tEnter food name to edit\n");
		scanf("%s",foodName);
		
		while(fread(&m,sizeof(struct menu),1,fp)){
		if(strcmp(foodName,m.itemName)!=0){
			fwrite(&m,sizeof(struct menu),1,fp1);
		}
		else{
		printf("\t\t\t\t\t\t\t\tEnter Prize of the %s Item\n",foodName);
		scanf("%d",&m.rate);
		fwrite(&m,sizeof(struct menu),1,fp1);
		}
		}
		fclose(fp);
		fclose(fp1);
		fp1=fopen("temp.txt","r");
	fp=fopen("FoodMenu.txt","w");
	while(fread(&m,sizeof(struct menu),1,fp1)){
			fwrite(&m,sizeof(struct menu),1,fp);
		}
		fclose(fp);
		fclose(fp1);
		
	}
}
void FirstScreen(){
	
	system("cls");
	printf("\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\n\n*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\n\n\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\n\n*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\n\n\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\n\n*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\n\n\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\n\n*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\n\n\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\n\n*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\n\n");
	printf("\t\t\t\t\t\t\t\tNPP Burger House \n");
	printf("\t\t\t\t\t\t\t\tPrepered By: \n");
	printf("\t\t\t\t\t\t\t\tSajal and Sudha \n");
	printf("\t\t\t\t\t\t\t\tPrepered For: \n");
	printf("\t\t\t\t\t\t\t\tCitizen COllege KumariPati Lalitpur(PU) \n");
	printf("\t\t\t\t\t\t\t\tInstructed By: \n");
	printf("\t\t\t\t\t\t\t\tEr. Hem Raj Bhattarai \n");
	printf("\t\t\t\t\t\t\t\tPress any key to continue.... \n");
	printf("*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\n\n\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\n\n*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\n\n\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\n\n*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\n\n\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\n\n*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\n\n\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\n\n*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\t*\n\n\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*\t\t*");
	getch();
	
	system("cls");
}

bool isDuplicateItem(char item[30]){
	bool result=false;
	FILE *fp;
	menu m;
	fp=fopen("FoodMenu.txt","r");
	if(fp==NULL){
		printf("\t\t\t\t\t\t\t\tCan not be opened file in getNewId \n");
	}
	else{
		//printf("\t\t\t\t\t\t\t\tFile opened in isDuplicateItem \n");
		//getch();
		while(fread(&m,sizeof(struct menu),1,fp)){
		if(strcmp(m.itemName,item)==0){
			result=true;
		}
		}
		fclose(fp);
		
	}
	fclose(fp);
	return result;
}
void readMenu(){
	FILE *fp;
	struct menu m;
	fp=fopen("FoodMenu.txt","a");
	if(fp==NULL){
		printf("\t\t\t\t\t\t\t\tFile can not be opened \n");
		printf("\t\t\t\t\t\t\t\tPress any key to continue@ \n");
		fclose(fp);
	}
	else{
		m.id=getNewId();
		printf("\t\t\t\t\t\t\t\tEnter Item Name: \n");
		scanf("%s",m.itemName);
		printf("\t\t\t\t\t\t\t\tEnter Item Price: \n");
		scanf("%d",&m.rate);
		if(isDuplicateItem(m.itemName)){
			printf("\t\t\t\t\t\t\t\tThis item is already in the file\n\n");
			printf("\t\t\t\t\t\t\t\tEnter a new item or edit the cost\n\n");
			fclose(fp);
			printf("\t\t\t\t\t\t\t\tPress any key to continue@ \n");
		getch();
		system("cls");
		fclose(fp);
		adminPage();
		}
		else{
		fwrite(&m,sizeof(struct menu),1,fp);
		printf("\t\t\t\t\t\t\t\tItem successfully added\n");
		fclose(fp);
		printf("\t\t\t\t\t\t\t\tPress any key to continue@ \n");
		getch();
		system("cls");
}

}
fclose(fp);
}
void showMenu(){
	FILE *fp;
	struct menu m;
	fp=fopen("FoodMenu.txt","r");
	if(fp==NULL){
		printf("\t\t\t\t\t\t\t\tFile can not be opened \n");
		printf("\t\t\t\t\t\t\t\tPress any key to continue@ \n");
		fclose(fp);
	}
	else{
		printf("\t\t\t\t\t\t\t\tId:  %s\t\tPrize(Rs.)\n","Item Name:");
		while(fread(&m,sizeof(struct menu),1,fp)){
			printf("\t\t\t\t\t\t\t\t%d   %s\t\t%d\n",m.id,m.itemName,m.rate);
		}
		fclose(fp);
	}
}

int getNewId(){
	int countId=1;
	FILE *fp;
	menu m;
	fp=fopen("FoodMenu.txt","r");
	if(fp==NULL){
		printf("\t\t\t\t\t\t\t\tCan not be opened file in getNewId \n");
	}
	else{
		while(fread(&m,sizeof(struct menu),1,fp)){
		countId++;	
		}
			fclose(fp);
	}
	fclose(fp);
	return countId;
}