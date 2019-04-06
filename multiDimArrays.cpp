/*************************************************************************
* Program:                                                                 
*    Assignment 40, Multi-Dimensional Arrays                               
*    Brother Ridges, CS124                                                 
* Author:                                                                  
*    Alexander Berryhill                                                   
* Summary:                                                                 
*    This program will get a tic tac toe board from a file than write it   
*    into a better board then write that into a file.                      
*                                                                          
*                                                                          
*                                                                          
*    Estimated:  0.5 hrs                                                   
*    Actual:     3.5 hrs                                                   
*      The most difficult part was finding that you need to write the      
*      array of the old file to the new file not the board.                
*************************************************************************/

#include <fstream>
#include <iostream>
using namespace std;

/*************************************************************************
 * getInFile will prompt and get the source fileName.                      
 ************************************************************************/
void getInFile(char fileName[])
{
   cout << "Enter source filename: ";
   cin >> fileName;
   cin.ignore();
   return;
}

/*************************************************************************
 * getOutFile will prompt and get an output fileName.                      
 ************************************************************************/
void getOutFile(char fileName[])
{
   cout << "Enter destination filename: ";
   cin >> fileName;
   cin.ignore();
   return;
}

/*************************************************************************
 * readFile will read the file int the array file[][]                      
 ************************************************************************/
void readFile(char fileName[], char file[3][3])
{
   ifstream fin;
   fin.open(fileName);
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         fin >> file[i][j];
      }
   }
   fin.close();
   return;
}

/*************************************************************************
 * getBoard will make a board[][] from file[][]                            
 ************************************************************************/
 void getBoard(char file[3][3], char board[5][11])
{
   bool row = true;
   int x = 0;
   int y = 0;

   for (int i = 0; i < 5; i++)
   {
      if (row)
      {
         for (int j = 0; j < 11; j++)
         {
            switch (j)
            {
               case 0: //spaces                                            
               case 2:
               case 4:
               case 6:
               case 8:
               case 10:
                  board[i][j] = ' ';
                  break;
               case 3:                 // lines                            
               case 7:
                  board[i][j] = '|';
                  break;
               case 1:
               case 5:
               case 9:
                  switch (file[y][ x++ ])
                  {
                                           case 'X':
                        board[i][j] = 'X';
                        break;
                     case 'O':
                        board[i][j] = 'O';
                        break;
                     case '.':
                        board[i][j] = ' ';
                        break;
                     default:
                        break;
                  }
                  break;
               default:
                  cout << "j loop 1 in get board out of bounds\n";
                  break;
            }
         }
         row = false;
      }
      else
      {
         for (int j = 0; j < 11; j++)
         {
            switch (j)
            {
               case 3:
               case 7:
                  board[i][j] = '+';
                  break;
               default:
                    board[i][j] = '-';
                  break;
            }
         }
         x = 0;
         y++;
         row = true;
      }
   }
   return;
}

/*************************************************************************
 * display will display the board                                          
 ************************************************************************/
void display(char board[5][11])
{
   for (int i = 0; i < 5; i++)
   {
      for (int j = 0; j < 11; j++)
      {
         cout << board[i][j];
      }
      cout << endl;
   }
   return;
}

/*************************************************************************
 * writeFile will write the board into the output file.                    
 ************************************************************************/
void writeFile(char fileName[], char file[3][3])
{
       ofstream fout;
   fout.open(fileName);
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         fout << file[i][j];
      }
      fout << endl;
   }
   fout.close();
   cout << "File written\n";
   return;
}

/*************************************************************************
 * main will declare fileName, file and board. Get the in fileName, read   
 * the file, build the board, display it, get the out fileName, then       
 * write it.                                                               
 ************************************************************************/
int main()
{
   char fileName[256];
   char file[3][3];
   char board[5][11];

   getInFile(fileName);
   readFile(fileName, file);
   getBoard(file, board);
   display(board);
   getOutFile(fileName);
    writeFile(fileName, file);

   return 0;
}