cmake_minimum_required(VERSION 3.10)
project(SimpleLanguageInterpreter)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)

add_executable(SimpleLanguageInterpreter main.cpp src/lexer/Lexer.cpp src/lexer/Lexer.h src/scanner/Scanner.cpp src/scanner/Scanner.h src/token/Token.cpp src/token/Token.h src/scanner/Position.h src/parser/Parser.cpp src/parser/Parser.h)