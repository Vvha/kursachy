#include "train.h"
#include "user.h"
#include "admin.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream file("list.txt");
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
					cout << "4. Просмотреть\n";
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
							if (ind < 1 || ind > list->data.total) {
								cout << "Некорректный ввод!";
							}
							else break;
						}
						admin.Edit(list, ind);
						break;
					case 4:
						cout << "___________________ Просмотр ___________________\n";
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
					cout << "1. Просмотреть\n";
					cout << "2. Поиск\n";
					cout << "3. Сортировка\n";
					cout << "4. Купить билет\n";
					cout << "4. Просмотр поездов\n";
					cout << "0. Выход\n";
					int ch;
					cin >> ch;
					if (ch == 0) break;
					system("cls");
			/* Действия */
					switch (ch)
					{
					case 1:
						user.Obs_list(list);
						system("pause");
						break;
					case 2:
						cout << "___________________ Поиск ___________________\n1. По номеру поезда\n2. По городу";
						int chh;
						cin >> chh;
						if (ch == 1)
							user.searchByNum(list);
						else
							user.searchByDest(list);
						system("pause");
						break;
					case 3:
						cout << "___________________ Сортировка ___________________\n";
						user.SortByDate(list);
						break;
					case 4:
						cout << "___________________ Покупка билета ___________________\n";
						user.BuyTicket(list);
						break;
					case 5:
						cout << "___________________ Просмотр поездов ___________________\n";
						user.showRange(list);
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