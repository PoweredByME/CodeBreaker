#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

class Matrix
{
   private:
   double **mat;
   int rows, columns;
   void swap(int row1, int row2)
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
          {
		  //https://www.youtube.com/watch?v=rpMrRYgXAMM
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
   Matrix(string random, int rows, int columns) : rows(rows), columns(columns)
   {
	   if (random == "random")
	   {
		   mat = new double*[rows];
		   for (int i = 0; i < this->rows; i++)
		   {
			   mat[i] = new double[this->columns];
			   for (int j = 0; j < this->columns; j++)
			   {
				   mat[i][j] = rand();
			   }
		   }
	   }
	   else if (random == "identity")
	   {
		   if (rows != columns)
		   {
			   cout << "Identity Matrix is only a square one" << endl;
			   cout << "Making a pseudoidentity matrix" << endl;
		   }
		   mat = new double *[rows];
		   for (int i = 0; i < this->rows; i++)
		   {
			   mat[i] = new double[this->columns];
			   for (int j = 0; j < this->columns; j++)
			   {
				   if (i == j)
					   mat[i][j] = 1;
				   else mat[i][j] = 0;
			   }
		   }
	   }
   }
   void randomize()
   {
	   for (int i = 0; i < this->rows; i++)
	   {
		   for (int j = 0; j < this->columns; j++)
		   {
			   mat[i][j] = rand();
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
			   swap(1, i + 1);
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
					   swap(h + 1, i + 1);
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
			   swap(1, i + 1);
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
					   swap(h + 1, i + 1);
				   }
			   }
			   return;
		   }
	   }
	   
   }
   void equationsolver()
   {
	   int variables;
	   cout << "Enter the number of variables: ";
	   cin >> variables;
	   Matrix m(variables, variables + 1);
	   double b;
	   for (int i = 0; i < variables; i++)
	   {
		   for (int j = 0; j < variables; j++)
		   {
			   cout << "Please enter a" << i << " for equation " << j << endl;
			   cin >> b;
			   m.mat[i][j]=b;
		   }
	   }
	   for (int i = 0; i < variables; i++)
	   {
		   cout << "Please enter the values of equations " << i + 1 << endl;
		   cin >> b;
		   m.mat[i][variables]=b;
	   }
	   m.Gaussjordan();
	   bool clear = 0;
	   for (int j = 0; j < variables; j++)
	   {
		   for (int i = 0; i < variables; i++)
		   {
			   if (m.mat[i][j] == 1)
			   {
				   clear = 1;
				   i = variables;
			   }
		   }
		   if (clear == 0)
		   {
			   cout << "The equation cannot be solved" << endl;
			   return;
		   }
	   }
	   for (int i = 0; i < variables; i++)
	   {
		   cout << "Variable number " << i << " is " << m.getElement(i, variables) << endl;
	   }
   }
   void quadraticsolver()
   {
	   double a, b, c, i;
	   cout << "Enter the coefficient of x^2: ";
	   cin >> a;
	   cout << "Enter the coefficient of x: ";
	   cin >> b;
	   cout << "Enter the coefficient of 1: ";
	   cin >> c;
	   i = b*b - 4 * a*c;
	   if (i == 0)
	   {
		   cout << "The roots are identical and have value: " << -0.5*b / a << endl;
	   }
	   else if (i > 0)
	   {
		   cout << "The roots are " << (-0.5*b + 0.5*sqrt(i)) / a << " and " << (-0.5*b - 0.5*sqrt(i)) / a << endl;
	   }
	   else
	   {
		   cout << "The roots are imaginary" << endl;
		   cout << "They are " << (-0.5*b) / a << " + " << 0.5*sqrt(-i) / a << "i and " << -0.5*b / a << " - " << 0.5*sqrt(-i) / a << "i" << endl;
	   }
   }
   double determinant()
   {
	   if (rows != columns)
	   {
		   cout << "Determinant can only be taken for square matrices" << endl;
		   cout << "Returning zero" << endl;
		   return 0;
	   }
	   double multiplier = 1;
	   bool valuerow = 0;
		   for (int i = 0; i < rows; i++)
		   {
			   if (mat[i][0] == 0)continue;
			   valuerow = 1;
			   multiplier *= mat[i][0];
			   divisionofrows(mat[i][0], i);
			   for (int j = i + 1; j < rows; j++)
			   {
				   rowaddition(i, j, -1 * mat[j][0]);
			   }
			   if (i != 0)
			   {
				   swap(i, 0);
				   multiplier *= -1;
			   }
			   if (rows == 3)
			   {
				   return (multiplier*(mat[rows - 2][rows - 2] * mat[rows - 1][rows - 1] - mat[rows - 1][rows - 2] * mat[rows - 2][rows - 1]));
			   }
			   Matrix m(rows-1,rows-1);
			   for (int c = 0; c < rows-1; c++)
			   {
				   for (int c1 = 0; c1 < rows-1; c1++)
				   {
					   m.mat[c][c1] = mat[c + 1][c1 + 1];
				   }
			   }
			   m.determinant();
		   }
		   if (valuerow == 0)return 0;
   }
   void eigenvalues()
   {
	   if (rows == 2 )
	   {
		   double b, c;
		   b = -(mat[0][0] + mat[1][1]);
		   c = this->determinant();
		   if (b*b > 4 * c)
			   cout << "The Eigenvalues are " << (-b + sqrt(b*b - 4 * c)) / 2 << " and " << (-b + sqrt(b*b - 4 * c)) / 2 << endl;
		   else if (b*b == 4 * c)
			   cout << "The (identical) Eigenvalues are " << -b / 2 << endl;
		   else cout << "The imaginary Eigenvalues " << -b / 2 << " + " << 0.5*sqrt(4 * c - b*b) << "i" << endl << -b / 2 << " - " << 0.5*sqrt(4 * c - b*b) << "i" << endl;
	   }

   }
};
