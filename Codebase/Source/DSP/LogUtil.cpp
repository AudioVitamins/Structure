#include "LogUtil.h"
namespace Jimmy {
#ifdef JYMMY_LOGGER_MUTEXT
	std::mutex Logger::m_mutex;
#endif
	std::string Logger::m_logfile = "_Log.txt";
#ifdef WINDOW
	std::string Logger::m_dir = "D:\\\\";
#else
	std::string Logger::m_dir = "";
#endif
	int Logger::m_mode = 0;
	FILE *Logger::fp_da = NULL;
	FILE *Logger::fp_d = NULL;
	FILE *Logger::fp_i = NULL;
	FILE *Logger::fp_s = NULL;
	FILE *Logger::fp = NULL;

	void Logger::SeparateLog() {
		Logger::SetEnabled(m_mode);
		Logger::SetEnabled(m_mode);
	}
	void Logger::MoveFile(std::string file) {
		char newname[512];
		time_t t_now = time(NULL);
		tm tm_now = *localtime(&t_now);
#ifdef WINDOW
		_snprintf_s(newname, sizeof(newname), _TRUNCATE, "%s (renamed at %04d-%02d-%02d %02d-%02d-%02d)",
#else
		sprintf(newname, "%s (renamed at %04d-%02d-%02d %02d-%02d-%02d)",
#endif
			(m_dir+file).c_str(),
			tm_now.tm_year + 1900, tm_now.tm_mon + 1, tm_now.tm_mday,
			tm_now.tm_hour, tm_now.tm_min, tm_now.tm_sec);
		newname[sizeof(newname) - 1] = '\0';

		rename((m_dir + file).c_str(), newname);
	}
	void Logger::OpenFile(LOG_LEVEL level, std::string file) {
		FILE *&fp = GetFile(level);
#ifdef WINDOW
		if ((fp = _fsopen((m_dir + file).c_str(), "a+", _SH_DENYWR)) == NULL)
#else
		if ((fp = fopen((m_dir + file).c_str(), "a+")) == NULL)
#endif
			fp = NULL;
	}
	void Logger::SetEnabled(int mode, bool autoName)
	{
		printf("Log Set Mode: %x", mode);
		m_mode = mode;

		if (fp_da != NULL) {
			fclose(fp_da);
			fp_da = NULL;
		}

		if (fp_d != NULL) {
			fclose(fp_d);
			fp_d = NULL;
		}

		if (fp_i != NULL) {
			fclose(fp_i);
			fp_i = NULL;
		}

		if (fp_s != NULL) {
			fclose(fp_s);
			fp_s = NULL;
		}


		if (fp != NULL) {
			fclose(fp);
			fp = NULL;
		}

		char name[200] = { 0 };
		if (autoName) {
			time_t t_now = time(NULL);
			tm tm_now = *localtime(&t_now);
#ifdef WINDOW
			_snprintf_s(name, sizeof(newname), _TRUNCATE, "%04d-%02d-%02d %02d-%02d-%02d",
#else
			sprintf(name, "%04d-%02d-%02d %02d-%02d-%02d",
#endif 
				tm_now.tm_year + 1900, tm_now.tm_mon + 1, tm_now.tm_mday,
				tm_now.tm_hour, tm_now.tm_min, tm_now.tm_sec);
		}
		MoveFile("DATA" + m_logfile);
		MoveFile("DETAIL" + m_logfile);
		MoveFile("INFORMATION" + m_logfile);
		MoveFile("STEP" + m_logfile);

		if (mode & DATA) {
			OpenFile(DATA, std::string("DATA") + name + m_logfile);
			return;
		}

		if (mode & DETAIL) {
			OpenFile(DETAIL, std::string("DETAIL") + name + m_logfile);
			return;
		}

		if (mode & INFORMATION) {
			OpenFile(INFORMATION, std::string("INFORMATION") + name + m_logfile);
			return;
		}

		if (mode & STEP) {
			OpenFile(STEP, std::string("STEP") + name + m_logfile );
			return;
		}
	};
	FILE * &Logger::GetFile(LOG_LEVEL lev) {
		return fp;
	}
	void Logger::Print(int level, char *fmt, ...) {
		FILE *&fp = GetFile((LOG_LEVEL)m_mode);

		if (fp == NULL) return;

		if (!(level & m_mode)) return;

		char buffer[8096];
		va_list va;
#ifdef JYMMY_LOGGER_MUTEXT
		Locker l(m_mutex);
#endif
		if (!(level & NONE_TIME)) {
#ifdef WINDOWS
			time_t t1;
			struct tm t2;
            time(&t1);
			localtime_s(&t2, &t1);
			fprintf(fp, "%04d-%02d-%02d %02d:%02d:%02d | ", t2.tm_year + 1900, t2.tm_mon + 1, t2.tm_mday, t2.
                    tm_hour, t2.tm_min, t2.tm_sec);
#else
            
#endif
		}

		va_start(va, fmt);
		
#ifdef WINDOW
		_vsnprintf_s(buffer, sizeof(buffer), _TRUNCATE, fmt, va);
#else
		sprintf(buffer, fmt, va);
#endif
		va_end(va);
		fprintf(fp, "%s", buffer);

		fflush(fp);
	}
};
