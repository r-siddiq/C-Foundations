// Rahim Siddiq
// Project 3
// 10/25/2023

#include <iostream>
#include <ctime>
using namespace std;

typedef struct node
{
	int ID;
	char grade;
	struct node* next;
} Student;

void printList(Student* head);
int countList(Student* head);
void fillNode(Student* node, Student* next);
int countAs(Student* head);											// Added function prototype for # of A's

int main()
{
	cout << "Rahim Siddiq - Project 3 - Linked List Exercise!\n\n";
	srand((unsigned int)time(NULL));								// "Seed" random number generator

	Student student1;												// Declare and fill the first node
	Student* top;
	Student* ptrStudent = NULL;
	top = &student1;
	fillNode(top, NULL);

	// Dynamically create a node, fill its data (ID, grade, and next)
	ptrStudent = (Student*)malloc(sizeof(Student));
	fillNode(ptrStudent, top);
	top = ptrStudent;												// Move pointer to the top

	// Another node, similar to lines 34-36
	ptrStudent = (Student*)malloc(sizeof(Student));
	fillNode(ptrStudent, top);
	top = ptrStudent;

	// Create another node after line 39
	ptrStudent = (Student*)malloc(sizeof(Student));
	fillNode(ptrStudent, top);
	top = ptrStudent;

	printList(top);
	int count = countList(top);
	printf("\nNumber of nodes = %4d", count);
	int countOfAs = countAs(top);
	printf("\nNumber of A's = %4d", countOfAs);

	cout << "\n\nRahim Siddiq - End of Project - Linked List Exercise!\n\n";
}

//=========================================================================================================================

void printList(Student* head)
{
	while (head != NULL)
	{
		printf("ID = %5d, grade = %c\n", head->ID, head->grade);
		head = head->next;
	}
}

//=========================================================================================================================

int countList(Student* head)
{
	int temp = 0;

	while (head != NULL)
	{
		temp++;
		head = head->next;
	}
	return temp;
}

//=========================================================================================================================

void fillNode(Student* node, Student* next)
{
	node->ID = rand() % 2000 + 1000;
	node->grade = (char)(65 + rand() % 4);
	node->next = next;
}

//=========================================================================================================================

int countAs(Student* head)
{
	int count = 0;
	while (head != NULL)
	{
		if (head->grade == 'A')
			count++;
		head = head->next;
	}
	return count;
}