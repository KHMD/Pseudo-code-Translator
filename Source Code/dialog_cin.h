#ifndef __DIALOG_CIN_H__
#define __DIALOG_CIN_H__

#include <wx/artprov.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include "control.h"
#include <wx/dialog.h>

class CinDialog : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		void _wxFB_c_get_input( wxCommandEvent& event ){ c_get_input( event ); }
		void _wxFB_c_close( wxCommandEvent& event ){ c_close( event ); }
		
	protected:
		enum
		{
			wxID_condition_input = 1000,
			wxID_get_input
		};
		
		wxPanel* m_panel3;
		wxStaticText* t_var_name;
		wxTextCtrl* t_var_name_input;
		wxButton* m_get_input;
		
		void c_get_input( wxCommandEvent& event );
		void c_close( wxCommandEvent& event );
	
	public:
		
		CinDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Read Input"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 210,127 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~CinDialog();
	
};

#endif //__DIALOG_CIN_H__
