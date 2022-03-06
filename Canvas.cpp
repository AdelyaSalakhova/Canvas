#include "Canvas.h"

Point::Point() : Primitive(1){
	x = 0;
	y = 0;
}

Point:: Point(int x1, int y1, COLORREF c) : Primitive(1) {
	color_circuit = c;
	x = x1;
	y = y1;
}

void Point::show(HDC hdc) {
	SetPixel(hdc, x, y, color_circuit);
}

Line::Line(int x1, int y1, int x2, int y2, COLORREF c) : Primitive(2) {
	color_circuit = c;
	p1.x = x1;
	p1.y = y1;
	p2.x = x2;
	p2.y = y2;
}

void Line::show(HDC hdc) {
	SelectObject(hdc, GetStockObject(DC_PEN));
	SetDCPenColor(hdc, color_circuit);
	MoveToEx(hdc, p1.x, p1.y, NULL);
	LineTo(hdc, p2.x, p2.y);
}

rectangle::rectangle(int x1, int y1, int x2, int y2, bool colored, COLORREF c) : Primitive(3) {
	color_circuit = c;
	background_color = c;
	this->colored = colored;
	rec_start_p.x = x1;
	rec_start_p.y = y1;
	rec_end_p.x = x2;
	rec_end_p.y = y2;
}

void rectangle::show(HDC hdc) {
	SelectObject(hdc, GetStockObject(DC_PEN)); 
	SetDCPenColor(hdc, color_circuit); 
	SetDCBrushColor(hdc, background_color); 
	if (colored) {
		SelectObject(hdc, GetStockObject(DC_BRUSH)); 
	}
	else {
    SelectObject(hdc, GetStockObject(NULL_BRUSH)); 
	}
	Rectangle(hdc, rec_start_p.x, rec_start_p.y, rec_end_p.x, rec_end_p.y);
}

ellipse :: ellipse(int x1, int y1, int x2, int y2, bool colored, COLORREF c) : Primitive(4) {
	color_circuit = c;
	background_color = c;
	this->colored = colored;
	elp_start_p.x = x1;
	elp_start_p.y = y1;
	elp_end_p.x = x2;
	elp_end_p.y = y2;
}

void ellipse :: show(HDC hdc) {
	SelectObject(hdc, GetStockObject(DC_PEN));
	SetDCPenColor(hdc, color_circuit);
	SetDCBrushColor(hdc, background_color);
	if (colored) {
		SelectObject(hdc, GetStockObject(DC_BRUSH));
	}
	else {
		SelectObject(hdc, GetStockObject(NULL_BRUSH));
	}
	Ellipse(hdc, elp_start_p.x, elp_start_p.y, elp_end_p.x, elp_end_p.y);
}

polygon::polygon (const POINT Points[6], bool colored, COLORREF c): Primitive(5) {
	this->colored = colored;
	color_circuit = c;
	background_color = c;
	Ippt = Points;
	Ippt1 = Points;
}

void polygon ::show(HDC hdc) {
	SelectObject(hdc, GetStockObject(DC_PEN));
	SetDCPenColor(hdc, color_circuit);
	SetDCBrushColor(hdc, background_color);
	if (colored) {
		SelectObject(hdc, GetStockObject(DC_BRUSH));
	}
	else {
		SelectObject(hdc, GetStockObject(NULL_BRUSH));
	}
	Polygon(hdc, Ippt, 6);
}

polygon :: ~polygon() {}

Canvas::Canvas() {
	hWnd = GetConsoleWindow(); 
	GetWindowRect(hWnd, &bufferSize);
	MoveWindow(hWnd, bufferSize.left, bufferSize.top, 800, 800, TRUE);
	hdc = GetDC(hWnd);
}

Canvas :: ~Canvas() {
	ReleaseDC(hWnd, hdc);
	PrimitivesList.clear();
}

void Canvas:: AddObject(Primitive*obj) {
	PrimitivesList.push_back(obj);
}

void Canvas::DeleteObject(int Number) {
	PrimitivesList.erase(PrimitivesList.begin() + (Number - 1));
}

void Canvas::ListClering() {
	PrimitivesList.clear();
}

void Canvas::GetInfo() {
	for (int i = 0; i < PrimitivesList.size(); i++) {
		switch (PrimitivesList.at(i)->type)
		{
		case 1: {
			Point* pptr1 = (Point*)PrimitivesList.at(i);
			std::cout <<"Point (" << pptr1->x << ", " << pptr1->y << ")" << std::endl;
			break;
		}
		case 2: {
			Line* pptr2 = (Line*)PrimitivesList.at(i);
			std::cout <<"Line (" << pptr2->p1.x << ", " << pptr2->p1.y << ", " << pptr2->p2.x << "; " << pptr2->p2.y << ")" << std::endl;
			break;
		}
		case 3: {
			rectangle* pptr3 = (rectangle*)PrimitivesList.at(i);
			std::cout <<"Rectangle (" << pptr3->rec_start_p.x << ", " << pptr3->rec_start_p.y << "; " << pptr3->rec_end_p.x << ", " << pptr3->rec_end_p.y << ")" << std::endl;
			break;
		}
		case 4: {
			ellipse* pptr4 = (ellipse*)PrimitivesList.at(i);
			std::cout << "Ellipse (" << pptr4->elp_start_p.x << ", " << pptr4->elp_start_p.y << "; " << pptr4->elp_end_p.x << ", " << pptr4->elp_end_p.y << ")" << std::endl;
			break;
		}
		case 5: {
			polygon* pptr5 = (polygon*)PrimitivesList.at(i);
			std::cout << "Polygon (";
			for (int j = 0; j < 6; j++) {
				if (j != 5) {
					std::cout << pptr5->Ippt1->x << ", ";
					std::cout << pptr5->Ippt1->y << "; ";
					pptr5->Ippt1++;
				}
				else {
					std::cout << pptr5->Ippt1->x << ", ";
					std::cout << pptr5->Ippt1->y;
					pptr5->Ippt1++;
				}
			}
			std::cout << ")" << std::endl;
			pptr5->Ippt1 = pptr5->Ippt;
			break;
		    }
	    }
   }
}

void Canvas::Show() {
	for (int i = 0; i < PrimitivesList.size(); i++) {
		PrimitivesList[i]->show(hdc);
	}
}

Primitive::Primitive(int type) { this->type = type; }

void Primitive :: show (HDC hdc) {}
