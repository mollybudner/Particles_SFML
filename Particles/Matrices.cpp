
#include "Matrices.h"
#include <cmath>
namespace Matrices
{
	Matrix::Matrix(int _rows, int _cols)
	{
		//assign member variables
		rows = _rows;
		cols = _cols;
		//resize vector
		/*a.resize(rows);
		for(size_t i = 0; i < rows; i++)
		{
			a[i].resize(cols);
			//initialize all cells to 0
			for(size_t j = 0; j < cols; j++)
			{
				a[i][j] = 0;
			}
		}*/
		//vector<vector<double>> a(rows,vector<double>(cols, 0);
		a.resize(rows, vector<double>(cols,0));
	}

	Matrix operator+(const Matrix& a, const Matrix& b)
	{
		if(a.getRows() != b.getRows() || a.getCols() != b.getCols())
		{
			//returns to caller
			throw runtime_error("Error: dimensions must agree");
		}

		Matrix c(a.getRows(), a.getCols());
		for(int i = 0; i < a.getRows(); i++)
		{
			for(int j = 0; j < a.getCols(); j++)
			{
				c(i,j) = a(i,j) + b(i,j);
			}
		}
		return c;
	}

	Matrix operator*(const Matrix& a, const Matrix& b)
	{
		if(a.getCols() != b.getRows())
		{
			//returns to caller
			throw runtime_error("Error: dimensions must agree");
		}

		Matrix c(a.getRows(), b.getCols()); //cells initialize to 0

		for(int i = 0; i < a.getRows(); i++)
		{
			for(int k = 0; k < b.getCols(); k++)
			{
				for(int j = 0; j < a.getCols(); j++)
				{
					c(i,k) += a(i,j) * b(j,k);
				}
			}
		}
		return c;
	}

	bool operator==(const Matrix& a, const Matrix& b)
	{
		if(a.getRows() != b.getRows() || a.getCols() != b.getCols())
		{
			return false;
		}
		for(int i = 0; i < a.getRows(); i++)
		{
			for(int j = 0; i < b.getCols(); j++)
			{
				if(fabs(a(i,j) - b(i,j)) < 0.001)
				{
					return true;
				}
			}
		}
		return false;
	}

	bool operator!=(const Matrix& a, const Matrix& b)
	{
		return !(a == b);
	}

	ostream& operator<<(ostream& os, const Matrix& a)
	{
		for(int i = 0; i < a.getRows(); i++)
		{
			for(int j = 0; j < a.getCols(); j++)
			{
				os << setw(8) << a(i,j) << " ";
			}
			os << endl;
		}
		return os;
	}
}

