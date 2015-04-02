#ifndef __MAINFRAME_H__
#define __MAINFRAME_H__


#include <wx/utils.h> 
#include <wx/artprov.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/notebook.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/msgdlg.h> // for message box dialog
#include <wx/filedlg.h>//for file dialog
#include <wx/intl.h> // for _(" some text ") macro
#include <wx/textfile.h>

#include "class_dialog.h"
#include "dialog_if.h"
#include "dialog_loop.h"
#include "dialog_operation.h"
#include "frame_var.h"
#include "struct_dialog.h"
#include "dialog_cin.h"
#include "dialog_cout.h"
#include "start_dialog.h"
#include "call_dialog.h"
#include "control.h"
#include "dialog_include.h"



class MainFrame : public wxFrame 
{
	DECLARE_EVENT_TABLE()
	private:
		void _wxFB_c_txtmodified( wxCommandEvent& event ){ c_txtmodified( event ); }
		void _wxFB_c_var_p( wxCommandEvent& event ){ c_var_p( event ); }
		void _wxFB_c_operation_p( wxCommandEvent& event ){ c_operation_p( event ); }
		void _wxFB_c_if_p( wxCommandEvent& event ){ c_if_p( event ); }
		void _wxFB_c_loop_p( wxCommandEvent& event ){ c_loop_p( event ); }
		void _wxFB_c_call_p( wxCommandEvent& event ){ c_call_p( event ); }
		void _wxFB_c_start( wxCommandEvent& event ){ c_start( event ); }
		void _wxFB_c_end( wxCommandEvent& event ){ c_end( event ); }
		void _wxFB_c_read( wxCommandEvent& event ){ c_read( event ); }
		void _wxFB_c_display( wxCommandEvent& event ){ c_display( event ); }
		void _wxFB_c_var_d( wxCommandEvent& event ){ c_var_d( event ); }
		void _wxFB_c_struct_d( wxCommandEvent& event ){ c_struct_d( event ); }
		void _wxFB_c_class_d( wxCommandEvent& event ){ c_class_d( event ); }
		void _wxFB_c_conv( wxCommandEvent& event ){ c_conv( event ); }
		void _wxFB_c_runcpp( wxCommandEvent& event ){ c_runcpp( event ); }
		void _wxFB_fm_new( wxCommandEvent& event ){ fm_new( event ); }
		void _wxFB_fm_save( wxCommandEvent& event ){ fm_save( event ); }
		void _wxFB_fm_open( wxCommandEvent& event ){ fm_open( event ); }
		void _wxFB_fm_exit( wxCommandEvent& event ){ fm_exit( event ); }
		void _wxFB_fm_clear( wxCommandEvent& event ){ fm_clear( event ); }
		void _wxFB_fm_include_lib( wxCommandEvent& event ){ fm_include_lib( event ); }
		void _wxFB_fm_conv( wxCommandEvent& event ){ fm_conv( event ); }
		void _wxFB_fm_cppsave( wxCommandEvent& event ){ fm_cppsave( event ); }
		void _wxFB_fm_compile( wxCommandEvent& event ){ fm_compile( event ); }
		void _wxFB_fm_run( wxCommandEvent& event ){ fm_run( event ); }
		void _wxFB_fm_about( wxCommandEvent& event ){ fm_about( event ); }
		
	
	public:
		enum
		{
			wxID_code_input = 1000,
			wxID_var_p,
			wxID_operation_p,
			wxID_if_p,
			wxID_loop_p,
			wxID_call_p,
			wxID_func_p,
			wxID_start,
			wxID_end,
			wxID_read,
			wxID_display,
			wxID_data_input,
			wxID_var_d,
			wxID_struct_d,
			wxID_class_d,
			wxID_cppOP,
			wxID_conv,
			wxID_runcpp,
			wxID_new,
			wxID_save,
			wxID_save_as,
			wxID_open,
			wxID_exit,
			wxID_clear,
			wxID_generate,
			wxID_convert,
			wxID_compile,
			wxID_run,
			wxID_include_lib,
			wxID_about
		};
		
		wxPanel* mainpanel;
		wxPanel* m_Editors;
		wxNotebook* m_pseudo_code;
		wxPanel* m_psuedo_panel;
		wxTextCtrl* t_code_input;
		wxPanel* m_pseudo_buttons;
		wxButton* m_var_p;
		wxButton* m_operation_p;
		wxButton* m_if_p;
		wxButton* m_loop_p;
		wxButton* m_call_p;
		wxButton* m_start;
		wxButton* m_end;
		wxButton* m_read;
		wxButton* m_display;
		wxPanel* m_cls_struct_panel;
		wxTextCtrl* t_data_input;
		wxPanel* m_buttons;
		wxButton* m_var_d;
		wxButton* m_struct_d;
		wxButton* m_class_d;
		wxPanel* m_cpp_code;
		wxStaticText* t_cpp;
		wxTextCtrl* t_cpp_output;
		wxPanel* m_UtilityBar;
		wxButton* m_conv;
		wxButton* m_runcpp;
		wxMenuBar* m_menubar;
		wxMenu* m_Filemenu;
		wxMenu* m_ActionMenu;
		wxMenu* m_HelpMenu;
		wxStatusBar* m_statusBar;
		
		void c_txtmodified( wxCommandEvent& event );
		void c_var_p( wxCommandEvent& event );
		void c_operation_p( wxCommandEvent& event );
		void c_if_p( wxCommandEvent& event );
		void c_loop_p( wxCommandEvent& event );
		void c_call_p( wxCommandEvent& event );
		void c_start( wxCommandEvent& event );
		void c_end( wxCommandEvent& event );
		void c_read ( wxCommandEvent& event );
		void c_display ( wxCommandEvent& event );
		void c_var_d( wxCommandEvent& event );
		void c_struct_d( wxCommandEvent& event );
		void c_class_d( wxCommandEvent& event );
		void c_conv( wxCommandEvent& event );
		void c_runcpp( wxCommandEvent& event );
		void fm_new( wxCommandEvent& event );
		void fm_save( wxCommandEvent& event );
		void fm_open( wxCommandEvent& event );
		void fm_exit( wxCommandEvent& event );
		void fm_clear( wxCommandEvent& event );
		void fm_include_lib( wxCommandEvent& event );
		void fm_conv( wxCommandEvent& event );
		void fm_cppsave( wxCommandEvent& event );
		void fm_compile( wxCommandEvent& event );
		void fm_run( wxCommandEvent& event );
		void fm_about( wxCommandEvent& event );
		
	
	public:
		void open_psc();
		bool save();
		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Psuedo Code Translator!"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 906,698 ), long style = wxDEFAULT_FRAME_STYLE|wxMAXIMIZE|wxTAB_TRAVERSAL );	
};

#endif 
