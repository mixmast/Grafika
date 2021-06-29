#include <vector>
#include <algorithm>
#include "Shape.h"


std::string Shape::txt_code() {

	double r = 0;
	int a = 0;
	std::string shape_code;

	switch (_kind_of_shape) {

	case CIRCLE:
		r = sqrt(pow(_points[1].x - _points[0].x, 2) + pow(_points[1].y - _points[0].y, 2));
		shape_code = "CI ";
		shape_code += std::to_string(static_cast<int>(_points[0].x - r)) + " " + std::to_string(static_cast<int>(_points[0].y - r));
		shape_code += " ";
		shape_code += std::to_string(static_cast<int>(_points[0].x - r)) + " " + std::to_string(static_cast<int>(_points[0].y + r));
		shape_code += " ";
		shape_code += std::to_string(static_cast<int>(_points[0].x + r)) + " " + std::to_string(static_cast<int>(_points[0].y + r));
		shape_code += " ";
		shape_code += std::to_string(static_cast<int>(_points[0].x + r)) + " " + std::to_string(static_cast<int>(_points[0].y - r));
		break;

	case SQUARE:
		a = std::max(_points[1].x - _points[0].x, _points[1].y - _points[0].y);
		shape_code = "SQ ";
		shape_code += std::to_string(static_cast<int>(_points[0].x)) + " " + std::to_string(static_cast<int>(_points[0].y));
		shape_code += " ";
		shape_code += std::to_string(static_cast<int>(_points[0].x)) + " " + std::to_string(static_cast<int>(_points[0].y + a));
		shape_code += " ";
		shape_code += std::to_string(static_cast<int>(_points[1].x)) + " " + std::to_string(static_cast<int>(_points[1].y));
		shape_code += " ";
		shape_code += std::to_string(static_cast<int>(_points[0].x)) + " " + std::to_string(static_cast<int>(_points[0].y - a));
		break;

	case ELLIPSE:
		a = _points[1].y - _points[0].y;
		shape_code = "EL ";
		shape_code += std::to_string(static_cast<int>(_points[0].x)) + " " + std::to_string(static_cast<int>(_points[0].y));
		shape_code += " ";
		shape_code += std::to_string(static_cast<int>(_points[0].x)) + " " + std::to_string(static_cast<int>(_points[0].y + a));
		shape_code += " ";
		shape_code += std::to_string(static_cast<int>(_points[1].x)) + " " + std::to_string(static_cast<int>(_points[1].y));
		shape_code += " ";
		shape_code += std::to_string(static_cast<int>(_points[0].x)) + " " + std::to_string(static_cast<int>(_points[0].y - a));
		break;

	case TRIANGLE:
		shape_code = "TR ";
		for (int i = 0; i < 3; ++i) {
			shape_code += std::to_string(static_cast<int>(_points[i].x)) + " " + std::to_string(static_cast<int>(_points[i].y));
			shape_code += " ";
		}
		break;

	case CURVE_LINE:
		shape_code = "CL ";
		for (auto point : _points) {
			shape_code += std::to_string(static_cast<int>(point.x)) + " " + std::to_string(static_cast<int>(point.y));
			shape_code += " ";
		}
		break;

	case BROKEN_LINE:
		shape_code = "BL ";
		for (auto point : _points) {
			shape_code += std::to_string(static_cast<int>(point.x)) + " " + std::to_string(static_cast<int>(point.y));
			shape_code += " ";
		}
		break;

	default:
		break;
	}

	return shape_code;
}