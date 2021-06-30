#ifndef __GUIAnimationFrame__
#define __GUIAnimationFrame__

/**
@file
Subclass of AnimationFrame, which is generated by wxFormBuilder.
*/

#include "GUI.h"

//// end generated include

#include <vector>
#include <string>
#include "Shape.h"

/** Implementing AnimationFrame */
class GUIAnimationFrame : public AnimationFrame
{
	protected:
		// Handlers for AnimationFrame events.
		void m_stop_button_clicked( wxCommandEvent& event );
		void m_start_button_clicked( wxCommandEvent& event );
		void m_speed_slider_changed( wxScrollEvent& event );
	public:
		/** Constructor */
		GUIAnimationFrame( wxWindow* parent );
	//// end generated class members

	protected:
		std::string m_file_path{ "Animation.txt" };
		std::vector<Shape> m_shapes;

		wxBitmap m_background_bitmap{ wxNullBitmap };
		wxColour m_background_color{ 128, 128, 128 };

		double m_animation_speed;

};

#endif // __GUIAnimationFrame__