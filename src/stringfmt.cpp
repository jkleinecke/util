#include "stringfmt.h"

#include <cstdarg>
#include <memory>

std::string stringfmt(const char* format, ...)
{
	va_list args;
	va_start(args, format);
#ifndef _MSC_VER

	//GCC generates warning for valid use of snprintf to get
	//size of result string. We suppress warning with below macro.
#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
#endif

	size_t size = std::snprintf(nullptr, 0, format, args) + 1; // Extra space for '\0'

#ifdef __GNUC__
# pragma GCC diagnostic pop
#endif

	std::unique_ptr<char[]> buf(new char[size]);
	std::vsnprintf(buf.get(), size, format, args);
	return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
#else
	int size = _vscprintf(format, args);
	std::string result(++size, 0);
	vsnprintf_s((char*)result.data(), size, _TRUNCATE, format, args);
	return result;
#endif
	va_end(args);
}