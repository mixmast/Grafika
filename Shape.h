#ifndef _SHAPE_
#define _SHAPE_

#include <wx/gdicmn.h>
#include <vector>
#include <string>
#include <algorithm>

//kazdy kontener ksztalt to typ i lista punktow wiec tu jest taki uniwersalny kontener na kazdy z nich
enum SHAPES_FLAG { CIRCLE = 100, TRIANGLE = 110, SQUARE = 120, ELLIPSE = 130, BROKEN_LINE = 140, CURVE_LINE = 150 };

class Shape {

public:
	Shape(int kind_of_shape = 0);
	//Shape(std::string code_txt); 
	
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
inline std::string Shape::txt_code() {

	double r = 0;
	int a = 0;
	std::string shape_code;

	switch (_kind_of_shape) {

	case CIRCLE:
		r = sqrt(pow(_points[1].x - _points[0].x, 2) + pow(_points[1].y - _points[0].y, 2));
		shape_code = "CI ";
		shape_code += std::to_string(static_cast<int>(_points[0].x - r)) + " " + std::to_string(static_cast<int>(_points[0].y - r));
		shape_code += "  ";
		shape_code += std::to_string(static_cast<int>(_points[0].x - r)) + " " + std::to_string(static_cast<int>(_points[0].y + r));
		shape_code += "  ";
		shape_code += std::to_string(static_cast<int>(_points[0].x + r)) + " " + std::to_string(static_cast<int>(_points[0].y + r));
		shape_code += "  ";
		shape_code += std::to_string(static_cast<int>(_points[0].x + r)) + " " + std::to_string(static_cast<int>(_points[0].y - r));
		shape_code += "     ";
		break;

	case SQUARE:
		a = std::max(_points[1].x - _points[0].x, _points[1].y - _points[0].y);
		shape_code = "SQ ";
		shape_code += std::to_string(static_cast<int>(_points[0].x)) + " " + std::to_string(static_cast<int>(_points[0].y));
		shape_code += "  ";
		shape_code += std::to_string(static_cast<int>(_points[0].x)) + " " + std::to_string(static_cast<int>(_points[0].y + a));
		shape_code += "  ";
		shape_code += std::to_string(static_cast<int>(_points[1].x)) + " " + std::to_string(static_cast<int>(_points[1].y));
		shape_code += "  ";
		shape_code += std::to_string(static_cast<int>(_points[0].x)) + " " + std::to_string(static_cast<int>(_points[0].y - a));
		shape_code += "     ";
		break;

	case ELLIPSE:
		a = _points[1].y - _points[0].y;
		shape_code = "EL ";
		shape_code += std::to_string(static_cast<int>(_points[0].x)) + " " + std::to_string(static_cast<int>(_points[0].y));
		shape_code += "  ";
		shape_code += std::to_string(static_cast<int>(_points[0].x)) + " " + std::to_string(static_cast<int>(_points[0].y + a));
		shape_code += "  ";
		shape_code += std::to_string(static_cast<int>(_points[1].x)) + " " + std::to_string(static_cast<int>(_points[1].y));
		shape_code += "  ";
		shape_code += std::to_string(static_cast<int>(_points[0].x)) + " " + std::to_string(static_cast<int>(_points[0].y - a));
		shape_code += "     ";
		break;

	case TRIANGLE:
		shape_code = "TR ";
		for (int i = 0; i < 3; ++i) {
			shape_code += std::to_string(static_cast<int>(_points[i].x)) + " " + std::to_string(static_cast<int>(_points[i].y));
			shape_code += "  ";
		}
		shape_code += "     ";
		break;

	case CURVE_LINE:
		shape_code = "CL ";
		for (auto point : _points) {
			shape_code += std::to_string(static_cast<int>(point.x)) + " " + std::to_string(static_cast<int>(point.y));
			shape_code += "  ";
		}
		shape_code += "     ";
		break;

	case BROKEN_LINE:
		shape_code = "BL ";
		for (auto point : _points) {
			shape_code += std::to_string(static_cast<int>(point.x)) + " " + std::to_string(static_cast<int>(point.y));
			shape_code += "  ";
		}
		shape_code += "     ";
		break;

	default:
		break;
	}

	return shape_code;
}

#endif // _SHAPE_