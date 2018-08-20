#include"StartScene.h"
#include"StartButtonObject.h"
#include"EndButtonObject.h"
#include"BackgroundObject.h"
namespace View {
	StartScene::StartScene() {
		BackgroundObject*bg = new BackgroundObject(4, Point(0, 0), "smallStart3.png");
		StartButtonObject*start = new StartButtonObject(
			1,
			Point(150, 100),
			"startbutton1.png",
			"startbutton2.png"
		);
		EndButtonObject*end = new EndButtonObject(
			2,
			Point(450, 100),
			"exitgame1.png",
			"exitgame2.png"
		);
		addObject(bg);
		addObject(start);
		addObject(end);
	}
}