// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CircularArray.h"
#include "assert.h"
#include <vector>

#define NUM_ELEMENTS 10

int main()
{
	//REGULAR FOR LOOP TESTS

	//create a CircularArray
	CircularArray<int> theArray1 = CircularArray<int>(NUM_ELEMENTS);

	//create another array with which to compare
	int theAnswers[NUM_ELEMENTS];

	//add some data
	for (int i = 0; i < NUM_ELEMENTS; i++) {
		theArray1[i] = i;
		theAnswers[i] = i;
	}
	//read some data
	for (int i = 0; i < NUM_ELEMENTS; i++) {
		assert(theArray1[i] == theAnswers[i]);
	}
	printf("Test 1 passed\n");


	//rotate the array by a small amount
	CircularArray<int> theArray2 = CircularArray<int>(NUM_ELEMENTS);
	for (int i = 0; i < NUM_ELEMENTS; i++) {
		theArray2[i] = i;
		theAnswers[i] = i;
	}
	int offset = 2;
	theArray2.rotate(offset);
	//read some data
	for (int i = 0; i < NUM_ELEMENTS; i++) {
		assert(theArray2[i] == theAnswers[(i + offset) % NUM_ELEMENTS]);
	}
	printf("Test 2.1 passed\n");
	//add some data
	for (int i = 0; i < NUM_ELEMENTS; i++) {
		theArray2[i] = i;
		theAnswers[i] = i;
	}
	//read some data
	for (int i = 0; i < NUM_ELEMENTS; i++) {
		assert(theArray2[i] == theAnswers[i]);
	}
	printf("Test 2.2 passed\n");


	//rotate the array by a large amount
	CircularArray<int> theArray3 = CircularArray<int>(NUM_ELEMENTS);
	for (int i = 0; i < NUM_ELEMENTS; i++) {
		theArray3[i] = i;
		theAnswers[i] = i;
	}
	offset = 76;
	theArray3.rotate(offset);
	//read some data
	for (int i = 0; i < NUM_ELEMENTS; i++) {
		assert(theArray3[i] == theAnswers[(i + offset) % NUM_ELEMENTS]);
	}
	printf("Test 3.1 passed\n");
	//add some data
	for (int i = 0; i < NUM_ELEMENTS; i++) {
		theArray3[i] = i;
		theAnswers[i] = i;
	}
	//read some data
	for (int i = 0; i < NUM_ELEMENTS; i++) {
		assert(theArray3[i] == theAnswers[i]);
	}
	printf("Test 3.2 passed\n");








	//RANGE-BASED FOR LOOP TESTS
	std::vector<int> theAnswers2 = std::vector<int>();
	CircularArray<int> theArray4 = CircularArray<int>(NUM_ELEMENTS);
	//write some data
	for (int i = 0; i < NUM_ELEMENTS; i++) {
		theArray4[i] = i;
		theAnswers2.push_back(i);
	}
	//read some data with range-based for loop
	int idx = 0;
	for (int i : theArray4) {
		assert(i == theAnswers2[idx]);
		idx++;
	}
	printf("Test 4.1 passed\n");
	

	printf("All tests passed!\n");

    return 0;
}

