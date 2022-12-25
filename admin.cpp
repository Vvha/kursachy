#include "admin.h"
// просмотр списка
void Admin::Obs_list(NODE* top)
{
	obs_list(top);
}
// добавление новой записи
void Admin::Add(NODE*& top)
{
	DATA data;
	int c = 0;
	int num;
	string word;
	do {
		switch (c) {
		case 0:
			cout << "Номер поезда: ";
			cin >> num;
			data.tr_num = num;
			break;
		case 1:
			cout << "Пункт отправления: ";
			cin >> word;
			data.dest_place = word;
			break;
		case 2:
			cout << "Дата отправления: ";
			cin >> word;
			data.datedep = ConvertStD(word);
			break;
		case 3:
			cout << "Время отправления: ";
			cin >> word;
			data.timedep = ConvertStT(word);
			break;
		case 4:
			cout << "Время прибытия: ";
			cin >> word;
			data.timearr = ConvertStT(word);
			break;
		case 5:
			cout << "цена билета: ";
			cin >> num;
			data.tick_cost = num;
			break;
		case 6:
			cout << "Количество оставшихся: ";
			cin >> num;
			data.tick_left = num;
			break;
		case 7:
			cout << "Количество купленых: ";
			cin >> num;
			data.tick_sold = num;
			break;
		default:
			break;
		}
		c++;
	} while (c != 7);
	append(top, data);
	cout << "Запись успешно добавлена в список!";
}
// удаление записи
void Admin::Del(NODE*& top, int ind)
{
	NODE* p = find(top, ind);
	if (!p) {
		cout << "поезда с Таким номером нет!";
		return;
	}
	if (p->data.id == 1) pop_head(top);
	else {
		p = findById(top, p->data.id - 1);
		if (!p) return;
		pop_after(p);
	}
	reset(top);
	cout << "Запись успешно удалена из списка!";
}
// изменение записи
void Admin::Edit(NODE*& top, int id)
{
	NODE* temp = find(top, id);
	if (!temp) { cout << "Такого рейса нет!"; return; }
	cout << "0. Рейс\n1. Тип\n2. Место прибытия\n3. Дата вылета\n4. Время вылета\n5. Время прибытия\n7. Бизнес класс\n8. Цена бизнес\n9. Эконом\n10. Цена эконом\n";
	int choice, num;
	cin >> choice;
	string word;
	switch (choice) {
	case 0:
		cin >> num;
		temp->data.tr_num = num;
		break;
	case 1:
		cin >> word;
		temp->data.dest_place = word;
		break;
	case 2:
		cin >> word;
		temp->data.datedep = ConvertStD(word);
		break;
	case 3:
		cin >> word;
		temp->data.timedep = ConvertStT(word);
		break;
	case 4:
		cin >> word;
		temp->data.timearr = ConvertStT(word);
		break;
	case 5:
		cin >> num;
		temp->data.tick_cost = num;
		break;
	case 6:
		cin >> num;
		temp->data.tick_left = num;
		break;
	case 7:
		cin >> num;
		temp->data.tick_sold = num;
		break;
	default:
		break;
	}

	cout << "Запись успешно изменена!";
}
