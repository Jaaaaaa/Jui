
#include "Files.h"

namespace Jui
{
	// Node /////////////////////////////////////////////////////

	Node::Node() { m_tabs = ""; }
	Node::Node(QString key, QVariant value) : m_key(key), m_value(value) { m_tabs = ""; }

	void Node::key(QString name) { m_key = name; }
	void Node::value(QVariant val) { m_value = val; }
	void Node::tabs(int n) {
		m_tabs = "";
		for (int i = 0; i < n; i++) { m_tabs += "\t"; }
	}

	Node::operator QByteArray() {
		QString txt = m_tabs + "- " + m_key + ": " + m_value.toString() + "\n";
		return txt.toUtf8();
	}
	Node::operator QString() {
		switch (m_value.type())
		{
		case QVariant::Int:	return QString::number(m_value.toInt());
		case QVariant::Double: return QString::number(m_value.toDouble());
		default: return m_value.toString();
		}
	}
	Node::operator int() { return m_value.toInt(); }
	Node::operator double() { return m_value.toDouble(); }


	// Data /////////////////////////////////////////////////////

	Data::Data() {
		currentLevel = 1;
	}

	void Data::add(QString key, QVariant value)
	{
		Node node(key, value);
		node.tabs(currentLevel);
		library.insert(key, node);
	}

	Node Data::at(QString key) { return library.value(key); }

	Data::operator QByteArray() {
		QByteArray ba;
		ba.append("[\n");

		foreach(QString oneKey, library.keys())
		{
			//currentLevel++;
			QByteArray oneNode = at(oneKey);
			ba.append(oneNode);
			//currentLevel--;
		}
		ba.append("]");
		return ba;
	}

	void Data::print() {
		foreach(QString oneKey, library.keys())
		{
			Node node = at(oneKey);
			QByteArray baNode = node;
			qDebug() << baNode;
		}
	}

	QString Data::level(int n) {
		QString tabs = "";
		for (int i = 0; i < n; i++) { tabs += "\t"; }
		//qDebug() << "Data::level tabs:" << tabs;
		return tabs;
	}

	// Folder /////////////////////////////////////////////////////

	Folder::Folder() {
		dir = QDir::current();
	}
	Folder::Folder(QString path) {
		dir = QDir(path);
		if (!dir.exists()) { bool done = dir.mkpath(dir.path()); }
	}

	void Folder::make(QString name) { dir.mkdir(name); }

	void Folder::enter(QString name) {
		bool done = dir.cd(name);
		if (!done) { qDebug() << "Folder::enter err (" << name << ") at" << current(); }
	}
	void Folder::escape() { dir.cdUp(); }

	QString Folder::current() {
		QString currentPath = dir.path();
		//qDebug() << "Folder::current:" << currentPath;
		//QDir::setCurrent(currentPath);
		return currentPath;
	}

	void Folder::show() {
		bool done = QDesktopServices::openUrl(QUrl(current()));
	}

	// File /////////////////////////////////////////////////////

	File::File(QString name) {
		file.setFileName(name);

	}
	File::File(Folder path, QString name) {
		QDir::setCurrent(path.current());
		file.setFileName(name);
	}

	void File::write(QString data) {
		file.open(QIODevice::WriteOnly);
		file.write(data.toUtf8());
		file.close();
	}
	void File::write(Data data) {
		file.open(QIODevice::WriteOnly);
		file.write(data);
		file.close();
	}
}