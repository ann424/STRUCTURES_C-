// Bank_client : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Bank_Client
{
	string fio;
	string bank_type;
	string account_number;
	double money;
	int data[9];
	
};

void Input(Bank_Client*, int);
int Size();
void View(Bank_Client&);
void Task(Bank_Client*, int);

int main()
{
	setlocale(LC_ALL, "RU");

	Bank_Client* array;
	int size, i;

	size = Size();

	array = new Bank_Client[size];

	Input(array, size);

	cout << "\nДанные о клиенте банка:\n";
	for (i = 0; i < size; i++)
		View(array[i]);

	Task(array, size);

	delete[]array;
	array = NULL;

	return 0;
}

void Input(Bank_Client* array, int size)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		cout << "\nВведите " << i + 1 << " клиента банка:\n";
		cout << "\nВведите ФИО:\n";
		rewind(stdin);
		getline(cin, array[i].fio);

		cout << "\nВведите тип счета:\n";
		rewind(stdin);
		cin >> array[i].bank_type;

		cout << "\nВведите номер счета:\n";
		rewind(stdin);
		cin >> array[i].account_number;

		cout << "\nВведите сумму на счете (BYN):\n";
		rewind(stdin);
		cin >> array[i].money;

		cout << "\nВведите дату последнего изменения:\n";
		rewind(stdin);
		cout << "Число:";
		for (j = 0; j < 3; j++)
		{
			switch (j)
			{
			case 1:
					cout << "Месяц:";
					break;
			case 2:
					cout << "Год:";
			}
			cin >> array[i].data[j];
		}
	}
}

int Size()
{
	int size;

	do
	{
		cout << "Введите количество структур:\n";
		cin >> size;
	} while (size < 1 && size>100);

	return size;
}

void View(Bank_Client& bank_client)
{
	int j;

	cout << setw(15) << bank_client.fio
		<< setw(15) << bank_client.bank_type
		<< setw(15) << bank_client.account_number
		<< setw(15) << bank_client.money<<" BYN" << setw(15);

	for (j = 0; j < 3; j++)
	{
		if (j <= 1)
			cout << bank_client.data[j] << ". ";
		else
			cout << bank_client.data[j];
	}
}

void Task(Bank_Client* array, int size)
{
	int i, j, min, max;
	bool flag;

	flag = false;
	cout << "\nВведите диапазон суммы" << endl;
	cout << "от ";
	cin >> min;
	cout << "\nдо ";
	cin >> max;

	for (i = 0; i < size; i++)
	{
		if (array[i].money >= min && array[i].money <= max)
		{
			if (!flag)
			{
				flag = true;
				cout << "Клиенты банка, с суммой на счету, входящей в заданный диапазон:" << endl;
			}
			View(array[i]);
		}
	}
		if (!flag)
			cout << "\nТаких клиентов нет.\n";
}
