#include "dialog_if.h"

BEGIN_EVENT_TABLE( IfDialog, wxDialog )
	EVT_BUTTON( wxID_add_condition, IfDialog::_wxFB_c_add_condition )
	EVT_RADIOBOX( wxID_if_choice, IfDialog::_wxFB_c_if_choice )
END_EVENT_TABLE()

IfDialog::IfDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{	
	insert_code.Empty();
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_panel2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	wxString m_if_choiceChoices[] = { wxT("if"), wxT("else if"), wxT("else") };
	int m_if_choiceNChoices = sizeof( m_if_choiceChoices ) / sizeof( wxString );
	m_if_choice = new wxRadioBox( m_panel2, wxID_if_choice, wxT("Choose"), wxDefaultPosition, wxDefaultSize, m_if_choiceNChoices, m_if_choiceChoices, 1, wxRA_SPECIFY_ROWS );
	m_if_choice->SetSelection( 0 );
	m_if_choice->SetToolTip( wxT("Select else if or else only if previous statment is an if") );
	
	bSizer4->Add( m_if_choice, 0, wxALL, 5 );
	
	t_condition = new wxStaticText( m_panel2, wxID_ANY, wxT("Enter the condition"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( t_condition, 0, wxALL, 5 );
	
	t_condition_input = new wxTextCtrl( m_panel2, wxID_condition_input, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( t_condition_input, 0, wxALL|wxEXPAND, 5 );
	
	m_add_condition = new wxButton( m_panel2, wxID_add_condition, wxT("Add Condition"), wxDefaultPosition, wxDefaultSize, 0 );
	m_add_condition->SetDefault();
	bSizer4->Add( m_add_condition, 0, wxALL|wxEXPAND, 5 );
	
	
	m_panel2->SetSizer( bSizer4 );
	m_panel2->Layout();
	bSizer4->Fit( m_panel2 );
	bSizer3->Add( m_panel2, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer3 );
	this->Layout();
	
	this->Centre( wxBOTH );
}
void IfDialog :: c_if_choice( wxCommandEvent& event )
{
	int selected = m_if_choice->GetSelection();
	if(selected==2)
	{
		t_condition_input->Enable(false);
	}
	else
	{
		t_condition_input->Enable(true);
	}
}
void IfDialog :: c_add_condition( wxCommandEvent& event )
{
	wxString p_block;
	insert_code.Empty();
	if((t_condition_input->GetLastPosition()!=0)||(m_if_choice->GetSelection()== 2))
	{
		insert_code.Empty();
		insert_code<<m_if_choice->GetStringSelection()<<" "<<t_condition_input->GetValue();
		p_block<<"End "<<m_if_choice->GetStringSelection();
		stk_p_block.push(p_block);
		endlabel_text.Empty();
		endlabel_text<<p_block;
		EndModal(wxID_CANCEL);
	}
	else
	{
		wxString msg;
		msg.Printf( _T("Fill in all the fields!"));
  		wxMessageBox(msg, _T("ERROR!"), wxOK | wxICON_ERROR , this);
	}
}
