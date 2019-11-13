#pragma once
#include <functional>
#include <optional>
#include "../../CommonTypes.h"

class IStyle
{
public:
	virtual std::optional<RGBAColor> GetColor() const = 0;
	virtual void SetColor(RGBAColor color) = 0;

	virtual std::optional<bool> IsEnabled() const = 0;
	virtual void SetEnabled(bool enable) = 0;

	virtual ~IStyle() = default;
};

using StyleCallback = std::function<void(IStyle&)>;
