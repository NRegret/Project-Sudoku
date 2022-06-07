//Main

//pemanggilan super header
#include"suHeader.cpp"



int main()
{
	int choice;
	char ch;
	cout<<"\t\t\t"<<"Selamat datang di Aplikasi Sudoku"<<endl;
	cout<<"Ingin memecahkan Sodoku Anda sendiri? :Tekan 1 Atau ingin membuatnya? :Tekan 2"<<endl;
	cin>>choice;
	do{
	if(choice == 1)
		input();	
	else if(choice == 2){
		generate();
		cout<<endl<<"Tekan Enter untuk memproses"<<endl;cin.ignore();
		cin.ignore();
		ifstream fin1;
		fin1.open("check.txt");
		solver(fin1);
		cout<<endl<<"Output disimpan di out.txt"<<endl;
		cout<<endl<<"Thanks (*_*)7 "<<endl;
	}
	else
		cout<<"Invalid";
		cout<<"Ulangi? Y/N"<<endl;
		cin>>ch;
	}while(toupper(ch)=='Y');
}

