#include "chessgame.h"

chessGame::chessGame(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Szachy");
    setMinimumSize(700,400);

    saved = true;

    QHBoxLayout *layout = new QHBoxLayout();

    layout->addStretch();

    //TODO: Przenieść do osobnej funkcji
    chessboard = new chessBoard();
    chessboard->generateChessPieces();
    connect(chessboard,SIGNAL(checkMate(int)),this,SLOT(game_over(int)));

    layout->addWidget(chessboard);

    layout->addSpacing(15);

    chessPanel *panel = new chessPanel();
    layout->addWidget(panel);

    layout->addStretch();

    QWidget *content = new QWidget();
    content->setLayout(layout);
    setCentralWidget(content);

    createMenus();
}


chessGame::~chessGame()
{

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
            //Save slot
            break;
        case QMessageBox::Discard:

            break;
        case QMessageBox::Cancel:

            break;
        default:
            break;
        }
    } else {
        saved = false;
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

void chessGame::createMenus()
{
    //Menu i paski
    QMenu *filemenu = menuBar()->addMenu("Plik");

    QAction *newgameAction = new QAction(QIcon::fromTheme("new-file"),"Nowa gra", this);
    newgameAction->setStatusTip("Rozpocznij nową grę");
    filemenu->addAction(newgameAction);
    connect(newgameAction,SIGNAL(triggered(bool)),this,SLOT(new_game()));


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
