#pragma once

class dateRegister {
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
