/*
 * Copyright 2010-2017 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bx#license-bsd-2-clause
 */

#ifndef BX_COMMANDLINE_H_HEADER_GUARD
#define BX_COMMANDLINE_H_HEADER_GUARD

#include "bx.h"
#include "string.h"

namespace bx
{
	/// Reference:
	/// http://msdn.microsoft.com/en-us/library/a1y7w461.aspx
	const char* tokenizeCommandLine(const char* _commandLine, char* _buffer, uint32_t& _bufferSize, int& _argc, char* _argv[], int _maxArgvs, char _term = '\0');

	///
	class CommandLine
	{
	public:
		///
		CommandLine(int _argc, char const* const* _argv);

		///
		const char* findOption(const char* _long, const char* _default) const;

		///
		const char* findOption(const char _short, const char* _long, const char* _default) const;

		///
		const char* findOption(const char* _long, int _numParams = 1) const;

		///
		const char* findOption(const char _short, const char* _long = NULL, int _numParams = 1) const;

		///
		const char* findOption(int _skip, const char _short, const char* _long = NULL, int _numParams = 1) const;

		///
		bool hasArg(const char _short, const char* _long = NULL) const;

		///
		bool hasArg(const char* _long) const;

		///
		bool hasArg(const char*& _value, const char _short, const char* _long = NULL) const;

		///
		bool hasArg(int& _value, const char _short, const char* _long = NULL) const;

		///
		bool hasArg(unsigned int& _value, const char _short, const char* _long = NULL) const;

		///
		bool hasArg(float& _value, const char _short, const char* _long = NULL) const;

		///
		bool hasArg(double& _value, const char _short, const char* _long = NULL) const;

		///
		bool hasArg(bool& _value, const char _short, const char* _long = NULL) const;

	private:
		///
		const char* find(int _skip, const char _short, const char* _long, int _numParams) const;

		int m_argc;
		char const* const* m_argv;
	};

} // namespace bx

#endif /// BX_COMMANDLINE_H_HEADER_GUARD
