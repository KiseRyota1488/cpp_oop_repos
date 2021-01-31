#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class TryCatch
{
private:
	int size;
	int* arr;

public:
	TryCatch()
	{
		cout << "Enter size: ";
		cin >> size;
		arr = new int[size];
		system("cls");

	}


	void Fill()
	{
		for (int i = 0; i < size; i++)
			arr[i] = rand() % 20 + 1;
	}

	void Print()
	{
		cout << "Array: ";
		for (int i = 0; i < size; i++)
			cout << arr[i] << " ";
	}

	void Sort()
	{
		for (int i = 0; i < size - 1; i++)
			for (int j = i + 1; j < size; j++)
				if (arr[i] > arr[j])
					swap(arr[i], arr[j]);

	}

	void AddEl()
	{
		int* newArr = new int[size + 1];

		for (int i = 0; i < size; i++)
			newArr[i] = arr[i];

		int item;
		cout << "Enter el: ";
		cin >> item;

		newArr[size] = item;

		delete[] arr;

		arr = new int[size + 1];

		for (int i = 0; i < size + 1; i++)
			arr[i] = newArr[i];

		size += 1;
	}

	void DeleteLastEl()
	{
		int* tmpArr = new int[size - 1];

		for (int i = 0; i < size - 1; i++)
			tmpArr[i] = arr[i];

		delete[] arr;

		arr = new int[size - 1];

		for (int i = 0; i < size - 1; i++)
			arr[i] = tmpArr[i];

		size -= 1;
	}

	int FindMax()
	{
		int max = -999;

		for (int i = 0; i < size; i++)
		{
			if (arr[i] > max)
				max = arr[i];
		}

		return max;
	}

	void SendToFile()
	{
		try
		{
			ofstream fout("array.txt");

			for (int i = 0; i < size; i++)
			{
				fout << arr[i] << " ";
			}

			fout.close();
		}
		catch (const exception& ex)
		{
			cout << "Error while reading";
		}
	}

	void GetFromFile()
	{

		try
		{
			ifstream fin("array.txt");

			vector <int> numbers;

			numbers.clear();

			int temp;

			while (fin.good())
			{

				fin >> temp;
				if (fin.good())
					numbers.push_back(temp);
			}

			delete[] arr;

			size = numbers.size();

			arr = new int[size];

			for (int i = 0; i < size; i++)
			{
				arr[i] = numbers[i];
			}

			fin.close();
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}

		Print();
	}

};

int main()
{
	srand(unsigned(time(NULL)));



	TryCatch arr;
	arr.Fill();


	char key;
	do {
		cout << " 1 Show array\n 2 Add el in the end of array\n 3 Delete last el"
			<< "\n 4 Find max el\n 5 Sort elements by the biggest\n 6 Send array to file\n 7 Get array from file \n 8 Exit\n->_";
		cin >> key;

		switch (key)
		{
		case '1':
		{
			arr.Print();
			cout << "\n";
			break;
		}
		case '2':
		{
			arr.AddEl();

			break;
		}
		case '3':
		{
			arr.DeleteLastEl();

			break;
		}
		case '4':
		{
			cout << "The biggest el is " << arr.FindMax() << endl;

			break;
		}
		case '5':
		{
			arr.Sort();

			break;
		}
		case '6':
		{
			arr.SendToFile();

			break;
		}
		case '7':
		{
			arr.GetFromFile();

			break;
		}
		default:
			break;
		}

		system("PAUSE");
		system("cls");

	} while (key != '8');



	return 0;
}
