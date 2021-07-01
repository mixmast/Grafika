#include "GUIAnimationFrame.h"
#include "Functions.h"

GUIAnimationFrame::GUIAnimationFrame(wxWindow* parent)
:
AnimationFrame(parent),
m_timer(this)
{

}

void GUIAnimationFrame::m_stop_button_clicked( wxCommandEvent& event )
{
	m_timer.stop();
}

void GUIAnimationFrame::m_start_button_clicked( wxCommandEvent& event )
{
	//tempo wyswietlania klatek ustawiam na 5fps
	m_timer.set_length(m_amount_of_frames);
	m_timer.start(200 / m_animation_speed);
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
	paint_frame();
}

void GUIAnimationFrame::m_speed_slider_changed( wxScrollEvent& event )
{
	m_animation_speed = m_slider2->GetValue() / 100.0;
}

void GUIAnimationFrame::load_frame(int number_of_frame) {

	std::fstream file;
	std::string line;
	std::string element_from_line;

	file.open(static_cast<std::string>(m_animation_file_picker->GetPath()), std::ios::in);
	m_shapes.clear();

	if (file.is_open()) {

		GotoLine(file, number_of_frame * 2 - 1);
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
		while (  line != "| " ) { 
			delete_element_from_string(line, element_from_line, '|');
			m_shapes.push_back(static_cast<Shape>(element_from_line + "| "));
			i++;
		}
		i++;
	}
	file.close();
}

void GUIAnimationFrame::paint_frame() {
	std::shared_ptr<wxClientDC> DC (new wxClientDC(m_animation_panel));
	DC->Clear();
	draw_vector_with_dc(DC, m_shapes);
}

GUIAnimationFrame::MyTimer::MyTimer(GUIAnimationFrame* animation_frame) : wxTimer(), m_animation_panel(animation_frame) { }

void GUIAnimationFrame::MyTimer::Notify() {
	if (m_cycle < m_length) {
		m_animation_panel->load_frame(m_cycle);
		m_animation_panel->paint_frame();
		++m_cycle;
	}
	else
		stop();
}

void GUIAnimationFrame::MyTimer::start(int milisec) {
	wxTimer::Start(milisec);
}

void GUIAnimationFrame::MyTimer::stop() {
	wxTimer::Stop();
}

void GUIAnimationFrame::MyTimer::set_length(int len) {
	m_length = len;
}
