
/* Name: Andrew Stade
Date: 9/14/2020
Section: COP 4530 */

#include <iostream>
#include <string>
#include "tlist.h"

using namespace std;


template <typename T> 
void PrintList(const TList<T>& L, string label) 	// PrintList setup from "driver.cpp"
{
	cout << label << " size is: " << L.GetSize() << "\n"
		<< label << " = ";
	L.Print(cout);
	cout << "\n\n";
}

int main()
{
	cout << "--- MYDRIVER.CPP ---" << endl;
	
	TList<int> List1;		// tests: TList(); setVoid();
	
	cout << "Print empty list 1 (ints)" << endl;
	PrintList(List1, "List1");
	
	TList<double> List2;	// tests: type flexibility (double)
	
	cout << "Print empty list 2 (doubles)" << endl;
	PrintList(List2, "List2");
	
	TList<char> List3;	// tests: type flexibility (char)
	
	cout << "Print empty list 3 (char)" << endl;
	PrintList(List3, "List3");
	
	
	// INT INSERTS
	cout << "Insert 10 numbers to the front of list 1 (ints)" << endl;
	for (int i = 0; i < 10; i++)	
	{
		List1.InsertFront(i);		// tests: InsertFront();	
	}
	PrintList(List1, "List1");
	
	cout << "Insert 3 numbers to the back of list 1 (ints)" << endl;
	for (int i = 0; i < 3; i++)	
	{
		List1.InsertBack(i*10);		// tests: InsertBack();	
	}
	PrintList(List1, "List1");	
	
	
	// DOUBLE INSERTS
	cout << "Insert 12 numbers to the front of list 2 (doubles)" << endl;
	for (int i = 0; i < 12; i++)	
	{
		List2.InsertFront(i*1.01);		// tests: InsertFront();	
	}
	PrintList(List2, "List2");
	
	cout << "Insert 3 numbers to the back of list 2 (doubles)" << endl;
	for (int i = 0; i < 3; i++)	
	{
		List2.InsertBack(i*5.25);		// tests: InsertBack();	
	}
	PrintList(List2, "List2");
	
	
	// CHAR INSERTS
	cout << "Insert 2 chars to the front of list 3 (chars)" << endl;
	cout << "This will run 8 times making 16 chars in list 3" << endl;
	for (int i = 0; i < 8; i++)	
	{
		for (int j = 0; j < 2; j++)
		{
			List3.InsertFront('a');		// tests: InsertFront(); x 8	
		}
	}
	PrintList(List3, "List3");
	
	cout << "Insert 1 char to the back of list 3 (chars)" << endl;
	cout << "This will run 8 times making 24 chars in list 3" << endl;
	for (int i = 0; i < 8; i++)	
	{
		for (int j = 0; j < 1; j++)
		{
			List3.InsertBack('b');		// tests: InsertBack();	x 8
		}
	}
	PrintList(List3, "List3");
	
	
	// INT REMOVES
	cout << "Remove 5 numbers from the front of list 1 (ints)" << endl;
	for (int i = 0; i < 5; i++)	
	{
		List1.RemoveFront();		// tests: RemoveFront();	
	}
	PrintList(List1, "List1");	
	
	cout << "Remove 4 numbers from the back of list 1 (ints)" << endl;
	for (int i = 0; i < 4; i++)	
	{
		List1.RemoveBack();		// tests: RemoveBack();	
	}
	PrintList(List1, "List1");	
	
	
	// DOUBLE REMOVES
	cout << "Remove 5 numbers from the front of list 2 (doubles)" << endl;
	for (int i = 0; i < 5; i++)	
	{
		List2.RemoveFront();		// tests: RemoveFront();	
	}
	PrintList(List2, "List2");
	
	cout << "Remove 4 numbers from the back of list 2 (doubles)" << endl;
	for (int i = 0; i < 4; i++)	
	{
		List2.RemoveBack();		// tests: RemoveBack();	
	}
	PrintList(List2, "List2");
	
	
	// CHAR REMOVES
	cout << "Remove 10 char from the front of list 3 (chars)" << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			List3.RemoveFront();	// tests: RemoveFront(); x 10
		}
	}
	PrintList(List3, "List3");
	
	cout << "Remove 10 char from the back of list 3 (chars)" << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			List3.RemoveBack();	// tests: RemoveBack();	x 9
		}
	}
	PrintList(List3, "List3");
	
	
	// ITERATOR SEARCHING
	TListIterator<int> itrList1 = List1.GetIterator();
	TListIterator<double> itrList2 = List2.GetIterator();
	
	for (int i = 0; i < List1.GetSize(); i++)	// moves throughout the list front to back
	{
		itrList1.Next();	// tests: Next();
	}
	for (int i = 0; i < List1.GetSize(); i++)	// moves throughout the list back to front
	{
		itrList1.Previous();	// tests: Previous();
	}
	
	cout << "Empty List 1" << endl;
	
	List1.Clear();			// tests: Clear();
	PrintList(List1, "List1");	

	cout << "Insert 11 numbers to the front of list 1 (iterator)" << endl;
	List1.InsertFront(33);
	List1.InsertFront(20);
	List1.InsertFront(96);
	List1.InsertFront(12);
	List1.InsertFront(55);
	List1.InsertFront(46);
	List1.InsertFront(21);
	List1.InsertFront(68);
	List1.InsertFront(80);
	List1.InsertFront(73);
	List1.InsertFront(99);		// tests: InsertFront(); x 11	
	PrintList(List1, "List1");	
	
	// ITERATOR INSERTS
	cout << "Iteratively insert the number 1 into list 1" << endl;
	List1.Insert(itrList1, 1);		// tests: Iterator Insert();
	PrintList(List1, "List1");	
	
	cout << "Iteratively insert the number 2 into list 1" << endl;
	cout << "This will run 9 times making 21 chars in list 1" << endl;
	for(int i = 0; i < 9; i++)
	{
		List1.Insert(itrList1, 2);	// tests: Iterator Insert(); x 9
	}
	PrintList(List1, "List1");	
	
	
	// ITERATOR REMOVES
	cout << "Iteratively remove 1 number from list 1" << endl;
	List1.Remove(itrList1);		// tests: Iterator Remove();
	PrintList(List1, "List1");	

	for(int i = 0; i < 10; i++)
	{
		itrList1.Previous();	
	}
	
	cout << "Iteratively remove 9 numbers from list 1" << endl;
	for(int i = 0; i < 9; i++)
	{
		List1.Remove(itrList1);		// tests: Iterator Remove(); x 9
		itrList1.Previous();	
	}
	PrintList(List1, "List1");	
	
	
	cout << "Final Lists :" << endl;		// OVERVIEW FUNCTIONS TESTED: 
	PrintList(List1, "List1");				// TList(); setVoid(); Clear(); Next(); Previous(); type felxibility (3 types tested: int, double, char);
	PrintList(List2, "List2");				// InsertFront() x 21; InsertBack() x 10; RemoveFront() x 12; RemoveBack() x 11;
	PrintList(List3, "List3");				// Iterator Insert() x 10; Iterator Remove(); x 10;
											// The list has been travesed both front to back AND back to front
											
	cout << "!Testing Complete!" << endl;
	
	return 0;
}