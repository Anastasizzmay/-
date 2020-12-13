#include "list.h"
template <class T>
void list<T>::create(T number)
{
	node<T>* temp = new node<T>;
	temp->data = number;
	temp->next = temp->prev = NULL;
	head = temp;
	tail = temp;
}

template <class T>
void list<T>::push(T number) //добавление в начало
{
	if (head != NULL)
	{
		node<T>* temp = new node<T>;
		temp->data = number;
		temp->prev = NULL;
		temp->next = head;
		head->prev = temp;
		head = temp;
		counter++;
	}
	else
	{
		this->create(number);
		counter = 1;
	}
}

template <class T>
void list<T>::pushToTail(T number) //добавление в конец 
{
	node<T>* temp = new node<T>;
	temp->data = number;
	temp->prev = tail;
	temp->next = NULL;
	tail->next = temp;
	tail = temp;
	counter++;
}

template <class T>
void list<T>::show() // вывод на экран
{
	node<T>* temp = head;
	if (head == NULL) cout << "Стек пуст!" << endl;
	int i = 1;
	while (temp != NULL)
	{
		cout << '|' << setw(2) << i << temp->data << endl;
		temp = temp->next;
		i++;
	}
}

template <class T>
void list<T>::pop() //удаление
{
	if (head == NULL) return;
	node<T>* temp = head;
	head = head->next;
	delete[] temp;
	counter--;
}

template <class T>
bool list<T>::empty() // проверка на наличие элементов
{
	if (head == NULL)
		return true;
	else
		return false;
}

template <class T>
void list<T>::deleteCertainNode(int number) //удаление конкретного элемента
{
	node<T>* temp = head;
	node<T>* prev = NULL, * next = NULL;
	if (head == NULL)
	{
		cout << "Стек пуст!" << endl;
		cout << endl;
		return;
	}
	int i = 0;
	while (temp != NULL)
	{
		if (i == number)
		{
			counter--;
			if (temp->prev == NULL)
			{
				head = head->next;
				delete temp;
				return;
			}
			if (temp->next == NULL)
			{
				tail = tail->prev;
				tail->next = NULL;
				delete temp;
				return;
			}
			if ((temp->next != NULL) && (temp->prev != NULL))
			{
				prev = temp->prev;
				next = temp->next;
				prev->next = next;
				next->prev = prev;
				delete temp;
				return;
			}
		}
		temp = temp->next;
		i++;
	}
}

template <class T>
void list<T>::swap(int first, int second) //обмен двух элементов местами
{
	int i = 0;
	node<T>* temp_first = head;
	node<T>* temp_second = head;
	node<T>* prev1, * prev2, * next1, * next2;
	while (i < first)
	{
		temp_first = temp_first->next;
		i++;
	}
	i = 0;
	while (i < second)
	{
		temp_second = temp_second->next;
		i++;
	}

	prev1 = temp_first->prev;
	prev2 = temp_second->prev;
	next1 = temp_first->next;
	next2 = temp_second->next;
	if (temp_second == next1)
	{
		temp_second->next = temp_first;
		temp_second->prev = prev1;
		temp_first->next = next2;
		temp_first->prev = temp_second;
		if (next2 != NULL)
			next2->prev = temp_first;
		if (temp_first != head)
			prev1->next = temp_second;
	}
	else if (temp_first == next2)
	{
		temp_first->next = temp_second;
		temp_first->prev = prev2;
		temp_second->next = next1;
		temp_second->prev = temp_first;
		if (next1 != NULL)
			next1->prev = temp_second;
		if (temp_second != head)
			prev2->next = temp_first;
	}
	else
	{
		if (temp_first != head)
			prev1->next = temp_second;
		temp_second->next = next1;
		if (temp_second != head)
			prev2->next = temp_first;
		temp_first->next = next2;
		temp_second->prev = prev1;
		if (next2 != NULL)
			next2->prev = temp_first;
		temp_first->prev = prev2;
		if (next1 != NULL)
			next1->prev = temp_second;
	}
	if (temp_first == head)
	{
		head = temp_second;
		return;
	}
	if (temp_second == head)
	{
		head = temp_first;
	}
}
/*
template <class T>
void list<T>::sort()
{
	node<T>* temp = head;
	int i = 0;
	while (temp->next != NULL)
	{
		if (temp->data > temp->next->data)
		{
			swap(i, i + 1);
			sort();
		}
		else
			temp = temp->next;
		i++;
		if (i >= counter)
			return;
	}
}

template <class T>
void list<T>::secondSort()
{
	node<T>* temp = head;
	int i = 0;
	while (temp->next != NULL)
	{
		if (temp->data < temp->next->data)
		{
			swap(i, i + 1);
			secondSort();
		}
		else
			temp = temp->next;
		i++;
		if (i >= counter)
			return;
	}
}*/

template <class T>
void list<T>::search()
{
	node<T>* temp = head;
	if (head == NULL)
	{
		cout << "Стек пуст!" << endl;
		return;
	}
	cout << endl;

	bool header = false;
	T search_object;
	search_object.searchInstance();

	while (temp != NULL)
	{
		if (search_object == temp->data)
		{
			if (header == false)
			{
				search_object.header();
				header = true;
			}
			cout << '|' << setw(2) << "--" << temp->data << endl;
		}
		temp = temp->next;
	}
}

template <class T>
void list<T>::write(string str)
{
	ofstream out(str, ios::out);
	node<T>* node = head;
	while (node)
	{
		out << node->data;
		node = node->next;
	}
	out.close();
}


template <class T>
void list<T>::read(string str)
{
	T subscr;
	ifstream in;
	in.open(str, ios::in);
	while (in >> subscr)
		this->push(subscr);
	in.close();
}

template <class T>
void list<T>::edit(int number)
{
	node<T>* temp = head;
	if (head == NULL)
	{
		cout << "Стек пуст!" << endl;
		cout << endl;
		return;
	}
	int i = 0;
	while (temp != NULL)
	{
		if (i == number)
		{
			temp->data.edit();
			return;
		}
		temp = temp->next;
		i++;
	}
}