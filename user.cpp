#include "user.h"
// реализация полей
void User::Obs_list(NODE* top)
{
	obs_list(top);
}
// поиск по Фамилии водителя
void User::searchByName(NODE* top)
{
	cout << "Введите Фамилию: ";
	string ss;
	cin >> ss;
	NODE* p = top;
	while (p) {
		// если подстрока не была найдена, в таком случае find() вернёт -1 = npos
		if (p->data.surname.find(ss) != string::npos) show(p);
		p = p->next;// переход на след элемент
	}
}
// поиск всех переговров, в которых участвовал введённый номер
void User::searchByNumber(NODE* top)
{
	string ss;
	cout << ": ";
	cin >> ss;// ввод символа
	NODE* p = top;
	while (p) {
		// если подстрока не была найдена, в таком случае find() вернёт -1 = npos
		// поиск происходит по двум полям номеров - адресата и адрестана вызова
		if (p->data.number.find(ss) != string::npos || p->data.call_number.find(ss) != string::npos) show(p);
		p = p->next;
	}
}

// сортировка по дате
void User::SortByDate(NODE*& top)
{
	if (!top) return;
	NODE* a, *b, *p, *h = NULL;

	for (NODE* i = top; i != NULL; ) {
		a = i;
		i = i->next;
		b = h;
		for (p = NULL; (b != NULL) && (a->data.call_date < b->data.call_date); ) {
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
// сортировка по длительности
void User::SortByDuration(NODE*& top)
{
	if (!top) return;
	NODE* a, * b, * p, * h = NULL;

	for (NODE* i = top; i != NULL; ) {
		a = i;
		i = i->next;
		b = h;
		for (p = NULL; (b != NULL) && (a->data.callduration < b->data.callduration); ) {
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
// сортировка по фамилии
void User::SortBySurname(NODE*& top) {
	if (!top) return;
	NODE* a, * b, * p, * h = NULL;

	for (NODE* i = top; i != NULL; ) {
		a = i;
		i = i->next;
		b = h;
		for (p = NULL; (b != NULL) && (a->data.surname > b->data.surname); ) {
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

void User::outCalls(NODE* top)
{
	SortBySurname(top);
	string temp;
	NODE* p = top;
	int from, to;
	cout << "Формат: 00:00\nС: ";
	cin >> temp;
	from = ConvertStT(temp);
	cout << "По: ";
	cin >> temp;
	to = ConvertStT(temp);
	for (;;) {
		int dur_sum = 0;
		string surname = p->data.surname;
		cout << endl << surname << " - " << p->data.number << endl;
		while (p) {
			if (p->data.surname != surname) break;
			/* тернарная условная операция : если начальное время промежутка > конца, то это значит что мы переходим 
			   через 00:00 (напрмер: 23:00 - 5:00) => должно быть условие, которое провряет такой промежуток: |------]-------[----|
			   иначе (5:00 - 23:00) - обычное зажатие в диапазон: |-----[------]----|
			   */
			if (from > to ? p->data.call_time >= from || p->data.call_time <= to : p->data.call_time >= from && p->data.call_time <= to) {
				if (p->data.calltype == "исходящий") {
					printf(" %-12s %-10s %-5s %-5s %-5s\n", p->data.call_number.c_str(), p->data.calltype.c_str(), ConvertDtS(p->data.call_date).c_str(), ConvertTtS(p->data.call_time).c_str(), ConvertTtS(p->data.callduration).c_str());
					dur_sum += p->data.callduration;
				}
			}
			p = p->next;
		}
		if (dur_sum != 0) cout << "\nСуммарное время переговоров: " << ConvertTtS(dur_sum) << endl;
		else cout << "\nУ данного водителя не было исходящих звонков в этот промежуток времени!\n";
		if (!p) break;
	}
}
