#include <stdio.h>
#include <iostream>
#include <time.h>
#include <locale.h>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int kart[5], mast[5];
	
	start:
	system("cls");

	//Выводим 5 карт
	cout << "Ваши карты:" << endl<<endl;

	/*kart[0] = 11;
	kart[1] = 10;
	kart[2] = 14;
	kart[3] = 12;
	kart[4] = 13;

	mast[0] = 2;
	mast[1] = 2;
	mast[2] = 2;
	mast[3] = 2;
	mast[4] = 2;*/
	
	for (int i = 0; i < 5; i++)
	{
	MK:
		mast[i] = 0 + rand() % 3;
		kart[i] = 2 + rand() % 13;
		/*for (int j = 1; j <= i; j++)
		{
			if ((mast[j] == mast[i-1]) && (kart[j] == kart[i-1])) goto MK;
			else
			{
				mast[i] = mast[i];
				kart[i] = kart[i];
			}
		}*/
		if (kart[i] == 2)cout << "2\t";
		else if (kart[i] == 3)cout << "3\t";
		else if (kart[i] == 4)cout << "4\t";
		else if (kart[i] == 5)cout << "5\t";
		else if (kart[i] == 6)cout << "6\t";
		else if (kart[i] == 7)cout << "7\t";
		else if (kart[i] == 8)cout << "8\t";
		else if (kart[i] == 9)cout << "9\t";
		else if (kart[i] == 10)cout << "10\t";
		else if (kart[i] == 11)cout << "Валет\t";
		else if (kart[i] == 12)cout << "Дама\t";
		else if (kart[i] == 13)cout << "Король\t";
		else if (kart[i] == 14)cout << "Туз\t";
		if (mast[i] == 0) cout << "пики" << endl;
		else if (mast[i] == 1) cout << "треф" << endl;
		else if (mast[i] == 2) cout << "буби" << endl;
		else if (mast[i] == 3) cout << "черви" << endl;
	}	
	cout << endl;
	//Создание массива kart1 копия kart
	int kart1[5];

	for (int i = 0; i < 5; i++)
	{
		kart1[i] = kart[i];
	}
	//Сортировка массива kart1 по возрастанию
	int prom;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5 - 1; j++) {
			if (kart1[j] > kart1[j + 1]) {
				prom = kart1[j];
				kart1[j] = kart1[j + 1];
				kart1[j + 1] = prom;
			}
		}
	}
	//Проверка на флеш
	int flush = 1;
	for (int i = 1; i < 5; i++)
	{
		if (mast[i] == mast[i - 1])flush++;
	}
	//Проверка на стрит
	int str = 1;
	for (int i = 1; i < 5; i++)
	{
		if (kart1[i] == kart1[i - 1] + 1)str++;
	}
	//Вывод результата: Роял-флеш или стрит-флеш или флеш или стрит
	if ((str == 5) && (flush == 5) && (kart1[0] == 10))cout << "У Вас роял-флеш \n";
	else
	{
		if ((str == 5) && (flush == 5))
		{
			cout << "У Вас стрит-флеш \n";
		}
		else
		{
			if (str == 5)
			{
				cout << "У Вас стрит \n";
			}
			if (flush == 5)
			{
				cout << "У Вас флеш \n";
			}
		}
	}
	int	kol=0;
	//Поиск в массиве парных карт
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == j) goto SLED;
			if (kart[j] == kart[i]) kol++;
		SLED:
			cout << "";
		}
	}
	//Вывод результата: Фул-хаус или каре или сет или пара или две пары
	if (kol == 2)
	{
		if(flush!=5) cout << "У Вас пара \n";
	}
	else if (kol == 6)
	{
		if (flush != 5)cout << "У Вас сет \n";
	}
	else if (kol == 4)
	{
		if (flush != 5)cout << "У Вас две пары \n";
	}
	else if (kol == 12)
	{
		cout << "У Вас каре \n";
	}
	else if (kol == 8)
	{
		cout << "У Вас фул-хаус \n";
	}
	else
	{
		if((kart1[4]==14) && (flush != 5))cout << "У Вас старшая карта туз"<< endl;
		else if ((kart1[4] == 13) && (flush != 5))cout << "У Вас старшая карта король" << endl;
		else if ((kart1[4] == 12) && (flush != 5))cout << "У Вас старшая карта дама" << endl;
		else if ((kart1[4] == 11) && (flush != 5))cout << "У Вас старшая карта валет" << endl;
		else if (flush != 5) cout << "У Вас старшая карта " << kart1[4] << endl;
	}
	cout << endl << "Нажмите на 1 и enter, для пересдачи карт ";
	int n;
	cin >> n;
	if (n == 1)goto start;
}

	