#include "../../catch.hpp"
#include "../slides/shapes/styles/ShapeGroupFillStyle.h"
#include "../slides/shapes/styles/ShapeGroupOutlineStyle.h"
#include "../slides/shapes/styles/SimpleShapeFillStyle.h"
#include "../slides/shapes/styles/SimpleShapeOutlineStyle.h"
#include "Colors.h"
#include <vector>

using namespace std;

class CMockShape : public IShape
{
public:
	CMockShape()
		: m_outlineStyle(std::make_shared<CSimpleShapeOutlineStyle>(true, Colors::Black, 1))
		, m_fillStyle(std::make_shared<CSimpleShapeFillStyle>(true, Colors::White))
	{
		// TODO: подумать, можно ли как-то несложно избавиться от зависимости от CSimpleShapeFillStyle и CSimpleShapeOutlineStyle
	}

	RectD GetFrame() final
	{
		return RectD{};
	}

	void SetFrame(const RectD& rect) final {}

	std::shared_ptr<IOutlineStyle> GetOutlineStyle() final
	{
		return m_outlineStyle;
	}

	std::shared_ptr<const IOutlineStyle> GetOutlineStyle() const final
	{
		return m_outlineStyle;
	}

	std::shared_ptr<IStyle> GetFillStyle() final
	{
		return m_fillStyle;
	}

	std::shared_ptr<const IStyle> GetFillStyle() const final
	{
		return m_fillStyle;
	}

	/* --- недоступные методы --- */
	size_t GetShapesCount() const final
	{
		return size_t();
	}

	void InsertShape(std::shared_ptr<IShape> shape, size_t position = std::numeric_limits<size_t>::max()) final {}

	std::shared_ptr<IShape> GetShapeAtIndex(size_t index) const final
	{
		return std::shared_ptr<IShape>();
	}

	void RemoveShapeAtIndex(size_t index) final {}

private:
	std::shared_ptr<IOutlineStyle> m_outlineStyle;
	std::shared_ptr<IStyle> m_fillStyle;
};

class CMockShapeGroup : public IShape
{
public:
	size_t GetShapesCount() const final
	{
		return m_shapes.size();
	}

	void InsertShape(std::shared_ptr<IShape> shape, size_t position = std::numeric_limits<size_t>::max()) final
	{
		if (position >= GetShapesCount())
		{
			m_shapes.push_back(shape);
		}
		else
		{
			m_shapes.insert(m_shapes.begin() + position, shape);
		}
	}

	std::shared_ptr<IShape> GetShapeAtIndex(size_t index) const final
	{
		return m_shapes.at(index);
	}

	void RemoveShapeAtIndex(size_t index) final {}

	/* --- недоступные методы */
	RectD GetFrame() final
	{
		return RectD{};
	}

	void SetFrame(const RectD& rect) final {}

	std::shared_ptr<IOutlineStyle> GetOutlineStyle() final
	{
		return std::shared_ptr<IOutlineStyle>();
	}

	std::shared_ptr<const IOutlineStyle> GetOutlineStyle() const final
	{
		return std::shared_ptr<IOutlineStyle>();
	}

	std::shared_ptr<IStyle> GetFillStyle() final
	{
		return std::shared_ptr<IStyle>();
	}

	std::shared_ptr<const IStyle> GetFillStyle() const final
	{
		return std::shared_ptr<IStyle>();
	}

private:
	vector<std::shared_ptr<IShape>> m_shapes;
};

/* --- fill style tests --- */
TEST_CASE("get undefined fill color of shape group")
{
	shared_ptr<IShape> shape1 = make_shared<CMockShape>();
	shape1->GetFillStyle()->SetColor(Colors::Red);

	shared_ptr<IShape> shape2 = make_shared<CMockShape>();
	shape2->GetFillStyle()->SetColor(Colors::Yellow);

	shared_ptr<IShape> shapeGroup = make_shared<CMockShapeGroup>();
	shapeGroup->InsertShape(shape1);
	shapeGroup->InsertShape(shape2);

	CShapeGroupFillStyle groupFillStyle(shapeGroup);

	CHECK(groupFillStyle.GetColor() == nullopt);
}

TEST_CASE("get fill color of red filled shape group")
{
	shared_ptr<IShape> shape1 = make_shared<CMockShape>();
	shape1->GetFillStyle()->SetColor(Colors::Red);

	shared_ptr<IShape> shape2 = make_shared<CMockShape>();
	shape2->GetFillStyle()->SetColor(Colors::Red);

	shared_ptr<IShape> shapeGroup = make_shared<CMockShapeGroup>();
	shapeGroup->InsertShape(shape1);
	shapeGroup->InsertShape(shape2);

	CShapeGroupFillStyle groupFillStyle(shapeGroup);

	CHECK(groupFillStyle.GetColor() == Colors::Red);
}

TEST_CASE("get undefined fill style enabled of shape group")
{
	shared_ptr<IShape> shape1 = make_shared<CMockShape>();
	shape1->GetFillStyle()->SetEnabled(false);

	shared_ptr<IShape> shape2 = make_shared<CMockShape>();
	shape2->GetFillStyle()->SetEnabled(true);

	shared_ptr<IShape> shapeGroup = make_shared<CMockShapeGroup>();
	shapeGroup->InsertShape(shape1);
	shapeGroup->InsertShape(shape2);

	CShapeGroupFillStyle groupFillStyle(shapeGroup);

	CHECK(groupFillStyle.IsEnabled() == nullopt);
}

TEST_CASE("get fill style enabled flag of shape group")
{
	shared_ptr<IShape> shape1 = make_shared<CMockShape>();
	shape1->GetFillStyle()->SetEnabled(true);

	shared_ptr<IShape> shape2 = make_shared<CMockShape>();
	shape2->GetFillStyle()->SetEnabled(true);

	shared_ptr<IShape> shapeGroup = make_shared<CMockShapeGroup>();
	shapeGroup->InsertShape(shape1);
	shapeGroup->InsertShape(shape2);

	CShapeGroupFillStyle groupFillStyle(shapeGroup);

	CHECK(groupFillStyle.IsEnabled() == true);
}

TEST_CASE("get fill styles options of empty group")
{
	shared_ptr<IShape> shapeGroup = make_shared<CMockShapeGroup>();
	CShapeGroupFillStyle groupFillStyle(shapeGroup);
	CHECK(groupFillStyle.GetColor() == nullopt);
	CHECK(groupFillStyle.IsEnabled() == nullopt);
}

TEST_CASE("set fill color of shape group")
{
	shared_ptr<IShape> shape1 = make_shared<CMockShape>();
	shared_ptr<IShape> shape2 = make_shared<CMockShape>();

	shared_ptr<IShape> shapeGroup = make_shared<CMockShapeGroup>();
	shapeGroup->InsertShape(shape1);
	shapeGroup->InsertShape(shape2);

	CShapeGroupFillStyle groupFillStyle(shapeGroup);
	groupFillStyle.SetColor(Colors::Pink);

	CHECK(shape1->GetFillStyle()->GetColor() == Colors::Pink);
	CHECK(shape2->GetFillStyle()->GetColor() == Colors::Pink);
}

TEST_CASE("set fill style enabled of shape group")
{
	shared_ptr<IShape> shape1 = make_shared<CMockShape>();
	shape1->GetFillStyle()->SetEnabled(false);

	shared_ptr<IShape> shape2 = make_shared<CMockShape>();
	shape2->GetFillStyle()->SetEnabled(false);

	shared_ptr<IShape> shapeGroup = make_shared<CMockShapeGroup>();
	shapeGroup->InsertShape(shape1);
	shapeGroup->InsertShape(shape2);

	CShapeGroupFillStyle groupFillStyle(shapeGroup);
	groupFillStyle.SetEnabled(true);

	CHECK(*shape1->GetFillStyle()->IsEnabled());
	CHECK(*shape2->GetFillStyle()->IsEnabled());
}

/* --- outline style tests --- */
TEST_CASE("get undefined outline color of shape group")
{
	shared_ptr<IShape> shape1 = make_shared<CMockShape>();
	shape1->GetOutlineStyle()->SetColor(Colors::Red);

	shared_ptr<IShape> shape2 = make_shared<CMockShape>();
	shape2->GetOutlineStyle()->SetColor(Colors::Yellow);

	shared_ptr<IShape> shapeGroup = make_shared<CMockShapeGroup>();
	shapeGroup->InsertShape(shape1);
	shapeGroup->InsertShape(shape2);

	CShapeGroupOutlineStyle groupOutlineStyle(shapeGroup);
	CHECK(groupOutlineStyle.GetColor() == nullopt);
}

TEST_CASE("get shape group outline color")
{
	shared_ptr<IShape> shape1 = make_shared<CMockShape>();
	shape1->GetOutlineStyle()->SetColor(Colors::Red);

	shared_ptr<IShape> shape2 = make_shared<CMockShape>();
	shape2->GetOutlineStyle()->SetColor(Colors::Red);

	shared_ptr<IShape> shapeGroup = make_shared<CMockShapeGroup>();
	shapeGroup->InsertShape(shape1);
	shapeGroup->InsertShape(shape2);

	CShapeGroupOutlineStyle groupOutlineStyle(shapeGroup);
	CHECK(groupOutlineStyle.GetColor() == Colors::Red);
}

TEST_CASE("get undefined outline style enabled of shape group")
{
	shared_ptr<IShape> shape1 = make_shared<CMockShape>();
	shape1->GetOutlineStyle()->SetEnabled(false);

	shared_ptr<IShape> shape2 = make_shared<CMockShape>();
	shape2->GetOutlineStyle()->SetEnabled(true);

	shared_ptr<IShape> shapeGroup = make_shared<CMockShapeGroup>();
	shapeGroup->InsertShape(shape1);
	shapeGroup->InsertShape(shape2);

	CShapeGroupOutlineStyle groupOutlineStyle(shapeGroup);
	CHECK(groupOutlineStyle.IsEnabled() == nullopt);
}

TEST_CASE("get outline style enabled flag of shape group")
{
	shared_ptr<IShape> shape1 = make_shared<CMockShape>();
	shape1->GetOutlineStyle()->SetEnabled(true);

	shared_ptr<IShape> shape2 = make_shared<CMockShape>();
	shape2->GetOutlineStyle()->SetEnabled(true);

	shared_ptr<IShape> shapeGroup = make_shared<CMockShapeGroup>();
	shapeGroup->InsertShape(shape1);
	shapeGroup->InsertShape(shape2);

	CShapeGroupOutlineStyle groupOutlineStyle(shapeGroup);
	CHECK(groupOutlineStyle.IsEnabled() == true);
}

TEST_CASE("get undefined outline style thickness of shape group")
{
	shared_ptr<IShape> shape1 = make_shared<CMockShape>();
	shape1->GetOutlineStyle()->SetThickness(2.0);

	shared_ptr<IShape> shape2 = make_shared<CMockShape>();
	shape2->GetOutlineStyle()->SetThickness(3.0);

	shared_ptr<IShape> shapeGroup = make_shared<CMockShapeGroup>();
	shapeGroup->InsertShape(shape1);
	shapeGroup->InsertShape(shape2);

	CShapeGroupOutlineStyle groupOutlineStyle(shapeGroup);
	CHECK(groupOutlineStyle.GetThickness() == nullopt);
}

TEST_CASE("get shape group outline thikness")
{
	shared_ptr<IShape> shape1 = make_shared<CMockShape>();
	shape1->GetOutlineStyle()->SetThickness(5.0);

	shared_ptr<IShape> shape2 = make_shared<CMockShape>();
	shape2->GetOutlineStyle()->SetThickness(5.0);

	shared_ptr<IShape> shapeGroup = make_shared<CMockShapeGroup>();
	shapeGroup->InsertShape(shape1);
	shapeGroup->InsertShape(shape2);

	CShapeGroupOutlineStyle groupOutlineStyle(shapeGroup);
	CHECK(groupOutlineStyle.GetThickness() == 5.0);
}

TEST_CASE("get outline styles options of empty group")
{
	shared_ptr<IShape> shapeGroup = make_shared<CMockShapeGroup>();
	CShapeGroupOutlineStyle groupOutlineStyle(shapeGroup);
	CHECK(groupOutlineStyle.GetColor() == nullopt);
	CHECK(groupOutlineStyle.IsEnabled() == nullopt);
	CHECK(groupOutlineStyle.GetThickness() == nullopt);
}

TEST_CASE("set outline color of shape group")
{
	shared_ptr<IShape> shape1 = make_shared<CMockShape>();
	shared_ptr<IShape> shape2 = make_shared<CMockShape>();

	shared_ptr<IShape> shapeGroup = make_shared<CMockShapeGroup>();
	shapeGroup->InsertShape(shape1);
	shapeGroup->InsertShape(shape2);

	CShapeGroupOutlineStyle groupOutlineStyle(shapeGroup);
	groupOutlineStyle.SetColor(Colors::Pink);

	CHECK(shape1->GetOutlineStyle()->GetColor() == Colors::Pink);
	CHECK(shape2->GetOutlineStyle()->GetColor() == Colors::Pink);
}

TEST_CASE("set outline style enabled of shape group")
{
	shared_ptr<IShape> shape1 = make_shared<CMockShape>();
	shape1->GetOutlineStyle()->SetEnabled(false);

	shared_ptr<IShape> shape2 = make_shared<CMockShape>();
	shape2->GetOutlineStyle()->SetEnabled(false);

	shared_ptr<IShape> shapeGroup = make_shared<CMockShapeGroup>();
	shapeGroup->InsertShape(shape1);
	shapeGroup->InsertShape(shape2);

	CShapeGroupOutlineStyle groupOutlineStyle(shapeGroup);
	groupOutlineStyle.SetEnabled(true);

	CHECK(*shape1->GetOutlineStyle()->IsEnabled());
	CHECK(*shape2->GetOutlineStyle()->IsEnabled());
}

TEST_CASE("set outline thickness of shape group")
{
	shared_ptr<IShape> shape1 = make_shared<CMockShape>();
	shared_ptr<IShape> shape2 = make_shared<CMockShape>();

	shared_ptr<IShape> shapeGroup = make_shared<CMockShapeGroup>();
	shapeGroup->InsertShape(shape1);
	shapeGroup->InsertShape(shape2);

	CShapeGroupOutlineStyle groupOutlineStyle(shapeGroup);
	groupOutlineStyle.SetThickness(10.0);

	CHECK(shape1->GetOutlineStyle()->GetThickness() == 10.0);
	CHECK(shape2->GetOutlineStyle()->GetThickness() == 10.0);
}
