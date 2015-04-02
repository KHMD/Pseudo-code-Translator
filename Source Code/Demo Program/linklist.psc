@Begin
Function main
	1. Variable input as int
	2. Read input for input
	3. Variable start as node* 
	4. Call createnode(input) store returned value in start
	5. Display start->data
End main

Function createnode parameters: int data returns node*

	1. Variable temp as node* 
	2. temp = new node
	3. temp->data = data
	4. temp->link = NULL
	5. return temp
End createnode
$
Structure node:
	Variable data as int
	Variable link as node* 
End Structure




#0^
#include<iostream>%
$0#
^-1#0#
@EndCode

