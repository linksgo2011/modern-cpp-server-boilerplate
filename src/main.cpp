#include <iostream>
#include "httplib.h"
#include <Server.h>
#include "Logger.h"

int main(int argc, char **argv) {
    Server server;
    Logger logger;

    logger.print("start....");
    server.start();
    return 0;
}