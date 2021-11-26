#pragma once
#include <string>
#include <chrono>
#include <algorithm>
#include <iomanip>
#include <ctime>
#define DLL __declspec(dllexport)
namespace backup {
	int DLL time(int timer, int start = 0);
	void DLL current_sys_time();
	std::string NowToString();
	void DLL make_backup(int interval, std::string dir1, std::string dir2);
	int combineInt(int in1, int in2, int in3, int in4);
}