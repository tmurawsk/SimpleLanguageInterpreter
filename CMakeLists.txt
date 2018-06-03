cmake_minimum_required(VERSION 3.10)
project(SimpleLanguageInterpreter)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(SimpleLanguageInterpreter main.cpp src/lexer/Lexer.cpp src/lexer/Lexer.h src/scanner/Scanner.cpp src/scanner/Scanner.h src/token/Token.cpp src/token/Token.h src/scanner/Position.h src/parser/Parser.cpp src/parser/Parser.h src/ast/Variable.cpp src/ast/Variable.h src/ast/expression/MathExpression.h src/ast/expression/AndExpr.cpp src/ast/expression/AndExpr.h src/ast/expression/RelationExpr.cpp src/ast/expression/RelationExpr.h src/ast/expression/MathExpr.cpp src/ast/expression/MathExpr.h src/ast/Variables.h src/ast/statement/Statement.h src/ast/statement/AssignStatement.cpp src/ast/statement/AssignStatement.h)