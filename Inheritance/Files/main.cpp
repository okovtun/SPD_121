#include<iostream>
#include<fstream>
using namespace std;

//#define WRITE_TO_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	cout << "Hello World!" << endl;

	ofstream fout;
	fout.open("File.txt", std::ios_base::app);
	//app - append(ix)
	fout << "Привет Мир!" << endl;
	fout.close();

	system("notepad File.txt");
#endif // WRITE_TO_FILE

	ifstream fin("File.txt");
	if (fin.is_open())
	{
		//Read file
		const unsigned int SIZE = 256;
		char buffer[SIZE]{};
		while (!fin.eof())//while NOT end_of_file
		{
			//fin >> buffer;
			fin.getline(buffer, SIZE);
			cout << buffer << endl;;
		}
		fin.close();
	}
	else
	{
		cerr << "Error: file not found" << endl;
	}
}