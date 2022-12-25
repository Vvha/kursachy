#include "vouchers.h"
#include "user.h"
#include "admin.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream file("..\\..\\list.txt");
	if (!file) { cout << "Файл пуст!\n"; }
	else {
		NODE* list;
		ReadFile(list, file);
		int choice;
		do {
			system("cls");// выбор админ или пользователь
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
					cout << "1. Просмотреть список путёвок\n";
					cout << "2. Добавить\n";
					cout << "3. Удалить\n";
					cout << "4. Изменить\n";
					cout << "0. Выход\n";
					int ch;
					cin >> ch;
					if (ch == 0) break;
					system("cls");
			/* Действия */
					switch (ch)
					{
					case 1:
						cout << "___________________ Cписок путёвок ___________________\n";
						admin.Obs_list(list);
						system("pause");
						break;
					case 2:
						cout << "___________________ Добавление В список ___________________\n";
						admin.Add(list);
						break;
					case 3:cout << "___________________ Удаление из списка ___________________\n";
						if (!list) {
							cout << "Список пуст!";
							break;
						}
						int id;
						cout << "Введите номер путёвки для удаления: ";
						cin >> id;
						admin.Del(list, id);
						break;
					case 4:
						cout << "___________________ Изменение записи ___________________\n";
						int ind;
						while (1) {
							system("cls");
							cout << "Введите номер путёвки, которую хотите изменить: ";
							cin >> ind;
							if (ind < 1 || ind > list->data.count) {
								cout << "Некорректный ввод!";
							}
							else break;
						}
						admin.Edit(list, ind);
						break;
					default:
						cout << "Некорректный ввод!";
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
					cout << "1. Просмотреть список путёвок\n";
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
						cout << "___________________ Cписок путёвок ___________________\n";
						user.Obs_list(list);
						system("pause");
						break;
					case 2:
						cout << "___________________ Поиск ___________________\n1. По Типу путёвки\n2. По типу питания";
						int chh;
						cin >> chh;
						if (chh == 1)
							user.searchByType(list);
						else
							user.searchByNutrition(list);
						system("pause");
						break;
					case 3:
						cout << "___________________ Сортировка ___________________\n1. По количеству дней\n2. По цене\n";
						int ch;
						do {
							cin >> ch;
							if (ch == 1) user.SortByDays(list);
							else if (ch == 2)  user.SortByCost(list);
							else cout << "Некорректный ввод";
						} while (ch != 1 && ch != 2);
						std::cout << "Список отсортиован!";
						break;
					case 4:
						cout << "______________________________ Выбор путевок по цене ______________________\n";
						user.showAll(list);
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