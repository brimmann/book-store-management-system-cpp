#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
//#define n 50
#include "books_database.h"
using namespace std;




void SearchBook();

void AddBook();
void SellBook();
void UpdateBook();
void bill(int index);

void DisplayBooks(int index);

int main()
{
	fill();
	
	for(int i = 0; i < n; i++)
	{
		if(books[i].isEmpty != true)
		{
			books[i].isEmpty = true;
		}
	}
	bool exit = false; bool exitToHome = false;
	
	string adminOption;
	while(exit == false)
	{
		string mode;
		cout << "Select a mode: customar - admin - exit: ";
		getline(cin, mode);
		exitToHome = false;
		if(mode == "customar")
		{
		    SearchBook();
		}
		else if(mode == "admin")
		{
			while(exitToHome == false && exit == false)
			{
				cout << "Select an option: add - update - sell - exitadmin - exit:  ";
				getline(cin, adminOption);
				if(adminOption == "add")
				{
					AddBook();
				}
				else if(adminOption == "update")
				{
					UpdateBook();
				}
				else if(adminOption == "sell")
				{
					SellBook();
				}
				else if(adminOption == "exitadmin")
				{
					exitToHome = true;
				}
				else if(adminOption == "exit")
				{
					exit = true;
				}
				else
				{
					cout << "Invalid Input!\n";
				}
			}
		}
		else if(mode == "exit")
		{
			exit = true;
		}
		else
		{
			cout << "Invalid Input!\n";
		}
	}
	cin.get();
	return 0;
}


void SearchBook()
{
	string searchMode;
	bool bookFound = false;
	
	bool searchHome = true;
	while(searchHome)
	{
		cout << "Select a search mode: bytitle - byauthor - exituser: ";
		getline(cin, searchMode);
	if(searchMode == "bytitle")
	{
		string bookTitle;
		cout << "Enter book title: ";
		getline(cin, bookTitle);
		for(int i = 0; i < n; i++)
		{
			if(bookTitle == books[i].title)
			{
				DisplayBooks(i);
				bookFound = true;
			}
		}
		if(bookFound == false)
		{
			cout << "Book not found!\n";
		}
		string cont;
		bool invalid = true;
		while(1)
		{
			cout << "Do you want to quit? yes|no: ";
			getline(cin, cont); 
			if(cont == "yes")
			{
				//invalid = false;
				searchHome = false;
				break;
			}
			else if(cont == "no")
			{
				//invalid = false;
				break;
			}
			else
			{
				cout << "Invalid Input!\n";
			}
		}
	}
	else if (searchMode == "byauthor")
	{
		string bookAuthor;
		cout << "Enter author's name: ";
		getline(cin, bookAuthor);
		for(int i = 0; i < n; i++)
		{
			if(bookAuthor == books[i].authorName)
			{
				DisplayBooks(i);
				bookFound = true;
			}	
		}
		if(bookFound == false)
		{
			cout << "Book not found!\n";
		}
		string cont;
		bool invalid = true;
		while(invalid)
		{
			cout << "Do you want to quit? yes|no: ";
			getline(cin, cont); 
			if(cont == "yes")
			{
				invalid = false;
				searchHome = false;
			}
			else if(cont == "no")
			{
				invalid = false;
			}
			else
			{
				cout << "Invalid Input!\n";
			}
		}
	}
	else if(searchMode == "exituser")
	{
		searchHome = false;
	}
	else
	{
		cout << "Invalid Input!\n";
	}
	}
}

void AddBook()
{
	bool cont = true;
	string yesNo;
	int ind = 0;
	while(cont)
	{
		
		bool contYesNo = true;
		
			if(books[ind].isEmpty == true)
			{
				cont = false;
				cout << "Book Title: "; getline(cin, books[ind].title);
				cout << "Author Name: "; getline(cin, books[ind].authorName);
				cout << "Edition: " ; cin >> books[ind].edition;
				cout << "Publication Year: "; cin >> books[ind].pubDate;
				cout << "Price: "; cin >> books[ind].price;
				cout << "Quantity: "; cin >> books[ind].qnt;
				books[ind].isEmpty = false;
				cont = false;
			}
		
		ind++;
		while(contYesNo)
		{
			cout << "Do you want to add more books? yes|no: "; cin.ignore(); getline(cin, yesNo);
			if(yesNo == "yes")
			{
				cont = true;
				contYesNo = false;
			}
			else if(yesNo == "no")
			{
				cont = false;
				contYesNo = false;
			}
			else
			{
				cout << "Invalid Input!";
				contYesNo = true;
			}
			
		}
		//cout << "TEST\n";
	
	}
}

void SellBook()
{
	book soldBook;
	int soldQnty = 0;
	cout << "Book Title: "; getline(cin, soldBook.title);
	cout << "Author Name: "; getline(cin, soldBook.authorName);
	cout << "Book Edition: "; cin >> soldBook.edition;
	
	for(int i = 0; i < n; i++)
	{
		if(soldBook.title ==  books[i].title && soldBook.authorName == books[i].authorName && soldBook.edition == books[i].edition)
		{
			cout << "Sold Book(s) Quantity: "; cin >> soldQnty;
			while(soldQnty > books[i].qnt)
			{
				cout << "Quantity exceed the availaiable amount of books, please try again!\n";
				cout << "Sold Book(s) Quantity: "; cin >> soldQnty;
			
			}
			books[i].qnt -= soldQnty;
			bill(i);
			break;
		}
		
	}
}

void bill(int index)
{
	cin.get();
	string cusName;
	cout << "Customar Name: ";
	getline(cin, cusName);  // Can't be able to get the right input
	time_t now = time(0);
	char* dt = ctime(&now);
	cout << "Book(s) Sold: \nTitle: "  << books[index].title << "\nAuthor: " << books[index].authorName << endl;
	cout << "Sold to: " << cusName << endl;
	cout << "Purchase Date: " << dt << endl;
	//cin.get();
}


void UpdateBook()
{
	book updateBook;
	int updateQnty = 0;
	bool invalid = true;
	while(invalid)
	{
		cout << "Book Title: "; getline(cin, updateBook.title);
		cout << "Author Name: "; getline(cin, updateBook.authorName);
		cout << "Book Edition: "; cin >> updateBook.edition;
		cout << "Update Quantity: "; cin >> updateQnty;
		for(int i = 0; i < n; i++)
		{
		if(updateBook.title ==  books[i].title && updateBook.authorName == books[i].authorName && updateBook.edition == books[i].edition)
		{
			books[i].qnt += updateQnty;
			cout << "Book Updated!\n";	
			cin.ignore();
			invalid = false;
			break;
		}
		else
		{
			cout << "Book does not exist, please try again!\n";
			invalid = true;
			break;
		}
		}
	}
}

void DisplayBooks(int index)
{
	char space[40];
	for(int i = 0; i < 40; i++) {space[i] = '\0';}
	int spaceSize;
	int spaceSizeDigit = 1;
	cout << "Book Title                          Author          Edition    Publication Year   Price     Quantity\n";
	spaceSize = 36-books[index].title.length();
	for(int i = 0; i < spaceSize; i++) {space[i] = ' ';}
	cout << books[index].title << space;
	spaceSize = 16-books[index].authorName.length();
	for(int i = 0; i < 40; i++) {space[i] = '\0';}
	for(int i = 0; i < spaceSize; i++) {space[i] = ' ';}
	cout << books[index].authorName << space;
	spaceSizeDigit = 1;
	int temp = books[index].edition;
	while( temp / 10)
	{
		spaceSizeDigit++;
		temp /= 10;
	}
	//cout << "****TEST****" << spaceSizeDigit << "*****";
	for(int i = 0; i < 40; i++) {space[i] = '\0';}
	for(int i = 0; i < 11-spaceSizeDigit; i++) {space[i] = ' ';}
	
	cout << books[index].edition << space;
	
	spaceSizeDigit = 1;
	temp = books[index].pubDate;
	//cout << "****TEST****" << books[index].pubDate % 10 << "*****";
	while(temp / 10)
	{
		spaceSizeDigit++;
		temp /= 10; 
	}
	//cout << "TEST*\n";
	for(int i = 0; i < 40; i++) {space[i] = '\0';}
	for(int i = 0; i < 19-spaceSizeDigit; i++) {space[i] = ' ';}
	cout << books[index].pubDate << space;
	
	spaceSizeDigit = 1;
	temp = int(books[index].price);
	while(temp / 10)
	{
		spaceSizeDigit++;
		temp /= 10;
	}
	for(int i = 0; i < 40; i++) {space[i] = '\0';}
	for(int i = 0; i < 10-(spaceSizeDigit+4); i++) {space[i] = ' ';}
	cout << fixed << setprecision(4) << books[index].price << space;
	cout << books[index].qnt << endl;
}

