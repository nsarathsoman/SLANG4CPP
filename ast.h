#include "common.h"
#include "codegen.h"
#include "context.h"

#ifndef AST_INCLUDED
#define AST_INCLUDED

class Expression
{

public:
   virtual SymbolInfo *evaluate(Runtime_Context *ctx) = 0;
	virtual Value *codegen() = 0;
	virtual TypeInfo typecheck(Compilation_Context *ctx) = 0;
	virtual TypeInfo get_type() = 0;
};

class BooleanConstant: public Expression
{
	SymbolInfo *info;

public:
	BooleanConstant(bool val);
	SymbolInfo *evaluate(Runtime_Context *ctx);
	TypeInfo typecheck(Compilation_Context *ctx);
	TypeInfo get_type();
};

class NumericConstant : public Expression
{

	SymbolInfo *info;

public:
	NumericConstant(double _value);
	SymbolInfo *evaluate(Runtime_Context *ctx);
	TypeInfo typecheck(Compilation_Context *ctx);
	TypeInfo get_type();
};


class StringLiteral : public Expression
{

	SymbolInfo *info;

public:
	StringLiteral(std::string _value);
	SymbolInfo *evaluate(Runtime_Context *ctx);
	TypeInfo typecheck(Compilation_Context *ctx);
	TypeInfo get_type();
};


class Variable:public Expression
{
   std::string name;
   TypeInfo type;

public:

   Variable(SymbolInfo *info);
   Variable(Compilation_Context *ctx, std::string _name, double _value);
   Variable(Compilation_Context *ctx, std::string _name, std::string _value);
   Variable(Compilation_Context *ctx, std::string _name, bool _value);
   std::string get_name();
   SymbolInfo *evaluate(Runtime_Context *ctx);
	TypeInfo typecheck(Compilation_Context *ctx);
	TypeInfo get_type();
    
};

class BinaryPlus:public Expression
{
   Expression *exp1, *exp2;
   TypeInfo type;

public:
   BinaryPlus(Expression *e1,Expression *e2);
   SymbolInfo *evaluate(Runtime_Context *ctx);
	TypeInfo typecheck(Compilation_Context *ctx);
	TypeInfo get_type();
   
};

class BinaryMinus:public Expression
{
   Expression *exp1, *exp2;
   TypeInfo type;

public:
   BinaryMinus(Expression *e1,Expression *e2);
   SymbolInfo *evaluate(Runtime_Context *ctx);
	TypeInfo typecheck(Compilation_Context *ctx);
	TypeInfo get_type();
   
};

class Mult:public Expression
{
   Expression *exp1, *exp2;
   TypeInfo type;

public:
   Mult(Expression *e1,Expression *e2);
   SymbolInfo *evaluate(Runtime_Context *ctx);
	TypeInfo typecheck(Compilation_Context *ctx);
	TypeInfo get_type();
   
};

class Div:public Expression
{
   Expression *exp1, *exp2;
   TypeInfo type;

public:
   Div(Expression *e1,Expression *e2);
   SymbolInfo *evaluate(Runtime_Context *ctx);
	TypeInfo typecheck(Compilation_Context *ctx);
	TypeInfo get_type();
   
};

class UnaryPlus:public Expression
{
   Expression *exp1;
   TypeInfo type;

public:
   UnaryPlus(Expression *e1);
   SymbolInfo *evaluate(Runtime_Context *ctx);
	TypeInfo typecheck(Compilation_Context *ctx);
	TypeInfo get_type();

};


class UnaryMinus:public Expression
{
   Expression *exp1;
   TypeInfo type;

public:
   UnaryMinus(Expression *e1);
   SymbolInfo *evaluate(Runtime_Context *ctx);
	TypeInfo typecheck(Compilation_Context *ctx);
	TypeInfo get_type();

};


#endif
