#ifndef WINDOWGAMECONNECT_H_DEFINED
#define WINDOWGAMECONNECT_H_DEFINED

#include <Engine/Graphics/Window.hpp>

#include <vector>

/// Specific Window that shows Help and other info
/// during Game.
///
class WindowGameConnect
{
public:
	WindowGameConnect();
	virtual ~WindowGameConnect() {};

	/// Updates and draws all tabs.
	void run();

private:
	Window* main;
	std::vector<Window*> windows;
};

#endif //WINDOWGAMECONNECT_H_DEFINED

