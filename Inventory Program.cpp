// TanyaLandreth
//MidTerm - Inventory Program
//07/05/2016

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>	//may not use
#include <cstring>

//Global constants to hold size of c-strings:
const int DESCRIPSZ = 51;
const int ITEMIDSZ = 7;
const int DATESZ = 11;

//Structure to hold data for each product:
struct InventoryData_S
{
	char itemID[ITEMIDSZ];
	char itemDescrip[DESCRIPSZ];
	char qtyAvail[DESCRIPSZ];
	char costWholeSale[DESCRIPSZ];
	char costRetail[DESCRIPSZ];
	char dateQtyUpdated[DATESZ];
};

using namespace std;

void Menu();				//Display menu
void Build_Inventory(fstream &);		//Build inventory - enter data only
void Create_Transactions(fstream &, string);	//Transactions for inventory - change data
void Display_Inventory(fstream &, string);	//Display binary file data

int main()
{
	string binaryName;						//binary file name
	fstream binaryData;					//fstream for Binary Data

	fstream textData;					//fstream for Text Data
	string textName;						//text file name
	
	char choice;

	cout << "\nEnter a filename for the INVENTORY file: > ";		//enter name for binary file
	cin >> binaryName;

	cin.ignore();
	cout << "\nEnter a filename for the TRANSACTIONS file: > ";		//enter name for text file
	cin >> textName;

	//loop menu
	do {

		Menu();	//display menu

		cout << "\nPlease select from the menu: > ";
		cin >> choice;

		while (toupper(choice) < 'A' || toupper(choice) > 'E')
			{
				cout << "\nPlease enter a valid selection: A, B, C, D, or E > ";
				cin >> choice;
			}

		//1. BUILD INVENTORY
		if (choice == 'A' || choice == 'a')
		{

				binaryData.open(binaryName, ios::out | ios::binary);		//**open the BINARY FILE for INPUT
				//if BINARY FILE fails to open, display a message
				if (!binaryData)
				{
					cout << "Binary file failed to open.\n";
					binaryData.close();
				}

				else
				{
					Build_Inventory(binaryData);						//call function to build inventory
					binaryData.close();
				}
		}

		//2. CREATE TRANSACTION HISTORY
		else if (choice == 'B' || choice == 'b')
				{
					Create_Transactions(textData, textName);						//call function to create transactions
				}

		//3. UPDATE INVENTORY
		else if (choice == 'c' || choice == 'C')
		{
			cout << "\n[[[[[ Update Inventory ]]]]]\n";

			InventoryData_S readingStructure;

			const int ARRAYSZ = 100;
			InventoryData_S *inventoryArray = nullptr;
			inventoryArray = new InventoryData_S[ARRAYSZ];

			binaryData.open(binaryName, ios::in | ios::out | ios::binary);		//**open the BINARY FILE for I/O
			//if BINARY FILE fails to open, display a message
			if (binaryData.fail())
				{	cout << "*****Binary file failed to open.\n";
					delete[] inventoryArray;
				}

			else 
			{
				int index = 0;

				//read record:
				binaryData.read(reinterpret_cast<char *>(&readingStructure), sizeof(readingStructure));

				//while data is in the binary file
				for (int index = 0 ; index < ARRAYSZ && !binaryData.eof() ; index++)
				{
					//copy data from record into array
					strcpy(inventoryArray[index].itemID, readingStructure.itemID);
					strcpy(inventoryArray[index].itemDescrip, readingStructure.itemDescrip);
					strcpy(inventoryArray[index].qtyAvail, readingStructure.qtyAvail);
					strcpy(inventoryArray[index].costWholeSale, readingStructure.costWholeSale);
					strcpy(inventoryArray[index].costRetail, readingStructure.costRetail);
					strcpy(inventoryArray[index].dateQtyUpdated, readingStructure.dateQtyUpdated);

					//read record:
					binaryData.read(reinterpret_cast<char *>(&readingStructure), sizeof(readingStructure));

				} 

		//once all data from binary file is read and copied to array:
				binaryData.close();
		//open text file
		textData.open(textName, ios::in);

		//if there IS text file, start updates:
if (textData)
	{	int i = 0;

		cin.ignore();
		cout << "\nEnter Today's Date: ";
		cin.getline(readingStructure.dateQtyUpdated, DATESZ);

//while text data exists


do
		{
				//copy to array
				strcpy(inventoryArray[i].dateQtyUpdated, readingStructure.dateQtyUpdated);

				string transaction1, transaction2, transaction3;		//strings for TEXT FILE input
				int pos;
				pos = textData.tellg();
				getline(textData, transaction1);
				pos = textData.tellg();
				getline(textData, transaction2);
				pos = textData.tellg();
				getline(textData, transaction3);
				pos = textData.tellg();
				
				//COMPARE:
do {
						//AI - Add qty to inventory
						if ((transaction1 == inventoryArray[i].itemID) && (transaction2 == "AI" || transaction2 == "ai"))
						{
							int numAi1, numAi2, totalAi;

							//convert contents of qtyAvail to INT
							numAi1 = atoi(inventoryArray[i].qtyAvail);

							char copyAi[ARRAYSZ];

							//copy transaction3 (reduction from inventory) to c-string
							strcpy(copyAi, transaction3.c_str());

							//convert c-string transaction3 (reduction from inventory) to INT
							numAi2 = atoi(copyAi);

							//add transaction3 TO current qtyAvail
							if ((numAi1 + numAi2) < 0)
									{ cout << "Unable to update QUANTITY AVAILABLE; negative qty occurrs."; }
							else {
								totalAi = numAi1 + numAi2;

								//convert INT to a STRING & store it
								string newTotal = to_string(totalAi);

								//convert STRING to c-string
								strcpy(copyAi, newTotal.c_str());

								//copy NEW TOTAL c-string into current qty Avail
								strcpy(inventoryArray[i].qtyAvail, copyAi);
							}
						}

						//RI - Remove qty from inventory
						else if ((transaction1 == inventoryArray[i].itemID) && (transaction2 == "RI" || transaction2 == "ri"))
						{
							int numRi1, numRi2, totalRi;

							//convert contents of qtyAvail to INT
							numRi1 = atoi(inventoryArray[i].qtyAvail);

							char copyRi[ARRAYSZ];
							//copy transaction3 (reduction from inventory) to c-string
							strcpy(copyRi, transaction3.c_str());

							//convert c-string transaction3 (reduction from inventory) to INT
							numRi2 = atoi(copyRi);

							//subtract transaction3 from current qtyAvail
							if ((numRi1 - numRi2) < 0)
							{
								cout << "Unable to update QUANTITY AVAILABLE; negative qty occurrs.";
							}
							else {
								totalRi = numRi1 + numRi2;

								//convert INT to a STRING & store it
								string newTotal = to_string(totalRi);

								//convert STRING to c-string
								strcpy(copyRi, newTotal.c_str());

								//copy NEW TOTAL c-string into current qty Avail
								strcpy(inventoryArray[i].qtyAvail, copyRi);
							}
						}

						//CW - Change wholesale cost
						else if ((transaction1 == inventoryArray[i].itemID) && (transaction2 == "CW" || transaction2 == "cw"))
						{
							char copyCw[ARRAYSZ];
							//copy transaction3 (wholesale cost) to c-string
							strcpy(copyCw, transaction3.c_str());

							//copy NEW COST c-string into current COST c-string
							strcpy(inventoryArray[i].costWholeSale, copyCw);
						}

						//CR - Change retail cost
						else if ((transaction1 == inventoryArray[i].itemID) && (transaction2 == "CR" || transaction2 == "cr"))
						{
							char copyCr[ARRAYSZ];
							//copy transaction3 (wholesale cost) to c-string
							strcpy(copyCr, transaction3.c_str());

							//copy NEW COST c-string into current COST c-string
							strcpy(inventoryArray[i].costRetail, copyCr);

						}

						//CD - Change description
						else if ((transaction1 == inventoryArray[i].itemID) && (transaction2 == "CD" || transaction2 == "cd"))
						{
							char copyCd[ARRAYSZ];
							//copy transaction3 (DESCRIP) to c-string
							strcpy(copyCd, transaction3.c_str());

							//copy NEW DESCRIP c-string into current descrip c-string
							strcpy(inventoryArray[i].itemDescrip, copyCd);
						}

					pos = textData.tellg();
					getline(textData, transaction1);
					pos = textData.tellg();
					getline(textData, transaction2);
					pos = textData.tellg();
					getline(textData, transaction3);
					pos = textData.tellg();

				} while (pos != -1);  //end while, for text file
				
				i++;
				textData.clear();
				textData.seekg(0L, ios::beg);
				
		} while (i < ARRAYSZ);
		
	}//end if for IF TEXT DATA IS PRESENT

	binaryData.open(binaryName, ios::out | ios::binary);

	int rewrite = 0;

	do{
		strcpy(readingStructure.itemID, inventoryArray[rewrite].itemID);
		strcpy(readingStructure.itemDescrip, inventoryArray[rewrite].itemDescrip);
		strcpy(readingStructure.qtyAvail, inventoryArray[rewrite].qtyAvail);
		strcpy(readingStructure.costWholeSale, inventoryArray[rewrite].costWholeSale);
		strcpy(readingStructure.costRetail, inventoryArray[rewrite].costRetail);
		strcpy(readingStructure.dateQtyUpdated, inventoryArray[rewrite].dateQtyUpdated);

		binaryData.write(reinterpret_cast<char *>(&readingStructure), sizeof(readingStructure));

		rewrite++;

	} while (rewrite < ARRAYSZ);

		binaryData.close();
		textData.close();
		delete[] inventoryArray;

}//end ELSE for when binary file doesn't fail

}//end main IF for menu choice

		//4. DISPLAY INVENTORY
		else if (choice == 'd' || choice == 'D')
		{
			cout << "\n[[[[[ Display Inventory ]]]]]\n";

			Display_Inventory(binaryData, binaryName);	
		
		}

		//5. END PROGRAM
		else if (choice == 'e' || choice == 'E')
		{
			exit(EXIT_FAILURE);
		}

		else
		{
			cout << "\nPlease enter a valid selection: A, B, C, D, or E > ";
		}

		
	} while (!cin.fail());
	//end menu loop

	system("pause");
    return 0;
}


//1. Build inventory - enter data only
void Build_Inventory(fstream &binaryFile)
{
	InventoryData_S Building;												//structure to hold binary data

	//Otherwise, have them enter data:
		cout << "\n[[[[[ Inventory ]]]]]\n";

		int num = 0;
		char again;

		int countNumofElem = 0;

	//for loop for data entry
		do
		{
			cout << "\n> Enter Item I.D.: >> ";
			cin.ignore();
			cin.getline(Building.itemID, ITEMIDSZ);
			//cin.clear();

			int len = strlen(Building.itemID);

				while ( len > ITEMIDSZ-1)		//validation -> this does NOT work -_-;
				{
					cin.clear();
					cin.ignore();
					cout << " **Enter a valid Item I.D. (6 digits): ";
					cin.getline(Building.itemID, ITEMIDSZ);

				}
				while (len < ITEMIDSZ-1)		//validation
				{
					cin.clear();
					cin.ignore();
					cout << " **Enter a valid Item I.D. (6 digits): ";
					cin.getline(Building.itemID, ITEMIDSZ);

				}

			cout << "\n> Enter Item Description: >> ";
				cin.ignore('\0');
				cin.getline(Building.itemDescrip, DESCRIPSZ);

			cout << "\n> Enter Quantity Available: >> ";
			cin.ignore('\0');
			cin.getline(Building.qtyAvail, DESCRIPSZ);
				while (atoi(Building.qtyAvail) < 0 )		//validation
				{
					cin.clear();
					cout << " **Enter a valid quantity ( > 0 ): ";
					cin.getline(Building.qtyAvail, DESCRIPSZ);
				}

			cout << "\n> Enter Wholesale Price: >> ";
			cin.getline(Building.costWholeSale, DESCRIPSZ);
				while (atof(Building.costWholeSale) < 0.00)		//validation
				{
					cout << " **Enter a valid price ( >/= 0.00 ): ";
					cin.getline(Building.costWholeSale, DESCRIPSZ);
				}
				
			cout << "\n> Enter Retail Price: >> ";
			cin >> Building.costRetail;
				while (atof(Building.costRetail) < 0.00)		//validation
				{
					cout << " **Enter a valid price ( >/= 0.00 ): ";
					cin.getline(Building.costRetail, DESCRIPSZ);
				}

			cout << "\n> Enter Item Entry Date (mm/dd/yyyy): >> ";
			cin.ignore();
			cin.getline(Building.dateQtyUpdated, DATESZ);

			binaryFile.write(reinterpret_cast<char *>(&Building), sizeof(Building));		//writing entire struc to binary file

			cout << "\tEnter more data? Y/N >> ";
			cin >> again;			

			countNumofElem++;

		} while (again == 'y' || again == 'Y');
		//END data entry loop

		//close binary file
		binaryFile.close();

}//end 1.


//2. Transactions for inventory - change data
void Create_Transactions(fstream &textFile, string fileName)
{
	cout << "\n[[[[[ Inventory Transactions ]]]]]\n";

	int num = 0;
	char againTransaction, againItem;		

		int inventoryChg, itemID;
		double costChgW, costChgR;
		string descripChg, transCode;

	//open TextFile
		textFile.open(fileName, ios::out);

		if (textFile.fail())
		{
			cout << "Text file failed to open.\n";
		}

	//for loop for data entry
	do
	{
		cout << "\n> Enter Item I.D.: >> ";
		cin >> itemID;

					while (itemID < 0)		//validation
					{
						//cin.ignore();
						cout << " **Enter a valid Item I.D. (6 digits): ";
						cin >> itemID;

						//cin.clear();
					}

	do
	{		
					cout << "\n\t--------------------------------------------------";
					cout << "\n\tAI - Add qty to inventory";
					cout << "\n\tRI - Remove qty from inventory";
					cout << "\n\tCW - Change wholesale cost";
					cout << "\n\tCR - Change retail cost";
					cout << "\n\tCD - Change description";
					cout << "\n\t--------------------------------------------------\n";

					cout << "\n> Enter Transaction Code: >> ";
					cin.ignore();
					getline(cin, transCode);

							int length = transCode.length();

							while (length > 2)		//validation -> this does NOT work...
							{
								//cin.ignore();
								cout << " **Enter a valid transaction code (2 characters, per menu): ";
								getline(cin, transCode);
								//cin.clear();
							}
							while (length < 2)		//validation
							{
								//cin.ignore();
								cout << " **Enter a valid transaction code (2 characters, per menu): ";
								getline(cin, transCode);
								//cin.clear();
							}

				cout << "\n> Enter Detail for change made: >> " << endl;

				if (transCode == "AI" || transCode == "ai")  //if AI - Add to inventory
				{
					cout << "Enter amount added to inventory: > ";
					cin >> inventoryChg;

					textFile << itemID << "\n";
					textFile << transCode << "\n";
					textFile << inventoryChg << "\n";
				}

				else if (transCode == "RI" || transCode == "ri")  //if RI - Reduce from inventory
					{
						cout << "Enter amount taken from inventory: > ";
						cin >> inventoryChg;

						textFile << itemID << "\n";
						textFile << transCode << "\n";
						textFile << inventoryChg << "\n";
					}
				else if (transCode == "CW" || transCode == "cw")  //if CW - Change wholesale cost
					{
						cout << "Enter new wholesale price: > ";
						cin >> costChgW;

						while (costChgW < 0)		//validation
							{
								//cin.ignore();
								cout << " **Enter a valid amount ( >/= 0.00): ";
								cin >> costChgW;
								//cin.clear();
							}

						textFile << itemID << "\n";
						textFile << transCode << "\n";
						textFile << costChgW << "\n";
					}

				else if (transCode == "CR" || transCode == "cr")  //if CR - Change retail cost
					{
						cout << "Enter new retail price: > ";
						cin >> costChgR;

						while (costChgR < 0)		//validation
						{
							//cin.ignore();
							cout << " **Enter a valid amount ( >/= 0.00): ";
							cin >> costChgR;
							//cin.clear();
						}

						textFile << itemID << "\n";
						textFile << transCode << "\n";
						textFile << costChgR << "\n";
					}

				else if (transCode == "CD" || transCode == "cd")  //if CD - Change description
					{
						cout << "Enter new description: > ";
						cin.ignore('\0');
						getline(cin, descripChg);

						textFile << itemID << "\n";
						textFile << transCode << "\n";
						textFile << descripChg << "\n";
					}

				else {
						cout << "Please enter a valid transaction code: >> ";
					}

			//loop for same item
			cout << "\tEnter more data for item " << itemID << "? Y/N >> ";
			cin >> againItem;

	} while (againItem == 'y' || againItem == 'Y');
	//end loop for transactions per item

	cout << "\t\nCreate additional transactions? Y/N >> ";
	cin >> againTransaction;

} while (againTransaction == 'y' || againTransaction == 'Y');
	//END data entry loop

	//close text file
	textFile.close();

}//end 2.

//4. Display binary file data
void Display_Inventory(fstream &binaryData, string filename)
{
	InventoryData_S displayData;

		binaryData.open(filename, ios::in | ios::binary);		//**open the BINARY FILE for OUTPUT
																//if BINARY FILE fails to open, display a message
do
	{
		if (binaryData.fail())
		{
			cout << "*****Binary file failed to open.\n";
		}

		else
		{
			//read record:
			binaryData.read(reinterpret_cast<char *>(&displayData), sizeof(displayData));

			do
			{
				cout << "\n------------------------\t\t---------------------------------------\n";
				cout << "Item I.D.: \t\t\t" << displayData.itemID << endl;
				cout << "Item Description: \t\t" << displayData.itemDescrip << endl;
				cout << "Item Quantity Available: \t" << displayData.qtyAvail << endl;
				cout << "Item Last Updated: \t\t" << displayData.dateQtyUpdated << endl;
				cout << "Item Wholesale Cost: \t\t$" << displayData.costWholeSale << endl;
				cout << "Item Retail Cost: \t\t$" << displayData.costRetail << endl;

				binaryData.read(reinterpret_cast<char *>(&displayData), sizeof(displayData));

			} while (!binaryData.eof());
		}
} while (binaryData);

binaryData.close();

}//end 4.

void Menu()
{
	cout << "\n";
	cout << "\t|--------------------------------------------------|\n";
	cout << "\t|          [[[[[ Menu: ]]]]]                       |\n";
	cout << "\t|                                                  |\n";
	cout << "\t| A : Enter Inventory Item                         |\n";
	cout << "\t| B : Change Inventory                             |\n";
	cout << "\t| C : Update Inventory [run after any change]      |\n";
	cout << "\t| D : Display Inventory                            |\n";
	cout << "\t| E : End Program                                  |\n";
	cout << "\t|                                                  |\n";
	cout << "\t|--------------------------------------------------|\n\n";
}
