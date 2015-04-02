#ifndef __CONTROL_H__
#define __CONTROL_H__
#include <wx/artprov.h>
#include <wx/wx.h>
#include <wx/string.h>
#define TABS 10
#include "mainframe.h"


extern wxString insert_code;
extern int n_ind;//extent of indentation
extern long int stackcount;
extern bool is_main_def;//to check if main function is defined
extern wxString endlabel_text;//To hold the label for end button;
extern wxString include_lib_list[100];//to hold the include liberaries list
extern long int n_lib;//number of liberaries included...
extern bool is_file_saved;//true is it is saved
extern bool is_cpp_saved;
extern wxString CurrentDocPath; //for saving the psc file.
extern wxString CurrentDocPath2;//for saving cpp file
extern wxString cppinclude,cppglobal,cppcode;

class stk_present_block//for changing the button labels from child dialog, eg to change end's label to end main when defining main func.
{
		struct node
		{
			wxString text;	
			node *link;
		}*top;//text will be going into the label of the end button and into the pseudo code window when end button is pressed.
	public:
		stk_present_block()
		{
			top=NULL;
		}
		void push(wxString input);
		wxString pop();
		wxString getlist(); //returns all elemets of stack as a string where each element is separated by /n 
		wxString getTop()
		{
			return top->text;
		}
		bool IsEmpty()
		{
			if(top==NULL)
				return true;
			else
				return false;
		}
};
extern stk_present_block stk_p_block;
class stk_line_number//for numbering the lines in pseudo cade window
{
	int l_no[100],top;
	public:
		stk_line_number()
		{
			top=-1;
		}
		void push(int n);
		int pop();
		void inc_step()//increments l_no[top]
		{
			l_no[top]++;
		}
		int ret_top()
		{
			return top;
		}
		void ret_array(int x[])
		{
			for(int i=0;i<=top;i++)
			x[i]=l_no[i];
		}
		void reset_top()
		{
			top = -1;
		}
};
extern stk_line_number stk_l_no;
extern int temp_l_no[100];


//conversion functions
wxString conv_variable(wxString input);
wxString conv_g_func(wxString input);
wxString conv_class(wxString input);
wxString conv_struct(wxString input);
wxString conv_globals();
wxString conv_include_lib();
wxString get_data_in_file();
wxString conv_p_func(wxString input);  
wxString conv_p_callfn(wxString input);
wxString conv_io(wxString input); 
wxString conv_psuedo();
wxString conv_p_elseif(wxString input);
wxString conv_p_if(wxString input);
wxString conv_p_forloop(wxString input);
wxString conv_p_whileloop(wxString input);
//diagnostic functions
void test(wxString temp); //to be deleted
void disp ( wxString msg );// to be deleted later



#endif //__CONTROL_H__
