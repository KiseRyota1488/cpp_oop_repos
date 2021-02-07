#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>

using namespace std;

int main()
{
	//1
	vector <int> v1;
	v1.resize(5);
	for (int i = 0; i < v1.size(); i++)
	{
		cout << "Enter " << i + 1 << " el: ";
		cin >> v1[i];
	}

	vector <int> v2(10, 0);

	vector <int> v3;
	cout << "Enter v3 size: ";
	int size;
	cin >> size;
	for (int i = 0; i < size; i++)
		v3.push_back(rand() % 10 + 1);

	vector <int> v4(v1.begin(), v1.end());

	vector <int> v5(v3.size() - 2);

	for (int i = 0; i < v5.size(); i++)
	{
		v5[i] = v3[i + 1];
	}



	//2
	for (int i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << " ";
	}
	cout << endl;

	ofstream write("numbers.txt");

	for (int i = 0; i < v1.size(); i++)
	{
		write << v3[i] << " ";
	}

	write.close();


	//3

	for (int i = 0; i < v2.size(); i++)
	{
		v2[i] = i + 1;
	}

	for (int i = 0; i < v2.size(); i++)
	{
		swap(v2[i], v2[rand() % v2.size()]);
	}

	v2.erase(v2.begin() + 1);
	v2.pop_back();


	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}

	//4

	for (int i = 0; i < v4.size(); i+=2)
	{
		v4.push_back(v4[i]);
		for (int j = v4.size()-1; j > i + 1; j--)
		{
			swap(v4[j], v4[j - 1]);
		}
	}

	cout << endl;
	for (int i = 0; i < v4.size(); i++)
	{
		cout << v4[i] << " ";
	}

	system("PAUSE");

}
