#ifndef FILES_H
#define FILES_H

#include <QDir>
#include <QUrl>
#include <QDesktopServices>
#include <QFile>
#include <QDebug>

namespace Jui
{
	// Node /////////////////////////////////////////////////////

	class Node {
	public:
		Node();
		Node(QString key, QVariant value);

		void key(QString name);
		void value(QVariant val);
		void tabs(int n);

		operator QByteArray();
		operator QString();
		operator int();
		operator double();

	private:
		QString m_key, m_tabs;
		QVariant m_value;
	};

	// Data /////////////////////////////////////////////////////

	class Data {
	public:
		Data();

		void add(QString key, QVariant value);

		Node at(QString key);

		void print();

		operator QByteArray();

	private:
		QMap<QString, Node> library;
		int currentLevel;

		static QString level(int n);
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

		void show();

	private:
		QFile file;
	};
}

#endif // FILES_H
