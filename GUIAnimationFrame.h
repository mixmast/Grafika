#ifndef __GUIAnimationFrame__
#define __GUIAnimationFrame__

/**
@file
Subclass of AnimationFrame, which is generated by wxFormBuilder.
*/

#include "GUI.h"

//// end generated include

#include <wx/timer.h>
#include <wx/image.h>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include "Shape.h"

/** Implementing AnimationFrame */
class GUIAnimationFrame : public AnimationFrame
{
	protected:
		// Handlers for AnimationFrame events.
		void m_stop_button_clicked( wxCommandEvent& event );
		void m_start_button_clicked( wxCommandEvent& event );
		void m_restatr_button_clicked( wxCommandEvent& event );
		void m_new_animation_file_selected( wxFileDirPickerEvent& event );
		void m_speed_slider_changed( wxScrollEvent& event );
	public:
		/** Constructor */
		GUIAnimationFrame( wxWindow* parent );
	//// end generated class members

		class MyTimer : public wxTimer {

		public:
			MyTimer(GUIAnimationFrame* animation_frame);
			void Notify() override;
			void start(int milisec);
			void stop();
			void set_length(int len);
			void set_cycle(int cyc);

		protected:
			int m_cycle{ 1 };
			int m_length{ 0 };
			GUIAnimationFrame* m_animation_panel;
		};

	protected:
		std::string m_file_path{ "Animation.txt" };
		std::string m_path_to_background {""};
		std::vector<Shape> m_shapes;

		wxBitmap m_background_bitmap{ wxNullBitmap };
		wxColour m_background_color{ *wxWHITE };
		MyTimer m_timer;

		std::shared_ptr<wxImage> m_background_image_org{ nullptr };
		std::shared_ptr<wxImage> m_background_image_dis{ nullptr };

		bool m_background_flag{ false };
		bool m_background_changed{ false };
		bool m_brightness_changed{ false };
		double m_animation_speed { 1 };
		int m_amount_of_frames;
		int m_frame_brightness;

		void load_frame(int number_of_frame);
		void correct_brightness(wxImage& image_to_change);
		void paint_frame();


};

#endif // __GUIAnimationFrame__
