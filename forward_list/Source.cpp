#include <iostream>
using namespace std;


struct Element
{
	// Данные
	char data;
	// Адрес следующего элемента списка
	Element* Next;
};

// Односвязный список
class List
{
	// Адрес головного элемента списка
	Element* Head;
	// Адрес головного элемента списка
	Element* Tail;
	// Количество элементов списка
	int Count;

public:
	// Конструктор
	List();
	// Деструктор
	~List();

	// Добавление элемента в список
	// (Новый элемент становится последним)
	void Add(char data);
	void AddToPosition(char data, int index);
	void DeleteFromPosition(int index);
	void Del();
	void DelAll();
	int FindElem(char symb);
	// Распечатка содержимого списка
	// (Распечатка начинается с головного элемента)
	void Print();

	// Получение количества элементов, находящихся в списке
	int GetCount();
};

List::List()
{
	// Изначально список пуст
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	// Вызов функции удаления
	DelAll();
}

int List::GetCount()
{
	// Возвращаем количество элементов
	return Count;
}

void List::Add(char data)
{
	// создание нового элемента
	Element* temp = new Element;
	// заполнение данными
	temp->data = data;
	// следующий элемент отсутствует
	temp->Next = NULL;
	// новый элемент становится последним элементом списка
	// если он не первый добавленный
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	// новый элемент становится единственным
	// если он первый добавленный
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
	// запоминаем адрес головного элемента
	Element* temp = Head;
	// перебрасываем голову на следующий элемент
	Head = Head->Next;
	// удаляем бывший головной элемент
	delete temp;
}

void List::DelAll()
{
	// Пока еще есть элементы
	while (Head != 0)
		// Удаляем элементы по одному
		Del();
}

void List::Print()
{
	// запоминаем адрес головного элемента
	Element* temp = Head;
	// Пока еще есть элементы
	while (temp != 0)
	{
		// Выводим данные
		cout << temp->data << " ";
		// Переходим на следующий элемент
		temp = temp->Next;
	}

	cout << "\n\n";
}

// Тестовый пример
void main()
{
	// Создаем объект класса List
	List lst;

	// Тестовая строка
	char s[] = "Hello, World !!!\n";
	// Выводим строку
	// Определяем длину строки
	int len = strlen(s);
	// Загоняем строку в список
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	// Распечатываем содержимое списка
	lst.AddToPosition('a', 3);
	lst.Print();
	lst.DeleteFromPosition(8);
	lst.Print();
	cout << lst.FindElem('r');
	// Удаляем три элемента списка
	//Распечатываем содержимое списка
}

