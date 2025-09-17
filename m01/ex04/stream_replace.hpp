#pragma once

#include <istream>
#include <ostream>
#include <string>

void stream_replace(
	std::istream &input,
	std::ostream &output,
	const std::string &to_match,
	const std::string &replacement);
