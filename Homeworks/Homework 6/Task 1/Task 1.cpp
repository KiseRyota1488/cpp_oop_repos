#include "Roullete.h"
#include <ctime>

int main()
{
	const int size = 5;
	srand(time(0));
	Roullete first(size);
	Roullete second(size);
	Roullete third(size);

	int el;
	for (int i = 0; i < size; i++)
	{
		el = rand() % 3 + 1;
		first.Add(el);
		el = rand() % 3 + 1;
		second.Add(el);
		el = rand() % 3 + 1;
		third.Add(el);
	}

	while (1)
	{
		system("cls");


		for (int i = 0; i < rand() % 5 + 1; i++)
			first.Extract();
		for (int i = 0; i < rand() % 5 + 1; i++)
			second.Extract();
		for (int i = 0; i < rand() % 5 + 1; i++)
			third.Extract();


		cout << "   Roullete game:\n Do spin and if u will get 3 same numbers u would win and grab 50$!\n\n";

		cout << "    |          |          |\n";
		first.Show();
		cout << " ";
		second.Show();
		cout << " ";
		third.Show();
		cout << "\n\n";

		system("PAUSE");

		if (first.GetById(first.GetCount() / 2) == second.GetById(second.GetCount() / 2) && first.GetById(first.GetCount() / 2) == third.GetById(third.GetCount() / 2))
		{
			bool tmp;
			system("cls");
			cout << " You won!\nDo you want to play more?\n->_";
			cin >> tmp;
			if (tmp)
				continue;
			else
				break;
		}
		else
		{
			system("cls");
			cout << "You lost!\n";
		}

		system("PAUSE");

	}

}

