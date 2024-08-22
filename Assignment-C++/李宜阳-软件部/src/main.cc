#include <iostream>
#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>
#include <cpr/cpr.h>
#include <unistd.h>

using json = nlohmann::json;

/**
  * @brief Read json object from path
  * @param path the path of the file
  * @return the json object
  * @author Li Yiyang
  * @date 2024-08-22
  */
auto readFromFile(const std::filesystem::path& path) -> json {
    std::ifstream file {path};
    return json::parse(file);
}

/**
  * @brief Get the url from json object and store the website
  * @param Path the json file
  * @param data the json data(containing "url")
  * @return no returns
  * @author Li Yiyang
  * @date 2024-08-22
  */
auto getWebsite(
    const std::filesystem::path& Path, json data) -> void {
    std::ofstream file {Path , std::ios::trunc | std::ios::out};
    cpr::Response response = cpr::Get(cpr::Url{
        data["url"]
    });
    file << response.text << "\n";
}

auto main() -> int {
    getWebsite("../../../../index.json", readFromFile("../../../../setting.json"));
    return 0;
}