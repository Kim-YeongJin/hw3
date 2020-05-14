#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "fixfld.h"
#include "delim.h"
#include "length.h"
#include <cstring>

class student
{
  public:
	// fields
	char identifier [11];
	char name [11];
	char Address [16];
	char dofe [16];
	char credit_hours [3];
	
	//operations
	student ();
	student (char input_id[], char input_name[], char input_addr[], char input_dofe[], char input_hours[]);
	void Clear ();

	static int InitBuffer (DelimFieldBuffer &);
	static int InitBuffer (LengthFieldBuffer &);
	static int InitBuffer (FixedFieldBuffer &);

	int Unpack (IOBuffer &);
	int Pack (IOBuffer &) const;
	void Print (ostream &, char * label = 0) const;
};

#endif
