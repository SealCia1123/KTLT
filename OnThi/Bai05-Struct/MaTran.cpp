#include <iostream>
using namespace std;

const int MAX_VAL = 49;
const int MIN_VAL = 10;

class Matrix
{
  private:
	int row, col;
	int **mt;
	bool valid = 1;

  public:
	int getRow()
	{
		return this->row;
	}

	int getCol()
	{
		return this->row;
	}

	bool getValid()
	{
		return this->valid;
	}

	void setRow(int row)
	{
		this->row = row;
	}

	void setCol(int col)
	{
		this->col = col;
	}

	void setValid(bool valid)
	{
		this->valid = valid;
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

	Matrix mulMatrix(const Matrix mt1, const Matrix mt2)
	{
		// a[n][m] x b[q][p] = c[n][p]
		if (mt1.col != mt2.row)
		{
			this->valid = 0;
			return *this;
		}
		this->row = mt1.row;
		this->col = mt2.col;
		this->mt = new int *[this->row];
		for (int i = 0; i < this->row; i++)
			this->mt[i] = new int[this->col];

		for (int i = 0; i < this->row; i++)
		{
			for (int j = 0; j < this->col; j++)
			{
				for (int k = 0; k < mt1.col; k++)
					this->mt[i][j] += mt1.mt[i][k] * mt2.mt[k][j];
			}
		}
		return *this;
	}

	Matrix sumMatrix(const Matrix mt1, const Matrix mt2)
	{
		// a[n][m] + b[n][m] =  c[n][m]
		if (mt1.row != mt2.row || mt1.col != mt2.col)
		{
			this->valid = 0;
			return *this;
		}
		this->row = mt1.row;
		this->col = mt1.col;
		this->mt = new int *[this->row];
		for (int i = 0; i < this->row; i++)
			this->mt[i] = new int[this->col];

		for (int i = 0; i < this->row; i++)
		{
			for (int j = 0; j < this->col; j++)
				this->mt[i][j] = mt1.mt[i][j] + mt2.mt[i][j];
		}
		return *this;
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

	mulMT = mulMT.mulMatrix(mt1, mt2);

	if (!mulMT.getValid())
		cout << "Can't multiply two matrix with different size!\n";
	else
	{
		cout << "Multiply matrix:\n";
		mulMT.print();
		mulMT.freeMt();
	}

	sumMT = sumMT.sumMatrix(mt1, mt2);
	if (!sumMT.getValid())
		cout << "Can't sum two matrix with different size!\n";
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
