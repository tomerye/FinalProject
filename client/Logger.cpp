/*
 * Logger.cpp
 *
 *  Created on: Aug 25, 2012
 *      Author: tomer
 */




#include "Logger.h"

Logger::Logger(std::string loggerName):m_logger_name(loggerName),event_que(100)
,terminate_working_thread(false){
	
	send_worker_thread = boost::thread(&Logger::log2Net,this);
		
	/*
	m_log_file_path=Configurator::getParameterValue("log_file_path");
	m_remote_server_ip=Configurator::getParameterValue("remote_server_ip");
 * */

}

Logger::~Logger()
{
	{
		boost::unique_lock<boost::mutex> lock(que_mutex);
		terminate_working_thread=true;
	}
	condition_data_ready.notify_one();
	send_worker_thread.join();

}
void Logger::sendLog(Event event)
{
	boost::unique_lock<boost::mutex> lock(que_mutex);
	event_que.push_back(event);
	condition_data_ready.notify_one();
}


void Logger::log2File(Event event)
{

}

void Logger::log2Net()
{
	int count=0;
	while(count<1)
	{

		boost::unique_lock<boost::mutex> lock(que_mutex);
		while(event_que.empty())
		{

			condition_data_ready.wait(lock);
			if(terminate_working_thread)
			{
				lock.unlock();
				return;

			}

		}
		Event *e=event_que.front();
		std::cout << e->get();
		event_que.pop_front();
		
		count++;
	}
}
