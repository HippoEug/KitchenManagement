#pragma once
using namespace std;

class dateRegister
{
public:
	int daysSinceDefault; //default is set to Year 2000
	int daysComparison;

	int c_year;
	int c_month;
	int c_day;

	void updateDate();
	void dayMainCalculator();
	void daysCounterX(int dc_days, int dc_months, int dc_years); //int& dcNumberOfDays
	void daysCounterY(int cx_days, int cx_months, int cx_years);
	void dayAlarm();
};

void dateRegister::updateDate()
{
	c_year = 2000;
	c_month = 1;
	c_day = 1;

	while (1)
	{
		time_t now = time(0);
		struct tm* localtm = localtime(&now);
		//cout << asc(localtm) << endl;
		asctime(localtm);

		//this_thread::sleep_for(chrono::seconds(5)); //CHANGE

		c_year = (localtm->tm_year + 1900);
		c_month = (localtm->tm_mon + 1);
		c_day = (localtm->tm_mday);
	}
}

void dateRegister::dayMainCalculator()
{

	c_day = 1;
	c_month = 1;
	c_year = 2000;

	while (1)
	{
		daysCounterX(c_day, c_month, c_year); //countX
		this_thread::sleep_for(chrono::seconds(1));
	}
}

void dateRegister::dayAlarm()
{
	int numberOfLines;

	int fstreamCategoryExpiry;
	string fstreamNameExpiry;
	int fstreamCodeExpiry;
	int fstreamDateDay;
	int fstreamDateMonth;
	int fstreamDateYear;

	int reInit = 0;

	lineCount(numberOfLines);

	ifstream getDateData;
	getDateData.open("V2.1C", std::ios::_Noreplace);

	for (int i = 1; i <= numberOfLines; i++)
	{
		getDateData >> fstreamCategoryExpiry >> fstreamNameExpiry >> fstreamCodeExpiry >> fstreamDateDay >> fstreamDateMonth >> fstreamDateYear;

		daysCounterY(fstreamDateDay, fstreamDateMonth, fstreamDateYear);

		if (daysComparison == daysSinceDefault || daysComparison == daysSinceDefault + 1 || daysComparison == daysSinceDefault + 2 || daysComparison == daysSinceDefault + 3)
		{
			cout << "\nExpiring Items: " << endl;
			cout << fstreamNameExpiry << " IS EXPIRING ON: " << fstreamDateDay << "-" << fstreamDateMonth << "-" << fstreamDateYear << endl;

			reInit = 1;
		}
		if (daysComparison < daysSinceDefault)
		{
			cout << "\nExpired Items: " << endl;
			cout << fstreamNameExpiry << " HAS EXPIRED ON: " << fstreamDateDay << "-" << fstreamDateMonth << "-" << fstreamDateYear << endl;
		}
		else if (daysComparison == 0 || daysSinceDefault == 0)
		{
			//do nothing
		}
	}

	getDateData.close();
	//this_thread::sleep_for(chrono::seconds(60));
	}


void dateRegister::daysCounterX(int dc_days, int dc_months, int dc_years) //int& dcNumberOfDays
{
	int date = 0; //total number of days

	if ((dc_days == 29 && dc_months == 2 && dc_months <= 12 && dc_years % 4 == 0 && dc_years >= 2000 && dc_days>0 && dc_months>0 && dc_years>0) || (dc_days <= 31 && dc_months % 2 != 0 && dc_months <= 12 && dc_years >= 2000 && dc_days>0 && dc_months>0 && dc_years>0) || (dc_days <= 30 && dc_months % 2 == 0 && dc_months <= 12 && dc_years >= 2000 && dc_days>0 && dc_months>0 && dc_years>0))
	{
		date = date + dc_days;	//add day to total number of days

		for (int i = 1; i < dc_months; i++) //add number of days in month to total number of days
		{
			if (i == 2)
			{
				if (dc_years % 4 == 0)
				{
					date = date + 29;
				}
				else
				{
					date = date + 28;
				}
			}
			else
			{
				if (i % 2 == 0)
				{
					date = date + 30;
				}
				else
				{
					date = date + 31;
				}
			}
		}

		for (int i = 2000; i < dc_years; i++) //add number of days in years to total number of days
		{
			if (i % 4 == 0)
			{
				date = date + 366;
			}
			else
			{
				date = date + 365;
			}
		}
		daysSinceDefault = date;
		//cout << "Days since 2000 = " << date << endl; //for debugging purpose
		//cout << "Date + 3 = " << date + 3 << endl; //for debugging purpose
		//cout << "Days in Class = " << daysSinceDefault << endl;
	}
	else
	{
		cout << "[ERROR]: Wrong format or input year is below 2000. Try again!" << endl;
	}
}

void dateRegister::daysCounterY(int cx_days, int cx_months, int cx_years) //int& dcNumberOfDays
{
	int date = 0; //total number of days

	if ((cx_days == 29 && cx_months == 2 && cx_months <= 12 && cx_years % 4 == 0 && cx_years >= 2000 && cx_days>0 && cx_months>0 && cx_years>0) || (cx_days <= 31 && cx_months % 2 != 0 && cx_months <= 12 && cx_years >= 2000 && cx_days>0 && cx_months>0 && cx_years>0) || (cx_days <= 30 && cx_months % 2 == 0 && cx_months <= 12 && cx_years >= 2000 && cx_days>0 && cx_months>0 && cx_years>0))
	{
		date = date + cx_days;	//add day to total number of days

		for (int i = 1; i < cx_months; i++) //add number of days in month to total number of days
		{
			if (i == 2)
			{
				if (cx_years % 4 == 0)
				{
					date = date + 29;
				}
				else
				{
					date = date + 28;
				}
			}
			else
			{
				if (i % 2 == 0)
				{
					date = date + 30;
				}
				else
				{
					date = date + 31;
				}
			}
		}

		for (int i = 2000; i < cx_years; i++) //add number of days in years to total number of days
		{
			if (i % 4 == 0)
			{
				date = date + 366;
			}
			else
			{
				date = date + 365;
			}
		}
		daysComparison = date;
		//cout << "Days since 2000 = " << date << endl; //for debugging purpose
		//cout << "Date + 3 = " << date + 3 << endl; //for debugging purpose
		//cout << "Days in Class = " << daysSinceDefault << endl;
	}
	else
	{
		cout << "[ERROR]: Wrong format or input year is below 2000. Try again!" << endl;
	}
}
