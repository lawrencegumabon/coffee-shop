#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void login_user();
void login_admin();
void register_user();
void forgotUser();
void forgotPass();
void loggedAdmin();
void loggedUser();
void adminOption();
void add();
void view();
void search();
void regUser();
void logout();
void exit();

//Declaration for Login and Register
int response, count = 5, userCount;
char username[16], password[16], email[16];
char firstName[16], lastName[16], cpNumber[11], number[11], num[11];
char usernames[10][16] = {"user1","user2", "user3", "user4", "user5"};
char passwords[10][16] = {"pass1", "pass2", "pass3", "user4", "pass5"};
char numbers[10][12] = {"1123", "2123", "3123", "4123", "5123"};
char emails[10][16] = {"user1@gmail.com", "user2@gmail.com", "user3@gmail.com", "user4@gmail.com", "user5@gmail.com"};
int status[10] = {1,0,0,0,0,};
int money[10] = {100, 200, 300, 400, 500};

//For Admin Login
int pin;
int pins = 0001;

int acct;

//Declaration for Logged in User and Admin
//Menu
char flavors[10][30] = {"Brewed", "Americano", "Cappuccino", "CafeLatte", "CafeMocha"};
char foodList[10][30] = {"Cheesecake", "BBerryCake", "Pretzel", "ChocoCake", "Waffle"};
//Price List
int flavorPrice[10] = {95, 110, 120, 120, 135};
int foodPrice[10] = {100, 120, 120, 130, 130};
//Stocks
int foodStocks[10] = {10,10,10,0,10};
int addFoodStock[10] = {0,0,0,0,0};
//Count
int flavorCount = 5, foodCount = 5, cPriceCount = 5, fPriceCount = 5;
int fStockCount = 5;

//For cup sizes
int sizeCount = 3;
char sizes[3][10] = {"Small", "Medium", "Large"};
int sizeStocks[3] = {10,10,10};
int addSizeStock[3] = {0,0,0};

//For Promo
int coffeePromo = 5;
int points[5] = {0,0,0,0,0};
//int pointsLeft[5] = {0,0,0,0,0};

//Search Coffee flavor and Food
char searchFlavor[20], searchFood[20];
char userSearch[20];

void main(){
clrscr();
	cout<<"=================================="<<endl;
	cout<<"========= WELCOME IN OUR ========="<<endl;
	cout<<"=========== Coffee Shop =========="<<endl;
	cout<<"=================================="<<endl;
	cout<<"What do you want to do? "<<endl;
	cout<<"1. Login "<<endl;
	cout<<"2. Register"<<endl;
	cout<<"3. Exit"<<endl;
	cout<<"----------------------------------"<<endl;
	cout<<"Option: ";
	cin>>response;

	if(response == 1){
	clrscr();
		cout<<"=================================\n";
		cout<<"=========== Login as:============\n";
		cout<<"=================================\n";
		cout<<"1. User "<<endl;
		cout<<"2. Admin"<<endl;
		cout<<"---------------------------------"<<endl;
		cout<<"Option: ";
		cin>>response;
		if(response == 1){
			login_user();
		}else if(response == 2){
			login_admin();
		}
	}else if(response == 2){
	clrscr();
		register_user();
	}else{
		cout<<"=================================="<<endl;
		cout<<"      Press any key to exit!"<<endl;
		cout<<"=================================="<<endl;
		exit();
	}
}

void login_user(){
	relogin:
	clrscr();
	cout<<"=============================== \n";
	cout<<"======== LOGIN (USER): ======== \n";
	cout<<"=============================== \n\n";
	cout<<"Username: ";
	cin>>username;
	cout<<"Password: ";
	cin>>password;
	for(int i = 0; i < count; i++){
		if((strcmp(username, usernames[i])==0 && strcmp(password, passwords[i])==0)){
			acct = i;
			if(status[acct] == 1){
				cout<<"\n===============================";
				cout<<"\n=== This account is banned! ===\n";
				cout<<"====== Use other account ======";
				cout<<"\n===============================";
				getch();
				goto relogin;
			}

			cout<<"\n==============================="<<endl;
			cout<<"====== Login Successful! ======"<<endl;
			cout<<"==============================="<<endl;
			cout<<"\n   Press any key to continue"<<endl;

			cout<<"==============================="<<endl;
			getch();
			loggedUser();
		}

		if(i == count - 1){
			clrscr();
			cout<<"\nAccount not found"<<endl;
			cout<<"===================="<<endl;
			cout<<"1. Re-login"<<endl;
			cout<<"2. Register"<<endl;
			cout<<"3. Forgot Username"<<endl;
			cout<<"4. Forgot Password"<<endl;
			cout<<"===================="<<endl;
			cout<<"Option: ";
			cin>>response;
			if(response == 1){
				login_user();
			}else if(response == 2){
				register_user();
			}else if(response == 3){
				forgotUser();
			}else if(response == 4){
				forgotPass();
			}else{
				exit();
			}
		}
	}
}

void login_admin(){
	clrscr();
	cout<<"=========================="<<endl;
	cout<<"===== LOGIN (ADMIN): ====="<<endl;
	cout<<"=========================="<<endl;
	cout<<"Enter pin: ";
	cin>>pin;
	if(pin == pins){
		cout<<"=== Login Succesfully! ===";
		loggedAdmin();
	}
	else{
		cout<<"\nIncorrect Pin\n";
		cout<<"= Directing to home page =";
		getch();
		main();
	}
	getch();
}

void register_user(){
clrscr();
	cout<<"============================="<<endl;
	cout<<"===== USER REGISTRATION ====="<<endl;
	cout<<"=============================\n"<<endl;
	cout<<"Enter first name: ";
	cin>>firstName;
	cout<<"Enter last name : ";
	cin>>lastName;
	cout<<"Enter email     : ";
	cin>>emails[count];
	cout<<"Enter number    : ";
	cin>>numbers[count];
	cout<<"Enter username  : ";
	cin>>usernames[count];
	cout<<"Enter password  : ";
	cin>>passwords[count];
	status[count++] = 0;
	cout<<"\n============================"<<endl;
	cout<<"Account Created Successfully"<<endl;
	cout<<"============================"<<endl;
	cout<<" Press any key to continue!"<<endl;
	cout<<"============================"<<endl;
	getch();
	login_user();
}

void forgotUser(){
	clrscr();
	cout<<"=============================================="<<endl;
	cout<<"Enter your email to confirm: ";
	cin>>email;
	cout<<"=============================================="<<endl;
	for(int i = 0; i < count; i++){
		if(strcmp(email, emails[i]) == 0){
			cout<<"Enter your new username: ";
			cin>>usernames[i];
			cout<<"----------------------------------------------"<<endl;
			cout<<"Your new username is: "<<usernames[i];
		}
	}
	cout<<"\n=============================================="<<endl;
	getch();
	login_user();
}


void forgotPass(){
	clrscr();
	cout<<"=============================================="<<endl;
	cout<<"Enter your email to confirm: ";
	cin>>email;
	cout<<"=============================================="<<endl;
	for(int i = 0; i < count; i++){
		if(strcmp(email, emails[i]) == 0){
			cout<<"Enter your new password: ";
			cin>>passwords[i];
			cout<<"----------------------------------------------"<<endl;
			cout<<"Your new password is: "<<passwords[i];
		}
	}
	cout<<"\ny=============================================="<<endl;
	getch();
	login_user();
}

void loggedUser(){
homePage:
clrscr();
	int coffeePrice=0, price=0, totalPrice=0, coffeeQty=0, foodQty=0, food_Price=0;

	//Temporary Storage of Price
	int tempoCPrice=0, tempoFPrice=0, tempoQty=0;

	//Total Price
	int totalCoffeePrice=0, totalFoodPrice=0;
	int quantity=0;

	int balanceLeft;

	int cash=0;

	cout<<"=========================="<<endl;
	cout<<"===== USER HOME PAGE ====="<<endl;
	cout<<"=========================="<<endl;
	cout<<"1. Order"<<endl;
	cout<<"2. Redeem Rewards"<<endl;
	cout<<"3. Account"<<endl;
	cout<<"4. Logout"<<endl;
	cout<<"--------------------------"<<endl;
	cout<<"Option: ";
	cin>>response;
	if(response == 1){
		coffeeMenu:
		clrscr();
		cout<<"==========================="<<endl;
		cout<<"======= COFFEE MENU ======="<<endl;
		cout<<"==========================="<<endl;
		for(int i = 0; i < flavorCount; i++){
			cout<<"["<<i+1<<"] "<<flavors[i];
			cout<<"\t\t"<<flavorPrice[i]<<endl;
		}
		cout<<"---------------------------"<<endl;
		cout<<"Choose flavor: ";
		cin>>response;

		coffeePrice = flavorPrice[response-1];
		sizing:
		//clrscr();
		cout<<"==========================="<<endl;
		cout<<"========== SIZE: =========="<<endl;
		cout<<"==========================="<<endl;
		cout<<"                   Stock"<<endl;
		cout<<"---------------------------"<<endl;
		for(int j = 0; j < sizeCount; j++){
			cout<<"["<<j+1<<"] "<<sizes[j]<<"\t    "<<sizeStocks[j]<<endl;
		}
		cout<<"==========================="<<endl;
		cout<<"Option: ";
		cin>>response;
		cout<<"==========================="<<endl;

		if(response == 1) price = coffeePrice * 1;
		else if(response == 2) price = coffeePrice * 1.25;
		else if(response == 3) price = coffeePrice * 1.5;
		else{
			cout<<"====== Invalid size! ======"<<endl;
			cout<<"==== Choose valid size ===="<<endl;
			cout<<"==========================="<<endl;
			getch();
			goto sizing;
		}

		if(sizeStocks[response - 1] == 0){
			cout<<"        Out of stock"<<endl;
			cout<<"     Choose other size"<<endl;
			cout<<"  Press any key to reorder!"<<endl;
			cout<<"==========================="<<endl;
			getch();
			goto sizing;
		}
		cout<<"How many? ";
		cin>>coffeeQty;
		sizeStocks[response - 1] -= coffeeQty;

		tempoCPrice = price * coffeeQty;
		totalCoffeePrice += tempoCPrice;

		tempoQty = coffeeQty;
		quantity += tempoQty;

		cout<<"\nOrder again? Yes[1] or No[2]: ";
		cin>>response;
		if(response == 1) goto coffeeMenu;

		clrscr();
		cout<<"----------------------------------"<<endl;
		cout<<"Order some food? Yes[1] or No[2]: ";
		cin>>response;
		cout<<"----------------------------------"<<endl;
		if(response == 1){
			foods:
			clrscr();
			cout<<"==========================="<<endl;
			cout<<"======== FOOD MENU ========"<<endl;
			cout<<"==========================="<<endl;
			cout<<"               Price  Stock"<<endl;
			cout<<"---------------------------"<<endl;
			for(int j = 0; j < foodCount; j++){
				cout<<"["<<j+1<<"] "<<foodList[j]<<"\t"<<foodPrice[j]<<"\t"<<foodStocks[j]<<endl;
			}
			cout<<"---------------------------"<<endl;
			cout<<"Choose your food: ";
			cin>>response;
			cout<<"---------------------------"<<endl;

			if(foodStocks[response - 1] == 0){
				cout<<"This food is out of stock!"<<endl;
				cout<<"Press any key to order again!"<<endl;
				getch();
				goto foods;
			}
			food_Price = foodPrice[response-1];

			cout<<"How many? ";
			cin>>foodQty;
			cout<<"----------------------------"<<endl;

			foodStocks[response-1] -= foodQty;

			tempoFPrice = food_Price * foodQty;
			totalFoodPrice += tempoFPrice;

			cout<<"Order again? Yes[1] or No[2]: ";
			cin>>response;
			if(response == 1) goto foods;
		}

		totalPrice = totalCoffeePrice + totalFoodPrice;
		clrscr();
		cout<<"========================================="<<endl;
		cout<<"================ RECEIPT ================"<<endl;
		cout<<"========================================="<<endl;

		cout<<"Total bill for Coffee: "<<totalCoffeePrice<<endl;
		cout<<"Total bill for Food: "<<totalFoodPrice<<endl;
		cout<<"-----------------------------------------"<<endl;
		cout<<"Total bill: "<<totalPrice;
		cout<<"\n========================================="<<endl;

		funds:
		cout<<endl;
		if(money[acct] >= totalPrice){
			cout<<"Pay the bill? Yes[1] or No[2]: ";
			cin>>response;
			if(response == 1){
				cout<<"\n========================================="<<endl;
				cout<<"Your total bill is: "<<totalPrice<<endl;
				money[acct] -= totalPrice;
				cout<<"\nYou paid "<<totalPrice<<", You have "<<money[acct]<<" in your account.\n";
				cout<<"You got "<<quantity<<" points for purchasing "<<quantity<<" coffee."<<endl;
				cout<<"The points will be added in your account\n";
				points[acct] += quantity;
				cout<<"\n          Thank you come again!"<<endl;
				cout<<"========================================="<<endl;
				cout<<"Go to Main Menu [1] or Exit [2]: ";
				cin>>response;
				cout<<"========================================="<<endl;
				cout<<"------ Press any key to continue! -------"<<endl;
				getch();
				if(response == 1) goto homePage;
				else exit();
			}else{
				cout<<"\nPress any key to continue"<<endl;
				getch();
				exit();
			}

		}else{
			cout<<"       Your balance is not enough!\n";
			cout<<"\nAdd funds? Yes [1] or No [2]: ";
			cin>>response;
			cout<<"-----------------------------------------"<<endl;
			if(response == 1){
				numberInput:
				cout<<"Enter your cellphone number: ";
				cin>>num;
				cout<<"-----------------------------------------"<<endl;
				if(strcmp(num, numbers[acct])==0){
					cout<<"             Number VERIFIED"<<endl;
					cout<<"-----------------------------------------"<<endl;
					cout<<"Add funds to your money: ";
					cin>>cash;
					cout<<"========================================="<<endl;
					money[acct] += cash;
					getch();
					goto funds;
				}
				else{
					cout<<"        Number is not registered!"<<endl;
					cout<<"========================================="<<endl;
					getch();
					goto numberInput;
				}
			}else{
				cout<<"========================================="<<endl;
				cout<<"          Press any key to exit"<<endl;
				cout<<"========================================="<<endl;
				exit();
			}
		}
	}
	if(response == 2){
		clrscr();
		cout<<"======================================"<<endl;
		cout<<"=========== REDEEM REWARDS ==========="<<endl;
		cout<<"======================================"<<endl;
		cout<<"1. Check Points"<<endl;
		cout<<"2. Get Free Coffee"<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<"Option: ";
		cin>>response;
		if(response == 1){
			clrscr();
			cout<<"======================================"<<endl;
			cout<<"You have "<<points[acct]<<" points in your account\n";
			cout<<"Use your points? Yes[1] or No[2]: ";
			cin>>response;
			cout<<"======================================"<<endl;
			if(response == 1){

			}else{
				cout<<"====== Press any key to go back ======"<<endl;
				cout<<"======================================"<<endl;
				getch();
				goto homePage;
			}

		}
		//2. Get free coffee
		if(points[acct] >= coffeePromo){
			clrscr();
			cout<<"======================================"<<endl;
			cout<<"============ COFFEE MENU: ============"<<endl;
			cout<<"======================================"<<endl;
			cout<<"      * Get Free LARGE Coffee! *"<<endl;
			cout<<"--------------------------------------"<<endl;
			for(int i = 0; i < flavorCount; i++){
				cout<<"["<<i+1<<"] "<<flavors[i]<<endl;
			}
			cout<<"======================================"<<endl;
			cout<<"Choose flavor: ";
			cin>>response;
			points[acct] -= coffeePromo;
			cout<<"======================================"<<endl;
			cout<<"You get free Large "<<flavors[response-1]<<endl;
			cout<<"You only have "<<points[acct]<<" points in your account."<<endl;
			cout<<"======================================"<<endl;
			cout<<"         Thank you come again!"<<endl;
			cout<<"======================================"<<endl;
			cout<<"       Press any key to go back"<<endl;
			cout<<"======================================"<<endl;
			getch();
			goto homePage;
		}else{
			cout<<"======================================"<<endl;
			cout<<"      Your points is not enough!"<<endl;
			cout<<"       Press any key to go back"<<endl;
			cout<<"======================================"<<endl;
			getch();
			goto homePage;
		}


	}
	//Account Settings
	if(response == 3){
	accountSettings:
	clrscr();
		cout<<"============================="<<endl;
		cout<<"======ACCOUNT SETTINGS:======"<<endl;
		cout<<"============================="<<endl;
		cout<<"1. Change Username/Password\n";
		cout<<"2. Balance\n";
		cout<<"3. Go back"<<endl;
		cout<<"-----------------------------"<<endl;
		cout<<"Choose: ";
		cin>>response;
		if(response == 1){
			clrscr();
			cout<<"================================"<<endl;
			cout<<"What do you want to change?"<<endl;
			cout<<"[1] Username"<<endl;
			cout<<"[2] Password"<<endl;
			cout<<"--------------------------------"<<endl;
			cout<<"Option: ";
			cin>>response;

			if(response == 1){
				clrscr();
				cout<<"======================================"<<endl;
				cout<<"Enter your new username: ";
				cin>>usernames[acct];
				cout<<"======================================"<<endl;
				cout<<"    Username Changed Successfully!"<<endl;
				cout<<"--------------------------------------"<<endl;
				cout<<"Your new username is: "<<usernames[acct]<<endl;
				cout<<"======================================"<<endl;
				cout<<"       Press any key to go back"<<endl;
				cout<<"======================================"<<endl;
				getch();
				goto accountSettings;
			}else if(response == 2){
				clrscr();
				cout<<"======================================"<<endl;
				cout<<"Enter your new password: ";
				cin>>passwords[acct];
				cout<<"======================================"<<endl;
				cout<<"    Password Changed Successfully!"<<endl;
				cout<<"--------------------------------------"<<endl;
				cout<<"Your new pass is: "<<passwords[acct]<<endl;
				cout<<"======================================"<<endl;
				cout<<"       Press any key to go back"<<endl;
				getch();
				goto accountSettings;
			}
		}
		if(response == 2){
		clrscr();
			cout<<"========================================="<<endl;
			cout<<"================ BALANCE ================"<<endl;
			cout<<"========================================="<<endl;
			cout<<"[1] Add funds"<<endl;
			cout<<"[2] Balance"<<endl;
			cout<<"-----------------------------------------"<<endl;
			cout<<"Option: ";
			cin>>response;
			if(response == 1){
				numberInput2:
				clrscr();
				cout<<"========================================="<<endl;
				cout<<"Enter your cellphone number: ";
				cin>>num;
				cout<<"========================================="<<endl;
				if(strcmp(num, numbers[acct])==0){
					cout<<"             Number VERIFIED"<<endl;
					cout<<"-----------------------------------------"<<endl;
					cout<<"Add funds to your money: ";
					cin>>cash;
					money[acct] += cash;
					cout<<"-----------------------------------------"<<endl;
					cout<<"Your new balance is: "<<money[acct];
					cout<<"\n========================================="<<endl;
					cout<<"        Press any key to go back!"<<endl;
					cout<<"========================================="<<endl;
				}
				else{
					cout<<"        Number is not REGISTERED!"<<endl;
					cout<<"-----------------------------------------"<<endl;
					getch();
					goto numberInput2;
				}
			}else{
				cout<<"========================================="<<endl;
				cout<<"Your balance is: "<<money[acct]<<endl;
				cout<<"========================================="<<endl;
				cout<<"        Press any key to go back!"<<endl;
				cout<<"========================================="<<endl;
			}
			getch();
			goto homePage;
		}else{
			cout<<"============================="<<endl;
			cout<<"  Press any key to go back!"<<endl;
			cout<<"============================="<<endl;
			getch();
			goto homePage;
		}

	}
	if(response == 4){
		getch();
		logout();
	}
getch();
}

void loggedAdmin(){
adminSettings:
clrscr();
	cout<<"=========================="<<endl;
	cout<<"===== ADMIN SETTINGS ====="<<endl;
	cout<<"=========================="<<endl;
	cout<<"1. Menu"<<endl;
	cout<<"2. Account"<<endl;
	cout<<"3. Logout"<<endl;
	cout<<"--------------------------"<<endl;
	cout<<"Option: ";
	cin>>response;
	if(response == 1){
		adminOption();
	}else if(response == 2){
		accountOption:
		clrscr();
		cout<<"=================================="<<endl;
		cout<<"======= ACCOUNT OPTION (ADMIN) ===\n";
		cout<<"=================================="<<endl;
		cout<<"1. View Registered Accounts\n";
		cout<<"2. Search Account\n";
		cout<<"3. List of Active/Banned Accounts\n";
		cout<<"4. Go back to Admin Settings\n";
		cout<<"----------------------------------"<<endl;
		cout<<"Option: ";
		cin>>response;
		if(response == 1){
			regUser();
			goto accountOption;
		}
		else if(response == 2){
			clrscr();
			cout<<"=================================="<<endl;
			cout<<"         Search Account: "<<endl;
			cout<<"=================================="<<endl;
			cout<<"Enter a username: ";
			cin>>userSearch;
			cout<<"----------------------------------"<<endl;
			for(int i = 0; i < count; i++){
				if(strcmp(userSearch, usernames[i])==0){
					if(status[i] == 0){
						cout<<userSearch<<" is found!"<<endl;
						break;
					}else{
						cout<<userSearch<<" is banned!"<<endl;
						break;
					}

				}
				if(i == count - 1){
					cout<<userSearch<<" is not found!\n";
				}
			}
			cout<<"=================================="<<endl;
			getch();
			goto accountOption;
		}
		else if(response == 3){
			clrscr();
			cout<<"=================================="<<endl;
			cout<<"        Ban/Unban Account: "<<endl;
			cout<<"=================================="<<endl;
			cout<<"[1] Ban Account/s\n";
			cout<<"[2] Unban Account/s\n";
			cout<<"----------------------------------"<<endl;
			cout<<"Option: ";
			cin>>response;
			if(response == 1){
				clrscr();
				cout<<"=================================="<<endl;
				cout<<"      List of Active User/s: "<<endl;
				cout<<"=================================="<<endl;
				cout<<"   User\t\t\t"<<"Status\t"<<endl;
				for(int i = 0; i < count; i++){
					cout<<"["<<i+1<<"] "<<usernames[i]<<"\t";
					if(status[i] == 0){
					cout<<"\tActive"<<endl;
					}
					else cout<<"\tBanned"<<endl;
				}
				cout<<"----------------------------------"<<endl;
				cout<<"Choose Username: ";
				cin>>userCount;
				cout<<"----------------------------------"<<endl;
				cout<<"User: "<<usernames[userCount - 1]<<" is now banned!\n";
				status[userCount - 1] = 1;
				cout<<"=================================="<<endl;
				cout<<"     Press any key to go back"<<endl;
				cout<<"=================================="<<endl;
				getch();
				goto accountOption;
			}

			if(response == 2){
				clrscr();
				cout<<"=================================="<<endl;
				cout<<"     List of banned account/s"<<endl;
				cout<<"=================================="<<endl;
				for(int i = 0; i < count; i++){
					if(status[i] == 1){
						cout<<"["<<i<<"] "<<usernames[i]<<endl;
					}
				}
				cout<<"=================================="<<endl;
				cout<<"Unban: ";
				cin>>userCount;
				cout<<"----------------------------------"<<endl;
				cout<<"User: "<<usernames[userCount]<<" is now unbanned!"<<endl;
				status[userCount] = 0;
				cout<<"=================================="<<endl;
				cout<<"     Press any key to go back"<<endl;
				cout<<"=================================="<<endl;
				getch();
				goto accountOption;
			}
		}
		else if(response == 4){
			goto adminSettings;
		}
	}else{
		logout();
	}
getch();
}

void adminOption(){
	adminOpt:
	clrscr();
	cout<<"=================================="<<endl;
	cout<<"========== ADMIN OPTION =========="<<endl;
	cout<<"=================================="<<endl;
	cout<<"1. Add"<<endl;
	cout<<"2. View"<<endl;
	cout<<"3. Search"<<endl;
	cout<<"4. Go back to Admin Settings"<<endl;
	cout<<"----------------------------------"<<endl;
	cout<<"Option: ";
	cin>>response;
	switch (response){
		case 1:
			add();
			break;
		case 2:
			view();
			break;
		case 3:
			search();
			break;
		case 4:
			loggedAdmin();
			break;
		default:
			cout<<"=================================="<<endl;
			cout<<"          Invalid Choice"<<endl;
			cout<<"----------------------------------"<<endl;
			cout<<"     Press any key to go back"<<endl;
			cout<<"=================================="<<endl;
			getch();
			goto adminOpt;
	}
getch();
}

void add(){
	clrscr();
	cout<<"=============================="<<endl;
	cout<<"=========  ADD ITEMS ========="<<endl;
	cout<<"=============================="<<endl;
	cout<<"[1] Coffee\n";
	cout<<"[2] Food\n";
	cout<<"[3] Stocks\n";
	cout<<"------------------------------"<<endl;
	cout<<"Option: ";
	cin>>response;
	if(response == 1){
		cout<<"=============================="<<endl;
		cout<<"Add Coffee: ";
		cin>>flavors[flavorCount];
		flavorCount++;
		cout<<"Add Price : ";
		cin>>flavorPrice[cPriceCount];
		cPriceCount++;
	}
	else if(response == 2){
		cout<<"=============================="<<endl;
		cout<<"Add Food  : ";
		cin>>foodList[foodCount];
		foodCount++;
		cout<<"Add Price : ";
		cin>>foodPrice[fPriceCount];
		fPriceCount++;
		cout<<"Add Stock : ";
		cin>>foodStocks[fStockCount];
		fStockCount++;
	}else if(response == 3){
		cout<<"=============================="<<endl;
		cout<<"[1] Add coffee size cup stock"<<endl;
		cout<<"[2] Add food stock"<<endl;
		cout<<"------------------------------"<<endl;
		cout<<"Option: ";
		cin>>response;
		if(response == 1){
			sStock:
			clrscr();
			cout<<"=============================="<<endl;
			cout<<"Choose size: "<<endl;
			cout<<"[1] Small"<<endl;
			cout<<"[2] Medium"<<endl;
			cout<<"[3] Large"<<endl;
			cout<<"------------------------------"<<endl;
			cout<<"Option: ";
			cin>>response;
			cout<<"------------------------------"<<endl;
			if((response < 1) || (response > 3)){
				cout<<"Invalid Size"<<endl;
				cout<<"Choose other size"<<endl;
				cout<<"Press any key to continue"<<endl;
				getch();
				goto sStock;
			}
			cout<<"Add stock: ";
			cin>>addSizeStock[response - 1];
			sizeStocks[response - 1] += addSizeStock[response - 1];
		}else if(response == 2){
			fStock:
			clrscr();
			cout<<"=============================="<<endl;
			cout<<"         Food/s List:"<<endl;
			cout<<"=============================="<<endl;
			for(int i = 0; i < foodCount; i++){
				cout<<"["<<i+1<<"] "<<foodList[i]<<endl;
			}
			cout<<"------------------------------"<<endl;
			cout<<"Option: ";
			cin>>response;
			cout<<"------------------------------"<<endl;
			cout<<"Add Stock: ";
			cin>>addFoodStock[response - 1];
			foodStocks[response - 1] += addFoodStock[response - 1];
		}
	}
	cout<<"=============================="<<endl;
	cout<<"   Press any key to go back"<<endl;
	cout<<"=============================="<<endl;
	getch();
	adminOption();
}

void view(){
	clrscr();
	cout<<"================================"<<endl;
	cout<<"========= VIEW ITEMS ==========="<<endl;
	cout<<"================================"<<endl;
	cout<<"[1] Coffee"<<endl;
	cout<<"[2] Food"<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<"Option: ";
	cin>>response;
	cout<<"================================"<<endl;
	if(response == 1){
		cout<<"COFFEE LIST:\t\tPRICE: \n";
		cout<<"--------------------------------\n";
		for(int i = 0; i < flavorCount; i++){
			cout<<"["<<i + 1<<"] "<<flavors[i]<<"\t\t";
			cout<<flavorPrice[i]<<endl;
		}
		cout<<"================================\n";
		cout<<"SIZES:\t\t\tSTOCKS: \n";
		cout<<"--------------------------------\n";
		for(int j = 0; j < sizeCount; j++){
			cout<<"["<<j+1<<"] "<<sizes[j]<<"\t\t"<<sizeStocks[j]<<endl;
		}
	}else if(response == 2){
		cout<<"FOOD LIST:\t  PRICE:  STOCK:\n";
		cout<<"================================\n";
		for(int x = 0; x < foodCount; x++){
			cout<<"["<<x + 1<<"] "<<foodList[x]<<"\t   ";
			cout<<foodPrice[x];
			cout<<"\t    "<<foodStocks[x]<<endl;
		}
	}
	cout<<"================================\n";
	cout<<"    Press any key to go back"<<endl;
	cout<<"================================"<<endl;
	getch();
	adminOption();
}

void search(){
	clrscr();
	cout<<"=================================="<<endl;
	cout<<"============ SEARCH: ============="<<endl;
	cout<<"=================================="<<endl;
	cout<<"Search for?\n[1] Coffee \n[2] Food"<<endl;
	cout<<"----------------------------------"<<endl;
	cout<<"Option: ";
	cin>>response;
	if(response == 1){
		cout<<"=================================="<<endl;
		cout<<"Enter coffee flavor: ";
		cin>>searchFlavor;
		cout<<"=================================="<<endl;
		for(int i = 0; i < flavorCount; i++){
			if(strcmp(searchFlavor, flavors[i])==0){
				cout<<"["<<i<<"] "<<searchFlavor<<" is available!\n";
				break;
			}
			if(i == flavorCount - 1){
				cout<<searchFlavor<<" is not found!\n";
			}
		}
	}else if(response == 2){
		cout<<"=================================="<<endl;
		cout<<"Enter food: ";
		cin>>searchFood;
		cout<<"=================================="<<endl;
		for(int i = 0; i < foodCount; i++){
			if(strcmp(searchFood, foodList[i])==0){
				if(foodStocks[i] == 0){
					cout<<"["<<i<<"] "<<searchFood<<" is out of stock!"<<endl;
					break;
				}
				cout<<"["<<i<<"] "<<searchFood<<" is available!\n";
				break;
			}
			if(i == foodCount - 1){
				cout<<searchFood<<" is not found!\n";
			}
		}
	}
	cout<<"=================================="<<endl;
	cout<<"     Press any key to go back"<<endl;
	cout<<"=================================="<<endl;
	getch();
	adminOption();
}

void regUser(){
	clrscr();
	cout<<"==========================================================="<<endl;
	cout<<"                    Registered User/s: "<<endl;
	cout<<"==========================================================="<<endl;
	cout<<"   User\t\t"<<"Status\t"<<"Balance\t"<<"Contact No.\t"<<"Email\t"<<endl;
	for(int i = 0; i < count; i++){
		cout<<"["<<i+1<<"] "<<usernames[i]<<"\t";
		if(status[i] == 0){
			cout<<"Active\t  "<<money[i]<<"\t   "<<numbers[i]<<"\t    "<<emails[i]<<endl;
		}
		else cout<<"Banned\t  "<<money[i]<<"\t   "<<numbers[i]<<"\t    "<<emails[i]<<endl;
	}
	cout<<"==========================================================="<<endl;
	cout<<"                Press any key to continue!"<<endl;
	cout<<"==========================================================="<<endl;
	getch();
}

void logout(){
	cout<<"=========================="<<endl;
	cout<<"Press any key to continue!"<<endl;
	cout<<"=========================="<<endl;
	getch();
	main();
}

void exit(){
	getch();
	exit(0);
}