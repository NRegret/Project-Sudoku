//Koleksi Header sama deklarasi beberapa fungsi

#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;

//Fungsi Generator

void generate();
void swap_Row(int , int);
void swap_Col(int , int);
void print_the_querry(int);
void solver(ifstream & fin);

//fungsi solver

void input();
int Solve_Sudoku(int grid[][9]);
void print_the_result(int grid[][9]); 
int check_If_Blank(int grid[][9], int &row, int &col);
int confirm(int grid[][9], int , int , int );

