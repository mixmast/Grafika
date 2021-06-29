#ifndef __GUIMyFrame1__
#define __GUIMyFrame1__

/**
@file
Subclass of MyFrame1, which is generated by wxFormBuilder.
*/

#include "GUI.h"

//// end generated include

#include <memory>
#include <vector>
#include <algorithm>
#include <wx/dcclient.h>
#include <fstream>
#include "Shape.h"

/** Implementing MyFrame1 */
class GUIMyFrame1 : public MyFrame1
{
	protected:
		// Handlers for MyFrame1 events.
		void m_next_frame_button_click( wxCommandEvent& event );
		void m_save_button_clicked( wxCommandEvent& event );
		void m_choosing_bacground_file( wxFileDirPickerEvent& event );
		void m_slider_change( wxScrollEvent& event );
		void m_circle_button_clicked( wxCommandEvent& event );
		void m_broken_line_button_clicked( wxCommandEvent& event );
		void m_curve_line_button_clicked( wxCommandEvent& event );
		void m_ellipse_button_clicked( wxCommandEvent& event );
		void m_square_button_clicked( wxCommandEvent& event );
		void m_triangle_button_clicked( wxCommandEvent& event );
		void m_fill_button_check( wxCommandEvent& event );
		void m_left_click_on_panel( wxMouseEvent& event );
		void m_mouse_on_panel_moved( wxMouseEvent& event );
		void m_right_click_on_panel( wxMouseEvent& event );
	public:
		/** Constructor */
		GUIMyFrame1( wxWindow* parent );
	//// end generated class members

	protected:
		
		std::vector<Shape> m_shapes; // cala klatka tu jest zapisana
		Shape m_actual_shape { 0 };
		int m_drawing_flag { 0 };
		bool m_first_click_flag { 1 };
		bool m_second_click_flag{ 1 };
		bool m_fill{0};

		//std::string m_frame_drawing_text = { "" };

		std::shared_ptr<wxImage> m_background_image_org { 0 };
		std::shared_ptr<wxImage> m_background_image_dis { 0 };

		wxBitmap m_background_bitmap { wxNullBitmap };

		wxColour m_background_color { 128, 128, 128 };

		void paint_on_wxpanel();
		void draw_vector_with_dc(std::shared_ptr<wxClientDC> DC);
		void save_vector_to_file();
		void correct_brightness(wxImage& image_to_change);
};

#endif // __GUIMyFrame1__
