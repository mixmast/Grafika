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

void GUIAnimationFrame::m_start_button_clicked(wxCommandEvent& event)
{
	//tempo wyswietlania klatek ustawiam na 5fps

	m_timer.set_length(m_amount_of_frames);
	m_timer.start(100 / m_animation_speed);
}

void GUIAnimationFrame::m_restatr_button_clicked( wxCommandEvent& event )
{
	m_timer.set_cycle(1);
	load_frame(1);
	paint_frame();
}

void GUIAnimationFrame::m_new_animation_file_selected(wxFileDirPickerEvent& event)
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

void GUIAnimationFrame::m_speed_slider_changed(wxScrollEvent& event)
{
	m_animation_speed = m_slider2->GetValue() / 100.0;
	if (m_timer.IsRunning()) {
		m_timer.stop();
		m_timer.start(100 / m_animation_speed);
	}


	std::string speed_text = std::to_string(m_animation_speed);
	speed_text.resize(3);
	
	m_animation_speed_textxtctr->SetValue(speed_text);
}


void GUIAnimationFrame::MyTimer::Notify() 
{
	if (m_cycle < m_length) {
		m_animation_panel->load_frame(m_cycle);
		m_animation_panel->paint_frame();
		++m_cycle;
	}
	else
		stop();
}

void GUIAnimationFrame::load_frame(int number_of_frame) 
{

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
			if (element_from_line != "NULL") {
				m_background_bitmap.LoadFile(m_path_to_background, wxBITMAP_TYPE_ANY);
				std::shared_ptr<wxImage> img_org(new wxImage(m_path_to_background));
				m_background_image_org = img_org;
				std::shared_ptr<wxImage> img_dis(new wxImage(m_path_to_background));
				m_background_image_dis = img_dis;
				m_background_flag = true;
				m_background_changed = true;
			}
			else {
				m_background_flag = false;
				m_background_changed = false;
			}
		}

		delete_element_from_string(line, element_from_line);
		m_frame_brightness = stoi(element_from_line);

		while (  line != "| "  && line != " ") { 
			delete_element_from_string(line, element_from_line, '|');
			m_shapes.push_back(static_cast<Shape>(element_from_line + "| "));
		}
	}
	file.close();
}

void GUIAnimationFrame::correct_brightness(wxImage& image_to_change)
{

	image_to_change = image_to_change.Copy();
	int data_length = 3 * image_to_change.GetHeight() * image_to_change.GetWidth();
	int current = 0;
	unsigned char* image_data = image_to_change.GetData();

	for (int i = 0; i < data_length; ++i) {
		current = image_data[i] + m_frame_brightness;
		if (current < 0)
			image_data[i] = 0;
		else if (current > 255)
			image_data[i] = 255;
		else
			image_data[i] = current;
	}
	m_background_bitmap = wxBitmap(image_to_change);
}



void GUIAnimationFrame::MyTimer::stop() 
{
	wxTimer::Stop();
}

void GUIAnimationFrame::MyTimer::set_length(int len) 
{
	m_length = len;
}

void GUIAnimationFrame::paint_frame() 
{
	std::shared_ptr<wxClientDC> DC (new wxClientDC(m_animation_panel));
	DC->Clear();
	if (m_background_flag) {
		if (m_brightness_changed || m_background_changed) {
			*m_background_image_dis = m_background_image_org->Copy();
			correct_brightness(*m_background_image_dis);
		}

		DC->DrawBitmap(m_background_bitmap, 0, 0);
	}
	draw_vector_with_dc(DC, m_shapes);
}

GUIAnimationFrame::MyTimer::MyTimer(GUIAnimationFrame* animation_frame) : wxTimer(), m_animation_panel(animation_frame) { }

void GUIAnimationFrame::MyTimer::start(int milisec) 
{
	wxTimer::Start(milisec);
}

void GUIAnimationFrame::MyTimer::set_cycle(int cyc) {
	m_cycle = cyc;
}