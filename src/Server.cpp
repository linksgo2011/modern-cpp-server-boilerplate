#include "httplib/httplib.h"
#include "Server.h"

void Server::start(){
    httplib::Server svr;

    svr.Get("/hi", [](const httplib::Request &, httplib::Response &res) {
        res.set_content("hell world\n", "text/plain");
    });

    svr.listen("0.0.0.0", 8080);
}