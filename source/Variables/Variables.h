#ifndef VARIABLES_H
#define VARIABLES_H

#include "Text.h"

namespace Jui {

	class Variable : public Canvas {
		Q_OBJECT

	public:
		Variable(QWidget *parent);
		void parent_(QWidget *parent);
		void label_(QString txt);
		void text_(QString val);

		void connectOnChange(const QObject *receiver, const char *method);

	signals:
		void changed();

	private:
		PureText *label, *valText;
	};

	// Vbool ///////////////////////////////////////////////

	class Vbool : public Variable {
	public:
		Vbool();
		void operator =(bool b);
		operator bool();
	private:
		bool reference;
	};

	// Vint ///////////////////////////////////////////////

	class Vint : public Variable {
	public:
		Vint();
		void operator =(int i);
		operator int();
	private:
		int reference;
	};
}

#endif