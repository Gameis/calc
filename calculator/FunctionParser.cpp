#include "FunctionParser.h"

bool FunctionParser::isOperation(const string & token) const
{
	return token == "+" || token == "-" || token == "*" || token == "/" || token == "^";
}

int FunctionParser::getValueOfOperation(const string & operation)
{
	if (operation == "(")
		return 1;
	if (operation == "-" || operation == "+")
		return 2;
	if (operation == "/" || operation == "*")
		return 3;
	if (operation == "^")
		return 4;
	return 0;
}

bool FunctionParser::isFunction(const string & token) const
{
	for (auto & el : *_functions)
	{
		if (el == token) return true;
	}
	return false;
}

bool FunctionParser::isDelimiter(const string & token)
{
	for (auto & el : _delims)
	{
		if (token[0] == el) return true;
	}
	return false;
}


bool FunctionParser::isWord(const string & token) const
	{
	bool isAlpha = true;
	for(auto & ch : token)
		{
		if(!isalpha(ch, _loc) && !ispunct(ch,_loc))
			{
			isAlpha = false;
			}
		}
	return isAlpha;
	}


bool FunctionParser::isNumber(const string & token) const
	{
	bool isDigit = true;
	for(auto & ch : token)
		{
		if(ch != '.' || ch != ',' || ch != '-' || !isdigit(ch,_loc))
			{
			isDigit = false;
			}
		}
	return isDigit;
	}


FunctionParser::FunctionParser()
{
	_flag = true;
	_expression = "";
	_parsedExpression = nullptr;
	_functions = nullptr;
}

FunctionParser::~FunctionParser()
{
	if (_parsedExpression != nullptr)
	{
		delete _parsedExpression;
		_parsedExpression = nullptr;
	}
	if (_functions != nullptr)
	{
		delete _functions;
		_functions = nullptr;
	}
}

FunctionParser::FunctionParser(const vector<string> & functions, const string & expression) : FunctionParser()
{
	_expression = expression;
	_functions = new vector<string>(functions);
}

void FunctionParser::setExpression(const string & expression)
{
	_expression = expression;
}

string FunctionParser::getExpression() const
{
	return _expression;
}

vector<string> & FunctionParser::getParsedExpression() const
	{
	if(_parsedExpression == nullptr)
		{
		vector<string> a;
		return a;
		}
	else return *_parsedExpression;
}

bool FunctionParser::parseExpression()
{
	if (_expression.empty())
	{
		delete _parsedExpression; _parsedExpression = nullptr; return false;
	}
	StringTokenizer * tokens = new StringTokenizer(_delims, _expression);
	_parsedExpression = new vector<string>();
	auto stk = new stack<string>();
	string prev;
	while (tokens->hasMoreTokens())
	{
		string curr = tokens->nextToken();
		if (!tokens->hasMoreTokens() && isOperation(curr))
		{
			delete _parsedExpression;
			_parsedExpression = nullptr;
			return false;
		}
		if (curr == " " || curr == "\t") continue;
		if (isFunction(curr)) stk->push(curr);
		else if (isDelimiter(curr))
		{
			if (curr == "(") stk->push(curr);
			else if (curr == ")")
			{
				while (!(stk->top() == "("))
				{
					_parsedExpression->push_back(stk->top());
					stk->pop();
					if (stk->empty())
					{
						delete _parsedExpression;
						_parsedExpression = nullptr; 
						return false;
					}
				}
				stk->pop();
				if (!stk->empty() && isFunction(stk->top()))
				{
					_parsedExpression->push_back(stk->top());
					stk->pop();
				}
			}
			else
			{
				if (curr == "-" && (prev.empty() || (isDelimiter(prev) && !(prev == ")"))))
				{
					curr = "u-";
				}
				else
				{
					while (!stk->empty() && (getValueOfOperation(curr) <= getValueOfOperation(stk->top())))
					{
						_parsedExpression->push_back(stk->top());
						stk->pop();
					}
				}
				stk->push(curr);
			}
		}
		else
		{
			if(!isWord(curr) || curr == "x")
				{
				_parsedExpression->push_back(curr);
				}
			else
				{

				delete _parsedExpression;
				_parsedExpression = nullptr;
				return false;
				}
		}
		prev = curr;
	}

	while (!stk->empty())
	{
		if (isOperation(stk->top()))
		{
			_parsedExpression->push_back(stk->top());
			stk->pop();
		}
		else
		{
			delete _parsedExpression; 
			_parsedExpression = nullptr; 
			return false;
		}
	}
	return true;
}
