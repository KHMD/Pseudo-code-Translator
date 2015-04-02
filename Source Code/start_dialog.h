#ifndef __START_DIALOG_H__
#define __START_DIALOG_H__

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
#include <wx/textdlg.h>
#include "control.h"

class StartDialog : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		void _wxFB_c_data_type_select( wxCommandEvent& event ){ c_data_type_select( event ); }
		void _wxFB_c_start( wxCommandEvent& event ){ c_start( event ); }
		void _wxFB_c_main_chk( wxCommandEvent& event ){ c_main_chk( event ); }
		void _wxFB_c_memfunc_chk( wxCommandEvent& event ){ c_memfunc_chk( event ); }

	protected:
		enum
		{
			wxID_rtype_choice = 1000,
			wxID_ptr_check,
			wxID_func_name,
			wxID_memfunc_chk,
			wxID_func_params,
			wxID_main_chk,
			wxID_start_func
		};
		
		wxString returntype;
		wxPanel* m_start_main;
		wxStaticText* t_data_type;
		wxComboBox* m_rtype_choice;
		wxCheckBox* m_ptr_check;
		wxStaticText* t_funcname;
		wxTextCtrl* t_func_name;
		wxCheckBox* m_check_main;
		wxStaticText* t_class_label;
		wxTextCtrl* t_class_name;
		wxCheckBox* m_memfunc_chk;
		wxStaticText* t_funcparams;
		wxTextCtrl* t_func_params;
		wxButton* m_start_func;
		
		void c_data_type_select( wxCommandEvent& event );
		void c_start( wxCommandEvent& event );
		void c_main_chk( wxCommandEvent& event );
		void c_memfunc_chk( wxCommandEvent& event );

	public:
		
		StartDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Start!"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 338,213 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		void disable_main_chk();
		~StartDialog()
		{
			EndModal(wxID_CANCEL);
		}
};

#endif 
