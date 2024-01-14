#pragma once

#include <iostream>

// TODO: Read the following comments carefully.

enum class SurakartaIllegalMoveReason {
    LEGAL,                     // unused
    LEGAL_CAPTURE_MOVE,        // capture a opponent's piece, and the move consists at least one corner loop
    LEGAL_NON_CAPTURE_MOVE,    // just as the name
    ILLIGAL,                   // unused
    NOT_PLAYER_TURN,           // unused, move when it's not the player's turn, this will never happen before we add the Network module
    OUT_OF_BOARD,              // from or to position is out of board
    NOT_PIECE,                 // move a position that is not a piece
    NOT_PLAYER_PIECE,          // move a piece that is not the player's
    ILLIGAL_CAPTURE_MOVE,      // try to capture a opponent's piece, but the move can't consist any corner loop
    ILLIGAL_NON_CAPTURE_MOVE,  // otherwise
    GAME_ALREADY_END,          // unused
    GAME_NOT_START             // unused
};

enum class SurakartaEndReason {
    NONE,          // not end
    STALEMATE,     // players can't make more legal move
    CHECKMATE,     // one player's last piece is captured
    ILLIGAL_MOVE,  // one player makes an illegal move
};

bool IsLegalMoveReason(SurakartaIllegalMoveReason reason);
bool IsEndReason(SurakartaEndReason reason);

std::ostream& operator<<(std::ostream& os, const SurakartaIllegalMoveReason& reason);
std::istream& operator>>(std::istream& is, SurakartaIllegalMoveReason& reason);

std::ostream& operator<<(std::ostream& os, const SurakartaEndReason& reason);
std::istream& operator>>(std::istream& is, SurakartaEndReason& reason);