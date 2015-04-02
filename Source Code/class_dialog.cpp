#include "class_dialog.h"

BEGIN_EVENT_TABLE( ClassDialog, wxDialog )
	EVT_BUTTON( wxID_addmember, ClassDialog::_wxFB_c_addmember )
	EVT_BUTTON( wxID_create_class, ClassDialog::_wxFB_c_createclass )
END_EVENT_TABLE()

ClassDialog::ClassDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{	
	insert_code.Empty();
	wxBoxSizer* s_class_main;
	s_class_main = new wxBoxSizer( wxVERTICAL );
	
	m_class_main = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* s_sub_main;
	s_sub_main = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* s_cls_struct;
	s_cls_struct = new wxBoxSizer( wxHORIZONTAL );
	
	t_cls_namelabel = new wxStaticText( m_class_main, wxID_ANY, wxT("Class  Name"), wxDefaultPosition, wxDefaultSize, 0 );
	s_cls_struct->Add( t_cls_namelabel, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	t_name_class = new wxTextCtrl( m_class_main, wxID_name_class, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	s_cls_struct->Add( t_name_class, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	s_sub_main->Add( s_cls_struct, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* s_AddMem;
	s_AddMem = new wxBoxSizer( wxVERTICAL );
	
	t_cls_addmem = new wxStaticText( m_class_main, wxID_ANY, wxT("Add A Member:"), wxDefaultPosition, wxDefaultSize, 0 );
	s_AddMem->Add( t_cls_addmem, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* PsudoControls;
	PsudoControls = new wxBoxSizer( wxHORIZONTAL );
	
	wxString m_mem_typeChoices[] = { wxT("Variable"), wxT("Function") };
	int m_mem_typeNChoices = sizeof( m_mem_typeChoices ) / sizeof( wxString );
	m_mem_type = new wxRadioBox( m_class_main, wxID_ANY, wxT("Member Type"), wxDefaultPosition, wxDefaultSize, m_mem_typeNChoices, m_mem_typeChoices, 1, wxRA_SPECIFY_ROWS );
	m_mem_type->SetSelection( 0 );
	PsudoControls->Add( m_mem_type, 1, wxALL, 5 );
	
	
	s_AddMem->Add( PsudoControls, 0, wxEXPAND, 5 );
	
	wxBoxSizer* s_visiblemode;
	s_visiblemode = new wxBoxSizer( wxHORIZONTAL );
	
	wxString m_visibilityboxChoices[] = { wxT("Public"), wxT("Private") };
	int m_visibilityboxNChoices = sizeof( m_visibilityboxChoices ) / sizeof( wxString );
	m_visibilitybox = new wxRadioBox( m_class_main, wxID_ANY, wxT("Access Specifier"), wxDefaultPosition, wxDefaultSize, m_visibilityboxNChoices, m_visibilityboxChoices, 1, wxRA_SPECIFY_ROWS );
	m_visibilitybox->SetSelection( 1 );
	s_visiblemode->Add( m_visibilitybox, 1, wxALL, 5 );
	
	m_addmember = new wxButton( m_class_main, wxID_addmember, wxT("Add Member"), wxDefaultPosition, wxDefaultSize, 0 );
	s_visiblemode->Add( m_addmember, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	s_AddMem->Add( s_visiblemode, 1, wxEXPAND, 5 );
	
	
	s_sub_main->Add( s_AddMem, 0, wxEXPAND, 5 );
	
	wxBoxSizer* s_cls_struct1;
	s_cls_struct1 = new wxBoxSizer( wxVERTICAL );
	
	t_cls_memlist = new wxStaticText( m_class_main, wxID_ANY, wxT("Members:"), wxDefaultPosition, wxDefaultSize, 0 );
	s_cls_struct1->Add( t_cls_memlist, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	t_memberlist = new wxTextCtrl( m_class_main, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	s_cls_struct1->Add( t_memberlist, 1, wxALL|wxEXPAND, 5 );
	
	
	s_sub_main->Add( s_cls_struct1, 1, wxEXPAND, 5 );
	
	wxBoxSizer* s_but_create;
	s_but_create = new wxBoxSizer( wxVERTICAL );
	
	m_createclass = new wxButton( m_class_main, wxID_create_class, wxT("Create Class"), wxDefaultPosition, wxDefaultSize, 0 );
	m_createclass->SetDefault();
	m_createclass->SetToolTip( wxT("Fill in all the fields before clicking!\n") );
	
	s_but_create->Add( m_createclass, 0, wxALL|wxEXPAND, 5 );
	
	
	s_sub_main->Add( s_but_create, 0, wxEXPAND, 5 );
	
	
	m_class_main->SetSizer( s_sub_main );
	m_class_main->Layout();
	s_sub_main->Fit( m_class_main );
	s_class_main->Add( m_class_main, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( s_class_main );
	this->Layout();
	
	this->Centre( wxBOTH );
}
void ClassDialog :: c_addmember( wxCommandEvent& event )
{
	int datatype = m_mem_type->GetSelection();
	int accesstype = m_visibilitybox->GetSelection();
	wxString visibility[] = { wxT("public"), wxT("private") };
	VariableDialog *vardialog = new VariableDialog(this);
	FunctionDialog *funcdialog = new FunctionDialog(this);
	switch(datatype)
	{
		case 0://variable
			*t_memberlist<<"\n";
			vardialog->ShowModal();
			delete vardialog;
			if (insert_code != ""){
				*t_memberlist<< visibility[accesstype] << " ";
				*t_memberlist << insert_code;
				insert_code.Empty();
			}
			break;
		case 1://function
			*t_memberlist<<"\n";
			funcdialog->ShowModal();
			delete funcdialog;
			if (insert_code != ""){
				*t_memberlist<< visibility[accesstype] << " ";
				*t_memberlist << insert_code;
				insert_code.Empty();
			}
			break;
	}
}		
void ClassDialog :: c_createclass( wxCommandEvent& event )
{
	insert_code.Empty();
	if(!t_name_class->IsModified())
	{
		wxString msg;
		msg.Printf( _T("Enter all fields!"));
  		wxMessageBox(msg, _T("ERROR!"), wxOK | wxICON_ERROR , this);
	}
	else
	{
		
		wxString temp;
		temp= t_memberlist->GetValue();
		temp= sortaccess(temp);
		temp.Replace("\n","\n\t");
		t_memberlist->Clear();
		*t_memberlist<<temp;
		insert_code<<"Class " <<t_name_class->GetValue() << ":";
		insert_code<<t_memberlist->GetValue();
		insert_code<<"\nEnd Class";
		EndModal(wxID_CANCEL);
	}
}

wxString ClassDialog :: sortaccess (wxString input)
{
	int i=0,j=0,k=0;
	input<<"\n";
	wxString publicmem,privatemem,tempstring;
	publicmem.Empty();
	privatemem.Empty();
	while(i!= (int)input.Length())
	{
		tempstring.Empty();
		if(input.GetChar(i)!='\n'){
			j++;
		}
		else 
		{	j++;
			tempstring = input.Mid(k,j);
			if(tempstring.Replace ("public","")!=0)
			{
				publicmem<<tempstring;
			}
			else if(tempstring.Replace ("private","")!=0)
			{
				privatemem<<tempstring;
			}
			k=i;
			j=0;
		}
		i++;	
	}
	tempstring.Empty();
	tempstring<<"\nprivate:";
	tempstring<<privatemem;
	tempstring<<"\npublic:";
	tempstring<<publicmem;
	return tempstring;
}
