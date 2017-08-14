
#pragma once

#include "Boolean.hpp"
#include <memory>

namespace Lpp{

std::unique_ptr<Boolean> logicalAnd(
	Pointer<const Boolean> _left, 
	Pointer<const Boolean> _right);

class BooleanAnd final : public Boolean{
public:
	BooleanAnd(
		Pointer<const Boolean> _left, 
		Pointer<const Boolean> _right);

	bool value() const final override;

private:
	const Pointer<const Boolean> m_left;
	const Pointer<const Boolean> m_right;
};

}
