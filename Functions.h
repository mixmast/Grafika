#pragma once

#include <fstream>
#include <string>
#include <memory>
#include <wx/pen.h>
#include "Shape.h"


inline std::string delete_element_from_string(std::string& elements_between_spaces, std::string& element, char separator = ' ') {

	
	int i = 0;
	std::string extracted_elements;
	
	while (elements_between_spaces[i] == separator)
		++i;
	while (elements_between_spaces[i] != separator) {
		extracted_elements.push_back(elements_between_spaces[i]);
		++i;
	}
	elements_between_spaces = elements_between_spaces.substr(i);
	element = extracted_elements;

	return extracted_elements;
}

inline std::fstream& GotoLine(std::fstream& file, int num) {
	file.seekg(std::ios::beg);
	for (int i = 0; i < num; ++i) {
		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return file;
}

inline void convert_to_relative_path(std::string& inrelative_path) {

	int num = inrelative_path.find("tlo");
	inrelative_path = inrelative_path.substr(num);
}