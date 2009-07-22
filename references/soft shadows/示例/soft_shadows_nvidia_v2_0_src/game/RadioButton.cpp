
// includes
#include "bleifrei/gfx/opengl.hpp"
#include "bleifrei/tex/Texture.hpp"

#include "RadioButton.hpp"

using namespace bleifrei::gfx;
using namespace bleifrei::tex;
using namespace std;

RadioButton::RadioButton(int id, int &selected, const string &text, Font *font, int x, int y, int width, int height)
	: GUIRadioButton(selected), text(text), font(font)
{
	move(x, y);
	resize(width, height);
	setId(id);
}

void RadioButton::onPaintOverlay(int absx, int absy)
{
	const int space = 3;

	if (isClicked())
		glColor4f(0.5f, 0.5f, 0.5f, 0.5f);
	else if (isMouseOver())
		glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
	else
		glColor4f(0.5f, 1.0f, 0.6f, 0.5f);

	glBegin(GL_QUADS);
		glVertex2i(absx + space, absy + space);
		glVertex2i(absx + space, absy - space + getHeight());
		glVertex2i(absx - space + getHeight(), absy - space + getHeight());
		glVertex2i(absx - space + getHeight(), absy + space);
	glEnd();

	if (isClicked())
		glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
	else if (isMouseOver())
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	else
		glColor4f(0.5f, 1.0f, 0.6f, 1.0f);

	if (isSelected()) {
		glBegin(GL_QUADS);
			glVertex2i(absx + space * 2, absy + space * 2);
			glVertex2i(absx + space * 2, absy - space * 2 + getHeight());
			glVertex2i(absx - space * 2 + getHeight(), absy - space * 2 + getHeight());
			glVertex2i(absx - space * 2 + getHeight(), absy + space * 2);
		glEnd();
	}
	glBegin(GL_LINE_LOOP);
		glVertex2i(absx + space, absy + space);
		glVertex2i(absx + space, absy - space + getHeight());
		glVertex2i(absx - space + getHeight(), absy - space + getHeight());
		glVertex2i(absx - space + getHeight(), absy + space);
	glEnd();

	glColor4f(1,1,1,1);
	Texture2::enable();
	font->bindTexture();
	font->print(absx + space + getHeight(), absy + (getHeight() - font->getHeight()) / 2, 1.0f, text);
	Texture2::disable();
}
