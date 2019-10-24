#pragma once
#include <string>
#include "document/DocumentItem.h"

using namespace std;

string GetHtmlString(const string& str);

void SaveToHtmlFunction(const string& path, const string& title, const vector<CDocumentItem>& items);
