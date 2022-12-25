#include "call_list.h"
#include "user.h"
#include "admin.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream file("..\\..\\list.txt");
	if (!file) { cout << "Файл пуст!\n"; }
	else {
		NODE* list;
		download(list, file);
		int choice;
		do {
			system("cls");// выбор админ или юзер
			cout << "1. Администратор\n2. Пользователь\n9. Выход\n";
			cin >> choice;
			switch (choice)
			{
	/* Администратор */
			case 1:
				Admin admin; // создание объекта admin
				//меню админа
				while (1) {
					system("cls");
					cout << "___________________ Администратор ___________________\n";
					cout << "1. Добавить\n";
					cout << "2. Удалить\n";
					cout << "3. Изменить\n";
					cout << "4. История звонков\n";
					cout << "0. Выход\n";
					int ch;
					cin >> ch;
					if (ch == 0) break;
					system("cls");
			/* Действия */
					switch (ch)
					{
					case 1:
						cout << "___________________ Добавление В список ___________________\n";
						admin.Add(list);
						break;
					case 2:
						cout << "___________________ Удаление из списка ___________________\n";
						if (!list) {
							cout << "Список пуст!";
							break;
						}
						int id;
						cout << "Введите номер поезда, который хотите удалить: ";
						cin >> id;
						admin.Del(list, id);
						break;
					case 3:
						cout << "___________________ Изменение записи ___________________\n";
						int ind;
						while (1) {
							system("cls");
							cout << "Введите порядковый номер рейса, который хотите изменить: ";
							cin >> ind;
							if (ind < 1 || ind > list->data.count) {
								cout << "Некорректный ввод!";
							}
							else break;
						}
						admin.Edit(list, ind);
						break;
					case 4:
						cout << "___________________ История звонков ___________________\n";
						admin.Obs_list(list);
						system("pause");
						break;
					default:
						cout << "Некорректный выбор!";
						Sleep(700);
						break;
					}
					Sleep(1000);
				}
				break;
	/* Пользователь */
			case 2:
				User user;
				while (1) {
					system("cls");
					cout << "___________________ Пользователь ___________________\n";
					cout << "1. История звонков\n";
					cout << "2. Поиск\n";
					cout << "3. Сортировка\n";
					cout << "4. Индивидуальное задание \n";
					cout << "0. Выход\n";
					int ch;
					cin >> ch;
					if (ch == 0) break;
					system("cls");
			/* Действия */
					switch (ch)
					{
					case 1:
						cout << "___________________ История зовнков ___________________\n";
						user.Obs_list(list);
						system("pause");
						break;
					case 2:
						cout << "___________________ Поиск ___________________\n1. По фамилии\n2. По номеру телефона";
						int chh;
						cin >> chh;
						if (chh == 1)
							user.searchByName(list);
						else
							user.searchByNumber(list);
						system("pause");
						break;
					case 3:
						cout << "___________________ Сортировка ___________________\n1. По дате\n2. По длительности\n3. По фамилии\n";
						int ch;
						cin >> ch;
						if(ch == 1) user.SortByDate(list);
						else if (ch == 2)  user.SortByDuration(list);
						else if (ch == 3) user.SortBySurname(list);
						std::cout << "Список отсортиован!";
						break;
					case 4:
						cout << "___________________ Индивидуальное задание ___________________\n";
						user.outCalls(list);
						system("pause");
						break;
					default:
						cout << "Некорректный выбор!";
						Sleep(1500);
						break;
					}
					Sleep(1500);
				}
				break;
			default:
				break;
			}
		} while (choice!=9);
	}
	return 0;
}