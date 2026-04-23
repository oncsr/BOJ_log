#include "pancakecookie.h"

PanCakeCookie::PanCakeCookie(int w, int h, int maxC, int u, int d) {
	//TODO
	this->w = w;
	this->h = h;
	this->maxC = maxC;
	this->curC = maxC;
	this->u = u;
	this->d = d;

	this->x = 0, this->y = 0, this->t = 0, this->score = 0;
}

int PanCakeCookie::getX() { return this->x; }
int PanCakeCookie::getY() { return this->y; }
int PanCakeCookie::getU() { return this->u; }
int PanCakeCookie::getD() { return this->d; }
int PanCakeCookie::getScore() { return this->score; }
int PanCakeCookie::getC() { return this->curC; }

void PanCakeCookie::reset() {
	// TODO 
	this->x = 0, this->y = 0, this->score = 0;
	this->t = 0, this->curC = maxC;
}

void PanCakeCookie::setU(int x) {
	// TODO 
	if (x >= 1 && x <= 1000) {
		this->u = x;
		this->reset();
	}
}

void PanCakeCookie::setD(int x) {
	// TODO
	if (x >= 1 && x <= 1000) {
		this->d = x;
		this->reset();
	}
}

void PanCakeCookie::setC(int x) {
	// TODO
	if (x >= 1 && x <= 1000) {
		this->maxC = x;
		this->reset();
	}
}

void PanCakeCookie::setT(int t) {

	// TODO
	if (t >= 0 && t < w) {
		this->reset();
		this->t = t;
		for (int i = 0; i < t; i++) {
			if (this->curC) {
				this->curC--;
				this->x++;
				this->y += this->u;
				if (this->y >= h)	this->y = h;
				this->score += this->y;
			}
			else {
				this->curC++;
				this->x++;
				this->y -= this->d;
				if (this->y < 0)	this->y = 0;
				this->score += this->y;
			}
		}
	}
}