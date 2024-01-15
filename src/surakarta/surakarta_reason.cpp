#include "surakarta_reason.h"
#include <iostream>

bool IsLegalMoveReason(SurakartaIllegalMoveReason reason) {
    switch (reason) {
        case SurakartaIllegalMoveReason::LEGAL:
        case SurakartaIllegalMoveReason::LEGAL_CAPTURE_MOVE:
        case SurakartaIllegalMoveReason::LEGAL_NON_CAPTURE_MOVE:
            return true;
        default:
            return false;
    }
}

bool IsEndReason(SurakartaEndReason reason) {
    switch (reason) {
        case SurakartaEndReason::NONE:
            return false;
        default:
            return true;
    }
}

std::ostream& operator<<(std::ostream& os, const SurakartaIllegalMoveReason& reason) {
    switch (reason) {
        case SurakartaIllegalMoveReason::LEGAL:
            os << "LEGAL";
            break;
        case SurakartaIllegalMoveReason::LEGAL_CAPTURE_MOVE:
            os << "LEGAL_CAPTURE_MOVE";
            break;
        case SurakartaIllegalMoveReason::LEGAL_NON_CAPTURE_MOVE:
            os << "LEGAL_NON_CAPTURE_MOVE";
            break;
        case SurakartaIllegalMoveReason::ILLIGAL:
            os << "ILLIGAL";
            break;
        case SurakartaIllegalMoveReason::NOT_PLAYER_TURN:
            os << "NOT_PLAYER_TURN";
            break;
        case SurakartaIllegalMoveReason::OUT_OF_BOARD:
            os << "OUT_OF_BOARD";
            break;
        case SurakartaIllegalMoveReason::NOT_PIECE:
            os << "NOT_PIECE";
            break;
        case SurakartaIllegalMoveReason::NOT_PLAYER_PIECE:
            os << "NOT_PLAYER_PIECE";
            break;
        case SurakartaIllegalMoveReason::ILLIGAL_CAPTURE_MOVE:
            os << "ILLIGAL_CAPTURE_MOVE";
            break;
        case SurakartaIllegalMoveReason::ILLIGAL_NON_CAPTURE_MOVE:
            os << "ILLIGAL_NON_CAPTURE_MOVE";
            break;
        case SurakartaIllegalMoveReason::GAME_ALREADY_END:
            os << "GAME_ALREADY_END";
            break;
        case SurakartaIllegalMoveReason::GAME_NOT_START:
            os << "GAME_NOT_START";
            break;
        default:
            os << "UNKNOWN";
            break;
    }
    return os;
}

std::istream& operator>>(std::istream& is, SurakartaIllegalMoveReason& reason) {
    std::string str;
    is >> str;
    if (str == "LEGAL") {
        reason = SurakartaIllegalMoveReason::LEGAL;
    } else if (str == "LEGAL_CAPTURE_MOVE") {
        reason = SurakartaIllegalMoveReason::LEGAL_CAPTURE_MOVE;
    } else if (str == "LEGAL_NON_CAPTURE_MOVE") {
        reason = SurakartaIllegalMoveReason::LEGAL_NON_CAPTURE_MOVE;
    } else if (str == "ILLIGAL") {
        reason = SurakartaIllegalMoveReason::ILLIGAL;
    } else if (str == "NOT_PLAYER_TURN") {
        reason = SurakartaIllegalMoveReason::NOT_PLAYER_TURN;
    } else if (str == "OUT_OF_BOARD") {
        reason = SurakartaIllegalMoveReason::OUT_OF_BOARD;
    } else if (str == "NOT_PIECE") {
        reason = SurakartaIllegalMoveReason::NOT_PIECE;
    } else if (str == "NOT_PLAYER_PIECE") {
        reason = SurakartaIllegalMoveReason::NOT_PLAYER_PIECE;
    } else if (str == "ILLIGAL_CAPTURE_MOVE") {
        reason = SurakartaIllegalMoveReason::ILLIGAL_CAPTURE_MOVE;
    } else if (str == "ILLIGAL_NON_CAPTURE_MOVE") {
        reason = SurakartaIllegalMoveReason::ILLIGAL_NON_CAPTURE_MOVE;
    } else if (str == "GAME_ALREADY_END") {
        reason = SurakartaIllegalMoveReason::GAME_ALREADY_END;
    } else if (str == "GAME_NOT_START") {
        reason = SurakartaIllegalMoveReason::GAME_NOT_START;
    } else {
        reason = SurakartaIllegalMoveReason::ILLIGAL;
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const SurakartaEndReason& reason) {
    switch (reason) {
        case SurakartaEndReason::NONE:
            os << "NONE";
            break;
        case SurakartaEndReason::STALEMATE:
            os << "STALEMATE";
            break;
        case SurakartaEndReason::CHECKMATE:
            os << "CHECKMATE";
            break;
        case SurakartaEndReason::TRAPPED:
            os << "TRAPPED";
            break;
        case SurakartaEndReason::RESIGN:
            os << "RESIGN";
            break;
        case SurakartaEndReason::TIMEOUT:
            os << "TIMEOUT";
            break;
        case SurakartaEndReason::ILLIGAL_MOVE:
            os << "ILLIGAL_MOVE";
            break;
        default:
            os << "UNKNOWN";
            break;
    }
    return os;
}

std::istream& operator>>(std::istream& is, SurakartaEndReason& reason) {
    std::string str;
    is >> str;
    if (str == "NONE") {
        reason = SurakartaEndReason::NONE;
    } else if (str == "STALEMATE") {
        reason = SurakartaEndReason::STALEMATE;
    } else if (str == "CHECKMATE") {
        reason = SurakartaEndReason::CHECKMATE;
    } else if (str == "TRAPPED") {
        reason = SurakartaEndReason::TRAPPED;
    } else if (str == "RESIGN") {
        reason = SurakartaEndReason::RESIGN;
    } else if (str == "TIMEOUT") {
        reason = SurakartaEndReason::TIMEOUT;
    } else if (str == "ILLIGAL_MOVE") {
        reason = SurakartaEndReason::ILLIGAL_MOVE;
    } else {
        reason = SurakartaEndReason::NONE;
    }
    return is;
}