#include "call_list.h"
#include "user.h"
#include "admin.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream file("..\\..\\list.txt");
	if (!file) { cout << "���� ����!\n"; }
	else {
		NODE* list;
		download(list, file);
		int choice;
		do {
			system("cls");// ����� ����� ��� ����
			cout << "1. �������������\n2. ������������\n9. �����\n";
			cin >> choice;
			switch (choice)
			{
	/* ������������� */
			case 1:
				Admin admin; // �������� ������� admin
				//���� ������
				while (1) {
					system("cls");
					cout << "___________________ ������������� ___________________\n";
					cout << "1. ��������\n";
					cout << "2. �������\n";
					cout << "3. ��������\n";
					cout << "4. ������� �������\n";
					cout << "0. �����\n";
					int ch;
					cin >> ch;
					if (ch == 0) break;
					system("cls");
			/* �������� */
					switch (ch)
					{
					case 1:
						cout << "___________________ ���������� � ������ ___________________\n";
						admin.Add(list);
						break;
					case 2:
						cout << "___________________ �������� �� ������ ___________________\n";
						if (!list) {
							cout << "������ ����!";
							break;
						}
						int id;
						cout << "������� ����� ������, ������� ������ �������: ";
						cin >> id;
						admin.Del(list, id);
						break;
					case 3:
						cout << "___________________ ��������� ������ ___________________\n";
						int ind;
						while (1) {
							system("cls");
							cout << "������� ���������� ����� �����, ������� ������ ��������: ";
							cin >> ind;
							if (ind < 1 || ind > list->data.count) {
								cout << "������������ ����!";
							}
							else break;
						}
						admin.Edit(list, ind);
						break;
					case 4:
						cout << "___________________ ������� ������� ___________________\n";
						admin.Obs_list(list);
						system("pause");
						break;
					default:
						cout << "������������ �����!";
						Sleep(700);
						break;
					}
					Sleep(1000);
				}
				break;
	/* ������������ */
			case 2:
				User user;
				while (1) {
					system("cls");
					cout << "___________________ ������������ ___________________\n";
					cout << "1. ������� �������\n";
					cout << "2. �����\n";
					cout << "3. ����������\n";
					cout << "4. �������������� ������� \n";
					cout << "0. �����\n";
					int ch;
					cin >> ch;
					if (ch == 0) break;
					system("cls");
			/* �������� */
					switch (ch)
					{
					case 1:
						cout << "___________________ ������� ������� ___________________\n";
						user.Obs_list(list);
						system("pause");
						break;
					case 2:
						cout << "___________________ ����� ___________________\n1. �� �������\n2. �� ������ ��������";
						int chh;
						cin >> chh;
						if (chh == 1)
							user.searchByName(list);
						else
							user.searchByNumber(list);
						system("pause");
						break;
					case 3:
						cout << "___________________ ���������� ___________________\n1. �� ����\n2. �� ������������\n3. �� �������\n";
						int ch;
						cin >> ch;
						if(ch == 1) user.SortByDate(list);
						else if (ch == 2)  user.SortByDuration(list);
						else if (ch == 3) user.SortBySurname(list);
						std::cout << "������ �����������!";
						break;
					case 4:
						cout << "___________________ �������������� ������� ___________________\n";
						user.outCalls(list);
						system("pause");
						break;
					default:
						cout << "������������ �����!";
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