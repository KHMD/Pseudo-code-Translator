#include <wx/wx.h>
#include "mainframe.h"

class Pct : public wxApp
{
	public:
    	virtual bool OnInit();
};

IMPLEMENT_APP(Pct)

bool Pct::OnInit()
{
	
    MainFrame *frame = new MainFrame(NULL);
    if(argc==2)
	{
		CurrentDocPath=argv[1];
		frame->open_psc();
	}
    frame->Show(TRUE);
    SetTopWindow(frame);
    return TRUE;
}
