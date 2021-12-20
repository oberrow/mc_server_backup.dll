#pragma once
#include "pch.h"
#include "global.h"
#include "auto.h"
#define DLL __declspec(dllexport)
#define EVENT_FINISH_BACKUP 0
#define EVENT_START_FUNCTION_ONE 1
#define EVENT_START_FUNCTION_ELSE 2
#define EVENT_BACKUP_STARTED 3
#define FILESYSTEM_VALID_PATH_ERROR 4
#define KEY std::cout << "Press any key to continue..."; int g = _getch();
#pragma warning (disable : 4251)
#pragma warning (disable : 4275)

namespace backup {
	void DLL time(int timer, int start = 0);
	void DLL current_sys_time();
	int combineInt(int in1, int in2, int in3, int in4);
	std::string DLL getexepathA();
	/*class arrayToStr
	{
	private:
		std::string m_str;
	public:
		std::string str;
		arrayToStr(char array[]) {
			for (int i = 0; i < MAX_PATH + 1; i++)
			{
				if (array[i] != '\0')
					m_str = array[i];
				else {
					const char* null = '\0';
					str = m_str.append(null);
					break;
				}
			}
		}
	arrayToStr() {}
	};*/
	/*template<typename T, typename T1>
	class vectorAssign {
	private:
	public:
		vectorAssign(T1 size, std::array<T, size> assign, std::vector<T>& vec) {
			vec.assign(std::begin(assign), std::end(assign));
		}
	};*/
	/*class config {
		using global = backup::global;
	private:
		int m_n = sizeof(global::dllFilePath) / sizeof(global::dllFilePath[0]);
	public:
		inline static int optionType0{};

		inline static std::string optionType1{};

		inline static bool optionType2{};

		inline static std::vector<char> vec{};

		config() {
			config* obj = this;
			obj->vec.resize(m_n);
			backup::vectorAssign<char, int> assign = { global::dllFilePath, m_n, vec };
			vec.assign(global::dllFilePath, global::dllFilePath + m_n);
			for (int i : vec) {
				configPath = configPath + vec[i];
			}
			if (std::filesystem::exists(getexepathA() + "\\config.txt")) {
				std::ifstream fin(getexepathA() + "\\config.txt");
				while (getline(fin, line)) {
					std::istringstream sin(line.substr(line.find("=") + 1));
					if (line.find("logFileName") != -1)
						sin >> optionType1;
					else if (line.find("backupInterval") != -1)
						sin >> optionType0;
					else if (line.find("makeLog") != -1)
					sin >> optionType2;
			}
				
			}
			else {
				std::ofstream config(getexepathA() + "\\config.txt");
				config << "logFileName = log.txt\nbackupInterval = 60\nmakeLog = true";
				config.close();
				}
		}
	private:
		inline static std::string line;
		inline static std::string configPath;
		inline static bool returnVal{};
		bool stob(std::string s, bool throw_on_error = true);
		bool exists();
	*/
	class DLL removeFromString {
	public:
		std::string out{};
		removeFromString(std::string in, std::string removeFrom) {

			std::string::size_type i = in.find(removeFrom);

			if (i != std::string::npos)
				in.erase(i, removeFrom.length());
			out = in;
		}
	};
	class DLL loggerException : public std::exception {
	public:
		virtual const char* except() const throw();
	} loggerExecpt;
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const AUTO<T>& dt);
	class log {
	private:
		bool logger(int eventId, bool displayTime, std::chrono::duration<float> dur, int interval, std::string dir1);
		void makeFile(int eventId, std::chrono::duration<float> dur, int interval, std::string dir1);
		inline static bool FS_ERROR;
		void DLL thread();
	public:
		inline static int returnVal{};
		inline static bool makeLog = true;
		inline static std::string eventIds = " EVENT_FINISH_BACKUP, EVENT_START_FUNCTION_ONE, EVENT_START_FUNCTION_ELSE, EVENT_BACKUP_STARTED and FILESYSTEM_VALID_PATH_ERROR";
		inline static std::string blank = "";
		inline static std::string filename{};
		log(int eventId, bool displayTime, std::chrono::duration<float> dur, int interval, std::string dir1) {
			log* obj = this;
			removeFromString str{ std::string(global::dllFilePath), "mc_server_backup.dll" };
			filename = str.out.append(filename);
			//if (config.optionType2) {
				if (obj->logger(eventId, displayTime, dur, interval, dir1) == 1) {
					if (obj->makeLog) {
						obj->makeFile(eventId, dur, interval, dir1);
					}

					returnVal = 0;
				}
				else {
					obj->makeFile(eventId, dur, interval, dir1);
					returnVal = 1;
				}
				//}
		}
		log() {
			log* obj = this;
			//makes the log file
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
			if (filename == blank) //checks if log file variable has data
				returnVal = 1; //if not int returnVal = 1
			else { //if it does have data it will make the log file
				std::ofstream logFile(filename);
				logFile.close();
			}
		}
		friend class backup;
	};
	class DLL Time {
	public:
		std::chrono::time_point<std::chrono::steady_clock> start;
		std::chrono::time_point<std::chrono::steady_clock> end;
		std::chrono::duration<float> duration{};
		
		Time() 
		{
			start = std::chrono::high_resolution_clock::now();
		}
		~Time() {
			end = std::chrono::high_resolution_clock::now();
			duration = end - start;
		}
	};
	class DLL backup {
		using String = std::string;
		using stringRef = std::string&;
		private:
		String m_logError{ "The log file name string is blank, Please initalize backup::file first" };
		String m_dir1Error{ "The string for the directory to backup is blank, Please initalize backup::dir1 first" };
		String m_dir2Error{ "The string for where to backup the directory is blank, Please initalize backup::dir2 first" };
		String m_allErrors{ "All public strings are blank, Please initalize All member variables first" };
		void make_backup(int interval, std::string dir1, std::string dir2, std::string file, bool showTime = true);
		void make_backup(AUTO<int> interval, std::string dir1, std::string dir2, std::string file, bool showTime = true);
		std::invalid_argument [[nodiscard]] throwException(String _in1);
		backup* m_thisObj = this;
		log* obj;
		std::thread thread1{ [=]() { obj->thread(); } };
	public:
		inline static AUTO<int> interval{};

		inline static String dir1{ log::blank };
		inline static String dir2{ log::blank };
		inline static String file{ log::blank };
		inline static bool showTime{ true };
		backup() {
			if (file == log::blank && dir2 == log::blank && dir1 == log::blank)
				throw(std::exception(m_allErrors.c_str()));
			else if (dir1 == log::blank)
				throw(std::exception(m_dir1Error.c_str()));
			else if (dir2 == log::blank)
				throw(std::exception(m_dir2Error.c_str()));
			else if (file == log::blank)
				throw(std::exception(m_logError.c_str()));
			else {
				//whatever code I'm going to do in "class config"
				make_backup(interval, dir1, dir2, file, showTime);
			}
		}
		~backup() {
			thread1.detach();
		}
	};
}