#ifndef __DIALOG_COUT_H__
#define __DIALOG_COUT_H__

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
#include <wx/dialog.h>
#include "control.h"

class CoutDialog : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		void _wxFB_c_disp( wxCommandEvent& event ){ c_disp( event ); }
		void _wxFB_c_close( wxCommandEvent& event ){ c_close( event ); }
		
	protected:
		enum
		{
			wxID_outType = 1000,
			wxID_display,
			wxID_disp
		};
		
		wxPanel* m_outdialog;
		wxRadioBox* m_outType;
		wxTextCtrl* t_display;
		wxButton* m_disp;
		
		
		void c_disp( wxCommandEvent& event );
		void c_close( wxCommandEvent& event );
	
	public:
		
		CoutDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Display"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 273,158 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~CoutDialog();
	
};

#endif
