#include "chessplayer.h"

chessPlayer::chessPlayer()
{

}

chessPlayer::~chessPlayer()
{

}

void chessPlayer::addLostPiece(chessPiece *piece)
{
    lostPieces << piece;
}

int chessPlayer::getNumber()
{
    return number;
}
