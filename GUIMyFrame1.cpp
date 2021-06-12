#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{

}

void GUIMyFrame1::m_next_frame_button_click( wxCommandEvent& event )
{
// TODO: Implement m_next_frame_button_click
}

void GUIMyFrame1::m_save_button_clicked( wxCommandEvent& event )
{
// TODO: Implement m_save_button_clicked
}

void GUIMyFrame1::m_choosing_bacground_file(wxFileDirPickerEvent& event)
{
	std::string path_to_file = m_filePicker->GetPath();

	std::shared_ptr<wxImage> image_org(new wxImage(path_to_file));
	m_background_image_org = image_org;

	std::shared_ptr<wxImage> image_dis(new wxImage(path_to_file));
	m_background_image_dis = image_dis;

	correct_brightness(*m_background_image_dis);

	paint_on_wxpanel();
}

void GUIMyFrame1::m_slider_change(wxScrollEvent& event)
{
	if (m_background_image_dis) {

		*m_background_image_dis = m_background_image_org->Copy();
		correct_brightness(*m_background_image_dis);
	}
	else {
		int level = std::min(static_cast<int>(m_slider->GetValue() / 100.0 * 255), 255);
		m_background_color = wxColour(level, level, level);
	}
	paint_on_wxpanel();
}

void GUIMyFrame1::m_circle_button_clicked( wxCommandEvent& event )
{
// TODO: Implement m_circle_button_clicked
}

void GUIMyFrame1::m_broken_line_button_clicked( wxCommandEvent& event )
{
// TODO: Implement m_broken_line_button_clicked
}

void GUIMyFrame1::m_curve_line_button_clicked( wxCommandEvent& event )
{
// TODO: Implement m_curve_line_button_clicked
}

void GUIMyFrame1::m_ellipse_button_clicked( wxCommandEvent& event )
{
// TODO: Implement m_ellipse_button_clicked
}

void GUIMyFrame1::m_square_button_clicked( wxCommandEvent& event )
{
// TODO: Implement m_square_button_clicked
}

void GUIMyFrame1::m_triangle_button_clicked( wxCommandEvent& event )
{
// TODO: Implement m_triangle_button_clicked
}

void GUIMyFrame1::m_fill_button_check( wxCommandEvent& event )
{

}

void GUIMyFrame1::m_left_click_on_panel( wxMouseEvent& event )
{
// TODO: Implement m_left_click_on_panel
}

void GUIMyFrame1::m_mouse_on_panel_moved( wxMouseEvent& event )
{
// TODO: Implement m_mouse_on_panel_moved
}

void GUIMyFrame1::m_right_click_on_panel( wxMouseEvent& event )
{
// TODO: Implement m_right_click_on_panel
}

void GUIMyFrame1::correct_brightness(wxImage& image_to_change) {

	image_to_change = image_to_change.Copy();
	int data_length = 3 * image_to_change.GetHeight() * image_to_change.GetWidth();
	int current = 0;
	double bright_value = m_slider->GetValue();
	unsigned char* image_data = image_to_change.GetData();

	for (int i = 0; i < data_length; ++i) {
		current = image_data[i] + bright_value;
		if (current < 0)
			image_data[i] = 0;
		else if (current > 255)
			image_data[i] = 255;
		else
			image_data[i] = current;
	}
	m_background_bitmap = wxBitmap(image_to_change);
}


void GUIMyFrame1::paint_on_wxpanel() 
{
	std::shared_ptr<wxClientDC> DC(new wxClientDC(m_panel));

	DC->Clear(); //Rysowanie tla wraz z jasnoscia
	if (m_background_image_dis) {
		DC->DrawBitmap( m_background_bitmap, 0, 0 );
	}
	else {
		m_panel->SetBackgroundColour(m_background_color);
	}


}


