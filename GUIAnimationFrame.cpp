#include "GUIAnimationFrame.h"

GUIAnimationFrame::GUIAnimationFrame( wxWindow* parent )
:
AnimationFrame( parent )
{

}

void GUIAnimationFrame::m_stop_button_clicked( wxCommandEvent& event )
{
// TODO: Implement m_stop_button_clicked
}

void GUIAnimationFrame::m_start_button_clicked( wxCommandEvent& event )
{
// TODO: Implement m_start_button_clicked
}

void GUIAnimationFrame::m_speed_slider_changed( wxScrollEvent& event )
{
	m_animation_speed = m_slider2->GetValue() / 100.0;
}
