#include "Canvas.h"


using namespace std;

int main () {
	setlocale(LC_ALL, "Russian");

	Canvas obj;

	POINT pp[6]; // �������� ������������ �������, � ������������ ��������������.
	pp[0].x = 10; pp[0].y = 30; 
	pp[1].x = 20; pp[1].y = 20;
	pp[2].x = 30; pp[2].y = 30;
	pp[3].x = 30; pp[3].y = 50;
	pp[4].x = 20;  pp[4].y = 60;
	pp[5].x = 10;  pp[5].y = 50;

	polygon first_pol(pp, true, RGB(255, 0, 0)); // �������� ������� �������������. ��� - 5.
	rectangle first_rec(100, 100, 200, 200, true, RGB(0, 128, 0)); // �������� ������� �������������. ��� - 4.
	ellipse first_el(300, 300, 400, 400, true, RGB(255, 255, 0)); // �������� ������� ������. ��� - 3.
	Line first_line(40, 300, 70, 200, RGB(138, 43, 226)); // �������� ������� �����. ��� - 2.
	Line second_line(300, 40, 400, 50, RGB(0, 255, 255)); // �������� ������� �����. ��� - 2.

//{ ���������� �������� � ������.
	obj.AddObject((Primitive*)&second_line);
	obj.AddObject((Primitive*)&first_line);
	obj.AddObject((Primitive*)&first_pol);
	obj.AddObject((Primitive*)&first_rec);
	obj.AddObject((Primitive*)&first_el);
//}

	obj.GetInfo(); // ��������� ���������� �� �������� � ������.

	system("pause");
	system("cls");

	cout << "����� ������������ ����������� ����� ��� ������� 'p', ����� �� ��������� �� ������� 'e'." << endl;

	system("pause");
	system("cls");

	char iKey = 0; // ����� �����, ���������� � ������.
	while (iKey != 'e') { // ����� ������������ ����������� ����� ��� ������� 'p', ����� �� ��������� �� ������� 'e'.
			cin >> iKey;
			system("cls");
			switch (iKey) {
			case 112:
				obj.Show();
				break;
		    }
		
	}

	obj.DeleteObject(1); //�������� ������� ��� ������� 1.

	cout << "������ 1 - ����� - ������." << endl;

	system("pause");
	system("cls");

	obj.GetInfo(); //��������� ���������� ����� �������� ������� �������.

	system("pause");
	system("cls");

	iKey = 0; // ����� �����, ���������� � ������.
	while (iKey != 'e') { // ����� ������������ ����������� ����� ��� ������� 'p', ����� �� ��������� �� ������� 'e'.
		cin >> iKey;
		system("cls");
		switch (iKey) {
		case 112:
			obj.Show();
			break;
		}

	}
	return 0;
}