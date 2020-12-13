#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

template <class T>
struct node
{
	T data;
	node<T>* prev, * next;
};

template <class T>
class list
{
private:
	node<T>* head, * tail;
	int counter;
public:
	list()
	{
		head = tail = NULL;
	}
	void create(T number);
	void push(T number);
	void pushToTail(T number);
	bool empty();
	void swap(int, int);
	//void sort();
	//void secondSort();
	void search();
	void deleteCertainNode(int);
	void pop();
	void show();
	void edit(int);
	void write(string str);
	void read(string str);
	~list()
	{
		node<T>* temp;
		if (head != NULL)
		{
			while (head->next != NULL)
			{
				temp = head;
				head = head->next;
				delete temp;
			}
			counter = 0;
		}
	}
};
