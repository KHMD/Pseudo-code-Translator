#ifndef __STRUCT_DIALOG_H__
#define __STRUCT_DIALOG_H__

#include <wx/artprov.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/radiobox.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/dialog.h>
#include "control.h"

class StructDialog : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		void _wxFB_c_addmember_struct( wxCommandEvent& event ){ c_addmember_struct( event ); }
		void _wxFB_c_createstruct( wxCommandEvent& event ){ c_createstruct( event ); }
		wxString structcode;
	protected:
		enum
		{
			wxID_name_class = 1000,
			wxID_addmember_struct,
			wxID_createstruct
		};
		
		wxPanel* m_struct_main;
		wxStaticText* t_struct_namelabel;
		wxTextCtrl* t_name_struct;
		wxStaticText* t_struct_addmem;
		wxRadioBox* m_struct_mtype;
		wxButton* m_addmember_struct;
		wxStaticText* t_cls_memlist;
		wxTextCtrl* t_memberlist_struct;
		wxButton* m_createstruct;

		void c_addmember_struct( wxCommandEvent& event );
		void c_createstruct( wxCommandEvent& event );
		
	public:
		
		StructDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Structure Dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 495,446 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~StructDialog()
		{
			EndModal(wxID_CANCEL);
		}
};

#endif
