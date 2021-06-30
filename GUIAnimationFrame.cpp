#include "GUIAnimationFrame.h"
#include "Functions.h"

GUIAnimationFrame::GUIAnimationFrame( wxWindow* parent )
:
AnimationFrame( parent )
{

}

void GUIAnimationFrame::m_stop_button_clicked( wxCommandEvent& event )
{

}

void GUIAnimationFrame::m_start_button_clicked( wxCommandEvent& event )
{
	
}

void GUIAnimationFrame::m_new_animation_file_selected( wxFileDirPickerEvent& event )
{
	std::fstream file;
	file.open(static_cast<std::string>(m_animation_file_picker->GetPath()), std::ios::in);

	std::string line;

	if (file.is_open())
		getline(file, line);

	m_amount_of_frames = stoi(line);
	file.close();

	load_frame(1);
}

void GUIAnimationFrame::m_speed_slider_changed( wxScrollEvent& event )
{
	m_animation_speed = m_slider2->GetValue() / 100.0;
}

void GUIAnimationFrame::load_frame(int number_of_frame) {

	std::fstream file;
	file.open(static_cast<std::string>(m_animation_file_picker->GetPath()), std::ios::in);

	std::string line;
	std::string element_from_line;

	if (file.is_open()) {

		GotoLine(file, number_of_frame);
		getline(file, line);

		delete_element_from_string(line, element_from_line);
		if (element_from_line != m_path_to_background) {
			m_path_to_background = element_from_line;
			if(element_from_line != "NULL")
				m_background_bitmap.LoadFile(m_path_to_background);
			//a co w przeciwnym wypadku?
		}

		delete_element_from_string(line, element_from_line);
		m_frame_brightness = stoi(element_from_line);

		int i = 0;
		while (line != "| ") { //tym znakiem koñczy siê ka¿da klatka tu tez jest jakis blad
			delete_element_from_string(line, element_from_line, '|');

			m_shapes.push_back(static_cast<Shape>(element_from_line + "| "));
			i++;
		}

	}
}

void GUIAnimationFrame::paint_frame() {

}
