add_rules("mode.debug", "mode.release")
add_requires("nlohmann_json", "cpr")
add_packages("nlohmann_json", "cpr")

target("hw")
    add_files("src/**.cc")
    add_includedirs("src")
    set_exceptions("cxx")
    set_kind("binary")
    set_languages("cxx20")
    set_warnings("allextra")
    
