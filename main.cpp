#include <crow.h>
#include <fstream>
#include "./include/ load.h"
#include "./include/add.h"

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        auto load=crow::mustache::load("index.html");
        return load.render(); 
    });

        CROW_ROUTE(app, "/bookmarks")([](){
            crow::mustache::context ctx = load_bookmarks_data();
            auto load_page = crow::mustache::load("bookmarks.html");
            return load_page.render(ctx);
        });

    CROW_ROUTE(app,"/add").methods(crow::HTTPMethod::GET)([](){
        auto load_page=crow::mustache::load("add.html");
        return load_page.render();
    });

    CROW_ROUTE(app,"/add_data").methods(crow::HTTPMethod::POST)([](const crow::request& req){
        auto parameters=req.get_body_params();
        std::string name=parameters.get("name");
        std::string url=parameters.get("url");
        std::string tag=parameters.get("tag");
        auto confirmation=add_bookmarks(name,url,tag);
        auto load_page=crow::mustache::load("confirmation.html");
        crow::mustache::context ctx;
        ctx={{"name",name},{"url",url}};
        return load_page.render(ctx);
    });

    app.port(80).multithreaded().run();
}