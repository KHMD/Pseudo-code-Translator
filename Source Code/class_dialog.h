#ifndef __CLASS_DIALOG_H__
#define __CLASS_DIALOG_H__

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
#include "frame_var.h"
#include "func_dialog.h"
#include "struct_dialog.h"
#include "control.h"


class ClassDialog : public wxDialog 
{
	DECLARE_EVENT_TABLE()
	private:
		void _wxFB_c_addmember( wxCommandEvent& event ){ c_addmember( event ); }
		void _wxFB_c_createclass( wxCommandEvent& event ){ c_createclass( event ); }
		
	protected:
		enum
		{
			wxID_name_class = 1000,
			wxID_addmember,
			wxID_create_class
		};
		
		wxPanel* m_class_main;
		wxStaticText* t_cls_namelabel;
		wxTextCtrl* t_name_class;
		wxStaticText* t_cls_addmem;
		wxRadioBox* m_mem_type;
		wxRadioBox* m_visibilitybox;
		wxButton* m_addmember;
		wxStaticText* t_cls_memlist;
		wxTextCtrl* t_memberlist;
		wxButton* m_createclass;
		
		void c_addmember( wxCommandEvent& event );
		void c_createclass( wxCommandEvent& event );
		wxString sortaccess (wxString input);
		
	public:
		
		ClassDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Class Dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 495,446 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~ClassDialog()
		{
		  EndModal(wxID_CANCEL);
		}
};

#endif
