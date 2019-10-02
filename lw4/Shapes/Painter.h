#pragma once
#include "draft/PictureDraft.h"
#include "canvas/ICanvas.h"

class CPainter
{
public:
	void DraftPicture(CPictureDraft& draft, ICanvas& canvas);
};
