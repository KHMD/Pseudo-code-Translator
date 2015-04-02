#include "dialog_cout.h"

BEGIN_EVENT_TABLE( CoutDialog, wxDialog )
	EVT_BUTTON( wxID_disp, CoutDialog::_wxFB_c_disp )
	EVT_CLOSE( CoutDialog::_wxFB_c_close )
END_EVENT_TABLE()

CoutDialog::CoutDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{	
	wxBoxSizer* s_main;
	s_main = new wxBoxSizer( wxVERTICAL );
	
	m_outdialog = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* s_outdialog;
	s_outdialog = new wxBoxSizer( wxVERTICAL );
	
	wxString m_outTypeChoices[] = { wxT("Variable"), wxT("Text") };
	int m_outTypeNChoices = sizeof( m_outTypeChoices ) / sizeof( wxString );
	m_outType = new wxRadioBox( m_outdialog, wxID_outType, wxT("Output Type"), wxDefaultPosition, wxDefaultSize, m_outTypeNChoices, m_outTypeChoices, 1, wxRA_SPECIFY_ROWS );
	m_outType->SetSelection( 0 );
	m_outType->SetToolTip( wxT("Select the type of the output") );
	
	s_outdialog->Add( m_outType, 1, wxEXPAND|wxALL, 5 );
	
	t_display = new wxTextCtrl( m_outdialog, wxID_display, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	t_display->SetToolTip( wxT("Enter the name of the variable or the text to display! Note: Type \\n when entering text to display on the next line.") );
	
	s_outdialog->Add( t_display, 0, wxALL|wxEXPAND, 5 );
	
	m_disp = new wxButton( m_outdialog, wxID_disp, wxT("Display"), wxDefaultPosition, wxDefaultSize, 0 );
	m_disp->SetDefault();
	m_disp->SetToolTip( wxT("Inserts code to display the either the entered text or the value of the variable") );
	
	s_outdialog->Add( m_disp, 0, wxALL|wxEXPAND, 5 );
	
	
	m_outdialog->SetSizer( s_outdialog );
	m_outdialog->Layout();
	s_outdialog->Fit( m_outdialog );
	s_main->Add( m_outdialog, 0, wxEXPAND|wxALL, 5 );
	
	
	this->SetSizer( s_main );
	this->Layout();
	
	this->Centre( wxBOTH );
}
void CoutDialog :: c_disp( wxCommandEvent& event )
{
	insert_code.Empty();
	if(t_display->GetLastPosition()!=0)
	{
		if(m_outType->GetSelection() == 0)
		insert_code<<"Display "<<t_display->GetValue();
		else
		insert_code<<"Display \""<<t_display->GetValue()<<"\"";
		EndModal(wxID_CANCEL);
	}
	else
	{
		wxString msg;
		msg.Printf( _T("Fill in all fields!"));
  		wxMessageBox(msg, _T("ERROR!"), wxOK | wxICON_ERROR , this);
	}	
}
void CoutDialog :: c_close(wxCommandEvent& event)
{
	insert_code.Empty();
	EndModal(wxID_CANCEL);
}
CoutDialog::~CoutDialog()
{
	EndModal(wxID_CANCEL);
}
