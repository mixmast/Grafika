#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{

}

void GUIMyFrame1::m_next_frame_button_click( wxCommandEvent& event )
{
// tutaj klatka zapisana w wektorze bedzie zapisywana do txt
}

void GUIMyFrame1::m_save_button_clicked( wxCommandEvent& event )
{
// tutaj w sumie to samo co wyzej ale bez czyszczenia tego wektora
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
	m_drawing_flag = CIRCLE;
}

void GUIMyFrame1::m_broken_line_button_clicked( wxCommandEvent& event )
{
	m_drawing_flag = BROKEN_LINE;
}

void GUIMyFrame1::m_curve_line_button_clicked( wxCommandEvent& event )
{
	m_drawing_flag = CURVE_LINE;
}

void GUIMyFrame1::m_ellipse_button_clicked( wxCommandEvent& event )
{
	m_drawing_flag = ELLIPSE;
}

void GUIMyFrame1::m_square_button_clicked( wxCommandEvent& event )
{
	m_drawing_flag = SQUARE;
}

void GUIMyFrame1::m_triangle_button_clicked( wxCommandEvent& event )
{
	m_drawing_flag = TRIANGLE;
}

void GUIMyFrame1::m_fill_button_check( wxCommandEvent& event )
{
	//czy to potrzebne?
}

/* w tej funkcji zakladam ze dochodzi do wyznaczenia poczatku prostokata i jego konca na podstawie
dwoch punktow. Ksztalt to figura wpisana w ten prostokat. Wyjatkami sa line. Dopiero przy zapisywaniu
do pliku tekstowego dwa punkty beda odpowiednio tlumaczonew zaleznosci od zmiennej "Kind". tutaj co 
najwyzej by mozna je z miejsca narysowac za pomoca Draw na panelu*/
void GUIMyFrame1::m_left_click_on_panel( wxMouseEvent& event )
{

	int mouseY;
	int mouseX;

	switch (m_drawing_flag) {


	case CIRCLE:
		if (m_first_click_flag) {

			m_first_click_flag = false;
			m_actual_shape.setKind(CIRCLE);

			mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
			mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;
			m_actual_shape.push_back(wxPoint(mouseX, mouseY));

			if (m_fill_button->IsChecked())
				m_actual_shape.setFilled();
		}
		else {
			m_first_click_flag = true;

			mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
			mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;
			m_actual_shape.push_back(wxPoint(mouseX, mouseY));

			m_shapes.push_back(m_actual_shape);
			m_actual_shape.clear();
		}
		break;

	case TRIANGLE:

		if (m_first_click_flag) {

			m_first_click_flag = false;
			m_actual_shape.setKind(TRIANGLE);

			mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
			mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;
			m_actual_shape.push_back(wxPoint(mouseX, mouseY));

			if (m_fill_button->IsChecked())
				m_actual_shape.setFilled();
		}
		else {
			m_first_click_flag = true;
			
			mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
			mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;
			m_actual_shape.push_back(wxPoint(mouseX, mouseY));

			m_shapes.push_back(m_actual_shape);
			m_actual_shape.clear();
		}
		break;

	case SQUARE:

		if (m_first_click_flag) {
			m_first_click_flag = false;
			m_actual_shape.setKind(SQUARE);
			
			mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
			mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;
			m_actual_shape.push_back(wxPoint(mouseX, mouseY));

			if (m_fill_button->IsChecked())
				m_actual_shape.setFilled();
		}
		else {
			m_first_click_flag = true;
			
			mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
			mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;
			m_actual_shape.push_back(wxPoint(mouseX, mouseY));

			m_shapes.push_back(m_actual_shape);
			m_actual_shape.clear();
		}
		break;

	case ELLIPSE:

		if (m_first_click_flag) {
			m_first_click_flag = false;
			m_actual_shape.setKind(ELLIPSE);
			
			mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
			mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;
			m_actual_shape.push_back(wxPoint(mouseX, mouseY));

			if (m_fill_button->IsChecked())
				m_actual_shape.setFilled();
		}
		else {
			m_first_click_flag = true;
			
			mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
			mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;
			m_actual_shape.push_back(wxPoint(mouseX, mouseY));

			m_shapes.push_back(m_actual_shape);
			m_actual_shape.clear();
		}
		break;

	case BROKEN_LINE:

		if (m_first_click_flag) {
			m_first_click_flag = false;
			m_actual_shape.setKind(BROKEN_LINE);
			if (m_fill_button->IsChecked())
				m_actual_shape.setFilled();
		}
		
		mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
		mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;
		m_actual_shape.push_back(wxPoint(mouseX, mouseY));

		break;

	case CURVE_LINE:

		if (m_first_click_flag) {
			m_first_click_flag = false;
			m_actual_shape.setKind(CURVE_LINE);
			if (m_fill_button->IsChecked())
				m_actual_shape.setFilled();
		}
		
		mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
		mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;
		m_actual_shape.push_back(wxPoint(mouseX, mouseY));

		break;
	}
}

void GUIMyFrame1::m_mouse_on_panel_moved( wxMouseEvent& event )
{
	if(m_first_click_flag == false)
		paint_on_wxpanel();

}

void GUIMyFrame1::m_right_click_on_panel( wxMouseEvent& event )
{
	switch (m_drawing_flag) {

	case CIRCLE:
	case TRIANGLE:
	case SQUARE:
	case ELLIPSE:
		m_first_click_flag = true;
		m_actual_shape.clear();
		break;

	case BROKEN_LINE:
	case CURVE_LINE:
		m_shapes.push_back(m_actual_shape);
		m_first_click_flag = true;
		m_actual_shape.clear();
		break;

	default:
		break;
	}
		
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
		DC->DrawBitmap( m_background_bitmap, 0, 0, true );
	}
	else {
		m_panel->SetBackgroundColour(m_background_color);
	}

	int mouseX;
	int mouseY;

	switch (m_actual_shape.getKind()) {

	case CIRCLE:
		double radious;
		if (m_first_click_flag == false) { // nie zakonczono rysowania 
			mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
			mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;
			m_actual_shape.push_back(wxPoint(mouseX, mouseY));
			radious = sqrt(pow(m_actual_shape[0].x - mouseX, 2) + pow(m_actual_shape[0].y - mouseY, 2));
		}
		else
			radious = sqrt(pow(m_actual_shape[0].x - m_actual_shape[1].x, 2) + pow(m_actual_shape[0].y- m_actual_shape[1].y, 2));
		DC->DrawCircle(m_actual_shape[0], radious);
		break;

	default:
		break;
	}
}


