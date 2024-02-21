// cgt215_lab6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

bool inRange(Color c) { //Checks pixel color to be within a certain range of RGB values.
	int rMin(30);
	int rMax(150);
	int gMin(210);
	int gMax(225);
	int bMin(20);
	int bMax(125);

	if (((c.r >= rMin) && (c.r <= rMax)) && ((c.g >= gMin) && (c.g <= gMax)) && ((c.b >= bMin) && (c.b <= bMax))) {
		return true;
	} else { return false; }
}

int main() {
	string background = "images1/backgrounds/prague.png";
	string foreground = "images1/characters/yoda.png";

	Texture backgroundTex;
	if (!backgroundTex.loadFromFile(background)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Texture foregroundTex;
	if (!foregroundTex.loadFromFile(foreground)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}

	Image backgroundImage;
	backgroundImage = backgroundTex.copyToImage();
	Image foregroundImage;
	foregroundImage = foregroundTex.copyToImage();
	Vector2u size = backgroundImage.getSize();
	for (int y = 0; y < size.y; y++) {
		for (int x = 0; x < size.x; x++) {
			if (inRange(foregroundImage.getPixel(x, y))) { //If pixel is within the range of RGB values, it is replaced.
				Color c = backgroundImage.getPixel(x, y);
				foregroundImage.setPixel(x, y, c);
			}
		}
	}

	RenderWindow window(VideoMode(1024, 768), "Here's the output");
	Sprite charaSpr;
	Texture charaTex;

	charaTex.loadFromImage(foregroundImage);
	charaSpr.setTexture(charaTex);
	window.clear();
	window.draw(charaSpr);
	window.display();
	while (true);
}

