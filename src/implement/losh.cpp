#include "codec.hpp"
#include "losh.hpp"

losh::losh(int argc, char** args) {
	for (int i = 1; i < argc; i += 1) {
		std::wstring arg = decode(args[i], codec_type::UTF_8);

		if (arg.find(L'=') != std::wstring::npos) {
			int index = arg.find(L'=');
			std::wstring front = arg.substr(0, index);
			std::wstring end = arg.substr(index + 1);

			if (front == L"") {
				if (end[0] == L'!') {
					this->bool_args[end.substr(1)] = false;
				}
				else {
					this->bool_args[end] = true;
				}
			}
			else {
				this->string_args[front] = end;
			}
		}
		else if (arg[0] == L'≠') {
			this->bool_args[arg.substr(1)] = false;
		}
		else {
			this->static_args.push_back(arg);
		}
	}
}

std::wstring losh::view() {
	std::wstring result;
	for (auto arg : this->static_args) {
		result += arg + L" ";
	}
	for (auto pair : this->bool_args) {
		result += (pair.second ? L"=" : L"≠") + pair.first + L" ";
	}
	for (auto pair : this->string_args) {
		result += pair.first + L"=" + pair.second + L" ";
	}
	return result;
}

bool losh::is(std::wstring name) {
	bool result = false;
	if (this->has_static() && this->static_args[pointer] == name) {
		result = true;
		pointer += 1;
	}
	return result;
}

bool losh::hasnt() {
	bool result;
	if (this->pointer >= this->static_args.size()) {
		result = true;
	}
	else {
		result = false;
	}
	return result;
}

bool losh::has_static() {
	if (this->pointer >= this->static_args.size()) {
		return false;
	}
	else {
		return true;
	}
}

std::wstring losh::get_static() { // next
	return this->static_args[this->pointer++]; // ++
}


bool losh::has_bool(std::wstring key) {
	if (this->bool_args.find(key) != this->bool_args.end()) {
		return true;
	}
	else {
		return false;
	}
}

bool losh::get_bool(std::wstring key) {
	return this->bool_args[key];
}

bool losh::has_string(std::wstring key) {
	if (this->string_args.find(key) != this->string_args.end()) {
		return true;
	}
	else {
		return false;
	}
}

std::wstring losh::get_string(std::wstring key) {
	return this->string_args[key];
}