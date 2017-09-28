#ifndef CONFIG_H
#define CONFIG_H

#include "Core.h"
#include "Fade.h"
#include "Canvas.h"
#include "Dummies.h"
#include "Button.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTime>
#include <QDebug>


namespace Jui
{
	
	class ColorTester : public QWidget
	{
	public:
		ColorTester(QWidget *parent = 0);
	protected:
		void paintEvent(QPaintEvent *e) override;
	private:
		FadeColor backG;
		QTime startTime;
		int cnt;
	};
	
	class Config : public Canvas
	{
		Q_OBJECT
	public:
		Config(int x, int y, int width, int height);
	private:
		FadeFloat fade;
		//FadeInt fade;
		QLineEdit *text;
		Text *label;
		QWidget *colorTester;

		private slots:
		void click();
		void result();
	};
}

#endif // CONFIG_H