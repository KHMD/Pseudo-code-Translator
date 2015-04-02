#include "frame_var.h"

BEGIN_EVENT_TABLE( VariableDialog, wxDialog )
	EVT_COMBOBOX( wxID_data_type, VariableDialog::_wxFB_c_data_type_select )
	EVT_CHECKBOX( wxID_array_check, VariableDialog::_wxFB_c_arraysize )
	EVT_BUTTON( wxID_create_var, VariableDialog::_wxFB_c_create_var )
END_EVENT_TABLE()

VariableDialog::VariableDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	insert_code.Empty();
	wxBoxSizer* s_var_main;
	s_var_main = new wxBoxSizer( wxVERTICAL );
	
	m_var_main = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* s_sub_main;
	s_sub_main = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* s_data_type;
	s_data_type = new wxBoxSizer( wxHORIZONTAL );
	
	t_data_type = new wxStaticText( m_var_main, wxID_ANY, wxT("Data Type"), wxDefaultPosition, wxDefaultSize, 0 );
	s_data_type->Add( t_data_type, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString dd_data_typrChoices[] = { wxT("--select data type--"), wxT("int"), wxT("float"), wxT("double"), wxT("long"), wxT("object"), wxT("structure variable"), wxT("char") };
	int dd_data_typrNChoices = sizeof( dd_data_typrChoices ) / sizeof( wxString );
	dd_data_typr = new wxComboBox( m_var_main, wxID_data_type, wxT("--select data type--"), wxDefaultPosition, wxDefaultSize, dd_data_typrNChoices, dd_data_typrChoices, 0 );
	dd_data_typr->SetSelection( 0 );
	s_data_type->Add( dd_data_typr, 0, wxALL, 5 );
	
	m_ptr_check = new wxCheckBox( m_var_main, wxID_ANY, wxT("Pointer"), wxDefaultPosition, wxDefaultSize, 0 );
	s_data_type->Add( m_ptr_check, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_array_check = new wxCheckBox( m_var_main, wxID_array_check, wxT("Array"), wxDefaultPosition, wxDefaultSize, 0 );
	s_data_type->Add( m_array_check, 0, wxALL|wxEXPAND, 5 );
	
	
	s_sub_main->Add( s_data_type, 0, 0, 5 );
	
	wxBoxSizer* s_cls_struct;
	s_cls_struct = new wxBoxSizer( wxHORIZONTAL );
	
	t_cls_struct = new wxStaticText( m_var_main, wxID_ANY, wxT("Class / Structure Name"), wxDefaultPosition, wxDefaultSize, 0 );
	t_cls_struct->Hide();
	
	s_cls_struct->Add( t_cls_struct, 0, wxALL, 5 );
	
	t_name_cls_struct = new wxTextCtrl( m_var_main, wxID_name_cls_struct, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	t_name_cls_struct->Hide();
	
	s_cls_struct->Add( t_name_cls_struct, 1, wxALL, 5 );
	
	
	s_sub_main->Add( s_cls_struct, 0, wxEXPAND, 5 );
	
	wxBoxSizer* s_arraybox;
	s_arraybox = new wxBoxSizer( wxHORIZONTAL );
	
	t_array_label = new wxStaticText( m_var_main, wxID_ANY, wxT("Array Size"), wxDefaultPosition, wxDefaultSize, 0 );
	t_array_label->Hide();
	s_arraybox->Add( t_array_label, 0, wxALL, 5 );
	
	t_arraysize = new wxTextCtrl( m_var_main, wxID_arraysize, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	t_arraysize->Hide();
	
	s_arraybox->Add( t_arraysize, 1, wxALL, 5 );
	
	
	s_sub_main->Add( s_arraybox, 0, wxEXPAND, 5 );
	
	wxBoxSizer* s_name_var;
	s_name_var = new wxBoxSizer( wxHORIZONTAL );
	
	t_name_var1 = new wxStaticText( m_var_main, wxID_ANY, wxT("Name of Variable"), wxDefaultPosition, wxDefaultSize, 0 );
	s_name_var->Add( t_name_var1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	t_name_var = new wxTextCtrl( m_var_main, wxID_name_var, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	s_name_var->Add( t_name_var, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	s_sub_main->Add( s_name_var, 1, wxEXPAND, 5 );
	
	wxBoxSizer* s_but_create;
	s_but_create = new wxBoxSizer( wxVERTICAL );
	
	m_create_var = new wxButton( m_var_main, wxID_create_var, wxT("Create Variable"), wxDefaultPosition, wxDefaultSize, 0 );
	m_create_var->SetDefault();
	m_create_var->SetToolTip( wxT("Fill in all the fields before clicking!\n") );
	
	s_but_create->Add( m_create_var, 0, wxALL|wxEXPAND, 5 );
	
	
	s_sub_main->Add( s_but_create, 0, wxEXPAND, 5 );
	
	
	m_var_main->SetSizer( s_sub_main );
	m_var_main->Layout();
	s_sub_main->Fit( m_var_main );
	s_var_main->Add( m_var_main, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( s_var_main );
	this->Layout();
	
	this->Centre( wxBOTH );
}


void VariableDialog :: c_data_type_select( wxCommandEvent& event )
{
	int ch = dd_data_typr->GetSelection();
	dd_data_typr->SetSelection(ch);
	if((ch==5) || (ch==6))
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

void VariableDialog::c_arraysize(wxCommandEvent& event)
{
	if(m_array_check->GetValue())
	{
	  t_array_label->Show();
	  t_arraysize->Show();
	}
	else
	{
	  t_array_label->Hide();
	  t_arraysize->Hide();
	}
}

void VariableDialog :: c_create_var( wxCommandEvent& event )
{
	insert_code.Empty();
	bool is_ptr=m_ptr_check->GetValue();
	int typech = dd_data_typr->GetSelection();
//	wxString dd_data_typrChoices[] = { wxT("--select data type--"), wxT("int"), wxT("float"), wxT("double"), wxT("long"), wxT("object"), wxT("structure variable"),wxT("char") };
	if((!typech)||(!t_name_var->GetLastPosition()))
	{
		wxString msg;
		msg.Printf( _T("Enter all fields!"));
  		wxMessageBox(msg, _T("ERROR!"), wxOK | wxICON_ERROR , this);
	}
	else if (((typech==5) || (typech==6)) && !(t_name_cls_struct->GetLastPosition()))
	{
		wxString msg;
		msg.Printf( _T("Enter all fields!"));
  		wxMessageBox(msg, _T("ERROR!"), wxOK | wxICON_ERROR , this);
	}
	else
	{
		insert_code<< "Variable ";
		insert_code<< t_name_var->GetValue();
		if(m_array_check->GetValue())
		{
	 	 	if(t_arraysize->GetLastPosition()!=0)
	 	 	{
				insert_code<<"["<<t_arraysize->GetValue()<<"]";
			}
	 		
		}
		
		insert_code<< " as ";	
		if((typech==5) || (typech==6))
		{
		 insert_code<< t_name_cls_struct->GetValue();
		}
		else
		{
		  insert_code<< dd_data_typr->GetStringSelection();
		}
		if(is_ptr) insert_code<<"* ";
		EndModal(wxID_CANCEL);
	}
	
}
