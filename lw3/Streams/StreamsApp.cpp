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

	for (size_t i = 0; i < options.size(); i++)
	{
		if (std::holds_alternative<OptionWithKey>(options[i]))
		{
			OptionWithKey optionWithKey = std::get<OptionWithKey>(options[i]);

			if (optionWithKey.option == Option::Encrypt)
			{
				outputFile = make_unique<CEncryptionOutputStream>(move(outputFile), optionWithKey.key);
			}
			else if (optionWithKey.option == Option::Decrypt)
			{
				inputFile = make_unique<CDecryptionInputStream>(move(inputFile), optionWithKey.key);
			}
		}
		else if (std::holds_alternative<OptionWithoutKey>(options[i]))
		{
			OptionWithoutKey optionWithoutKey = std::get<OptionWithoutKey>(options[i]);

			if (optionWithoutKey.option == Option::Compress)
			{
				outputFile = make_unique<CCompressedOutputStream>(move(outputFile));
			}
			else if (optionWithoutKey.option == Option::Decompress)
			{
				inputFile = make_unique<CDecompressedInputStream>(move(inputFile));
			}
		}
	}

	while (!inputFile->IsEOF())
	{		
		outputFile->WriteByte(inputFile->ReadByte());
	}
}
