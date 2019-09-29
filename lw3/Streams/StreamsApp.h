#pragma once
#include <variant>
#include <string>
#include <vector>

using namespace std;

enum class Option
{
	Encrypt,
	Decrypt,
	Compress,
	Decompress,
};

struct OptionWithKey
{
	Option option;
	unsigned key;
};

struct OptionWithoutKey
{
	Option option;
};

using OptionsVector = std::vector<std::variant<OptionWithKey, OptionWithoutKey>>;

void RunProgram(const OptionsVector& options, const string& inputFileName, const string& outputFileName);