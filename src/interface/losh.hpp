#pragma once

#include <vector>
#include <string>
#include <map>

class losh {
public:
	losh(int argc, char** args);

	std::wstring view();

	bool is(std::wstring name);

	bool hasnt();

	bool has_static();

	std::wstring get_static();

	bool has_bool(std::wstring key);

	bool get_bool(std::wstring key);

	bool has_string(std::wstring key);

	std::wstring get_string(std::wstring key);

private:
	std::vector<std::wstring> static_args;
	std::map<std::wstring, bool> bool_args;
	std::map<std::wstring, std::wstring> string_args;

	int pointer = 0;
};