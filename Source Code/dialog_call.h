#ifndef __DIALOG_CALL_H__
#define __DIALOG_CALL_H__

#include <wx/artprov.h>
#include <wx/string.h>
#include <wx/radiobox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/dialog.h>
#include "control.h"

class CallDialog : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		
		void _wxFB_c_ret_chk( wxCommandEvent& event ){ c_ret_chk( event ); }
		void _wxFB_c_call_func( wxCommandEvent& event ){ c_call_func( event ); }
		void _wxFB_c_mem_chk( wxCommandEvent& event ){ c_mem_chk( event ); }
		
	protected:
		enum
		{
			wxID_ret_chk = 1000,
			wxID_condition_input,
			wxID_mem_chk,
			wxID_call_func
		};
		
		wxPanel* m_panel2;
		wxRadioBox* m_ret_chk;
		wxRadioBox* m_mem_func_chk;
		wxStaticText* t_funcname;
		wxTextCtrl* t_func_name_input;
		wxStaticText* t_cls_name;
		wxTextCtrl* t_cls_name_input;
		wxStaticText* t_ret_var_name;
		wxTextCtrl* t_ret_var_name_input;
		wxStaticText* t_para_list;
		wxTextCtrl* t_para_list_input;
		wxButton* m_add_condition;

		void c_ret_chk( wxCommandEvent& event );
		void c_mem_chk( wxCommandEvent& event );
		void c_call_func( wxCommandEvent& event );
	
	public:
		
		CallDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Call a Function"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 507,329 ), long style = wxDEFAULT_DIALOG_STYLE );
		~CallDialog()
		{
			EndModal(wxID_CANCEL);
		}
};

#endif
