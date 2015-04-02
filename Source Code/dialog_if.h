#ifndef __DIALOG_IF_H__
#define __DIALOG_IF_H__

#include <wx/artprov.h>
#include <wx/string.h>
#include <wx/radiobox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/dialog.h>
#include "control.h"

class IfDialog : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		void _wxFB_c_add_condition( wxCommandEvent& event ){ c_add_condition( event ); }
		void _wxFB_c_if_choice( wxCommandEvent& event ){ c_if_choice( event ); }
		
	
	protected:
		enum
		{
			wxID_if_choice = 1000,
			wxID_condition_input,
			wxID_add_condition
		};
		
		wxPanel* m_panel2;
		wxRadioBox* m_if_choice;
		wxStaticText* t_condition;
		wxTextCtrl* t_condition_input;
		wxButton* m_add_condition;
		
		void c_add_condition( wxCommandEvent& event );
		void c_if_choice( wxCommandEvent& event );
	
	public:
		
		IfDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("If"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 285,169 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~IfDialog()
		{
			EndModal(wxID_CANCEL);
		}
};

#endif
