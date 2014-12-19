#include <Game/Display/WindowGameConnect.hpp>
#include <Game/Entities/Profile.hpp>
#include <Engine/Graphics/Layout.hpp>
#include <Engine/Graphics/Colors.hpp>
#include <Game/Config/Globals.hpp>
#include <Engine/InputManager.hpp>

WindowGameConnect::WindowGameConnect()
{
	int width  = 50;
	int height = 20;

	int windowx = Layout::screenWidth/2  - width/2;
	int windowy = Layout::screenHeight/2 - height/2;

	this->main = new Window(windowx,
	                        windowy,
	                        width,
	                        height);

	if (Globals::Profiles::current->settings.screen.show_borders)
	{
		this->main->borders(Globals::Profiles::current->settings.screen.fancy_borders ?
		                    Window::BORDER_FANCY :
		                    Window::BORDER_REGULAR);
	}

	Window* win;

	// Help
	win = new Window(this->main, 0, 0, WINDOW_FILL, WINDOW_FILL);
	this->windows.push_back(win);
}
void WindowGameConnect::run()
{
	int activatedIndex = 0;

	while (true)
	{
		// Refreshing Windows
		this->main->clear();
		this->windows[activatedIndex]->clear();

		this->main->print(((activatedIndex == 0) ?
		                   "(Help)" :
		                   " Help "),
		                  2,
		                  0,
		                  ((activatedIndex == 0) ?
		                   Globals::Profiles::current->settings.theme.textbox :
		                   Globals::Profiles::current->settings.theme.hilite_text));

		// HACK TO AVOID THE BORDERS FROM BEING
		// BOLD. GOTTA SOLVE THIS MISTERY.
		Colors::pairActivate(this->main->win, Globals::Profiles::current->settings.theme.text);

		// Help Window
		if (activatedIndex == 0)
		{
			this->windows[0]->print_multiline("yetris: customizable Tetris(tm) clone\n"
			                                  "        for the terminal.\n",
			                                  1, 1,
			                                  Globals::Profiles::current->settings.theme.text);

			this->windows[0]->print_multiline("Controls:\n",
			                                  1, 4, Globals::Profiles::current->settings.theme.hilite_text);

			this->windows[0]->print_multiline(" Move Left\n"
			                                  " Move Right\n"
			                                  " Soft Drop\n"
			                                  " Hard Drop\n"
			                                  " Hold Piece\n"
			                                  " Rotate Clockwise\n"
			                                  " Rotate Counterclockwise\n"
			                                  " Show Help\n"
			                                  " Pause\n"
			                                  " Quit Anytime\n",
			                                  11, 4,
			                                  Globals::Profiles::current->settings.theme.hilite_text);

			this->windows[0]->print_multiline(InputManager::keyToString(InputManager::getBind("left")) + "\n" +
			                                  InputManager::keyToString(InputManager::getBind("right")) + "\n" +
			                                  InputManager::keyToString(InputManager::getBind("down")) + "\n" +
			                                  InputManager::keyToString(InputManager::getBind("drop")) + "\n" +
			                                  InputManager::keyToString(InputManager::getBind("hold")) + "\n" +
			                                  InputManager::keyToString(InputManager::getBind("rotate_clockwise")) + "\n" +
			                                  InputManager::keyToString(InputManager::getBind("rotate_counterclockwise")) + "\n" +
			                                  InputManager::keyToString(InputManager::getBind("rotate_180")) + "\n" +
			                                  InputManager::keyToString(InputManager::getBind("help")) + "\n" +
			                                  InputManager::keyToString(InputManager::getBind("pause")) + "\n" +
			                                  InputManager::keyToString(InputManager::getBind("quit")) + "\n",
			                                  37, 4,
			                                  Globals::Profiles::current->settings.theme.text);

			this->windows[0]->print_multiline("Your settings and scores are stored at:\n",
			                                  1, 16,
			                                  Globals::Profiles::current->settings.theme.text);

			this->windows[0]->print_multiline("~/.local/share/yetris/" + Globals::Profiles::current->name,
			                                  0, 17,
			                                  Globals::Profiles::current->settings.theme.hilite_text);
		}		

		this->windows[activatedIndex]->refresh();
		this->main->refresh();
		refresh();

		// Getting Input
		InputManager::update();

		if (InputManager::isPressed("quit") ||
		         InputManager::isPressed(KEY_ENTER) ||
		         InputManager::isPressed('\n'))
			return;
	}
}

