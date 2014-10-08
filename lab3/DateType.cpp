Mandelynn Atkins

// File DateType.cpp  contains the implementation of class DateType
#include "DateType.h"
#include <fstream>
#include <iostream>
using namespace std;

// Nmber of days in each month
static int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30,
                            31, 30, 31};	

// Nmaes of the months
static string conversionTable[] = {"Error", "January", "February", 
    "March", "April", "May", "June", "July", "August", "September",
    "October", "November", "December"};

void DateType::Initialize (int newMonth, int newDay, int newYear)
// Post: If newMonth, newDay and newYear represent a valid date,
//       year is set to newYear;
//       month is set to newMonth;
//       day is set to newDay;
//       otherwise a string exception is thrown, stating the
//       first incorrect parameter.
//
// Note:  Years must be 1900 or sooner.
//
{
   // iffffssssss
   if(newMonth < 1 || newMonth > 12)
   {
      throw string ("Invalid month");
   }
   
   else if(newDay < 1 || newDay > daysInMonth[newMonth])
   {
      throw string ("Invalid day.");
   }
   
   else if(newYear <= 1900)
   {
      throw string ("Invalid year.");
   }
   
   day = newDay;
   year = newYear;
   month = newMonth;
}
int DateType::GetMonth() const
// Accessor function for data member month.
{
   return month;
}

string DateType::GetMonthAsString() const
// Returns data member as a string
{
   // *** put code here
   return conversionTable[month];
}

int DateType::GetYear() const
// Accessor function for data member year.
{
   return year;
}

int DateType::GetDay() const
// Accessor function for data member day.
{
   return day;
}

bool DateType::leapYear(int year) const
// Determines whether the year is a leap year and
// returns true if it is and false if not
{
   //
   return(year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

DateType DateType::Adjust(int daysAway) const
// Pre:  Self has been initialized
// Post: Function value = newDate daysAway from self
{
   int newDay = day + daysAway;
   int newMonth = month;
   int newYear = year;
   bool finished = false;
   DateType returnDate;
   
   while(!finished)
   {
      int daysInThisMonth = daysInMonth[newMonth];
	  if(newMonth == 2)
	  {
	     if(leapYear(newYear))
		    daysInThisMonth++;
	  }
	  if(newDay <= daysInThisMonth)
	     finished = true;
	  else
	  {
	     newDay = newDay - daysInThisMonth;
		 newMonth = (newMonth % 12) + 1;
		 if(newMonth == 1)
		    newYear++;
	   }
    }
	
	returnDate.Initialize(newMonth, newDay, newYear);
	return returnDate;
}