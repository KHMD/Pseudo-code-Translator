#include "dialog_cin.h"

BEGIN_EVENT_TABLE( CinDialog, wxDialog )
	EVT_BUTTON( wxID_get_input, CinDialog::_wxFB_c_get_input )
	EVT_CLOSE( CinDialog::_wxFB_c_close )
END_EVENT_TABLE()

CinDialog::CinDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	m_panel3 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	t_var_name = new wxStaticText( m_panel3, wxID_ANY, wxT("Enter the name of the variable in which \nyou want to store the input in"), wxDefaultPosition, wxDefaultSize, 0 );
	t_var_name->SetToolTip( wxT("eg: i<10 where i is the control") );
	
	bSizer6->Add( t_var_name, 0, wxALL, 5 );
	
	t_var_name_input = new wxTextCtrl( m_panel3, wxID_condition_input, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
		
	bSizer6->Add( t_var_name_input, 0, wxALL|wxEXPAND, 5 );
	
	m_get_input = new wxButton( m_panel3, wxID_get_input, wxT("Read Input"), wxDefaultPosition, wxDefaultSize, 0 );
	m_get_input->SetDefault();
	bSizer6->Add( m_get_input, 0, wxALL|wxEXPAND, 5 );
	
	
	m_panel3->SetSizer( bSizer6 );
	m_panel3->Layout();
	bSizer6->Fit( m_panel3 );
	bSizer5->Add( m_panel3, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer5 );
	this->Layout();
	
	this->Centre( wxBOTH );
}
void CinDialog :: c_close(wxCommandEvent& event)
{
	insert_code.Empty();
	EndModal(wxID_CANCEL);
}
void CinDialog :: c_get_input( wxCommandEvent& event )
{
	insert_code.Empty();
	if(t_var_name_input->GetLastPosition()!=0)
	{
		insert_code<<"Read input for "<<t_var_name_input->GetValue();
		EndModal(wxID_CANCEL);
	}
	else
	{
		wxString msg;
		msg.Printf( _T("Fill in all fields!"));
  		wxMessageBox(msg, _T("ERROR!"), wxOK | wxICON_ERROR , this);
	}
}
CinDialog::~CinDialog()
{
	EndModal(wxID_CANCEL);
}
