///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 750,600 ), wxSize( 750,600 ) );
	this->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_nextbutton = new wxButton( this, wxID_ANY, wxT("Kolejna klatka"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_nextbutton, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxEXPAND|wxTOP, 5 );

	m_save_button = new wxButton( this, wxID_ANY, wxT("Zapisz animacje"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_save_button, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxEXPAND, 5 );

	m_undo_button = new wxButton( this, wxID_ANY, wxT("Cofnij"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_undo_button, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxEXPAND, 5 );

	m_display_animation_button = new wxButton( this, wxID_ANY, wxT("Wyświetl"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_display_animation_button, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxEXPAND, 5 );

	m_filePicker = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Wybierz plik z tlem"), wxT("*.png; *.jpg;"), wxDefaultPosition, wxDefaultSize, wxFLP_OPEN );
	bSizer2->Add( m_filePicker, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxEXPAND, 5 );

	m_sliderTEXT = new wxStaticText( this, wxID_ANY, wxT("Jasnosc tla"), wxDefaultPosition, wxDefaultSize, 0 );
	m_sliderTEXT->Wrap( -1 );
	bSizer2->Add( m_sliderTEXT, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP, 5 );

	m_slider = new wxSlider( this, wxID_ANY, 0, -255, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer2->Add( m_slider, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM, 5 );

	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 0, 2, 0, 0 );

	m_circle_button = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_circle_button->SetBitmap( wxBitmap( wxT("ikony/okrag.png"), wxBITMAP_TYPE_ANY ) );
	m_circle_button->SetBitmapDisabled( wxBitmap( wxT("ikony/okrag_s.png"), wxBITMAP_TYPE_ANY ) );
	m_circle_button->SetBitmapPressed( wxBitmap( wxT("ikony/okrag_s.png"), wxBITMAP_TYPE_ANY ) );
	m_circle_button->SetBitmapFocus( wxBitmap( wxT("ikony/okrag_s.png"), wxBITMAP_TYPE_ANY ) );
	m_circle_button->SetBitmapCurrent( wxBitmap( wxT("ikony/okrag_s.png"), wxBITMAP_TYPE_ANY ) );
	m_circle_button->SetMinSize( wxSize( 40,40 ) );
	m_circle_button->SetMaxSize( wxSize( 40,40 ) );

	gSizer1->Add( m_circle_button, 0, wxALL, 5 );

	m_broken_line_button = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_broken_line_button->SetBitmap( wxBitmap( wxT("ikony/lamana.png"), wxBITMAP_TYPE_ANY ) );
	m_broken_line_button->SetBitmapPressed( wxBitmap( wxT("ikony/lamana_s.png"), wxBITMAP_TYPE_ANY ) );
	m_broken_line_button->SetBitmapFocus( wxBitmap( wxT("ikony/lamana_s.png"), wxBITMAP_TYPE_ANY ) );
	m_broken_line_button->SetBitmapCurrent( wxBitmap( wxT("ikony/lamana_s.png"), wxBITMAP_TYPE_ANY ) );
	m_broken_line_button->SetMinSize( wxSize( 40,40 ) );
	m_broken_line_button->SetMaxSize( wxSize( 40,40 ) );

	gSizer1->Add( m_broken_line_button, 0, wxALL, 5 );

	m_curve_line_button = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_curve_line_button->SetBitmap( wxBitmap( wxT("ikony/krzywa.png"), wxBITMAP_TYPE_ANY ) );
	m_curve_line_button->SetBitmapPressed( wxBitmap( wxT("ikony/krzywa_s.png"), wxBITMAP_TYPE_ANY ) );
	m_curve_line_button->SetBitmapFocus( wxBitmap( wxT("ikony/krzywa_s.png"), wxBITMAP_TYPE_ANY ) );
	m_curve_line_button->SetBitmapCurrent( wxBitmap( wxT("ikony/krzywa_s.png"), wxBITMAP_TYPE_ANY ) );
	m_curve_line_button->SetMinSize( wxSize( 40,40 ) );
	m_curve_line_button->SetMaxSize( wxSize( 40,40 ) );

	gSizer1->Add( m_curve_line_button, 0, wxALL, 5 );

	m_ellipse_button = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_ellipse_button->SetBitmap( wxBitmap( wxT("ikony/elipsa.png"), wxBITMAP_TYPE_ANY ) );
	m_ellipse_button->SetBitmapPressed( wxBitmap( wxT("ikony/elipsa_s.png"), wxBITMAP_TYPE_ANY ) );
	m_ellipse_button->SetBitmapFocus( wxBitmap( wxT("ikony/elipsa_s.png"), wxBITMAP_TYPE_ANY ) );
	m_ellipse_button->SetBitmapCurrent( wxBitmap( wxT("ikony/elipsa_s.png"), wxBITMAP_TYPE_ANY ) );
	m_ellipse_button->SetMinSize( wxSize( 40,40 ) );
	m_ellipse_button->SetMaxSize( wxSize( 40,40 ) );

	gSizer1->Add( m_ellipse_button, 0, wxALL, 5 );

	m_square_button = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_square_button->SetBitmap( wxBitmap( wxT("ikony/kwadrat.png"), wxBITMAP_TYPE_ANY ) );
	m_square_button->SetBitmapPressed( wxBitmap( wxT("ikony/kwadrat_s.png"), wxBITMAP_TYPE_ANY ) );
	m_square_button->SetBitmapFocus( wxBitmap( wxT("ikony/kwadrat_s.png"), wxBITMAP_TYPE_ANY ) );
	m_square_button->SetBitmapCurrent( wxBitmap( wxT("ikony/kwadrat_s.png"), wxBITMAP_TYPE_ANY ) );
	m_square_button->SetMinSize( wxSize( 40,40 ) );
	m_square_button->SetMaxSize( wxSize( 40,40 ) );

	gSizer1->Add( m_square_button, 0, wxALL, 5 );

	m_triangle_button = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_triangle_button->SetBitmap( wxBitmap( wxT("ikony/trojkat.png"), wxBITMAP_TYPE_ANY ) );
	m_triangle_button->SetBitmapPressed( wxBitmap( wxT("ikony/trojkat_s.png"), wxBITMAP_TYPE_ANY ) );
	m_triangle_button->SetBitmapFocus( wxBitmap( wxT("ikony/trojkat_s.png"), wxBITMAP_TYPE_ANY ) );
	m_triangle_button->SetBitmapCurrent( wxBitmap( wxT("ikony/trojkat_s.png"), wxBITMAP_TYPE_ANY ) );
	m_triangle_button->SetMinSize( wxSize( 40,40 ) );
	m_triangle_button->SetMaxSize( wxSize( 40,40 ) );

	gSizer1->Add( m_triangle_button, 0, wxALL, 5 );


	bSizer2->Add( gSizer1, 1, wxALIGN_CENTER_HORIZONTAL, 5 );

	m_line_colourTEXT = new wxStaticText( this, wxID_ANY, wxT("Kolor linii"), wxDefaultPosition, wxDefaultSize, 0 );
	m_line_colourTEXT->Wrap( -1 );
	bSizer2->Add( m_line_colourTEXT, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	m_line_colour = new wxColourPickerCtrl( this, wxID_ANY, wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer2->Add( m_line_colour, 0, wxALL, 5 );

	m_fill_colourTEXT = new wxStaticText( this, wxID_ANY, wxT("Kolor wypelnienia"), wxDefaultPosition, wxDefaultSize, 0 );
	m_fill_colourTEXT->Wrap( -1 );
	bSizer2->Add( m_fill_colourTEXT, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP, 5 );

	m_fill_colour = new wxColourPickerCtrl( this, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer2->Add( m_fill_colour, 0, wxALL, 5 );

	m_fill_button = new wxCheckBox( this, wxID_ANY, wxT("Wypelnienie"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_fill_button, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	bSizer1->Add( bSizer2, 0, wxALL|wxSHAPED, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	bSizer5->SetMinSize( wxSize( 610,600 ) );
	m_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	bSizer5->Add( m_panel, 1, wxALL|wxEXPAND, 5 );


	bSizer1->Add( bSizer5, 0, wxALL|wxEXPAND|wxFIXED_MINSIZE, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_nextbutton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_next_frame_button_click ), NULL, this );
	m_save_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_save_button_clicked ), NULL, this );
	m_undo_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_undo_button_clicked ), NULL, this );
	m_display_animation_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_display_button_clicked ), NULL, this );
	m_filePicker->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( MyFrame1::m_choosing_bacground_file ), NULL, this );
	m_slider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::m_slider_change ), NULL, this );
	m_slider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::m_slider_change ), NULL, this );
	m_slider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::m_slider_change ), NULL, this );
	m_slider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::m_slider_change ), NULL, this );
	m_slider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::m_slider_change ), NULL, this );
	m_slider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::m_slider_change ), NULL, this );
	m_slider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::m_slider_change ), NULL, this );
	m_slider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::m_slider_change ), NULL, this );
	m_slider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::m_slider_change ), NULL, this );
	m_circle_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_circle_button_clicked ), NULL, this );
	m_broken_line_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_broken_line_button_clicked ), NULL, this );
	m_curve_line_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_curve_line_button_clicked ), NULL, this );
	m_ellipse_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_ellipse_button_clicked ), NULL, this );
	m_square_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_square_button_clicked ), NULL, this );
	m_triangle_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_triangle_button_clicked ), NULL, this );
	m_fill_button->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::m_fill_button_check ), NULL, this );
	m_panel->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MyFrame1::m_left_click_on_panel ), NULL, this );
	m_panel->Connect( wxEVT_MOTION, wxMouseEventHandler( MyFrame1::m_mouse_on_panel_moved ), NULL, this );
	m_panel->Connect( wxEVT_RIGHT_DCLICK, wxMouseEventHandler( MyFrame1::m_right_click_on_panel ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	m_nextbutton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_next_frame_button_click ), NULL, this );
	m_save_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_save_button_clicked ), NULL, this );
	m_undo_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_undo_button_clicked ), NULL, this );
	m_display_animation_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_display_button_clicked ), NULL, this );
	m_filePicker->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( MyFrame1::m_choosing_bacground_file ), NULL, this );
	m_slider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::m_slider_change ), NULL, this );
	m_slider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::m_slider_change ), NULL, this );
	m_slider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::m_slider_change ), NULL, this );
	m_slider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::m_slider_change ), NULL, this );
	m_slider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::m_slider_change ), NULL, this );
	m_slider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::m_slider_change ), NULL, this );
	m_slider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::m_slider_change ), NULL, this );
	m_slider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::m_slider_change ), NULL, this );
	m_slider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::m_slider_change ), NULL, this );
	m_circle_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_circle_button_clicked ), NULL, this );
	m_broken_line_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_broken_line_button_clicked ), NULL, this );
	m_curve_line_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_curve_line_button_clicked ), NULL, this );
	m_ellipse_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_ellipse_button_clicked ), NULL, this );
	m_square_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_square_button_clicked ), NULL, this );
	m_triangle_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_triangle_button_clicked ), NULL, this );
	m_fill_button->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::m_fill_button_check ), NULL, this );
	m_panel->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MyFrame1::m_left_click_on_panel ), NULL, this );
	m_panel->Disconnect( wxEVT_MOTION, wxMouseEventHandler( MyFrame1::m_mouse_on_panel_moved ), NULL, this );
	m_panel->Disconnect( wxEVT_RIGHT_DCLICK, wxMouseEventHandler( MyFrame1::m_right_click_on_panel ), NULL, this );

}

AnimationFrame::AnimationFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 620,620 ), wxSize( 620,620 ) );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	m_stop_button = new wxButton( this, wxID_ANY, wxT("Stop"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stop_button->SetMinSize( wxSize( -1,20 ) );

	bSizer6->Add( m_stop_button, 1, wxEXPAND, 5 );

	m_start_button = new wxButton( this, wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0 );
	m_start_button->SetMinSize( wxSize( -1,20 ) );

	bSizer6->Add( m_start_button, 1, wxEXPAND, 5 );

	m_animation_file_picker = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Wybierz animacje"), wxT("*.txt"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_animation_file_picker, 1, wxEXPAND, 5 );

	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("            Szybkosc :  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer6->Add( m_staticText6, 0, wxALL, 5 );

	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("0.25"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer6->Add( m_staticText4, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	m_slider2 = new wxSlider( this, wxID_ANY, 100, 25, 200, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer6->Add( m_slider2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT(" 2   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer6->Add( m_staticText5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer5->Add( bSizer6, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxVERTICAL );

	bSizer61->SetMinSize( wxSize( 610,600 ) );
	m_animation_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 600,600 ), wxTAB_TRAVERSAL );
	m_animation_panel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNHIGHLIGHT ) );
	m_animation_panel->SetMinSize( wxSize( 600,600 ) );
	m_animation_panel->SetMaxSize( wxSize( 600,600 ) );

	bSizer61->Add( m_animation_panel, 1, wxALL, 5 );


	bSizer5->Add( bSizer61, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer5 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_stop_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AnimationFrame::m_stop_button_clicked ), NULL, this );
	m_start_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AnimationFrame::m_start_button_clicked ), NULL, this );
	m_animation_file_picker->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( AnimationFrame::m_new_animation_file_selected ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( AnimationFrame::m_speed_slider_changed ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( AnimationFrame::m_speed_slider_changed ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( AnimationFrame::m_speed_slider_changed ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( AnimationFrame::m_speed_slider_changed ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( AnimationFrame::m_speed_slider_changed ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( AnimationFrame::m_speed_slider_changed ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( AnimationFrame::m_speed_slider_changed ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( AnimationFrame::m_speed_slider_changed ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( AnimationFrame::m_speed_slider_changed ), NULL, this );
}

AnimationFrame::~AnimationFrame()
{
	// Disconnect Events
	m_stop_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AnimationFrame::m_stop_button_clicked ), NULL, this );
	m_start_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AnimationFrame::m_start_button_clicked ), NULL, this );
	m_animation_file_picker->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( AnimationFrame::m_new_animation_file_selected ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( AnimationFrame::m_speed_slider_changed ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( AnimationFrame::m_speed_slider_changed ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( AnimationFrame::m_speed_slider_changed ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( AnimationFrame::m_speed_slider_changed ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( AnimationFrame::m_speed_slider_changed ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( AnimationFrame::m_speed_slider_changed ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( AnimationFrame::m_speed_slider_changed ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( AnimationFrame::m_speed_slider_changed ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( AnimationFrame::m_speed_slider_changed ), NULL, this );

}
