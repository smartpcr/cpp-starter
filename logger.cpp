#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

#include "logger.h"

Loggable::Loggable() {
    auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    consoleSink->set_level(spdlog::level::info);
    auto errorLogFileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/error.log", true);
    errorLogFileSink->set_level(spdlog::level::warn);
    auto debugLogFileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/debug.log", true);
    debugLogFileSink->set_level(spdlog::level::debug);
    logger = std::make_shared<spdlog::logger>("myLogger");
    logger->sinks().push_back(consoleSink);
    logger->sinks().push_back(errorLogFileSink);
    logger->sinks().push_back(debugLogFileSink);
}
