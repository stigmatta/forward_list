#include <iostream>
using namespace std;


struct Element
{
	// ������
	char data;
	// ����� ���������� �������� ������
	Element* Next;
};

// ����������� ������
class List
{
	// ����� ��������� �������� ������
	Element* Head;
	// ����� ��������� �������� ������
	Element* Tail;
	// ���������� ��������� ������
	int Count;

public:
	// �����������
	List();
	// ����������
	~List();

	// ���������� �������� � ������
	// (����� ������� ���������� ���������)
	void Add(char data);
	void AddToPosition(char data, int index);
	void DeleteFromPosition(int index);
	void Del();
	void DelAll();
	int FindElem(char symb);
	// ���������� ����������� ������
	// (���������� ���������� � ��������� ��������)
	void Print();

	// ��������� ���������� ���������, ����������� � ������
	int GetCount();
};

List::List()
{
	// ���������� ������ ����
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	// ����� ������� ��������
	DelAll();
}

int List::GetCount()
{
	// ���������� ���������� ���������
	return Count;
}

void List::Add(char data)
{
	// �������� ������ ��������
	Element* temp = new Element;
	// ���������� �������
	temp->data = data;
	// ��������� ������� �����������
	temp->Next = NULL;
	// ����� ������� ���������� ��������� ��������� ������
	// ���� �� �� ������ �����������
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	// ����� ������� ���������� ������������
	// ���� �� ������ �����������
	else {
		Head = Tail = temp;
	}
	Count++;
}
int List::FindElem(char symb)
{
	Element* count = Head;
	for (int i = 0; i < Count; i++)
	{
		if (count->Next->data == symb)
			return i;
		else
			count = count->Next;
	}


	return NULL;
}

void List::AddToPosition(char data, int index)
{
	Element* count = Head;
	Element* temp = new Element;
	temp->data = data;
	temp->Next = NULL;
	if (index == 0)
	{
		if (Tail == NULL)
			Head = Tail = temp;
		else
		{
			temp->Next = Head;
			Head = temp;
		}
	}
	else if (index > Count)
	{
		cout << "No element exists" << endl;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
		{
			cout << count->data;
			count = count->Next;
		}
		cout << count->data << endl;
		temp->Next = count->Next;
		count->Next = temp;
		if (index == Count)
			Tail = temp;
	}
	Count++;
}
void List::DeleteFromPosition(int index)
{
	Element* count = Head;
	if (index == 0)
	{
		if (Tail == NULL)
			cout << "You have no elements to delete" << endl;
	}
	else if (index > Count)
		cout << "No element exists" << endl;
	else
	{
		for (int i = 0; i < index - 1; i++)
		{
			count = count->Next;
		}
		Element* temp = count->Next;
		count->Next = temp->Next;
	}
	Count--;
}
void List::Del()
{
	// ���������� ����� ��������� ��������
	Element* temp = Head;
	// ������������� ������ �� ��������� �������
	Head = Head->Next;
	// ������� ������ �������� �������
	delete temp;
}

void List::DelAll()
{
	// ���� ��� ���� ��������
	while (Head != 0)
		// ������� �������� �� ������
		Del();
}

void List::Print()
{
	// ���������� ����� ��������� ��������
	Element* temp = Head;
	// ���� ��� ���� ��������
	while (temp != 0)
	{
		// ������� ������
		cout << temp->data << " ";
		// ��������� �� ��������� �������
		temp = temp->Next;
	}

	cout << "\n\n";
}

// �������� ������
void main()
{
	// ������� ������ ������ List
	List lst;

	// �������� ������
	char s[] = "Hello, World !!!\n";
	// ������� ������
	// ���������� ����� ������
	int len = strlen(s);
	// �������� ������ � ������
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	// ������������� ���������� ������
	lst.AddToPosition('a', 3);
	lst.Print();
	lst.DeleteFromPosition(8);
	lst.Print();
	cout << lst.FindElem('r');
	// ������� ��� �������� ������
	//������������� ���������� ������
}

