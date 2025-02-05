#include "Mainwindow.h"
#include <QShortcut>

Window::Window(QWidget* parent)
	: QMainWindow(parent), font_size(100)
{
	setWindowTitle("Neji_TextEditor");
	setGeometry(200, 200, 800, 600);

	textarea = new QPlainTextEdit();
	setCentralWidget(textarea);

	init_menubar();
	init_statusbar();
	init_toolbar();

	connect(NewAction, QAction::triggered, this, Window::New);
	connect(OpenAction, QAction::triggered, this, Window::Open);
	connect(SaveAction, QAction::triggered, this, Window::Save);
	connect(SaveAsAction, QAction::triggered, this, Window::SaveAs);
	connect(ExitAction, QAction::triggered, this, Window::Exit);

}

Window::~Window()
{

}

void Window::Save()
{
}

void Window::Open()
{
}

void Window::New()
{
	printf("");
}

void Window::SaveAs()
{
}

void Window::Exit()
{
}

void Window::init_menubar()
{
	filemenu = menuBar()->addMenu("File");
	{
		NewAction = new QAction(QIcon(":/icons/new.png"),"New");
		NewAction->setShortcut(QKeySequence::New);
		NewAction->setStatusTip("Create new file");
		filemenu->addAction(NewAction);

		OpenAction = new QAction(QIcon(":/icons/open.png"), "Open");
		OpenAction->setShortcut(QKeySequence::Open);
		OpenAction->setStatusTip("Open exist file");
		filemenu->addAction(OpenAction);

		SaveAsAction = new QAction(QIcon(":/icons/save_as.png"), "Save As");
		SaveAsAction->setShortcut(QKeySequence::SaveAs);
		SaveAsAction->setStatusTip("Save as new format");
		filemenu->addAction(SaveAsAction);

		SaveAction = new QAction(QIcon(":/icons/save.png"), "Save");
		SaveAction->setShortcut(QKeySequence::Save);
		SaveAction->setStatusTip("Save file");
		filemenu->addAction(SaveAction);

		filemenu->addSeparator();
		ExitAction = new QAction(QIcon(":/icons/exit.png"), "Exit");
		ExitAction->setShortcut(tr("Ctrl+Q"));
		ExitAction->setStatusTip("Exit program");
		filemenu->addAction(ExitAction);
	}
	
	helpmenu = menuBar()->addMenu("Help");
	{
		AboutAction = new QAction(QIcon(":/icons/about.png"), "Help");
		AboutAction->setStatusTip("About us");
		helpmenu->addAction(AboutAction);
	}

	editmenu = menuBar()->addMenu("Edit");
	formatmenu = menuBar()->addMenu("Format");
	viewmenu = menuBar()->addMenu("View");

}

void Window::init_toolbar()
{
	toolbar = new QToolBar();
	toolbar->addAction(NewAction);
	toolbar->addAction(OpenAction);
	toolbar->addAction(SaveAction);
	toolbar->addAction(SaveAsAction);
	toolbar->addAction(ExitAction);
	toolbar->addAction(AboutAction);

	addToolBar(toolbar);
}

void Window::init_statusbar()
{
	statusBar()->addPermanentWidget(new QLabel(""));
	statusBar()->addPermanentWidget(new QLabel(tr("%1 %").arg(font_size)));
}

