#ifndef CANVA_H
#define CANVA_H
#include <vector>
#include <iostream>
#include <istream>
#include <Windows.h>
#include <conio.h>

struct Primitive {
	int type;
	Primitive(int type);
	virtual void show(HDC hdc);
};

class Point : Primitive {
public :
	int x, y;
	COLORREF color_circuit;
	Point();
	Point(int x1, int y1, COLORREF c);
	void show(HDC hdc);
};

class Line : Primitive {
public:
	Point p1, p2;
	COLORREF color_circuit; 
	Line(int x1, int y1, int x2, int y2, COLORREF c);
	void show(HDC hdc);
};

class rectangle : Primitive {
public :
	bool colored;
	COLORREF color_circuit; 
	COLORREF background_color;
	Point rec_start_p, rec_end_p;
	rectangle(int x1, int y1, int x2, int y2, bool colored, COLORREF c);
	void show(HDC hdc);
};

class ellipse : Primitive {
public :
	bool colored;
	COLORREF color_circuit;  
	COLORREF background_color;
	Point elp_start_p, elp_end_p;
	ellipse(int x1, int y1, int x2, int y2, bool colored, COLORREF c);
	void show(HDC hdc);
};

class polygon : Primitive{
public:
	COLORREF color_circuit;
	COLORREF background_color;
	bool colored;
	const POINT* Ippt;
	const POINT* Ippt1;
	polygon(const POINT Points[6], bool colored, COLORREF c);
	void show(HDC hdc);
	~polygon();
};

class Canvas {
private:
	std :: vector <Primitive*> PrimitivesList;
	HWND hWnd;
    HDC hdc;
	RECT bufferSize;
public:
	Canvas();
	void AddObject(Primitive* obj2);
	void DeleteObject(int Number);
	void ListClering();
	void GetInfo();
	void Show();
	~Canvas();
};
#endif