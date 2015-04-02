#include "control.h"

wxString insert_code;
wxString endlabel_text;
wxString CurrentDocPath;
wxString CurrentDocPath2;
wxString include_lib_list[100];
int n_ind;
long int n_lib;
long int stackcount;
bool is_main_def;
bool is_file_saved;
bool is_cpp_saved;
wxString cppinclude,cppglobal,cppcode;

void stk_present_block :: push(wxString input)
{
	node *temp=new node;
	temp->link=NULL;
	temp->text<<input;
	if(top==NULL)
	{
		top=temp;
	}
	else
	{
		temp->link=top;
		top=temp;
	}
}
wxString stk_present_block :: pop()
{
	node *temp;
	wxString x;
	if(top!=NULL){
		temp=top;
		x<<temp->text;
		top=top->link;
		temp->link=NULL;
		delete temp;
		return x;
	}
	else
		return _T("Stack Empty");
}
wxString stk_present_block :: getlist()
{
	stackcount = 0;
	stk_present_block templist;
	wxString return_string;
	return_string.Empty();
	while(!this->IsEmpty())
	{
		stackcount++;
		return_string<<this->getTop()<<"%";
		templist.push(this->pop());
	}
	while(!templist.IsEmpty())
	{
		this->push(templist.pop());
	}
	return return_string;
}
void stk_line_number :: push(int n)
{
	top++;
	l_no[top]=n;
}
int stk_line_number :: pop()
{
	top--;
	return l_no[top+1];
}

stk_line_number stk_l_no;
int temp_l_no[100];
stk_present_block stk_p_block;

wxString get_data_in_file()//returns the contents of the the .psc file as 1 wxString varible...
{
	wxTextFile file;
	wxString tempString;
	file.Open(CurrentDocPath);
	if(file.IsOpened())
    {
         tempString.Empty();
		 //store file data for further processing
       	 for (wxString str = file.GetFirstLine(); !file.Eof();str = file.GetNextLine())
       	 {
			tempString += str;
			tempString += "\n";
		 }
	}
	return tempString;
}

//start of funcs for conv include libs...
wxString conv_include_lib()
{
	wxString tempString;
	tempString.Empty();
	tempString=get_data_in_file();
	tempString.Replace("@Begin\n","");
	tempString=tempString.AfterFirst('^');
	tempString=tempString.BeforeFirst('$');
	tempString.Replace("%","");
	if(tempString.Contains(wxT("iostream")))
	tempString<<"\nusing namespace std;\n";
	return tempString;	
}
//end of funcs for conv include libs...

//starting of funcs to conv pseudo part...


wxString conv_p_func(wxString input)//input =  Function func_name parameters: int var1,char * var2,int var3 returns char*
{
	wxString output,fname,rtype,params;
	input = input.AfterFirst(' '); //input contains "func_name parameters: int var1,char * var2,int var3 returns char*"
	fname = input.BeforeFirst(' ');
	input = input.AfterFirst(' ');//input contains "parameters: int var1,char * var2,int var3 returns char*"
	input = input.AfterFirst(' ');//input contains "int var1,char * var2,int var3 returns char*"
	input.Replace("returns","%returns");//input contains "int var1,char * var2,int var3 %returns char*"
	params = input.BeforeFirst('%');
	input = input.AfterFirst('%');
	rtype = input.AfterFirst(' ');
	output.Empty();
	if(params.Contains(wxT("none"))) params.Empty();
	if (fname == "main") rtype = "int";
	output<< rtype <<" " << fname << "(" << params <<")\n{\n"; //output =  char* func_name(int var1,char * var2,int var3)\n{
	return output;
}

wxString conv_p_elseif(wxString input)//input =  else if condition
{
	wxString output,condition;
	input = input.AfterFirst(' '); 
	condition = input.AfterFirst(' ');
	output.Empty();
	output<<"else if( " << condition << " )\n"; //output =  else if (condition)\n
	return output;
}

wxString conv_p_if(wxString input)//input = if condition
{
	wxString output,condition;
	condition = input.AfterFirst(' ');
	output.Empty();
	output<<"if( " << condition << " )\n"; //output = if (condition)\n
	return output;
}

wxString conv_p_forloop(wxString input)//input =  for loop from i=0 until i<5 update i=i+2
{
	wxString output,initial,condition,reinitial;
	input.Replace("for loop from","for");
	initial = input.AfterFirst(' '); 
	input = initial;//i=0 until i<5 update i=i+2
	initial = initial.BeforeFirst(' ');
	input = input.AfterFirst(' ');//until i<5 update i=i+2
	input = input.AfterFirst(' ');//i<5 update i=i+2
	condition = input.BeforeFirst(' ');
	input = input.AfterFirst(' ');//update i=i+2
	reinitial = input.AfterFirst(' ');
	output.Empty();
	output<<"for( "<<initial<<" ; "<< condition << " ; "<< reinitial <<" )\n"; //output =  for( int i=0 ; i<5 ; i=i+2 )\n
	return output;
}


wxString conv_p_whileloop(wxString input)//input =  while loop until x>asd
{
	wxString output,condition;
	input.Replace("while loop until ","while ");
	condition = input.AfterFirst(' '); 
	output.Empty();
	output<<"while( "<<condition <<" )\n"; //output =  while( i<5 )\n
	return output;
}
wxString conv_p_callfn(wxString input)//Call sample.asdf() store returned value in abc
{
	wxString output,fname,rvar;
	fname = input.AfterFirst(' ');
	fname = fname.BeforeFirst(')'); //has sample.asdf()
	fname<<")";
	rvar = input.AfterLast(' '); //abc
	output.Empty();
	if(input.Contains(wxT("returned")))
	{
		rvar<<" = ";
		output<<rvar<<fname<<";";
	}
	else
	{
		output<<fname<<";";
	}
	return output;
}


wxString conv_io(wxString input)//To convert to CIN and COUT statements
{
	wxString output;
	output.Empty();
	if(input.Contains(wxT("Read")))
	{
		output<<"cin>>";
		input=input.AfterFirst('r');
		output<<input<<";";
	}	
	else if(input.Contains(wxT("Display")))
	{
		output<<"cout<<";
		input=input.AfterFirst('y');
		output<<input<<";";
	}	
	return output;	
}

wxString conv_psuedo()//Parse psuedo code Tab 
{
	wxString tempString,tstring2,convString,finalString,pString; 
	int indcount=0;//counting indents of normal statements
	int endindcount = 0;//counting indent of end statements
	int endmainposition = 0;
	tempString.Empty();
	tempString=get_data_in_file();
	convString.Empty();
	tempString.Replace("@Begin\n","");
	pString= tempString.BeforeFirst ('$');
	//the main parser:
	pString.Replace("\n","$\n");
	tempString.Empty();
	while(pString.Contains(wxT("$")))
	{
		tempString.Empty();
	    tempString = pString.BeforeFirst('$');//tempstring stores a line 
	    //check if its a function statement:
	    //disp(tempString);
	    if(tempString.Contains("Display") && (!tempString.Matches("Function*")))
	    {
			tstring2 = tempString.BeforeFirst('D');
			indcount = tstring2.Freq('.');
			for(int i=0; i<indcount;i++)convString<<"\t";//place the indents
			tempString.Replace(". Display ",". %Display ");
			tempString = tempString.AfterFirst('%');
			convString << conv_io(tempString)<<"\n";
		}
		else if(tempString.Contains("Read"))
	    {
			tstring2 = tempString.BeforeFirst('R');
			indcount = tstring2.Freq('.');
			for(int i=0; i<indcount;i++)convString<<"\t";//place the indents
			tempString.Replace("Read ","%Read ");
			tempString = tempString.AfterFirst('%');
			convString << conv_io(tempString)<<"\n";
		}
		else if(tempString.Contains("Call "))
	    {
			tstring2 = tempString.BeforeFirst('C');
			indcount = tstring2.Freq('.');
			for(int i=0; i<indcount;i++)convString<<"\t";//place the indents
			tempString.Replace("Call ","%Call ");
			tempString = tempString.AfterFirst('%');
			convString << conv_p_callfn(tempString)<<"\n";
		}
		else if(tempString.Contains("Variable"))
	    {
			tstring2 = tempString.BeforeFirst('V');
			indcount = tstring2.Freq('.');
			for(int i=0; i<indcount;i++)convString<<"\t";//place the indents
			tempString.Replace("Variable ","%Variable ");
			tempString = tempString.AfterFirst('%');
			convString << conv_variable(tempString)<<"\n";
		}
		else if(tempString.Contains("else if "))
	    {
			tstring2 = tempString.BeforeFirst('e');
			indcount = tstring2.Freq('.');
			endindcount = indcount;
			for(int i=0; i<indcount;i++)convString<<"\t";//place the indents
			tempString.Replace("else if ","%else if ");
			tempString = tempString.AfterFirst('%');
			convString << conv_p_elseif(tempString);
			for(int i=0; i<indcount;i++)convString<<"\t";
			convString<<"{\n";
		}
		else if(tempString.Contains("if "))
	    {
			tstring2 = tempString.BeforeFirst('i');
			indcount = tstring2.Freq('.');
			endindcount = indcount;
			for(int i=0; i<indcount;i++)convString<<"\t";//place the indents
			tempString.Replace("if ","%if ");
			tempString = tempString.AfterFirst('%');
			convString << conv_p_if(tempString);
			for(int i=0; i<indcount;i++)convString<<"\t";
			convString<<"{\n";
		}
		else if(tempString.Contains("else "))
	    {
			tstring2 = tempString.BeforeFirst('e');
			indcount = tstring2.Freq('.');
			endindcount = indcount;
			for(int i=0; i<indcount;i++)convString<<"\t";//place the indents
			convString <<"else \n";
			for(int i=0; i<indcount;i++)convString<<"\t";
			convString<<"{\n";
		}
		else if(tempString.Contains("for loop from ")) 
	    {
			tstring2 = tempString.BeforeFirst('f');
			indcount = tstring2.Freq('.');
			endindcount = indcount;
			for(int i=0; i<indcount;i++)convString<<"\t";//place the indents
			tempString.Replace("for loop from ","%for loop from ");
			tempString = tempString.AfterFirst('%');
			convString << conv_p_forloop(tempString);
			for(int i=0; i<indcount;i++)convString<<"\t";
			convString<<"{\n";
		}
		else if(tempString.Contains("while loop until ")) 
	    {
			tstring2 = tempString.BeforeFirst('w');
			indcount = tstring2.Freq('.');
			endindcount = indcount;
			for(int i=0; i<indcount;i++)convString<<"\t";//place the indents
			tempString.Replace("while loop until ","%while loop until ");
			tempString = tempString.AfterFirst('%');
			convString << conv_p_whileloop(tempString);
			for(int i=0; i<indcount;i++)convString<<"\t";
			convString<<"{\n";
		}
		else if(tempString.Contains("Function ")) //contains function main
		{
			endindcount=0;
			convString <<  conv_p_func(tempString);
		}
		else if(tempString.Matches("*End *"))
		{
			
			for(int i=0; i<endindcount;i++)convString<<"\t";
			convString << "}\n";
			endindcount--;
			if(tempString.Contains("main")) endmainposition = convString.Length();
			
		}
		else if(tempString.Matches("*?. *"))// operation - eg 4.2. xyz = 43.21
		{
			tstring2 = tempString.BeforeFirst(' ');
			indcount = tstring2.Freq('.');
			for(int i=0; i<indcount;i++)convString<<"\t";//place the indents
			tempString = tempString.AfterFirst(' ');
			convString << tempString <<";\n";
		}
	   pString= pString.AfterFirst('$');
	}
	tstring2.Empty();
	tempString.Empty();
	int mainposition = convString.Find("int main");
	tempString = convString.Mid(mainposition,(endmainposition-mainposition));
	tstring2 = convString.Left(mainposition);//all to left of main.
	finalString.Empty();
	finalString <<tstring2;
	tstring2 = convString.Mid(endmainposition);
	finalString << tstring2;
	finalString <<"\n"<<tempString;
	return finalString;	    
}





//end of funcs for conv pseudo part...

//starting of funcs to conv globals...
wxString conv_variable(wxString input) //converts input of form "Variable vame[23] as datatype*"  to datatype* vname[23];
{
	wxString output,vname,datatype;
	input = input.AfterFirst(' '); //input contains "vame[23] as datatype*"
	vname = input.BeforeFirst(' ');
	input = input.AfterFirst(' ');//input contains "as datatype*
	datatype= input.AfterFirst(' ');
	output.Empty();
	output<<datatype<<" "<<vname<<";";
	return output;	
}

wxString conv_g_func(wxString input)//input =  Function func_name parameters: int var1,char * var2,int var3 returns char*
{
	wxString output,fname,rtype,params;
	input = input.AfterFirst(' '); //input contains "func_name parameters: int var1,char * var2,int var3 returns char*"
	fname = input.BeforeFirst(' ');
	input = input.AfterFirst(' ');//input contains "parameters: int var1,char * var2,int var3 returns char*"
	input = input.AfterFirst(' ');//input contains "int var1,char * var2,int var3 returns char*"
	input.Replace("returns","%returns");//input contains "int var1,char * var2,int var3 %returns char*"
	params = input.BeforeFirst('%');
	if(params.Contains(wxT("none"))) params.Empty();
	input = input.AfterFirst('%');
	rtype = input.AfterFirst(' ');
	output.Empty();
	output<< rtype <<" " << fname << "(" << params <<");"; //output =  char* func_name(int var1,char * var2,int var3);
	return output;
}

wxString conv_class(wxString input)//input contains class classname:$/nprivate:$/nvariable ...$/n
{
 	wxString output,classname,temporary;
 	output.Empty();
 	classname = input.BeforeFirst('$');//contains Class classname:
 	classname = classname.AfterFirst(' ');
 	classname = classname.BeforeFirst(':');
 	input = input.AfterFirst('$');//contains \n\tprivate:$\n.....
 	output << "class " <<classname;
 	temporary = input.BeforeFirst('$');//contains \n\tprivate:
	output<<"\n{"<<temporary<<"\n";//has private:\n
	input= input.AfterFirst('$'); //list of data members - either variables or functions and then $\n\tpublic:$\n
	while(input.Contains(wxT("public:")))//input has /nint ....$/n...$/npublic:$/n
	{
		temporary = input.BeforeFirst('$');//contains variable or function or public;
		if(temporary.Contains(wxT("public:"))) break;
		else if(temporary.Contains(wxT("Variable")))
		{
			temporary.Replace("\t ","");
			output<<"\t "<< conv_variable(temporary)<<"\n";
		}
		else if(temporary.Contains(wxT("Function")))
		{
			temporary.Replace("\t ","");
			output<<"\t " << conv_g_func(temporary)<<"\n";
		}
		input = input.AfterFirst('$');
	}//input contains \n\tpublic:$\n ... \nEnd Class$\n
	temporary = input.BeforeFirst('$');//contains \n\tpublic:
	output<<temporary<<"\n";//output has public:\n
	input = input.AfterFirst('$');//input has list of datamembers and then has endclass$\n
	while(input.Contains(wxT("End")))//input has /nint ....$/n...$/npublic:$/n
	{
		temporary = input.BeforeFirst('$');//contains variable or function or public;
		if(temporary.Contains(wxT("End"))) break;
		else if(temporary.Contains(wxT("Variable")))
		{
			temporary.Replace("\t ","");
			output<<"\t "<< conv_variable(temporary)<<"\n";
		}
		else if(temporary.Contains(wxT("Function")))
		{
			temporary.Replace("\t ","");
			output<<"\t " << conv_g_func(temporary)<<"\n";
		}
		input = input.AfterFirst('$');
	}
	output<<"\n};";
	return output;
}

wxString conv_struct(wxString input)//input contains Structure structname:$\nvariable ...$\n
{
 	wxString output,structname,temporary;
 	output.Empty();
 	structname = input.BeforeFirst('$');//contains Structure structname:
 	structname = structname.AfterFirst(' ');
 	structname = structname.BeforeFirst(':');
 	input = input.AfterFirst('$');//Contains list of data members - either variables or functions and then End Structure
 	output << "struct " <<structname;
	output<<"\n{\n";
	while(input.Contains(wxT("End")))//input has /nint ....$/n...$/npublic:$/n
	{
		temporary = input.BeforeFirst('$');//contains variable or function or public;
		if(temporary.Contains(wxT("End"))) break;
		else if(temporary.Contains(wxT("Variable")))
		{
			temporary.Replace("\t ","");
			output<<"\t "<< conv_variable(temporary)<<"\n";
		}
		else if(temporary.Contains(wxT("Function")))
		{
			temporary.Replace("\t ","");
			output<<"\t " << conv_g_func(temporary)<<"\n";
		}
		input = input.AfterFirst('$');
	}//input contains End Struct $\n
	output<<"\n};";
	return output;
}

wxString conv_globals()//Parse Globals Tab Code
{
	wxString tempString,convString,gString; 
	tempString.Empty();
	tempString=get_data_in_file();
	convString.Empty();
	tempString.Replace("@Begin\n","");
	gString= tempString.AfterFirst ('$');
	gString=gString.BeforeFirst('#');//gstring has everything in globals tab in one long string
	//the main parser:
	gString.Replace("\n","$\n");
	tempString.Empty();
	while(gString.Contains(wxT("$")))
	{
		tempString.Empty();
	    tempString = gString.BeforeFirst('$');//tempstring stores a line
	   	//converting variable
	   	if(tempString.Contains(wxT("Variable")))
		convString << conv_variable(tempString)<<"\n\n"; // the result string has converted form of variable
	   	//Converting Class;
	   	else if (tempString.Contains(wxT("Class"))) 
	   	{
			//gstring has everything from classname$all other strings after that
	   		tempString = gString;
	   		tempString.Replace("End Class","End Class%");//Temp String will have everything
	   		gString = tempString.AfterFirst('%');//gString has moved out of the class;
	   		tempString = tempString.BeforeFirst('%');//TempString has class to end class
	   		convString << conv_class(tempString)<<"\n\n";
	   }
	   //Converting Structure
	   else if (tempString.Contains(wxT("Structure"))) 
	   {
			//gstring has everything from Structure name$\nall other strings after that
	   		tempString = gString;
	   		tempString.Replace("End Structure","End Structure%");//Temp String will have everything
	   		gString = tempString.AfterFirst('%');//gString has moved out of the class;
	   		tempString = tempString.BeforeFirst('%');//TempString has Structure to End Structure
	   		convString << conv_struct(tempString)<<"\n\n";
	   }
	   gString= gString.AfterFirst('$');
	}
	
	return convString;	    
}
	
//end of funcs for conv globals...


//disp(wxString::Format(wxT("%i"),integervariable)); to display integers
//Diagnostic Functions  - To be deleted on completion of project
void disp ( wxString msg )//to display strings
{
	
    wxMessageBox(msg, _T("Diagnostic Display!"), wxOK | wxICON_INFORMATION, NULL);
}



void test(wxString temp) //write the string temp to a file
{
	
	wxFileDialog *SaveDialog = new wxFileDialog(NULL, _("Save Temp"), wxEmptyString, wxEmptyString,_("Temporary Diagnostic File (*.txt)|*.txt"),wxSAVE | wxOVERWRITE_PROMPT, wxDefaultPosition);
 
	// Creates a Save Dialog 
	if (SaveDialog->ShowModal() == wxID_OK) // If the user clicked "OK" and not cancel
	{	
		wxString CurrentDocPath2 = SaveDialog->GetPath();// set the path of our current document to the file the user chose to save
		wxTextFile file;
		file.Create(CurrentDocPath2);
		if(file.IsOpened())
		{
			file.AddLine(temp);
			file.Write();
		}
	}
 
	// Clean up 
	SaveDialog->Destroy();
}
