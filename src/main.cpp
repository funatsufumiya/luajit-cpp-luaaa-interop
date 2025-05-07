#include <iostream>
#include <fstream>
#include <string>
#include <example.h>
#include <luaaa.hpp>
#include <lua.hpp>

std::string readFile(const std::string& path) {
    std::ifstream file(path);
    if (!file) {
        throw std::runtime_error("Cannot open file: " + path);
    }
    return std::string(std::istreambuf_iterator<char>(file), 
                      std::istreambuf_iterator<char>());
}

int luaopen_example(lua_State* L) {
    luaaa::LuaClass<Calculator> calculatorClass(L, "Calculator");
    
    calculatorClass.ctor<>();
    calculatorClass.fun("add", &Calculator::add);
    calculatorClass.fun("multiply", &Calculator::multiply);
    calculatorClass.fun("greet", &Calculator::greet);
    
    return 0;
}

int main() {
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    
    // register Calculator class into global namespace using luaaa
    luaopen_example(L);
    
    try {
        std::string luaCode = readFile("scripts/test.lua");
        if (luaL_dostring(L, luaCode.c_str()) != 0) {
            std::cerr << "Error executing Lua script: " << lua_tostring(L, -1) << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    lua_close(L);
    return 0;
}
