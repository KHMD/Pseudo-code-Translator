#include "start_dialog.h"

BEGIN_EVENT_TABLE( StartDialog, wxDialog )
	EVT_COMBOBOX( wxID_rtype_choice, StartDialog::_wxFB_c_data_type_select )
	EVT_CHECKBOX( wxID_main_chk, StartDialog::_wxFB_c_main_chk )
	EVT_CHECKBOX( wxID_memfunc_chk, StartDialog::_wxFB_c_memfunc_chk )
	EVT_BUTTON( wxID_start_func, StartDialog::_wxFB_c_start )
END_EVENT_TABLE()

StartDialog::StartDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{	
	insert_code.Empty();
	wxBoxSizer* s_start_main;
	s_start_main = new wxBoxSizer( wxVERTICAL );
	
	m_start_main = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* s_sub_main;
	s_sub_main = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* s_data_type;
	s_data_type = new wxBoxSizer( wxHORIZONTAL );
	
	t_data_type = new wxStaticText( m_start_main, wxID_ANY, wxT("Return Type"), wxDefaultPosition, wxDefaultSize, 0 );
	s_data_type->Add( t_data_type, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_rtype_choiceChoices[] = { wxT("--select data type--"), wxT("int"), wxT("float"), wxT("double"), wxT("long"), wxT("object"), wxT("structure"), wxT("void"),wxT("char") };
	int m_rtype_choiceNChoices = sizeof( m_rtype_choiceChoices ) / sizeof( wxString );
	m_rtype_choice = new wxComboBox( m_start_main, wxID_rtype_choice, wxT("--select data type--"),wxDefaultPosition, wxDefaultSize, m_rtype_choiceNChoices, m_rtype_choiceChoices, 0 );
	m_rtype_choice->SetSelection( 0 );
	s_data_type->Add( m_rtype_choice, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_ptr_check = new wxCheckBox( m_start_main, wxID_ptr_check, wxT("Return as Pointer"), wxDefaultPosition, wxDefaultSize, 0 );
	s_data_type->Add( m_ptr_check, 1, wxALL|wxEXPAND, 5 );
	
	
	s_sub_main->Add( s_data_type, 1, wxEXPAND, 5 );
	
	wxBoxSizer* s_func_name;
	s_func_name = new wxBoxSizer( wxHORIZONTAL );
	
	t_funcname = new wxStaticText( m_start_main, wxID_ANY, wxT("Function Name"), wxDefaultPosition, wxDefaultSize, 0 );
	s_func_name->Add( t_funcname, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	t_func_name = new wxTextCtrl( m_start_main, wxID_func_name, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	s_func_name->Add( t_func_name, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_check_main = new wxCheckBox( m_start_main, wxID_main_chk, wxT("Main"), wxDefaultPosition, wxDefaultSize, 0 );
	m_check_main->SetToolTip( wxT("check it if you want to write pseudo code for the main function.") );
	
	s_func_name->Add( m_check_main, 0, wxALL|wxEXPAND, 5 );
	
	
	s_sub_main->Add( s_func_name, 0, wxEXPAND, 5 );
	
	wxBoxSizer* s_memberfunction;
	s_memberfunction = new wxBoxSizer( wxHORIZONTAL );
	
	t_class_label = new wxStaticText( m_start_main, wxID_ANY, wxT("Class Name"), wxDefaultPosition, wxDefaultSize, 0 );
	s_memberfunction->Add( t_class_label, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	t_class_name = new wxTextCtrl( m_start_main, wxID_func_name, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	t_class_name->Enable(false);
	s_memberfunction->Add( t_class_name, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_memfunc_chk = new wxCheckBox( m_start_main, wxID_memfunc_chk, wxT("Member Function"), wxDefaultPosition, wxDefaultSize, 0 );
	m_memfunc_chk->SetToolTip( wxT("check it if you want to write pseudo code for a member function of a class.") );
	m_memfunc_chk->SetValue(false);
	s_memberfunction->Add( m_memfunc_chk, 0, wxALL|wxEXPAND, 5 );
	
	
	s_sub_main->Add( s_memberfunction, 0, wxEXPAND, 5 );
	
	wxBoxSizer* s_params;
	s_params = new wxBoxSizer( wxHORIZONTAL );
	
	t_funcparams = new wxStaticText( m_start_main, wxID_ANY, wxT("Parameters"), wxDefaultPosition, wxDefaultSize, 0 );
	s_params->Add( t_funcparams, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	t_func_params = new wxTextCtrl( m_start_main, wxID_func_params, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	t_func_params->SetToolTip( wxT("Enter the parameters, separated by commas.\nEg: int x,float y,double z,char *str,\nor \"none\" for no parameters") );
	
	s_params->Add( t_func_params, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	s_sub_main->Add( s_params, 1, wxEXPAND, 5 );
	
	wxBoxSizer* s_but_create;
	s_but_create = new wxBoxSizer( wxVERTICAL );
	
	m_start_func = new wxButton( m_start_main, wxID_start_func, wxT("Start Function"), wxDefaultPosition, wxDefaultSize, 0 );
	m_start_func->SetToolTip( wxT("Fill in all the fields before clicking!\n") );
	m_start_func->SetDefault();
	s_but_create->Add( m_start_func, 0, wxALL|wxEXPAND, 5 );
	
	
	s_sub_main->Add( s_but_create, 1, wxEXPAND, 5 );
	
	
	m_start_main->SetSizer( s_sub_main );
	m_start_main->Layout();
	s_sub_main->Fit( m_start_main );
	s_start_main->Add( m_start_main, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( s_start_main );
	this->Layout();
	
	this->Centre( wxBOTH );
}



void StartDialog :: c_data_type_select( wxCommandEvent& event )
{
	if((m_rtype_choice->GetSelection() == 5) || (m_rtype_choice->GetSelection() == 6))
	{
		returntype = "";
		while(returntype == "")
			returntype= wxGetTextFromUser("Enter the name of the class/structure","Return Type Selection","", this,-1,-1,false);
	}
	else
		returntype= m_rtype_choice->GetStringSelection();
}
void StartDialog :: c_start( wxCommandEvent& event )
{
	wxString p_block;
	
	insert_code.Empty();
	bool is_main,is_ptr;
	is_main=m_check_main->GetValue();
	is_ptr=m_ptr_check->GetValue();
	n_ind=0;
	if(is_main)
	{
		insert_code<<"Function ";
		insert_code<<"main";
		is_main_def=true;
		p_block<<"End main";
		stk_p_block.push(p_block);
		endlabel_text.Empty();
		endlabel_text<<p_block;
		insert_code<<"\n";
		EndModal(wxID_CANCEL);
	}
	else if(!is_main )
	{
		if((t_func_name->GetLastPosition()!=0) && (m_rtype_choice->GetSelection()!=0) && (t_func_params->GetLastPosition()!=0) )
		{
			if(!m_memfunc_chk->GetValue())
			{
				insert_code<<"Function ";	
				p_block<<"End "<<t_func_name->GetValue();
				insert_code<<t_func_name->GetValue();
				
				if(t_func_params->GetValue() != "none")
					insert_code<<" parameters: "<<t_func_params->GetValue();
				else
					insert_code<<" parameters: none";
				insert_code<<" returns "<<returntype;
				if(is_ptr)
				insert_code<<"*";
				stk_p_block.push(p_block);
				endlabel_text.Empty();
				endlabel_text<<p_block;
				insert_code<<"\n";
				EndModal(wxID_CANCEL);
			}
			else if ((m_memfunc_chk->GetValue()) && (t_class_name->GetLastPosition()!=0))
			{
				insert_code<<"Function ";	
				p_block<<"End "<<t_class_name->GetValue()<<"::"<<t_func_name->GetValue();
				insert_code<<t_class_name->GetValue()<<"::"<<t_func_name->GetValue();
			
				if(t_func_params->GetValue() != "none")
					insert_code<<" parameters: "<<t_func_params->GetValue();
				else
					insert_code<<" parameters: none";
				insert_code<<" returns "<<returntype;
				if(is_ptr)
				insert_code<<"*";
				stk_p_block.push(p_block);
				endlabel_text.Empty();
				p_block.Empty();
				p_block<<"End "<<t_func_name->GetValue();
				endlabel_text<<p_block;
				insert_code<<"\n";
				
				EndModal(wxID_CANCEL);
			}
		}
		else
		{
			wxString msg;
			msg.Printf( _T("Enter All fields!"));
			wxMessageBox(msg, _T("ERROR!"), wxOK | wxICON_ERROR , this);
		}
			
	}
	else
	{
		wxString msg;
		msg.Printf( _T("Enter All fields!"));
		wxMessageBox(msg, _T("ERROR!"), wxOK | wxICON_ERROR , this);
	}
	
	
}
void StartDialog :: c_main_chk( wxCommandEvent& event )
{
	bool is_main;
	is_main=m_check_main->GetValue();
	if(!is_main)
	{
		t_class_name->Enable(false);
		m_memfunc_chk->Enable(true);
		m_memfunc_chk->SetValue(false);
		t_func_name->Enable(true);
		m_rtype_choice->SetSelection( 0 );
		m_rtype_choice->Enable(true);
		m_ptr_check->Enable(true);
		t_func_params->Enable(true);
	}
	else
	{
		t_class_name->Enable(false);
		m_memfunc_chk->Enable(false);
		t_func_name->Enable(false);
		m_rtype_choice->SetSelection( 0 );
		m_rtype_choice->Enable(false);
		m_ptr_check->Enable(false);
		t_func_params->Enable(false);
		
	}
}

void StartDialog :: c_memfunc_chk( wxCommandEvent& event )
{
	bool is_memfunc;
	is_memfunc=m_memfunc_chk->GetValue();
	if(!is_memfunc)
	{
		t_class_name->Enable(false);
	}
	else
	{
		t_class_name->Enable(true);
	}
}

void StartDialog :: disable_main_chk()
{
	m_check_main->Enable(false);
	m_check_main->SetValue(false);
	t_func_name->Enable(true);
	m_memfunc_chk->Enable(true);
}
