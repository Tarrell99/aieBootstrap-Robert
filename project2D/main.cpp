#include "Application2D.h"
#include"DragonRPG.h"
int main() {
	
	// allocation
	auto app = new DragonRPG_Application();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}