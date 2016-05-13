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
		if (row1 > rows || row1 <= 0 || row2 > rows || row2 <= 0)
		{
			cout << "Sorry ,swap not possible" << endl;
			return;
		}
		int column = this->columns;
		double temp;
		for (int i = 0; i < column; i++)
		{
			temp = mat[row1-1][i];
			mat[row1 - 1][i] = mat[row2 - 1][i];
			mat[row2 - 1][i] = temp;
		}
	}
	void rowaddition(int row1, int row2, double factor)
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
		if (this->rows == obj.rows && this->columns == obj.columns)
		{
			Matrix result(obj.rows, this->columns);
			for (int c = 0; c < this->rows; c++)
			{
				for (int c1 = 0; c1 < this->columns; c1++)
				{
					result.InputElement(this->mat[c][c1] + obj.mat[c][c1], c + 1, c1 + 1);
				}
			}
			return result;
		}
		else {
			cout << "\nMatrices cannot be added.\n";
			return (Matrix());
		}
	}
	Matrix Minimatrixgetter(const Matrix& m,int r1,int r2,int c1,int c2)
	{
		if (r1 >= 0 && r1 < m.rows&& r2 >= 0 && r2 < m.rows&& c1 >= 0 && c1 < m.rows&& c2 >= 0 && c2 < m.rows)
		{
			int ro_w = r2 - r1;
			int co_l = c2 - c1;
			Matrix temp(r2 - r1, c2 - c1);
			for (int i = r1 - 1; i < r2 - 1; i++)
			{
				for (int j = c1 - 1; j < r2 - 1; j++)
				{
					temp.mat[i - r1 + 1][j - c1 + 1] = m.mat[i][j];
				}
			}
			return temp;
		}
		else return NULL;
		//   RRRRR
	}
	Matrix Matrixbuilder(const Matrix& m1, const Matrix& m2, const Matrix& m3, const Matrix& m4)
	{
		int r = m1.rows;
		int c = m1.columns;
		Matrix temp(2 * r, 2 * c);
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				temp.mat[i][j] = m1.mat[i][j];
			}
		}
		for (int i = r; i < 2 * r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				temp.mat[i][j] = m2.mat[i-r][j];
			}
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = c; j < 2 * c; j++)
			{
				temp.mat[i][j] = m3.mat[i][j - c];
			}
		}
		for (int i = r; i < 2 * r; i++)
		{
			for (int j = c; j < 2 * c; j++)
			{
				temp.mat[i][j] = m4.mat[i - r][j - c];
			}
		}
		return temp;
	}
	Matrix Matrixbuilder(const Matrix& m1, const Matrix& m2)
	{
		int r = m1.rows;
		int c = m1.columns;
		this->resize(r, 2 * c);
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				mat[i][j] = m1.mat[i][j];
			}
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = c; j < 2*c; j++)
			{
				mat[i][j] = m2.mat[i][j-c];
			}
		}
		return (*this);
	}
	Matrix subMatrix(const Matrix& obj)  const
	{
		if (this->rows == obj.rows && this->columns == obj.columns)
		{
			Matrix result(obj.rows, this->columns);
			for (int c = 0; c < this->rows; c++)
			{
				for (int c1 = 0; c1 < this->columns; c1++)
				{
					result.InputElement(this->mat[c][c1] - obj.mat[c][c1], c + 1, c1 + 1);
				}
			}
			return result;
		}
		else {
			cout << "\nMatrices cannot be added.\n";
			return (Matrix());
		}
	}

	bool isEqual(const Matrix& rhs) const
	{
		if (this->rows == rhs.rows && this->columns == rhs.columns)
		{
			int e = rhs.rows*this->columns;
			int count = 0;
			for (int c = 0; c < this->rows; c++)
			{
				//https://www.youtube.com/watch?v=rpMrRYgXAMM
				for (int c1 = 0; c1 < rhs.columns; c1++)
				{
					this->mat[c][c1] == rhs.mat[c][c1] ? count++ : 0;
				}
			}
			return (count == e);
		}
		else return false;
	}

	void plusEqual(const Matrix& obj)
	{
		if (this->rows == obj.rows && this->columns == obj.columns)
		{
			for (int c = 0; c < this->rows; c++)
			{
				for (int c1 = 0; c1 < this->columns; c1++)
				{
					this->mat[c][c1] += obj.mat[c][c1];
				}
			}
		}
		else cout << "\nERROR IN CALCULATIONS.\n";
	}

	void plusEqualDouble(double obj)
	{
		for (int c = 0; c < this->rows; c++)
		{
			for (int c1 = 0; c1 < this->columns; c1++)
			{
				this->mat[c][c1] += obj;
			}
		}
	}

	Matrix Multiplication(const Matrix& rhs) const
	{
		if (this->columns == rhs.rows)
		{
			Matrix result(this->rows, rhs.columns);
			for (int c = 0; c < this->rows; c++)
			{
				for (int c1 = 0; c1 < rhs.columns; c1++)
				{
					for (int c2 = 0; c2 < this->columns; c2++)
					{
							result.mat[c][c1] += this->mat[c][c1] * rhs.mat[c][c1];
					}
				}
			}
			return result;
		}
		else
		{
			cout << "\nERROR. MATRICES CANNOT BE MULTPLIED.\n";
			return (Matrix());
		}
	}


public:

	Matrix(int rows = 1, int columns = 1) : rows(rows), columns(columns)
	{
		mat = new double*[rows];
		for (int c = 0; c < this->rows; c++)
		{
			mat[c] = new double[this->columns];
			for (int c1 = 0; c1 < this->columns; c1++)
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
		for (int c = 0; c < this->rows; c++)
		{
			delete[](mat[c]);
		}
		delete[] mat;
	}

	Matrix(const Matrix& obj) : rows(obj.rows), columns(obj.columns)
	{
		mat = new double *[rows];
		for (int c = 0; c < this->rows; c++)
		{
			mat[c] = new double[this->columns];
			for (int c1 = 0; c1 < this->columns; c1++)
			{
				this->mat[c][c1] = obj.mat[c][c1];
			}
		}
	}

	void InputElement(double element, int rows, int columns)
	{
		if (rows<0||rows>=this->rows||columns<0||columns>=columns)
		{
			cout << "Sorry ,out of range" << endl;
			return;
		}
		this->mat[rows - 1][columns - 1] = element;
	}

	double getElement(int rows, int columns) const
	{
		return (this->mat[rows][columns]);
	}
	int getRows() const { return (this->rows); }
	int getColumns() const { return (this->columns); }

	void In()
	{
		for (int c = 0; c < this->rows; c++)
		{
			for (int c1 = 0; c1 < this->columns; c1++)
			{
				cout << "Enter the element [" << c + 1 << "][" << c1 + 1 << "] = "; cin >> mat[c][c1];
			}
		}
	}

	void Out()
	{
		for (int c = 0; c < this->rows; c++)
		{
			for (int c1 = 0; c1 < this->columns; c1++)
			{
				cout << "\t" << mat[c][c1];
			}
			cout << endl;
		}
	}

	Matrix operator= (const Matrix& rhs) 
	{
		if (this->rows != rhs.rows || this->columns != rhs.columns)
		{
			cout << "The matrices cannot be equalized as they have different order" << endl;
			return *this;
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				mat[i][j] = rhs.mat[i][j];
			}
		}
		return *this;
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
				swap(1, i+1);
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
						swap(h+1, i+1);
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
				for (int k = i + 1; k < rows; k++)
				{
					rowaddition(i, k, -1 * mat[k][j]);
					mat[k][j] = 0;
				}
				swap(1, i+1);
				int h = 1;
				for (j = j + 1; j < columns; j++, h++)
				{
					for (i = h; i < rows; i++)
					{
						if (mat[i][j] == 0)continue;
						divisionofrows(mat[i][j], i);
						for (int k = 0; k < rows; k++)
						{
							if (k == i)continue;
							rowaddition(i, k, -1 * mat[k][j]);
							mat[k][j] = 0;
						}
						swap(h+1, i+1);
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
				m.mat[i][j] = b;
			}
		}
		for (int i = 0; i < variables; i++)
		{
			cout << "Please enter the values of equations " << i + 1 << endl;
			cin >> b;
			m.mat[i][variables] = b;
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
		Matrix temp(rows, rows);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				temp.mat[i][j] = mat[i][j];
			}
		}
		static double multiplier = 1;
		if (rows == 2)
		{
			multiplier = 1;
			return (mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1]);
		}
		bool valuerow = 0;
		for (int i = 0; i < rows; i++)
		{
			if (temp.mat[i][0] == 0)continue;
			valuerow = 1;
			multiplier *= temp.mat[i][0];
			temp.divisionofrows(temp.mat[i][0], i);
			for (int k = i + 1; k < rows; k++)
			{
				temp.rowaddition(i, k, -1 * temp.mat[k][0]);
			}
			if (i != 0)
			{
				temp.swap(i+1, 1);
				multiplier *= -1;
			}
			if (rows == 3)
			{
				double tmp = multiplier;
				multiplier = 1;
				return (tmp*(temp.mat[rows - 2][rows - 2] * temp.mat[rows - 1][rows - 1] - temp.mat[rows - 1][rows - 2] * temp.mat[rows - 2][rows - 1]));
			}
			Matrix m(rows - 1,rows - 1);
			for (int c = 0; c < rows - 1; c++)
			{
				for (int c1 = 0; c1 < rows - 1; c1++)
				{
					m.mat[c][c1] = temp.mat[c + 1][c1 + 1];
				}
			}
			m.determinant();
		}
		if (valuerow == 0)return 0;
	}
	void eigenvalues()
	{
		if (rows == 2)
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
	void resize(int newrow, int newcolumn)
	{
		for (int i = 0; i < this->rows; i++)
		{
			delete[](mat[i]);
		}
		delete[] mat;
		rows = newrow;
		columns = newcolumn;
		mat = new double*[rows];
		for (int i = 0; i < this->rows; i++)
		{
			mat[i] = new double[this->columns];
			for (int j = 0; j < this->columns; j++)
			{
				mat[i][j] = 0;
			}
		}
	}
	static void xrotation(double x, double y, double z, double angle)
	{
		Matrix v(3, 1);
		v.mat[0][0] = x;
		v.mat[1][0] = y*cos(angle/57.3) - z*sin(angle/57.3);
		v.mat[2][0] = y*sin(angle/57.3)+z*cos(angle/57.3);
		v.Out();
	}
	static void yrotation(double x, double y, double z, double angle)
	{
		Matrix v(3, 1);
		v.mat[0][0] = x*cos(angle/57.3) - z*sin(angle/57.3);
		v.mat[1][0] = y;
		v.mat[2][0] = x*sin(angle/57.3) + z*cos(angle/57.3);
		v.Out();
	}
	static void zrotation(double x, double y, double z, double angle)
	{
		Matrix v(3, 1);
		v.mat[0][0] = x*cos(angle/57.3) - y*sin(angle/57.3);
		v.mat[1][0] = x*sin(angle/57.3) + y*cos(angle/57.3);
		v.mat[2][0] = z;
		v.Out();
	}
	double dotproduct(Matrix&m1, Matrix& m2) const
	{
		if (m1.rows != m2.rows || m1.columns != 1 || m2.columns != 1)
		{
			cout << "Dot Product not possible" << endl;
			return NULL;
		}
		double dotp=0;
		for (int i = 0; i < m1.rows; i++)
		{
			dotp += m1.mat[i][0] * m2.mat[i][0];
		}
		return dotp;
	}
	Matrix crossproduct(Matrix& m1, Matrix& m2) const
	{
		if (m1.rows != m2.rows || m1.columns != 1 || m2.columns != 1 || m1.rows !=3)
		{
			return NULL;
		}
		Matrix m(m1.rows, 1);
		m.mat[0][0] = m1.mat[1][0] * m2.mat[2][0] - m1.mat[2][0] * m2.mat[1][0];
		m.mat[1][0] = m1.mat[0][0] * m2.mat[2][0] - m1.mat[2][0] * m2.mat[0][0];
		m.mat[2][0] = m1.mat[0][0] * m2.mat[1][0] - m1.mat[1][0] * m2.mat[0][0];
		return m;
	}
	Matrix crossproduct(double vector1x, double vector1y, double vector1z, double vector2x, double vector2y, double vector2z)
	{
		Matrix m(3, 1);
		m.mat[0][0] = vector1y*vector2z - vector1z*vector2y;
		m.mat[1][0] = vector1x*vector2z - vector1z*vector2x;
		m.mat[2][0] = vector1x*vector2y - vector2x*vector1y;
		return m;
	}
	void magic(int x)
	{
		if (x % 2== 1)
		{
			bool donefor = false;
			int r = 0;
			int c = (x - 1) / 2;
			this->resize(x, x);
			mat[r][c] = 1;
			for (int i = 2; i <= x*x; i++)
			{
				while (donefor == 0)
				{
					r--;
					c++;
					if (r < 0) { r += x; }
					else if (r >= x)r -= x;
					if (c >= x) c -= x;
					else if (c < 0) c += x;
					if (mat[r][c] != 0)
					{
						r+=2;
						c--;
					}
					if (r < 0) { r += x; }
					else if (r >= x)r -= x;
					if (c >= x) c -= x;
					else if (c < 0) c += x;
					if (mat[r][c] == 0)donefor = true;
				}
				mat[r][c] = i;
				donefor = 0;
			}
		}
		else if (x % 4 == 0)
		{
			int k = 1;
			this->resize(x, x);
			Matrix x1(x, x), x2(x, x);
			for (int i = 0; i < x ; i++)
			{
				for (int j = 0; j < x; j++,k++)
				{
					x1.mat[j][i] = k;
				}
			}
			k = x*x;
			for (int i = 0; i < x; i++)
			{
				for (int j = 0; j < x; j++)
				{
					x2.mat[i][j] = k;
					k--;
				}
			}
			for (int i = 0; i < x; i++)
			{
				for (int j = 0; j < x; j++)
				{
					if (i == j)mat[i][j] = 1;
					else if (i == -j)mat[i][j] = 1;
				}
			}
			for (int i = 0; i < x; i++)
			{
				for (int j = 0; j < x; j++)
				{
					if (mat[i][j] == 1)mat[i][j] = x1.mat[i][j];
					else mat[i][j] = x2.mat[i][j];
				}
			}
		}
		else
		{
			this->resize(x, x);
			if (x == 2)
			{
				cout << "Magic Matrix does not exist" << endl;
				return;
			}
			int r = x / 2;
			Matrix m1(r, r);
			Matrix m2(r, r), m3(r, r), m4(r, r);
			m1.magic(r);
			Matrix i1(r, r);
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < r; j++)
				{
					i1.mat[i][j] = r*r;
				}
			}
			m2 = m1 + i1;
			m3 = m1 + i1 + i1;
			m4 = m1 + i1 + i1 + i1;
			*this=Matrixbuilder(m1, m4, m3, m2);
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < (r + 1) / 2; j++)
				{
					if (i == (r - 1) / 2 && j == 0)
					{
						continue;
					}
					else if (i != (r - 1) / 2 && j == (r - 1) / 2)
					{
						continue;
					}
					else
					{
						numberswap(mat[i][j], mat[r+i][j]);
					}
				}
				for (int j = 2 * r  - (r - 3) / 2; j < 2 * r ; j++)
				{
					numberswap(mat[i][j], mat[i + r][j]);
				}
			}
		}
}
	void numberswap(double& x, double& y)
	{
		double temp = x;
		x = y;
		y = temp;
		return;
	}
	Matrix getInverse()
	{
		double det = determinant();
		if (det == 0)
		{
			cout << "Inverse not possible" << endl;
			return (*this);
		}
		Matrix temp1(rows, rows), temp2("identity",rows, rows);
		Matrix Big;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				temp1.mat[i][j] = mat[i][j];
			}
		}
		Big.Matrixbuilder(temp1, temp2);
		Big.Gaussjordan();
		for (int i = 0; i < rows; i++)
		{
			for (int j = rows; j < 2*rows; j++)
			{
				temp1.mat[i][j-rows] = Big.mat[i][j];
			}
		}
		return temp1;
	}
};
//class Complex
//{
//private:
//	double real;
//	double imag;
//public:
//	Complex() :real(0), imag(0)
//	{
//
//	}
//	Complex(double real, double imagin = 0) :real(real), imag(imagin)
//	{
//
//	}
//	Complex(const Complex& c)
//	{
//		this->real = c.real;
//		this->imag = c.imag;
//	}
//	Complex operator+(Complex& c)
//	{
//		Complex temp;
//		temp.real = this->real + c.real;
//		temp.imag = this->imag + c.imag;
//		return temp;
//	}
//	Complex operator=(Complex& c)
//	{
//		this->real = c.real;
//		this->imag = c.imag;
//		return (*this);
//	}
//	Complex operator-(Complex& c)
//	{
//		Complex temp;
//		temp.real = this->real - c.real;
//		temp.imag = this->imag - c.imag;
//		return temp;
//	}
//	Complex operator+=(Complex& c)
//	{
//		this->real += c.real;
//		this->imag += c.imag;
//		return (*this);
//	}
//	Complex operator-=(Complex& c)
//	{
//		this->real -= c.real;
//		this->imag -= c.imag;
//		return (*this);
//	}
//	Complex operator*(Complex& c)
//	{
//		Complex temp;
//		temp.real = this->real*c.real - this->imag*c.imag;
//		temp.imag = this->real*c.imag + this->imag*c.real;
//		return temp;
//	}
//	Complex operator*=(Complex& c)
//	{
//		Complex temp;
//		temp = (*this);
//		this->real = temp.real*c.real - temp.imag*c.imag;
//		this->imag = temp.real*c.imag + temp.imag*c.real;
//		return (*this);
//	}
//	double magnitude()
//	{
//		return (sqrt(real*real + imag*imag));
//	}
//	Complex operator/(Complex& c)
//	{
//		Complex temp,tempc=c;
//		tempc.imag *= -1;
//		temp.real = tempc.real / (tempc.magnitude()*tempc.magnitude());
//		temp.imag = tempc.imag / (tempc.magnitude()*tempc.magnitude());
//		tempc = (*this)*(temp);
//		return tempc;
//	}
//	Complex operator/=(Complex& c)
//	{
//		Complex temp, tempc = c;
//		tempc.imag *= -1;
//		temp.real = tempc.real / (tempc.magnitude()*tempc.magnitude());
//		temp.imag = tempc.imag / (tempc.magnitude()*tempc.magnitude());
//		tempc = (*this)*(temp);
//		(*this) = tempc;
//		return (*this);
//	}
//	Complex operator*(double i)
//	{
//		Complex temp = (*this);
//		temp.real *= i;
//		temp.imag *= i;
//		return temp;
//	}
//	Complex operator/(double i)
//	{
//		if (i == 0)
//		{
//			cout << "Division by zero not possible" << endl;
//			return (*this);
//		}
//		Complex temp = (*this);
//		temp.real /= i;
//		temp.imag /= i;
//		return temp;
//	}
//	bool operator==(double i)
//	{
//		return (i == this->magnitude());
//	}
//	friend ostream& operator << (ostream& print, Complex& c);
//	friend istream& operator >> (istream& input, Complex& c);
//	friend Complex operator*(double i, Complex& c);
//	friend Complex operator*=(double i, Complex& c);
//	friend Complex operator/=(double i, Complex& c);
//	friend bool operator==(double i, Complex& c);
//};
//ostream& operator << (ostream& print, Complex& c)
//{
//	if (c.imag == 0)
//	{
//		print << c.real;
//		return print;
//	}
//	else if (c.imag > 0)
//	{
//		print << c.real << "+" << c.imag;
//		return print;
//	}
//	else
//	{
//		print << c.real << "-" << c.imag;
//		return print;
//	}
//}
//istream& operator >> (istream& input, Complex& c)
//{
//	cout << "Enter the real component: ";
//	input >> c.real;
//	cout << "Enter the imaginary component: ";
//	input >> c.imag;
//	return input;
//}
//class cMatrix
//{
//private:
//	int rows;
//	int columns;
//	Complex**mat;
//	void swap(int row1, int row2)
//	{
//		if (row1 > rows || row1 < 0 || row2 > rows || row2 < 0)
//		{
//			cout << "Sorry ,swap not possible" << endl;
//			return;
//		}
//		int column = this->columns;
//		Complex * temp = new Complex;
//		for (int i = 0; i < column; i++)
//		{
//			*temp = mat[row1 - 1][i];
//			mat[row1 - 1][i] = mat[row2 - 1][i];
//			mat[row2 - 1][i] = *temp;
//		}
//		delete temp;
//	}
//	void rowaddition(int row1, int row2, Complex factor)
//	{
//		for (int i = 0; i < columns; i++)
//		{
//			mat[row2][i] += factor*(mat[row1][i]);
//		}
//	}
//	void columnaddition(int column1, int column2, Complex factor)
//	{
//		for (int i = 0; i < rows; i++)
//		{
//			mat[i][column2] += factor*(mat[i][column1]);
//		}
//	}
//	void divisionofrows(Complex factor, int rownum)
//	{
//		if (factor == 0)
//			return;
//		for (int i = 0; i < columns; i++)
//		{
//			mat[rownum][i] /= factor;
//		}
//	}
//	void divisionofcolumns(Complex factor, int colnum)
//	{
//		if (factor == 0)
//			return;
//		for (int i = 0; i < rows; i++)
//		{
//			mat[i][colnum] /= factor;
//		}
//	}
//	int getRows()
//	{
//		return rows;
//	}
//	int getColumns()
//	{
//		return columns;
//	}
//	Complex getElement(int row, int column)
//	{
//		if (row > 0 && row <= rows&&column>0&&column<=columns)
//		return mat[row - 1][column - 1];
//		else
//		{
//			cout << "Element does not exist" << endl;
//			return NULL;
//		}
//	}
//	void InputElement(int row, int column)
//	{
//		if (row > 0 && row <= rows&&column > 0 && column <= columns)
//			cin >> mat[row - 1][column - 1];
//		else
//		{
//			cout << "Element does not exist" << endl;
//			return;
//		}
//	}
//};
