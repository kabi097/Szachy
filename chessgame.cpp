#include "chessgame.h"

chessGame::chessGame(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Szachy");
    //setMinimumSize(700,400);

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

    //Menu i paski
    QMenu *filemenu = menuBar()->addMenu("Plik");
    QAction *closeAction = new QAction(QIcon::fromTheme("application-exit"), "Zamknij",this);
    closeAction->setShortcut(QKeySequence::Quit);
    closeAction->setStatusTip("Kliknij by zamknąć grę");
    filemenu->addAction(closeAction);
    connect(closeAction, SIGNAL(triggered(bool)), this, SLOT(close_window()));
}


chessGame::~chessGame()
{

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
    chessSettings setting;
}
