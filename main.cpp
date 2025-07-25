#include <crow.h>

int main(){
    crow::SimpleApp app;
    
    CROW_ROUTE(app,"/")([](){
        auto load=crow::mustache::load("index.html");
        return load.render();
    });



    app.port(80).multithreaded().run();
}