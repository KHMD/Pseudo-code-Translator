#ifndef __FRAME_VAR_H__
#define __FRAME_VAR_H__

#include <wx/artprov.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/choice.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/dialog.h>
#include "control.h"
class VariableDialog : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		void _wxFB_c_data_type_select( wxCommandEvent& event ){ c_data_type_select( event ); }
		void _wxFB_c_arraysize( wxCommandEvent& event ){ c_arraysize( event ); }
		void _wxFB_c_create_var( wxCommandEvent& event ){ c_create_var( event ); }

	protected:
		enum
		{
			wxID_data_type = 1000,
			wxID_name_cls_struct,
			wxID_arraysize,
			wxID_array_check,
			wxID_name_var,
			wxID_create_var
		};
		
		wxPanel* m_var_main;
		wxStaticText* t_data_type;
		wxComboBox* dd_data_typr;
		wxCheckBox* m_ptr_check;
		wxStaticText* t_cls_struct;
		wxTextCtrl* t_name_cls_struct;
		wxCheckBox* m_array_check;
		wxStaticText* t_array_label;
		wxTextCtrl* t_arraysize;
		wxStaticText* t_name_var1;
		wxTextCtrl* t_name_var;
		wxButton* m_create_var;
		void c_data_type_select( wxCommandEvent& event );
		void c_arraysize( wxCommandEvent& event );
		void c_create_var( wxCommandEvent& event );

		int arraymax;
	
	public:
		
		VariableDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Create a variable!"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 320,207 ), long style = wxDEFAULT_DIALOG_STYLE );  
		~VariableDialog()
		{
			EndModal(wxID_CANCEL);
		}
};

#endif
