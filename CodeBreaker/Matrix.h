#include <string>
#include <iostream>
using namespace std;

class Matrix
{
   private:
   double **mat;
   int rows, columns;
   void swap(string roworcolumn, int row1, int row2)
   {
	   if (roworcolumn == "row")
	   {
		   if (row1 > rows || row1 < 0 || row2 > rows || row2 < 0)
		   {
			   cout << "Sorry ,swap not possible" << endl;
			   return;
		   }
		   int column = this->columns;
		   double * temp = new double;
		   for (int i = 0; i<column; i++)
		   {
			   *temp = mat[row1 - 1][i];
			   mat[row1 - 1][i] = mat[row2 - 1][i];
			   mat[row2 - 1][i] = *temp;
		   }
		   delete temp;
	   }
	   else {
		   if (row1 > columns || row1 < 0 || row2 > columns || row2<0)
		   {
			   cout << "Sorry, swap not possible" << endl;
			   return;
		   }
		   double *temp = new double;
		   int row = this->getRows();
		   for (int i = 0; i<row; i++)
		   {
			   *temp = mat[i][row1 - 1];
			   mat[i][row1 - 1] = mat[i][row2 - 1];
			   mat[i][row2 - 1] = *temp;
		   }
		   delete temp;
	   }
   }
   void rowaddition(int row1, int row2, int factor)
   {
	   for (int i = 0; i < columns; i++)
	   {
		   mat[row2][i] += factor*(mat[row1][i]);
	   }
   }
   void columnaddition(int column1, int column2, double factor)
   {
	   for (int i = 0; i < rows; i++)
	   {
		   mat[i][column2] += factor*(mat[i][column1]);
	   }
   }
   void divisionofrows(double factor, int rownum)
   {
	   if (factor == 0)
		   return;
	   for (int i = 0; i < columns; i++)
	   {
		   mat[rownum][i] /= factor;
	   }
   }
   void divisionofcolumns(double factor, int colnum)
   {
	   if (factor == 0)
		   return;
	   for (int i = 0; i < rows; i++)
	   {
		   mat[i][colnum] /= factor;
	   }
   }


   Matrix addMatrix(const Matrix& obj)  const
   { 
        if(this->rows == obj.rows && this->columns == obj.columns)
        {
           Matrix result(obj.rows, this->columns);
           for(int c = 0 ; c<this->rows ; c++)
           { 
               for(int c1 = 0; c1 < this->columns; c1++)
               { 
                    result.InputElement(this->mat[c][c1]+obj.mat[c][c1], c+1, c1+1);
               }
           }
           return result;
        }
        else {
        cout<<"\nMatrices cannot be added.\n";
        return (Matrix());
        }
    }

    Matrix subMatrix(const Matrix& obj)  const
   { 
        if(this->rows == obj.rows && this->columns == obj.columns)
        {
           Matrix result(obj.rows, this->columns);
           for(int c = 0 ; c<this->rows ; c++)
           { 
               for(int c1 = 0; c1 < this->columns; c1++)
               { 
                    result.InputElement(this->mat[c][c1]-obj.mat[c][c1], c+1, c1+1);
               }
           }
           return result;
        }
        else {
        cout<<"\nMatrices cannot be added.\n";
        return (Matrix());
        }
    }

    bool isEqual(const Matrix& rhs) const
    {
       if(this->rows == rhs.rows && this->columns == rhs.columns)
       {  
          int e = rhs.rows*this->columns;
          int count = 0;
          for(int c = 0; c < this->rows ; c++)
          {https://www.youtube.com/watch?v=rpMrRYgXAMM
             for(int c1 = 0 ; c1 < rhs.columns ; c1++)
             {
                 this->mat[c][c1]==rhs.mat[c][c1]?count++:0;
             }
          }
          return (count==e);
       }
       else return false;
    }

    void plusEqual(const Matrix& obj)
    {
       if(this->rows == obj.rows && this->columns == obj.columns)
       {
           for(int c = 0 ; c < this->rows ; c++)
           {
               for(int c1 = 0 ; c1 < this->columns ; c1++)
               { 
                 this->mat[c][c1] += obj.mat[c][c1];
               }
           }
       }
       else cout<<"\nERROR IN CALCULATIONS.\n";
    }

    void plusEqualDouble(double obj)
    {
           for(int c = 0 ; c < this->rows ; c++)
           {
               for(int c1 = 0 ; c1 < this->columns ; c1++)
               { 
                 this->mat[c][c1] += obj;
               }
           }
    }

    Matrix Multiplication(const Matrix& rhs) const
    {
        if(this->columns == rhs.rows)
        {
             Matrix result(this->rows, rhs.columns);
             for(int c = 0 ; c < this->rows; c++)
             {
                 for(int c1 = 0; c1 < rhs.columns; c1++)
                 {
                    for(int c2 = 0 ; c2 < this->columns ; c2++)
                    {
                        if(c2==0)
                            result.mat[c][c1]=this->mat[c][c1]* rhs.mat[c][c1];
                        else
                            result.mat[c][c1]+=this->mat[c][c1]* rhs.mat[c][c1];
                    }
                 }
             }          
             return result;
        }
        else
        {
           cout<<"\nERROR. MATRICES CANNOT BE MULTPLIED.\n"; 
           return (Matrix());
        }
    }


   public:

   Matrix(int rows = 1, int columns = 1): rows(rows), columns(columns)
   {
    mat = new double*[rows];
     for(int c = 0; c<this->rows; c++)
     { 
         mat[c] = new double[this->columns];
          for(int c1 = 0 ; c1 < this->columns ; c1++)
          {
             mat[c][c1] = 0;
          }
     }
   }

   ~Matrix()
   {
        for(int c=0;c<this->rows; c++)
        { 
           delete[] (mat[c]);
        }
        delete[] mat;
   }

   Matrix(const Matrix& obj): rows(obj.rows), columns(obj.columns)
   {
        mat = new double *[rows];
        for(int c = 0; c < this->rows; c++)
        {
           mat[c] = new double[this->columns];
           for(int c1 = 0 ; c1 < this->columns; c1++)
           {
               this->mat[c][c1] = obj.mat[c][c1]; 
           }
        }
   }

   void InputElement(double element, int rows, int columns)
   { 
         this->mat[rows-1][columns-1] = element;
   }

   double getElement(int rows, int columns) const
   {
        return (this-> mat[rows][columns]);
   }
   int getRows() const {return (this->rows);}
   int getColumns() const {return (this->columns);}

   void In()
   {
        for(int c = 0; c<this->rows; c++)
        {
            for(int c1 = 0 ; c1 < this->columns;  c1++)
            {
                cout<<"Enter the element ["<<c+1<<"]["<<c1+1<<"] = "; cin>>mat[c][c1];             
            }
        }
   }

   void Out()
   {
         for(int c = 0; c< this->rows; c++)
         {
             for(int c1=0; c1< this->columns; c1++)
             { 
                  cout<<"\t"<<mat[c][c1]; 
             }
             cout<<endl;
         } 
   }


   Matrix operator+ (const Matrix& rhs) const
   {
       return (this->addMatrix(rhs));
   }

   Matrix operator- (const Matrix& rhs) const
   {
      return (this->subMatrix(rhs));
   }

   bool operator== (const Matrix& rhs) const
   {
      return (this->isEqual(rhs));
   }

   void operator+= (const Matrix& rhs) 
   {
      this->plusEqual(rhs);
   }

   void operator+= (double rhs)
   {
       this->plusEqualDouble(rhs);
   }

   Matrix operator* (const Matrix& rhs) const
   {
      return (this->Multiplication(rhs));
   }
   void GaussElimination()
   {
	   int j, i;
	   bool calculation = 0;
	   for (j = 0; j < columns; j++)
	   {
		   for (i = 0; i < rows; i++)
		   {
			   if (mat[i][j] == 0)continue;
			   calculation = 1;
			   divisionofrows(mat[i][j], i);
			   for (int k = i + 1; k < rows; k++)
			   {
				   rowaddition(i, k, -1 * mat[k][j]);
				   mat[k][j] = 0;
			   }
			   swap("row", 1, i + 1);
			   int h = 1;
			   for (j = j + 1; j < columns; j++, h++)
			   {
				   for (i = h; i < rows; i++)
				   {
					   if (mat[i][j] == 0)continue;
					   divisionofrows(mat[i][j], i);
					   for (int k = i + 1; k < rows; k++)
					   {
						   rowaddition(i, k, -1 * mat[k][j]);
						   mat[k][j] = 0;
					   }
					   swap("row", h + 1, i + 1);
				   }
			   }
		   }
	   }

   }
   void Gaussjordan()
   {
	   int j, i;
	   bool calculation = 0;
	   for (j = 0; j < columns; j++)
	   {
		   for (i = 0; i < rows; i++)
		   {
			   if (mat[i][j] == 0)continue;
			   calculation = 1;
			   divisionofrows(mat[i][j], i);
			   for (int k = i+1; k < rows; k++)
			   {
				   rowaddition(i, k, -1*mat[k][j]);
				   mat[k][j] = 0;
			   }
			   swap("row", 1, i + 1);
			   int h = 1;
			   for ( j = j + 1; j < columns; j++, h++)
			   {
				   for ( i = h; i < rows; i++)
				   {
					   if (mat[i][j] == 0)continue;
					   divisionofrows(mat[i][j], i);
					   for (int k = 0; k < rows; k++)
					   {
						   if (k == i)continue;
						   rowaddition(i, k, -1 * mat[k][j]);
						   mat[k][j] = 0;
					   }
					   swap("row", h + 1, i + 1);
				   }
			   }
			   return;
		   }
	   }
	   
   }
};
