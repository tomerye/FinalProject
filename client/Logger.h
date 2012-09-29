/*
 * Logger.h
 *
 *  Created on: Aug 25, 2012
 *      Author: tomer
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include "Event.h"
#include "Configurator.h"
#include <boost/circular_buffer.hpp>
#include <boost/thread.hpp>

class Logger
{

public:
	Logger(std::string loggerName);
	~Logger();
	void sendLog(Event event);//send event to the server and file.

private:
	void log2File(Event event);
	void log2Net();
	std::deque<Event> m_event_deque;
	std::string m_logger_name;
	std::string m_log_file_path;
	std::string m_remote_server_ip;
	boost::circular_buffer<Event> event_que;
	boost::thread send_worker_thread;
	boost::mutex que_mutex;
	boost::condition_variable condition_data_ready;
	bool terminate_working_thread;
};

#endif /* LOGGER_H_ */
