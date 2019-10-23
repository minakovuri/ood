#pragma once
#include "../History.h"
#include "IParagraph.h"

class CParagraph : public IParagraph
{
public:
	CParagraph() = default;
	CParagraph(const std::string& text);

	std::string GetText() const override;
	void SetText(const std::string& text) override;

private:
	std::string m_text;
};
