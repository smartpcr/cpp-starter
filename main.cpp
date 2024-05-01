#include <fmt/core.h>
#include <httplib.h>

int main() {
    httplib::Client client("http://example.com");
    auto res = client.Get("/");
    if (res) {
        std::cout << "Status: " << res->status << std::endl;
        for (const auto& [key, value] : res->headers) {
            std::cout << key << ": " << value << std::endl;
        }
        std::cout << "Body: " << res->body << std::endl;
    } else {
        std::cout << "Failed to get a response" << std::endl;
    }
    fmt::print("Hello, World!\n");
    return 0;
}
