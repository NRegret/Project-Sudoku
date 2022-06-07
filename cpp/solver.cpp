//Solver sudoku dengan metode backtracking
 
//pemanggilan super header
#include"suHeader.cpp"		



//pengecekan apakah kolom kosong
int check_If_Blank(int grid[][9], int &row, int &col)
{
    for (row = 0; row < 9; row++)   
        for (col = 0; col < 9; col++)
            if (grid[row][col] == 0)
                return 1;
    return 0;
}


//Print hasil ke file txt
void print_the_result(int grid[][9])
{
	int k;
	ofstream fout;
	fout.open("out.txt");
	for(k = 0; k < 31; k++)
		fout<<"-";
	fout<<"\n";	
    for (int row = 0; row < 9; row++)
    {
       for (int col = 0; col < 9; col++){
		   if(col==0)
					fout<<"|";
            fout<<" "<<grid[row][col]<<" ";
			if(col % 3 == 2)
				fout<<"|";
			
			}
		if(row % 3 == 2){
				fout<<"\n";	
				for(k = 0; k < 31; k++)
					fout<<"-";
		} 
        fout<<"\n";
    }
    fout.close();
    string line;
    ifstream fin;
    fin.open("out.txt");
    while( ! fin.eof() ){
		getline(fin , line);
		cout<<line<<endl;
	}
	fin.close();
}

//fungsi untuk ngecek kolom mana yang dapat di input untuk sudoku

int Solve_Sudoku(int grid[9][9])
{
    int row, col;
    if ( !check_If_Blank(grid, row, col))			//cek apakah ada kolom kosong
       return 1;
    for (int num = 1; num <= 9; num++)			//loop semua angka yang mungkin
    {
        if (confirm(grid, row, col, num))		//cek apakah bisa di input
        {
            grid[row][col] = num;				//Isi kolom tertentu dengan nomor
            if (Solve_Sudoku(grid))				//Periksa apakah dapat sudoku dengan benar
                return 1;
            grid[row][col] = 0;					//jika gagal masukkan angka 0
        }
    }
    return 0; 
}

//pengecekan row(baris) apakah ada nomer yang sama

int Row_Check(int grid[9][9], int row, int num)
{
    for (int col = 0; col < 9; col++)
        if (grid[row][col] == num)
            return 1;
    return 0;
}

//pengecekan coloumn(kolom) apakah ada nomer yang sama

int Col_Check(int grid[9][9], int col, int num)
{
    for (int row = 0; row < 9; row++)
        if (grid[row][col] == num)
            return 1;
    return 0;
}

//pengecekan apakah ada nomor yang sama dalam 1 box region

int Square_Check(int grid[9][9], int boxRow, int boxCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxRow][col+boxCol] == num)
                return 1;
    return 0;
}

//cek apakah sesuai dengan aturan sudoku

int confirm(int grid[9][9], int row, int col, int num)
{
    return (!Row_Check(grid, row, num) &&
           !Col_Check(grid, col, num) &&
           !Square_Check(grid, row - row%3 , col - col%3, num));
}


//akses file input
void solver(ifstream & fin )
{
	int grid[9][9];
    for(int row = 0; row < 9; row++)
    {
		for(int col = 0; col < 9; col++)
		 fin>>grid[row][col];					
	}
	if (Solve_Sudoku(grid) == 1){							
		  cout<<"Sudoku yang terselesaikan adalah -:"<<endl;
          print_the_result(grid);}							
    else{
         cout<<"Sudoku ini tidak bisa diselesaikan " <<endl<<endl;
		exit(1);
    }     
}