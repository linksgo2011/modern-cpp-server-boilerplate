#define CPPHTTPLIB_OPENSSL_SUPPORT

#include "httplib/httplib.h"
#include <iostream>

int main(int argc, char **argv) {
    httplib::Server svr;

    svr.Get("/hi", [](const httplib::Request &, httplib::Response &res) {
        res.set_content("hell world\n", "text/plain");
    });


    svr.listen("0.0.0.0", 8080);
    return 0;
}