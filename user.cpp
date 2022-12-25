#include "user.h"
// реализация полей
void User::Obs_list(NODE* top)
{
	obs_list(top);
}
// поиск по номеру поезда
void User::searchByNum(NODE* top)
{
	cout << "Введите номер поезда: ";
	int num;
	cin >> num;
	cout << "--------------------------------------------------------------\n";
	NODE* p = find(top, num);
	if (!p) { cout << "Такого поезда нет!\n"; return; }
	show(p);
}
// поиск всех поездов, которые идут в введённый город
void User::searchByDest(NODE* top)
{
	string ss;
	cout << "Введите город: ";
	cin >> ss;
	cout << "--------------------------------------------------------------\n";
	NODE* p = top;
	while (p) {
		if (p->data.dest_place.find(ss) != string::npos) show(p);
		p = p->GetNext();
	}
}
// сортировка по дате
void User::SortByDate(NODE*& top)
{
	if (empty(top)) return;
	NODE* a, *b, *p, *h = NULL;

	for (NODE* i = top; i != NULL; ) {
		a = i;
		i = i->GetNext();
		b = h;
		for (p = NULL; (b != NULL) && (a->data.datedep < b->data.datedep); ) {
			p = b;
			b = b->GetNext();
		}
		if (p == NULL) {
			a->SetNext(h);
			h = a;
		}
		else {
			a->SetNext(b);
			p->SetNext(a);
		}
	}
	if (h != NULL)
		top = h;
	reset(top);

	std::cout << "Список отсортиован!";
}
// покупка билета
void User::BuyTicket(NODE*& top)
{
	int num;
	cout << "Введите номер поезда: ";
	cin >> num;
	NODE* p = find(top, num);
	if (!p) { cout << "Такого поезда нет!"; return; }
	if (!p->data.tick_left) { cout << "Билетов на данный поезд нет в наличии!"; return; }
	printf("Стоимость билета: %i\nОсталось - %i\n", p->data.tick_cost, p->data.tick_left);
	cout << "Купить билет 0/1 - ";
	cin >> num;
	if (num) {
		cout << "Введите количество билетов: ";
		for (;;) {
			cin >> num;
			if (num > p->data.tick_left) {
				cout << "Такого количества билетов нет в наличии!\nВведите другое число: ";
				continue;
			}
			p->data.tick_left -= num;
			p->data.tick_sold += num;
			break;
		}
		cout << "Билеты успешно куплены!";
	}
}

void User::showRange(NODE* top)
{
	NODE* p = top;
	string str, city;
	int a, b;
	cout << "Введите город: ";
	cin >> city;
	cout << "Ввод диапазона дат. Формат: 00.00\nОт: ";
	cin >> str;
	a = ConvertStD(str);
	cout << "До: ";
	cin >> str;
	b = ConvertStD(str);

	while (p) {
		if (p->data.dest_place.find(city) != string::npos && p->data.datedep > a && p->data.datedep < b) {
			show(p);
		}
		p = p->GetNext();
	}
}

