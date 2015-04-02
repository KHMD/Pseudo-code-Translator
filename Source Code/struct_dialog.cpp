#include "struct_dialog.h"

BEGIN_EVENT_TABLE( StructDialog, wxDialog )
	EVT_BUTTON( wxID_addmember_struct, StructDialog::_wxFB_c_addmember_struct )
	EVT_BUTTON( wxID_createstruct, StructDialog::_wxFB_c_createstruct )
END_EVENT_TABLE()

StructDialog::StructDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{	
	insert_code.Empty();
	wxBoxSizer* s_struct_main;
	s_struct_main = new wxBoxSizer( wxVERTICAL );
	
	m_struct_main = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* s_sub_main;
	s_sub_main = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* s_cls_struct;
	s_cls_struct = new wxBoxSizer( wxHORIZONTAL );
	
	t_struct_namelabel = new wxStaticText( m_struct_main, wxID_ANY, wxT("Structure  Name"), wxDefaultPosition, wxDefaultSize, 0 );
	s_cls_struct->Add( t_struct_namelabel, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	t_name_struct = new wxTextCtrl( m_struct_main, wxID_name_class, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	s_cls_struct->Add( t_name_struct, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	s_sub_main->Add( s_cls_struct, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* s_AddMem;
	s_AddMem = new wxBoxSizer( wxVERTICAL );
	
	t_struct_addmem = new wxStaticText( m_struct_main, wxID_ANY, wxT("Add A Member:"), wxDefaultPosition, wxDefaultSize, 0 );
	s_AddMem->Add( t_struct_addmem, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* s_membercontrols;
	s_membercontrols = new wxBoxSizer( wxHORIZONTAL );
	
	wxString m_struct_mtypeChoices[] = { wxT("Variable"), wxT("Function") };
	int m_struct_mtypeNChoices = sizeof( m_struct_mtypeChoices ) / sizeof( wxString );
	m_struct_mtype = new wxRadioBox( m_struct_main, wxID_ANY, wxT("Member Type"), wxDefaultPosition, wxDefaultSize, m_struct_mtypeNChoices, m_struct_mtypeChoices, 1, wxRA_SPECIFY_ROWS );
	m_struct_mtype->SetSelection( 0 );
	s_membercontrols->Add( m_struct_mtype, 1, wxALL, 5 );
	
	m_addmember_struct = new wxButton( m_struct_main, wxID_addmember_struct, wxT("Add Member"), wxDefaultPosition, wxDefaultSize, 0 );
	s_membercontrols->Add( m_addmember_struct, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	s_AddMem->Add( s_membercontrols, 0, wxEXPAND, 5 );
	
	
	s_sub_main->Add( s_AddMem, 0, wxEXPAND, 5 );
	
	wxBoxSizer* s_cls_class1;
	s_cls_class1 = new wxBoxSizer( wxVERTICAL );
	
	t_cls_memlist = new wxStaticText( m_struct_main, wxID_ANY, wxT("Members:"), wxDefaultPosition, wxDefaultSize, 0 );
	s_cls_class1->Add( t_cls_memlist, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	t_memberlist_struct = new wxTextCtrl( m_struct_main, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	s_cls_class1->Add( t_memberlist_struct, 1, wxALL|wxEXPAND, 5 );
	
	
	s_sub_main->Add( s_cls_class1, 1, wxEXPAND, 5 );
	
	wxBoxSizer* s_but_create;
	s_but_create = new wxBoxSizer( wxVERTICAL );
	
	m_createstruct = new wxButton( m_struct_main, wxID_createstruct, wxT("Create Structure"), wxDefaultPosition, wxDefaultSize, 0 );
	m_createstruct->SetToolTip( wxT("Fill in all the fields before clicking!\n") );
	m_createstruct->SetDefault();
	
	s_but_create->Add( m_createstruct, 0, wxALL|wxEXPAND, 5 );
	
	
	s_sub_main->Add( s_but_create, 0, wxEXPAND, 5 );
	
	
	m_struct_main->SetSizer( s_sub_main );
	m_struct_main->Layout();
	s_sub_main->Fit( m_struct_main );
	s_struct_main->Add( m_struct_main, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( s_struct_main );
	this->Layout();
	
	this->Centre( wxBOTH );
}
void StructDialog :: c_addmember_struct( wxCommandEvent& event )
{
	int datatype = m_struct_mtype->GetSelection();
	VariableDialog *vardialog = new VariableDialog(this);
	FunctionDialog *funcdialog = new FunctionDialog(this);
	switch(datatype)
	{
		case 0://variable
			*t_memberlist_struct<<"\n";
			vardialog->ShowModal();
			delete vardialog;
			if (insert_code != ""){
				*t_memberlist_struct << insert_code;
				insert_code.Empty();
			}
			break;
		case 1://function
			*t_memberlist_struct<<"\n";
			funcdialog->ShowModal();
			delete funcdialog;
			if (insert_code != ""){
				*t_memberlist_struct << insert_code;
				insert_code.Empty();
			}
			break;
	}
}
void StructDialog :: c_createstruct( wxCommandEvent& event )
{
	insert_code.Empty();
	if(!t_name_struct->IsModified())
	{
		wxString msg;
		msg.Printf( _T("Enter all fields!"));
  		wxMessageBox(msg, _T("ERROR!"), wxOK | wxICON_ERROR , this);
	}
	else
	{
		wxString temp;
		temp= t_memberlist_struct->GetValue();
		temp.Replace("\n","\n\t");
		t_memberlist_struct->Clear();
		*t_memberlist_struct<<temp;
		insert_code<<"Structure " <<t_name_struct->GetValue() << ":";
		insert_code<<t_memberlist_struct->GetValue();
		insert_code<<"\nEnd Structure";
		EndModal(wxID_CANCEL);
	}
}
