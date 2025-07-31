#include <crow.h>
#include <fstream>

crow::mustache::context load_bookmarks_data()
{
    std::ifstream in("bookmarks.json");
    std::string json_data, line;
    while (getline(in, line))
        json_data += line;
    in.close();

    crow::json::rvalue json_value = crow::json::load(json_data);
    crow::mustache::context ctx;
    std::vector<crow::mustache::context> items;
    if (json_value.t() == crow::json::type::Object && json_value.has("bookmarks"))
    {
        const auto &arr = json_value["bookmarks"];
        if (arr.t() == crow::json::type::List)
        {
            for (const auto &key : arr.lo())
            {
                if (key.t() == crow::json::type::Null)
                    continue;
                crow::mustache::context item_ctx;
                item_ctx["tag"] = key.has("tag") ? std::string(key["tag"].s()) : "";
                item_ctx["url"] = key.has("url") ? std::string(key["url"].s()) : "";
                item_ctx["title"] = key.has("title") ? std::string(key["title"].s()) : "";
                items.push_back(item_ctx);
            }
        }
    }
    ctx["items"] = std::move(items);
    return ctx;
}
