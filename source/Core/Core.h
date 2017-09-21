#ifndef CORE_H
#define CORE_H

#include <QWidget>
#include <QDebug>
#include <QPainter>
#include <QMouseEvent>
#include <QVariantAnimation>

namespace Jui
{
	enum fade { out, in };
	void fadeVariant(QVariantAnimation &variable, Jui::fade fade, int duration);
}

#endif // CORE_H