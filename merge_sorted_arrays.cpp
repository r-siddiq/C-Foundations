// Rahim Siddiq
// Project 2
// 10/14/2023

#include <iostream>

// constant declarations
#define DATA1_SIZE 15
#define DATA2_SIZE 12
#define DATA12_SIZE DATA1_SIZE + DATA2_SIZE

// Functions Prototypes
void populateData(int[], int);
void printData(int[], int);
void mergeData(int[], int, int[], int, int[]);

int main()
{
	int data1[DATA1_SIZE];
	int data2[DATA2_SIZE];
	int data12[DATA12_SIZE];

	srand(time(0));											// seed random numbers

	// populate and print first array
	populateData(data1, DATA1_SIZE);
	printf("Array1 data:\n");
	printData(data1, DATA1_SIZE);

	// Populate and print second array
	populateData(data2, DATA2_SIZE);
	printf("Array2 data:\n");
	printData(data2, DATA2_SIZE);

	// Merge arrays and print merged data
	mergeData(data1, DATA1_SIZE, data2, DATA2_SIZE, data12);
	printf("\nMerged data:\n");
	printData(data12, DATA12_SIZE);
}
//---------------------------------------------------------
// Populate array with random data, sorted in increasing order
void populateData(int data[], int size)
{
	data[0] = rand() % (50 - 10 + 1) + 10;					//Get a random integer in range of [10, 50]
	for (int i = 1; i < size; i++)
		data[i] = data[i - 1] + rand() % (15 - 5 + 1) + 5;  // Add a random integer in range of [5, 15]

}

void printData(int data[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%4d", data[i]);								// Print data elements with spaces in between
	printf("\n");											// Move to next line
}

void mergeData(int data1[], int size1, int data2[], int size2, int data12[])
{
    int i = 0;                                              // Index for data1
    int j = 0;                                              // Index for data2
    int k = 0;                                              // Index for data12

    // Merge data while both arrays have not reached their end
    while (i < size1 && j < size2)
    {
        if (data1[i] < data2[j])
        {
            data12[k] = data1[i];
            i++;
        }
        else
        {
            data12[k] = data2[j];
            j++;
        }
        k++;
    }

    // Merge the remaining elements of data1 (if any)
    while (i < size1)
    {
        data12[k] = data1[i];
        i++;
        k++;
    }

    // Merge the remaining elements of data2 (if any)
    while (j < size2)
    {
        data12[k] = data2[j];
        j++;
        k++;
    }
}