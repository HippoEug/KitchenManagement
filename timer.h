#pragma once
using namespace std;

class dateRegister
{
public:
    int daysSinceDefault; //default is set to Year 2000
    int daysToExpiry;
    
    int c_year;
    int c_month;
    int c_day;
    
    int c_yearCheck;
    int c_monthCheck;
    int c_dayCheck;
    
    void updateDate();
    void dayMainCalculator();
    void daysCounterX(int dc_days, int dc_months, int dc_years, int& dcNumberOfDays);
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
        
        this_thread::sleep_for(chrono::seconds(1)); //CHANGE
        
        c_year = (localtm->tm_year + 1900);
        c_month = (localtm->tm_mon + 1);
        c_day = (localtm->tm_mday);
    }
}

void dateRegister::dayMainCalculator()
{
    int countX = 0;
    
    c_day = 1;
    c_month = 1;
    c_year = 2000;
    
    while (1)
    {
        daysCounterX(c_day, c_month, c_year, countX);
        this_thread::sleep_for(chrono::seconds(10));
    }
}

void dateRegister::daysCounterX(int dc_days, int dc_months, int dc_years, int& dcNumberOfDays)
{
    int date = 0; //total number of days
    
    if ((dc_days == 29 && dc_months == 2 && dc_months<=12 && dc_years % 4 == 0 && dc_years>=2000 && dc_days>0 && dc_months>0 && dc_years>0) || (dc_days <= 31 && dc_months % 2 != 0 && dc_months <= 12 && dc_years >= 2000 && dc_days>0 && dc_months>0 && dc_years>0) || (dc_days <= 30 && dc_months % 2 == 0 && dc_months <= 12 && dc_years >= 2000 && dc_days>0 && dc_months>0 && dc_years>0))
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

void dateRegister::dayAlarm()
{
    int numberOfLines;
    
    int fstreamCategoryExpiry;
    string fstreamNameExpiry;
    int fstreamCodeExpiry;
    long long fstreamDateExpiry;
    
    while (1)
    {
        lineCount(numberOfLines);
        
        ifstream getDateData;
        getDateData.open("V2.1B", std::fstream::in | std::fstream::out | std::fstream::app);
        //getDateData.open("V2.1B", std::ios::_Noreplace);
        
        getDateData >> fstreamCategoryExpiry >> fstreamNameExpiry >> fstreamCodeExpiry >> fstreamDateExpiry;
        
        //cout << "Date Expiry = " << fstreamDateExpiry << endl; //for debugging
        
        getDateData.close();
        
        this_thread::sleep_for(chrono::seconds(10));
    }
}
