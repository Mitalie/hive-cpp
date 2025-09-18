#include "stream_replace.hpp"

#include <cstddef>
#include <istream>
#include <ostream>
#include <string>

void stream_replace(
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
	std::size_t match_pos = 0;
	char input_char;
	while (input.get(input_char) && output)
	{
		if (input_char == to_match[match_pos])
		{
			++match_pos;
			if (match_pos == to_match.length())
			{
				output.write(replacement.data(), replacement.length());
				match_pos = 0;
			}
		}
		else
		{
			output.write(to_match.data(), match_pos);
			output.put(input_char);
			match_pos = 0;
		}
	}
}
