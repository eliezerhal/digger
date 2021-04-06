#include "Controller.h"
#include <thread>

int main()
{
	Controller& c = Controller::getInstance();
	c.loading();
}
