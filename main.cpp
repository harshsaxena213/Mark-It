#include <crow.h>
#include <fstream>
#include "./include/ load.h"

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([]()
                         {
        auto load=crow::mustache::load("index.html");
        return load.render(); });

    CROW_ROUTE(app, "/bookmarks")([](){
        crow::json::rvalue json_value=load_bookmarks_data();
        crow::mustache::context ctx;
        std::vector<crow::json::wvalue> items;
        crow::mustache::context item_ctx;
        if (json_value.t()==crow::json::type::List)
        {
            auto arr=json_value.lo();
            for(const auto& key:arr){

                item_ctx["Title"] = key["title"].s();
                item_ctx["Url"] = key["url"].s();
                item_ctx["Tag"] = key["tag"].s();
                items.push_back(item_ctx);
            }
        }
        ctx["items"] = std::move(items);

        CROW_LOG_INFO << "Items count: " << items.size();

        auto load_page=crow::mustache::load("bookmarks.html");
        return load_page.render(ctx);

    });
                                  
    // return data;
    app.port(80).multithreaded().run();
}