#ifndef __DIALOG_OPERATION_H__
#define __DIALOG_OPERATION_H__

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

class OperationDialog : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		void _wxFB_c_add_operation( wxCommandEvent& event ){ c_add_operation( event ); }
	
	protected:
		enum
		{
			wxID_operation_input = 1000,
			wxID_add_operation
		};
		
		wxPanel* m_panel2;
		wxStaticText* t_operation;
		wxTextCtrl* t_operation_input;
		wxButton* m_add_operation;

		void c_add_operation( wxCommandEvent& event );
		
	
	public:
		
		OperationDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Operation"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 251,119 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~OperationDialog()
		{
			EndModal(wxID_CANCEL);
		}
};

#endif
