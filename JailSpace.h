#pragma once
#include "NonProperty.h"
class JailSpace : public NonProperty
{
private:

public:
	JailSpace(std::string name, int pos);
	virtual void display();
};