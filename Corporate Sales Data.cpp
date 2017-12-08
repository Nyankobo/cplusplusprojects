//Tanya_Landreth
//Chapter 12-Corporate Sales Data
//6/24/16

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstring>

using namespace std;

//Global constants to hold size of c-strings:
	const int DIVSIZE = 50;

//Structure to hold sales data for each quarter:
	struct SalesDivision_S
		{
			char divisionName[DIVSIZE];	
			char quarterName1[DIVSIZE];
			char quarterSales[DIVSIZE];	

		};

//Function prototypes:
	void Binary_Data(fstream &, string);				//Binary Data
	void Text_Data(fstream &, string);					//Text Data

int main()
{

	fstream salesDataText;					//fstream for Text Data
	fstream salesDataBinary;				//fstream for Binary Data
	string textName;						//text file name
	string binaryName;						//binary file name
	
//Get file names:
	cout << "Enter a filename for the TEXT file: > ";
	cin >> textName;

	cout << "Enter a filename for the BINARY file: > ";
	cin >> binaryName;

//Enter data:
	Binary_Data(salesDataBinary, binaryName);		//Enter data into BINARY file

	Text_Data(salesDataText, textName);				//Enter data into TEXT file


	//if re-write doesn't work, this is where you can copy back over::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//OPEN FILES FOR MATCHING:
	cout << "\n\t-[MATCHING]-\n";

	salesDataText.open(textName, ios::in);							//**open the TEXT FILE for INPUT
	salesDataBinary.open(binaryName, ios::in | ios::binary);		//**open the BINARY FILE for INPUT

if (!salesDataText)
{  	cout << "Error opening Text file.\n\n";  }

else {
	int counter = 0;															//set counter for average
		SalesDivision_S compare;												//structure to pull data from binary file
		double totalSales = 0.00;												//accumulator		
		double avgSales;														//hold avg sales

		//loop through TEXT FILE beg-to-end
		//loop through whole BINARY FILE for each 1 TEXT FILE loop
//while the TEXT FILE has data, and EO BINARY FILE not reached:
	while (salesDataText && !salesDataBinary.eof())														
	{
		//TRYING TO READ IN THE TEXT DATA
			string textInput1, textInput2;										//strings for TEXT FILE input

			getline(salesDataText, textInput1);
			getline(salesDataText, textInput2);

		//TRYING TO READ IN & COMPARE THE BINARY DATA

			//IF BINARY FILE WON'T OPEN, DISPLAY MESSAGE:
						if (!salesDataBinary)
						{  	cout << "Error opening Binary file.\n\n";  		}

			//IF BINARY FILE _DOES_ OPEN, READ THE DATA IN THE BINARY FILE AND START MATCHING:
				double sales;

				//TRYING TO COMPARE THE DATA
				//while there is binary data AND text data;
				while (!salesDataBinary.eof())
				{
					//read record
						salesDataBinary.read(reinterpret_cast<char *>(&compare), sizeof(compare));

						//COMPARING DATA:
							//compare data in text and binary files
						//if the data in TEXT file DOES match binary data
						if (compare.divisionName == textInput1 && compare.quarterName1 == textInput2)
						{
							//show match message
							cout << "\nDivision & Quarter Names match!\n";
							cout << "\tBinary: " << compare.divisionName << " " << compare.quarterName1 << endl;
							cout << "\tText: " << textInput1 << " " << textInput2 << endl;

							//display total sales for the division/quarters matched:
							cout << "\tTotal Sales for " << compare.divisionName << ", " << compare.quarterName1 << ": $" << compare.quarterSales;

							//READING IN BINARY DATA:
							sales = atof(compare.quarterSales);

							//total sales accumulates:
							totalSales += sales;

							//Counter for average increments
							counter++;

							cout << "\n\t\t COUNTER: " << counter << endl;

							//Average sales established:
							avgSales = (totalSales / counter);
							cout << fixed << setprecision(2) << "\n\tAverage Sales for all divisions/quarters matched: $" << avgSales << endl << "\n";
						} //end the "match" if

						//If no match, show "doesn't match" message;
						else { cout << "\n------No match.----------\n"; } //end else no match


		}//end while to compare, if the BINARY file has ended & when there is no more  data in TEXT file

//After binary file has ended, clearing/seeking should restart BINARY FILE
			//repeat until end of TEXT FILE is reached

					salesDataBinary.clear();					//clear EOF flag for binary file
					salesDataBinary.seekg(0L, ios::beg);		//seekfile to beginning

	}//END GIGANTIC WHILE, for "while there is data in the TEXT FILE"	

}//end ELSE, for if the text file opens


//close all files
salesDataBinary.close();
salesDataText.close();	 
	 
	 system("pause");
			return 0;
		
} //end main

//FUNCTION ...................... Get Binary Data ........................................................................................
void Binary_Data(fstream & binaryfile, string filenameBINARY)
{
					SalesDivision_S enterSalesInfo;									//structure to hold binary data

					binaryfile.open(filenameBINARY, ios::out | ios::binary);		//**open the BINARY FILE for output

				//if BINARY FILE fails to open, display a message
						if (binaryfile.fail())	
						{
							cout << "Binary file failed to open";
							binaryfile.close();
						}		

				//Otherwise, have them enter data:
						else
						{
							cout << "\n\t-[BINARY DATA ENTRY]-\n";

							int num = 0;
							char again;

							do										//for loop for regions
							{
								cout << "\nEnter Division: ";
								cin.ignore();
								cin.getline(enterSalesInfo.divisionName, DIVSIZE);

								cout << "\nEnter quarter name and sales amount: >>> \n";
								cout << ++num << ") Quarter name:";
								cin.getline(enterSalesInfo.quarterName1, DIVSIZE);
								cout << num << ") Quarter sales amount: ";
								cin.getline(enterSalesInfo.quarterSales, DIVSIZE);
									while (atof(enterSalesInfo.quarterSales) < 0)								//validation sales amt > 0
									{
									cout << " **Enter sales amount: ";
									cin.getline(enterSalesInfo.quarterSales, DIVSIZE);
									}

							binaryfile.write(reinterpret_cast<char *>(&enterSalesInfo), sizeof(enterSalesInfo));		//writing entire struc to binary file

									cout << "\tEnter more data? Y/N >> ";
									cin >> again;

							} while (again == 'y' || again == 'Y');


							//close binary file
							binaryfile.close();	
						}//end else
} //END OF BINARY FUNCTION


//FUNCTION ......................... Get Text Data ................................................................
void Text_Data(fstream & textfile, string filenameTEXT)
				{
					textfile.open(filenameTEXT, ios::out);							//**open the TEXT FILE for OUTPUT

					cout << "\n\t-[TEXT DATA ENTRY]-\n\n";

					if (textfile.fail())	//if TEXT FILE fails to open, display a message=
							{
								cout << "Text file failed to open";
								textfile.close();
							}

					else
					{
						string salesDivName, quarterNum;							//strings
						char again;													//loop control

						do
						{
							cin.ignore();
							cout << "Enter the name of a sales division: > ";
							getline(cin, salesDivName);

							textfile << salesDivName << endl;		//writing to text file

							cout << "Enter quarter number: > ";
							getline(cin, quarterNum);

							textfile << quarterNum << endl;			//writing to text file

							cout << "\tEnter more data? Y/N >> ";
							cin >> again;

						} while (again == 'y' || again == 'Y');


						textfile.close();							//close text file

					}

} //END OF TEXT FUNCTION