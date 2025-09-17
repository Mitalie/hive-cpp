#include <fstream>
#include <iostream>
#include <string>

#include "stream_replace.hpp"

static bool file_replace(
	const std::string &infile,
	const std::string &outfile,
	const std::string &to_match,
	const std::string &replacement)
{
	std::ifstream input(infile.c_str(), std::ifstream::in | std::ifstream::binary);
	if (!input)
	{
		std::cerr << "failed to open input file\n";
		return false;
	}
	std::ofstream output(outfile.c_str(), std::ofstream::out | std::ofstream::binary);
	if (!output)
	{
		std::cerr << "failed to open output file\n";
		return false;
	}
	stream_replace(input, output, to_match, replacement);
	if (!output)
	{
		std::cerr << "output error\n";
		return false;
	}
	if (!input.eof())
	{
		std::cerr << "input error\n";
		return false;
	}
	return true;
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	return 1;
}
