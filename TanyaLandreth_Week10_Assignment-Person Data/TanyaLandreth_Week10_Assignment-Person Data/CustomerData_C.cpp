#include "stdafx.h"
#include "CustomerData_C.h"
#include "PersonData_C.h"
#include <string>

//Constructors:
	CustomerData_C::CustomerData_C() : PersonData_C()
	{
		customerNum = 0;
		mailingList = true;

	}

	CustomerData_C::CustomerData_C(int num, bool yn)
	{
		Set_CustomerNum(num);
		Set_MailingList(yn);
	}

//Mutators:
	void CustomerData_C::Set_CustomerNum(int number)
		{
			customerNum = number;

		}
	void CustomerData_C::Set_MailingList(bool yesorno)
		{
			mailingList = yesorno;

		}

//Accessors:
	int CustomerData_C::Get_CustomerNum() const
	{
		return customerNum;
	}
	string CustomerData_C::Get_MailingList() const
	{
		if (mailingList == true)
			return "Yes";

		if (mailingList == false)
			return "No";
	}

	void CustomerData_C::Display_Data() const		
	{
		cout << "\tCustomer #: " << Get_CustomerNum() << endl;
		cout << "\tOn Mailing List (Y/N): " << Get_MailingList() << endl;
	}

//Destructor:
CustomerData_C::~CustomerData_C()
{
}
