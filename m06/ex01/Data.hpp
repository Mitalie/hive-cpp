#pragma once

struct Data
{
	~Data() = default;
	Data() = default;
	Data(const Data &) = default;
	Data &operator=(const Data &) = default;

	int i;
	double *dp;
};
