#ifndef FILES_H
#define FILES_H

#include <QDir>
#include <QUrl>
#include <QDesktopServices>
#include <QFile>
#include <QColor>
#include <QFont>
#include <QDebug>

namespace Jui
{
	// Leaf /////////////////////////////////////////////////////

	class Leaf {
	public:
		Leaf(QString key, QVariant value);
		//Leaf(QString folder, QString key, QVariant value);

		QString key();
		QVariant value();
		QVariant::Type type();

		operator QString();

	private:
		QMap<QString, QVariant> map;
	};

	// Data /////////////////////////////////////////////////////

	class Data {
	public:
		Data();
		Data(QByteArray ba);

		void add(QString key, QVariant value);
		void add(QString key, Data value);

		QVariant at(QString key);
		QList<QVariant> nodes();
		QList<QString> keys();
		QMap<QString, QVariant> map();

		void print();
		operator QByteArray();
		operator QString();

	private:
		QMap<QString, QVariant> library;

		QStringList map2string(QMap<QString, QVariant> data, int level = 0);
		int currentLevel;

	};

	// Folder /////////////////////////////////////////////////////

	class Folder {
	public:
		Folder();
		Folder(QString path);

		void make(QString name);

		void enter(QString name);
		void escape();

		QString current();
		void show();

	private:
		QDir dir;
	};

	// File /////////////////////////////////////////////////////

	class File {
	public:
		File(QString name);
		File(QString path, QString name);

		void write(QString data);
		void write(Data data);

		QByteArray read();

		void show();

	private:
		QFile file;
	};
}

#endif // FILES_H
