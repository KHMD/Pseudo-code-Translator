#include "dialog_loop.h"

BEGIN_EVENT_TABLE( LoopDialog, wxDialog )
	EVT_BUTTON( wxID_add_loop, LoopDialog::_wxFB_c_add_loop )
	EVT_RADIOBOX( wxID_loop_choice, LoopDialog::_wxFB_c_choice_loop )
END_EVENT_TABLE()

LoopDialog::LoopDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{	
	insert_code.Empty();
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	m_panel3 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	wxString m_loop_choiceChoices[] = { wxT("for"), wxT("while") };
	int m_loop_choiceNChoices = sizeof( m_loop_choiceChoices ) / sizeof( wxString );
	m_loop_choice = new wxRadioBox( m_panel3, wxID_loop_choice, wxT("Choose"), wxDefaultPosition, wxDefaultSize, m_loop_choiceNChoices, m_loop_choiceChoices, 1, wxRA_SPECIFY_ROWS );
	m_loop_choice->SetSelection( 0 );
	bSizer6->Add( m_loop_choice, 0, wxALL, 5 );
	
	t_intialize = new wxStaticText( m_panel3, wxID_ANY, wxT("Enter Initializer"), wxDefaultPosition, wxDefaultSize, 0 );
	t_intialize->SetToolTip( wxT("eg: i=0 where i is already declared variable and i is called the control") );
	
	bSizer6->Add( t_intialize, 0, wxALL, 5 );
	
	t_init_input = new wxTextCtrl( m_panel3, wxID_init_input, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	t_init_input->SetToolTip( wxT("eg: i=0 where i is already declared variable and i is called the control") );
	
	bSizer6->Add( t_init_input, 0, wxALL|wxEXPAND, 5 );
	
	t_condition = new wxStaticText( m_panel3, wxID_ANY, wxT("Enter Condition"), wxDefaultPosition, wxDefaultSize, 0 );
	t_condition->SetToolTip( wxT("eg: i<10 where i is the control") );
	
	bSizer6->Add( t_condition, 0, wxALL, 5 );
	
	t_condition_input = new wxTextCtrl( m_panel3, wxID_condition_input, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	t_condition_input->SetToolTip( wxT("eg: i<10 where i is the control") );
	
	bSizer6->Add( t_condition_input, 0, wxALL|wxEXPAND, 5 );
	
	t_inc_dec = new wxStaticText( m_panel3, wxID_ANY, wxT("Enter the Re-initializer"), wxDefaultPosition, wxDefaultSize, 0 );
	t_inc_dec->SetToolTip( wxT("eg: i= i -1 to decrease i by 1 every iteration") );
	
	bSizer6->Add( t_inc_dec, 0, wxALL, 5 );
	
	t_inc_dec_input = new wxTextCtrl( m_panel3, wxID_inc_dec_input, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	t_inc_dec_input->SetToolTip( wxT("eg: i= i -1 to decrease i by 1 every iteration") );
	
	bSizer6->Add( t_inc_dec_input, 0, wxALL|wxEXPAND, 5 );
	
	m_add_loop = new wxButton( m_panel3, wxID_add_loop, wxT("Add Loop"), wxDefaultPosition, wxDefaultSize, 0 );
	m_add_loop->SetDefault();
	bSizer6->Add( m_add_loop, 0, wxALL|wxEXPAND, 5 );
	
	
	m_panel3->SetSizer( bSizer6 );
	m_panel3->Layout();
	bSizer6->Fit( m_panel3 );
	bSizer5->Add( m_panel3, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer5 );
	this->Layout();
	
	this->Centre( wxBOTH );
}
void LoopDialog :: c_choice_loop(wxCommandEvent& event)
{
	if(m_loop_choice->GetSelection()==1)
	{
		t_init_input->Enable(false);
		t_inc_dec_input->Enable(false);
	}
	else if(m_loop_choice->GetSelection()==0)
	{
		t_init_input->Enable(true);
		t_inc_dec_input->Enable(true);
	}
}
void LoopDialog :: c_add_loop( wxCommandEvent& event )
{
	wxString p_block;
	insert_code.Empty();
	if(m_loop_choice->GetSelection()==0)
	{
		if(t_condition_input->GetLastPosition()!=0)
		{
			insert_code.Empty();
			insert_code<<m_loop_choice->GetStringSelection()<<" loop ";
			if(t_init_input->GetLastPosition()!=0)
			{
				insert_code<<"from "<<t_init_input->GetValue()<<" ";
			}
			insert_code<<"until "<<t_condition_input->GetValue()<<" update ";
			if(t_inc_dec_input->GetLastPosition()!=0)
			{
				insert_code<<t_inc_dec_input->GetValue();
			}
			p_block<<"End "<<m_loop_choice->GetStringSelection();
			stk_p_block.push(p_block);
			endlabel_text.Empty();
			endlabel_text<<p_block;
			EndModal(wxID_CANCEL);
		}
		else
		{
			wxString msg;
			msg.Printf( _T("Fill in all necessary fields!"));
  			wxMessageBox(msg, _T("ERROR!"), wxOK | wxICON_ERROR , this);
		} 
	}
	else if(m_loop_choice->GetSelection()==1)
	{
		if(t_condition_input->GetLastPosition()!=0)
		{
			insert_code.Empty();
			insert_code<<m_loop_choice->GetStringSelection()<<" loop";
			insert_code<<" until "<<t_condition_input->GetValue()<<" ";
			p_block<<"End "<<m_loop_choice->GetStringSelection();
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
}
