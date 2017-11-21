#include "chessgame.h"

chessGame::chessGame(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Szachy");
    setMinimumSize(1000,900);

    saved = false;

    chessboard = new chessBoard(this);
    chessboard->generateChessBoard();
    setCentralWidget(chessboard);

    QMenu *plik = menuBar()->addMenu("Plik");
    QAction *zamknij = new QAction(QIcon::fromTheme("application-exit"), "Zamknij",this);
    zamknij->setShortcut(QKeySequence::Quit);
    zamknij->setStatusTip("Kliknij by zamknąć grę");
    plik->addAction(zamknij);
    connect(zamknij, SIGNAL(triggered(bool)), this, SLOT(close_window()));
}


chessGame::~chessGame()
{

}

void chessGame::close_window()
{
    if (saved!=true) {
        QMessageBox message;
        message.setText("Gra nie została zapisana");
    }
}

void chessGame::createMenus()
{

}
