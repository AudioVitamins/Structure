#pragma once

#include <string>
#include <stdarg.h>
#include <time.h>

#define JIMMY_LOGGER_PRINT Jimmy::Logger::Print
#define JIMMY_LOGGER_ACTIVATE Jimmy::Logger::SetEnabled

#define JIMMY_LOGGER_DATA Jimmy::DATA
#define JIMMY_LOGGER_DETAIL Jimmy::DETAIL
#define JIMMY_LOGGER_INFO Jimmy::INFORMATION
#define JIMMY_LOGGER_STEP Jimmy::STEP
#define JIMMY_LOGGER_NONE Jimmy::NONE
#define JIMMY_LOGGER_NONE_TIME Jimmy::NONE_TIME


#ifdef JYMMY_LOGGER_MUTEXT
#include <mutex>
#endif
namespace Jimmy {
#ifdef JYMMY_LOGGER_MUTEXT
	class Locker
	{
	public:
		Locker(std::mutex & mutex) : m_mutex(mutex)
		{
			m_mutex.lock();
		}

		~Locker()
		{
			m_mutex.unlock();
		}

	private:
		std::mutex& m_mutex;
	};
#endif
	enum LOG_LEVEL {
		DATA = 0x00000008,
		DETAIL = 0x00000004,
		INFORMATION = 0x00000002,
		STEP = 0x00000001,
		NONE = 0x0000000,

		NONE_TIME = 0x80000008
	};
	class Logger
	{
	private:
#ifdef JYMMY_LOGGER_MUTEXT
		static std::mutex m_mutex;
#endif
		
		static std::string m_logfile;
		static std::string m_dir;
		static int m_mode;
		static FILE *fp_da;
		static FILE *fp_d;
		static FILE *fp_i;
		static FILE *fp_s;
		static FILE *fp;
		static void MoveFile(std::string file);
		static void OpenFile(LOG_LEVEL level, std::string file);
		static FILE * &GetFile(LOG_LEVEL level);
	public:
		static void SetEnabled(int enable, bool autoName = false);
		static void SeparateLog();
		static void SetFilename(std::string logfile) { m_logfile = logfile; };
		static void Print(int level, char *fmt, ...);
		static void Log(LOG_LEVEL level, char *fmt, ...);
	};
};
