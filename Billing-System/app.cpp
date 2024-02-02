#include<iostream>
#include<string>
#include<conio.h>
#include<iomanip>
#include<fstream>

using namespace std;

class Product {
private:
	int productNumber;
	string productName;
	float productRate;

public:
	Product()
	{
		productNumber = 0;
		productName = "";
		productRate = 0.0;
	}

	Product(int number, string name, float rate)
		: productNumber(number), productName(name), productRate(rate)
	{
		ofstream outProduct;
		outProduct.open("Products.txt", ios::out | ios::app);
		outProduct
			<< productNumber
			<< ' '
			<< productName
			<< ' '
			<< productRate
			<< endl;
		cout << "\n\n\n\tPRODUCT CREATED SUCCESSFULLY";
		getch();
	}

	int getProductNumber()
	{
		return productNumber;
	}

	string getProductName()
	{
		return productName;
	}

	float getProductRate()
	{
		return productRate;
	}

	void setProductNumber(int number)
	{
		productNumber = number;
	}

	void setProductName(string name)
	{
		productName = name;
	}

	void setProductRate(float rate)
	{
		productRate = rate;
	}
};

class Bill {
public:
	string date;
	float totalAmount;

public:
	Bill()
	{
		time_t now = time(0);
		char* dt = ctime(&now);
		date = dt;
		totalAmount = 0;
	}
};

class BillItem {
private:
	Product product;
	int quantity;

public:
	void setProduct(int code)
	{
		ifstream prodFile;
		prodFile.open("Products.txt", ios::in);
		int number;
		string name;
		float rate;
		while (1)
		{
			prodFile >> number >> name >> rate;
			if (number == code)
			{
				product.setProductNumber(number);
				product.setProductName(name);
				product.setProductRate(rate);
				break;
			}
		}
	}

	void setQuantity(int qty)
	{
		quantity = qty;
	}

	float getItemAmount()
	{
		return product.getProductRate() * quantity;
	}

	void printItemDetails()
	{
		cout
			<< "\t" << setw(14) << product.getProductNumber()
			<< "\t" << setw(12) << product.getProductName()
			<< "\t" << setw(12) << product.getProductRate()
			<< "\t" << setw(8) << quantity << "\t";
	}
};

class Invoice :public Bill {
private:
	int numOfItems;
	BillItem item[50];
};

class Menu {
public:
	static void showIntro()
	{
		cout << "\n\n\n\tBILLING SYSTEM" << endl;
		cout << "\n\t================================================================\n";
		cout << "\n\n\tDEVELOPED BY:";
		cout << "\n\n\tNavnath Varade";
		cout << "\n\n\tPlease enter any key......";

	}

	static void displayMainMenu()
	{
		int choice;
		system("cls");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t1. CUSTOMER";
		cout << "\n\n\t2. ADMINISTRATOR";
		cout << "\n\n\t3. EXIT";
		cout << "\n\n\tPlease Select Your Option (1-3) : ";
		cin >> choice;
		switch (choice)
		{
		case 1: customerMenu(); break;
		case 2: adminMenu(); break;
		case 3: exit(0);
		}
	}

	static void customerMenu()
	{
		int numItems;
		BillItem item[20];
		system("cls");
		cout << "\n\n\tENTER THE NUMBER OF ITEMS:";
		cin >> numItems;
		displayProducts();
		int code, qty;
		for (int i = 0; i < numItems; i++)
		{
			cout << "\n\tENTER ITEM CODE:";
			cin >> code;
			item[i].setProduct(code);
			cout << "\n\tENTER ITEM QUANTITY:";
			cin >> qty;
			item[i].setQuantity(qty);
		}
		Bill finalBill;
		for (int i = 0; i < numItems; i++)
		{
			finalBill.totalAmount += item[i].getItemAmount();
		}
		displayInvoice(finalBill, item, numItems);
	}

	static void adminMenu()
	{
		while (1)
		{
			system("cls");
			int choice;
			cout << "\n\n\n\tADMIN MENU";
			cout << "\n\n\t1.CREATE PRODUCT";
			cout << "\n\n\t2.DISPLAY ALL PRODUCTS";
			cout << "\n\n\t3.MODIFY PRODUCT";
			cout << "\n\n\t4.DELETE PRODUCT";
			cout << "\n\n\t5.BACK TO MAIN MENU";
			cout << "\n\n\tPlease Enter Your Choice (1-5) ";
			cin >> choice;
			switch (choice)
			{
			case 1: createProduct(); break;
			case 2: displayProducts(); break;
			case 3: modifyProduct(); break;
			case 4: deleteProduct(); break;
			case 5: displayMainMenu(); break;
			default: break;
			}
		}
	}

	static void createProduct()
	{
		system("cls");
		int num;
		string name;
		float rate;
		cout << "\n\n\tENTER THE DETAILS OF THE PRODUCT" << endl;
		cout << "\n\tENTER THE PRODUCT NUMBER : ";
		cin >> num;
		cout << "\n\tENTER THE PRODUCT NAME : ";
		cin >> name;
		cout << "\n\tENTER THE PRODUCT RATE : ";
		cin >> rate;
		Product product(num, name, rate);
	}

	static void displayProducts()
	{
		system("cls");
		ifstream displayProducts;
		displayProducts.open("Products.txt", ios::in);
		int num;
		string name;
		float rate;
		cout << "\n\n\tDISPLAY ALL PRODUCTS" << "\n\t=================================================================";
		while (1)
		{
			displayProducts >> num;
			if (displayProducts.eof())
				break;
			displayProducts >> name >> rate;
			cout << "\n\tPRODUCT NUMBER : " << num;
			cout << "\n\tPRODUCT NAME : " << name;
			cout << "\n\tRATE OF PRODUCT : " << rate;
			cout << "\n\t=================================================================";
		}
		cout << "\n\tPress any key";
		getch();
	}

	static void modifyProduct()
	{
		system("cls");
		displayProducts();
		ifstream prodIn;
		ofstream prodTmp;
		cout << "\n\t*****************************************************************";
		cout << "\n\tEnter the Product Number to Modify:\n";
		int modNum;
		cin >> modNum;
		prodIn.open("Products.txt", ios::in);
		prodTmp.open("temp.txt", ios::out);
		int num;
		string name;
		float rate;
		while (1)
		{
			prodIn >> num;
			if (prodIn.eof())
				break;
			prodIn >> name >> rate;
			if (num == modNum)
			{
				cout << "\n\tEnter new rate:";
				cin >> rate;
			}
			prodTmp
				<< num
				<< ' '
				<< name
				<< ' '
				<< rate
				<< endl;
		}
		prodIn.close();
		prodTmp.close();
		remove("Products.txt");
		rename("temp.txt", "Products.txt");
		cout << "\n\n\n\tPRODUCT RATE UPDATED SUCCESSFULLY";
		getch();
	}

	static void deleteProduct()
	{
		system("cls");
		displayProducts();
		ifstream prodIn;
		ofstream prodTmp;
		cout << "\n\t*****************************************************************";
		cout << "\n\tEnter the Product Number to Delete:\n";
		int modNum;
		cin >> modNum;
		prodIn.open("Products.txt", ios::in);
		prodTmp.open("temp.txt", ios::out);
		int num;
		string name;
		float rate;
		while (1)
		{
			prodIn >> num;
			if (prodIn.eof())
				break;
			prodIn >> name >> rate;
			if (num != modNum)
			{
				prodTmp
					<< num
					<< ' '
					<< name
					<< ' '
					<< rate
					<< endl;
			}
		}
		prodIn.close();
		prodTmp.close();
		remove("Products.txt");
		rename("temp.txt", "Products.txt");
		cout << "\n\n\n\tPRODUCT DELETED SUCCESSFULLY";
		getch();
	}

	static void displayInvoice(Bill finalBill, BillItem item[], int numItems)
	{
		system("cls");
		cout << "\n\n\tINVOICE\t\t\tDate/Time:" << finalBill.date << endl;
		cout << "\t======================================================================================================" << endl;
		cout << "\tProduct Number\tProduct Name\tProduct Rate\tQuantity\tAmount" << endl;
		for (int i = 0; i < numItems; i++)
		{
			item[i].printItemDetails();
			cout << setw(6) << item[i].getItemAmount() << endl;
		}
		cout << "\n\n\t\t\t\tTOTAL AMOUNT: " << finalBill.totalAmount;
		cout << "\n\tThank You for Shopping" << endl;
		cout << "\n\tPress any key to continue...";
		getch();
	}
};

int main()
{
	Menu::showIntro();
	getch();
	system("cls");
	while (1)
	{
		Menu::displayMainMenu();
	}
	return 0;
}
