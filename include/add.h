#include "crow.h"
#include <fstream>

bool add_bookmarks(std::string name, std::string url, std::string tag)
{
    std::ifstream file("bookmarks.json");
    std::string content;
    if(file){
        content.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();
    }

     crow::json::wvalue wval;
    if(!content.empty()){
        auto parsed = crow::json::load(content);
        if(parsed){
            if(parsed.has("bookmarks") && parsed["bookmarks"].t()==crow::json::type::List){
                wval=parsed;
            }
            else{
                wval["bookmarks"]=crow::json::wvalue::list();
                if (parsed.t()==crow::json::type::Object)
                {
                    for(const auto& key : parsed.keys()){
                        if(key != "bookmarks"){
                            wval[key] = parsed[key];
                        }
                    }
                }
                
            }
        }else{
            wval["bookmarks"] = crow::json::wvalue::list();

        }
    }
    crow::json::wvalue new_bookmark;
    new_bookmark["title"] = name;
    new_bookmark["url"] = url;
    new_bookmark["tag"] = tag;
    wval["bookmarks"][wval["bookmarks"].size()] = std::move(new_bookmark);
    std::ofstream out("bookmarks.json");
    if (!out) {
        std::cerr << "Error opening bookmarks.json for writing\n";
        return false;
    }
    out << wval.dump();
    out.close();
    return true;


}
