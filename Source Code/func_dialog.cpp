#include "func_dialog.h"

BEGIN_EVENT_TABLE( FunctionDialog, wxDialog )
	EVT_COMBOBOX( wxID_rtype_choice, FunctionDialog::_wxFB_c_data_type_select )
	EVT_BUTTON( wxID_create_func, FunctionDialog::_wxFB_c_create_func )
END_EVENT_TABLE()

FunctionDialog::FunctionDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	insert_code.Empty();
	wxBoxSizer* s_func_main;
	s_func_main = new wxBoxSizer( wxVERTICAL );
	
	m_func_main = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* s_sub_main;
	s_sub_main = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* s_data_type;
	s_data_type = new wxBoxSizer( wxHORIZONTAL );
	
	t_data_type = new wxStaticText( m_func_main, wxID_ANY, wxT("Return Type"), wxDefaultPosition, wxDefaultSize, 0 );
	s_data_type->Add( t_data_type, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_rtype_choiceChoices[] = { wxT("--select data type--"), wxT("int"), wxT("float"), wxT("double"), wxT("long"), wxT("object"), wxT("structure"), wxT("void"), wxT("char") };
	int m_rtype_choiceNChoices = sizeof( m_rtype_choiceChoices ) / sizeof( wxString );
	m_rtype_choice = new wxComboBox( m_func_main, wxID_rtype_choice, wxT("--select data type--"),wxDefaultPosition, wxDefaultSize, m_rtype_choiceNChoices, m_rtype_choiceChoices, 0 );
	m_rtype_choice->SetSelection( 0 );
	s_data_type->Add( m_rtype_choice, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_ptr_check = new wxCheckBox( m_func_main, wxID_ptr_check, wxT("Return as Pointer"), wxDefaultPosition, wxDefaultSize, 0 );
	s_data_type->Add( m_ptr_check, 1, wxALL|wxEXPAND, 5 );
	
	
	s_sub_main->Add( s_data_type, 1, wxEXPAND, 5 );
	
	wxBoxSizer* s_cls_struct;
	s_cls_struct = new wxBoxSizer( wxHORIZONTAL );
	
	t_cls_struct = new wxStaticText( m_func_main, wxID_ANY, wxT("Class / Structure Name"), wxDefaultPosition, wxDefaultSize, 0 );
	t_cls_struct->Hide();
	
	s_cls_struct->Add( t_cls_struct, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	t_name_cls_struct = new wxTextCtrl( m_func_main, wxID_name_cls_struct, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	t_name_cls_struct->Hide();
	
	s_cls_struct->Add( t_name_cls_struct, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	s_sub_main->Add( s_cls_struct, 1, wxEXPAND, 5 );
	
	wxBoxSizer* s_name_var;
	s_name_var = new wxBoxSizer( wxHORIZONTAL );
	
	t_name_var1 = new wxStaticText( m_func_main, wxID_ANY, wxT("Function Name"), wxDefaultPosition, wxDefaultSize, 0 );
	s_name_var->Add( t_name_var1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	t_func_name = new wxTextCtrl( m_func_main, wxID_func_name, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	s_name_var->Add( t_func_name, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	s_sub_main->Add( s_name_var, 0, wxEXPAND, 5 );
	
	wxBoxSizer* s_params;
	s_params = new wxBoxSizer( wxHORIZONTAL );
	
	t_name_var11 = new wxStaticText( m_func_main, wxID_ANY, wxT("Parameters"), wxDefaultPosition, wxDefaultSize, 0 );
	s_params->Add( t_name_var11, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	t_func_params = new wxTextCtrl( m_func_main, wxID_func_params, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	t_func_params->SetToolTip( wxT("Enter the parameters, separated by commas.\nEg: int x,float y,double z,char *str,\nor \"none\" for no parameters") );
	
	s_params->Add( t_func_params, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	s_sub_main->Add( s_params, 1, wxEXPAND, 5 );
	
	wxBoxSizer* s_but_create;
	s_but_create = new wxBoxSizer( wxVERTICAL );
	
	m_create_func = new wxButton( m_func_main, wxID_create_func, wxT("Create Function"), wxDefaultPosition, wxDefaultSize, 0 );
	m_create_func->SetToolTip( wxT("Fill in all the fields before clicking!\n") );
	m_create_func->SetDefault();
	
	s_but_create->Add( m_create_func, 0, wxALL|wxEXPAND, 5 );
	
	
	s_sub_main->Add( s_but_create, 1, wxEXPAND, 5 );
	
	
	m_func_main->SetSizer( s_sub_main );
	m_func_main->Layout();
	s_sub_main->Fit( m_func_main );
	s_func_main->Add( m_func_main, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( s_func_main );
	this->Layout();
	
	this->Centre( wxBOTH );
}
void FunctionDialog :: c_data_type_select( wxCommandEvent& event )
{
	returntype.Empty();
	returntype = m_rtype_choice->GetStringSelection();
	if((returntype=="object") || (returntype=="structure"))
	{
	  t_cls_struct->Show();
	  t_name_cls_struct->Show();
	}
	else
	{
	  t_cls_struct->Hide();
	  t_name_cls_struct->Hide();
	}
}
void FunctionDialog :: c_create_func( wxCommandEvent& event )
{
	insert_code.Empty();
	bool is_ptr=m_ptr_check->GetValue();
	if((returntype.IsEmpty())||!(t_func_name->IsModified())||!(t_func_params->IsModified()))
	{
		wxString msg;
		msg.Printf( _T("Enter all fields!"));
  		wxMessageBox(msg, _T("ERROR!"), wxOK | wxICON_ERROR , this);
	}
	else if (((returntype=="object") || (returntype=="structure")) && !(t_name_cls_struct->IsModified()))
	{
		wxString msg;
		msg.Printf( _T("Enter all fields!"));
  		wxMessageBox(msg, _T("ERROR!"), wxOK | wxICON_ERROR , this);
	}
	else 
	{
		
		insert_code<< "Function ";
		insert_code<< t_func_name->GetValue();
		insert_code<< " parameters: ";
		insert_code<< t_func_params->GetValue();
		insert_code<< " returns ";
		if((returntype=="object") || (returntype=="structure"))
		{
		 insert_code<<t_name_cls_struct->GetValue();
		}
		else
		{
		  insert_code<< returntype;
		}
		if(is_ptr) insert_code<<"*";
		EndModal(wxID_CANCEL);
	}
}
