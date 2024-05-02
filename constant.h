#include <string>

class Constant {
    public:
        const char *message = "Welcome to spdlog!";
        const char *statusTemplate = "Status: {}";
        const char *bodyTemplate = "Body: {}";
        const char *errorMessage = "Failed to get a response";
};