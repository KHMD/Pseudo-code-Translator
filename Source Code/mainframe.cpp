#include "mainframe.h"


BEGIN_EVENT_TABLE( MainFrame, wxFrame )
	EVT_TEXT( wxID_code_input, MainFrame::_wxFB_c_txtmodified )
	EVT_TEXT( wxID_data_input, MainFrame::_wxFB_c_txtmodified )
	EVT_BUTTON( wxID_var_p, MainFrame::_wxFB_c_var_p )
	EVT_BUTTON( wxID_operation_p, MainFrame::_wxFB_c_operation_p )
	EVT_BUTTON( wxID_if_p, MainFrame::_wxFB_c_if_p )
	EVT_BUTTON( wxID_loop_p, MainFrame::_wxFB_c_loop_p )
	EVT_BUTTON( wxID_call_p, MainFrame::_wxFB_c_call_p )
	EVT_BUTTON( wxID_start, MainFrame::_wxFB_c_start )
	EVT_BUTTON( wxID_end, MainFrame::_wxFB_c_end )
	EVT_BUTTON( wxID_read, MainFrame::_wxFB_c_read )
	EVT_BUTTON( wxID_display, MainFrame::_wxFB_c_display )
	EVT_BUTTON( wxID_var_d, MainFrame::_wxFB_c_var_d )
	EVT_BUTTON( wxID_struct_d, MainFrame::_wxFB_c_struct_d )
	EVT_BUTTON( wxID_class_d, MainFrame::_wxFB_c_class_d )
	EVT_BUTTON( wxID_conv, MainFrame::_wxFB_c_conv )
	EVT_BUTTON( wxID_runcpp, MainFrame::_wxFB_c_runcpp )
	EVT_MENU( wxID_new, MainFrame::_wxFB_fm_new )
	EVT_MENU( wxID_save, MainFrame::_wxFB_fm_save )
	EVT_MENU( wxID_save_as, MainFrame::save )
	EVT_MENU( wxID_open, MainFrame::_wxFB_fm_open )
	EVT_MENU( wxID_exit, MainFrame::_wxFB_fm_exit )
	EVT_MENU( wxID_clear, MainFrame::_wxFB_fm_clear )
	EVT_MENU( wxID_include_lib, MainFrame::_wxFB_fm_include_lib )
	EVT_MENU( wxID_generate, MainFrame::_wxFB_fm_conv )
	EVT_MENU( wxID_convert, MainFrame::_wxFB_fm_cppsave )
	EVT_MENU( wxID_compile, MainFrame::_wxFB_fm_compile )
	EVT_MENU( wxID_run, MainFrame::_wxFB_fm_run )
	EVT_MENU( wxID_about, MainFrame::_wxFB_fm_about )
END_EVENT_TABLE()

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{	
	n_ind=0; //intializing the extent of indentation to 0.
	is_cpp_saved = false;
	wxBoxSizer* s_main_sizer;
	s_main_sizer = new wxBoxSizer( wxVERTICAL );
	
	mainpanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	wxBoxSizer* s_primary_elements;
	s_primary_elements = new wxBoxSizer( wxVERTICAL );
	
	m_Editors = new wxPanel( mainpanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	wxBoxSizer* s_editors;
	s_editors = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* s_pseudo_main;
	s_pseudo_main = new wxBoxSizer( wxVERTICAL );
	
	m_pseudo_code = new wxNotebook( m_Editors, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_psuedo_panel = new wxPanel( m_pseudo_code, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	wxBoxSizer* s_pseudo_code;
	s_pseudo_code = new wxBoxSizer( wxVERTICAL );
	
	t_code_input = new wxTextCtrl( m_psuedo_panel, wxID_code_input, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxTE_MULTILINE|wxTE_PROCESS_TAB );
	t_code_input->SetFont( wxFont( 10, 74, 90, 90, false, wxT("Courier New") ) );
	s_pseudo_code->Add( t_code_input, 1, wxALL|wxEXPAND, 5 );
	
	m_pseudo_buttons = new wxPanel( m_psuedo_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	wxBoxSizer* s_psudo_control;
	s_psudo_control = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* s_var_p;
	s_var_p = new wxBoxSizer( wxVERTICAL );
	
	m_var_p = new wxButton( m_pseudo_buttons, wxID_var_p, wxT("Variable"), wxDefaultPosition, wxDefaultSize, 0 );
	m_var_p->Enable( false );
	m_var_p->SetToolTip( wxT("Create a local variable,object or structure variable") );
	
	s_var_p->Add( m_var_p, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxEXPAND|wxTOP, 5 );
	
	
	s_psudo_control->Add( s_var_p, 1, wxEXPAND, 5 );
	
	wxBoxSizer* s_operation_p;
	s_operation_p = new wxBoxSizer( wxVERTICAL );
	
	m_operation_p = new wxButton( m_pseudo_buttons, wxID_operation_p, wxT("Operation"), wxDefaultPosition, wxDefaultSize, 0 );
	m_operation_p->Enable( false );
	m_operation_p->SetToolTip( wxT("Insert an operation statement (eg: C = A + B )") );
	
	s_operation_p->Add( m_operation_p, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxEXPAND|wxTOP, 5 );
	
	
	s_psudo_control->Add( s_operation_p, 1, wxEXPAND, 5 );
	
	wxBoxSizer* s_if_p;
	s_if_p = new wxBoxSizer( wxVERTICAL );
	
	m_if_p = new wxButton( m_pseudo_buttons, wxID_if_p, wxT("If"), wxDefaultPosition, wxDefaultSize, 0 );
	m_if_p->Enable( false );
	m_if_p->SetToolTip( wxT("Insert an If/Else-If/ Else Block\n") );
	
	s_if_p->Add( m_if_p, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxEXPAND|wxTOP, 5 );
	
	
	s_psudo_control->Add( s_if_p, 1, wxEXPAND, 5 );
	
	wxBoxSizer* s_loop_p;
	s_loop_p = new wxBoxSizer( wxVERTICAL );
	
	m_loop_p = new wxButton( m_pseudo_buttons, wxID_loop_p, wxT("Loop"), wxDefaultPosition, wxDefaultSize, 0 );
	m_loop_p->Enable( false );
	m_loop_p->SetToolTip( wxT("Insert a Looping Construct:\nFor / While / Do - While Loop") );
	
	s_loop_p->Add( m_loop_p, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxEXPAND|wxTOP, 5 );
	
	
	s_psudo_control->Add( s_loop_p, 1, wxEXPAND, 5 );
	
	wxBoxSizer* s_call_p;
	s_call_p = new wxBoxSizer( wxVERTICAL );
	
	m_call_p = new wxButton( m_pseudo_buttons, wxID_call_p, wxT("Call Func"), wxDefaultPosition, wxDefaultSize, 0 );
	m_call_p->Enable( false );
	m_call_p->SetToolTip( wxT("Insert a function call") );
	
	s_call_p->Add( m_call_p, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxEXPAND|wxTOP, 5 );
	
	
	s_psudo_control->Add( s_call_p, 1, wxEXPAND, 5 );
	
	
	m_pseudo_buttons->SetSizer( s_psudo_control );
	m_pseudo_buttons->Layout();
	s_psudo_control->Fit( m_pseudo_buttons );
	s_pseudo_code->Add( m_pseudo_buttons, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* s_blocks;
	s_blocks = new wxBoxSizer( wxHORIZONTAL );
	
	m_start = new wxButton( m_psuedo_panel, wxID_start, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0 );
	m_start->Enable( true );
	s_blocks->Add( m_start, 1, wxALL|wxEXPAND, 5 );

	
	m_end = new wxButton( m_psuedo_panel, wxID_end, wxT("End"), wxDefaultPosition, wxDefaultSize, 0 );
	m_end->Enable( false );
	
	s_blocks->Add( m_end, 1, wxALL|wxEXPAND, 5 );
	
	m_read = new wxButton( m_psuedo_panel, wxID_read, wxT("Read Input"), wxDefaultPosition, wxDefaultSize, 0 );
	m_read->Enable( false );
	m_read->SetToolTip( wxT("Insert code to read input from user") );
	
	s_blocks->Add( m_read, 1, wxALL, 5 );
	
	m_display = new wxButton( m_psuedo_panel, wxID_display, wxT("Display"), wxDefaultPosition, wxDefaultSize, 0 );
	m_display->Enable( false );
	m_display->SetToolTip( wxT("Insert code to display output to user") );
	
	s_blocks->Add( m_display, 1, wxALL, 5 );
	
	
	s_pseudo_code->Add( s_blocks, 0, wxEXPAND, 5 );
	
	
	m_psuedo_panel->SetSizer( s_pseudo_code );
	m_psuedo_panel->Layout();
	s_pseudo_code->Fit( m_psuedo_panel );
	m_pseudo_code->AddPage( m_psuedo_panel, wxT("Psuedo Code"), true );
	m_cls_struct_panel = new wxPanel( m_pseudo_code, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	wxBoxSizer* s_cls_struct;
	s_cls_struct = new wxBoxSizer( wxVERTICAL );
	
	t_data_input = new wxTextCtrl( m_cls_struct_panel, wxID_data_input, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxTE_MULTILINE|wxTE_PROCESS_TAB );
	t_data_input->SetFont( wxFont( 10, 74, 90, 90, false, wxT("Courier New") ) );
	s_cls_struct->Add( t_data_input, 1, wxALL|wxEXPAND, 5 );
	
	m_buttons = new wxPanel( m_cls_struct_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	wxBoxSizer* PsudoControls;
	PsudoControls = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* s_var_d;
	s_var_d = new wxBoxSizer( wxVERTICAL );
	
	m_var_d = new wxButton( m_buttons, wxID_var_d, wxT("Variable"), wxDefaultPosition, wxDefaultSize, 0 );
	m_var_d->SetToolTip( wxT("Create a variable") );
	
	s_var_d->Add( m_var_d, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxEXPAND|wxTOP, 5 );
	
	
	PsudoControls->Add( s_var_d, 1, wxEXPAND, 5 );
		
	wxBoxSizer* s_struct_d;
	s_struct_d = new wxBoxSizer( wxVERTICAL );
	
	m_struct_d = new wxButton( m_buttons, wxID_struct_d, wxT("Structure"), wxDefaultPosition, wxDefaultSize, 0 );
	m_struct_d->SetToolTip( wxT("Create a Structure") );
	
	s_struct_d->Add( m_struct_d, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxEXPAND|wxTOP, 5 );
	
	
	PsudoControls->Add( s_struct_d, 1, wxEXPAND, 5 );
	
	wxBoxSizer* s_class_d;
	s_class_d = new wxBoxSizer( wxVERTICAL );
	
	m_class_d = new wxButton( m_buttons, wxID_class_d, wxT("Class"), wxDefaultPosition, wxDefaultSize, 0 );
	m_class_d->SetToolTip( wxT("Create a Class") );
	
	s_class_d->Add( m_class_d, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxEXPAND|wxTOP, 5 );
	
	
	PsudoControls->Add( s_class_d, 1, wxEXPAND, 5 );
	
	
	m_buttons->SetSizer( PsudoControls );
	m_buttons->Layout();
	PsudoControls->Fit( m_buttons );
	s_cls_struct->Add( m_buttons, 0, wxALL|wxEXPAND, 5 );
	
	
	m_cls_struct_panel->SetSizer( s_cls_struct );
	m_cls_struct_panel->Layout();
	s_cls_struct->Fit( m_cls_struct_panel );
	m_pseudo_code->AddPage( m_cls_struct_panel, wxT("Globals"), false );
	
	s_pseudo_main->Add( m_pseudo_code, 1, wxEXPAND | wxALL, 5 );
	
	
	s_editors->Add( s_pseudo_main, 1, wxEXPAND, 5 );
	
	wxBoxSizer* s_cpp_code;
	s_cpp_code = new wxBoxSizer( wxVERTICAL );
	
	m_cpp_code = new wxPanel( m_Editors, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );
	
	t_cpp = new wxStaticText( m_cpp_code, wxID_ANY, wxT("C++ Code"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( t_cpp, 0, wxALL, 5 );
	
	t_cpp_output = new wxTextCtrl( m_cpp_code, wxID_cppOP, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxTE_MULTILINE );
	t_cpp_output->SetFont( wxFont( 10, 74, 90, 90, false, wxT("Courier New") ) );
	bSizer14->Add( t_cpp_output, 1, wxALL|wxEXPAND, 5 );
	
	
	m_cpp_code->SetSizer( bSizer14 );
	m_cpp_code->Layout();
	bSizer14->Fit( m_cpp_code );
	s_cpp_code->Add( m_cpp_code, 1, wxEXPAND | wxALL, 5 );
	
	
	s_editors->Add( s_cpp_code, 1, wxEXPAND, 5 );
	
	
	m_Editors->SetSizer( s_editors );
	m_Editors->Layout();
	s_editors->Fit( m_Editors );
	s_primary_elements->Add( m_Editors, 1, wxEXPAND | wxALL, 5 );
	
	m_UtilityBar = new wxPanel( mainpanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	wxBoxSizer* s_quick_access;
	s_quick_access = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* s_quick_acees_holder;
	s_quick_acees_holder = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* s_generate;
	s_generate = new wxBoxSizer( wxVERTICAL );
	
	m_conv = new wxButton( m_UtilityBar, wxID_conv, wxT("Generate C++"), wxDefaultPosition, wxDefaultSize, 0 );
	m_conv->Enable( false );
	m_conv->SetToolTip( wxT("Convert Psuedo Code to C++ ") );
	
	s_generate->Add( m_conv, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	
	s_quick_acees_holder->Add( s_generate, 1, 0, 5 );
	
	wxBoxSizer* s_comp_run;
	s_comp_run = new wxBoxSizer( wxVERTICAL );
	
	m_runcpp = new wxButton( m_UtilityBar, wxID_runcpp, wxT("Compile and Run"), wxDefaultPosition, wxDefaultSize, 0 );
	m_runcpp->Enable( false );
	m_runcpp->SetToolTip( wxT("Compile and Execute converted C++ code") );
	
	s_comp_run->Add( m_runcpp, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	
	s_quick_acees_holder->Add( s_comp_run, 1, 0, 5 );
	
	
	s_quick_access->Add( s_quick_acees_holder, 1, wxEXPAND|wxALIGN_RIGHT, 5 );
	
	
	m_UtilityBar->SetSizer( s_quick_access );
	m_UtilityBar->Layout();
	s_quick_access->Fit( m_UtilityBar );
	s_primary_elements->Add( m_UtilityBar, 0, wxALL|wxEXPAND, 5 );
	
	
	mainpanel->SetSizer( s_primary_elements );
	mainpanel->Layout();
	s_primary_elements->Fit( mainpanel );
	s_main_sizer->Add( mainpanel, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( s_main_sizer );
	this->Layout();
	m_menubar = new wxMenuBar( 0 );
	m_Filemenu = new wxMenu();
	wxMenuItem* m_new;
	m_new = new wxMenuItem( m_Filemenu, wxID_new, wxString( wxT("New") ) , wxT("Create a new psuedo code file"), wxITEM_NORMAL );
	m_Filemenu->Append( m_new );

	wxMenuItem* m_open;
	m_open = new wxMenuItem( m_Filemenu, wxID_open, wxString( wxT("Open") ) , wxT("Open psuedo code file from Disk"), wxITEM_NORMAL );
	m_Filemenu->Append( m_open );
	
	wxMenuItem* m_save;
	m_save = new wxMenuItem( m_Filemenu, wxID_save, wxString( wxT("Save") ) , wxT("Save current psuedo code file to Disk"), wxITEM_NORMAL );
	m_Filemenu->Append( m_save );
	
	wxMenuItem* m_save_as;
	m_save_as = new wxMenuItem( m_Filemenu, wxID_save_as, wxString( wxT("Save As") ) , wxT("Save as new psuedo code file to Disk"), wxITEM_NORMAL );
	m_Filemenu->Append( m_save_as );
		
	wxMenuItem* m_exit;
	m_exit = new wxMenuItem( m_Filemenu, wxID_exit, wxString( wxT("Exit") ) , wxT("Close the program"), wxITEM_NORMAL );
	m_Filemenu->Append( m_exit );
	
	m_menubar->Append( m_Filemenu, wxT("File") ); 
	
	m_ActionMenu = new wxMenu();
	
	wxMenuItem* m_clear;
	m_clear = new wxMenuItem( m_ActionMenu, wxID_clear, wxString( wxT("Clear") ) , wxT("Clears both Psuedo code and Globals tab"), wxITEM_NORMAL );
	m_ActionMenu->Append( m_clear );
	
	wxMenuItem* m_include_lib;
	m_include_lib = new wxMenuItem( m_ActionMenu, wxID_include_lib, wxString( wxT("Include Libraries") ) , wxT("Generate C++ code from Psuedo Code"), wxITEM_NORMAL );
	m_ActionMenu->Append( m_include_lib );
	
	wxMenuItem* m_generate;
	m_generate = new wxMenuItem( m_ActionMenu, wxID_generate, wxString( wxT("&Generate C++") ) , wxT("Generate C++ code from Psuedo Code"), wxITEM_NORMAL );
	m_ActionMenu->Append( m_generate );
	
	wxMenuItem* m_convert;
	m_convert = new wxMenuItem( m_ActionMenu, wxID_convert, wxString( wxT("Save as  .cpp") ) , wxT("Save the converted c++ code to Disk"), wxITEM_NORMAL );
	m_ActionMenu->Append( m_convert );
	m_convert->Enable(true);
	
	wxMenuItem* m_compile;
	m_compile = new wxMenuItem( m_ActionMenu, wxID_compile, wxString( wxT("Compile C++ Code") ) , wxT("Compile converted psuedo code using gcc make"), wxITEM_NORMAL );
	m_ActionMenu->Append( m_compile );
	m_compile->Enable( false );
	
	wxMenuItem* m_run;
	m_run = new wxMenuItem( m_ActionMenu, wxID_run, wxString( wxT("Run C++ Code") ) , wxT("Run compiled c++ code"), wxITEM_NORMAL );
	m_ActionMenu->Append( m_run );
	m_run->Enable( false );
	
	m_menubar->Append( m_ActionMenu, wxT("Actions") ); 
	
	m_HelpMenu = new wxMenu();
	wxMenuItem* m_about;
	m_about = new wxMenuItem( m_HelpMenu, wxID_about, wxString( wxT("About") ) , wxEmptyString, wxITEM_NORMAL );
	m_HelpMenu->Append( m_about );
	
	m_menubar->Append( m_HelpMenu, wxT("Help") ); 
	
	this->SetMenuBar( m_menubar );
	
	m_statusBar = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );
	
	n_lib=0;//initialise the libraries counter to zero and include iostream by default;
	include_lib_list[n_lib]<<"#include<iostream>";
}
void MainFrame :: c_var_p( wxCommandEvent& event )//in pseudo code area
{
	VariableDialog *dialog_var = new VariableDialog(this);
	dialog_var->ShowModal();
	delete dialog_var;
	if(!insert_code.IsEmpty())
	{
		for(int i=0;i<n_ind;i++)
		*t_code_input<<"\t";
		stk_l_no.inc_step();//start of printing line number
		int num=0;//number of substeps, eg 1.1.1 then num=3
		while(stk_l_no.ret_top()>-1)
		{
			temp_l_no[num]=stk_l_no.pop();
			 num++;
		}
		for(int i=num-1;i>=0;i--)
		{
			*t_code_input<<temp_l_no[i]<<".";
			stk_l_no.push(temp_l_no[i]);
		}//end of printing line number
		is_file_saved=false;
		SetStatusText(wxT("Recent Changes Not Saved"));
		SetTitle(wxString("Pseudo Code Translator - ") << CurrentDocPath<<"*");
		*t_code_input<<" "<<insert_code<<"\n";
	}
}
void MainFrame :: c_operation_p( wxCommandEvent& event )//in pseudo code area
{
	OperationDialog *dialog_operation = new OperationDialog(this);
	dialog_operation->ShowModal();
	delete dialog_operation;
	if(!insert_code.IsEmpty())
	{
		for(int i=0;i<n_ind;i++)
		*t_code_input<<"\t";
		stk_l_no.inc_step();//start of printing line number
		int num=0;//number of substeps, eg 1.1.1 then num=3
		while(stk_l_no.ret_top()>-1)
		{
			temp_l_no[num]=stk_l_no.pop();
			 num++;
		}
		for(int i=num-1;i>=0;i--)
		{
			*t_code_input<<temp_l_no[i]<<".";
			stk_l_no.push(temp_l_no[i]);
		}//end of printing line number
		is_file_saved=false;
		*t_code_input<<" "<<insert_code<<"\n";
	}	
}
void MainFrame :: c_if_p( wxCommandEvent& event )//in pseudo code area
{
	IfDialog *dialog_if = new IfDialog(this);
	dialog_if->ShowModal();
	delete dialog_if;
	if(!insert_code.IsEmpty())
	{
		for(int i=0;i<n_ind;i++)
		*t_code_input<<"\t";
		stk_l_no.inc_step();//start of printing line number
		int num=0;//number of substeps, eg 1.1.1 then num=3
		while(stk_l_no.ret_top()>-1)
		{
			temp_l_no[num]=stk_l_no.pop();
			 num++;
		}
		for(int i=num-1;i>=0;i--)
		{
			*t_code_input<<temp_l_no[i]<<".";
			stk_l_no.push(temp_l_no[i]);
		}//end of printing line number
		stk_l_no.push(0);
		is_file_saved=false;
		*t_code_input<<" "<<insert_code<<"\n";
		m_end->SetLabel(endlabel_text);		
		n_ind++;
	}
}
void MainFrame :: c_loop_p( wxCommandEvent& event )//in pseudo code area
{
	LoopDialog *dialog_loop = new LoopDialog(this);
	dialog_loop->ShowModal();
	delete dialog_loop;
	if(!insert_code.IsEmpty())
	{
		for(int i=0;i<n_ind;i++)
		*t_code_input<<"\t";
		stk_l_no.inc_step();//start of printing line number
		int num=0;//number of substeps, eg 1.1.1 then num=3
		while(stk_l_no.ret_top()>-1)
		{
			temp_l_no[num]=stk_l_no.pop();
			 num++;
		}
		for(int i=num-1;i>=0;i--)
		{
			*t_code_input<<temp_l_no[i]<<".";
			stk_l_no.push(temp_l_no[i]);
		}//end of printing line number
		stk_l_no.push(0);
		is_file_saved=false;
		*t_code_input<<" "<<insert_code<<"\n";
		m_end->SetLabel(endlabel_text);		
		n_ind++;
	}
}

void MainFrame :: c_read( wxCommandEvent& event )
{
	CinDialog *dialog_cin = new CinDialog(this);
	dialog_cin->ShowModal();
	delete dialog_cin;
	if(!insert_code.IsEmpty())
	{
		for(int i=0;i<n_ind;i++)
		*t_code_input<<"\t";
		stk_l_no.inc_step();//start of printing line number
		int num=0;//number of substeps, eg 1.1.1 then num=3
		while(stk_l_no.ret_top()>-1)
		{
			temp_l_no[num]=stk_l_no.pop();
			 num++;
		}
		for(int i=num-1;i>=0;i--)
		{
			*t_code_input<<temp_l_no[i]<<".";
			stk_l_no.push(temp_l_no[i]);
		}//end of printing line number
		is_file_saved=false;
		*t_code_input<<" "<<insert_code<<"\n";
	}	
}

void MainFrame :: c_display( wxCommandEvent& event )
{
	CoutDialog *dialog_cout = new CoutDialog(this);
	dialog_cout->ShowModal();
	delete dialog_cout;
	if(!insert_code.IsEmpty())
	{
		for(int i=0;i<n_ind;i++)
		*t_code_input<<"\t";
		stk_l_no.inc_step();//start of printing line number
		int num=0;//number of substeps, eg 1.1.1 then num=3
		while(stk_l_no.ret_top()>-1)
		{
			temp_l_no[num]=stk_l_no.pop();
			 num++;
		}
		for(int i=num-1;i>=0;i--)
		{
			*t_code_input<<temp_l_no[i]<<".";
			stk_l_no.push(temp_l_no[i]);
		}//end of printing line number
		is_file_saved=false;
		*t_code_input<<" "<<insert_code<<"\n";
	}	
}

void MainFrame :: c_call_p( wxCommandEvent& event )//in pseudo code area
{


	FnCallDialog *calldialog = new FnCallDialog(this);
	calldialog->ShowModal();
	delete calldialog;
	if(!insert_code.IsEmpty())
	{
		for(int i=0;i<n_ind;i++)
		*t_code_input<<"\t";
		stk_l_no.inc_step();//start of printing line number
		int num=0;//number of substeps, eg 1.1.1 then num=3
		while(stk_l_no.ret_top()>-1)
		{
			temp_l_no[num]=stk_l_no.pop();
			 num++;
		}
		for(int i=num-1;i>=0;i--)
		{
			*t_code_input<<temp_l_no[i]<<".";
			stk_l_no.push(temp_l_no[i]);
		}//end of printing line number
		is_file_saved=false;
		*t_code_input<<" "<<insert_code<<"\n";
	}		
}
void MainFrame :: c_start( wxCommandEvent& event )//in pseudo code area
{
	
	wxString mainfinder;
	mainfinder= t_code_input->GetValue();
	if(mainfinder.Find("main")>=0)//main exists! This check is done just incase the person has mainualy entered main function!
	 {
		is_main_def=true;					
	 }
	else
	 {
		is_main_def=false;
	 }
	StartDialog *dialog_start = new StartDialog(this);
	if(is_main_def)
	dialog_start->disable_main_chk();
	dialog_start->ShowModal();
	delete dialog_start;
	if(!insert_code.IsEmpty())
	{
		m_conv->Enable(true);
		m_var_p->Enable();
		m_operation_p->Enable();
		m_if_p->Enable();
		m_loop_p->Enable();
		m_call_p->Enable();
		m_end->Enable();
		m_read->Enable();
		m_display->Enable();
		stk_l_no.push(0);
		is_file_saved=false;
		*t_code_input<<insert_code;
		m_end->SetLabel(endlabel_text);
		m_start->Enable(false);
		n_ind++;
	}
}
void MainFrame :: c_end( wxCommandEvent& event )//in pseudo code area
{
	n_ind--;
	stk_l_no.pop();
	for(int i=0;i<n_ind;i++)
	*t_code_input<<"\t";
	*t_code_input<<stk_p_block.pop();
	*t_code_input<<"\n";
	if(n_ind==0)
	{
		m_var_p->Disable();
		m_operation_p->Disable();
		m_if_p->Disable();
		m_loop_p->Disable();
		m_call_p->Disable();
		m_read->Disable();
		m_display->Disable();
		m_start->Enable(true);
		m_end->Enable(false);
	}	
	if(!stk_p_block.IsEmpty())
	   m_end->SetLabel(stk_p_block.getTop());
	is_file_saved=false;
		
}
void MainFrame :: c_var_d( wxCommandEvent& event )//in global area
{
	VariableDialog *dialog_var = new VariableDialog(this);
	dialog_var->ShowModal();
	delete dialog_var;
	if(!insert_code.IsEmpty())
	{
		is_file_saved=false;
		*t_data_input<< "\n" << insert_code;
	}
}

void MainFrame :: c_struct_d( wxCommandEvent& event )//in global area
{
	StructDialog *dialog_struct = new StructDialog(this);
	dialog_struct->ShowModal();
	delete dialog_struct;
	if(!insert_code.IsEmpty())
	{
		is_file_saved=false;
		*t_data_input<< "\n" << insert_code;
	}
}	
void MainFrame :: c_class_d( wxCommandEvent& event )//in global area
{
	ClassDialog *dialog_class = new ClassDialog(this);
	dialog_class->ShowModal();
	delete dialog_class;
	if(!insert_code.IsEmpty())
	{
		is_file_saved=false;
		*t_data_input<< "\n" << insert_code;
	}
}
void MainFrame :: c_conv( wxCommandEvent& event )//in common area
{
	fm_conv(event);//To minimise duplication of code;
	/*if(!is_file_saved)
	{
		save();	
	}
	t_cpp_output->Clear();
	*t_cpp_output<<"#include<iostream>\n";
	for(int i=0;i<n_lib;i++)
	*t_cpp_output<<include_lib_list[n_lib];
	*t_cpp_output<<"\nusing namespace std;";
	wxTextFile file;
	file.Open(CurrentDocPath);
	//to be continued with the rest of the conversion......... */
}
void MainFrame :: c_runcpp( wxCommandEvent& event )//in common area
{
	fm_compile(event);
	fm_run(event);
}
void MainFrame :: fm_new( wxCommandEvent& event )//in common area
{
	//call clear event
	fm_clear(event);
	// Set the Title to reflect the file open
	SetTitle(_T("Pseudo Code Translator - * untitled.psc"));
}

void MainFrame :: fm_clear( wxCommandEvent& event )
{
	is_file_saved=false;
	m_conv->Enable(false);
	// Clear the edit box
	t_code_input->Clear();
	t_data_input->Clear();
	t_cpp_output->Clear();
	// reset the variables, and controls!
	for(int i=0;i<100;i++)
	{
		include_lib_list[i].Empty();
	}
	n_lib=0;
	include_lib_list[n_lib]<<"#include<iostream>";
	m_var_p->Disable();
	m_operation_p->Disable();
	m_if_p->Disable();
	m_loop_p->Disable();
	m_call_p->Disable();
	m_read->Disable();
	m_display->Disable();
	m_start->Enable(true);
	m_end->Enable(false);	
	n_ind=0;
	is_main_def=false;
	insert_code.Empty();
	endlabel_text.Empty();
	while(stk_l_no.ret_top()!=-1)
	{
		stk_l_no.pop();	
	}
	while(!stk_p_block.IsEmpty())
	{
		wxString x;
		x=stk_p_block.pop();
	}
}

void MainFrame :: fm_save( wxCommandEvent& event )//in common area
{
	if(CurrentDocPath.IsEmpty())
	save();
	else
	{
		wxTextFile file;
		file.Create(CurrentDocPath);
		if(file.IsOpened())
		{
			wxString tempString,tempString2;
			int linenos[100],ltop;
			tempString <<"@Begin\n"<<t_code_input->GetValue();
			tempString<< "$" << t_data_input->GetValue()<<"\n#"<<n_lib<<"^\n";
			for(int i=0;i<=n_lib;i++)
				tempString<<include_lib_list[i]<<"%\n";//write the include files list
			tempString2<<stk_p_block.getlist();
			tempString<<"$"<<stackcount<<"#"<<tempString2;//write the end labels
			ltop = stk_l_no.ret_top();
			tempString<<"\n^"<<ltop<<"#"<<n_ind<<"#";//write the line numbers
			stk_l_no.ret_array(linenos);
			for(int i = 0;i<=ltop;i++)
			tempString<<linenos[i]<<"%";
			tempString<<"\n@EndCode\n";
			file.AddLine(tempString);
			file.Write();
			// Set the Title to reflect the file open
			is_file_saved=true;
			SetTitle(wxString("Pseudo Code Translator - ") << CurrentDocPath) ;
		}
	}
}
bool MainFrame :: save()
{
	wxFileDialog *SaveDialog = new wxFileDialog(this, _("Save File"), wxEmptyString, wxEmptyString,_("Pseudo Code File (*.psc)|*.psc"),wxSAVE | wxOVERWRITE_PROMPT, wxDefaultPosition);
 	is_file_saved=false;
 	SetTitle(wxString("Pseudo Code Translator - * ") << CurrentDocPath) ;
 	// Creates a Save Dialog 
	if (SaveDialog->ShowModal() == wxID_OK) // If the user clicked "OK" and not cancel
	{	
		CurrentDocPath = SaveDialog->GetPath();// set the path of our current document to the file the user chose to save
		wxTextFile file;
		file.Create(CurrentDocPath);
		if(file.IsOpened())
		{
			wxString tempString,tempString2;
			int linenos[100],ltop;
			tempString <<"@Begin\n"<<t_code_input->GetValue();
			tempString<< "$" << t_data_input->GetValue()<<"\n#"<<n_lib<<"^\n";
			for(int i=0;i<=n_lib;i++)
				tempString<<include_lib_list[i]<<"%\n";//write the include files list
			tempString2<<stk_p_block.getlist();
			tempString<<"$"<<stackcount<<"#"<<tempString2;//write the end labels
			ltop = stk_l_no.ret_top();
			tempString<<"\n^"<<ltop<<"#"<<n_ind<<"#";//write the line numbers
			stk_l_no.ret_array(linenos);
			for(int i = 0;i<=ltop;i++)
			tempString<<linenos[i]<<"%";
			tempString<<"\n@EndCode\n";
			file.AddLine(tempString);
			file.Write();
			// Set the Title to reflect the file open
			is_file_saved=true;
			SetTitle(wxString("Pseudo Code Translator - ") << CurrentDocPath) ;
		}
	}
 
	// Clean up 
	SaveDialog->Destroy();
	return is_file_saved;
}
void MainFrame :: fm_open( wxCommandEvent& event )//in common area
{
	wxFileDialog *OpenDialog = new wxFileDialog(this, _("Choose a Psuedo Code File to open"), wxEmptyString, wxEmptyString,_("Pseudo Code File (*.psc)|*.psc"),wxOPEN, wxDefaultPosition);
 
	if (OpenDialog->ShowModal() == wxID_OK) // do only if the user click "Open"  and not cancel
	{
		CurrentDocPath = OpenDialog->GetPath();// Sets our current document to the file the user selected
 		open_psc();
 		is_file_saved=true;
	}
}
void MainFrame :: open_psc()
{
	wxTextFile file;
	file.Open(CurrentDocPath);
	if(file.IsOpened())
    {
         wxString tempString,pString,gString,mainfinder,n_lib_temp,endlabstack,line_no,tempString2; 
         long int ltop,numholder;
         tempString.Empty();
		 //store file data for further processing
       	 for (wxString str = file.GetFirstLine(); !file.Eof();str = file.GetNextLine())
       	 {
			tempString<<str;
			tempString<<"\n";
		 }
		 tempString.Replace("@Begin\n","");
         
		 pString= tempString.BeforeFirst('$');
         gString= tempString.AfterFirst ('$');
         n_lib_temp = gString;
         gString=gString.BeforeFirst('#');
       	 n_lib_temp = n_lib_temp.AfterFirst('#');
         n_lib_temp = n_lib_temp.BeforeFirst('^');
         n_lib_temp.ToLong(&n_lib);
         n_lib_temp= tempString.AfterFirst('^');
         n_lib_temp = n_lib_temp.BeforeFirst('$');
         n_lib_temp.Replace("\n","");
         n_lib_temp.Replace("%\n","%");
         for(int i=0;i<100;i++)
				include_lib_list[i].Empty();
         for(int i=0;i<=n_lib;i++)
         {
				include_lib_list[i] = n_lib_temp.BeforeFirst('%');
				n_lib_temp = n_lib_temp.AfterFirst('%');
		 }
		 endlabstack = tempString.AfterFirst('$');	
		 endlabstack = endlabstack.AfterFirst('$');
		 line_no = endlabstack.AfterFirst('^');
		 endlabstack = endlabstack.BeforeFirst('^'); 
		 //Handle the End labels;
		 tempString2 = endlabstack.BeforeFirst('#');
		 tempString2.ToLong(&stackcount);
		 endlabstack = endlabstack.AfterFirst('#');
		 while(!stk_p_block.IsEmpty()) //empty the endlabel stack. 
		 {
				stk_p_block.pop();
		 }
		 for(int i=0;i<stackcount;i++)
		 {
			endlabstack = endlabstack.BeforeLast('%');	
			stk_p_block.push(endlabstack.AfterLast('%'));	
		 }
		 //handle line nos
         //line_no contains something like - 2#3#2%2%1%\n@EndCode of format - top,n_ind,last decimal place
         tempString2.Empty();
         tempString2= line_no.BeforeFirst('#');//contains top;
         tempString2.ToLong(&ltop);
         line_no = line_no.AfterFirst('#');
         tempString2.Empty();
         tempString2= line_no.BeforeFirst('#');//contains n_ind;
         tempString2.ToLong(&numholder);
         n_ind = numholder;
         line_no = line_no.AfterFirst('#');//2%2%1%\n@EndCode
         stk_l_no.reset_top();
 		 for(int i = 0;i<=ltop;i++)//push stuff into stack
         {
			 tempString2 = line_no.BeforeFirst('%');
			 line_no = line_no.AfterFirst('%');
			 tempString2.ToLong(&numholder);
			 stk_l_no.push(numholder);
		 }
         if ((pString != tempString) && (gString != tempString))
         {
				t_code_input->Clear();
				*t_code_input<< pString;
				t_data_input->Clear();
				*t_data_input<< gString;
		 }
		 
		//Change buttons
		
		if(!stk_p_block.IsEmpty())
		{
			m_end->SetLabel(stk_p_block.getTop());
			m_end->Enable(true);
			insert_code.Empty();
			m_var_p->Enable();
			m_operation_p->Enable();
			m_if_p->Enable();
			m_loop_p->Enable();
			m_call_p->Enable();
			m_read->Enable();
			m_display->Enable();
			m_start->Disable();
	    }
	    else
	    {
			//Reset the buttons!
		 	m_var_p->Disable();
			m_operation_p->Disable();
			m_if_p->Disable();
			m_loop_p->Disable();
			m_call_p->Disable();
			m_read->Disable();
			m_display->Disable();
			m_start->Enable(true);
			m_end->Enable(false);
			n_ind=0;
			insert_code.Empty();
			endlabel_text.Empty();
	    }
		//Check if main exists
		mainfinder= t_code_input->GetValue();
		if(mainfinder.Find("main")>=0)//main exists...
		 {
			is_main_def=true;	
			m_conv->Enable(true);				
		 }
		else
		 {
			is_main_def=false;
		 }
		// Set the Title to reflect the  file open
		SetTitle(wxString("Pseudo Code Translator - ") << CurrentDocPath);
	}	
}

void MainFrame :: fm_exit( wxCommandEvent& event )//in common area
{
	Close(true);
}
void MainFrame :: fm_include_lib( wxCommandEvent& event )//in common area
{
	IncludeDialog *dialog_include = new IncludeDialog(this);
	dialog_include->ShowModal();
	delete dialog_include;
	c_txtmodified(event);
}
void MainFrame :: fm_conv( wxCommandEvent& event )//in common area
{
	
	if(!is_file_saved)
	{
		fm_save(event);
		if(is_file_saved)
		{
			t_cpp_output->Clear();
			cppinclude.Empty();
			cppglobal.Empty();
			cppcode.Empty();
			cppglobal = conv_globals();//defined in control.cpp
			cppcode = conv_psuedo();
			cppinclude=conv_include_lib();
			*t_cpp_output <<cppinclude<<"\n"<< cppglobal << "\n" <<cppcode;
		}	
	}
	else
	{
		t_cpp_output->Clear();
		cppinclude.Empty();
		cppglobal.Empty();
		cppcode.Empty();
		cppglobal = conv_globals();//defined in control.cpp
		cppcode = conv_psuedo();
		cppinclude=conv_include_lib();
		*t_cpp_output <<cppinclude<<"\n"<< cppglobal << "\n" <<cppcode;
	}
	is_cpp_saved = false;
}
void MainFrame:: c_txtmodified( wxCommandEvent& event )
{
	is_file_saved=false;
 	SetTitle(wxString("Pseudo Code Translator - * ") << CurrentDocPath) ;
}

void MainFrame :: fm_cppsave( wxCommandEvent& event )//in common area Saveascpp
{
    wxFileDialog *SaveDialog = new wxFileDialog(this, _("Save File"), wxEmptyString, wxEmptyString,_("C++ (*.cpp)|*.cpp"),wxSAVE | wxOVERWRITE_PROMPT, wxDefaultPosition);
 	// Creates a Save Dialog 
	if (SaveDialog->ShowModal() == wxID_OK) // If the user clicked "OK" and not cancel
	{	
		CurrentDocPath2 = SaveDialog->GetPath();// set the path of our current document to the file the user chose to save
		wxTextFile file;
		file.Create(CurrentDocPath2);
		if(file.IsOpened())
		{
			wxString tempString;
			tempString <<t_cpp_output->GetValue();
			file.AddLine(tempString);
			file.Write();
		}
		is_cpp_saved = true;
	}
 
	// Clean up 
	SaveDialog->Destroy();
}
void MainFrame :: fm_compile( wxCommandEvent& event )//in common area
{

	
}
void MainFrame :: fm_run( wxCommandEvent& event )//in common area
{
	
}
void MainFrame :: fm_about( wxCommandEvent& event )//in common area
{
	wxString msg;
	msg.Printf( _T("A Project By Sriram Desai and Arjun Rao \n Developed as part of project work, Computer Science 2013-2014 \n Version 1.0"));
    wxMessageBox(msg, _T("About Psuedo Code Translator!"), wxOK | wxICON_INFORMATION, this);
}
