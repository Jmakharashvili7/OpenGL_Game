#pragma once
#ifndef GLUTCALLBACKS.H
#define GLUTCALLBACKS

class HelloGL;

namespace GLUTCallbacks
{
	void Init(HelloGL* gl);
	void Display();
	void Timer(int preferredRefresh);
	void Keyboard(unsigned char key, int x, int y);
}
#endif // GLUTCALLBACKS.H

