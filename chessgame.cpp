#include "chessgame.h"

/*!
    \class chessGame
    \brief Główna klasa gry. Odpowiada za poprawne działania i wyświetlanie okna.

    Klasa ta dziedziczy po QMainWindow. Tworzy nowe okno, a w nim szachownicę oraz panel.
    Odpowiada za prawidłowe działanie pasków i przycisków.
*/

chessGame::chessGame(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("[*] Szachy");
    saved = true;
    statusBar();

    QHBoxLayout *layout = new QHBoxLayout();

    layout->addStretch();

    chessboard = new chessBoard();
    chessboard->generateChessPieces();
    connect(chessboard,SIGNAL(checkMate(int)),this,SLOT(game_over(int)));
    connect(chessboard,SIGNAL(nextMove()), this, SLOT(setNotSaved()));

    layout->addWidget(chessboard);

    layout->addSpacing(15);
    panel = new chessPanel(chessboard);
    connect(chessboard,SIGNAL(newLost()), panel, SLOT(updateLost()));
    connect(chessboard,SIGNAL(nextMove()), panel, SLOT(updateCurrentPlayer()));
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
        if (file.open(QFile::WriteOnly | QFile::Text)) {
            file.resize(0);
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
                setWindowModified(false);
                saved=true;
            }
        }
    }
}

void chessGame::saveAs_game()
{
    QString newfile = QFileDialog::getSaveFileName(this, tr("Zapisz"));
    QFile file(newfile);
    if (file.open(QFile::WriteOnly | QFile::Text)) {
        currentFile = newfile;
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
        saved=true;
    } else {
        QMessageBox::warning(this,"Błąd!", "Nie udało się odczytać pliku.");
    }
}

void chessGame::open_game()
{
    if (saved==false) {
        QMessageBox message;
        message.setWindowTitle("Ostrzeżenie");
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
            saved = true;
            setWindowModified(false);
            open_game();
            break;
        default:
            break;
        }
    } else {
        currentFile = QFileDialog::getOpenFileName(this, "Otwórz");
        QFile file(currentFile);
        if (file.open(QFile::ReadOnly | QFile::Text)) {
            chessboard->resetChessboard();
            chessboard->generateChessPieces();
            panel->clearLost();
            panel->updateCurrentPlayer();
            QTextStream in(&file);
            try {
                while (!in.atEnd()) {
                    QString line = in.readLine();
                    chessboard->readFromText(line);
                }
            } catch (QString error) {
                QMessageBox::critical(this,"Błąd!", error);
                chessboard->resetChessboard();
                chessboard->generateChessPieces();
                panel->clearLost();
                panel->updateCurrentPlayer();
            }
            saved = true;
            setWindowModified(false);
        }
    }
}

void chessGame::new_game()
{
    if (saved==false) {
        QMessageBox message;
        message.setWindowTitle("Ostrzeżenie");
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
            panel->clearLost();
            panel->updateCurrentPlayer();
            break;
        default:
            break;
        }
    } else {
        chessboard->resetChessboard();
        chessboard->generateChessPieces();
        saved = true;
        setWindowModified(false);
    }
}

void chessGame::closeEvent(QCloseEvent *event) {
    close_window();
}

void chessGame::close_window()
{
    if (saved==true) {
        QApplication::quit();
    } else {
        QMessageBox message;
        message.setWindowTitle("Ostrzeżenie");
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
            QApplication::quit();
            break;
        case QMessageBox::Discard:
            QApplication::quit();
            break;
        default:
            break;
        }
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
    QString about = "Program reprezentuje grę w szachy. Zbudowany jest z 6 klas, które zapewniają mu pełną funkcjonalność. Umożliwia on grę dwóch osób oraz zapis i odczyt wyników z pliku.  Program posiada funkcje za pomocą których użytkownik może modyfikować wygląd szachownicy w dowolny sposób co czyni grę ciekawszą.";
    QMessageBox::about(this,"O grze", about);
}

void chessGame::game_over(int player)
{
    QMessageBox gameover_info;
    gameover_info.setWindowTitle("Informacja");
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

    QAction *newgameAction = new QAction(QIcon::fromTheme("document-new", QIcon(":/icons/Icons/New file.png")),"Nowa gra", this);
    newgameAction->setShortcut(QKeySequence::New);
    newgameAction->setStatusTip("Rozpocznij nową grę");
    filemenu->addAction(newgameAction);
    connect(newgameAction,SIGNAL(triggered(bool)),this,SLOT(new_game()));

    QAction *openGameAction = new QAction(QIcon::fromTheme("document-open", QIcon(":/icons/Icons/Open file.png")),"Otwórz", this);
    openGameAction->setShortcut(QKeySequence::Open);
    openGameAction->setStatusTip("Otwórz grę z pliku");
    filemenu->addAction(openGameAction);
    connect(openGameAction,SIGNAL(triggered(bool)),this,SLOT(open_game()));

    filemenu->addSeparator();

    QAction *saveGameAction = new QAction(QIcon::fromTheme("document-save", QIcon(":/icons/Icons/Save.png")),"Zapisz", this);
    saveGameAction->setShortcut(QKeySequence::Save);
    saveGameAction->setStatusTip("Zapisz stan gry");
    filemenu->addAction(saveGameAction);
    connect(saveGameAction,SIGNAL(triggered(bool)),this,SLOT(save_game()));

    QAction *saveAsGameAction = new QAction(QIcon::fromTheme("document-save-as", QIcon(":/icons/Icons/Save as.png")),"Zapisz jako", this);
    saveAsGameAction->setShortcut(QKeySequence::SaveAs);
    saveAsGameAction->setStatusTip("Zapisz stan gry");
    filemenu->addAction(saveAsGameAction);
    connect(saveAsGameAction,SIGNAL(triggered(bool)),this,SLOT(saveAs_game()));

    filemenu->addSeparator();

    QAction *settingsAction = new QAction(QIcon::fromTheme("preferences-system", QIcon(":/icons/Icons/Settings.png")),"Ustawienia", this);
    settingsAction->setMenuRole(QAction::PreferencesRole);
    settingsAction->setShortcut(QKeySequence::Preferences);
    settingsAction->setStatusTip("Otwórz ustawienia gry");
    filemenu->addAction(settingsAction);
    connect(settingsAction,SIGNAL(triggered(bool)),this,SLOT(open_settings()));

    filemenu->addSeparator();

    QAction *closeAction = new QAction(QIcon::fromTheme("application-exit", QIcon(":/icons/Icons/Close.png")), "Zamknij",this);
    closeAction->setShortcut(QKeySequence::Quit);
    closeAction->setStatusTip("Kliknij by zamknąć grę");
    closeAction->setMenuRole(QAction::QuitRole);
    filemenu->addAction(closeAction);
    connect(closeAction, SIGNAL(triggered(bool)), this, SLOT(close_window()));

    QMenu *helpmenu = menuBar()->addMenu("Pomoc");

    QAction *aboutQtAction = new QAction(QIcon(":/icons/Icons/Qt.png"),"About Qt", this);
    aboutQtAction->setMenuRole(QAction::AboutQtRole);
    helpmenu->addAction(aboutQtAction);
    connect(aboutQtAction,SIGNAL(triggered(bool)),this,SLOT(about_qt()));

    QAction *aboutGameAction = new QAction(QIcon::fromTheme("about", QIcon(":/icons/Icons/Help.png")),"About Game", this);
    aboutGameAction->setMenuRole(QAction::AboutRole);
    helpmenu->addAction(aboutGameAction);
    connect(aboutGameAction,SIGNAL(triggered(bool)),this,SLOT(about_game()));
}

chessGame::~chessGame()
{

}
