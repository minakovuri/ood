#include "StreamsApp.h"
#include "decorators/CCompressedOutputStream.h"
#include "decorators/CDecompressedInputStream.h"
#include "decorators/CDecryptionInputStream.h"
#include "decorators/CEncryptionOutputStream.h"
#include "inputStream/CFileInputStream.h"
#include "outputStream/CFileOutputStream.h"

void RunProgram(const OptionsVector& options, const string& inputFileName, const string& outputFileName)
{
	unique_ptr<IInputDataStream> inputFile = make_unique<CFileInputStream>(inputFileName);
	unique_ptr<IOutputDataStream> outputFile = make_unique<CFileOutputStream>(outputFileName);

	OptionsVector inputFileOptions;
	OptionsVector outputFileOptions;

	for (size_t i = 0; i < options.size(); i++)
	{
		if (std::holds_alternative<OptionWithKey>(options[i]))
		{
			OptionWithKey optionWithKey = std::get<OptionWithKey>(options[i]);

			if (optionWithKey.option == Option::Encrypt)
			{
				outputFileOptions.push_back(optionWithKey);
			}
			else if (optionWithKey.option == Option::Decrypt)
			{
				inputFileOptions.push_back(optionWithKey);
			}
		}
		else if (std::holds_alternative<OptionWithoutKey>(options[i]))
		{
			OptionWithoutKey optionWithoutKey = std::get<OptionWithoutKey>(options[i]);

			if (optionWithoutKey.option == Option::Compress)
			{
				outputFileOptions.push_back(optionWithoutKey);
			}
			else if (optionWithoutKey.option == Option::Decompress)
			{
				inputFileOptions.push_back(optionWithoutKey);
			}
		}
	}

	for (size_t i = 0; i < inputFileOptions.size(); i++)
	{
		if (std::holds_alternative<OptionWithKey>(inputFileOptions[i]))
		{
			OptionWithKey decrypt = std::get<OptionWithKey>(inputFileOptions[i]);
			inputFile = make_unique<CDecryptionInputStream>(move(inputFile), decrypt.key);
		}
		else if (std::holds_alternative<OptionWithoutKey>(inputFileOptions[i]))
		{
			inputFile = make_unique<CDecompressedInputStream>(move(inputFile));
		}
	}

	for (int i = outputFileOptions.size() - 1; i >= 0; i--)
	{
		if (std::holds_alternative<OptionWithKey>(outputFileOptions[i]))
		{
			OptionWithKey encrypt = std::get<OptionWithKey>(outputFileOptions[i]);
			outputFile = make_unique<CEncryptionOutputStream>(move(outputFile), encrypt.key);
		}
		else if (std::holds_alternative<OptionWithoutKey>(outputFileOptions[i]))
		{
			outputFile = make_unique<CCompressedOutputStream>(move(outputFile));
		}
	}

	while (!inputFile->IsEOF())
	{
		try
		{
			outputFile->WriteByte(inputFile->ReadByte());
		}
		catch (const std::exception&)
		{
		}
	}
}
