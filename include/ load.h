#include <crow.h>
#include <fstream>

crow::json::rvalue load_bookmarks_data(){
    std::ifstream in("bookmarks.json");
    std::string json_data,line;
    bool verified;
    while (getline(in,line))
    {
        json_data+=line;
    }

    crow::json::rvalue json_value;
    json_value=crow::json::load(json_data);
    return json_value;
    
}