#include "pch.h"
#include "copyad5a672a-f35d-421d-b9ac-58dd24ffeefe.h"
using namespace std::chrono_literals;
#pragma warning ( disable : 4996 )
namespace backup {
	void DLL time(int timer, int start)
	{
		int minutes = 0;
		int seconds = 0;
		seconds = timer;
		int hours = 0;
		int days = 0;
		start++;
		for (int i = 0; i < timer; ++i) {
			int currentTime = combineInt(days, hours, minutes, seconds);
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
	void DLL backup::make_backup(int interval, std::string dir1, std::string dir2, std::string file, bool showTime)
	{
		log::filename = file;
		int i = interval *= 60;
		auto s = std::chrono::high_resolution_clock::now();
		auto e = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> d = e - s;
		int interval2 = i / 60;
		if (interval2 == 1) {
			log(EVENT_START_FUNCTION_ONE, showTime, d, interval2, dir1);
		}
		else
		{
			log(EVENT_START_FUNCTION_ELSE, showTime, d, interval2, dir1);
		}
		int copyInterval = i;
		std::this_thread::sleep_for(std::chrono::seconds(copyInterval));
		const std::chrono::time_point<std::chrono::system_clock> now =
			std::chrono::system_clock::now();

		const std::time_t t_c = std::chrono::system_clock::to_time_t(now);

		int ti_me = t_c;

		std::string appender = "-" + std::to_string(ti_me);

		dir2.append(appender);

		log(EVENT_BACKUP_STARTED, showTime, d, interval2, dir1);
		std::chrono::time_point<std::chrono::steady_clock> start;
		std::chrono::time_point<std::chrono::steady_clock> end;
		try {
			start = std::chrono::high_resolution_clock::now();
			std::filesystem::copy(dir1, dir2, std::filesystem::copy_options::recursive);
			end = std::chrono::high_resolution_clock::now();
		}
		catch (std::filesystem::filesystem_error) {
			log(FILESYSTEM_VALID_PATH_ERROR, true, d, i, dir1);
		}
		std::chrono::duration<float> duration = end - start;
		log(EVENT_FINISH_BACKUP, showTime, duration, 0, dir1);
	}
	void DLL backup::make_backup(AUTO<int> interval, std::string dir1, std::string dir2, std::string file, bool showTime)
	{
		log::filename = file;
		AUTO<int> uint32 = 60;
		int i = 0;
		interval.multi(interval, 60);
		i = interval.m_keep;
		auto s = std::chrono::high_resolution_clock::now();
		auto e = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> d = e - s;
		int interval2 = i / 60;
		if (interval2 == 1) {
			log(EVENT_START_FUNCTION_ONE, showTime, d, interval2, dir1);
		}
		else
		{
			log(EVENT_START_FUNCTION_ELSE, showTime, d, interval2, dir1);
		}
		int copyInterval = i;
		std::this_thread::sleep_for(std::chrono::seconds(copyInterval));
		const std::chrono::time_point<std::chrono::system_clock> now =
			std::chrono::system_clock::now();

		const std::time_t t_c = std::chrono::system_clock::to_time_t(now);

		int ti_me = t_c;

		std::string appender = "-" + std::to_string(ti_me);

		dir2.append(appender);

		log(EVENT_BACKUP_STARTED, showTime, d, interval2, dir1);
		std::chrono::time_point<std::chrono::steady_clock> start;
		std::chrono::time_point<std::chrono::steady_clock> end;
		try {
				start = std::chrono::high_resolution_clock::now();
				std::filesystem::copy(dir1, dir2, std::filesystem::copy_options::recursive);
				end = std::chrono::high_resolution_clock::now();
		}
		catch (std::filesystem::filesystem_error) {
			log(FILESYSTEM_VALID_PATH_ERROR, true, d, i, dir1);
		}
		std::chrono::duration<float> duration = end - start;
		log(EVENT_FINISH_BACKUP, showTime, duration, 0, dir1);
	}
	std::invalid_argument backup::throwException(String _in1)
	{
			return std::invalid_argument(_in1);
	}
	bool log::logger(int eventId, bool displayTime, std::chrono::duration<float> dur, int interval, std::string dir1)
	{
		if (eventId == FILESYSTEM_VALID_PATH_ERROR) {
			std::cout << "Backup failed! Did you enter the correct path?\n";
			log::makeFile(FILESYSTEM_VALID_PATH_ERROR, dur, interval, dir1);
			log::FS_ERROR = true;
			return false;
		}
		else if (eventId == EVENT_START_FUNCTION_ONE && displayTime == true && log::FS_ERROR == false) {
			current_sys_time();  std::cout << "Backing up in " << interval << " minute\n";
			return true;
		}
		else if (eventId == EVENT_START_FUNCTION_ELSE && displayTime == true && log::FS_ERROR == false)
		{
			current_sys_time();  std::cout << "Backing up in " << interval << " minutes\n";
			return true;
		}
		else if (eventId == EVENT_START_FUNCTION_ONE && displayTime == false && log::FS_ERROR == false) {
			std::cout << "Backing up in " << interval << " minute\n";
			return true;
		}
		else if (eventId == EVENT_START_FUNCTION_ELSE && displayTime == false && log::FS_ERROR == false)
		{
			std::cout << "Backing up in " << interval << " minutes\n";
			return true;
		}
		else if (eventId == EVENT_BACKUP_STARTED && displayTime == true && log::FS_ERROR == false) {
			current_sys_time();  std::cout << "Starting backup of " << dir1 << "...\n";
			return true;
		}
		else if (eventId == EVENT_BACKUP_STARTED && displayTime == false && log::FS_ERROR == false) {
			std::cout << "Starting backup of " << dir1 << "...\n";
			return true;
		}
		else if (eventId == EVENT_FINISH_BACKUP && displayTime == true && log::FS_ERROR == false)
		{
			current_sys_time(); std::cout << "Backup Finished! Backup took approximately " << dur.count() << " seconds\n";
			return true;
		}
		else if (eventId == EVENT_FINISH_BACKUP && displayTime == false && log::FS_ERROR == false) {
			std::cout << "Backup Finished! Backup took approximately " << dur.count() << " seconds\n";
			return true;
		}
		else if (FS_ERROR == false) {
			std::cout << "[INTERNAL LOGGING SYSTEM] Are you sure you entered valid parameters? Event id macros are EVENT_BACKUP_STARTED, EVENT_BACKUP_FINISHED and EVENT_FUNCTION_START.\n";
			std::cout << "Possible error code is " << GetLastError() << " 0 means nothing went wrong, 1 means a mild error happened and 2 means a severe error happened\n";
			return false;
		};
	}
	const char* loggerException::except() const throw()
	{
		return "Did you enter valid parameters? Make sure that backup::log::filename has any data in it or did you enter the correct path?";
	}
	void log::makeFile(int eventId, std::chrono::duration<float> dur, int interval, std::string dir1)
	{
		std::ofstream __io_file__;
		__io_file__.open(log::filename, std::ios_base::app);
		std::string _fileName = getexepathA() + log::filename;
		switch (eventId) {
		case 0:
			__io_file__ << "\n[INTERNAL LOGGING SYSTEM, INFO]Backup finished! Backup took " << dur.count() << " seconds\n\n";
			//__io_file__.flush();
			break;
		case 1:
			__io_file__ << "\n[INTERNAL LOGGING SYSTEM, INFO] Backing up in " << interval << " minute." << " Path is " << dir1 << "\n\n";
			//__io_file__.flush();
			break;
		case 2:
			__io_file__ << "\n[INTERNAL LOGGING SYSTEM, INFO] Backing up in " << interval << " minutes." << " Path is " << dir1 << "\n\n";
			//__io_file__.flush();
			break;
		case 3:
			__io_file__ << "\n[INTERNAL LOGGING SYSTEM, INFO] Starting backup of " << dir1 << "...\n\n";
			//__io_file__.flush();
			break;
		case 4:
			__io_file__ << "\n[INTERNAL LOGGING SYSTEM, ERROR] Backup failed!\n\n";
			//__io_file__.flush();
			break;
		default:
			__io_file__ << "\n[INTERNAL LOGGING SYSTEM, ERROR] Did you enter valid parameters? Event ids are" << eventIds;
		}
		__io_file__.close();
	}
	void log::thread()
	{
		while (true) {
			std::this_thread::sleep_for(120h);
			std::filesystem::remove(log::filename);
			std::ofstream file(log::filename);
		}
	}
	std::string DLL getexepathA()
	{
		char result[MAX_PATH]{};
		return std::string(result, GetModuleFileNameA(NULL, result, MAX_PATH));
	}
	void current_sys_time() {
		const std::chrono::time_point<std::chrono::system_clock> now =
			std::chrono::system_clock::now();

		const std::time_t t_c = std::chrono::system_clock::to_time_t(now);
		std::cout << std::put_time(std::localtime(&t_c), "%F %T.\n");
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
	//bool config::stob(std::string s, bool throw_on_error)
	//{
		//auto result = false;    // failure to assert is false
		//std::istringstream is(s);
		// first try simple integer conversion
		//is >> result;
		//if (is.fail())
		//{
			// simple integer failed; try boolean
			//is.clear();
			//is >> std::boolalpha >> result;
		//}
		//if (is.fail() && throw_on_error)
		//{
			//throw std::invalid_argument(s.append(" is not convertable to bool"));
		//}
		//return result;
	//}
	//bool config::exists()
	//{
		//return std::filesystem::exists(getexepathA() + "\\config.txt");
	//}
}