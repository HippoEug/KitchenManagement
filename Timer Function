#include <chrono>
#include <iostream>
#include <future>
using namespace std;

void timer() {
    cout << "Start\n";
    for(int i=0;i<20;i++)
    {
        cout << (i) << '\n';
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << "DONE\n";
}
int main ()
{
    auto future = async(timer);
    //std::cout << "test\n";
}

#include <chrono>
#include <iostream>
#include <future>
#include <ctime>
using namespace std;

void timer()
{
    for (int i=0;;i++)
    {
        cout << (i) << '\n';
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void updateTime()
{
    while (1)
    {
        time_t now = time(0);
        tm* localtm = localtime(&now);
        cout << asctime(localtm) << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}


int main ()
{
    auto future = async(timer); //counting to 20
    
    
    //time_t t = time(0);   // get time now
    //struct tm * now = localtime( & t );
    //cout << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-' <<  now->tm_mday << endl; //to output year month day
    
    updateTime();
}
