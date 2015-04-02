#include "dialog_operation.h"

BEGIN_EVENT_TABLE( OperationDialog, wxDialog )
	EVT_BUTTON( wxID_add_operation, OperationDialog::_wxFB_c_add_operation )
END_EVENT_TABLE()

OperationDialog::OperationDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	insert_code.Empty();
	wxBoxSizer* s_dialog_operation_main;
	s_dialog_operation_main = new wxBoxSizer( wxVERTICAL );
	
	m_panel2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	t_operation = new wxStaticText( m_panel2, wxID_ANY, wxT("Enter Your Operation:"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( t_operation, 0, wxALL, 5 );
	
	t_operation_input = new wxTextCtrl( m_panel2, wxID_operation_input, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	t_operation_input->SetToolTip( wxT("eg: a=b+(c*d)-w, where a, b, c,d, w are all variables declared by you earlier") );
	
	bSizer8->Add( t_operation_input, 1, wxALL|wxEXPAND, 5 );
	
	m_add_operation = new wxButton( m_panel2, wxID_add_operation, wxT("Add Operation"), wxDefaultPosition, wxDefaultSize, 0 );
	m_add_operation->SetDefault();
	bSizer8->Add( m_add_operation, 0, wxALL|wxEXPAND, 5 );
	
	
	m_panel2->SetSizer( bSizer8 );
	m_panel2->Layout();
	bSizer8->Fit( m_panel2 );
	s_dialog_operation_main->Add( m_panel2, 0, wxEXPAND | wxALL, 5 );
	
	
	this->SetSizer( s_dialog_operation_main );
	this->Layout();
	
	this->Centre( wxBOTH );
}
void OperationDialog :: c_add_operation( wxCommandEvent& event )
{
	insert_code.Empty();
	if(t_operation_input->GetLastPosition()!=0)
	{
		insert_code<<t_operation_input->GetValue();
		EndModal(wxID_CANCEL);
	}
	else
	{
		wxString msg;
		msg.Printf( _T("Fill in all fields!"));
  		wxMessageBox(msg, _T("ERROR!"), wxOK | wxICON_ERROR , this);
	}
}
