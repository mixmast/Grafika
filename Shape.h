#ifndef _SHAPE_
#define _SHAPE_

#include <wx/gdicmn.h>
#include <wx/dcclient.h>
#include <vector>
#include <string>
#include <algorithm>
#include "Functions.h"

//kazdy kontener ksztalt to typ i lista punktow wiec tu jest taki uniwersalny kontener na kazdy z nich
enum SHAPES_FLAG { CIRCLE = 100, TRIANGLE = 110, SQUARE = 120, ELLIPSE = 130, BROKEN_LINE = 140, CURVE_LINE = 150 };

class Shape {

public:
	Shape(int kind_of_shape = 0);
	explicit Shape(std::string code_txt); 
	
	int getKind();
	void setKind( int kind );
	bool isEmpty();
	
	bool isFilled();
	void setFilled(wxBrush x);
	void setUnFilled();

	void push_back(wxPoint& point);
	void pop_back();
	void clear();
	std::string txt_code();

	wxPoint& operator[] (unsigned int indeks);
	operator bool();
	wxBrush GetColour();
	wxColour GetLine();
	void SetLine(wxColour x);

private:
	bool _filled{ false };
	int _kind_of_shape{ 0 };
	std::vector<wxPoint> _points;
	wxBrush _fill=*wxTRANSPARENT_BRUSH;
	wxColour _line;
};


inline 	Shape::Shape(std::string code_txt) {

	int number;
	std::string element_from_string;
	std::vector<int> shape_desc;

	while (delete_element_from_string(code_txt, element_from_string) != "|") {
		number = stoi(element_from_string);
		shape_desc.push_back(number);
	}

	_filled = shape_desc[0];
	if (_filled) {
		wxColour f_color(shape_desc[1], shape_desc[2], shape_desc[3], shape_desc[4]);
		_fill.SetColour(f_color);
	}
	else
		_fill = wxBrush(*wxTRANSPARENT_BRUSH);
	_line = wxColour(shape_desc[5], shape_desc[6], shape_desc[7], shape_desc[8]);
	_kind_of_shape = shape_desc[9];

	for (int i = 10; i < shape_desc.size(); i += 2) {
		_points.push_back(wxPoint(shape_desc[i], shape_desc[i + 1]));
	}
}

inline void Shape::setKind( int kind ) {
	_kind_of_shape = kind;
}

inline bool Shape::isEmpty() {
	return _kind_of_shape == 0;
}

inline bool Shape::isFilled() {
	return _filled;
}

inline void Shape::setFilled(wxBrush x) {
	_filled = true;
	_fill = x;
}

inline void Shape::setUnFilled() {
	_filled = false;
}


inline Shape::Shape(int kind_of_shape) {
	_kind_of_shape = kind_of_shape;
}

inline int Shape::getKind() {
	return _kind_of_shape;
}

inline void Shape::push_back(wxPoint& point){
	_points.push_back(point);
}

inline void Shape::pop_back() {
	_points.pop_back();
}

inline void Shape::clear() {
	_points.clear();
	_filled = false;
	_kind_of_shape = 0;
}

inline wxPoint& Shape::operator[] (unsigned int indeks) {
	return _points[indeks];
}

inline  Shape::operator bool() {
	return _points.size() > 1;
}
inline wxBrush Shape::GetColour()
{
	return _fill;
}

inline wxColour Shape::GetLine()
{
	return _line;
}

inline void Shape::SetLine(wxColour x)
{
	_line = x;
}

//background-brightness isfill-rf-gf-bf-af-rl-gl-bl-al-kind-points|...
inline std::string Shape::txt_code() {

	double r = 0;
	int a = 0;
	std::string shape_code;

	if (isFilled()) {
		wxColour fill_color = _fill.GetColour();
		shape_code = "1 ";
		shape_code += std::to_string(fill_color.Red()) + " ";
		shape_code += std::to_string(fill_color.Green()) + " ";
		shape_code += std::to_string(fill_color.Blue()) + " ";
		shape_code += std::to_string(fill_color.Alpha()) + " ";
	}
	else {
		shape_code = "0 0 0 0 0 ";
	}

	wxColour line_color = _line;

	shape_code += std::to_string(line_color.Red()) + " ";
	shape_code += std::to_string(line_color.Green()) + " ";
	shape_code += std::to_string(line_color.Blue()) + " ";
	shape_code += std::to_string(line_color.Alpha()) + " ";

	shape_code += std::to_string(_kind_of_shape) + " ";

	switch (_kind_of_shape) {

	case CIRCLE:
		shape_code += std::to_string(static_cast<int>(_points[0].x )) + " " + std::to_string(static_cast<int>(_points[0].y ));
		shape_code += " ";
		shape_code += std::to_string(static_cast<int>(_points[1].x )) + " " + std::to_string(static_cast<int>(_points[1].y));
		shape_code += " ";
		break;

	case SQUARE:
		shape_code += std::to_string(static_cast<int>(_points[0].x)) + " " + std::to_string(static_cast<int>(_points[0].y));
		shape_code += " ";
		shape_code += std::to_string(static_cast<int>(_points[1].x)) + " " + std::to_string(static_cast<int>(_points[1].y));
		shape_code += " ";
		break;

	case ELLIPSE:
		shape_code += std::to_string(static_cast<int>(_points[0].x)) + " " + std::to_string(static_cast<int>(_points[0].y));
		shape_code += " ";
		shape_code += std::to_string(static_cast<int>(_points[1].x)) + " " + std::to_string(static_cast<int>(_points[1].y));
		shape_code += " ";
		break;

	case TRIANGLE:
		
		shape_code += std::to_string(static_cast<int>(_points[0].x)) + " " + std::to_string(static_cast<int>(_points[0].y));
		shape_code += " ";
		shape_code += std::to_string(static_cast<int>(_points[1].x)) + " " + std::to_string(static_cast<int>(_points[1].y));
		shape_code += " ";
		
		break;

	case CURVE_LINE:
		for (auto point : _points) {
			shape_code += std::to_string(static_cast<int>(point.x)) + " " + std::to_string(static_cast<int>(point.y));
			shape_code += " ";
		}
		break;

	case BROKEN_LINE:
		shape_code += std::to_string(static_cast<int>(_points[0].x)) + " " + std::to_string(static_cast<int>(_points[0].y));
		shape_code += " ";
		shape_code += std::to_string(static_cast<int>(_points[1].x)) + " " + std::to_string(static_cast<int>(_points[1].y));
		shape_code += " ";
		break;

	default:
		break;
	}
	shape_code += " | ";

	return shape_code;
}




inline void draw_vector_with_dc(std::shared_ptr<wxClientDC> DC, std::vector<Shape>& shapes) {
	wxPoint tab[3];
	for (auto shape : shapes) {
		switch (shape.getKind()) {

		case CIRCLE:

			double radious;
			radious = sqrt(pow(shape[0].x - shape[1].x, 2) + pow(shape[0].y - shape[1].y, 2));
			DC->SetBrush(shape.GetColour());
			DC->SetPen(wxPen(shape.GetLine(), 3));
			DC->DrawCircle(shape[0], radious);
			break;

		case SQUARE:

			double d;
			d = std::max(shape[1].x - shape[0].x, shape[1].y - shape[0].y);
			DC->SetBrush(shape.GetColour());
			DC->SetPen(wxPen(shape.GetLine(), 3));
			DC->DrawRectangle(shape[0].x, shape[0].y, d, d);

			break;
		case ELLIPSE:

			double f, g;
			f = shape[1].x - shape[0].x;
			g = shape[1].y - shape[0].y;
			DC->SetBrush(shape.GetColour());
			DC->SetPen(wxPen(shape.GetLine(), 3));
			DC->DrawEllipse(shape[0].x, shape[0].y, f, g);
			break;

		case TRIANGLE:

			double x;
			x = shape[1].x - shape[0].x;
			x = x / 2 + shape[0].x;
			tab[0] = wxPoint(shape[0].x, shape[1].y);
			tab[2] = wxPoint(shape[1].x, shape[1].y);
			tab[1] = wxPoint(x, shape[0].y);
			DC->SetBrush(shape.GetColour());
			DC->SetPen(wxPen(shape.GetLine(), 3));
			DC->DrawPolygon(3, tab);
			break;

		case BROKEN_LINE:

			DC->SetPen(wxPen(shape.GetLine(), 3));
			DC->DrawLine(shape[0].x, shape[0].y, shape[1].x, shape[1].y);
			break;
		case CURVE_LINE:
			DC->SetPen(wxPen(shape.GetLine(), 3));
			DC->DrawSpline(shape[0].x, shape[0].y, shape[2].x, shape[2].y, shape[1].x, shape[1].y);
			break;
		default:
			break;
		}
	}
}

#endif // _SHAPE_