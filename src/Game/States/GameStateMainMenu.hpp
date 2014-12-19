#ifndef GAMESTATEMAINMENU_H_DEFINED
#define GAMESTATEMAINMENU_H_DEFINED

#include <Engine/Flow/GameState.hpp>
#include <Game/Display/Layouts/LayoutMainMenu.hpp>
#include <Engine/Graphics/Widgets/Menu.hpp>
#include <Game/Display/WindowGameHelp.hpp>
#include <Game/Display/WindowGameConnect.hpp>

/// The Main Menu.
///
class GameStateMainMenu: public GameState
{
	friend class LayoutMainMenu;

public:
	GameStateMainMenu();
	virtual ~GameStateMainMenu();

    void load(int stack=0);

    int unload();

	GameState::StateCode update();

    void draw();

private:
	LayoutMainMenu* layout;

	/// The main menu.
	Menu* menu;

	Menu* menuSinglePlayer;
	bool menuSinglePlayerActivated;

	Menu* menuDoublePlayer;
	bool menuDoublePlayerActivated;

	Menu* menuGameSettings;
	bool menuGameSettingsActivated;

	Menu* menuGUIOptions;
	bool menuGUIOptionsActivated;

	Menu* menuProfiles;
	bool menuProfilesActivated;

	Menu* menuControls;
	bool menuControlsActivated;

	WindowGameHelp* helpWindows;
	WindowGameConnect* connectWindows;

	// easily create internal menus
	void createMainMenu();
	void createSinglePlayerMenu();
	void createDoublePlayerMenu();
	void createGameSettingsMenu();
	void createGUIOptionsMenu();
	void createControlsMenu();
	void createProfilesMenu();
	void saveSettingsMenuOptions();
	void saveSettingsMenuSinglePlayer();
	void saveSettingsMenuDoublePlayer();
};

#endif //GAMESTATEMAINMENU_H_DEFINED

