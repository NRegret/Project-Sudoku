//Input

//pemanggilan super header
#include"suHeader.cpp"

//Fungsi untuk pengecekan apakah file kosong

int emptyFile(ifstream &fin)
{
	int temp = fin.peek();
	if(temp == EOF)
		return 1;
	else return 0;	
}

//Fungsi untuk pengecekan filenya ada atau tidak
int exist(ifstream &fin)
{
	if(!fin)
		return 0;
	else
		return 1;
}

//Fungsi input file

void input()
{
	string filename ;
	ifstream fin;
	cout<<"Inputkan nama file : "<<endl;
	cin>>filename;
	fin.open(filename.c_str());
	if(!exist( fin )){
		cout<<"File tidak ditemukan! "<<endl;
		return;
	}
	else if (emptyFile(fin))
		cout<<"file kosong!";
	else{
		 cout<<endl<<"File yang di input adalah : "<<filename<<endl<<endl;
		 cout<<endl<<"Isi filenya adalah : "<<endl<<endl;
		 string line;
		 while( !fin.eof() ){
		 getline(fin , line);
		 cout<<line<<endl;
		 }
		 fin.close();
		 fin.open( filename.c_str() );
		 solver( fin );
		 cout << endl << "Output disimpan di out.txt" << endl;
		 cout << endl << "Thanks (*_*)7 " << endl;
		}
	fin.close();	
}