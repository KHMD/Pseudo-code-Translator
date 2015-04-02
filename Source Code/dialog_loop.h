#ifndef __DIALOG_LOOP_H__
#define __DIALOG_LOOP_H__

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

class LoopDialog : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		void _wxFB_c_add_loop( wxCommandEvent& event ){ c_add_loop( event ); }
		void _wxFB_c_choice_loop( wxCommandEvent& event ){ c_choice_loop( event ); }
		
	protected:
		enum
		{
			wxID_loop_choice = 1000,
			wxID_init_input,
			wxID_condition_input,
			wxID_inc_dec_input,
			wxID_add_loop
		};
		
		wxPanel* m_panel3;
		wxRadioBox* m_loop_choice;
		wxStaticText* t_intialize;
		wxTextCtrl* t_init_input;
		wxStaticText* t_condition;
		wxTextCtrl* t_condition_input;
		wxStaticText* t_inc_dec;
		wxTextCtrl* t_inc_dec_input;
		wxButton* m_add_loop;
		
		void c_add_loop( wxCommandEvent& event );
		void c_choice_loop( wxCommandEvent& event );
	
	public:
		
		LoopDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Loop"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 243,276 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~LoopDialog()
		{
			EndModal(wxID_CANCEL);
		}
};

#endif
