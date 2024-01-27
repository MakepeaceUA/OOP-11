#include <iostream>
#include <Windows.h>
using namespace std;

struct Element
{
	char data;
	Element* Next;
};
class List
{
	Element* Head;
	Element* Tail;
	int Count;
public:
	List();
	~List();
	void Add(char symbol);
	void Del();
	void DelAll();
	void AddHead(char symbol);
	void Print();
	int GetCount();
	void GetElem(int position);
};
List::List()
{
	Head = Tail = NULL;
	Count = 0;
}
List::~List()
{
	DelAll();
}
int List::GetCount()
{
	return Count;
}
void List::Add(char symbol)
{
	Element* temp = new Element;
	temp->data = symbol;
	temp->Next = NULL;
	if (Head != NULL)
	{
		Tail->Next = temp;
		Tail = temp;
	}
	else
	{
		Head = Tail = temp;
	}
	Count++;
}
void List::Del()
{
	Element* temp = Head;
	Head = Head->Next;
	delete temp;
}

void List::DelAll()
{
	while (Head != 0)
		Del();
}
void List::AddHead(char symbol)
{
	Element* temp = new Element;
	temp->data = symbol;
	temp->Next = Head;
	if (Head != NULL)
	{
		Head = temp;
	}
	else
	{
		Tail = Head = temp;
	}
}

void List::GetElem(int position) 
{
	Element* temp = Head;
	if (position >= 0 && position < Count)
	{
		for (int i = 0; i < position; i++)
		{
			temp = temp->Next;
		}
		cout << temp->data << "\n";
	}
	else
	{
		cout << "Error\n";
	}
}
void List::Print()
{
	Element* temp = Head;
	while (temp != 0)
	{
		cout << temp->data << " ";
		temp = temp->Next;
	}
	cout << "\n\n";
}


void main()
{
	List lst;
	char s[] = "Hello, World !!!";
	cout << s << "\n\n";
	int len = strlen(s);
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	lst.Print();
	lst.Del();
	lst.Del();
	lst.Del();
	lst.Print();

	lst.AddHead('A');
	lst.AddHead('A');
	lst.AddHead('A');
	lst.Print();
	lst.GetElem(5);
}










