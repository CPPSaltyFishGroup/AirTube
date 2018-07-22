#include"EndScene.h"
#include"StartButtonObject.h"
#include"EndButtonObject.h"
#include"BackgroundObject.h"
#include"TextObject.h"
namespace View {
	EndScene::EndScene() {
		BackgroundObject*bg = new BackgroundObject(4, Point(0, 0), "Start.png");
		StartButtonObject*restart = new StartButtonObject(
			1,
			Point(150, 100),
			"restart1.png",
			"restart2.png"
		);
		EndButtonObject*end = new EndButtonObject(
			2,
			Point(450, 100),
			"endgame1.png",
			"endgame2.png"
		);
		TextObject*text = new TextObject(-12234, Point(150, 600));
		text->text = "Score:10086!!!!!!!!!!!!!!";
		addObject(bg);
		addObject(restart);
		addObject(end);
		addObject(text);
	}
}