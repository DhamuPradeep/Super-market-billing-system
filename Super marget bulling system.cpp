#include <iostream>
#include <fstream>
using namespace std;

class shopping{
	private:
		int pcode;
		float price,dis;
		string pname;
		
	public:
		void menu();
		void admin();
		void buyer();
		void add();
		void edit();
		void rem();
		void list();
		void receipt();
};

void shopping :: menu(){
	
	start:
	int choice;
	string email;
	string password;
	
	
	cout << "\t\t\t\t -------------------------------------------------------------\n";
	cout << "\t\t\t\t                                                              \n";
	cout << "\t\t\t\t                SuperMarket Bulling System                    \n";
	cout << "\t\t\t\t                                                              \n";
	cout << "\t\t\t\t -------------------------------------------------------------\n";
	cout << "\t\t\t\t 															   \n";
	cout << "\t\t\t\t    | 1) Admin      |\t";
	cout << "\t\t\t\t 															   \n";
	cout << "\t\t\t\t    | 2) Buyer      |\t";
	cout << "\t\t\t\t 															   \n";
	cout << "\t\t\t\t    | 3) Exit      |\t";
	cout << "\t\t\t\t 															   \n";
	cout << "\t\t\t\t Enter Your Choice ";
	cin >> choice;
	
	
	switch(choice){
		case 1:
			cout << "\n\t\t\t\t Please Login \n";
			cout << "\t\t\t\t Enter Your Admin mail ID : ";
			cin >> email;
			cout << "\t\t\t\t Enter Password  :  ";
			cin >> password;
			cout << "\t\t\t\t 															   \n";
			if(email == "dhamupradeep2610@gmail.com" && password == "17102002"){
				admin();
			}else{
				cout << "\t\t\t\tInvalid Email ID or Password" << "\n\n\n";
			}
			break;
		case 2:
			buyer();
			break;
		case 3:
			exit(0);
			break;
		default:
			cout << "\t\t\t\t           Please enter a Valid Choice                \n";
	}
	goto start;
}


void shopping :: admin(){
	start:
	int choice;
	cout << "\n\n\n\t  Admin Optons   \n";
	cout << "\n\t\t\t\t                \n";
	cout << "\n\t\t  1) Add Products    \n";
	cout << "\n\t\t\t\t                \n";
	cout << "\n\t\t  2) Modify Products    \n";
	cout << "\n\t\t\t\t                \n";
	cout << "\n\t\t  3) Remove Products    \n";
	cout << "\n\t\t\t\t                \n";
	cout << "\n\t\t  4) Back to Main Menu   \n";
	cout << "\n\t\t\t\t                \n";
	cout << "\n\t Enter the choice : ";
	cin >> choice;
	cout << "\n\n";
	switch(choice){
		case 1:
			add();
			break;
		case 2:
			edit();
			break;
		case 3:
			rem();
			break;
		case 4:
			menu();
			break;
		default:
			cout << "\n\t\t Enter a Valid Choice  ";
	}
	goto start;
}


void shopping :: buyer(){
	
	start:
	int choice;
	cout << "\n\n\t\t     Buyer     \n";
	cout << "\t\t\t\t                \n";
	cout << "\t\t    1) Buy Products    \n";
	cout << "\t\t\t\t                \n";
	cout << "\t\t    2) Back To Main Menu    \n";
	cout << "\t\t\t\t                \n";
	cout << "\t Enter your Choice :  ";
	cin >> choice;
	
	
	switch(choice){
		
		case 1:
			receipt();
			break;
		case 2:
			menu();
			break;
			
		default:
			cout << "\t\t  Enter a Valid Choice \n" ;
		
	}
	
	goto start;
}


void shopping :: add(){
	start:
	fstream data;
	int c,token = 0;
	float p,d;
	string n;
	
	
	cout << "\n\n\t\t\t Add new Products \n";
	cout << "\n\n\t\t Enter the product code : ";
	cin >> pcode;
	cout << "\n\n\t\t Enter the Name of the Product : ";
	cin >> pname;
	cout << "\n\n\t\t Enter the Price of the Product : ";
	cin >> price;
	cout << "\n\n\t\t Enter the Discount on Product : ";
	cin >> dis;
	cout << "\n\n";
	
	
	data.open("database.txt",ios::in);
	
	if(!data){
		data.open("database.txt",ios::app | ios::out);
		data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
		data.close();
	}else{
		data >> c >> n >> p >> d;
		while(!data.eof()){
			if(c == pcode)
				token++;
			data >> c >> n >> p >> d;
		}
		data.close();
	
		if(token == 1){
			cout << "\t\t Product code is already Exist \n\n";
			goto start;
		}else{
			data.open("database.txt",ios::app | ios :: out);
			data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
			data.close();
		}
	}
	cout << "\n\n\t\t Product Inserted \n";
}

void shopping :: edit(){
	start:
	fstream data,data1;
	int c,token = 0,pkey;
	float p,d;
	string n;
	cout << "\n\t\t\t Modify the Products\n";
	cout << "\n\n\t\tEnter the product Code : ";
	cin >> pkey;
	
	data.open("database.txt",ios::in);
	
	if(!data){
		cout << "\n\t\t\t File does not exit \n";
	}else{
		data1.open("database1.txt",ios::app | ios::out);
		
		data >> pcode >> pname >> price >> dis;
		
		while(!data.eof()){
			if(pkey == pcode){
				cout << "\n\n\t\t Product new Code : ";
				cin >> c;
				cout << "\n\n\t\t Name of the Product : ";
				cin >> n;
				cout << "\n\n\t\t Price of the Product : ";
				cin >> p;
				cout << "\n\n\t\t Discount : ";
				cin >> d;
				data1 << " " << c << " " << n << " " << p << " " << d << "\n";
				cout << "\n\n\t\t\t\t Record Edited Successfully\n\n";
				token++;
			}else{
				data1 << " "<< pcode << " " << pname << " " << price << " " << dis <<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt","database.txt");
		if(token == 0)
			cout << "\n\n\n\t\t Product not Found Sorry!!!!\n";		
	}	
}

void shopping :: rem(){
	start:
	fstream data,data1;
	int c,token = 0,pkey;
	float p,d;
	string n;
	cout << "\n\t\t\t Delete the Product \n";
	cout << "\n\n\t\tEnter the product Code : ";
	cin >> pkey;
	
	data.open("database.txt",ios::in);
	
	if(!data){
		cout << "\n\t\t\tProduct Does not Found \n";
	}else{
		data1.open("database1.txt",ios::app | ios::out);
		
		data >> pcode >> pname >> price >> dis;
		
		while(!data.eof()){
			if(pkey == pcode){
				cout << "\n\n\t\t\t\t Product Deleted Successfully\n";
				token++;
			}else{
				data1 << " "<< pcode << " " << pname << " " << price << " " << dis <<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt","database.txt");
		if(token == 0)
			cout << "\n\n\n\t\t Product not Found Sorry!!!!\n";		
	}	
}

void shopping :: list(){
	fstream data;
	data.open("database.txt",ios::in);
	cout << "\n\n\t\t------------------------------------------------------------------------------\n";
	cout << "\t\tProduct\t\tName\t\tprice\t\t\n";
	cout  << "\n\n\t\t-----------------------------------------------------------------------------\n";
	data >> pcode >> pname >> price >> dis;
	while(!data.eof()){
		cout << "\t\t" <<  pcode << " \t\t " << pname << " \t\t " << price << " \t\t \n";
		data >> pcode >> pname >> price >> dis;
	}
	data.close();
} 

void shopping :: receipt(){
	fstream data;
	
	int arrc[100];
	int arrq[100];
	char choice;
	int c = 0;
	float amount = 0,dis = 0,total = 0;
	
	cout << "\n\n\t\t\t\t Receipt \t\t \n";
	data.open("database.txt",ios::in);
	if(!data){
		cout << "\n\n\t There is no Products in the Store\n";
	}else{
		data.close();
		list();
		
		cout << "\n\t\t ____________________________________________________________";
		cout << "\n\t\t|                                                            |";
		cout << "\n\t\t|                      Place Order                           |";
		cout << "\n\t\t|                                                            |";
		cout << "\n\t\t|____________________________________________________________|\n";
		do{
			start:
			cout << "\n\n\t\t Enter the Product code : ";
			cin >> arrc[c];
			cout << "\n\n\t\t Enter the Produce quantity : ";
            cin >> arrq[c];
            for(int i = 0;i<c;i++){
            	if(arrc[i] == arrc[c]){
            		cout << "\n\n\t\t You already taken the Product \n\n";
            		goto start;
				}
			}
			bool f = false;
			data.open("database.txt",ios::in);
			data >> pcode >> pname >> price >> dis;
			while(data){
				if(pcode == arrc[c]){
					f = true;
				}
				data >> pcode >> pname >> price >> dis; 
			}
			data.close();
			if(!f){
				cout << "\n\n\t\tProduct you want to buy is Out of Stock \n";
				goto start;
			}
			c++;
			cout << "\n\n\t\t Do you want any other product? Enter y if yes or n if no : ";
			cin >> choice;
		}while(choice == 'y');
		cout << "\n\n\t _________________________________RECERIPT________________________________________\n\n";
		cout << "\t|Product No\tProduct Name\tQuantity\tPrice\t\tAmt\tAmt after discount|\n\n";
		for(int i = 0;i<c;i++){
		
			data.open("database.txt",ios::in);
			data >> pcode >> pname >> price >> dis;
			while(data){
				if(pcode == arrc[i]){
					amount = price*arrq[i];
					dis = amount - (amount*dis/100);
					total+=dis;
					cout << "\n\t" << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount  << "\t\t" << dis << "\n";
				}
				data >> pcode >> pname >> price >> dis; 
			}
			data.close();
		}
	}
	cout << "\n\n\t\t_______________________________________________________________________________________\n";
	cout <<  "\tTotal Amount = " << total << "\n"; 
}


int main(){
	
	shopping sh;
	sh.menu();
	return 0;
}


