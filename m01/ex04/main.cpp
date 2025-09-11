#include <fstream>
#include <istream>
#include <ostream>
#include <string>

static void put_string_it(
	std::ostream &output,
	const std::string::const_iterator begin,
	const std::string::const_iterator end)
{
	std::string::const_iterator it = begin;
	while (it != end)
		output.put(*it++);
}

void replace(
	std::istream &input,
	std::ostream &output,
	const std::string &to_match,
	const std::string &replacement)
{
	if (to_match.length() == 0)
	{
		output << input.rdbuf();
		return;
	}
	std::string::const_iterator match_pos = to_match.begin();
	char input_char;
	while (input.get(input_char) && output)
	{
		if (input_char == *match_pos)
		{
			++match_pos;
			if (match_pos == to_match.end())
			{
				put_string_it(output, replacement.begin(), replacement.end());
				match_pos = to_match.begin();
			}
		}
		else
		{
			put_string_it(output, to_match.begin(), match_pos);
			output.put(input_char);
			match_pos = to_match.begin();
		}
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return 2;
	std::string filename(argv[1]);
	std::ifstream input(filename.c_str(), std::ifstream::in | std::ifstream::binary);
	filename += ".replace";
	std::ofstream output(filename.c_str(), std::ofstream::out | std::ofstream::binary);
	replace(input, output, argv[2], argv[3]);
}
