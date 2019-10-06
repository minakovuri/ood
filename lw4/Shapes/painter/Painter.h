#pragma once
#include "../canvas/ICanvas.h"
#include "../draft/PictureDraft.h"

class CPainter
{
public:
	void DrawPicture(CPictureDraft& draft, ICanvas& canvas);
};
