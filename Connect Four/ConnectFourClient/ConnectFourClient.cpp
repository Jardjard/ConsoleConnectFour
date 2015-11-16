#include <iostream>
#include <string>
#include <vector>
#include <WinSock2.h>
#pragma comment (lib,"ws2_32.lib")
#include <Windows.h>
using namespace std;


struct consoleSize{
	consoleSize(unsigned width, unsigned height)
	{
		SMALL_RECT r;
		COORD      c;
		auto hConOut = GetStdHandle( STD_OUTPUT_HANDLE );

		c.X = width;
		c.Y = height;
		SetConsoleScreenBufferSize( hConOut, c );
	}

	~consoleSize()
	{

	}


	void color (WORD color = 0x1B)
	{
		auto hConOut = GetStdHandle( STD_OUTPUT_HANDLE );
		SetConsoleTextAttribute (hConOut, color);
	}
};



int main(){
	//Set the console background to black

	//Vector of colors
	vector<string> chipColor(6);
	chipColor.push_back("Blue");
	chipColor.push_back("Green");
	chipColor.push_back("Aqua");
	chipColor.push_back("Red");
	chipColor.push_back("Purple");
	chipColor.push_back("Yellow");

	//Set the console window width
	consoleSize con (200, 200);

	//Grid walls
	string lineStartEnd = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	string lineTwo = "|||||" ;
	string lineThree = "||||";
	string uiBufferThree = "|||";
	string lineCenter = "|";

	//Circle Empty
	string circleLineOne		 = ",-''-.";
	string circlineLineTwo		= "/      \\";
	string circlineLineThree	= "|        |";
	string circlineLineFour		= "\\      /";
	string circlineLineFive		  = "'-..-'";

	//Circle Full
	string circleFilledOne		  = ",-++-.";
	string circlineFilledTwo	= "/++++++\\";
	string circlineFilledThree	= "|++++++++|";
	string circlineFilledeFour	= "\\++++++/";
	string circlineFilledFive	  = "'-++-'";

	//Empty Circle Grid
	cout << "                          WELCOME TO CONNECT FOUR! :)\n" << endl;

	//Pick your chip piece
	con.color(7);
	cout << "Pick a color for your Chip Piece: " << endl;
	con.color (9);
	cout << "Blue: 1" << endl;
	con.color(10);
	cout << "Green: 2" << endl;
	con.color(11);
	cout << "Aqua: 3" << endl;
	con.color(12);
	cout << "Red: 4" << endl;
	con.color(13);
	cout << "Purple: 5" << endl;
	con.color(14);
	cout << "Yellow: 6" << endl;
	con.color(7);

	string playerColor;
	cout << "Your Color: ";
	getline(cin, playerColor);
	int colorNumber = atoi(playerColor.c_str());

	if( colorNumber <= chipColor.size())
	{
		//player chip is colorNum + 8
	}
	

	for(int i = 0; i < 6; i++)
	{
		con.color(3);
		cout << lineStartEnd << endl;
		cout << lineTwo << circleLineOne<< lineTwo << circleLineOne <<lineTwo << circleLineOne <<lineTwo << circleLineOne <<lineTwo << circleLineOne <<lineTwo << circleLineOne <<lineTwo << circleLineOne <<lineTwo << endl;
		cout << lineThree << circlineLineTwo << uiBufferThree << circlineLineTwo << uiBufferThree << circlineLineTwo << uiBufferThree << circlineLineTwo << uiBufferThree << circlineLineTwo << uiBufferThree << circlineLineTwo << uiBufferThree << circlineLineTwo << lineThree << endl;
		cout << uiBufferThree << circlineLineThree << lineCenter << circlineLineThree << lineCenter << circlineLineThree << lineCenter << circlineLineThree << lineCenter << circlineLineThree << lineCenter << circlineLineThree << lineCenter << circlineLineThree << uiBufferThree << endl;
		cout << lineThree << circlineLineFour << uiBufferThree << circlineLineFour << uiBufferThree << circlineLineFour << uiBufferThree << circlineLineFour << uiBufferThree << circlineLineFour << uiBufferThree << circlineLineFour << uiBufferThree << circlineLineFour << lineThree << endl;
		cout << lineTwo << circlineLineFive << lineTwo << circlineLineFive << lineTwo << circlineLineFive << lineTwo << circlineLineFive << lineTwo << circlineLineFive << lineTwo << circlineLineFive << lineTwo << circlineLineFive << lineTwo << endl;
	}
	cout << lineStartEnd << endl;

}