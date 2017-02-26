/*
Version 0.1
*/

// HelpToWrite

#include <iostream>

using namespace std;

class HelpToWrite
{
private:
	int i;
public:
	template <typename T>
	void write(T id)
	{
		cout << id;
	}

	template <typename T>
	void write(string text, T id)
	{
		cout << text << id;
	}

	template <typename T>
	void read(T &id)
	{
		cin >> id;
	}

	void tab(int sum)
	{
		for (i = 0; i < sum; i++)
			write("\n");
	}

	void space(int sum)
	{
		for (i = 0; i < sum; i++)
			write("-");
	}
};
