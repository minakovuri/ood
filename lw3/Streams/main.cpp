#include "StreamsApp.h"
#include <iostream>

using namespace std;

const string ENCRYPT_OPTION = "--encrypt";
const string DECRYPT_OPTION = "--decrypt";
const string COMPRESS_OPTION = "--compress";
const string DECOMPRESS_OPTION = "--decompress";

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cerr << "Invalid parameters count: " << argc << ", want 2 minimum" << endl;
	}

	OptionsVector options;
	string inputFileName = argv[argc - 2];
	string outputFileName = argv[argc - 1];

	for (int i = 1; i < argc - 2;)
	{
		if (argv[i] == ENCRYPT_OPTION)
		{
			unsigned key = atoi(argv[++i]);
			OptionWithKey option = { Option::Encrypt, key };
			options.push_back(option);
		}
		else if (argv[i] == DECRYPT_OPTION)
		{
			unsigned key = atoi(argv[++i]);
			OptionWithKey option = { Option::Decrypt, key };
			options.push_back(option);
		}
		else if (argv[i] == COMPRESS_OPTION)
		{
			OptionWithoutKey option = { Option::Compress };
			options.push_back(option);
		}
		else if (argv[i] == DECOMPRESS_OPTION)
		{
			OptionWithoutKey option = { Option::Decompress };
			options.push_back(option);
		}
		else
		{
			cerr << "Unknown option: " << argv[i] << endl;
			return 1;
		}

		i++;
	}

	try
	{
		RunProgram(options, inputFileName, outputFileName);
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
		return 1;
	}

	return 0;
}
