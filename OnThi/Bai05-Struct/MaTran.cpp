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
		Matrix mulMT;
		if (this->col != mt2.row)
		{
			mulMT.row = -1;
			mulMT.col = -1;
			return mulMT;
		}
		mulMT.row = this->row;
		mulMT.col = mt2.col;
		mulMT.mt = new int *[mulMT.row];
		for (int i = 0; i < mulMT.row; i++)
			mulMT.mt[i] = new int[mulMT.col];

		for (int i = 0; i < mulMT.row; i++)
		{
			for (int j = 0; j < mulMT.col; j++)
			{
				for (int k = 0; k < this->col; k++)
					mulMT.mt[i][j] += this->mt[i][k] + mt2.mt[k][j];
			}
		}
		return mulMT;
	}

	Matrix sumMatrix(const Matrix mt2)
	{
		// a[n][m] + b[n][m] =  c[n][m]
		Matrix sumMT;
		if (this->row != mt2.row || this->col != mt2.col)
		{
			sumMT.row = -1;
			sumMT.col = -1;
			return sumMT;
		}
		sumMT.row = this->row;
		sumMT.col = this->col;
		sumMT.mt = new int *[sumMT.row];
		for (int i = 0; i < sumMT.row; i++)
			sumMT.mt[i] = new int[sumMT.col];

		for (int i = 0; i < sumMT.row; i++)
		{
			for (int j = 0; j < sumMT.col; j++)
				sumMT.mt[i][j] = this->mt[i][j] + mt2.mt[i][j];
		}
		return sumMT;
	}
};

int main()
{
	Matrix mt1, mt2, mulMT, sumMT;
	mt1.initMatrix();
	cout << "Matrix 1:\n";
	mt1.print();

	mt2.initMatrix();
	cout << "Matrix 2:\n";
	mt2.print();

	mulMT = mt1.mulMatrix(mt2);
	if (mulMT.getRow() == -1 || mulMT.getCol() == -1)
		cout << "Can't multiply two matrix with different size!\n";
	else
	{
		cout << "Multiply matrix:\n";
		mulMT.print();
		mulMT.freeMt();
	}

	sumMT = mt1.sumMatrix(mt2);
	if (sumMT.getRow() == -1 || sumMT.getCol() == -1)
		cout << "Can't multiply two matrix with different size!\n";
	else
	{
		cout << "Sum matrix:\n";
		sumMT.print();
		sumMT.freeMt();
	}

	mt1.freeMt();
	mt2.freeMt();
	return 0;
}