#pragma once

#include <wx/gdicmn.h>
#include <vector>

//kazdy kontener ksztalt to typ i lista punktow wiec tu jest taki uniwersalny kontener na kazdy z nich


class Shape {

public:
	Shape(int kind_of_shape = 0);
	
	int getKind();
	void setKind( int kind );
	bool isEmpty();
	
	bool isFilled();
	void setFilled();
	void setUnFilled();

	void push_back(wxPoint& point);
	void pop_back();
	void clear();

private:
	bool _filled{ false };
	int _kind_of_shape{ 0 };
	std::vector<wxPoint> _points;
};

void Shape::setKind( int kind ) {
	_kind_of_shape = kind;
}

bool Shape::isEmpty() {
	return _kind_of_shape == 0;
}

bool Shape::isFilled() {
	return _filled;
}

void Shape::setFilled() {
	_filled = true;
}

void Shape::setUnFilled() {
	_filled = false;
}


Shape::Shape(int kind_of_shape) {
	_kind_of_shape = kind_of_shape;
}

int Shape::getKind() {
	return _kind_of_shape;
}

void Shape::push_back(wxPoint& point){
	_points.push_back(point);
}

void Shape::pop_back() {
	_points.pop_back();
}

void Shape::clear() {
	_points.clear();
	_filled = false;
	_kind_of_shape = 0;
}