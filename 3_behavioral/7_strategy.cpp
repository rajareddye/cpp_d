/*
Strategy Method:
that defines a family of interchangeable algorithms and allows them to be used interchangeably within a context. 
This pattern enables the algorithm to be selected at runtime, 
providing flexibility and promoting code reusability.

Suppose you are working on a data processing application, and you need to implement a sorting feature 
that allows users to sort data in various ways. 
You decide to use the Strategy Pattern to handle different sorting algorithms.

*/

#include <bits/stdc++.h>
class SortingStrategy {
public:
	virtual void sort(std::vector<int>& arr) = 0;
};
class BubbleSort : public SortingStrategy {
public:
	void sort(std::vector<int>& arr) override
	{
		// Implement Bubble Sort algorithm
	}
};

class QuickSort : public SortingStrategy {
public:
	void sort(std::vector<int>& arr) override
	{
		// Implement Quick Sort algorithm
	}
};

// Add more sorting algorithms as needed

class SortContext {
private:
	SortingStrategy* strategy;

public:
	void setStrategy(SortingStrategy* strategy)
	{
		this->strategy = strategy;
	}

	void executeStrategy(std::vector<int>& arr)
	{
		strategy->sort(arr);
	}
};
int main()
{
	std::vector<int> data = { 5, 2, 7, 1, 9 };

	SortContext context;
	BubbleSort bubbleSort;
	QuickSort quickSort;

	context.setStrategy(&bubbleSort);
	context.executeStrategy(data); // Executes Bubble Sort

	context.setStrategy(&quickSort);
	context.executeStrategy(data); // Executes Quick Sort

	return 0;
}
