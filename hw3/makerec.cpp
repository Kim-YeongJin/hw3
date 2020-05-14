#include <fstream>
#include <iomanip>
#include <cstring>
#include "iobuffer.h"
#include "fixfld.h"
#include "length.h"
#include "student.h"
#include "coursereg.h"
#include "buffile.h"
#include "recfile.h"
#include "recfile.cpp"

student * st[10];
coursereg * cs[10];

void InitPerson(){

	st[0] = new student ("10", "A", "Seoul", "2014", "10");
	st[1] = new student ("11", "B", "Seoul", "2014", "10");	
	st[2] = new student ("12", "C", "Seoul", "2014", "10");
	st[3] = new student ("13", "D", "Seoul", "2014", "10");
	st[4] = new student ("14", "E", "Seoul", "2014", "10");
	st[5] = new student ("15", "F", "Seoul", "2014", "10");
	st[6] = new student ("16", "G", "Seoul", "2014", "10");
	st[7] = new student ("17", "H", "Seoul", "2014", "10");
	st[8] = new student ("18", "I", "Seoul", "2014", "10");
	st[9] = new student ("19", "J", "Seoul", "2014", "10");
	
	cs[0] = new coursereg ("1", "a", "10", "A");
	cs[1] = new coursereg ("2", "b", "10", "A");
	cs[2] = new coursereg ("3", "c", "10", "A");
	cs[3] = new coursereg ("4", "d", "10", "A");
	cs[4] = new coursereg ("5", "e", "10", "A");
	cs[5] = new coursereg ("6", "f", "10", "A");
	cs[6] = new coursereg ("7", "g", "10", "A");
	cs[7] = new coursereg ("8", "h", "10", "A");
	cs[8] = new coursereg ("9", "i", "10", "A");
	cs[9] = new coursereg ("10", "j", "10", "A");
}


void st_RecFile(IOBuffer &Buff, char *myfile){

	int result;
	
	int st_recaddr[10];
	
	RecordFile<student> Recfile_write (Buff);
	Recfile_write.Create (myfile, ios::out);
	
	cout << "create student file " << result << endl;
	
	if(!result){
		cout << "Unable to create file " << myfile << endl;
		return;
	}
	
	for(int i=0; i<10; i++){
		st_recaddr[i] = Recfile_write.Write(*st[i]);
		cout << "<student> write at " << st_recaddr[i] << endl;
	}
	
	Recfile_write.Close();
	
	RecordFile<student> Recfile_read (Buff);
	Recfile_read.Open(myfile, ios::in);
	
	for(int i=0; i<10; i++){
		Recfile_read.Read(*st[i]);
		st[i]->Print(cout, "record");
	}
	
	Recfile_read.Close();

}

void cs_RecFile(IOBuffer &Buff, char *myfile){

	int result;
	
	int cs_recaddr[10];
	
	RecordFile<coursereg> Recfile_write (Buff);
	Recfile_write.Create (myfile, ios::out);
	
	cout << "create file " << result << endl;
	
	if(!result){
		cout << "Unable to create file " << myfile << endl;
		return;
	}
	
	for(int i=0; i<10; i++){
		cs_recaddr[i] = Recfile_write.Write(*cs[i]);
		cout << "<course> write at " << cs_recaddr[i] << endl;
	}
	
	Recfile_write.Close();
	
	RecordFile<coursereg> Recfile_read (Buff);
	Recfile_read.Open(myfile, ios::in);
	
	for(int i=0; i<10; i++){
		Recfile_read.Read(*cs[i]);
		cs[i]->Print(cout, "record");
	}
	
	Recfile_read.Close();

}

int main()
{
	InitPerson();

	FixedFieldBuffer fx_Buffer(10);
	student::InitBuffer(fx_Buffer);
	st_RecFile(fx_Buffer, "student_rec.dat");
	
	DelimFieldBuffer dl_Buffer;
	coursereg::InitBuffer(dl_Buffer);
	cs_RecFile(dl_Buffer, "course_rec.dat");
	
}
