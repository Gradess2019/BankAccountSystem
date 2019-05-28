#include "Application.h"
#include <windows.h>
#include "User.h"
#include "GUI.h"
int main()
{
	Application* application = new Application();
	application->Start();
	return 0;
}

void Application::Start()
{
	User* user = new User();
	GUI* gui = new GUI(user);
}