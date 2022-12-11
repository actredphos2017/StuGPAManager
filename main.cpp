#include <iostream>


#define TEST_CPPCONN false

#if !TEST_CPPCONN

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

#endif



//test jdbc
#if TEST_CPPCONN

#include "cppconn/driver.h"
#include "cppconn/connection.h"

int main(){
    sql::Driver* dri = get_driver_instance();
    sql::Connection* con = dri->connect("tcp://127.0.0.1","root","gamemode1");
}

#endif