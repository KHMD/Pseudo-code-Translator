 #ifndef __DIALOG_INCLUDE_H__
#define __DIALOG_INCLUDE_H__

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
#include<wx/listbox.h>
#include <wx/dialog.h>
#include "control.h"

class IncludeDialog : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		void _wxFB_c_add( wxCommandEvent& event ){ c_add( event ); }
		void _wxFB_c_done( wxCommandEvent& event ){ c_done( event ); }
		void _wxFB_c_remove( wxCommandEvent& event ){ c_remove( event ); }
		void c_init();
		
	protected:
		enum
		{
			wxID_lib_input = 1000,
			wxID_listbox,
			wxID_add,
			wxID_lib_list,
			wxID_remove,
			wxID_done
		};
		
		wxStaticText* t_input;
		wxTextCtrl* t_lib_input;
		wxButton* m_add;
		wxListBox* m_listBox;
		wxButton* m_remove;
		wxButton* m_done;
		
		void c_add( wxCommandEvent& event );
		void c_done( wxCommandEvent& event );
		void c_remove( wxCommandEvent& event );
	
	public:
		
		IncludeDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Include Liberaries"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 314,227 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~IncludeDialog()
		{
			EndModal(wxID_CANCEL);
		}
	
};

#endif
