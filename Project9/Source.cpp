#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int main()
{
	ifstream fsInput("in.txt", ios::in);
	ofstream fsOutput("out.txt", ios::out);
	int dem = 0;
	if (fsInput.fail())
	{
		cout << "Load File That Bai";
		return 0;
	}
	else
	{
		while (!fsInput.eof())
		{
			dem++;
			char temp[255];
			fsInput.getline(temp, 255);
			string line = temp;
			string lineIndex;
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == '"')
				{
					for (int j = i + 1; j < line.length(); j++)
					{
						if (line[j] == '"')
						{
							fsOutput << lineIndex << "\t";
							break;
						}
						lineIndex = lineIndex + line[j];
					}
				}
			}
			if (dem == 47)
			{
				fsOutput << endl;
				dem = 0;
			}
				
		}
	}
	fsInput.close();
}