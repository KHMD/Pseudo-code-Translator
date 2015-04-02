#ifndef __FUNC_DIALOG_H__
#define __FUNC_DIALOG_H__

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

class FunctionDialog : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		void _wxFB_c_data_type_select( wxCommandEvent& event ){ c_data_type_select( event ); }
		void _wxFB_c_create_func( wxCommandEvent& event ){ c_create_func( event ); }
	protected:
		enum
		{
			wxID_rtype_choice = 1000,
			wxID_ptr_check,
			wxID_name_cls_struct,
			wxID_func_name,
			wxID_func_params,
			wxID_create_func
		};
		
		wxString returntype;
		wxPanel* m_func_main;
		wxStaticText* t_data_type;
		wxComboBox* m_rtype_choice;
		wxCheckBox* m_ptr_check;
		wxStaticText* t_cls_struct;
		wxTextCtrl* t_name_cls_struct;
		wxStaticText* t_name_var1;
		wxTextCtrl* t_func_name;
		wxStaticText* t_name_var11;
		wxTextCtrl* t_func_params;
		wxButton* m_create_func;
		
		void c_data_type_select( wxCommandEvent& event );
		void c_create_func( wxCommandEvent& event );
	
	public:
		
		FunctionDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Function Prototype"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 338,213 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~FunctionDialog()
		{
			
			EndModal(wxID_CANCEL);
		}
};

#endif
