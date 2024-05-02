#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <fmt/core.h>

#define LOG_TRACE(logger, message, ...) logger.Trace(__FILE__, __LINE__, __func__, message, ##__VA_ARGS__)
#define LOG_DEBUG(logger, message, ...) logger.Debug(__FILE__, __LINE__, __func__, message, ##__VA_ARGS__)
#define LOG_INFO(logger, message, ...) logger.Info(__FILE__, __LINE__, __func__, message, ##__VA_ARGS__)
#define LOG_WARN(logger, message, ...) logger.Warn(__FILE__, __LINE__, __func__, message, ##__VA_ARGS__)
#define LOG_ERROR(logger, message, ...) logger.Error(__FILE__, __LINE__, __func__, message, ##__VA_ARGS__)

class Loggable {
    public:
        Loggable();
        virtual ~Loggable() = default;

        template<typename... Args>
        void Trace(const char *file, int line, const char *method, const char *message) {
            logger->trace("[{}:{}:{}] {}", file, method, line, message);
        }

        template<typename... Args>
        void Debug(const char *file, int line, const char *method, const char *message) {
            logger->debug("[{}:{}:{}] {}", file, method, line, message);
        }

        template<typename... Args>
        void Info(const char *file, int line, const char *method, const char *message) {
            logger->info("[{}:{}:{}] {}", file, method, line, message);
        }

        template<typename... Args>
        void Warn(const char *file, int line, const char *method, const char *message) {
            logger->warn("[{}:{}:{}] {}", file, method, line, message);
        }

        template<typename... Args>
        void Error(const char *file, int line, const char *method, const char *message) {
            logger->error("[{}:{}:{}] {}", file, method, line, message);
        }

    private:
        std::shared_ptr<spdlog::logger> logger;
};