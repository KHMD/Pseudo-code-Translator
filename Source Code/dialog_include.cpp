#include "dialog_include.h"

BEGIN_EVENT_TABLE( IncludeDialog, wxDialog )
	EVT_BUTTON( wxID_add, IncludeDialog::_wxFB_c_add )
	EVT_BUTTON( wxID_remove, IncludeDialog::_wxFB_c_remove )
	EVT_BUTTON( wxID_done, IncludeDialog::_wxFB_c_done )
END_EVENT_TABLE()

IncludeDialog::IncludeDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{	
	wxBoxSizer* bmain;
	bmain = new wxBoxSizer( wxVERTICAL );
	
	t_input = new wxStaticText( this, wxID_ANY, wxT("Enter the name of the liberary you want to include"), wxDefaultPosition, wxDefaultSize, 0 );
	bmain->Add( t_input, 0, wxALL, 5 );
	
	t_lib_input = new wxTextCtrl( this, wxID_lib_input, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	t_lib_input->SetToolTip( wxT("eg: math.h") );
	
	bmain->Add( t_lib_input, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_listBox = new wxListBox( this, wxID_listbox, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_ALWAYS_SB ); 
	bSizer2->Add( m_listBox, 1, wxALL, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_add = new wxButton( this, wxID_add, wxT("ADD"), wxDefaultPosition, wxDefaultSize, 0 );
	m_add->SetDefault();
	bSizer3->Add( m_add, 0, wxALL|wxEXPAND, 5 );
	
	m_remove = new wxButton( this, wxID_remove, wxT("REMOVE"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_remove, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer2->Add( bSizer3, 0, wxEXPAND, 5 );
	
	
	bmain->Add( bSizer2, 0, wxEXPAND, 5 );
	
	m_done = new wxButton( this, wxID_done, wxT("DONE"), wxDefaultPosition, wxDefaultSize, 0 );
	bmain->Add( m_done, 0, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bmain );
	this->Layout();
	
	this->Centre( wxBOTH );
	c_init();
}
void IncludeDialog :: c_init()
{
	m_listBox->Clear();
	for(int i=0;i<=n_lib;i++)
	 m_listBox->Append(include_lib_list[i]);
}
void IncludeDialog :: c_add(wxCommandEvent& event)
{
	wxString temp;
	if(t_lib_input->GetLastPosition()!=0)
	{
		temp.Empty();
		temp<<"#include<"<<t_lib_input->GetValue()<<">";
		n_lib++;
		include_lib_list[n_lib]=temp;
		t_lib_input->Clear();
		c_init();
	}
	else
	{
		wxString msg;
		msg.Printf( _T("Fill in the field to add!"));
  		wxMessageBox(msg, _T("ERROR!"), wxOK | wxICON_ERROR , this);
	}
}
void IncludeDialog :: c_remove(wxCommandEvent& event)
{
//	m_listBox->Delete(m_listBox->GetSelection());
//	include_lib_list[m_listBox->GetSelection()].Empty();
	if(n_lib>=0)
	n_lib--;
	c_init();
}
void IncludeDialog :: c_done(wxCommandEvent& event)
{
	//include_lib_list.Empty();
	//include_lib_list<<t_lib_list->GetValue();
	EndModal(wxID_CANCEL);
}
