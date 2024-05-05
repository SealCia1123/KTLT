#include <iostream>
using namespace std;

const int MAX_VAL = 49;
const int MIN_VAL = 10;

class Matrix
{
  private:
	int row, col;
	int **mt;

  public:
	int getRow()
	{
		return this->row;
	}

	int getCol()
	{
		return this->row;
	}

	void setRow(int row)
	{
		this->row = row;
	}

	void setCol(int col)
	{
		this->col = col;
	}

	void initMatrix()
	{
		int r, c;
		cout << "Input numbers of row and col: ";
		cin >> r >> c;
		setRow(r);
		setCol(c);
		mt = new int *[this->row];
		for (int i = 0; i < this->row; i++)
			mt[i] = new int[this->col];
		for (int i = 0; i < this->row; i++)
		{
			for (int j = 0; j < this->col; j++)
				mt[i][j] = rand() % (MAX_VAL - MIN_VAL + 1) + MIN_VAL;
		}
	}

	void print()
	{
		for (int i = 0; i < this->row; i++)
		{
			for (int j = 0; j < this->col; j++)
				cout << this->mt[i][j] << "\t";
			cout << endl;
		}
	}

	void freeMt()
	{
		for (int i = 0; i < this->row; i++)
			delete[] this->mt[i];
		delete[] this->mt;
	}

	Matrix mulMatrix(const Matrix mt2)
	{
		// a[n][m] x b[p][q] = c[n][q]
		Matrix mt3;
		if (this->col != mt2.row)
		{
			mt3.row = -1;
			mt3.col = -1;
			return mt3;
		}
		mt3.row = this->row;
		mt3.col = mt2.col;
		mt3.mt = new int *[mt3.row];
		for (int i = 0; i < mt3.row; i++)
			mt3.mt[i] = new int[mt3.col];

		for (int i = 0; i < mt3.row; i++)
		{
			for (int j = 0; j < mt3.col; j++)
			{
				for (int k = 0; k < this->col; k++)
					mt3.mt[i][j] += this->mt[i][k] + mt2.mt[k][j];
			}
		}
		return mt3;
	}
};

int main()
{
	Matrix mt1, mt2, mt3;
	mt1.initMatrix();
	cout << "Matrix 1:\n";
	mt1.print();

	mt2.initMatrix();
	cout << "Matrix 2:\n";
	mt2.print();

	mt3 = mt1.mulMatrix(mt2);
	cout << "Matrix multiply:\n";
	mt3.print();

	mt1.freeMt();
	mt2.freeMt();
	mt3.freeMt();
	return 0;
}
