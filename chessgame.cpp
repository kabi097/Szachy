#include "chessgame.h"

chessGame::chessGame(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("[*] Szachy");

    saved = true;

    QHBoxLayout *layout = new QHBoxLayout();

    layout->addStretch();

    chessboard = new chessBoard();
    chessboard->generateChessPieces();
    connect(chessboard,SIGNAL(checkMate(int)),this,SLOT(game_over(int)));
    connect(chessboard,SIGNAL(nextMove()), this, SLOT(setNotSaved()));

    layout->addWidget(chessboard);

    layout->addSpacing(15);

    chessPanel *panel = new chessPanel(chessboard);
    layout->addWidget(panel);

    layout->addStretch();

    QWidget *content = new QWidget();
    content->setLayout(layout);
    setCentralWidget(content);
    createMenus();
}

void chessGame::save_game()
{
    if (saved==false) {
        if (currentFile.isEmpty()==true) {
            currentFile = QFileDialog::getSaveFileName(this, "Zapisz");
        }
        QFile file(currentFile);
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            //nie udało się otworzyć
            //throw QString("Nie udało się otworzyć pliku");
        } else {

            QTextStream out(&file);

            QStringList history = chessboard->history;

            int counter=0;
            for (int i=0; i<history.size(); i++) {
                out << history.at(i) << " ";
                counter++;
                if (counter%2==0) {
                    out << endl;
                    counter=0;
                }
            }
            setWindowModified(false);
        }
    }
}

void chessGame::open_game()
{
    if (saved==false) {
        save_game();
        chessboard->resetChessboard();
        chessboard->generateChessPieces();
    }
    currentFile = QFileDialog::getOpenFileName(this, "Otwórz");
    QFile file(currentFile);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        throw QString("Nie udało się otworzyć pliku");
    } else {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            //process_line(line);
        }
    }
}

void chessGame::new_game()
{
    if (saved==false) {
        QMessageBox message;
        message.setText("Gra nie została zapisana.");
        message.setInformativeText("Czy chcesz zapisać stan gry?");
        message.addButton(QMessageBox::Save);
        message.addButton(QMessageBox::Discard);
        message.addButton(QMessageBox::Cancel);
        message.setDefaultButton(QMessageBox::Save);
        int ret = message.exec();
        switch (ret) {
        case QMessageBox::Save:
            save_game();
            break;
        case QMessageBox::Discard:
            chessboard->resetChessboard();
            chessboard->generateChessPieces();
            break;
        default:
            break;
        }
    } else {
        saved = false;
        chessboard->resetChessboard();
        chessboard->generateChessPieces();
    }
}

void chessGame::closeEvent(QCloseEvent *event) {
    close_window();
}

void chessGame::close_window()
{
    if (saved!=true) {
        QMessageBox message;
        message.setText("Gra nie została zapisana.");
        message.setInformativeText("Czy chcesz zapisać stan gry?");
        message.addButton(QMessageBox::Save);
        message.addButton(QMessageBox::Discard);
        message.addButton(QMessageBox::Cancel);
        message.setDefaultButton(QMessageBox::Save);
        int ret = message.exec();
        switch (ret) {
        case QMessageBox::Save:

            break;
        case QMessageBox::Discard:
            QApplication::quit();
            break;
        case QMessageBox::Cancel:

            break;
        default:
            break;
        }
    } else {
        QApplication::quit();
    }
}

void chessGame::open_settings()
{
    chessSettings setting(chessboard);
    if (setting.exec()==QDialog::Accepted) {
        chessboard->updateColors(setting.tempBlack,setting.tempWhite,setting.tempSelect,setting.tempAttack);
    }
}

void chessGame::about_qt()
{
    QMessageBox::aboutQt(this,"About Qt");
}

void chessGame::about_game()
{
    QMessageBox::about(this,"O grze", "Witamy!");
}

void chessGame::game_over(int player)
{
    //koniec gry
    QMessageBox gameover_info;
    gameover_info.setText("Koniec gry.");
    if (player == 0) {
        gameover_info.setInformativeText("Wygrał gracz biały.");
    } else {
        gameover_info.setInformativeText("Wygrał gracz czarny.");
    }
    gameover_info.exec();
    chessboard->blockAllSquares();

}

void chessGame::setNotSaved()
{
    saved = false;
    setWindowModified(true);

}

void chessGame::createMenus()
{
    //Menu i paski
    QMenu *filemenu = menuBar()->addMenu("Plik");

    QAction *newgameAction = new QAction(QIcon::fromTheme("document-new"),"Nowa gra", this);
    newgameAction->setStatusTip("Rozpocznij nową grę");
    filemenu->addAction(newgameAction);
    connect(newgameAction,SIGNAL(triggered(bool)),this,SLOT(new_game()));

    QAction *openGameAction = new QAction(QIcon::fromTheme("document-open"),"Otwórz", this);
    openGameAction->setStatusTip("Otwórz grę z pliku");
    filemenu->addAction(openGameAction);
    connect(openGameAction,SIGNAL(triggered(bool)),this,SLOT(open_game()));

    QAction *saveGameAction = new QAction(QIcon::fromTheme("document-save"),"Zapisz", this);
    saveGameAction->setStatusTip("Zapisz stan gry");
    filemenu->addAction(saveGameAction);
    connect(saveGameAction,SIGNAL(triggered(bool)),this,SLOT(save_game()));

    QAction *settingsAction = new QAction(QIcon::fromTheme("preferences-system"),"Ustawienia", this);
    settingsAction->setMenuRole(QAction::PreferencesRole);
    newgameAction->setStatusTip("Otwórz ustawienia gry");
    filemenu->addAction(settingsAction);
    connect(settingsAction,SIGNAL(triggered(bool)),this,SLOT(open_settings()));

    QAction *closeAction = new QAction(QIcon::fromTheme("application-exit"), "Zamknij",this);
    closeAction->setShortcut(QKeySequence::Quit);
    closeAction->setStatusTip("Kliknij by zamknąć grę");
    closeAction->setMenuRole(QAction::QuitRole);
    filemenu->addAction(closeAction);
    connect(closeAction, SIGNAL(triggered(bool)), this, SLOT(close_window()));

    QMenu *helpmenu = menuBar()->addMenu("Pomoc");

    QAction *aboutQtAction = new QAction(QIcon::fromTheme("about"),"About Qt", this);
    aboutQtAction->setMenuRole(QAction::AboutQtRole);
    helpmenu->addAction(aboutQtAction);
    connect(aboutQtAction,SIGNAL(triggered(bool)),this,SLOT(about_qt()));

    QAction *aboutGameAction = new QAction(QIcon::fromTheme("about"),"About Game", this);
    aboutGameAction->setMenuRole(QAction::AboutRole);
    helpmenu->addAction(aboutGameAction);
    connect(aboutGameAction,SIGNAL(triggered(bool)),this,SLOT(about_game()));
}

chessGame::~chessGame()
{

}
