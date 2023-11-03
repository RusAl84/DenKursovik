#include <iostream>
#include <string>
#include <Windows.h>
#include <stdio.h>
#include <fstream>

using namespace std;

enum class sex : char { Women, Men, Any };  // пол студента
enum class markType : char { Fail, Pass, Excellent5, Good4, Satisfactory3, Bad2 }; // оценки за предмет
struct ExamsRecords {
	string name; // Название предмета
	enum class markType; // Оценка
	bool isEmpty; // заполнен ли слот?
};

struct StudentNode  // Структура студент
{
	char surName[30]; // Фамилия
	char name[30]; // Имя
	char middleName[30]; // Отчество
	char institute[30]; // Институт  (в задании факультет)
	char department[30]; // Кафедра
	char group[30]; // Группа	
	char recordСardNumber[30]; // Номер зачетной книжки
	char birthDateString[15]; // Дата рождения
	enum class sex sex; // Пол
	int startYear; // Год начала обучения
	ExamsRecords examsRecordsData[9][10]; // Оценки за сессию  9 сессий по 10 слотов под зачеты и экзамены
};

StudentNode addStudent() {
	StudentNode stud1;
	system("cls");
	cout << "Введите имя:" << endl;
	cin >> stud1.name;
	return stud1;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251);

	std::cout << "Курсовая работа!\n";
	//menu
	int selectedItem = -1;
	while (selectedItem != 0) {
		system("cls");
		cout << "Главное меню" << endl;
		cout << "0 - выйти из программы" << endl;
		cout << "1 - добавить данные о студенте" << endl;
		cout << "2 - вывести данные о студентах" << endl;
		cout << "3 - Выполнить задание" << endl;
		cout << "Введите цифру для выбора действия" << endl;
		cin >> selectedItem;
		switch (selectedItem) {
		case 0:
			break;
		case 1:{
			StudentNode stud1;
			stud1 = addStudent();
			FILE* binaryFile;
			fopen_s(&binaryFile, "binaryFile.txt", "w");
			fwrite(&stud1, sizeof(stud1), 1, binaryFile);
			fclose(binaryFile);
			break; 
		}
		case 2: {
			StudentNode stud1;
			FILE* binaryFile;
			fopen_s(&binaryFile, "binaryFile.txt", "rb");
			fread_s(&stud1, sizeof(stud1), sizeof(stud1), 1, binaryFile);
			fclose(binaryFile);
			system("cls");
			cout << "Список студентов" << endl;
			cout << "Имя студента:" << endl;
			cout << stud1.name << endl;
			break;
		}
		default:
			cout << "Выход из курсовой работы" << "\n";
			break;
		}
	}
}
