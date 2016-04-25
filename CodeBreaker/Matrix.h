using namespace std;

class Matrix
{
   private:
   double **mat;
   int rows, columns;

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


};




