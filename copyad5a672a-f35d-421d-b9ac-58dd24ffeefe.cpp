#include "pch.h"
#include <sstream>
#include <iostream>
#include <chrono>
#include "copyad5a672a-f35d-421d-b9ac-58dd24ffeefe.h"
#pragma warning (disable : 4996)
namespace backup {
	int DLL time(int timer, int start)
	{
		int minutes = 0;
		int seconds = 0;
		seconds = timer;
		int hours = 0;
		int days = 0;
		start++;
		for (int i = 0; i < timer; ++i) {
			int currentTime = combineInt(days, hours, minutes, seconds);
			for (int j = 0; j < 1; j++)
			{
				return currentTime;
			}
			seconds++;
			start++;
			Sleep(1000);
			if (start == 60 || seconds == 60) {
				minutes++;
				seconds = 0;
				start = 0;
			}
			else if (minutes == 60) {
				hours++;
				seconds = 0;
				minutes = 0;
			}
			else if (hours == 24) {
				days++;
				seconds = 0;
				minutes = 0;
				hours = 0;
			}
			else {

			}
		}
	}
	std::string NowToString()
	{
		std::chrono::system_clock::time_point p = std::chrono::system_clock::now();
		time_t t = std::chrono::system_clock::to_time_t(p);
		char str[26];
		ctime_s(str, sizeof str, &t);
		return str;
	}
	void DLL make_backup(int interval, std::string dir1, std::string dir2)
	{
		interval *= 1000;
		interval *= 60;
		Sleep(interval);
		const std::chrono::time_point<std::chrono::system_clock> now =
			std::chrono::system_clock::now();

		const std::time_t t_c = std::chrono::system_clock::to_time_t(now);

		int ti_me = t_c;

		std::string appender = "-" + std::to_string(ti_me);

		dir2.append(appender);

		std::filesystem::copy(dir1, dir2, std::filesystem::copy_options::recursive);
	}
	int combineInt(int in1, int in2, int in3, int in4)
	{
		std::string s1 = std::to_string(in1);
		std::string s2 = std::to_string(in2);
		std::string s3 = std::to_string(in3);
		std::string s4 = std::to_string(in4);

		// Concatenate both strings 
		std::string s = s1 + s2 + s3 + s4;

		// Convert the concatenated  
		// to integer 
		int returnValue = stoi(s);

		// return the formed integer 
		return returnValue;
	}
	void current_sys_time() {
		const std::chrono::time_point<std::chrono::system_clock> now =
			std::chrono::system_clock::now();

		const std::time_t t_c = std::chrono::system_clock::to_time_t(now);
		std::cout << std::put_time(std::localtime(&t_c), "%F %T.\n") << std::flush;
	}
}