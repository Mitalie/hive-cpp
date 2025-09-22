#include <exception>
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

int replace_main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: replace <infile> <to_replace> <replacement>\n";
		return 2;
	}
	std::string infile(argv[1]);
	std::string outfile = infile + ".replace";
	std::string to_match(argv[2]);
	std::string replacement(argv[3]);
	if (!file_replace(infile, outfile, to_match, replacement))
		return 1;
	return 0;
}

int main(int argc, char **argv)
{
	try
	{
		return replace_main(argc, argv);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	catch (...)
	{
		std::cerr << "Unknown exception" << std::endl;
		return 1;
	}
}
