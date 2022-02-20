#include "httplib/httplib.h"
#include "Server.h"
#include "Logger.h"
#include "lib/Reverse.h"

void Server::start() {
    httplib::Server svr;
    Logger logger;
    Reverse reverse;

    svr.Get("/hi", [&](const httplib::Request &, httplib::Response &res) {
        logger.print("handle request");
        std::string string = "hell world\n";
        res.set_content(reverse.reverse(string), "text/plain");
    });

    svr.listen("0.0.0.0", 8080);
}