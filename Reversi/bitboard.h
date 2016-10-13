#ifndef BITBOARD_H
#define BITBOARD_H

#include <limits.h>
include "reversi.h"

typedef struct {
	size_t size;
	uint64_t black;
	uint64_t white;
} bitboard_t;

bitboard_t bb_new(size_t size);

bitboard_t bb_set(move_t move, state_t state);

bitboard_t bb_init(size_t size);

void bb_print(bitboard_t board);

score_t bb_score(bitboard_t board);

bitboard_t bb_move(move_t move, state_t state);

bitboard_t bb_moves(state_t state);

int score_heuristic (state_t state);

move_t minmax(state_t state, int depth, int (*heuristic) state_t state);

move_t negamax(state_t state, int depth, int (*heuristic) state_t state);

move_t minmax_alphabeta(state_t state, int depth, int (*heuristic) (state_t state));

move_t negamax_alphabeta(state_t state, int depth, int (*heuristic) (state_t state));

static move_t ai_player(state_t state);

#endif