#include "user.h"
// реализация полей
void User::Obs_list(NODE* top)
{
	obs_list(top);
}
// поиск по типу путёвки
void User::searchByType(NODE* top)
{
	cout << "1. Отдых\n2. Лечение\n";
	size_t c;
	string ss;
	do {
		cin >> c;
		if (c == 1) ss = "отдых";
		else if (c == 2) ss = "лечение";
		else cout << "Некорректный ввод!\n";
	} while (c != 1 && c != 2);
	NODE* p = top;
	while (p) {
		// если подстрока не была найдена, в таком случае find() вернёт -1 = npos
		if (p->data.vouch_type.find(ss) != string::npos) show(p);
		p = p->next;// переход на след элемент
	}
}
// поиск всех переговров, в которых участвовал введённый номер
void User::searchByNutrition(NODE* top)
{
	int c;
	NODE* p = top;
	string ss;
	cout << "Введите тип питания:\n1. Завтрак\n2. Всё включено\n";
	do {
		cin >> c;
		if (c == 1) ss = "завтрак";
		else if (c == 2) ss = "всё включено";
		else cout << "Неверный ввод! Попробуйте снова\n";
	} while (c != 1 && c != 2);
	cout << ": ";
	cin >> ss;// ввод символа
	while (p) {
		// если подстрока не была найдена, в таком случае find() вернёт -1 = npos
		// поиск происходит по двум полям номеров - адресата и адрестана вызова
		if (p->data.nutrition.find(ss) != string::npos) show(p);
		p = p->next;
	}
}

// сортировка по дням
void User::SortByDays(NODE*& top)
{
	if (!top) return;
	NODE* a, *b, *p, *h = NULL;

	for (NODE* i = top; i != NULL; ) {
		a = i;
		i = i->next;
		b = h;
		for (p = NULL; (b != NULL) && (a->data.days_amount < b->data.days_amount); ) {
			p = b;
			b = b->next;
		}
		if (p == NULL) {
			a->next = h;
			h = a;
		}
		else {
			a->next = b;
			p->next = a;
		}
	}
	if (h != NULL)
		top = h;
	reset(top);

}
// сортировка по стоимости
void User::SortByCost(NODE*& top)
{
	if (!top) return;
	NODE* a, * b, * p, * h = NULL;

	for (NODE* i = top; i != NULL; ) {
		a = i;
		i = i->next;
		b = h;
		for (p = NULL; (b != NULL) && (a->data.cost < b->data.cost); ) {
			p = b;
			b = b->next;
		}
		if (p == NULL) {
			a->next = h;
			h = a;
		}
		else {
			a->next = b;
			p->next = a;
		}
	}
	if (h != NULL)
		top = h;
	reset(top);

}

void User::showAll(NODE*& top)
{
	SortByCost(top);
	NODE* temp = top;
	int c;
	string str;
	cout << "1. Отдых\n2. Лечение\n";
	do {
		cin >> c;
		if (c == 1) str = "отдых";
		else if (c == 2) str = "лечение";
		else cout << "Некорректный ввод!\n";
	} while (c != 1 && c != 2);
	cout << "Введите цену: ";
	cin >> c;
	int counter =0;
	while (temp) {
		if (temp->data.cost < c && temp->data.vouch_type == str) {
			counter++;
			show(temp);
		}
		temp = temp->next;
	}
	if (!counter) cout << "Путёвок типа " << str << " с заявленной ценой нет в наличии!\n";
}