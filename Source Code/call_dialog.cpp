#include "call_dialog.h"

BEGIN_EVENT_TABLE( FnCallDialog, wxDialog )
	EVT_RADIOBOX( wxID_ret_chk, FnCallDialog::_wxFB_c_ret_chk )
	EVT_RADIOBOX( wxID_mem_chk, FnCallDialog::_wxFB_c_mem_chk )
	EVT_BUTTON( wxID_call_func, FnCallDialog::_wxFB_c_call_func )
END_EVENT_TABLE()

FnCallDialog::FnCallDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	insert_code.Empty();
	wxBoxSizer* s_main;
	s_main = new wxBoxSizer( wxVERTICAL );
	
	m_calldialog_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* s_calldialog_sizer;
	s_calldialog_sizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* s_radiobox_sizer;
	s_radiobox_sizer = new wxBoxSizer( wxHORIZONTAL );
	
	wxString m_ret_chkChoices[] = { wxT("Yes"), wxT("No") };
	int m_ret_chkNChoices = sizeof( m_ret_chkChoices ) / sizeof( wxString );
	m_ret_chk = new wxRadioBox( m_calldialog_panel, wxID_ret_chk, wxT("Does the function return a value?"), wxDefaultPosition, wxDefaultSize, m_ret_chkNChoices, m_ret_chkChoices, 1, wxRA_SPECIFY_ROWS );
	m_ret_chk->SetSelection( 0 );
	s_radiobox_sizer->Add( m_ret_chk, 0, wxALL|wxEXPAND, 5 );
	
	wxString m_mem_chkChoices[] = { wxT("Yes"), wxT("No") };
	int m_mem_chkNChoices = sizeof( m_mem_chkChoices ) / sizeof( wxString );
	m_mem_chk = new wxRadioBox( m_calldialog_panel, wxID_mem_chk, wxT("Is the function a member function of any class or structure?"), wxDefaultPosition, wxDefaultSize, m_mem_chkNChoices, m_mem_chkChoices, 1, wxRA_SPECIFY_ROWS );
	m_mem_chk->SetSelection( 0 );
	s_radiobox_sizer->Add( m_mem_chk, 1, wxALL, 5 );
	
	
	s_calldialog_sizer->Add( s_radiobox_sizer, 0, wxEXPAND, 5 );
	
	t_funcname = new wxStaticText( m_calldialog_panel, wxID_ANY, wxT("Enter the function name"), wxDefaultPosition, wxDefaultSize, 0 );
	s_calldialog_sizer->Add( t_funcname, 0, wxALL, 5 );
	
	t_func_name_input = new wxTextCtrl( m_calldialog_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	s_calldialog_sizer->Add( t_func_name_input, 0, wxALL|wxEXPAND, 5 );
	
	t_cls_name = new wxStaticText( m_calldialog_panel, wxID_ANY, wxT("Enter the name of the class or structure to which the function belongs"), wxDefaultPosition, wxDefaultSize, 0 );
	s_calldialog_sizer->Add( t_cls_name, 0, wxALL, 5 );
	
	t_cls_name_input = new wxTextCtrl( m_calldialog_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	s_calldialog_sizer->Add( t_cls_name_input, 0, wxALL|wxEXPAND, 5 );
	
	t_ret_var_name = new wxStaticText( m_calldialog_panel, wxID_ANY, wxT("Enter the name of the variable to which the returned value has to be stored"), wxDefaultPosition, wxDefaultSize, 0 );
	s_calldialog_sizer->Add( t_ret_var_name, 0, wxALL, 5 );
	
	t_ret_var_name_input = new wxTextCtrl( m_calldialog_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	s_calldialog_sizer->Add( t_ret_var_name_input, 0, wxALL|wxEXPAND, 5 );
	
	t_para_list = new wxStaticText( m_calldialog_panel, wxID_ANY, wxT("Enter the parameter list"), wxDefaultPosition, wxDefaultSize, 0 );
	s_calldialog_sizer->Add( t_para_list, 0, wxALL, 5 );
	
	t_para_list_input = new wxTextCtrl( m_calldialog_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	s_calldialog_sizer->Add( t_para_list_input, 0, wxALL|wxEXPAND, 5 );
	
	m_call_func = new wxButton( m_calldialog_panel, wxID_call_func, wxT("Add Function Call"), wxDefaultPosition, wxDefaultSize, 0 );
	m_call_func->SetDefault();
	s_calldialog_sizer->Add( m_call_func, 0, wxALL|wxEXPAND, 5 );
	
	
	m_calldialog_panel->SetSizer( s_calldialog_sizer );
	m_calldialog_panel->Layout();
	s_calldialog_sizer->Fit( m_calldialog_panel );
	s_main->Add( m_calldialog_panel, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( s_main );
	this->Layout();
	
	this->Centre( wxBOTH );
}

void FnCallDialog :: c_ret_chk( wxCommandEvent& event )
{
	if(m_ret_chk->GetSelection()==1)
	{
		t_ret_var_name_input->Enable(false);
		t_ret_var_name->Enable(false);
	}
	else
	{
		t_ret_var_name_input->Enable(true);
		t_ret_var_name->Enable(true);		
	}
}

void FnCallDialog :: c_mem_chk( wxCommandEvent& event )
{
	if(m_mem_chk->GetSelection()==1)
	{
		t_cls_name_input->Enable(false);
		t_cls_name->Enable(false);
	}
	else
	{
		t_cls_name_input->Enable(true);
		t_cls_name->Enable(true);
	}
}

void FnCallDialog :: c_call_func( wxCommandEvent& event )
{
	insert_code.Empty();
	if((m_ret_chk->GetSelection()==0)&&(m_mem_chk->GetSelection()==1))
	{	
		insert_code.Empty();	
		if((t_func_name_input->GetLastPosition()!=0)&&(t_ret_var_name_input->GetLastPosition()!=0))
		{
			insert_code.Empty();
			insert_code<<"Call "<<t_func_name_input->GetValue()<<"("<<t_para_list_input->GetValue()<<") store returned value in "<<t_ret_var_name_input->GetValue();
			EndModal(wxID_CANCEL);
		}
		else
		{
			wxString msg;
			msg.Printf( _T("Fill in atleast the functin name and the variable to store returned value!"));
  			wxMessageBox(msg, _T("ERROR!"), wxOK | wxICON_ERROR , this);
		}
	}
	else if((m_ret_chk->GetSelection()==1)&&(m_mem_chk->GetSelection()==0))
	{	
		insert_code.Empty();
		if((t_func_name_input->GetLastPosition()!=0)&&(t_cls_name_input->GetLastPosition()!=0))
		{
			insert_code.Empty();
			insert_code<<"Call "<<t_cls_name_input->GetValue()<<"."<<t_func_name_input->GetValue()<<"("<<t_para_list_input->GetValue()<<")";
			EndModal(wxID_CANCEL);
		}
		else
		{
			wxString msg;
			msg.Printf( _T("Fill in atleast the functoin name and the class/structur to which it belongs!"));
  			wxMessageBox(msg, _T("ERROR!"), wxOK | wxICON_ERROR , this);
		}		
	}
	else if((m_ret_chk->GetSelection()==0)&&(m_mem_chk->GetSelection()==0))
	{
		insert_code.Empty();		
		if((t_func_name_input->GetLastPosition()!=0)&&(t_cls_name_input->GetLastPosition()!=0)&&(t_ret_var_name_input->GetLastPosition()!=0))
		{
			insert_code.Empty();
			insert_code<<"Call "<<t_cls_name_input->GetValue()<<"."<<t_func_name_input->GetValue()<<"("<<t_para_list_input->GetValue()<<") store returned value in "<<t_ret_var_name_input->GetValue();
			EndModal(wxID_CANCEL);
		}
		else
		{
			wxString msg;
			msg.Printf( _T("Fill in all the fields!"));
  			wxMessageBox(msg, _T("ERROR!"), wxOK | wxICON_ERROR , this);
		}		
	}
	else if((m_ret_chk->GetSelection()==1)&&(m_mem_chk->GetSelection()==1))
	{
		insert_code.Empty();		
		if(t_func_name_input->GetLastPosition()!=0)
		{
			insert_code.Empty();
			insert_code<<"Call "<<t_func_name_input->GetValue()<<"( "<<t_para_list_input->GetValue()<<" )";
			EndModal(wxID_CANCEL);
		}
		else
		{
			wxString msg;
			msg.Printf( _T("Fill in atleast the function name!"));
  			wxMessageBox(msg, _T("ERROR!"), wxOK | wxICON_ERROR , this);
		}		
	}
}
