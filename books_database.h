#include <string>

//Books List
using namespace std;
struct book 
{
	string title;
	string authorName;
	unsigned int edition;
	unsigned int pubDate;
	float price;
	unsigned int qnt;
	bool isEmpty;
};
const int n = 50;
book books[n];

void fill()
{ 
	books[0] = {"Computer Network", "Keith Ross", 6, 2018, 400, 5, false};
	books[1] = {"Computer Network", "Keith Ross", 3, 2008, 400, 4, false};
	books[2] = {"Linear Algebra", "David C.Lay", 5, 2016, 300, 7, false};
	books[3] = {"Linear Algebra", "Ward Cheney", 2, 2011, 350, 2, false};
	books[4] = {"Linear Algebra", "R. Aleny", 1, 2003, 300, 5, false};
	books[5] = {"Discrete Mathematics", "Kenneth H Rosen", 7, 2013, 500, 4, false};
}

